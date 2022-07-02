#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n" 
#define No cout<<"No\n"
#define dcout(x) cout<<fixed<<setprecision(10)<<x
#define pb push_back
#define ff first
#define ss second
#define umap unordered_map
#define pqmax(T) priority_queue<T>
#define pqmin(T) priority_queue<T,vector<T>,greater<T>>
#define ABCD ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define fore(x,n,m) for(ll x=n;x<=m;x++)
#define rfor(x,n,m) for(ll x=n;x>=m;x--)
#define int long long
#define el cout<<"\n"
#define  pi pair<int,int>
#define pii pair<int, pair<int,int>>
#define mod 1000000007

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int lcm (int a , int b){
    return (a*b)/gcd(a,b);
}  

void solve(){
    
}

int32_t main(){
    ABCD;
    ll t;
    cin>>t;
    // t = 1;
    while(t--) solve();
}