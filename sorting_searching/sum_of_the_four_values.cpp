#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18+7;
const int MOD  = 998244353;
const int N = 1e6+7;


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

bool check(int tm, vector<int> &v,int target){
    int items = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int item = tm/v[i];
        items += item;
        items = min(INF,items);
    }
    if (items>=target)
    {
        return true;
    }
    return false;
}

void solve()
{        
    
}
signed main()
{
    time_t begin, end;
    time(&begin);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    // sieve();
    while (t--)
    {
        solve();
    }
    return 0;
}