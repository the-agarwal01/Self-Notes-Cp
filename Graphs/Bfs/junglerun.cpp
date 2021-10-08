//Application for 2D bfs
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

const int N = 31;
 vector<int>adj[N];
 int visited[N][N],dist[N][N],n,m;
 char arr[N][N];

 int dx[]={-1,0,1,0};//It stores the change in x and y possible
 int dy[]={0,1,0,-1};

 bool isvalid(int x,int y)
 {
     if((x<1 || x>n )|| (y<1) || y>m)
     return false;

     if(visited[x][y] || arr[x][y]=='T')
     return false;

     return true;
 }

void bfs(int srcx,int srcy)
{
    queue<pair<int,int>>q;
    q.push({srcx,srcy});

    visited[srcx][srcy]=1;
    dist[srcx][srcy]=0;
    while(!q.empty())
    {
        int currx=q.front().ff;
        int curry=q.front().ss;
        q.pop();
        for(int i=0;i<4;i++)
        {
        if(isvalid(currx+dx[i],curry+dy[i]))
        {
            int newX=currx+dx[i];
            int newY=curry+dy[i];
            q.push({newX,newY});
            visited[newX][newY]=1;
            dist[newX][newY]=dist[currx][curry]+1;


        }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     cout<<dist[i][j]<<" ";
    //     cout<<endl;
    // }

}
 
void solve() {
   cin>>n;
   m=n;
   int srcx,srcy,endx,endy;
   rep(i,1,n+1)
   {
       rep(j,1,n+1)
       {
       cin>>arr[i][j];
       if(arr[i][j]=='S')
       srcx=i,srcy=j;
       if(arr[i][j]=='E')
       endx=i,endy=j;       }
   }
   bfs(srcx,srcy);
   cout<<dist[endx][endy];
   
   

  
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