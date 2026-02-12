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
    ll a,b;
    cin>>a>>b;
    if(b==1){
        cout<<"NO"<<lb;
    }else{
        cout<<"YES"<<lb;
        ll x=a;
        ll y=a*b;
        ll z=a*(b+1);
        // x nearly good, y good, z nearly good
        // kintu jodi b=2 hoy tobe x=a, y=2a, z=3a. ekhane y good.
        // aro safe thakar jonno b ke boro kora jay
        cout<<a<<" "<<a*b<<" "<<a*(b+1)<<lb;
    }
}

int main() {
    fast
    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}