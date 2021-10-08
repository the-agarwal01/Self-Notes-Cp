//Question https://www.spoj.com/problems/MPOW/
//for direct multiplication just remove mod in res


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
const int  mod =1e9+7;
#define REP(i,n) for(int i=1;i<=n;i++)
#define N 101

int arr[N][N],I[N][N];
void mul(int A[][N],int B[][N],int dim)
{
    int res[dim+1][dim+1];//product will be dim length and since start from 1 so dim+1
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
void power(int A[][N],int dim,int n){
    REP(i,dim)
    { 
        REP(j,dim){
            if(i==j) I[i][j]=1;//Making the identity matrix
            else I[i][j]=0;
        }
    }
    
    while(n>0)
    {
        if(n%2==0){
            mul(A,A,dim);
            n/=2;

        }
        else{
        mul(I,A,dim);
        n--;}
    }

    REP(i,dim) REP(j,dim) A[i][j]=I[i][j]; //We copy elemnts of I into A as values of A will be copied to arr by refernce and will be printed


}
void printans(int A[][N],int dim)
{
    REP(i,dim) 
    {
        REP(j,dim)
        cout<<A[i][j]<<" ";
        cout<<endl;
    }
}

signed main()
{
    ios;
    int t,dim,n;
    cin>>t;
    while(t--)
    {
        cin>>dim>>n;
        REP(i,dim) REP(j,dim) cin>>arr[i][j];
        
            
       
        power(arr,dim,n);
        printans(arr,dim);
        
    }
}