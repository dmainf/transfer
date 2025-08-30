#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long countSnakeNumbers(long long L, long long R) {
    auto count =  {
        string s = to_string(x);
        int n = s.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    if (i == 0 && k == 0) continue;
                    if (k < j) dp[i + 1][k] += dp[i][j];
                }
            }
        }
        long long res = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < 10; ++j) {
                res += dp[i][j];
            }
        }
        int prev = 0;
        for (int i = 0; i < n; ++i) {
            int digit = s[i] - '0';
            for (int j = (i == 0 ? 1 : 0); j < digit; ++j) {
                if (j < prev) res += dp[n - i - 1][j];
            }
            if (digit < prev) break;
            prev = digit;
        }
        return res;
    };
    return count(R + 1) - count(L);
}

int main() {
    long long L, R;
    cin >> L >> R;
    cout << countSnakeNumbers(L, R) << endl;
    return 0;
}