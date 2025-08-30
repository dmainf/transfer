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
    vector<string> ans;
    rep(i, 1<<n) {
        string s;
        rep(bit, n) {
            if((i>>bit)&1) s+='(';
            else s+=')';
        }
        int cnt=0;
        bool flag=true;
        rep(j, n) {
            if(s[j]=='(') cnt++;
            else cnt--;

            if(cnt<0) flag=false;
        }
        if(cnt==0 && flag) ans.push_back(s);
    }
    sort(all(ans));
    for(string t:ans) cout << t << endl;

    return 0;
}