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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int q;
    cin >> q;
    vector<int> ans;
    while(q--) {
        int com, b, e;
        cin >> com >> b >> e;
        if(com==0) {
            ans.push_back(*min_element(a.begin()+b, a.begin()+e));
        }
        if(com==1) {
            ans.push_back(*max_element(a.begin()+b, a.begin()+e));
        }
    }
    for(int x:ans) cout << x << endl;

    return 0;
}