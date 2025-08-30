#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    set<int> x;
    x.emplace(2*a-b);
    if((a+b)/2*2==a+b) x.emplace((a+b)/2);
    x.emplace(2*b-a);
    cout << x.size() << endl;
    return 0;
}