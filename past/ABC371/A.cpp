#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string sab, sac, sbc;
    cin >> sab >> sac >> sbc;
    string s;
    s=sab+sac+sbc;
    char ans;
    if(s=="<<<") ans='B';
    if(s=="<<>") ans='C';
    if(s=="<>>") ans='A';
    if(s=="><<") ans='A';
    if(s==">><") ans='C';
    if(s==">>>") ans='B';
    cout << ans << endl; 

    return 0;
}
