#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    //nex[i][c] i文字目以降でcが出現する最小の添字
    auto cal_next=[&](const string &s) {
        int n=(int)s.size();
        vector<vector<int>> res(n+1, vector<int>(26, n));
        for (int i=n-1;0<=i;i--) {
            res[i]=res[i+1];
            res[i][s[i]-'a']=i;
        }
        return res;
    };
    vector<vector<int>> nex=cal_next(s);
    int now=-1;
    string ans="";
    rep(i, k) for(char c='a'; c<='z'; c++) {
        int tmp=nex[now+1][c-'a'];
        if(k-i<=n-tmp) {
            ans+=c;
            now=tmp;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}