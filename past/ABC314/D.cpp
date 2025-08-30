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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<int> t(q), x(q);
    vector<char> c(q);
    vector<pair<bool, int>> last;
    rep(i, q) {
        cin >> t[i] >> x[i] >> c[i];
        x[i]--;
        if(t[i]==2) last.push_back({false, i});
        if(t[i]==3) last.push_back({true, i});
    }
    if(last.size()==0) {
        for(int i=0; i<n; i++) if(t[i]==1) {
            s[x[i]]=c[i];
        }
        cout << s << endl;
        return 0;
    }
    auto [capital, idx]=last.back();
    for(int i=0; i<=idx; i++) if(t[i]==1) {
        s[x[i]]=c[i];
    }
    rep(i, n) {
        if(capital) s[i]=toupper(s[i]);
        else s[i]=tolower(s[i]);
    }
    for(int i=idx+1; i<q; i++) s[x[i]]=c[i];
    cout << s << endl;

    return 0;
}