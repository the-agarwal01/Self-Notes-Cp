//applied single source shortest path same problem
//Code link:-https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/

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
 
vector<int>adj[1001];
int visited[1001],dist[1001];

void dfs(int node,int di)
{
    visited[node]=1;
    dist[node]=di;   //We store the distanc here .This dist==prvious node dist+1
    for(auto x:adj[node])
    {
        if(!visited[x])
        dfs(x,dist[node]+1);
    }
}
void solve() {
   int n,a,b,q;
   cin>>n;
   
   for(int i=1;i<=n-1;i++)
   {
       cin>>a>>b;
       adj[a].pb(b);
       adj[b].pb(a);
   }
   dfs(1,0);
   cin>>q;
   int min_dist=INT_MAX,ans=-1;
   while(q--)
   {
       int girl_city;
       cin>>girl_city;
       
       if(dist[girl_city]<min_dist){
       min_dist=dist[girl_city];
       ans=girl_city;}
       
       else if(dist[girl_city]==min_dist && ans>girl_city)
       ans=girl_city;
       
       
       
   }
   cout<<ans<<endl;
   
   
  
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