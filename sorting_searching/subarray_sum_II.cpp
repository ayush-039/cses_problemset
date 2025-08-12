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

void solve()
{        
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    map<int,int> mp;
    mp[0] = 1;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        int req = sum - x;
        if (mp.find(req) != mp.end())
        {
            ans = ans+mp[req];
        }
        mp[sum] = mp[sum] + 1;
    }
    // cout<<endl;
    // for(auto m:mp){
    //     cout<<m.first<<" "<<m.second<<endl;
    // }
    
    cout<<ans<<endl;
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