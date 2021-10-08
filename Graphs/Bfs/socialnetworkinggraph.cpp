//problem link is broken for reading refer this https://stackoverflow.com/questions/51208644/bfs-social-network-algorithmgraph-algorithm-hackerearth
//Bascially given source and a dist we have to tell how many nodes are connected at dist d from the source
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
 int visited[N],dist[N],level[NOMINMAX];

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
                level[dist[child]]++;//all nodes from that dist will be stored
            }
        }
    }

}
 
void solve() {
   int n,m,a,b,q,src,d;
   cin>>n>>m;

  
   for(int i=0;i<m;i++)
   {
       cin>>a>>b;
       adj[a].pb(b);
       adj[b].pb(a);
   }
   cin>>q;
   while(q--)
   {
       cin>>src>>d;
       for(int i=0;i<=n;i++)
       level[i]=0,visited[i]=0;

       bfs(src);
       cout<<level[d]<<endl;
   }
  

  
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
    //   cin>>test;
      
      while(test--)
      {
          //cout<<"Case #"<<tc<<": ";
          //tc++;
         solve();
      }
       
    
    return 0;
	}