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
    int k, g, m;
    //g<m
    cin >> k >> g >> m;
    int glass=0, magcap=0;
    rep(ki, k) {
        if(glass==g) glass=0;
        else {
            if(magcap==0) magcap=m;
            else {
                while(!(magcap==0 || glass==g)) {
                    glass+=1;
                    magcap-=1;
                }
            }
        }
    }
    cout << glass << " " << magcap << endl;
    return 0;
}