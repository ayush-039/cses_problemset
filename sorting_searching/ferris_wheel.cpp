#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e17+7;
const int MOD  = 998244353;
const int N = 1e6+7;

void solve()
{        
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l = 0, r = n-1;
    int ans = 0, cnt = 0; 
    while(l<r){
        if(v[l]+v[r]<=k){
            l++;
            r--;
            ans++;
        }
        else
        {
            r--;
            cnt++;
        }
    }
    if (l==r)
    {
        cnt++;
    }
    
    // cout<<ans<<" "<<cnt<<endl;
    cout<<ans+cnt<<endl;
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