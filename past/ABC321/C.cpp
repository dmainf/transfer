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
    vector<ll> ans;
    //各数字が1回しか出てこない
    //2進数ででた数字を順番に並べる
    for(int x=2; x<(1<<10); x++) {
        ll tmp=0;
        for(int bit=9; bit>=0; bit--) {
            if(x&(1<<bit)) {
                tmp*=10;
                tmp+=bit;
            }
        }
        ans.push_back(tmp);
    }
    sort(all(ans));
    int k;
    cin >> k;
    cout << ans[k-1] << endl;
    
    return 0;
}