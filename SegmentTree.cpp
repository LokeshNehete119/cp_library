#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node{
    ll sum, lazy_add, lazy_set;
    bool is_set; 

    Node(){
        sum = 0;
        lazy_add = 0;
        lazy_set = 0;
        is_set = false;
    }
};

struct SegmentTree{
    ll n;
    vector<ll> arr;
    vector<Node> tree;

    Node merge(Node &a, Node &b) {
        Node ans;
        ans.sum = a.sum + b.sum;
        return ans;
    }
    
    void apply_set(ll idx, ll l, ll r, ll val) {
        tree[idx].is_set = true;
        tree[idx].lazy_set = val;
        tree[idx].lazy_add = 0; 
        tree[idx].sum = val*(r-l+1);
    }

    void apply_add(ll idx, ll l, ll r, ll val) {
        tree[idx].lazy_add += val;
        tree[idx].sum += val*(r-l+1);
    }

    void push(ll idx, ll l, ll r) {
        if (l!=r) {
            ll mid = (l+r)/2;
            
            if (tree[idx].is_set) {
                apply_set(2*idx+1, l, mid, tree[idx].lazy_set);
                apply_set(2*idx+2, mid+1, r, tree[idx].lazy_set);
                tree[idx].is_set = false;
            }
            
            if (tree[idx].lazy_add != 0) {
                apply_add(2*idx+1, l, mid, tree[idx].lazy_add);
                apply_add(2*idx+2, mid+1, r, tree[idx].lazy_add);
                tree[idx].lazy_add = 0;
            }
        }
    }

    void build(ll idx, ll l, ll r) {
        if(l==r){
            tree[idx].sum = arr[l];
            return;
        }
        ll mid = (l+r)/2;
        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);
        tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
    }

    Node query(ll idx, ll l, ll r, ll ql, ll qr) {
        push(idx, l, r); 
        if (ql>r || qr<l) return Node(); 
        if (ql<=l && qr>=r) return tree[idx]; 

        ll mid = (l+r)/2;
        Node left_ans = query(2*idx+1, l, mid, ql, qr);
        Node right_ans = query(2*idx+2, mid+1, r, ql, qr);
        return merge(left_ans, right_ans);
    }

    void update_add(ll idx, ll l, ll r, ll ql, ll qr, ll val) {
        push(idx, l, r);
        if (ql>r || qr<l) return;
        if (ql<=l && qr>=r) {
            apply_add(idx, l, r, val);
            return;
        }
        ll mid = (l+r)/2;
        update_add(2*idx+1, l, mid, ql, qr, val);
        update_add(2*idx+2, mid+1, r, ql, qr, val);
        tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
    }

    void update_set(ll idx, ll l, ll r, ll ql, ll qr, ll val) {
        push(idx, l, r);
        if (ql > r || qr < l) return;
        if (ql <= l && qr >= r) {
            apply_set(idx, l, r, val);
            return;
        }
        ll mid = (l+r)/2;
        update_set(2*idx+1, l, mid, ql, qr, val);
        update_set(2*idx+2, mid+1, r, ql, qr, val);
        tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
    }

    SegmentTree(vector<ll> &v) {
        arr = v;
        n = v.size();
        tree.resize(4*n);
        build(0, 0, n-1);
    }

    ll get_sum(ll l, ll r) { 
        return query(0, 0, n-1, l, r).sum; 
    }

    void add_range(ll l, ll r, ll val) { 
        update_add(0, 0, n-1, l, r, val); 
    }

    void set_range(ll l, ll r, ll val) { 
        update_set(0, 0, n-1, l, r, val); 
    }
};