
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

const int N = 8;
int visited[9][9],dist[9][9];
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
bool isvalid(int x,int y)
{
    if(x>N || x<1 || y>N ||y<1)
    return false;

    if(visited[x][y])
    return false;

    return true;
}
void bfs(int srcx,int srcy)
{
    queue<pair<int,int>>q;
    q.push({srcx,srcy});
    // visited[srcx][srcyy]=1;
    dist[srcx][srcy]=0;
    while(!q.empty())
    {
        int currx=q.front().ff;
        int curry=q.front().ss;
        q.pop();

        for(int i=0;i<8;i++)
        {
            if(isvalid(currx+dx[i],curry+dy[i]))
            {
                int newx=currx+dx[i],newy=curry+dy[i];
                visited[newx][newy]=1;
                q.push({newx,newy});
                dist[newx][newy]=dist[currx][curry]+1;
            }
        }

    }

}
 

 
void solve() {
   string a,b;
   cin>>a>>b;
   int srcx=(a[0]-'a')+1;
   int srcy=a[1]-'1'+1;
   int endx=b[0]-'a'+1;
   int endy=b[1]-'1'+1;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
        visited[i][j]=0;
        dist[i][j]=0;
        }


    }
   bfs(srcx,srcy);
   cout<<dist[endx][endy]<<endl;

//    cout<<srcx<<" "<<srcy<<" "<<endx<<" "<<srcy<<endl;
  
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