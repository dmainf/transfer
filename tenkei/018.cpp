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
    int T, L, X, Y;
    cin >> T >> L >> X >> Y;
    int q; cin >> q;
    vector<double> ans;
    while(q--) {
        int e; cin >> e;
        e%=T;
        double theta=(double)e/T*2*M_PI;
        double cx=0.0;
        /*
        cy  =cos(-theta+PI/2)
            =-sin(-theta)
            =sin(theta)
        cz  =sin(-theta+PI/2)
            =cos(-theta)
            =cos(theta)
        */
        double cy=-(L/2.0)*sin(theta);
        double cz=-(L/2.0)*cos(theta)+(L/2.0);
        double dx=X-cx;
        double dy=Y-cy;
        double dist=sqrt(dx*dx+dy*dy);
        double angle=atan2(cz, dist);
        cout<<fixed<<setprecision(12)<<angle*180.0/M_PI<<endl;
    }
    for(double x:ans) cout << x << endl;

    return 0;
}