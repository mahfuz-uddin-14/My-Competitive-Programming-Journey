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

struct Z {
    int l, r, i;
};

bool cmp(Z a, Z b){
    return a.l<b.l;
}

void solve() {
    int n;
    cin>>n;
    vector<Z> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].l>>v[i].r;
        v[i].i=i;
    }
    sort(all(v), cmp);
    int mx=v[0].r;
    int k = -1;
    for(int i=0; i<n-1; i++){
        mx = max(mx, v[i].r);
        if(mx < v[i+1].l){
            k=i;
            break;
        }
    }
    if(k==-1){
        cout<<-1<<lb;
        return;
    }
    vector<int> res(n);
    for (int i=0;i<=k;i++) res[v[i].i]=1;
    for(int i=k+1; i<n; ++i) res[v[i].i] = 2;
    for(int i=0; i<n; i++) cout<<res[i] << " ";
    cout << lb;
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