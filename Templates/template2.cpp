
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int 				long long
#define ll          long long
#define pb 					push_back
#define endl 				'\n'
#define ff 					first
#define ss 					second
#define vi 					vector<int>
#define pii 				pair<int, int>
#define all(x)				(x).begin(), (x).end()
#define rep(i, a, b)		for(int i=a; i<b; i++)
#define setbits(x) 			__builtin_popcountll(x)
#define ios				ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 				1e19
#define mod 				1000000007 // 1e9+7
#define MOD 				1000000007 // 1e9+7

 
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

using namespace std;
using namespace __gnu_pbds;


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
 /*  pbds A;
    *A.find_by_order(k);//gives the address of kth  element in the set(thus star before)
     A.order_of_key(k)// gives the number of eleememts smaller than k 
    
    instead of less<int>,greater<int> will make it sort in descending order and less_equal will make it a multiset in ascending .
 */

const int N = 200005;
 

 bool myCompare(int a,int b)
{
  return a>b;
}
clock_t time_p=clock();
void timedekhlo()
{
	time_p=clock()-time_p;
	cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
ll seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());

inline ll rnd(ll l=0,ll r=INF){return uniform_int_distribution<ll>(l,r)(rng);}
bool isPrime(int n) 
{ 
    
    if (n <= 1) 
        return false; 
  
    
    for (int i = 2; i*i<= n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
}
bool isPalindrome(string str)
{
    
    int l = 0;
    int h = str.length() - 1;
  
   
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
           
            return false;
        }
    }
   return true;
}

 vector<bool>prime(N + 1,true);
void SieveOfEratosthenes(int n)
{
    
   
    // memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=false;
    for (int p = 2; p * p <= n; p++)
    {
        
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
 int power(int x, unsigned int y) 
{ 
    int res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x%mod; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x % mod;  // Change x to x^2 
    } 
    return res%mod; 
}

ll fastModuloExponentiation(ll a,ll b,ll M)
{
    ll result=1;
    while(b>0){
    if(b&1){
    result=(result*a)%M;}
    
    a=(a*a)%M;
    
    b=b>>1;
    }
   return result;
    
}
int modInv(int a){return power(a,MOD-2);}
int fact[N],inv[N];
void factorial(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++){
		fact[i]=fact[i-1]*i;
		if(fact[i]>=MOD)
			fact[i]%=MOD;
	}
}
void InvFactorial(int n){
	inv[0]=1;
	for(int i=1;i<=n;i++)
		inv[i]=modInv(fact[i]);
}
int ncr(int n,int r){
    
	if(n<r||n<0||r<0)
		return 0;
	int b=inv[n-r];
	int c=inv[r];
	int a=fact[n]*b;
	if(a>=MOD)
		a%=MOD;
	a*=c;
	if(a>=MOD)
		a%=MOD;
	return a;
}


void solve() {
   
  cout<<(6*fastModuloExponentiation(4,13,mod))%mod;
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