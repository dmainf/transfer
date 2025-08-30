#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>> q;
    vector<int> box(1e6, 0);
    int sum=0;
    rep(i, q) {
        int query;
        cin >> query;
        if(query==1) {
            int x;
            cin >> x;
            if(box[x]==0) sum++;
            box[x]++;
        }
        if(query==2) {
            int x;
            cin >> x;
            if(box[x]==1) sum--;
            box[x]--; 
        }
        if(query==3) cout << sum << endl;
    }

    return 0;
}
