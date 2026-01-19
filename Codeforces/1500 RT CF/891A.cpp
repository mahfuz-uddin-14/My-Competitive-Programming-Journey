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
    vector<int>a(n);
    int g=0,cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(g==0)g=a[i];
        else g=__gcd(g,a[i]);
        if(a[i]==1)cnt++;
    }
    if(g>1){
        cout<<-1<<lb;
        return;
    }
    if(cnt>0){
        cout<<n-cnt<<lb;
        return;
    }
    int mn=INF;
    for(int i=0;i<n;i++){
        int cur=a[i];
        for(int j=i+1;j<n;j++){
            cur=__gcd(cur,a[j]);
            if(cur==1){
                mn=min(mn,j-i);
                break;
            }
        }
    }
    cout<<mn+n-1<<lb;
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