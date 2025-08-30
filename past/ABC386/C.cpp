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
    int k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    int def=0;
    if(s.size()==t.size()) {
        rep(i, s.size()) if(s[i]!=t[i]) {
            def++;
        }
    } else {
        int i=0, j=0;
        while(i<s.size() && j<t.size()) {
            if(s[i]!=t[j]) {
                def++;
                if(s.size()<t.size()) i--;
                else j--;
            }
            i++;
            j++;
        }
        def+=max(s.size(), t.size())-max(i, j);
    }
    if(def<=k) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}