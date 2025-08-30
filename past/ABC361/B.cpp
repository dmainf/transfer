#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
struct Point {
    int x, y, z;
};
Point input() {
    Point p;
    cin >> p.x >> p.y >> p.z;
    return p;
}
bool solve() {
    Point l1=input();
    Point r1=input();
    Point l2=input();
    Point r2=input();
    if(r1.x<=l2.x) return false;
    if(r2.x<=l1.x) return false;
    if(r1.y<=l2.y) return false;
    if(r2.y<=l1.y) return false;
    if(r1.z<=l2.z) return false;
    if(r2.z<=l1.z) return false;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(solve()) Yes;
    else No;

    return 0;
}
