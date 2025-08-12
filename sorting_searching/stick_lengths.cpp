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
    int tsum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        tsum += v[i];
    }
    sort(v.begin(),v.end());
    int mn = tsum;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int tp = tsum - 2*sum - n* v[i] +2*i*v[i]; 
        mn = min(mn,tp);
        sum += v[i];
    }
    cout<<mn<<endl;

    
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