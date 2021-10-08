/*SO we have to find the minimum absolute difference of an element with the target element in an sorted array*/ 

/*We do it by finding the floor and ceil value of the taget and get the min difference.Ceil is element just gretaer than it and floor is just smaller than the target.But this is the longer method*/

/*Shorter method is for any given vlaue if the value is not present the high and low gives the neighbouring element positions wrt to value so we just return min(abs(v[l]-target,abs(v[r]-target)))*/

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
    int l=0,r=n-1,mid,res1,res2;
  while(l<=r)
  {
      mid=l+(r-l)/2;
      if(v[mid]==target)
      return 0;
      else if(v[mid]>target)
      {
          res2=v[mid];//ceil value
          r=mid-1;
      }
      else{
          l=mid+1;
        
        res1=v[mid];//floor value
      }
      cout<<l<<" "<<r<<endl;
  }
      return min(abs(res1-target),abs(res2-target));


  
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