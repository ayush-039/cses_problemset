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
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(i+1);
    }
    vector<int> ans;
    int st = 1;
    while (!s.empty())
    {
        vector<int>tp;
        auto itr = s.begin();
        if (st == 1)
        {
            itr++;
        }
        // decide the st point
        int sz = s.size();
        if(sz == 2) st = 0;
        if(sz%2!=0){
            if(st==1) st=0;
            else st = 1;
        }
        while (itr != s.end())
        {
            tp.push_back(*itr);
            itr++;
            if(itr != s.end()) itr++;
            else break;
        }
        for (int i = 0; i < tp.size(); i++)
        {
            ans.push_back(tp[i]);
            s.erase(tp[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    
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