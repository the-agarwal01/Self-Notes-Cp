
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define rep(i, x, y) for (int i = x; i < y; i++)
#define setbits(x) __builtin_popcountll(x)
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INF 1e19
#define mod 1000000007 // 1e9+7

#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

using namespace std;

const int N = 200005;
/*What we are doing here is calculating all adjacent element of a node ,parent if the node is already visited so we dont consider it ,except that we add all adjacent nodes and then call a dfs on them .At last we store the value */



vector<int>adj[N];
int visited[N],subtree_size,subsize[N];
int dfs(int node)
{
    visited[node]=1;
    int subtree_size=1;
    for(auto child:adj[node])
    {
        if(!visited[child])
        {
            
            subtree_size+=dfs(child);
            
        }
    }
   
    return subsize[node]=subtree_size;
}

 
void solve() {
   int n,a,b;
   cin>>n;
   for(int i=1;i<=n-1;i++)
   {
       cin>>a>>b;
       adj[a].pb(b);
       adj[b].pb(a);
   }
   dfs(1);
   rep(i,1,n+1)
   cout<<subsize[i]<<" ";

  
  }

signed main()
{ 
      ios;
      int test;
      test=1;
      int tc=1;
    //   factorial(N-1);
    //   InvFactorial(N-1);
    
    // SieveOfEratosthenes(N-1);
      // cin>>test;
      
      while(test--)
      {
          //cout<<"Case #"<<tc<<": ";
          //tc++;
         solve();
      }
       
    
    return 0;
	}