#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<long long> a(19);
    vector<long long> b(19);
    cin >> n;
    rep(i, n) cin >> a[i];

    vector<long long> ans;
    long long tmp;
    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                b[k]=a[k];
            }
            if(i!=j) {
                b[i]+=b[j];
                b[j]=0;
            }
            rep(k, n) {
                tmp=tmp^b[k];
            }
            if(find(ans.begin(), ans.end(), tmp) == ans.end()) {
                ans.push_back(tmp);
            }
        }
    }
    cout << ans.size() << endl;
	return 0;
}