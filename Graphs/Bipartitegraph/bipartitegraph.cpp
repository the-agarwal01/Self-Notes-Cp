//A graph with an odd number of vertices in the cycle are not bipartite whereas even can and cannot be also



#include <bits/stdc++.h>
#define int 				long long
#define ll          long long
#define pb 					push_back
#define endl 				'\n'
#define ff 					first
#define ss 					second
#define vi 					vector<int>
#define pii 				pair<int, int>
#define all(x)				(x).begin(), (x).end()
#define rep(i, x, y)		for(int i=x; i<y; i++)
#define setbits(x) 			__builtin_popcountll(x)
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 				1e19
#define mod 				1000000007 // 1e9+7
 
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

 using namespace std;

const int N = 200005;
 vector<int>adj[N];
 int visited[N],colour[N];

bool dfs(int node,int col)
{
    visited[node]=1;
    colour[node]=col;
    for(auto x:adj[node])
    {
        if(!visited[x])
        {
         if(dfs(x,col^1)==false)
         return false;
        }
        else{
            if(colour[x]==colour[node])
            return false;
        }
        
    }
    return true;

}
void solve() {
    int n,m,a,b;
    cin>>n>>m;
    rep(i,0,m)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);

    }
    if(dfs(1,1))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;

    
   
  
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