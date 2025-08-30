#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int ans=0;
    rep(i, n-2) {
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') ans++;
    }
    rep(i, q) {//ABCBC
        int x;
        char c;
        cin >> x >> c;
        x--;
        int bef=0;
        //↓substrで良かった
        rep(j, 3) if(s[x-2+j]=='A'&&s[x-1+j]=='B'&&s[x+j]=='C') bef++;
        s[x]=c;
        int aft=0;
        rep(j, 3) if(s[x-2+j]=='A'&&s[x-1+j]=='B'&&s[x+j]=='C') aft++;
        cout << ans-bef+aft << endl;
        
        ans=ans-bef+aft;
    }

    return 0;
}
