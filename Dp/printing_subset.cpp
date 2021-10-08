
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
 
int dp[1001];

 


signed main()
{ 
      ios;
      int n,sum;
      cin>>n>>sum;
      vector<int>v(n);
      rep(i,0,n) cin>>v[i];
      
      dp[0]=1;
      for(int i=0;i<n;i++)
      {
          for(int j=sum;j>=v[i];j--)
          {
              if( dp[j]!=0 || dp[j-v[i]]==0)
              continue;
              else
              dp[j]=v[i];
              
          }
      }
    //   for(auto x:dp)
    //   cout<<x<<" ";
      
      if(dp[sum])
      {
          cout<<"YEs"<<endl;
          while(sum!=0)
          {
              cout<<dp[sum]<<" ";
              sum-=dp[sum];
          }
      }
      else
      cout<<"No"<<endl;
      
      
       
    
    return 0;
	}