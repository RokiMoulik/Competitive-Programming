//using dijkstra algorithm
#include<iostream>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

#define inf 2147483647 // -> assume its the largest distance of all cities, so we need to make it lowest

map<pair<string, string>, int>cityDistance; // store distance between two cities
map<string, vector<string> >graph;
map<string, bool> vis; // mark the city is visited or not
map<string, int>dist; // store shortest distance from the source
vector<string>citiesInq; // store the cities in queue

string getMinCity(){
    int mn = inf;
    int mnInd;
    string minCity = "";
    cout << "getMinCity"<<endl;
    for(int i = 0; i < citiesInq.size(); i++){
        cout << "in loop"<<endl;
        if(dist[citiesInq[i]] < mn){
            mn = dist[citiesInq[i]];
            minCity = citiesInq[i];
            mnInd = i;
        }
    }

    //remove that city that has minimum distance
    citiesInq.erase(citiesInq.begin() + mnInd);

    return minCity;
}


void BFS(string source){
    vis[source] = true;
    dist[source] = 0;
    citiesInq.push_back(source);

    while(!citiesInq.empty()){
        string minCity = getMinCity();

        for(auto city : graph[minCity]){
            if(vis[city] == false){ // not visited yet
                citiesInq.push_back(city);
                vis[city] = true;
            }
            if(dist[city] > dist[minCity] + cityDistance[{minCity, city}]){
                dist[city] = dist[minCity] + cityDistance[{minCity, city}];
            }
        }
    }
}

int main()
{
    int edge, distan;
    string cityA, cityB;

    cout << "Enter Number of pairs of city: ";
    cin >> edge;



    for(int i = 0; i < edge; i++){
        fflush(stdin); // flush the input so that getline works perfectly

        cout << "Enter 1st City: ";
        getline(cin, cityA);
        cout << "Enter 2nd City: ";
        getline(cin, cityB);
        cout << "Enter Distance: ";
        cin >> distan;

        // assume this is a undirected graph because city A to city B distance and city B to city A distance is same.
        cityDistance[{cityA, cityB}] = distan;
        cityDistance[{cityB, cityA}] = distan;

        graph[cityA].push_back(cityB);
        graph[cityB].push_back(cityA);

        vis[cityA] = false;
        vis[cityB] = false;

        dist[cityA] = inf;
        dist[cityB] = inf;
    }

    cout << "Enter the source city: ";
    fflush(stdin);
    getline(cin, cityA);

    BFS(cityA);

    cout << "\n\n======== All City Distance From Rabat: =========\n\n\n";
    for(auto it : dist){
        cout << it.first <<": "<<dist[it.first]<<endl;
    }

    return 0;
}

/*



20
Rabat
Sueca
1063
Sueca
Rudow
2656
Rudow
Mosu
1352
Mosu
Le Plessis Trevise
1841
Le Plessis Trevise
Kang Dong
61
Kang Dong
Nezahualcayotl
1634
Nezahualcayotl
Lindenwold
151
Lindenwold
QationboYon
285
QationboYon
Saint Chamond
146
Saint Chamond
Cheektowaga
11
Cheektowaga
Tirupati
380
Tirupati
Snezhinsk
2547
Snezhinsk
Glazov
2524
Glazov
Gaoyou
97
Gaoyou
Nolo
6999
Nolo
Rutigliano
63
Rutigliano
Colombo
105
Colombo
Meckenheim
244
Meckenheim
Hamburg
502
Hamburg
Rabat
30
Rabat



*/

