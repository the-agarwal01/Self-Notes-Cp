
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
 int dp[1000][1000];
int lcsubstring(string a,string b,int n,int m,int cnt)
{
    if(n==0||m==0)
    return dp[n][m]= cnt;
    
    if(dp[n][m]!=-1)
    return dp[n][m];
    
    else if(a[n-1]==b[n-1])
     dp[n][m]=cnt=lcsubstring(a,b,n-1,m-1,cnt+1);
    
    else 
     dp[n][m]=cnt=max(cnt,max(lcsubstring(a,b,n-1,m,0),lcsubstring(a,b,n,m-1,0)));
     
     
     return dp[n][m]=cnt;

    
}

signed main()
{ 
      ios;
      string a,b;
      cin>>a>>b;
      int n=a.size(),m=b.size();
     memset(dp,-1,sizeof(dp));
      cout<<lcsubstring(a,b,n,m,0);
     
       
    
    return 0;
	}