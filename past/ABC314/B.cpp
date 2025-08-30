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
    vector<int> human(n);
    vector<vector<int>> num(37);
    rep(i, n) {
        int c;
        cin >> c;
        human[i]=c;
        rep(j, c) {
            int a;
            cin >> a;
            num[a].push_back(i);
        }
    }
    int x;
    cin >> x;
    int mn=INF;
    for(int z:num[x]) mn=min(mn, human[z]);
    vector<int> ans;
    for(int z:num[x]) {
        if(human[z]==mn) ans.push_back(z+1);
    }
    cout << ans.size() << endl;
    sort(all(ans));
    for(int z:ans) cout << z << " ";
    cout << endl;

    return 0;
}