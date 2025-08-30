#include<bits/stdc++.h>
using namespace std;
int N, D;
string S;
int main() {
    cin >> N >> D;
    cin >> S;

    int cokies=0;
    for(int i=1; i<=N; i++) {
        if(S[i-1]=='@') {
            cokies++;
        }
    }
    cout << N-cokies+D << endl;
}