#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> A(5);
    for(int i = 0; i < 5; i++) {
        cin >> A[i];
    }
    vector<int> B = {1, 2, 3, 4, 5};

    if(A == B) {
        cout << "No\n";
        return 0;
    }
    for(int i = 0; i < 4; i++) {
        vector<int> tmp = A;
        swap(tmp[i], tmp[i+1]);
        if(tmp == B) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}
