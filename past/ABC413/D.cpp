#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
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
    int t; cin >> t;
    vector<bool> ans;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        vector<pi> abs_a(n);
        rep(i, n) abs_a[i]={abs(a[i]), i};
        sort(all(abs_a));
        vector<int> b(n);
        rep(i, n) {
            b[i]=a[abs_a[i].second];
        }
        set<int> abs_set;
        int pos=0, neg=0;
        rep(i, n) {
            abs_set.insert(abs(a[i]));
            if(a[i]>0) pos++;
            else neg++;
        }
        bool flag=true;
        if(abs_set.size()==1) {
            if(pos==n || neg==n) flag=true;
            else if(abs(pos-neg)<=1) flag=true;
            else flag=false;
        } else {
            ll bunsi=(ll)b[1], bunbo=(ll)b[0];
            //bunsi/bunbo==b[i+1]/b[i]
            //bunsi*b[i]==b[i+1]*bunbo
            rep(i, n-1) {
                if((ll)b[i+1]*bunbo!=(ll)b[i]*bunsi) {
                    flag=false;
                    break;
                }
            }
        }
        ans.push_back(flag ? true:false);
    }
    for(bool flag:ans) cout << (flag ? "Yes":"No") << endl;

    return 0;
}