
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
 
void bubblesort(int arr[],int n)
{
    if(n==1)//base case
    return;

    for(int j=0;j<=n-2;j++){
        if(arr[j]>arr[j+1])
        swap(arr[j],arr[j+1]);

    }
    bubblesort(arr,n-1);
}
void bubblesort2(int arr[],int j,int n)
{
    if(n==1)
    return;

    if(j==n-1){
       return bubblesort2(arr,0,n-1);
    }
    if(arr[j]>arr[j+1])
    swap(arr[j],arr[j+1]);

    return bubblesort2(arr,j+1,n);

}
 
void solve() {
   
  int arr[]={5,4,3,2,1};
  bubblesort2(arr,0,5);
  for(int i=0;i<5;i++)
  cout<<arr[i]<<" ";
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