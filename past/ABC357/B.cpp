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
    string s;
    cin >> s;
    int la=0, sm=0;
    rep(i, s.size()) {
        if('A'<=s[i] && s[i]<='Z') la++;
        else sm++;
    }
    rep(i, s.size()) {
        if(la>sm) {
            if('a'<=s[i] && s[i]<='z') s[i]=s[i]-'a'+'A';
        } else {
            if('A'<=s[i] && s[i]<='Z') s[i]=s[i]-'A'+'a';
        }
    }//isupper toupperでいいやん怒
    cout << s << endl;

    return 0;
}
