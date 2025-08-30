#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    int q;
    cin >> q;
    vector<char> ch(26);
    rep(i, 26) ch[i]='a'+i;
    rep(i, q) {
        char c, d;
        cin >> c >> d;
        rep(j, 26) if(ch[j]==c) {
            ch[j]=d;
        }
    }
    rep(i, n) cout << ch[s[i]-'a'];
    cout << endl;

    return 0;
}
