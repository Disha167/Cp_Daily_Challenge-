//Day 13 Problem 1
//An interesting problem based on two pointers. Every friend is characterized by money and friend_factor so we create a structure T for friend having 2 members money and 
//friend_factor and our task is to find the optimal company i.e. where no friend has d units less money than any other friend in company and total friend_factor is maximised.
//We arrange the array in increasing order of money, so as to use the trick that if A[right]-A[left] is >d, then all A[right+1], A[right+2] & so on.... will be greater than 
//A[right], hence all will have d units more money than A[left]. So, for every index of left, We repeat the same process i.e. keep on incrementing right untill difference
//becomes greater than d and then keep on increasing left and storing the prefix_sum i.e. friendship_factor value, we do this for every index hence coveing the whole array. 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
struct T{
    ll money;
    ll friend_factor;
};
bool cmp(T a, T b){
    return (a.money<b.money);
}
void tests() {

    ll n,d;
    cin>>n>>d;
    T arr[100005]={0};
    ll i=1;
    while(i<=n)
    {
       cin>>arr[i].money>>arr[i].friend_factor; 
       i++;
    }
    sort(arr+1,arr+n+1,cmp);
    ll prefix_sum[100005]={0};
   
    for(ll i=1;i<=n;i++)
    {
        prefix_sum[i]=prefix_sum[i-1]+arr[i].friend_factor;
       //cout<<prefix_sum[i]<<endl;
    }
    ll left=1,right=1;
    ll ans=0;
    while(left<=n)
    {
        
        while(right<=n&&arr[right].money-arr[left].money<d)
        {
            right++;
        }
        right--;
        ans=max(ans,prefix_sum[right]-prefix_sum[left-1]);
        left++;///we do this for every index untill left becomes n
    }
   cout<<ans<<endl;

}
int32_t main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int t = 1;
//	cin>>t;
	while(t--){
		tests();
	}
    return 0 ; 
}
