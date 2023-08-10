#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<bool> vbool;
typedef set<int> sti;
typedef map<int, int> mii;

#define nl "\n"
#define Pyes cout<<"YES"<<nl
#define Pno cout<<"NO"<<nl
#define lcm(a,b) (a*b)/(__gcd(a,b))
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define rev(x) reverse(x.begin(), x.end())
#define mnv(x) *min_element(x.begin(), x.end())
#define mxv(x) *max_element(x.begin(), x.end())
#define ACC(x) accumulate(x.begin(), x.end(), 0ll)

#define MOD 1000000007*1LL
#define pi 2 * acos(0.0)

//------------------------------------------------------------------------------------------------------------------//
int modSum(int a, int b, int m){ return ((a % m) + (b % m)) % m; }
int modDiff(int a, int b, int m){ return ((a % m) - (b % m) + m) % m; }
int modProd(int a, int b, int m){ return ((a % m) * (b % m)) % m; }
int modpw(int a, int b, int m){
    if(b == 0)  return 1 % m;
    if(b % 2 == 0){
        int temp = modpw(a, b/2, m);
        return modProd(temp, temp, m);
    }
    else{
        int temp = modpw(a, (b-1)/2, m);
        return modProd(a, modProd(temp, temp, m), m);
    }
}
int modInv(int b, int m){ return modpw(b, m-2, m); }
int modDiv(int a, int b, int m){ return ((a % m) * (modInv(b, m) % m)) % m; }
//------------------------------------------------------------------------------------------------------------------//

bool checkPrime(int x){
  for (int i = 2; i * i <= x; i++) {
      if (x % i == 0)
          return false;
  }
  return true;
}

bool isSquare(int n){
    return floor(sqrt(n)) == ceil(sqrt(n));
}

int NODiv(int n){
    int cnt = 0;
    for(int i = 1; i * i <= n; i++)
    {
        if(n%i == 0){
            cnt += 2;
            if(i*i == n)    cnt-=1;
        }        
    }
    return cnt;
}

//----------------------------------------------Prime Factors---------------------------------------------//

map<int,int> factors;
void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        factors[2]++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            factors[i]++;
            n = n/i;
        }
    }
    if (n > 2)  factors[n]++;
}

//-----------------------------------------------------Sieve-------------------------------------------------------//
// #define NS 100000000
// vector<bool> is_prime(NS+1, true);
// vi prime;
// void sieve(){    

//     is_prime[0] = is_prime[1] = false;
//     for (int i = 2; i * i <= NS; i++){
//         if (is_prime[i]){
//             for (int j = i * i; j <= NS; j += i)    is_prime[j] = false;
//         }
//     }

//     for (int i = 0; i <= NS; i++)
//     {
//         if(is_prime[i])     prime.pb(i);
//     }
    
// }
//-----------------------------------------------------------------------------------------------------------------//

int tree[1001][1001];
int pre[1001][1001]={0};
void solve(){
    bool flag = 0;
    int n, q; 
    cin>>n>>q;
    // string s;
    // cin>>s;
    // vi a(n), b(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>a[i];
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char t;
            cin>>t;
            if(t=='.')  tree[i][j]=0;
            else tree[i][j]=1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + tree[i][j];
        }
        
    }

    while(q--){
        int x, y, X, Y;
        cin>>x>>y>>X>>Y;
        int ans = pre[X][Y] - pre[x-1][Y] - pre[X][y-1] + pre[x-1][y-1];
        cout<<ans<<nl;
    }
    
    
         
}


signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T=1;
    // cin>>T;
    while(T--){

        solve();

    }
    return 0;
}