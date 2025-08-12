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

bool check(int min_sum, vector<int> &v, int k){
    int n = v.size();
    int l = 0, r = 0;
    int sum = 0;
    int cnt = 1;
    while (l<n && r<n)
    {
        sum += v[r];
        if (v[r]>min_sum)
        {
            return false;
        }
        if (sum>min_sum)
        {
            // cout<<sum<<endl;
            while (r>l)
            {
                sum -= v[l];
                l++;
            }
            cnt++;
        }
        r++;
    }
    // if (sum>)
    // {
    //     /* code */
    // }
    
    // cout<<cnt<<endl;
    if (cnt<=k)
    {
        return true;
    }
    return false;
    
    
}

void solve()
{        
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    int hi = INF;
    int lo = 0;
    // cout<<check(7,v,k)<<endl;
    while (hi-lo>1)
    {
        int mid = lo + (hi-lo)/2;
        if (check(mid,v,k))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    
    if (check(lo,v,k))
    {
        cout<<lo<<endl;
    }
    else
    {
        cout<<hi<<endl;
    }
    
    
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