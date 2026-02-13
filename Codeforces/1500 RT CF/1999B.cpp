#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)(x).size()
#define lb '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int f(int x, int y) {
    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    
    // Case 1: (a, c) and (b, d)
    int s1 = 0;
    if (f(a, c) == 1) s1++; else if (f(a, c) == -1) s1--;
    if (f(b, d) == 1) s1++; else if (f(b, d) == -1) s1--;
    if (s1 > 0) ans++;

    // Case 2: (a, d) and (b, c)
    int s2 = 0;
    if (f(a, d) == 1) s2++; else if (f(a, d) == -1) s2--;
    if (f(b, c) == 1) s2++; else if (f(b, c) == -1) s2--;
    if (s2 > 0) ans++;

    // Case 3: (b, c) and (a, d)
    int s3 = 0;
    if (f(b, c) == 1) s3++; else if (f(b, c) == -1) s3--;
    if (f(a, d) == 1) s3++; else if (f(a, d) == -1) s3--;
    if (s3 > 0) ans++;

    // Case 4: (b, d) and (a, c)
    int s4 = 0;
    if (f(b, d) == 1) s4++; else if (f(b, d) == -1) s4--;
    if (f(a, c) == 1) s4++; else if (f(a, c) == -1) s4--;
    if (s4 > 0) ans++;

    cout << ans << lb;
}

int main() {
    fast
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}