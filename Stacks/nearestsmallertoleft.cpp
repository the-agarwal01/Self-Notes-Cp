
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
 /*changes made is reversed gretaer and less than signs and reverse removed*/

 
void solve() {
    int n;
   cin>>n;
   vector<int>v(n),ans;
   rep(i,0,n) cin>>v[i];
   stack<int>st;
   for(int i=0;i<n;i++)
   {
       if(st.size()==0)
           ans.pb(-1);
       
       else if(st.top()<v[i] && st.size()>0)
        ans.pb(st.top());
       else if(st.top()>=v[i] && st.size()>0)
       {
          while(st.size()>0 && st.top()>=v[i] ){//always write s.size() before otherwise it gives run time error
            //   cout<<st.top()<<" ";
               st.pop();
          }
         
           
           if(st.empty())
           ans.pb(-1);
           else 
           ans.pb(st.top());
       }
        st.push(v[i]);
       
       
       
       
   }
 
  for(auto x:ans) cout<<x<<" ";
  

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