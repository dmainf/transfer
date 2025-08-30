#include <bits/stdc++.h>
using namespace std;
int H, W, D;
char S[19][19];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> H >> W >> D;
    for(int i=1; i<=H; i++) {
        for(int j=1; j<=W; j++) {
            cin >> S[i][j];
        }
    }
    int answer[10009];
    for(int i=0; i<=10009; i++) answer[i]=0;
    int count=0;
    for(int i=1; i<=H; i++) {
        for(int j=1; j<=W; j++) {
            for(int k=1; k<=H; k++) {
                for(int l=1; l<=W; l++) {
                    for(int a=1; a<=H; a++) {
                        for(int b=1; b<=W; b++) {
                            if(S[i][j]=='.'&&S[k][l]=='.'&&S[a][b]=='.') {
                                int div1=abs(a-i)+abs(b-j);
                                int div2=abs(a-k)+abs(b-l);
                                if(div1<=D || div2<=D) {
                                    answer[count]++;
                                }
                            } else {
                            }
                        }
                    }
                    count++;
                }
            }
        }
    }
    int ans=0;
    for(int i=1; i<=10009; i++) {
        ans=max(ans, answer[i]);
    }
    cout << ans << endl;;
}