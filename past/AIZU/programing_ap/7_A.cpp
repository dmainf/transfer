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
    int q;
    cin >> q;
    set<int> st;
    vector<int> ans;
    while(q--) {
        int op, x;
        cin >> op >> x;
        if(op==0) {
            st.insert(x);
            ans.push_back(st.size());
        } if(op==1) ans.push_back((st.count(x) ? 1:0));
    }
    for(int x:ans) cout << x << endl;

    return 0;
}