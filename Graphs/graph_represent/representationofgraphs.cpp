//Graph represenatation using Adjacency  list
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
 
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}
void printList(vector<int>adj[],int vertices)
{
    for(int i=0;i<vertices;i++)
    {
        cout<<i;
    for(auto x:adj[i])
    cout<<"->"<<x;
    cout<<endl;
    }

}
void solve() {
    int v;
    cin>>v;
   vector<int>adj[v+1];//array of vectors(2-d vector)
   addEdge(adj,0,4);
   addEdge(adj,2,3);
   addEdge(adj,1,5);
   addEdge(adj,2,4);

  printList(adj,v);
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