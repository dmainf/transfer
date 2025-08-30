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
    int  n;
    cin >> n;
    vector<pair<int, string>> human(n);
    int mn=INF, mn_idx;
    rep(i, n) {
        string s;
        cin >> s;
        int a;
        cin >> a;
        if(a<mn) {
            mn=a;
            mn_idx=i;
        }
        human[i]={a, s};
    }
    rotate(human.begin(), human.begin()+mn_idx, human.end());
    for(auto [z, name]:human) cout << name << endl;

    return 0;
}