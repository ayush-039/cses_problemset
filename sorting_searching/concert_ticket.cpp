#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e17+7;
const int MOD  = 998244353;
const int N = 1e6+7;

void solve()
{        
    int n,m;
    cin>>n>>m;
    vector<int> cust(m);
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        ms.insert(x);
    }
    
    for (int i = 0; i < m; i++)
    {
        cin>>cust[i];
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        auto cost = ms.upper_bound(cust[i]);
        if (cost != ms.begin())
        {
            cost--;
            cout<<*cost<<endl;
            ms.erase(cost);
            ans++;
        }
        else{
            cout<<-1<<endl;
        }
    }
    // cout<<ans<<endl;
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