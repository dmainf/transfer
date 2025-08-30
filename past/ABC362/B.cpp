#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> x(3), y(3);
    rep(i, 3) cin >> x[i] >> y[i];
    vector<int> len(3);
    int max=0, mx;
    rep(i, 3) {
        len[i]=pow(x[i]-x[(i+1)%3], 2)+pow(y[i]-y[(i+1)%3], 2);
        if(max<len[i]) {
            max=len[i]; mx=i;
        }
    }
    if(mx==0) {
        if(len[0]==len[1]+len[2]) Yes;
        else No;
    }
    if(mx==1){
        if(len[1]==len[0]+len[2]) Yes;
        else No;
    }
    if(mx==2) {
        if(len[2]==len[0]+len[1]) Yes;
        else No;
    }


    return 0;
}
