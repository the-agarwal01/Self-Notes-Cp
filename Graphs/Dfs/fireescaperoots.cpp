//Checking the number of connected components and also number of cnodes in each connected componenet
//Link:-https://www.codechef.com/problems/FIRESC
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
 int visited[N],conn_num;
 vector<int>adj[N];

 int dfs(int node)
 {
     visited[node]=1;
     conn_num++;
     for(int child:adj[node])
     {
         if(!visited[child])
         dfs(child);
     }
     return conn_num;
 }

 
void solve() {
    int n,m,a,b,connected=0,ans=1;
    cin>>n>>m;

    for(int i=1;i<=n;i++)//clearing the previous values
    {
        adj[i].clear();
        visited[i]=0;
    }
    for(int i=1;i<=m;i++)//Mkaing the adjacency list
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            conn_num=0;
            connected++;
            dfs(i);
            ans=(ans*conn_num)%mod;

        }
    }
    cout<<connected<<" "<<ans<<endl;

   
  
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