
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
#define minheap     priority_queue<int,vector<int>,greater<int>>
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 				1e19
#define mod 				1000000007 // 1e9+7
 
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

 using namespace std;
 using namespace __gnu_pbds;

 typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
 /*  pbds A;
    *A.find_by_order(k);//gives the address of kth  element in the set(thus star before)->indexing starts from 0
     A.order_of_key(k)// gives the number of eleememts smaller than k 
    
    instead of less<int>,greater<int> will make it sort in descending order and less_equal will make it a multiset in ascending .
 */



const int N = 200005;
 
 bool myCompare(int a,int b)
{
  return a>b;
}
clock_t time_p=clock();
void time()
{
	time_p=clock()-time_p;
	cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
// ll seed;
// mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());

// inline ll rnd(ll l=0,ll r=INF){return uniform_int_distribution<ll>(l,r)(rng);}

/*Steps*/
/*
1.Find appropriate values of i,j.
2.find base condition wrt i,j.+
3.find range of k.
4.Calculate fir temp ans.
*/
int dp[1001][1001];
int recur(int arr[],int i,int j)
{
    if(i>=j)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=recur(arr,i,k)+recur(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}
 
void solve() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<recur(arr,1,n-1);

   
  
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
      // cout << fixed << setprecision(15);
       
    
    return 0;
	}