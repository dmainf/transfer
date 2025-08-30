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
    int n; cin >> n;
    vector<string> s(n);
    set<string> st;
    vector<int> ans;
    rep(i, n) {
        string s;
        cin >> s;
        if(!st.count(s)) ans.push_back(i+1);
        st.insert(s);
    }
    for(int x:ans) cout << x << endl;

    return 0;
}