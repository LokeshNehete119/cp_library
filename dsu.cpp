#include<bits/stdc++.h>
using namespace std;

using ll = long long;

/*-------------------------- DSU -------------------------*/

struct DSU {
    vector<ll> parent, sz;
    ll components;

    DSU(ll n){
        parent.resize(n);
        sz.assign(n, 1);
        components = n;
        for(ll i=0; i<n; i++) parent[i] = i;
    }

    ll find(ll x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(ll a, ll b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        components--;
        return true;
    }

    ll size(ll x){
        return sz[find(x)];
    }

};
