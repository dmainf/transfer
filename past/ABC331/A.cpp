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
    int M, D, y, m, d;
    cin >> M >> D;
    cin >> y >> m >> d;
    d++;
    if(D<d) d=1, m++;
    if(M<m) m=1, y++;
    cout << y << " " << m << " " << d << endl;

    return 0;
}
