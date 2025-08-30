#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> c(3, vector<int>(3));
    rep(i, 3) rep(j, 3) {
        cin >> c[i][j];
    }
    //0 1 2
    //3 4 5 
    //6 7 8     c[i/3][i%3]
    vector<int> p;
    rep(i, 9) p.push_back(i);
    int out=0;
    int sum=0;
    do {
        vector<vector<int>> row(3, vector<int>(10, 0));
        vector<vector<int>> col(3, vector<int>(10, 0));
        vector<int> crol(10, 0);
        vector<int> cror(10, 0);
        bool flag=false;
        for(int i:p) {
            rep(k, 10) {
                if(row[i/3][k]==2) flag=true;
                if(col[i%3][k]==2) flag=true;
                if(i==0 || i==4 || i==8) if(crol[k]==2) flag=true;
                if(i==2 || i==4 || i==6) if(cror[k]==2) flag=true;                
            }
            int x=c[i/3][i%3];
            row[i/3][x]++;
            col[i%3][x]++;
            if(i==0 || i==4 || i==8) crol[x]++;
            if(i==2 || i==4 || i==6) cror[x]++;
        }
        if(flag) out++;
        sum++;
    } while(next_permutation(all(p)));
    double ans=1.0-(double)out/(double)sum;
    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}