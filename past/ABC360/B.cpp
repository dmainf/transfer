#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    for(int w=1; w<s.size(); w++) {
        string ns=s;
        vector<string> str;
        while(ns.size()>w) {
            str.push_back(ns.substr(0, w));
            ns.erase(ns.begin(), ns.begin()+w);
        }
        str.push_back(ns);//余り
        rep(c, w) {
            string nt="";//縦読み
            for(string ns : str) {
                if(c<ns.size()) nt+=ns[c];
            }
            if(nt==t) {
                Yes;
                return 0;
            }
        }
    }
    No;

    return 0;
}