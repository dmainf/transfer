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
    vector<vector<int>> box(n+1);
    map<int, vector<int>> card;
    vector<vector<int>> ans;
    while(q--) {
        int com, i;
        cin >> com >> i;
        if(com==1) {
            int j;
            cin >> j;
            box[j].push_back(i);
            card[i].push_back(j);
        }
        if(com==2) {
            sort(all(box[i]));
            ans.push_back(box[i]);
        }
        if(com==3) {
            sort(all(card[i]));
            card[i].erase(unique(all(card[i])), card[i].end());
            ans.push_back(card[i]);
        }
    }
    for(auto tmp:ans) {
        for(int x:tmp) cout << x << " ";
        cout << endl;
    }

    return 0;
}