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
    char p, q;
    cin >> p >> q;
    char left=min(p, q);
    char right=max(p, q);
    map<char, int> mp;
    vector<int> sui={3,1,4,1,5,9};
    vector<int> pre(7, 0);
    rep(i, 6) pre[i+1]=pre[i]+sui[i];
    rep(i, 7) {
        mp['A'+i]=pre[i];
    }
    cout << mp[right]-mp[left] << endl;

    return 0;
}