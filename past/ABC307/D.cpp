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
    int n;
    cin >> n;
    string s;
    cin >> s;
    deque<char> dq;
    int cnt=0;
    //a(b)(
    rep(i, n) {
        if(s[i]=='(') cnt++;
        if(s[i]==')' && 0<cnt) {
            while(dq.back()!='(') dq.pop_back();
            dq.pop_back();
            cnt--;
        } else dq.push_back(s[i]);
    }
    while(!dq.empty()) {
        cout << dq.front();
        dq.pop_front();
    }
    cout << endl;

    return 0;
}