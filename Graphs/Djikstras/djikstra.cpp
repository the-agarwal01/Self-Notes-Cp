//Time complexity is O(V+ElogV)
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
 
 bool myCompare(int a,int b)
{
  return a>b;
}
clock_t time_p=clock();
void time()
{
	time_p=clock()-time_p;
	cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}




vector<pair<int,int>>adj[N];

 
void solve() {
    int n,m,a,b,w;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});//For directed remove it.
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n+1,1e18);
    pq.push({0,1});//Weight and node number
    dist[1]=0;

    while(!pq.empty())
    {
        int curr=pq.top().ss;
        int curr_d=pq.top().ff;
        pq.pop();

        for(pair<int,int>edge:adj[curr])
        {
            if(curr_d+edge.ss<dist[edge.ff])//for edge node is first then weight ,see {b,w}
            {
                dist[edge.ff]=curr_d+edge.ss;
                pq.push({dist[edge.ff],edge.ff});
            }
        }
    }
    for(int i=1;i<=n;i++)
    cout<<dist[i]<<" ";

    time();


    /* If asked to Use max heap,we can create a max heap instead and then push negative weights in the priority queue and then while taking out the node from the priority queue we can use abs value instead
     int n,e;    cin >> n >> e;
    vector<vector<pair<int , int>>>g(n);
    int u , v, w;
    for(int i=0; i<e; i++){
        cin >> u >> v >> w;
        g[u].push_back({v , w});
        g[v].push_back({u , w});
    }
    priority_queue<pair<int , int>>pq;
    int src;    cin >> src;
    vector<int>dist(n , 1e9);
    pq.push({0,src});
    dist[src] = 0;
    while(!pq.empty()){
        pair<int,int> node = pq.top();
        pq.pop();
        for(auto it : g[node.second]){
            if(abs(node.first) + it.second < dist[it.first]){
                dist[it.first] = abs(node.first)+it.second;
                pq.push({-dist[it.first] , it.first});
            }
        }
    }*/
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
      // cout << fixed << setprecision(15);
       
    
    return 0;
	}