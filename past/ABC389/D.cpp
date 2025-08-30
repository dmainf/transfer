#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long R;
    cin >> R;

    auto axix = [&](long long R){
        long double val = (long double)R*R - 0.25;
        if(val < 0) return 0LL;
        long double tmp = sqrtl(val) - 0.5;
        if(tmp < 0) return 0LL;
        long long i_max = (long long)floor(tmp);
        if(i_max < 1) return 0LL;
        return i_max; 
    };

    long long R2 = (long long)R * R;
    long long count_inner = 0;
    long long j = max(0LL, (long long)floor((long double)R - 0.5));
    for(long long i = 1; i <= (long long)floor((long double)R - 0.5); i++){
        long double ix = (long double)i + 0.5;
        long double left = (long double)R*R - (ix*ix); 
        if(left < 0){
            break;
        }
        while(j >= 1){
            long double jy = (long double)j + 0.5;
            if(jy*jy <= left){
                break;
            }
            j--;
        }
        if(j >= 1){
            count_inner += j;
        } else {
            break;
        }
    }

    long long count_i = axix(R);
    long long count_j = count_i;
    long long origin = 1;
    long long ans = 0;
    ans += 4 * count_inner;
    ans += 2 * (count_i + count_j);
    ans += origin;

    cout << ans << "\n";

    return 0;
}
