
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

void lcs(string a,string b,int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0|| j==0)
            dp[i][j]= 0;
    
            else if(a[i-1]==b[j-1])
            dp[i][j]= (1+dp[i-1][j-1]);
    
            else
            dp[i][j] =max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    
}

signed main()
{ 
      ios;
      string a,b;
      cin>>a>>b;
    //   a='.'+a;
    //   b='.'+b;
      int n=a.size(),m=b.size();
      lcs(a,b,n,m);
      cout<<dp[n][m];
     
       
    
    return 0;
	}