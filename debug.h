#pragma once
#include <bits/stdc++.h>
using namespace std;

/*===========================================================================
 * CUSTOM CP DEBUG TEMPLATE
 *===========================================================================*/

// ============================================================================
// 1. FORWARD DECLARATIONS (Crucial for deeply nested structures)
// ============================================================================
template<typename T> void print(const T& x);
template<typename T, typename V> void print(const pair<T, V>& p);
template<typename T> void print(const vector<T>& v);
template<typename T, typename V> void print(const vector<pair<T, V>>& v);
template<typename T> void print(const vector<vector<T>>& v);
void print(const vector<vector<char>>& v);
template<typename K, typename V> void print(const map<K, V>& m);
template<typename T> void print(const set<T>& s);
template<typename T> void print(const multiset<T>& ms);
template<typename T> void print(queue<T> q);
template<typename T> void print(priority_queue<T> pq);
template<typename T> void print(stack<T> s);

// ============================================================================
// 2. BASE TYPES
// ============================================================================
template<typename T> void print(const T& x) { cerr << x; }
void print(const string& x) { cerr << x; }
void print(const char& x) { cerr << x; }

// ============================================================================
// 3. PAIRS
// ============================================================================
template<typename T, typename V> 
void print(const pair<T, V>& p) { 
    cerr << "("; print(p.first); cerr << ", "; print(p.second); cerr << ")"; 
}

// ============================================================================
// 4. 1D CONTAINERS (Vectors, Sets, Multisets)
// ============================================================================
// Format: [ 1 2 3 ]
template<typename T> 
void print(const vector<T>& v) {
    cerr << "[ ";
    for (const auto& x : v) { print(x); cerr << " "; }
    cerr << "]";
}

// Format: { 1 2 3 }
template<typename T> 
void print(const set<T>& s) {
    cerr << "{ ";
    for (const auto& x : s) { print(x); cerr << " "; }
    cerr << "}";
}

// Format: { 1 1 2 3 }
template<typename T> 
void print(const multiset<T>& ms) {
    cerr << "{ ";
    for (const auto& x : ms) { print(x); cerr << " "; }
    cerr << "}";
}

// ============================================================================
// 5. NESTED & KEY-VALUE CONTAINERS (Maps, Vector of Pairs)
// ============================================================================
// Format: Custom curly braces with newlines
template<typename T, typename V> 
void print(const vector<pair<T, V>>& v) {
    cerr << "{\n";
    for (const auto& p : v) {
        cerr << "  "; print(p.first); cerr << " : "; print(p.second); cerr << '\n';
    }
    cerr << "}";
}

template<typename K, typename V> 
void print(const map<K, V>& m) {
    cerr << "{\n";
    for (const auto& p : m) {
        cerr << "  "; print(p.first); cerr << " : "; print(p.second); cerr << '\n';
    }
    cerr << "}";
}

// ============================================================================
// 6. 2D MATRICES
// ============================================================================
// Format: Matrix wrapped in { } with spaces between elements
template<typename T> 
void print(const vector<vector<T>>& v) {
    cerr << "{\n"; 
    for (const auto& row : v) {
        cerr << "  "; // Indent the row
        for (const auto& x : row) { print(x); cerr << " "; }
        cerr << '\n';
    }
    cerr << "}";
}

// Format: Continuous grid wrapped in { } (no spaces between chars)
void print(const vector<vector<char>>& v) {
    cerr << "{\n"; 
    for (const auto& row : v) {
        cerr << "  "; // Indent the row
        for (const auto& x : row) { cerr << x; } 
        cerr << '\n';
    }
    cerr << "}";
}

// ============================================================================
// 7. CONTAINER ADAPTERS (Passed by value to destructively print)
// ============================================================================
template<typename T> 
void print(queue<T> q) { 
    cerr << "[ "; 
    while(!q.empty()) { print(q.front()); cerr << " "; q.pop(); } 
    cerr << "]"; 
}

template<typename T> 
void print(priority_queue<T> pq) { 
    cerr << "[ "; 
    while(!pq.empty()) { print(pq.top()); cerr << " "; pq.pop(); } 
    cerr << "]"; 
}

template<typename T> 
void print(stack<T> s) { 
    vector<T> v; 
    while(!s.empty()) { v.push_back(s.top()); s.pop(); } 
    reverse(v.begin(), v.end()); // Top of stack is on the right
    print(v); 
}

// ============================================================================
// 8. SMART DEBUG UNPACKER (Chops variables, handles nested brackets)
// ============================================================================
void debug_out(string s) { cerr << '\n'; }

template <typename Head, typename... Tail>
void debug_out(string s, Head H, Tail... T) {
    int bracket = 0, i = 0;
    while (i < s.size() && (s[i] != ',' || bracket != 0)) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<') bracket++;
        if (s[i] == ')' || s[i] == '}' || s[i] == ']' || s[i] == '>') bracket--;
        i++;
    }
    
    string name = s.substr(0, i);
    while (name.size() && name.front() == ' ') name.erase(name.begin());
    while (name.size() && name.back() == ' ') name.pop_back();

    cerr << name << " = ";
    print(H);
    
    if (sizeof...(T)) {
        cerr << " | ";
        debug_out(s.substr(i + 1), T...);
    } else {
        cerr << '\n';
    }
}

// ============================================================================
// 9. THE MACRO
// ============================================================================

#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)

/*===========================================================================*/