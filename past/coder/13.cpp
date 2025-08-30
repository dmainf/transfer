#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define drep(i, n) for(int i=(n)-1;i>=0;i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;
    vector<bitset<10>> col(c);
    rep(i, r) rep(j, c) {
        int x;
        cin >> x;
        if(x==1) col[j].set(i);
    }
    int ans=0;
    rep(x, 1<<r) {
        bitset<10> xx(x);
        int tmp=0;
        rep(i, c) {
            bitset<10> newcol=col[i]^xx;//行反転
            int cnt=newcol.count();
            tmp+=max(cnt, r-cnt);//列反転はここだけ
            //裏返して多くなるなら裏返すだけ
        }
        ans=max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}