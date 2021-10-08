//refer codencode and hitesh video
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
 
vector<int> adj[N];
int low[N],in[N],visited[N],timer;//here low is the lowest ancestor of that node(we keep updating it)
 
 void dfs(int node,int par)
 {
     visited[node]=1;
     in[node]=low[node]=timer;
     timer++;
     for(auto child:adj[node])
     {
         if(child==par) continue; //If child==par then we continue

          if(visited[child]) //This is a back edge 
          {
              low[node]=min(low[node],in[child]);
          }
          else 
          {
              dfs(child,node); //This is a tree edge then 
              low[node]=min(low[node],low[child]);

              if(low[child]>in[node])
              cout<<"There is a bridge between "<<child <<" and "<<node<<endl;
          }

     }
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
   dfs(1,-1);
    
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