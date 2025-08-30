#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n==1) {
            cout << s << endl;
            continue;
        }
        int l=-1, r=n-1;
        rep(i, n-1) if(s[i]>s[i+1]) {
            l=i;
            break;
        }
        if(l<0) {
            cout << s << endl;
            continue;
        }
        for(int i=l+1; i<n; i++) if(s[l]<s[i]) {
            r=i-1;
            break;
        }
        string t=s;
        for(int i=l; i<r; i++) {
            t[i]=s[i+1];
        }
        t[r]=s[l];
        cout << t << endl;
    }

    return 0;
}