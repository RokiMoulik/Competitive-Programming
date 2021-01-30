#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define N 200000002
int status[8000000];
vector<ll>prime;

bool check(int n, int pos) {
    return (bool)(n & (1<<pos));
}
int setBit(int n, int pos) {
    return n = (n | (1<<pos));
}

void sieve() {
    prime.pb(2);
    ll i, j, sQrt = sqrt(N);

    for(i = 3; i <= sQrt; i+= 2) {
        if(check(status[i>>5], i&31)==0) {
            //prime.pb(i);
            for(j = i*i; j<= N; j+= (i<<1)) {
                status[j>>5] = setBit(status[j>>5], (j&31));
            }
        }
    }
    if(sQrt&1)
        i = sQrt;
    else i = sQrt + 1;

    for(i; i <= N; i +=2) {
        if(!check(status[i>>5], i&31));
        //prime.pb(i);
    }
}


int main() {
    sieve();
    // cout<<prime.size()<<endl;
    //for(int i = 0; i < prime.size(); ++i) {
    //cout<<prime[i]<<" ";
    //}

    return 0;
}
