
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
 
// int knapsack(vector<int>value,vector<int>weight,int w,int n)
// {
//     //BAse condition
//     if(w==0|| n==0)
//     return 0;
    
//     //Choice Diagram
//     if(weight[n-1]<=w)
//     {
//         return max(value[n-1]+knapsack(value,weight,w-weight[n-1],n-1),knapsack(value,weight,w,n-1));
//     }
//     else{
//         return knapsack(value,weight,w,n-1);
//     }
// }
 

signed main()
{ 
      ios;
      int n,w;
      cin>>n;
      vector<int>value(n),weight(n);
      for(int i=0;i<n;i++)
      cin>>value[i];
      for(int i=0;i<n;i++)
      weight[i]=i+1;
      int dp[n+1][n+1];
      for(int i=0;i<=n;i++)//Base condition
      {
          for(int j=0;j<=n;j++)
          {
              if(i==0|| j==0)
              dp[i][j]=0;
          }
      }
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=n;j++)
          {
              if(weight[i-1]<=j)
              {
                  dp[i][j]=max(value[i-1]+dp[i][j-weight[i-1]],dp[i-1][j]);
              }
              else{
                  dp[i][j]=dp[i-1][j];
              }
          }
      }
      
      
      cout<<dp[n][n]<<endl;
      
      
      
    return 0;
}