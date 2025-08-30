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
    int n;
    string s;
    cin >> n >> s;
    bool flag=false;
    rep(i, n-1) {
        if(s[i]=='a' && s[i+1]=='b') flag=true;
        if(s[i]=='b' && s[i+1]=='a') flag=true;        
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}