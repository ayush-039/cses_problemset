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
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    multiset<int> ms;
    set<int> s;
    int ans = 0;
    int l=0,r=0;
    while (l<n && r<n)
    {
        ms.insert(v[r]);
        s.insert(v[r]);
        int sz = s.size();
        while (sz>k)
        {
            ms.erase(ms.find(v[l]));
            if (ms.find(v[l]) == ms.end())
            {
                s.erase(v[l]);
            }
            l++;
            sz = s.size();
        }
        ans += r-l+1;
        r++;
    }
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