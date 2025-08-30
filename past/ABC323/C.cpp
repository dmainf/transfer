#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
using ll=long long;
using pi=pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<int> score(n, 0);
    rep(i, n) {
        score[i]+=i+1;
        rep(j, m) if(s[i][j]=='o') {
            score[i]+=a[j];
        }
    }
    int mx=*max_element(all(score));
    rep(i, n) {
        vector<int> tmp;
        rep(j, m) if(s[i][j]=='x') {
            tmp.push_back(a[j]);
        }
        sort(rall(tmp));
        int cnt=0;
        while(score[i]<mx) {
            score[i]+=tmp[cnt];
            cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}