#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    // 解が存在するための必要条件: N = k*(k-1)/2
    long long disc = 1LL + 8LL * N;      // 判別式
    long long t = sqrt(disc);
    if(t * t != disc) {                // 平方数でなければ存在しない
        cout << "No" << "\n";
        return 0;
    }
    if((1 + t) % 2 != 0) {             // kが整数にならなければ存在しない
        cout << "No" << "\n";
        return 0;
    }
    int k = (1 + t) / 2;
    if((long long)k * (k - 1) / 2 != N) {
        cout << "No" << "\n";
        return 0;
    }
    
    // 解が存在する場合
    cout << "Yes" << "\n";
    cout << k << "\n";
    
    // k 個の集合 S1,...,Sk を用意する
    vector<vector<int>> S(k);
    int num = 1;
    // 1 <= i < j <= k の全ペアに対して、整数 num を対応させる
    for(int i = 0; i < k; i++){
        for(int j = i + 1; j < k; j++){
            S[i].push_back(num);
            S[j].push_back(num);
            num++;
        }
    }
    
    // 各集合の情報を出力する（各行：要素数と要素一覧）
    for(int i = 0; i < k; i++){
        cout << S[i].size();
        for(auto x : S[i]){
            cout << " " << x;
        }
        cout << "\n";
    }
    
    return 0;
}
