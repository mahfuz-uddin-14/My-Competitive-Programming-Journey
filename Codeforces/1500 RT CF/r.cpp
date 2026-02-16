#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0);
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
const int MOD = 1e10+7;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    bool f=false;
    for(int i=0;i<n-2;i++){
        if(a[i]+a[i+1]>a[i+2]){
            f=true;
            break;
        }
    }
    if(f)cout<<"YES"<<lb;
    else cout<<"NO"<<lb;
}

int main(){
    fast
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}