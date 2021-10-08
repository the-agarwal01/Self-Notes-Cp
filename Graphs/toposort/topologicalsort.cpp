/*Topological sort can be used for solving deadlock problems in operating system.Topological sort basically gives a path in which previous
 dependencies have been fulfilled and present dependency can be continued.This is the reason why there is no one answer for this sort.*/
 //Time complexity is O(V+E)

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
vector<int>ans;
int in[N],n,m;
void kahn()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)// storing all in vertices with 0 values
        q.push(i);
    }
    while(!q.empty())
    {
        int curr=q.front();
        ans.pb(curr);
        q.pop();
        for(auto x:adj[curr])
        {
            in[x]--; // decreasing the value by 1 as the curr node is already counted and its dependecies is removed. 
            if(in[x]==0)
            q.push(x);
        }

    }
    for(auto x:ans)//printing the topo sort
    cout<<x<<" ";

}
 
void solve() {
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
        in[b]++;
    }
    kahn();
   
  
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