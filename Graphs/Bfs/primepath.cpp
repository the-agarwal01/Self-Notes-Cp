
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
 vector<int>primes;
 int visited[N],dist[N];
vector<bool>prime(N + 1,true);
void SieveOfEratosthenes(int n)
{
    
   
    // memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=false;
    for (int p = 2; p * p <= n; p++)
    {
        
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for(int i=1000;i<=9999;i++)//storing all prime numbers in one place
    {
        if(prime[i])
        primes.pb(i);
    }
}
bool valid(int a,int b)
{
    int cnt=0;
    while(a)
    {
    if(a%10 !=b%10)
    cnt++;

    a/=10,b/=10;
    }

    if(cnt==1)
    return true;
    else
    return false;
}
void buildGraph()
{
    int n=primes.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(valid(primes[i],primes[j]))//Checking if only oen digit differs in it or not,if yes it adds it to the adjacenecy list
            adj[primes[i]].pb(primes[j]),adj[primes[j]].pb(primes[i]);
        }
    }
}
void bfs(int node)
{
    queue<int>q;
    q.push(node);
    visited[node]=1;
    dist[node]=0;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        for(auto child:adj[par])
        {
            if(!visited[child])
            {
                q.push(child);
                visited[child]=1;
                dist[child]=dist[par]+1;
            }
        }
    }

}
 
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1000;i<=9999;i++)
    visited[i]=0,dist[i]=-1;//reinitailazie all as 0 and -1,-1 as if any path is not possible then we can print impossible

    bfs(n);//We use bfs to find the min dist from n to m with n as the root node

    if(dist[m]==-1)
    cout<<"Impossible"<<endl;
    else
    cout<<dist[m]<<endl;
    // for(int i=0;i<primes.size();i++)
    // {
    //     cout<<primes[i]<<" :";
    //     for(auto x:adj[primes[i]])
    //     cout<<x<<"->";
    //     cout<<endl;

    // }
    // cout<<valid(n,m);

   
  
  }

signed main()
{ 
      ios;
      int test;
      test=1;
      int tc=1;
    //   factorial(N-1);
    //   InvFactorial(N-1);
    
    SieveOfEratosthenes(N-1);
    buildGraph();
      cin>>test;
      
      while(test--)
      {
          //cout<<"Case #"<<tc<<": ";
          //tc++;
         solve();
      }
       
    
    return 0;
	}