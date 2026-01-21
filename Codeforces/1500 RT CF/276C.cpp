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
void solve() {
    int n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> cnt(n+2,0);
    while(q--){
        int l,r;
        cin>>l>>r;
        cnt[l]++;
        cnt[r+1]--;
    }
    vector<ll> f;
    for(int i=1;i<=n;i++){
        cnt[i]+=cnt[i-1];
        f.pb(cnt[i]);
    }
    sort(all(a));
    sort(all(f));
    ll ans=0;
    for(int i=0;i<n;i++) ans+=a[i]*f[i];
    cout<<ans<<lb;
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