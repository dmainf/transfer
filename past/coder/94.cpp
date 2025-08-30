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
const int MAX=1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true){
        int n, w, d;
        cin >> n >> w >> d;
        if(n == 0 && w == 0 && d == 0) break;
        
        // 最初は1つのケーキ(長方形)だけがある
        vector<pair<int,int>> pieces;
        pieces.push_back({w, d});
        
        // n回のカットをシミュレート
        for (int i = 0; i < n; i++){
            int p, s;
            cin >> p >> s;
            int idx = p - 1; // 0-indexed に変換
            int cw = pieces[idx].first;
            int ch = pieces[idx].second;
            
            // 選んだピースは削除
            pieces.erase(pieces.begin() + idx);
            
            int perim = 2 * (cw + ch);
            int effective_s = s % perim;
            if(effective_s == 0) effective_s = perim;
            
            pair<int,int> piece1, piece2;
            // 北側：上辺
            if(effective_s < cw){
                int cutPos = effective_s;
                piece1 = {cutPos, ch};         // 左側
                piece2 = {cw - cutPos, ch};      // 右側
            }
            // 東側：右辺
            else if(effective_s < cw + ch){
                int cutPos = effective_s - cw;
                piece1 = {cw, cutPos};           // 上側
                piece2 = {cw, ch - cutPos};      // 下側
            }
            // 南側：下辺
            else if(effective_s < 2 * cw + ch){
                int cutPos = effective_s - (cw + ch);
                piece1 = {cw - cutPos, ch};      // 左側
                piece2 = {cutPos, ch};           // 右側
            }
            // 西側：左辺
            else {
                int cutPos = effective_s - (2 * cw + ch);
                piece1 = {cw, ch - cutPos};      // 上側
                piece2 = {cw, cutPos};           // 下側
            }
            
            // 2つの新ピースは面積が小さい方に小さい識別番号を与える
            int area1 = piece1.first * piece1.second;
            int area2 = piece2.first * piece2.second;
            if(area1 > area2) swap(piece1, piece2);
            
            pieces.push_back(piece1);
            pieces.push_back(piece2);
        }
        
        // 最終的な各ピースの面積を計算しソート
        vector<int> areas;
        for(auto &p: pieces){
            areas.push_back(p.first * p.second);
        }
        sort(areas.begin(), areas.end());
        
        // 結果を出力（空白で区切る）
        for (size_t i = 0; i < areas.size(); i++){
            cout << areas[i];
            if(i + 1 < areas.size()) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
