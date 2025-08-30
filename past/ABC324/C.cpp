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
    string t;
    cin >> n >> t;
    vector<int> ans;
    for(int ni=1; ni<=n; ni++) {
        string s;
        cin >> s;
        bool flag=false;
        int Size=max(t.size(), s.size());
        if(t.size()==s.size()) {
            int diff=0;
            rep(i, Size) if(s[i]!=t[i]) {
                diff++;
            }
            if(diff<=1) flag=true;
        }
        if(t.size()==s.size()+1) {
            int si=0, ti=0;
            int diff=0;
            //t:asdfgh
            //s:asfgh
            rep(i, Size) {
                if(s[si]!=t[ti]) {
                    si--;
                    diff++;
                }
                si++; ti++;
            }
            if(diff<=1) flag=true;
        }
        if(t.size()==s.size()-1) {
            int si=0, ti=0;
            int diff=0;
            rep(i, Size) {
                if(s[si]!=t[ti]) {
                    ti--;
                    diff++;
                }
                si++; ti++;
            }
            if(diff<=1) flag=true;
        }
        if(flag) ans.push_back(ni);
    }
    int k=ans.size();
    cout << k << endl;
    for(auto x:ans) cout << x << " ";
    cout << endl;

    return 0;
}
