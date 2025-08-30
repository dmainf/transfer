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
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> id(n, -1);
    int v=0;
    int cnt=0;
    while(id[v]==-1) {
        id[v]=cnt;
        cnt++;
        v=a[v];
    }
    vector<int> ans;
    //最後に行ったとこが閉路の始まり
    int start=v;
    int len=cnt-id[v];
    //閉路2周目
    while(len--) {
        ans.push_back(v);
        v=a[v];
    }
    cout << ans.size() << endl;
    for(int x:ans) cout << x+1 << " ";
    cout << endl;

    return 0;
}