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

bool check(int tm, vector<int> &v,int target){
    int items = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int item = tm/v[i];
        items += item;
        items = min(INF,items);
    }
    if (items>=target)
    {
        return true;
    }
    return false;
}

void solve()
{        
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v[i] = {x,i};
    }
    if (n<=2)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    
    sort(v.begin(),v.end());
    int ans1 = -1, ans2 = -1, ans3 = -1;
    for (int i = 0; i < n; i++)
    {
        int l= i+1;
        int r= n-1;
        int sum = x-v[i].first;
        while (l<r)
        {
            if (sum>v[l].first+v[r].first)
            {
                l++;
            }
            else if (sum<v[l].first+v[r].first)
            {
                r--;
            }
            else{
                ans1 = v[i].second+1;
                ans2 = v[l].second+1;
                ans3 = v[r].second+1;
                break;
            }
        }
        if (ans1 != -1 && ans2 != -1 && ans3 != -1)
        {
            break;
        }
    }
    if (ans1==-1 && ans2==-1 && ans3==-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
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