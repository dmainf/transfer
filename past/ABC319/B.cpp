#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    rep(i, n+1) {
        bool flag=true;
        for(int j=1; j<=9; j++) if(n%j==0) {
            if(i%(n/j)==0) {
                cout << j;
                flag=false;
                break;
            }
        }
        if(flag) cout << "-";
    }
    cout << endl;

    return 0;
}