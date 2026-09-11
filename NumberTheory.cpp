#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll M = 1e9+7;

bool isPrime(ll n) {
    if(n<=1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(ll i=5; i*i<=n; i+=6) {
        if(n%i==0 || n%(i+2) == 0)  return false;
    }
    return true;
}

vector<ll> primeFactors(ll n) {
    vector<ll> f;
    for(ll i=2; i*i<=n; i++){
        while(n%i == 0){
            f.push_back(i);
            n /= i;
        }
    }
    if(n>1) f.push_back(n);
    return f;
}

vector<ll> SPF(ll n){
    vector<ll> spf(n+1);
    for(ll i=0; i<=n; i++){
        spf[i] = i;
    }

    for(ll i=2; i*i<=n; i++){
        if(spf[i] == i){
            for(ll j=i*i; j<=n; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}

vector<ll> fastFactorize(ll n, vector<ll> &spf) {
    vector<ll> factors;
    while (n>1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}

vector<ll> divisors(ll n) {
    vector<ll> d;
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            d.push_back(i);
            if(i!=(n/i)) d.push_back(n/i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}

vector<bool> sieve(int n){
    vector<bool> prime(n+1, 1);
    prime[0] = prime[1] = 0;
    
    for(ll i=2; i*i<=n; i++){
        if(prime[i]){
            for(ll j=i*i; j<=n; j+=i){
                prime[j] = 0;
            }
        }
    }
    
    return prime;
}

ll modpow(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b&1) res = (res*a)%M;
        a = (a*a)%M;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a){  return modpow(a, M-2); }

/*-------------------------- COMBINATORICS -------------------------*/

const int N = 1e6;
vector<ll> fact(N+1), invfact(N+1);

void precomputeFactorial(){
    fact[0] = 1;
    for(ll i=1; i<=N; i++){
        fact[i] = (fact[i-1]*i) % M;
    }

    invfact[N] = modpow(fact[N], M-2);
    for(ll i=N-1; i>=0; i--){
        invfact[i] = (invfact[i+1]*(i+1)) % M;
    }
}

ll nCr(ll n, ll r){
    if(r<0 || r>n) return 0;

    return (((fact[n]*invfact[r]) % M) * invfact[n-r]) % M;
}

/*-------------------------- BITS -------------------------*/

// (a|b) = (a^b) + (a&b)
// (a+b) = (a|b) + (a&b) = (a^b) + 2*(a&b)
// (a-b) = ((a|b)^b) - ((a|b)^a) = ((a&b)^a) - ((a&b)^b)