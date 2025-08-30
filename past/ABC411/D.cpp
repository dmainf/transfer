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
    int n, q;
    cin >> n >> q;
    vector<int> moji(1);
    vector<int> pre;
    pre.push_back(0);
    vector<int> head(n+1, 0);
    while(q--) {
        int com;
        cin >> com;
        if(com==1) {
            int p;
            cin >> p;
            head[p]=head[0];
        }
        if(com==2) {
            int p;
            string s;
            cin >> p >> s;
            for(char c:s) {
                moji.push_back(c);
                pre.push_back(head[p]);
                head[p]=moji.size()-1;
            }
        }
        if(com==3) {
            int p;
            cin >> p;
            head[0]=head[p];
        }
    }
    string ans;
    for(int v=head[0]; v!=0; v=pre[v]) ans.push_back(moji[v]);
    reverse(all(ans));
    cout << ans << endl;

    return 0;
}