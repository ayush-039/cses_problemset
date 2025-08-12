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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int l = 0,r=1;
    int sum = v[l];
    int ans = v[l];
    while (l<n && r<n)
    {
        if(sum<=0){
            l=r;
            sum = v[l];
        }
        else
        {
            sum += v[r];
        }
        r++;
        ans = max(ans,sum);
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