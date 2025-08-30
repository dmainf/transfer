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
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool A=false;
    bool B=false;
    bool C=false;
    rep(i, n) {
        if(s[i]=='A') A=true;
        if(s[i]=='B') B=true;
        if(s[i]=='C') C=true;        
        if(A && B && C) {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}