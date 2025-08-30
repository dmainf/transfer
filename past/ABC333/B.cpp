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
    char s1,s2,t1,t2;
    cin >> s1 >> s2 >> t1 >> t2;
    auto f=[&](char x, char y) {
        if(x>y) swap(x, y);
        if(y-x==1 || y-x==4) return true;
        else return false;
    };
    if(f(s1, s2)==f(t1, t2)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
