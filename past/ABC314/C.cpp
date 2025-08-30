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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> c(n);
    vector<deque<int>> que(m);
    rep(i, n) {
        cin >> c[i];
        c[i]--;
        que[c[i]].push_back(i);
    }
    rep(i, m) {
        int tmp=que[i].back();
        que[i].pop_back();
        que[i].push_front(tmp);
    }
    rep(i, n) {
        int idx=que[c[i]].front();
        que[c[i]].pop_front();
        cout << s[idx];
    }
    cout << endl;

    return 0;
}