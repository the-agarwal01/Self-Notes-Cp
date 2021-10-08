//Checking if it is a tree or not
//Problem link:Type same name as file

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
 
 int visited[N];
vector<int>adj[N];

void dfs(int node)
{
    visited[node]=1;
    for(auto x:adj[node])
    {
        if(!visited[x])
        dfs(x);
    }

}
 
void solve() {
   int n,m,a,b,cnt=0;
   cin>>n>>m;
   rep(i,0,m) //creating adjacency list
   {
       cin>>a>>b;
       adj[a].pb(b);
       adj[b].pb(a);
   }

   for(int i=1;i<=n;i++)
   {
       if(!visited[i]){
           dfs(i);
           cnt++;
       }
   }
   if(cnt==1 && m==n-1)// for tree checking if it is a single connected component and if edges if 1 less tahn vertices
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