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
    string s; cin>>s;
    ll a=1,c=0;
    for(int i=0;i<sz(s);i++){
        if(s[i]=='a')c++;
        else if(s[i]=='b'){
            a=(a*(c+1))%MOD;
            c=0;
        }
    }
    a=(a*(c+1))%MOD;
    cout<<(a-1+MOD)%MOD<<lb;
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