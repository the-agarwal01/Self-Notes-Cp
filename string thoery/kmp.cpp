
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
   string s,t,st;
   cin>>s>>t;
   st=s+'#'+t;//adding # so that value of prefix funcn at  a val cant be greater than searched string s
   int n=s.size(),res=0,cnt=0; 
   prefix_function(st);
//   for(auto x:pi)
//   cout<<x<<" ";
vector<int>v;
   for(int i=n+1;i<st.size();i++)  //sda#sadasda
   {
       if(pi[i]==n){
       res++;
      
    //    if(cnt==0)
    //    v.pb(0);                        //needed if also printing position
    //    else if(cnt-(n-1)>=0)
    //    v.pb(cnt-(n-1));
    //    }
       
    //    cnt++;
   }
   cout<<res<<endl;
  for(auto x:v)
  cout<<x<<" ";              //this also prints the first occurence where the string starts
   
  
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