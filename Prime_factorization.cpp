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

vector<int>factors;
void factorize(int n){
    int sq=sqrt(n);
    for(int i=0; i<prime.size() && prime[i]<=sq; i++){
        if(n%prime[i] == 0){
            while (n%prime[i] == 0)
            {
                n/=prime[i];
                factors.push_back(prime[i]);
            }
            sq=sqrt(n);
        }
    }
    if(n>1) factors.push_back(n);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    primeGen(n);
    factorize(n);
    for(auto it:factors) cout<<it<<' ';
    return 0;
}