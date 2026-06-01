#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

/*----------------------- INPUT OUTPUT Vectors ----------------------*/
template<typename T> void inputvec(vector<T>& v){for(auto& x:v) cin>>x;}
template<typename T,typename U> void inputvec(vector<pair<T,U>>& v){for(auto& p:v) cin>>p.first>>p.second;}
template<typename T> void printvec(const T& v){ for(const auto& x:v) cout<<x<<" "; cout<<"\n"; }
template<typename T,typename U> void printvec(const vector<pair<T,U>>& v){ for(const auto& p:v) cout<<p.first<<" "<<p.second<<"\n"; }

/*------------------------- MACROS ------------------------------*/
using ll = long long;
using str = string;
const ll M = 1e9+7;
#define forp(i,a,b) for(ll i=a; i<b; i++)
#define forn(i,a,b) for(ll i=a; i>=b; i--)
#define even(x) ((x)%2==0)
#define inv(x) modpow((x), M-2)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yepp cout<<"YES"<<'\n'
#define nope cout<<"NO"<<'\n'
#define yepps cout<<"Yes"<<'\n'
#define nopes cout<<"No"<<'\n'

/* ------------------------ CONTAINERS --------------------------*/
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vpll vector<pair<ll,ll>>
#define vvll vector<vector<ll>>
#define mll map<ll,ll>
#define pll pair<ll,ll>

/*-------------------------- FUNCTIONS -------------------------*/

bool isSquare(ll x) { return (ll)sqrt(x)*(ll)sqrt(x) == x; }

ll ceil(ll x, ll y) { return (x+y-1)/y; }

ll log2(ll x) { return x ? 63-__builtin_clzll(x) : -1; }

bool isPrime(ll n) {
    if(n<=1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(ll i=5; i*i<=n; i+=6) {
        if(n%i==0 || n%(i+2) == 0)  return false;
    }
    return true;
}

vector<ll> divisors(ll n) {
    vector<ll> d;
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            d.pb(i);
            if(i!=(n/i)) d.pb(n/i);
        }
    }
    sort(all(d));
    return d;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b&1) res = (res*a);
        a = (a*a);
        b >>= 1;
    }
    return res;
}

/*------------------------ Solution --------------------------*/

void solve(){
    
}

/*--------------------------------------------------------------*/
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t; while(t--)
        solve();
    return 0;
}