#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define drep(i, n) for(int i=(n)-1;i>=0;i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    int ans=0;
    rep(i, 1000) {
        string t="";
        t+=i/100+'0';
        t+=i/10%10+'0';
        t+=i%10+'0';
        int now=0;
        rep(i, n) {
            if(t[now]==s[i]) now++;
            if(now==3) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
