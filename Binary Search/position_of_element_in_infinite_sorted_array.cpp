/*The only diff btw this and normal bs is that the array is infinite and we cant set the upper limit  for it initilally*/
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
 
int binary_search(vector<int>v,int target,int n)//if array is in ascending order
{
    
     int l=0,r=1;
     while(v[r]<target)//We keep the r just next to the l and traverse until we finally find a range where we can binary search and then we do it
     {
         l=r;
         r=r*2;
     }
   while(l<=r)//l==r when we have only one element
   {
       int mid=l+(r-l)/2;
       if(v[mid]==target)
       return mid;
       else if(v[mid]>target)
       r=mid-1;
       else
       l=mid+1;

   }
   return -1;
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