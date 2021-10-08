//many implelementation ,one of them is to find whether given 2 nodes if either of them lie in each other subtree or not


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

const int N =10;
 vector<int>adj[N];
 int visited[N],out[N],in[N];
int timer =1;
 void dfs(int node)
 {
     visited[node]=1;
    in[node]=timer++;
    for(int child:adj[node])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }
    out[node]=timer++;
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
   dfs(1);
    for(auto x:in)
    cout<<x<<" ";
    cout<<endl;
    for(auto x:out)
    cout<<x<<" ";

    int x,y;
    cin>>x>>y;
    if(in[x]>in[y] && out[x]<out[y] || in[x]<in[y] && out[x]>out[y])
    cout<<"They are in the same subtree"<<endl;
    else
    cout<<"They are in diiferent subtrees"<<endl;
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