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
    string s;
    cin>>s;
    string t="hello";
    int j=0;
    for(int i=0; i<s.size();i++){
        if(s[i]==t[j]){
            j++;
        }
        if(j==5) break;
    }
    if(j==5)cout<<"YES"<<lb;
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