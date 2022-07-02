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

int n, m;
int a[105], b[105];
int adj[205][205] = {}; 
int par[205] = {};

int bfs(){
    fo(2*n + 2) par[i] = -1;
    queue<pi> q;
    q.push({0, 1e10});
    while(!q.empty()){
        auto p = q.front();
        if(p.ff == 2*n + 1) return p.ss;
        q.pop();
        for(int i = 1; i <= 2*n + 1 ; i++){
            if( adj[p.ff][i] > 0  && par[i] == -1){
                par[i] = p.ff;
                q.push({i,min(p.ss, adj[p.ff][i])});
            }
        }
    }
    return 0;
}

void solve(){
    cin>>n>>m;
    fore(i, 1, n) cin>>a[i];
    fore(i, 1, n) cin>>b[i];
    fore(i, 1, n) adj[0][i] = a[i], adj[i][n+i] = 1e5, adj[n+i][2*n+1] = b[i];
    fo(m){
        int u, v;
        cin>>u>>v;
        adj[u][v+n] = 1e5;
        adj[v][u+n] = 1e5;
    }
    int suma = 0, sumb = 0 , flow = 0;
    fore(i, 1, n) suma += a[i], sumb += b[i];
    int curr = 0;
    while( (curr = bfs()) > 0){
        flow += curr;
        int u = 2*n + 1;
        while(par[u] != -1 ){
            int v = par[u];
            adj[v][u] -= curr ;
            adj[u][v] += curr;
            u = v;
        }
    }
    if( flow != suma || flow != sumb ){
        NO;
        return;
    }
    YES;
    int ans[n][n] = {} ;
    fore(i, 1, n){
        fore(j, n+1, 2*n ){
            if(adj[i][j]) ans[i-1][j-n-1] = 1e5 - adj[i][j];
        }
    }
    fo(n){
        forn(j, n) cout<<ans[i][j]<<" ";
        el;
    }
}

int32_t main(){
    ABCD;
    ll t;
    // cin>>t;
    t = 1;
    while(t--) solve();
}