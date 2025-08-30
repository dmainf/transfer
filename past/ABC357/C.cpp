#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    int n;
    cin >> n;
    int size=pow(3, n);
    rep(i, size) {
        rep(j, size) {
            int x=i, y=j;
            bool isWhite=false;
            while (x>0 || y>0) {
                if (x%3==1 && y%3==1) {
                    isWhite=true;
                    break;
                }
                x/=3;
                y/=3;
            }
            cout << (isWhite ? '.' : '#');
        }
        cout << endl;;
    }
    return 0;
}
