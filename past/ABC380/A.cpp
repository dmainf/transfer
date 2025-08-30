#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    if(count(n.begin(), n.end(), '1')==1) {
        if(count(n.begin(), n.end(), '2')==2) {
            if(count(n.begin(), n.end(), '3')==3) {
                cout << "Yes" << endl;
                return 0;
            }   
        }
    }
    cout << "No" << endl;

	return 0;
}