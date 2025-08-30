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
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    int n=n1+n2;
    vector<vector<int>> G(n1+n2);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist_n1(n, -1);
    dist_n1[0]=0;
    queue<int> que1;
    que1.push(0);
    while(!que1.empty()) {
        int v=que1.front();
        que1.pop();
        for(int nv:G[v]) {
            if(dist_n1[nv]!=-1) continue;
            dist_n1[nv]=dist_n1[v]+1;
            que1.push(nv);
        }
    }
    vector<int> dist_n2(n, -1);
    dist_n2[n-1]=0;
    queue<int> que2;
    que2.push(n-1);
    while(!que2.empty()) {
        int v=que2.front();
        que2.pop();
        for(int nv:G[v]) {
            if(dist_n2[nv]!=-1) continue;
            dist_n2[nv]=dist_n2[v]+1;
            que2.push(nv);
        }
    }
    int mx_n1=0, mx_n2=0;
    rep(i, n1) mx_n1=max(mx_n1, dist_n1[i]);
    for(int i=n1; i<n; i++) {
        mx_n2=max(mx_n2, dist_n2[i]);
    }
    cout << mx_n1+mx_n2+1 << endl;

    return 0;
}