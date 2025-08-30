#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a, b(n, n);
    rep(i, n) {
        int tmp;
        cin >> tmp;
        tmp--;
        a.push_back(tmp);
    }
    int front;
    rep(i, n) {
        if(a[i]<0) front=i;
        else b[a[i]]=i;
    }
    rep(i, n) {
        cout << front+1 << " \n"[i==n-1];
        front=b[front];
    }

    return 0;
}