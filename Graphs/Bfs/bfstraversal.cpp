// Also solution for monk and the isalnd problem hackerearth .
//bfs is used for finding the shortest path as it goes level by level 

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
 int visited[N],dist[N];

void bfs(int node)
{
    queue<int>q;
    q.push(node);
    dist[node]=0;
    visited[node]=1;
    while(!q.empty())
    {
        
        int curr=q.front();
        // cout<<curr<<"->";//prints the bfs path
        q.pop();
        for(auto child:adj[curr] )
        {
            if(!visited[child])
            {
                q.push(child);
                dist[child]=dist[curr]+1;
                visited[child]=1;
            }
        }
    }

}
 
void solve() {
   int n,m,a,b;
   cin>>n>>m;

   for(int i=1;i<=n;i++)//Clearing previous values
   {
       adj[i].clear();
       visited[i]=0;
   }
   for(int i=1;i<=m;i++)
   {
       cin>>a>>b;
       adj[a].pb(b);
       adj[b].pb(a);
   }
   bfs(1);
//    for(int i=1;i<=n;i++)
//    cout<<dist[i]<<" ";
   cout<<dist[n]<<endl;

  
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
      cin>>test;
      
      while(test--)
      {
          //cout<<"Case #"<<tc<<": ";
          //tc++;
         solve();
      }
       
    
    return 0;
	}