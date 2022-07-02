#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define ss second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
#define vi vector<int>
#define vl vector<ll>
#define pr(t) cout<<t<<"\n"
#define int long long
#define p 998244353

ll mod = 1e9 + 7;
ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll fac[1000010];

ll power(ll x, ll y ){
    ll res = 1;
    x = x % p;
    if(x == 0 ) return x;
    while (y > 0){
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}


ll modInverse(ll n ){
    return power(n, p-2);
}

ll ncr(ll n,ll r ){
    if( r > n ) return 0;
    if (r==0||r==n) return 1;
    return (fac[n]* modInverse(fac[r]) % p * modInverse(fac[n-r]) % p) % p;
}


int32_t main(){
    KOBE;
    ll n,r;
    fac[0] = 1;
    for (ll i=1 ; i<1000010; i++)
        fac[i] = fac[i-1]*i%p;
    cin>>n>>r;
    cout<<ncr(n,r)<<"\n";
}

