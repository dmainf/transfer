#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<ll> ans;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n*2);
        ll total=0;
        rep(i, n*2) {
            cin >> a[i];
            total+=a[i];
        }
        priority_queue<ll, vector<ll>, less<ll>> pq;
        //400 500 200 100 300 600
        //(())()
        rep(i, n*2) {
            pq.push(a[i]);
            //because of 0-index, i+1
            int cap=(i+1)/2;
            if(cap<(int)pq.size()) pq.pop();
        }
        ll sum=0;
        while(!pq.empty()) {
            sum+=pq.top();
            pq.pop();
        }
        ans.push_back(total-sum);
    }
    for(auto x:ans) cout << x << endl;

    return 0;
}