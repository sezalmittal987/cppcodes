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

const ll M = 1e5+100 , LG = 20;
ll par[LG][M],level[M],tot[M];
ll c[M];
ll n,x,y;
vector<int> gr[M];


void dfs(ll k,ll parent,ll d){
    par[0][k]=parent;
    level[k]=d;
    tot[k]=1;
    for(auto it:gr[k])
    {
        if(it==parent)
            continue;
        dfs(it,k,d+1);
        tot[k]+=tot[it];
    }
}


void precompute(){
  for(ll i=1;i<LG;i++){
    for(ll j=1;j<=n;j++){
      if(par[i-1][j])
          par[i][j]=par[i-1][par[i-1][j]];
    }
  }
}


ll lca(ll u, ll v)
{
    if(level[u]<level[v])
        swap(u,v);
    ll diff=level[u]-level[v];
    for(ll i=LG-1;i>=0;i--){
        if((1ll<<i) & diff){
            u=par[i][u];
        }
    }
    if(u==v)
        return u;
    for(ll i=LG-1;i>=0;i--){
        if(par[i][u] && par[i][u]!=par[i][v]){
            u=par[i][u];
            v=par[i][v];
        }
    }
    return par[0][u];
}

void solve(){
    //take input from graph first, then
    dfs(1,0,0); //call this
    precompute(); //then call this, now we can use lca

}

int32_t main(){
    ABCD;
    ll t;
    t = 1;
    // re t;
    while(t--) solve();
}