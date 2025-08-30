#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<map<int, int>> sai(n);
    vector<int> nface(n);
    rep(i, n) {
        int k;
        cin >> k;
        nface[i]=k;
        rep(j, k) {
            int a;
            cin >> a;
            sai[i][a]++;
        }
    }
    double ans=0.0;
    rep(i, n) {
        rep(j, n){
            if(i==j) continue;
            double prob = 0.0;
            if(sai[i].size()<sai[j].size()){
                for(auto &p : sai[i]){
                    int face=p.first;
                    int cnti=p.second;
                    if(sai[j].count(face)){
                        int cntj=sai[j][face];
                        prob+=(double)cnti/nface[i]*(double)cntj/nface[j];
                    }
                }
            } else {
                for(auto &p : sai[j]){
                    int face=p.first;
                    int cntj=p.second;
                    if(sai[i].count(face)){
                        int cnti=sai[i][face];
                        prob+=(double)cnti / nface[i] * (double)cntj / nface[j];
                    }
                }
            }
            ans=max(ans, prob);
        }
    }
    
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}