#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e17+7;
const int MOD  = 998244353;
const int N = 1e6+7;

bool comp_(vector<int> a, vector<int> b){
    if (a[0]<b[0])
    {
        return true;
    }
    else if (a[0]==b[0])
    {
        if (a[1]>b[1])
        {
            return true;
        }
    }
    return false;
}

void solve()
{        
    int n;
    cin>>n;
    vector<vector<int>> pr;
    // vector<vector<int>> pr1;
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        pr.push_back({x,y,i});
        // pr1.push_back({x,y,i});
        ms.insert(y);
    }
    multiset<int> chk;
    sort(pr.begin(),pr.end(),comp_);
    // sort(pr1.begin(),pr1.end(),comp_);
    vector<int> ans1(n,0);
    vector<int> ans2(n,0);
    for (int i = 0; i < n; i++)
    {
        // it contains some others
        ms.erase(ms.find(pr[i][1]));
        auto ub = ms.upper_bound(pr[i][1]);
        if(ub != ms.begin()) ans1[pr[i][2]] = 1;
        
        // some others contain it
        auto lb = chk.lower_bound(pr[i][1]);
        if(lb != chk.end()) ans2[pr[i][2]] = 1;
        chk.insert(pr[i][1]);
        
        
    }
    for (int i = 0; i < n; i++)
    {
        if (i!=0 && pr[i-1][0]==pr[i][0] && pr[i-1][1]==pr[i][1])
        {
            ans1[i] = 1;
            ans2[i-1] = 1;
        }
    }
    
    
    for (int i = 0; i < n; i++)
    {
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<ans2[i]<<" ";
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