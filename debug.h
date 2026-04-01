#include<bits/stdc++.h>
using namespace std;

/*-------------------------- DEBUG -------------------------*/
void debug(){cerr<<'\n';}

template<typename T> auto is_iterable(int)->decltype(begin(declval<T>()),true_type{});
template<typename T> false_type is_iterable(...);
template<typename T> auto is_pair(int)->decltype(declval<T>().first,declval<T>().second,true_type{});
template<typename T> false_type is_pair(...);

template<typename T>
void print(const T& x){
    if constexpr(decltype(is_iterable<T>(0))::value && !is_same_v<T,string>){
        if constexpr(decltype(is_pair<typename T::value_type>(0))::value){
            cerr<<"{\n";
            for(auto& it:x) cerr<<"  "<<it.first<<" : "<<it.second<<'\n';
            cerr<<"}";
        }else{
            cerr<<"[ ";
            for(auto& e:x) print(e), cerr<<" ";
            cerr<<"]";
        }
    }else if constexpr(decltype(is_pair<T>(0))::value)
        cerr<<"{ "<<x.first<<" : "<<x.second<<" }";
    else cerr<<x;
}

template<typename T>
void debug(const string&, const vector<vector<T>>& a){
    for(const auto& row : a){
        for(const auto& x : row) cerr << x << " ";
        cerr << '\n';
    }
}

template<typename T,typename... Args>
void debug(const string& n,const T& v,Args... a){
    cerr<<n<<" = "; print(v);
    if constexpr(sizeof...(a)) cerr<<" | ";
    debug(a...);
}

/*-------------------------- INPUT OUTPUT Vectors -------------------------*/
template<typename T> void inputvec(vector<T>& v){for(auto& x:v) cin>>x;}
template<typename T,typename U> void inputvec(vector<pair<T,U>>& v){for(auto& p:v) cin>>p.first>>p.second;}

template<typename T> void printvec(const T& v){ for(const auto& x:v) cout<<x<<" "; cout<<"\n"; }
template<typename T,typename U> void printvec(const vector<pair<T,U>>& v){ for(const auto& p:v) cout<<p.first<<" "<<p.second<<"\n"; }
