#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

/*---------------------- ORDERED SET ----------------------*/

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

/*
Functions:

insert(x)
erase(x)

find_by_order(k)
-> iterator to kth element (0-indexed)

order_of_key(x)
-> number of elements strictly smaller than x
*/