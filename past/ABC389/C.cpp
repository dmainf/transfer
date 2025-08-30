#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    vector<long long> sum(Q+1, 0LL);

    long long offset = 0;      
    int front = 0;       
    int total = 0;     
    
    while(Q--){
        int t;
        cin >> t;
        if(t == 1){
            long long l;
            cin >> l;
            ++total;
            sum[total] = sum[total - 1] + l;

        } else if(t == 2){
            long long m = sum[front + 1] - sum[front];
            offset -= m;
            front++;

        } else {
            int k;
            cin >> k;
            long long ans = offset + sum[front + k - 1];
            cout << ans << "\n";
        }
        //offset：先頭の消したやつ
    }

    return 0;
}
