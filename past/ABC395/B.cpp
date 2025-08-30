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
    vector<string> a(n, string(n, '?'));
    rep(i, n) {
        int j=n-1-i;
        if(i<=j) {
            char tmp;
            if(i%2==0) tmp='#';
            else tmp='.';
            for(int ni=i; ni<=j; ni++) for(int nj=i; nj<=j; nj++) {
                a[ni][nj]=tmp;
            }
        }
    }
    rep(i, n) cout << a[i] << endl;

    return 0;
}