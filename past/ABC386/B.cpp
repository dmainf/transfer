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
    string s;
    cin >> s;
    int ans=0;
    rep(i, s.size()) {
        if(s[i]!='0') ans++;
        else {
            int tmp=0;
            while(s[i]=='0') {
                tmp++;
                i++;
            }
            ans+=tmp/2+tmp%2;
            i--;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}