#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a;
    cin >> n >> a;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    queue<long long> raw;
    int time=0;
    int i=0;
    while(i<n || raw.empty()!=true) {
        if(time==t[i]) {
            raw.push(a);
            i++;
        }
        time++;
        raw.front()--;
        if(raw.front()==0) {
            cout << time << endl;
            raw.pop();
        }
    }

    return 0;
}
