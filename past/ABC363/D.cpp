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
    if(n==1) {
        cout << 0 << endl;
        return 0;
    }
    n--;
    for(int digit=1;; digit++) {
        int l=(digit+1)/2;
        ll num=9;
        rep(i, l-1) num*=10;
        if(n>num) {
            n-=num;
            continue;
        }
        n+=num/9-1;
        string s=to_string(n);
        string rs=s;
        reverse(all(rs));
        if(digit%2==1) s.pop_back();
        s+=rs;
        cout << s << endl;
        return 0;
    }

    return 0;
}
