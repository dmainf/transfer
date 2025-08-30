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
const int MAX=24*60*60;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto t_i=[&](string str) -> int{
        int res=0;
        res += stoi(str.substr(0, 2)) * 60 * 60;
        res += stoi(str.substr(3, 2)) * 60;
        res += stoi(str.substr(6, 2));  
        return res;
    };
    int n;
    while(cin >> n && n!=0) {
        vector<int> train(MAX+1, 0);
        rep(i, n) {
            string str1, str2;
            cin >> str1 >> str2;
            int start=t_i(str1);
            int goal=t_i(str2);
            train[start]++;
            train[goal]--;
        }
        for(int i=1; i<=MAX; i++) train[i]+=train[i-1];
        int ans=0;
        rep(i, MAX+1) ans=max(ans, train[i]);
        cout << ans << endl;
    }

    return 0;
}
