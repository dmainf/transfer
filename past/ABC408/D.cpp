#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> one(n+1, 0);
        rep(i, n) one[i+1]=one[i]+(s[i]=='1' ? 1:0);
        int l_val=0;
        int tmp=INF;
        rep(r, n+1) {
            //[l, r)内の0をすべて1にする
            //(r-l)-(one[r]-one[l])
            //[l, r)以外の1をすべて0にする
            //one[n]-(one[r]-one[l])
            //=one[n]+(r-2*one[r])+(2*one[l]-l)
            int cur=one[n]+(r-2*one[r])+l_val;
            tmp=min(tmp, cur);
            l_val=min(l_val, 2*one[r]-r);
            cout << "l_val:" << l_val << endl;
        }
        ans.push_back(tmp==INF ? 0:tmp);
    }
    for(int x:ans) cout << x << endl;

    return 0;
}