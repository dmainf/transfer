#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int a = s[0] - '0'; // '0' との文字コード差をとることで整数に変換
    int b = s[2] - '0';
    cout << a*b << endl;

	return 0;
}