#include <bits/stdc++.h>
using namespace std;
int H, W, D;
char S[1009][1009];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> H >> W >> D;
    for (int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> S[i][j];
        }
    }
    bool visited[1009][1009];
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            visited[i][j]=false;
        }
    }
    queue<pair<pair<int, int>, int>> q;
    int dx[]={0, 0, -1, 1};
    int dy[]={-1, 1, 0, 0};
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (S[i][j]=='H') {
                q.push({{i, j}, 0});
                visited[i][j]=true;
            }
        }
    }
    int count=0;
    while (!q.empty()) {
        pair<pair<int, int>, int> current=q.front();
        q.pop();
        int x=current.first.first;
        int y=current.first.second;
        int dis=current.second;
        if (dis>D) continue;
        count++;
        for (int k=0; k<4; k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            if (nx>=0 && nx<H && ny>=0 && ny<W && !visited[nx][ny] && S[nx][ny]!='#') {
                visited[nx][ny]=true;
                q.push({{nx, ny}, dis+1});
            }
        }
    }

    cout << count << endl;
}
