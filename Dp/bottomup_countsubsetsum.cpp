
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
      int n,sum;
      cin>>n>>sum;
      vector<int>weight(n);
      
      for(int i=0;i<n;i++)
      cin>>weight[i];
      int dp[n+1][sum+1];
      
      //Base condition
      for(int i=0;i<=sum;i++)//making all first row elements as 0 means false;
      dp[0][i]=0;
      
      for(int i=0;i<=n;i++)//making all first column elements as 1 means true;
      dp[i][0]=1;
      
      
      
      
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=sum;j++)
          {
              if(weight[i-1]<=j)
              {
                  dp[i][j]=dp[i-1][j-weight[i-1]] + dp[i-1][j];
              }
              else{
                  dp[i][j]=dp[i-1][j];
              }
          }
      }
      
      
      cout<<dp[n][sum]<<endl;
      
      
      
    return 0;
}