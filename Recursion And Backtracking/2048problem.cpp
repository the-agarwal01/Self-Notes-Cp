//print 2048 in digits using recursion
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
void printi(int n)
{
    if(n==0)
    cout<<"Zero ";
    else if(n==1)
    cout<<"One ";
    else if(n==2)
    cout<<"Two ";
    else if(n==3)
    cout<<"Three ";
    else if(n==4)
    cout<<"Four ";
     else if(n==5)
    cout<<"Five ";
    else if(n==6)
    cout<<"Six ";
    else if(n==7)
    cout<<"Seven ";
    else if(n==8)
    cout<<"Eight ";
    else if(n==9)
    cout<<"Nine ";
    

}
void ans(int n)
{
    if(n==0){
        return;
    }
    ans(n/10);
    printi(n%10);
}


 
void solve() {
   
  ans(2048);
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