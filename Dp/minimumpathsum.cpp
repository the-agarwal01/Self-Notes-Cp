
//https://leetcode.com/problems/minimum-path-sum/submissions/
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
 

 int arr[1001][1001];
 int dp[1001][1001];
 int n,m;
 
 
 

signed main()
{ 
      ios;
      
      cin>>n>>m;
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
          cin>>arr[i][j];
      }
      for(int i=1;i<=m+1;i++)
      dp[n+1][i]=INT_MAX;
      
      for(int i=1;i<=n+1;i++)
      dp[i][m+1]=INT_MAX;
      
      dp[n+1][m]=dp[n][m+1]=0;
      
      for(int i=n;i>=1;i--)
      {
          for(int j=m;j>=1;j--)
          {
              dp[i][j]=arr[i][j]+min(dp[i][j+1],dp[i+1][j]);
          }
      }
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
          cout<<dp[i][j]<<" ";
          cout<<endl;
      }
      cout<<dp[1][1];
      
      
      
      
      
    
    return 0;
	}