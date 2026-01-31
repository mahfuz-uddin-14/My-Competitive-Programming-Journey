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

void solve(){
int n;
cin>>n;
string s[105];
for(int i=0;i<n;i++)cin>>s[i];
string a=s[0],b="";
int c1=0,c2=0;
for(int i=0;i<n;i++){
if(s[i]==a)c1++;
else{
b=s[i];
c2++;
}
}
if(c1>c2)cout<<a<<lb;
else cout<<b<<lb;
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