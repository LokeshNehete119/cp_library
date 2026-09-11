#include<bits/stdc++.h>
using namespace std;

using ll = long long;

/*----------------------- Binary Lifting -----------------------*/

const ll MAX_BITS = 20;
vector<vector<ll>> up;
vector<ll> depth;

void dfs(ll node, ll parent, const vector<vector<ll>> &adj, ll d){
    up[node][0] = parent;
    depth[node] = d;

    for (ll i=1; i<MAX_BITS; i++) {
        if(up[node][i-1] != -1){
            up[node][i] = up[up[node][i-1]][i-1];
        } 
        else{
            up[node][i] = -1;
        }
    }

    for(ll child : adj[node]){
        if(child != parent) {
            dfs(child, node, adj, d+1);
        }
    }
}

ll get_kth_ancestor(ll node, ll k){
    for(ll i=0; i<MAX_BITS; i++){
        if (k & (1ll<<i)) { 
            node = up[node][i];
            if(node==-1) return -1;
        }
    }
    return node;
}

ll get_lca(ll u, ll v){
    if(depth[u]<depth[v]) swap(u, v);
    u = get_kth_ancestor(u, depth[u]-depth[v]);
    if(u==v) return u;

    for (ll i=MAX_BITS-1; i>=0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

ll get_dist(ll u, ll v) {
    return depth[u]+depth[v]-2*depth[get_lca(u, v)];
}

// Returns true if 'u' is an ancestor of 'v'
bool is_ancestor(ll u, ll v) {
    if(depth[u]>depth[v]) return false;
    return get_kth_ancestor(v, depth[v]-depth[u]) == u;
}