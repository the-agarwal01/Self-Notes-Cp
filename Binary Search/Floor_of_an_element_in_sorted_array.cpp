/*Basically floor of an element in an array means that we have to find the same element if it exists or just smaller element than it*/
/*Similarly we can find the ceil of an eleemnt also*/

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
 

int binary_search(vector<int>v,int target,int n)
{
    int l=0,r=n-1,mid,res=-1;
  while(l<=r)
  {
      mid=l+(r-l)/2;
      if(v[mid]==target)
      return v[mid];
      else if(v[mid]>target)
      {
          r=mid-1;
      }
      else{
          l=mid+1;
        //   if(v[l]<target)//Just storing the largest value closer to it 
        //   res=max(res,v[l]);
        res=v[mid];
      }
  }
      return res;


  
} 
void solve() {
   
  int n,target;
  cin>>n>>target;
  vector<int>v(n);
  rep(i,0,n) cin>>v[i];
  cout<<binary_search(v,target,n);
  
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