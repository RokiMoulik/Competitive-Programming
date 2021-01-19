#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios::sync_with_stdio(0)

const int N = 0;
int ar[N+5];

int32_t main() {
  //  faster;
    int ts;
    cin >> ts;
    while(ts--) {
        int n;
        cin >> n;
        string b;
        cin >> b;
        char pre = ' ';
        for(auto it : b){
            if(it == '1' && pre != '2'){
                cout <<1;
                pre = '2';
            }
            else if(it == '1'){
                cout << 0;
                pre = '1';
            }
            else if(pre != '1'){
                cout << 1;
                pre = '1';
            }
            else{
                cout <<0;
                pre = '0';
            }
        }
        cout << "\n";
    }
    return 0;
}
