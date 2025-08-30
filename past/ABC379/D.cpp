#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    queue<ll> plant;
    ll time=0;
    rep(i, q) {
        int query;
        cin >> query;
        if(query==1) {
           plant.push(time); 
        }
        if(query==2) {
            int t;
            cin >> t;
            time+=t;
        }
        if(query==3) {
            int ans=0;
            int h;
            cin >> h;
            while(!plant.empty() && time-plant.front()>=h) {
                plant.pop();
                ans++;
            }
            cout << ans << endl;
        }
    }

    return 0;
}