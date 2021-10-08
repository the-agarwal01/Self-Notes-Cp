//Problem -->>>https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem

//Also refer https://www.codechef.com/problems/TILE

//FORMULA:-
/*(F1 F2) *(magic matrix)^n-1=(Fn Fn+1)*/


#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
const int  mod =1e9+7;
#define REP(i,n) for(int i=1;i<=n;i++)
#define N 101
ll T[3][3],I[3][3];
void mul(ll A[][3],ll B[][3],ll dim)
{
    ll res[dim+1][dim+1];//product will be dim length and since start from 1 so dim+1
    REP(i,dim)
    {
        REP(j,dim)
        {
            res[i][j]=0;
            REP(k,dim) res[i][j] = (res[i][j] % mod + ((A[i][k] % mod) * (B[k][j] % mod) % mod)) % mod ;
        }
    }

    REP(i,dim) REP(j,dim) A[i][j]=res[i][j];//We copy elemnts of res into A as values of A will be copied to I by refernce and will be used

}
ll getn(ll a ,ll b,ll n)
{
    if(n==1)//fibnacci at pos 1 is 1 
    return a;
    else if(n==2)
    return b; //finonacci at 2 is 2
    else
    {
        n--;//raise power n-1
        I[1][1]=I[2][2]=1;  I[1][2]=I[2][1]=0; //identity matrix
        T[1][1]=0;   T[1][2]=T[2][1]=T[2][2]=1;//Transition matrix
         while(n>0)
        {
        if(n%2==0){
            mul(T,T,2);
            n/=2;

        }
        else{
        mul(I,T,2);
        n--;}
    }


        ll ans=(I[1][1]*a+I[2][1]*b)%mod;
        return ans;

    }



}




signed main()
{
    ios;
    ll t,a,b,n;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        n+=1;//so it becomes 1 based indexing 
        ll ans=getn(a,b,n);
        cout<<ans<<endl;
    }
}
