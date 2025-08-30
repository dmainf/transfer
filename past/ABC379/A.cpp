#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;
    string a, b, c;
    a=n[0]; b=n[1]; c=n[2];
    cout << b << c << a << " ";
    cout << c << a << b << endl;

	return 0;
}