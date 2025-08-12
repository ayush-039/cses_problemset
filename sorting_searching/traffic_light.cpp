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
    vector<int> v(k);
    for (int i = 0; i < k; i++)
    {
        cin>>v[i];
    }
    set<int>s;
    multiset<int> ms;
    ms.insert(n);
    for (int i = 0; i < k; i++)
    {
        // cout<<"v: "<<v[i]<<endl;
        if (i==0)
        {
            ms.erase(ms.find(n));
            s.insert(v[i]);
            ms.insert(v[i]);
            ms.insert(n-v[i]);
        }
        else
        {
            auto lb = s.lower_bound(v[i]);
            if (lb == s.begin())
            {
                // cout<<"enter0"<<endl;
                int fst = 0;
                int lst = *s.begin();
                s.insert(v[i]);
                ms.erase(ms.find(lst-fst));
                ms.insert(v[i]);
                ms.insert(lst-v[i]);
            }
            else if (lb == s.end())
            {
                // cout<<"enter1"<<endl;
                int fst = *(--s.end());
                int lst = n;
                // cout<<fst<<" "<<lst<<endl;
                s.insert(v[i]);
                ms.erase(ms.find(lst-fst));
                ms.insert(v[i]-fst);
                ms.insert(lst-v[i]);
            }
            else
            {
                // cout<<"enter2"<<endl;
                int lst = *lb;
                int fst = *(--lb);
                s.insert(v[i]);
                ms.erase(ms.find(lst-fst));
                ms.insert(v[i]-fst);
                ms.insert(lst-v[i]);
            }
        }
        int ans = *(--ms.end());
        cout<<ans<<endl;
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