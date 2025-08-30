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
    int t; cin >> t;
    vector<int> ans;
    while(t--) {
        int n;
        cin >> n;
        vector<int> domino;
        int start, goal;
        rep(i, n) {
            int s; cin >> s;
            if(i==0) start=s;
            else if(i==n-1) goal=s;
            else domino.push_back(s);
        }
        sort(all(domino));
        int now=start;
        int cnt=0;
        bool flag=false;
        if(goal<=now*2) {
            flag=true;
        } else {
            while(true) {
                auto next=upper_bound(all(domino), now*2);
                if(next==domino.begin()) break; //初手すら無理+next--の配列外アクセス予防
                next--;
                if(*next<=now) break;   //変化なし(=進めない)
                cnt++;
                if(goal<=*next*2) {
                    flag=true;
                    break;
                }
                now=*next;
            }
        }
        ans.push_back(flag ? cnt+2:-1);
    }
    for(int x:ans) cout << x << endl;

    return 0;
}