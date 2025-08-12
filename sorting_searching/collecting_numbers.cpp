#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e17+7;
const int MOD  = 998244353;
const int N = 1e6+7;
 
void solve()
{        
    int n,m;
    cin>>n>>m;
    vector<int> pos(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v[i] = x;
        pos[x-1] = i;
    }
    int ans = 1;
    for (int i = 0; i < n-1; i++)
    {
        if (pos[i]>pos[i+1])
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    
    while (m--)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(x>y) swap(x,y);
        swap(v[x],v[y]);
        swap(pos[v[x]],pos[v[y]]);
        
        if (v[x]!=0)
        {
            if (pos[v[y]]>pos[v[x]-1] && pos[v[x]]<pos[v[x]-1] )
            {
                ans++;
            }
            if(pos[v[y]]<pos[v[x]-1] && pos[v[x]]>pos[v[x]-1]){
                ans--;
            } 
        }
        if (v[y]!=0)
        {
            if (pos[v[x]]>pos[v[y]-1] && pos[v[y]]<pos[v[y]-1] )
            {
                ans++;
            }
            if(pos[v[x]]<pos[v[y]-1] && pos[v[y]]>pos[v[y]-1]){
                ans--;
            } 
        }
        if (v[x]!=n-1)
        {
            if (pos[v[y]]>pos[v[x]+1] && pos[v[x]]<pos[v[x]+1] )
            {
                ans--;
            }
            if(pos[v[y]]<pos[v[x]+1] && pos[v[x]]>pos[v[x]+1]){
                ans++;
            } 
        }
        if (v[y]!=n-1)
        {
            if (pos[v[x]]>pos[v[y]+1] && pos[v[y]]<pos[v[y]+1] )
            {
                ans--;
            }
            if(pos[v[x]]<pos[v[y]+1] && pos[v[y]]>pos[v[y]+1]){
                ans++;
            } 
        }
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