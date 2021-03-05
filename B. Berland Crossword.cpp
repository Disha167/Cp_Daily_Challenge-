//Day 13 Problem 1
//tricky problem , many edge cases if consider every test case so it is better to find the number of uncommmon vertices
//The idea is to keep on decreasing l and r if u or d is n or n-1 as similarly for u and d and then check at last the number of uncommon shapes, if they are positive
//then blocks can be painted
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void tests() {
int n,u,r,d,l;
cin>>n>>u>>r>>d>>l;
int u1=u,r1=r,d1=d,l1=l;
if(u==n)//remember we check on u and not u1, as suppose for u=4,d=4,l=4,r=4.At the end of the result u1,d1,l1,r1 should be 2 as these are the only number of non common cells
        //but if we decrease on same variables i.e. l,r for u then it becomes 3 3 and then we decrease l,r by1 but actually it should decrease by 2 as it is independent
        of the decrease caused on u.
{
    l1--;
    r1--;
}
if(d==n)
{
    l1--;
    r1--;
}
if(r==n)
{
    u1--;
    d1--;
}
if(l==n)
{
    u1--;
    d1--;
}
if(u==n-1)
{
    if(l1>r1)
    l1--;
    else
    r1--;
}
if(d==n-1)
{
    if(l1>r1)
    l1--;
    else
    r1--;
}
if(l==n-1)
{
    if(u1>d1)
    u1--;
    else
    d1--;
}
if(r==n-1)
{
    if(u1>d1)
    u1--;
    else
    d1--;
}
if(l1<0||r1<0||u1<0||d1<0)
cout<<"NO"<<endl;
else
cout<<"YES"<<endl;
}
int32_t main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int t = 1;
	cin>>t;
	while(t--){
		tests();
	}
    return 0 ; 
}
