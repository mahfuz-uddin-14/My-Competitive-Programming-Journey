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
    int n; cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        v.pb({l,1});
        v.pb({r,2});
    }
    sort(all(v));
    int c=0;
    for(auto x:v){
        if(x.ss==1) c++;
        else c--;
        if(c>2){
            cout<<"NO"<<lb;
            return;
        }
    }
    cout<<"YES"<<lb;
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