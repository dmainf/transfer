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
    int  m;
    cin >> m;
    vector<int> d(m);
    int sum=0;
    rep(i, m) {
        cin >> d[i];
        sum+=d[i];
    }
    int half=(sum+1)/2;
    int a, b;
    rep(i, m) {
        if(0<half-d[i]) half-=d[i];
        else {
            a=i+1;
            b=half;
            cout << a << " " << b << endl;
            return 0;
        }
    }

    return 0;
}