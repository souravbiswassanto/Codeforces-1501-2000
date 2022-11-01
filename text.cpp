#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define pb push_back

vector<ll>prime;
const int N = 1e7, mx1 = N + 1;
bool mark[mx1];
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}


int main(){
	
    seive();
    ll mul = 1;
    for (int i = 0; i < 21; i ++) {
    	mul *= prime[i] * 1LL;
    	cout << mul << endl;
    }
}