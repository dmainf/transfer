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
    int n, k, x;
    cin >> n >> k >> x;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<string> hako;
    rep(i, pow(n, k)) {
        string tmp;
        int cur=i;
        rep(bit, k) {
            tmp+=s[cur%n];
            cur/=n;
        }
        hako.push_back(tmp);
    }
    sort(all(hako));
    cout << hako[x-1] << endl;

    return 0;
}