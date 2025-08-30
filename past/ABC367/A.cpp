#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    bool ans=false;;
    if(b<c) {
        if(!(b<a && a<c)) ans=true;
    } else {
        if(c<a && a<b) ans=true;
    }
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
