
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
 int n,m;
 bool vis[1000][1000];
 bool isvalid(int x,int y)
 {
     if((x<1 || x>n )|| (y<1) || y>m)
     return false;

     if(vis[x][y])
     return false;

     return true;
 }
 int dx[]={-1,0,1,0};//It stores the change in x and y possible
 int dy[]={0,1,0,-1};

//  int dx[]={-1,-1,-1,0,0,1,1,1};
//  int dy[]={-1,0,1,-1,1,-1,0,1}; When the corner are also allowed

 void dfs(int x,int y)// Shorter version.....
 {
     vis[x][y]=1;
     cout<<x<<" "<<y<<endl;
     for(int i=0;i<4;i++)
     {
         if(isvalid(x+dx[i],y+dy[i]))
         dfs(x+dx[i],y+dy[i]);
     }
 }
//  void dfs(int x,int y)
//  {
//      vis[x][y]=1;
//      cout<<x<<" "<<y<<endl;

//      if(isvalid(x-1,y))   //Up
//      dfs(x-1,y);

//      if(isvalid(x,y+1))   //Right
//      dfs(x,y+1);

//      if(isvalid(x+1,y))   //Down
//      dfs(x+1,y);

//      if(isvalid(x,y-1)) //Left
//      dfs(x,y-1);
//  }




 
void solve() {
     
     cin>>n>>m;
     dfs(1,1);
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