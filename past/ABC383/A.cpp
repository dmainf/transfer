#include <bits/stdc++.h>
using namespace std;
int N;
int T[109], V[100000009];
int main(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> T[i] >> V[T[i]];
    int water=0;
    int count=1;
    for(int i=1; i<=T[N]; i++) {
        if(water>0) water--;
        if(i==T[count]) {
            water+=V[T[count]];
            count++;
        }
    }
    cout << water << endl;
}