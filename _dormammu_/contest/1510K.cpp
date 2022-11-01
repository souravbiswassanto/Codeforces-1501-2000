// Problem: K. King's Task
// Contest: Codeforces - 2020-2021 ICPC, NERC, Northern Eurasia Onsite (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1510/problem/K
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


/*########  IN THE NAME OF AintAH   ##########*/

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter" 
#include<bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#define ll long long
#define INF 999999999999999999
#define nl printf("\n")
#define  r0 return 0
#define  r1 return 1
#define sf1(x)  scanf("%d",&x)
#define sf2(x,y)  scanf("%d %d",&x,&y)
#define sf3(x,y,z)  scanf("%d %d %d",&x,&y,&z)
#define pf1(x)  printf("%d\n",x)
#define pf2(x,y)  printf("%d %d\n",x,y)
#define pf3(x,y,z)  printf("%d %d %d\n",x,y,z)
#define yes  printf("YES\n")
#define no  printf("NO\n")
#define pc(x,y)  printf("Case %d: %d\n",x,y)
#define pcn(x,y)  printf("Case %d:\n",x)
#define pb push_back
#define mp make_pair
#define pa pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define MIN  -99999999999999999
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pi 2.0*acos(0.0)
#define vs(v) (v.begin(),v.end())
int power(int B,int P){ if(P==0) return 1; int X=power(B,P/2); if(P%2==0) return X*X; else return B*X*X;}
int fx[]={1,-1,0,0}; int fy[]={0,0,1,-1};
vector<int> swap1(vector<int> V){
    for(int i = 0; i < V.size(); i+= 2){
        swap(V[i], V[i + 1]);
    }
    return V;
}
vector<int> swap2(vector<int> V){
    int n = V.size() / 2;
    for(int i = 0; i < n; i++){
        swap(V[i], V[i + n]);
    }
    return V;
}
int main()
{
   int T,N,E,u,Q,v,n,i,j,k,sum=0,ck=0,x,y,cs=0;
 
     string S,S1;
 
     double d1,d2,d3;
     vector<int>vc;
    cin>>N;
    for(i=0;i<2*N;i++)
    {
    	cin>>u;
    	vc.pb(u);
    }
    
   if(is_sorted(vc.begin(),vc.end()))
   {
   	cout<<"0"<<endl;
   	return 0;
   }
   
  vector<int>v1,v2,v3,v4;
  v1=vc;
  v2=vc;
   int ans1=300001;
   for(i=1;i<=30000;i++)
   {
   	   if(i%2)
   	   {
   	   	 v3=swap1(v1);
   	   }
   	   else
   	   {
   	   	v3=swap2(v1);
   	   }
   	   
   	   if(is_sorted(v3.begin(),v3.end()))
   	   {
   	   	  ans1=i;
   	   	  break;
   	   }
   	   
   	   v1=v3;
   	   
   }
   
   int ans2=300001;
   for(i=1;i<=30000;i++)
   {
   	   if(i%2)
   	   {
   	   	 v4=swap2(v2);
   	   }
   	   else
   	   {
   	   	v4=swap1(v2);
   	   }
   	   
   	   if(is_sorted(v4.begin(),v4.end()))
   	   {
   	   	  ans2=i;
   	   	  break;
   	   }
   	   v2=v4;
   	   
   }
   
   int res=min(ans1,ans2);
   if(res==300001)
   {
   	cout<<"-1"<<endl;
   }
   else cout<<res<<endl;
   
   
   

   
   /************ALEYA YOUSUF ************/
 
 
 /************AintAH IS ALMIGHTY ************/
return 0;
 
}