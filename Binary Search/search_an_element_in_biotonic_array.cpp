/*Biotonic array means array where eleemnts are first increasing then decreasing../*

/*We find the peak element in the array and then all elements to the left are the increasing and to the right are decreasing so we apply binary search on both and if one of them gives a positive value we return it.*/



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
 int increasing(vector<int>v,int l,int r,int target)
 {
     while(l<=r)
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
 int decreasing(vector<int>v,int l,int r,int target)
 {
     while(l<=r)
     {
         int mid=l+(r-l)/2;
         if(v[mid]==target)
         return mid;
         else if(v[mid]>target)
         l=mid+1;
         else
         r=mid-1;
     }
     return -1;
 }

 
void solve() {
    int n,target;
    cin>>n>>target;
    vector<int>v(n);
    rep(i,0,n) cin>>v[i];
    int peak=binary_search(v,n);
    if(v[peak]==target){
    cout<<peak;
    return;}
    int res1=increasing(v,0,peak-1,target);
    int res2=decreasing(v,peak+1,n-1,target);
    cout<<peak<<" "<<res1<<" "<<res2<<endl;
    cout<<max(res1,res2);

   
  
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