#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    bool flag=false;
    if(a==b && b==c) flag=true;
    if(a+b==c) flag=true;
    if(b+c==a) flag=true;
    if(c+a==b) flag=true;
    if(flag) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}