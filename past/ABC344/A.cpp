#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    size_t first_pipe = s.find('|');
    size_t second_pipe = s.find('|', first_pipe + 1);
    string result = s.substr(0, first_pipe) + s.substr(second_pipe + 1);
    cout << result << endl;

    return 0;
}