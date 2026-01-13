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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    priority_queue<int,vector<int>,greater<int>> q;
    vector<bool> f(n+1, false);

    q.push(1);
    f[1]=true;

    while(!q.empty()){
        int u = q.top();
        q.pop();
        cout << u << " ";

        for(auto v : g[u]){
            if(!f[v]){
                f[v]=true;
                q.push(v);
            }
        }
    }
    cout<<lb;
}

int main() {
    fast
    int t=1; 
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}#include<bits/stdc++.h>
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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    priority_queue<int,vector<int>,greater<int>> q;
    vector<bool> f(n+1, false);

    q.push(1);
    f[1]=true;

    while(!q.empty()){
        int u = q.top();
        q.pop();
        cout << u << " ";

        for(auto v : g[u]){
            if(!f[v]){
                f[v]=true;
                q.push(v);
            }
        }
    }
    cout<<lb;
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