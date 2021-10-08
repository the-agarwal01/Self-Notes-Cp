//Rolling Hash but will help of 2 hash functions for better accuracy
// problem  link:-https://www.spoj.com/problems/ADACLEAN/


#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
lli dp1[1000001];
lli dp2[1000001];
lli inv1[1000001];
lli inv2[1000001];
// lli inv[1000001];

lli power(lli a , lli n)
{
	lli result = 1;
	
	while(n)
	{
		if(n & 1) result = (result * a) % mod;
		
		n >>= 1;
		a = (a * a) % mod;
	}
	
	return result;
}


void init1(string input_string)//dp stores the hash value of first i characters and inv stores the inverse of p^i
{
	lli p = 37;
	lli p_power = 1;
	inv1[0] = 1;
    // power_arr[0]=1;
	dp1[0] = (input_string[0] - 'a' + 1);
	
	
	for(int i=1;i<input_string.size();i++)
	{
		char ch = input_string[i];
		 
		p_power = (p_power * p) % mod;
        // power_arr[i]=p_power;
		inv1[i] = power(p_power , mod - 2);
		
		dp1[i] = (dp1[i-1] + (ch - 'a' + 1)*p_power) % mod;
	}
}
void init2(string input_string)//dp stores the hash value of first i characters and inv stores the inverse of p^i
{
	lli p = 47;
	lli p_power = 1;
	inv2[0] = 1;
    // power_arr[0]=1;
	dp2[0] = (input_string[0] - 'a' + 1);
	
	
	for(int i=1;i<input_string.size();i++)
	{
		char ch = input_string[i];
		 
		p_power = (p_power * p) % mod;
        // power_arr[i]=p_power;
		inv2[i] = power(p_power , mod - 2);
		
		dp2[i] = (dp2[i-1] + (ch - 'a' + 1)*p_power) % mod;
	}
}



lli substringHash1(int L , int R)//substring hash calcuated here
{
	int result = dp1[R];
	
	if(L > 0) result = (result - dp1[L-1] + mod) % mod;
	
	result = (result * inv1[L]) % mod;
	
	return result;
}
lli substringHash2(int L , int R)//substring hash calcuated here
{
	int result = dp2[R];
	
	if(L > 0) result = (result - dp2[L-1] + mod) % mod;
	
	result = (result * inv2[L]) % mod;
	
	return result;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n,k,i,j;
        cin>>n>>k>>s;
        init1(s);
        init2(s);
        set<pair<int,int>>ss;
        for( i=0,j=k-1;j<n;i++,j++)//We use 2 hashes as collision was occuring in some case when single hash was used.
        {
            ss.insert({substringHash1(i,j),substringHash2(i,j)});
        }
        cout<<ss.size()<<endl;
        
    }


	
// 	while(cin>>n)
// 	{
// 		cin>>needle;
// 		cin>>haystack;
		
// 		lli needleHash = getHash(needle);
		
// 		init(haystack);
		
// 		for(L=0 , R=needle.size()-1; R < haystack.size(); L++ , R++)
// 		{
// 			if((needleHash*power_arr[L])%mod == substringHash(L , R))
// 			cout<<L<<endl;
// 		}
		
// 		cout<<endl;
// 	}
}

