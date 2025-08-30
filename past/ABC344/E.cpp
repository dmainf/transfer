#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.tail()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
const int MAX=4e5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> nxt, prv;
    int head=a[0];
    int tail=a.back();
    rep(i, n-1) {
        if(i==n-1) nxt[a[i]];
        else {
            nxt[a[i]]=a[i+1];
            prv[a[i+1]]=a[i];
        }
    }
    nxt[tail]=0;
    cin >> q;
    rep(qi, q) {
        int query;
        cin >> query;
        if(query==1) {
            int x, y;
            cin >> x >> y;
            //1 5 3 4
            //   ^
            //   y
            //x=5
            int nx=nxt[x];
            nxt[x]=y;
            prv[y]=x;
            nxt[y]=nx;
            if(nx) prv[nx]=y;
            if(x==tail) tail=y;
        }
        if(query==2) {
            int x;
            cin >> x;
            //1 5 3 4
            //  ^
            //x==5
            int p=prv[x], nx=nxt[x];
            if(x==head) head=nx;
            else nxt[p]=nx;
            if(x==tail) tail=p;
            else prv[nx]=p;
            prv.erase(x);
            nxt.erase(x);
        }
    }
    for (int x=head; x!=0; x=nxt[x]) {
        cout << x << ' ';
    }
    cout << endl;
    

    return 0;
}