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
    string s;
    cin >> s;
    int ans;
    if(s=="tourist") ans=3858;
    if(s=="ksun48") ans=3679;
    if(s=="Benq") ans=3658;
    if(s=="Um_nik") ans=3648;
    if(s=="apiad") ans=3638;
    if(s=="Stonefeang") ans=3630;
    if(s=="ecnerwala") ans=3613;
    if(s=="mnbvmar") ans=3555;
    if(s=="newbiedmy") ans=3516;
    if(s=="semiexp") ans=3481;
    cout << ans << endl;

    return 0;
}