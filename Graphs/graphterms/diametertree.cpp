//We can calc the diamter of the graph by using dfs 2 times .By using maxdist node of the first dfs as source node of the second node 
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
int visited[N],maxD,maxNode;

void dfs(int node,int d)//using shortest search path for finding dist and taking the max dist node as the end pt of dfs 
{
    if(d>maxD)
    maxD=d,maxNode=node;
    
    visited[node]=1;
    for(auto child:adj[node])
    {
        if(!visited[child])
        dfs(child,d+1);
    }
       
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

   maxD=-1;

   dfs(1,0);//Taking 1 as atleast one node will be present 

   rep(i,1,n+1)//making all visited node unvisited
   visited[i]=0;

   maxD=-1;
   dfs(maxNode,0);//taking dfs agaiin but with max dist Node 
   cout<<maxD<<endl;

  


  
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