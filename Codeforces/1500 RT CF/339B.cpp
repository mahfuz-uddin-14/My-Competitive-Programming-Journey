#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define lb '\n'

void solve() {
    int n,m;
    cin>>n>>m;
    int p=1;
    ll c=0;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        if(a>=p){
            c+=(a-p);
        }else{
            c+=(n-p+a);
        }
        p=a;
    }
    cout<<c<<lb;
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