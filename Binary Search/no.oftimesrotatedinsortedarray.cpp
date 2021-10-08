// first of all->
//  a) type of rotation=>
//            if(array is LEFT rotated then no_of_rotations is equal to (length - index_of_min_element)%length)
           
//            if(  array is RIGHT rotated then no_of_rotations = index_of _min_element)
//            *for right rotation we might have to make few other changes in the code*
// b) one case is missing inside while loop=>
//            add this in the beginning of while loop:
            
//              if(arr[start] <= arr[end]){
//                     return s;
//              }
// c) this code is applicable with a condition that there are NO REPEATED VALUES
//        it is a standard interview problem (search_element_in_rotated_sorted_array )you can find out on leetcode


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
 

 




int pivotIdx(vector<int> arr, int n){
	if(arr[0] < arr[n-1]){
		return 0;
	}

	int pivot = -1;
	int s = 0, e = n-1;
	while(s <= e){
                if(arr[s] <= arr[e]){
                     return s;
                 }
		int mid = s + (e-s)/2;
		int next = (mid+1)%n;
		int prev = (mid-1+n)%n;
		if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
          
                      pivot = mid;
		      break;
            
		}
		if(arr[s] <= arr[mid]){

                       s = mid + 1;//we move to the  unsorted part of the array
		}
		else if(arr[mid] <= arr[e]){
			e = mid - 1;//we move to the  sorted part of the array
		}

	}
   
	return pivot;
}
void solve() {
   int n;
   cin>>n;
   vector<int>v(n);
   rep(i,0,n) cin>>v[i];
   cout<<pivotIdx(v,n);
  
  
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