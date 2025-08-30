#include <bits/stdc++.h>
using namespace std;
#define rep(coin, s) for(int coin=0;coin<(s);coin++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
const int MAX=1000000;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a, b;
    for(int coin=1;; coin++) {
        int tmp=coin*(coin+1)*(coin+2)/6;
        if(tmp>MAX) break;
        a.push_back(tmp);
        if(tmp%2==1) b.push_back(tmp);
    }
    vector<int> dp_a(MAX+1, INF);
    dp_a[0]=0;
    for(int coin:a) for(int j=coin; j<=MAX; j++) {
        dp_a[j]=min(dp_a[j], dp_a[j-coin]+1);
    }
    vector<int> dp_b(MAX+1, INF);
    dp_b[0]=0;
    for(int coin:b) for(int j=coin; j<=MAX; j++) {
        dp_b[j]=min(dp_b[j], dp_b[j-coin]+1);
    }
    int n;
    while(cin >> n && n!=0){
        cout << dp_a[n] << " " << dp_b[n] << endl;
    }

    return 0;
}