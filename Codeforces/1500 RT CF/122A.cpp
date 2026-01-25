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
int n;cin>>n;
int a[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
bool f=0;
for(int i=0;i<14;i++){
if(n%a[i]==0){f=1;break;}
}
if(f)cout<<"YES"<<lb;
else cout<<"NO"<<lb;
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