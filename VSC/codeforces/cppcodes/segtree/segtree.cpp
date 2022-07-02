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
#define INF 1e15

class SegmentTree{
    public:
        int st[10006] , lazy[10006];

    SegmentTree(int n){
        fo(4*n+5) st[i]=lazy[i]=0;
    }

    int buildTree(int *arr , int curr, int l, int r){
        if(l==r) st[curr] = arr[l];
        else{
            int mid= (l+r)/2;
            st[curr]=(buildTree(arr,2*curr,l,mid)+buildTree(arr,2*curr+1,mid+1,r)); //function
        }
        return st[curr];
    }

    int query( int curr , int l, int r , int ql ,int qr){
        if(qr < l || ql >r) return 0;             //case sensitive
        if(ql<=l && qr >=r) return st[curr];        
        int mid = (l+r)/2;
        return (query(2*curr, l , mid, ql,qr)+query(2*curr+1 ,mid+1,r,ql,qr)); //function
    }

    void update(int curr , int l ,int r , int qi, int x){
        if(l==r){
            st[curr]=x;
            return;
        }   
        int mid= (l+r)/2;
        if(qi<=mid) update(2*curr,l, mid,qi, x);
        else update(2*curr+1,mid+1,r,qi,x);
        st[curr] = (st[2*curr]+st[2*curr+1]); // function
    }

    int lquery(int curr, int l ,int  r, int ql, int qr){
        if(lazy[curr] != 0) {
            int x = lazy[curr];
            lazy[curr]=0;
            st[curr] += x*(r-l+1); //case sensitive
            if(l!=r) lazy[2*curr]+=x,lazy[2*curr+1]+=x;
        }
        if(qr < l || ql >r) return 0;             //case sensitive
        if((ql<=l && qr >=r)|| l==r) return st[curr];        
        int mid = (l+r)/2;
        return (lquery(2*curr, l , mid, ql,qr)+lquery(2*curr+1 ,mid+1,r,ql,qr)); //function
    }

    void lupdate(int curr, int l, int r ,int ql,int qr ,int x){
        if(lazy[curr] != 0) {
            int dx = lazy[curr];
            lazy[curr]=0;
            st[curr] += dx*(r-l+1); //case sensitive
            if(l!=r) lazy[2*curr]+=dx,lazy[2*curr+1]+=dx;   
        }
        if(qr < l || ql >r) return ;             
        if((ql<=l && qr >=r) || l==r) {
            st[curr] += x*(r-l+1); //case sensitive
            if(l!=r) lazy[2*curr]+=x,lazy[2*curr+1]+=x;
            return;
        }        
        int mid = (l+r)/2;
        lupdate(2*curr, l , mid, ql,qr,x);
        lupdate(2*curr+1 ,mid+1,r,ql,qr,x);
        st[curr] = st[2*curr] + st[2*curr+1]; //function
    }
};

void solve(){
    SegmentTree s(5);
    int arr[10]={0,1,2,-3,9,-10};
    s.buildTree(arr,1,1,5);    
}

int32_t main(){
    ABCD;
    ll t;
    // cin>>t;
    t = 1;
    while(t--) solve();
}