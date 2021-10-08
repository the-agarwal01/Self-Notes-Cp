
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
int visited[N];

bool dfs(int node,int par)
{
    visited[node]=1;
    for(auto child:adj[node])
    {
        if(!visited[child])
        {
            if(dfs(child,node)==true) 
            return true;
        }
        else{
            if(child!=par)//if any child is visited apart from its parent then it is a backedge hence a cycle
            return true;
        }
    }
    return false;
}
 
void solve() {
   int n,m,a,b;
   cin>>n>>m;
   for(int i=1;i<=m;i++)
   {
       cin>>a>>b;
       adj[a].pb(b);
       adj[b].pb(a);
   }
   if(dfs(1,0))
   cout<<"There exists a cycle"<<endl;
   else
   cout<<"No cycle found"<<endl;

  
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