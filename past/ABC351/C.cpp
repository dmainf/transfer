#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    stack<ll> st;
    rep(i, n){
        int a;
        cin >> a;
        st.push(a);
        while(st.size()>=2){
            ll top=st.top();
            st.pop();
            ll next=st.top();
            if(top==next){
                st.pop();
                st.push(top+1);
            } else {
                st.push(top);
                break;
            }
        }
    }
    cout << st.size() << endl;

    return 0;
}