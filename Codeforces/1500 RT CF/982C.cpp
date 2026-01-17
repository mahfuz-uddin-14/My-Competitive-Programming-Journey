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

struct st {
    int l, r, i;
};

bool cmp(st a, st b) {
    if(a.l!=b.l) return a.l < b.l;
    return a.r > b.r;
}

void solve() {
    int n;
    cin>>n;
    vector<st> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i].l>> a[i].r;
        a[i].i = i+1;
    }
    sort(all(a), cmp);
    int mx=-1;
    int id=-1;
    for(int i=0; i<n; i++){
        if(a[i].r<=mx) {
            cout<<a[i].i<<" "<<id<<lb;
            return;
        }
        mx=a[i].r;
        id = a[i].i;
    }
    cout<<"-1 -1"<<lb;
}

int main() {
    fast
    int t=1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}