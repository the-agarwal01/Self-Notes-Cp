
#include <iostream>
#include<vector>
#define int 				long long
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl 				'\n'

 using namespace std;
 string s;
  int k,n,ans;
const int N = 1000001;
 vector<int> pi(N);
 void prefix_function(string s) {//prefix funcn that calcn the value of pi 
    int n = (int)s.length();
   
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    
}
 
void solve() {
 
  cin>>s>>k;
   n=s.size(),ans;
//   cout<<s<<k;
  prefix_function(s);
//   cout<<n;
//   for(int i=0;i<n;i++)
//   cout<<pi[i]<<" ";
  
//   rep(i,0,n)
//   {
//       maxi=max(maxi,pi[i]);
//   }
  
//   cout<<maxi<<endl;
  ans=n+(k-1)*(n-pi[n-1]);
  cout<<ans<<endl;

  
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
      cin>>test;
      
      while(test--)
      {
          //cout<<"Case #"<<tc<<": ";
          //tc++;
         solve();
      }
       
    
    return 0;
	}