#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int  n, q;
    cin >> n >> q;
    vector<bool> col(n, false);
    //false white
    //true  black
    int now=0;
    //2 3 3 5 1 5 2
    while(q--) {
        int a;
        cin >> a;
        a--;
        int left=a>0 && col[a-1];
        int right=a<=n && col[a+1];
        if(!col[a]) {
            now+=1-left-right;
            col[a]=true;
        } else {
            now-=1-left-right;
            col[a]=false;
        }
        cout << now << endl;
    }


    return 0;
}