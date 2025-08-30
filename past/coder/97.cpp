#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;

// ユークリッドの互除法で gcd を計算
ll gcd(ll a, ll b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// lcm を計算（オーバーフローに注意：ここでは M までの値で十分）
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll M;
    cin >> N >> M;
    vector<ll> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    // まず各 a[i] について、2 で何回割れるかを調べる
    int base = 0;
    {
        ll temp = a[0];
        while(temp % 2 == 0) {
            base++;
            temp /= 2;
        }
    }
    
    // 全ての a[i] で割り切れる 2 の回数が同じかチェック
    for(int i = 1; i < N; i++){
        int cnt = 0;
        ll temp = a[i];
        while(temp % 2 == 0) {
            cnt++;
            temp /= 2;
        }
        if(cnt != base){
            cout << 0 << "\n";
            return 0;
        }
    }

    // 各 a[i] を 2 で割った値の lcm を計算
    ll L = 1;
    for (int i = 0; i < N; i++){
        ll b = a[i] / 2;
        L = lcm(L, b);
        if(L > M) { // L が M を超えてしまえば答えは 0
            cout << 0 << "\n";
            return 0;
        }
    }

    // X = L * (odd) となる X ≤ M の個数を数える
    ll maxk = M / L;
    // 1 から maxk までの奇数の個数は (maxk + 1) / 2
    ll ans = (maxk + 1) / 2;
    cout << ans << "\n";
    return 0;
}