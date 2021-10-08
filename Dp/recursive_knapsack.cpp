//Dp is choice + Optimal
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
 
int knapsack(vector<int>value,vector<int>weight,int w,int n)
{
    //BAse condition
    if(w==0|| n==0)
    return 0;
    
    //Choice Diagram
    if(weight[n-1]<=w)
    {
        return max(value[n-1]+knapsack(value,weight,w-weight[n-1],n-1),knapsack(value,weight,w,n-1));
    }
    else{
        return knapsack(value,weight,w,n-1);
    }
}
 

signed main()
{ 
      ios;
      int n,w;
      cin>>n>>w;
      vector<int>value(n),weight(n);
      for(int i=0;i<n;i++)
      cin>>value[i];
      for(int i=0;i<n;i++)
      cin>>weight[i];
      
      cout<<knapsack(value,weight,w,n)<<endl;
      
      
      
    return 0;
}