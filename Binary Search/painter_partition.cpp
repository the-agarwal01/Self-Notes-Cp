/*Its binary search on ans*/
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
 
bool valid(vector<int>v,int mini,int n,int k)
{
    int cnt=1,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum>mini)
        {
            cnt++;
            sum=v[i];
        }
        
    }
    if(cnt<=k)
    return true;
    else
    return false;
}
 
void solve() {
   
  int n,k,sum=0,res;
  cin>>n>>k;
  vector<int>v(n);
  rep(i,0,n){ cin>>v[i];
  sum+=v[i];}
  
  int l=v[n-1],r=sum;
  while(l<=r)
  {
      int mid=l+(r-l)/2;
      if(valid(v,mid,n,k)){
          res=mid;
          r=mid-1;
      }
      
      else
      l=mid+1;
  }
  cout<<res;
  
  
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