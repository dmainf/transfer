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
    string u="";
    rep(i, t.size()) u+=tolower(t[i]);
    int ui=0;//何個あっているか
    for(char c : s) {
        if(u[ui]==c) {
            ui++;
        }
        if(ui==3 || (ui==2 && t[2]=='X')) {
            Yes;
            return 0;
        }
    }
    No;

    return 0;
}