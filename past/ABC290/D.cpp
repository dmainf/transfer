#include <bits/stdc++.h>
using namespace std;
#define rep(totu,n) for(int totu=0;totu<(n);totu++)
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
    int t;
    cin >> t;
    vector<int> ans;
    while(t--) {
        int n, d, k;
        cin >> n >> d >> k;
        k--;
        int g=gcd(n, d);
        ll cycle=n/g;           //周期
        ll step=d/g;            //1回の飛び幅
        int offset=(k*step)%cycle;   //何step目にいるか
        int totu=k/cycle;       //何回衝突が起きたか
        int tmp=offset*g+totu;  //step単位をマス単位に戻す
        ans.push_back(tmp);
    }
    for(int x:ans) cout << x << endl;

    return 0;
}