#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e17+7;
const int MOD  = 998244353;
const int N = 1e6+7;

void solve()
{        
    int n,tar;
    cin>>n>>tar;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v[i] = {x,i};
    }
    sort(v.begin(),v.end());
    int l = 0, r = n-1;
    int ans1 = -1, ans2 = -1;
    while (l<r)
    {
        if (v[l].first+v[r].first == tar)
        {
            ans1 = v[l].second;
            ans2 = v[r].second;
            break;
        }
        else if (v[l].first+v[r].first<tar)
        {
            l++;
        }
        else{
            r--;
        }
    }
    
    
    if (ans1 == -1 && ans2 == -1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        cout<<ans1+1<<" "<<ans2+1<<endl;
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