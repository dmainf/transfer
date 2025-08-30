#include<bits/stdc++.h>
using namespace std;
int N, D;
string S;
int main() {
    cin >> N >> D;
    cin >> S;
    
    int count=0;
    for(int i=0; i<N; i++) {
        if(S[i]=='@') count++;
    }
    for(int i=0; i<N; i++) {
        if(S[i]=='.') {
            cout << '.';
        } else {
            if(count-D>0) {
                cout << '@';
            } else {
                cout << '.';
            }
            count--;
        }
    }
    cout << endl;
} 