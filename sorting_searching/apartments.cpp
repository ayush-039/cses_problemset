#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e17+7;
const int MOD  = 998244353;
const int N = 1e6+7;

void solve()
{        
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(n);
    vector<int> v1(m);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>v1[i];
    }

    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
    // for(int i=0;i<n;i++) cout<<v[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<m;i++) cout<<v1[i]<<" ";
    // cout<<endl;
    vector<int> used(n,0);
    int ans = 0;
    int pt1 = 0;
    int pt2 = 0;
    while (pt1<n && pt2<m)
    {
        if (abs(v[pt1]-v1[pt2])<=k)
        {
            pt1++;
            pt2++;
            ans++;
        }
        else if (v[pt1]-v1[pt2]>k)
        {
            pt2++;
        }
        else{
            pt1++;
        }
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