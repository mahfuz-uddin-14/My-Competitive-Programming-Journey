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
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];

    map<pii,int> mp;
    int z=0, mx=0;

    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(b[i]==0) z++;
        } else {
            int x = -b[i];
            int y = a[i];
            int g = __gcd(abs(x),abs(y));
            x/=g;
            y/=g;
            if(y<0){
                x=-x; 
                y=-y;
            }
            mp[{x,y}]++;
            mx=max(mx, mp[{x,y}]);
        }
    }
    cout<<z+mx<<lb;
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