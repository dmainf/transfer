#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> box(n, 1);
    vector<int> hato(n);
    rep(i, n) hato[i]=i;
    set<int> ans;
    rep(i, q) {
        int query;
        cin >> query;
        if(query==1) {
            int p, h;
            cin >> p;
            p--;
            box[hato[p]]--;
            if(box[hato[p]]<2) ans.erase(hato[p]);
            cin >> h;
            h--;
            hato[p]=h;
            box[h]++;
            if(box[h]>1) ans.emplace(h);
        } else {
            cout << ans.size() << endl;
        }
    }
    
	return 0;
}