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
    while(true) {
        int n, m;
        cin >> n >> m;
        if(n==0 && m==0) break;
        vector<vector<char>> c(n, vector<char>(m));
        rep(i, n) rep(j, m) cin >> c[i][j];
        //.##..#
        //#..##.
        //#..##.
        //.##..#
        vector<vector<int>> cnt(n, vector<int>(m));
        bool flag=false;
        int point=0;
        rep(i, n-1) rep(j, m-1) {
            if(c[i][j]=='.'&&c[i][j+1]=='#'&&c[i+1][j]=='#'&&c[i+1][j+1]=='#') flag=true;
            if(c[i][j]=='#'&&c[i][j+1]=='.'&&c[i+1][j]=='#'&&c[i+1][j+1]=='#') flag=true;
            if(c[i][j]=='#'&&c[i][j+1]=='#'&&c[i+1][j]=='.'&&c[i+1][j+1]=='#') flag=true;
            if(c[i][j]=='#'&&c[i][j+1]=='#'&&c[i+1][j]=='#'&&c[i+1][j+1]=='.') flag=true;
            if(c[i][j]=='#'&&c[i][j+1]=='.'&&c[i+1][j]=='.'&&c[i+1][j+1]=='.') flag=true;
            if(c[i][j]=='.'&&c[i][j+1]=='#'&&c[i+1][j]=='.'&&c[i+1][j+1]=='.') flag=true;
            if(c[i][j]=='.'&&c[i][j+1]=='.'&&c[i+1][j]=='#'&&c[i+1][j+1]=='.') flag=true;
            if(c[i][j]=='.'&&c[i][j+1]=='.'&&c[i+1][j]=='.'&&c[i+1][j+1]=='#') flag=true;
            //cnt==0
            //cnt==1  
            if(c[i][j]=='.'&&c[i][j+1]=='#'&&c[i+1][j]=='#'&&c[i+1][j+1]=='.') {
                //cout << i << " " << j << endl;
                cnt[i][j]++;
                point++;
            }
            if(c[i][j]=='#'&&c[i][j+1]=='.'&&c[i+1][j]=='.'&&c[i+1][j+1]=='#') {                            
                //cout << i << " " << j << endl;
                cnt[i][j]++;
                point++;
            }
        }
        if(flag) {
            cout << -1 << endl;
            continue;
        }
        if(point==1) {
            cout << 0 << endl;
            continue;
        }
        vector<int> sq_size;
        {
            rep(i, n) {
                int pre_yoko=-1;
                rep(j, m) if(0<cnt[i][j]) {
                    if(pre_yoko==-1) {
                        pre_yoko=j;
                        continue;
                    }
                    int tmp=j-pre_yoko;
                    sq_size.push_back(tmp);
                    pre_yoko=j;
                }
            }
        }
        {
            rep(j, m) {
                int pre_tate=-1;
                rep(i, n) if(0<cnt[i][j]) {
                    if(pre_tate==-1) {
                        pre_tate=i;
                        continue;
                    }
                    int tmp=i-pre_tate;
                    sq_size.push_back(tmp);
                    pre_tate=i;
                }
            }
        }
        if(sq_size.size()==0) {
            /*
            bool tate1=false;
            bool tate2=false;
            rep(i, n) rep(j, m-1) {
                if(c[i][j]=='.'&&c[i][j+1]=='#') tate1=true;
                if(c[i][j]=='#'&&c[i][j+1]=='.') tate2=true;
            }
            bool yoko1=false;
            bool yoko2=false;
            rep(i, n-1) rep(j, m) {
                if(c[i][j]=='.'&&c[i+1][j]=='#') yoko1=true;
                if(c[i][j]=='#'&&c[i+1][j]=='.') yoko2=true;
            }
            if((tate1&&tate2) || (yoko1&&yoko2)) {
                cout << "b" << endl;
                cout << -1 << endl;
                continue;
            }
            */
            {
                vector<pair<int, char>> p;
                rep(i, n) {
                    if(!p.empty() && p.back().second==c[i][0]) p.back().first++;
                    else p.push_back({1, c[i][0]});
                }
                if(p.size()<=2) {
                    cout << 0 << endl;
                    continue;
                }
                if(*min_element(p.begin()+1, p.end()-1)!=*max_element(p.begin()+1, p.end()-1)) {
                    cout << -1 << endl;
                    continue;
                }
                if(!(p[0].first<=p[1].first) || !(p.back().first<=p[1].first)) {
                    cout << -1 << endl;
                    continue;
                }
                if(p[1].first<m) {
                    cout << -1 << endl;
                    continue;
                }
            }
            {
                vector<pair<int, char>> p;
                rep(j, m) {
                    if(!p.empty() && p.back().second==c[0][j]) p.back().first++;
                    else p.push_back({1, c[0][j]});
                }
                if(p.size()<=2) {
                    cout << 0 << endl;
                    continue;
                }
                if(*min_element(p.begin()+1, p.end()-1)!=*max_element(p.begin()+1, p.end()-1)) {
                    cout << -1 << endl;
                    continue;
                }
                if(!(p[0].first<=p[1].first) || !(p.back().first<=p[1].first)) {
                    cout << -1 << endl;
                    continue;
                }
                if(p[1].first<n) {
                    cout << -1 << endl;
                    continue;
                }
            }
            cout << 0 << endl;
            continue;
        }
        if(*min_element(all(sq_size))!=*max_element(all(sq_size))) {
            cout << -1 << endl;
            continue;
        }
        cout << sq_size.front() << endl;
    }

    return 0;
}