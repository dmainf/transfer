#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    
    vector<int> cnt(n + 1, 0);
    
    // O(N)で素因数の個数を計算
    for(int i = 2; i <= n; i++) {
        if(cnt[i] == 0) { // iが素数
            for(int j = i; j <= n; j += i) {
                int temp = j;
                while(temp % i == 0) {
                    cnt[j]++;
                    temp /= i;
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        if(cnt[i] >= k) ans++;
    }
    
    cout << ans << endl;
    return 0;
}