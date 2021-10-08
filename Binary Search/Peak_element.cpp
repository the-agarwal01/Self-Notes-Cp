/*Peak element means element which is greater than both of its neighbours*/
/*Also note that there is atleast one peak element there in an array always*/


/*We use binary search to check if mid is greater than both of its neighbours or not,if yes we return the position else we check if mid-1 is greater if yes then there is a possibility that an element might be there else we check for mid+1.for first and last position we check seperately*/
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
 
 int binary_search(vector<int>v,int n)
 {
     int l=0,r=n-1;
     while(l<=r)
     {
         int mid=l+(r-l)/2;
         if(mid>0 && mid<n-1)
         {
             if(v[mid]>v[mid-1] && v[mid]>v[mid+1])
             return mid;

             else if(v[mid]<v[mid-1])
             r=mid-1;

             else
             l=mid+1;
         }
         else if(mid==0)
         {
             if(v[mid]>v[mid+1])
             return mid;
             else
             return mid+1;
         }
         else
         {
             if(v[mid]>v[mid-1])
             return mid;
             else
             return mid-1;
         }
     }
     return -1;
 }

 
void solve() {
    int n;
    cin>>n;
    vector<int>v(n);
    rep(i,0,n) cin>>v[i];
    cout<<binary_search(v,n);

   
  
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