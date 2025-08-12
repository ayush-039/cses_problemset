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
    vector<pair<int,int>> pr;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        pr.push_back({x,y});
    }
    set<pair<int,int>> s;
    set<int> aval_mem;
    for (int i = 0; i < k; i++)
    {
        s.insert({0,i});
    }
    sort(pr.begin(),pr.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto st = *s.begin();
        while(!s.empty() && st.first<=pr[i].first){
            aval_mem.insert(st.second);
            s.erase(s.begin());
            st = *s.begin();
        }
        if (aval_mem.empty())
        {
            // swap with max finish time if it's more than current finish time.
            auto ls = *(--s.end());
            if (ls.first > pr[i].second)
            {
                pair<int,int> nw = {pr[i].second,ls.second};
                s.erase(--s.end());
                s.insert(nw);
            }
        }
        else
        {
            auto ps = *aval_mem.begin();
            aval_mem.erase(aval_mem.begin());
            s.insert({pr[i].second,ps});
            ans++;
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