#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e17+7;
const int MOD  = 998244353;
const int N = 1e6+7;


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

void solve()
{        
    int n;
    cin>>n;
    vector<vector<int>> pr(n);
    set<int> rooms;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        pr[i] = {x,y,i};
        rooms.insert(i+1);
    }
    sort(pr.begin(),pr.end());
    
    multiset<pair<int,int>> ms;
    vector<int> ans(n);
    int max_room = 0;
    for (int i = 0; i < n; i++)
    {
        auto tp = *ms.begin();
        while (!ms.empty() && tp.first<pr[i][0])
        {
            rooms.insert(tp.second);
            ms.erase(ms.begin());
            tp = *ms.begin();
        }
        auto aval_room = *rooms.begin();
        rooms.erase(rooms.begin());
        ans[pr[i][2]] = aval_room;
        ms.insert({pr[i][1],aval_room});
        max_room = max(max_room,aval_room);
    }
    cout<<max_room<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    

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