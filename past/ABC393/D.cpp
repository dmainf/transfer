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
    int n;
    string s;
    cin >> n >> s;
    vector<int> one;
    rep(i, n) {
        if(s[i]=='1')
        one.push_back(i);
    }
    int mid=one.size()/2;
    long long ans=0;
    rep(i, one.size()) ans+=abs((one[i]-one[mid])+mid-i);//one[mid]+mid：目標区間の中央
    cout << ans << endl;

    return 0;
}