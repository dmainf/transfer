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
    vector<int> card(14, 0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    card[a]++;
    card[b]++;
    card[c]++;
    card[d]++;
    vector<int> count(5, 0);
    for(int i=1; i<=13; i++) {
        count[card[i]]++;
    }
    if(count[2]==2 || (count[3]==1 && count[1]==1)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}