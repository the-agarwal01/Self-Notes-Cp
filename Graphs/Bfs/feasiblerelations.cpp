//Using dfs to solve it and cocnept of connected componenets
//Link:-https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/
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
 int visited[N],cc[N],curr_cc=0;

void dfs(int node)
{
    visited[node]=1;
    cc[node]=curr_cc;//storing the current node connected component here
    for(auto child:adj[node])
    {
        if(!visited[child])
        dfs(child);
    }
}

 
void solve() {
        int n,k,a,b;
        cin>>n>>k;
        string st;
        vector<pair<int,int>>check;

        for(int i=1;i<=n;i++) //Clearing previous values
        adj[i].clear(),visited[i]=0;

        for(int i=1;i<=k;i++)
        {
            cin>>a>>st>>b;
            if(st=="=")
            adj[a].pb(b),adj[b].pb(a);
            else{
                check.pb({a,b});//The != ones are sttored here whereas the equal ones ares tored as edges 
            }

        }
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                dfs(i);
                curr_cc++;
            }
        }
        bool flag=true;
        for(int i=0;i<check.size();i++)
        {
            int a=check[i].ff;
            int b=check[i].ss;
            if(cc[a]==cc[b])
            {
                flag=false;
                break;
            }
        }
        if(flag)
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
      cin>>test;
      
      while(test--)
      {
          //cout<<"Case #"<<tc<<": ";
          //tc++;
         solve();
      }
       
    
    return 0;
	}