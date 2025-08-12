#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e17+7;
const int MOD  = 998244353;
const int N = 1e6+7;

void solve()
{        
    int n;
    cin>>n;
    vector<pair<int,int>> s;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        s.push_back({x,y});
    }
    sort(s.begin(),s.end());
    set<int>tp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int st = s[i].first;
        tp.insert(s[i].second);
        while (!tp.empty() && *(tp.begin())<st)
        {
            tp.erase(tp.begin());
        }
        int sz = tp.size();
        ans = max(ans,sz);
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