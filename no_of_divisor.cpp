#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
const int N=1e7+10;
int is_prime[N];
vector<int>prime;

void primeGen ( int n ) // give sqroot of given n while computing prime facto of n;
{
    n += 10;
    for ( int i = 3; i <= n; i += 2 ) is_prime[i] = 1;
 
    int sq = sqrt ( n );
    for ( int i = 3; i <= sq; i += 2 ) {
        if ( is_prime[i] == 1 ) {
            for ( int j = i*i; j <= n; j += ( i + i ) ) {
                is_prime[j] = 0;
            }
        }
    }
 
    is_prime[2] = 1;
    prime.push_back (2);
 
    for ( int i = 3; i <= n; i += 2 ) {
        if ( is_prime[i] == 1 ) prime.push_back ( i );
    }
}

int Divisor(int n){
    int sq=sqrt(n),res=0;

    for(int i=1; i<sq; i++){
        if(n%i == 0) res+=2;
    }

    if(n%sq == 0){
        if(sq * sq  == n ) res++;
        else res+=2;
    }
    
    return res;
}
//using prime factorization
int DivisorByFactorize(int n){
    int sq=sqrt(n);
    int res=1;
    for(int i=0; i<prime.size() && prime[i]<=sq; i++){
        int ct=0;
        if(n%prime[i] == 0){
            while (n%prime[i] == 0)
            {
                ct++;
                n/=prime[i];
            }
            sq=sqrt(n);
            ct++;
            res*=ct;
        }
    }
    if(n>1) res*=2;
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    primeGen(1000000);
    cout<<Divisor(24)<<endl;
    cout<<DivisorByFactorize(24)<<endl;
    return 0;
}