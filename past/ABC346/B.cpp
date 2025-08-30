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
    int w, b;
    cin >> w >> b;
    string s="wbwbwwbwbwbw";
    rep(i, 5) s+=s;
    rep(k, 12) {
        int wi=0, bi=0;
        for(int i=k; i<s.size(); i++) {
            if(s[i]=='w') wi++;
            else bi++;
            if(wi==w && bi==b) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
