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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool head=false, tail=false;
    if(t.substr(0, s.size())==s) head=true;
    //fgh
    //asdfgh
    if(t.substr(t.size()-s.size(), s.size())==s) tail=true;
    if     (head&&tail) cout << 0 << endl;
    else if(head&&!tail) cout << 1 << endl;
    else if(!head&&tail) cout << 2 << endl;
    else cout << 3 << endl;

    return 0;
}