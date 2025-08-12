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
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v[i] = x;
    }
    int l = 0;
    int r = 0;
    set<int> s;
    int ans = 0;
    while (l<n && r<n)
    {
        while (l<r && s.find(v[r])!= s.end())
        {
            s.erase(v[l]);
            l++;
        }
        s.insert(v[r]);
        int sz = s.size();
        ans = max(ans,sz);
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