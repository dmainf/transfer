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
    ll n;
    cin >> n;
    ll ans=0;
    //2の部分
    for(int a=1; (n>>a); a++) {
        //2で割った数
        ll tmp=n>>a;
        ll m=sqrt((long double)tmp);
        while((m+1)*(m+1)<=tmp) m++;
        while(m*m>tmp) m--;
        ans+=(m+1)/2;
    }
    cout << ans << endl;

    return 0;
}