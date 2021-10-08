// Substring problem (spoj)  rabin karp version
//Only difference here is that of multiplying with inverse if p^l we take it to the other side and match it.We precompute the powers earlier
//All alphanumneric values are covered here

#include<bits/stdc++.h>
#define lli long long
#define mod 1000000007

#define endl '\n'

using namespace std;
lli dp[1000001];
lli power_arr[1000001];
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


void init(string input_string)//dp stores the hash value of first i characters and inv stores the inverse of p^i
{
	lli p = 67;
	lli p_power = 1;
	// inv[0] = 1;
    power_arr[0]=1;
    if(input_string[0]>='A' && input_string[0]<='Z')
	dp[0] = (input_string[0] - 'A' +27);
	else if(input_string[0]>='a' && input_string[0]<='z')
	dp[0] = (input_string[0] - 'a' + 1);
    else
	dp[0] = (input_string[0]-'1'+53);
	
	
	for(int i=1;i<input_string.size();i++)
	{
		char ch = input_string[i];
		 
		p_power = (p_power * p) % mod;
        power_arr[i]=p_power;
		// inv[i] = power(p_power , mod - 2);
		if(ch>='a' && ch<='z')
		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
		else if(ch>='A' && ch<='Z')
		dp[i] = (dp[i-1] + (ch - 'A' + 27)*p_power) % mod;
		else
		dp[i] = (dp[i-1] + (ch - '1' + 53)*p_power) % mod;
		
	}
}

lli getHash(string key)//hash function for needle
{
	lli value = 0;
	lli p = 67;
	lli p_power = 1;
	
	for(char ch : key)
	{
	    if(ch>='A' && ch<='Z')
	    value = (value + (ch -'A'+27)*p_power) % mod;
	    else if(ch>='a' && ch<='z')
		value = (value + (ch - 'a' + 1)*p_power) % mod;
		else
		value=(value+(ch-'1'+53)*p_power)%mod;
		
		p_power = (p_power * p) % mod;
	}
	
	return value;
}

lli substringHash(int L , int R)//substring hash calcuated here
{
	int result = dp[R];
	
	if(L > 0) result = (result - dp[L-1] + mod) % mod;
	
	// result = (result * inv[L]) % mod;
	
	return result;
}

int main()
{
	string haystack , needle;//haystack is the full string and needle is the substring to find
	int n , L , R , answer;
	bool flag = false;
	cin>>haystack>>n;
		init(haystack);
		
	
	while(n--)
	{
		flag=false;
		cin>>needle;
		
		lli needleHash = getHash(needle);
		
	
		for(L=0 , R=needle.size()-1; R < haystack.size(); L++ , R++)
		{
			if((needleHash*power_arr[L])%mod == substringHash(L , R)){
			cout<<"Y"<<endl;
			flag=true;
			break;
			}
		}
		if(!flag)
		cout<<"N"<<endl;
	}
}

