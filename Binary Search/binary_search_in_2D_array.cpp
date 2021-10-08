/*This is bascially 2D binary search where all element are sorted row and column wise.*/

/*What we do is we put the pointer at the first row last col element and check if it is the target if yes we retur the position else if it is gretaer than the target then it has to be in the downward row so we do i++ else we do j-- means it has to be on the lft side*/
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
 
vector<int> binary_search(vector<vector<int>>v,int n,int m,int target)
{
    vector<int>ans;
    int i=0,j=m-1;
    
    while(i>=0 && i<=n-1 && j>=0 && j<=m-1)
    {
        // cout<<v[i][j]<<" ";
        if(v[i][j]==target)
        {
            ans.pb(i);
            ans.pb(j);
            return ans;

        }
        else if(v[i][j]<target)
        i++;
        else
        j--;
    }     
    ans.pb(-1);
    return ans;
}


 
void solve() {
   int n,m,target;
   cin>>n>>m>>target;
   vector<vector<int>>v(n,vector<int>(m));
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       cin>>v[i][j];
   }

   
   vector<int>ans=binary_search(v,n,m,target);
   for(auto x:ans)
   cout<<x<<" ";
  
  
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