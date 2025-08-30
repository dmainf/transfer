#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string d;
    cin >> d;
    rep(i, d.size()) {
        if(d[i]=='N') cout << 'S';
        if(d[i]=='S') cout << 'N';
        if(d[i]=='W') cout << 'E';
        if(d[i]=='E') cout << 'W';
    }
    cout << endl;

	return 0;
}