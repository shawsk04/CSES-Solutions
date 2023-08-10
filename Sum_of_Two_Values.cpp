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
#define Pe cout<<nl
#define Psp cout<<" "
#define P cout<<
#define S cin>>
#define pyes cout<<"YES"<<nl
#define pno cout<<"NO"<<nl
#define lcm(a,b) (a*b)/(__gcd(a,b))
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define pb push_back
#define ppb pob_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define vrange(x, l, r) x.begin()+l, x.begin()+r
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define rev(x) reverse(x.begin(), x.end())
#define mnv(x) *min_element(x.begin(), x.end())
#define mxv(x) *max_element(x.begin(), x.end())
#define ACC(x) accumulate(x.begin(), x.end(), 0ll)

#define MOD1 1000000007LL
#define MOD2 998244353LL
#define pi 2 * acos(0.0)

//-------------------------------------------------------------------------------------------------------------------//
#ifndef ONLINE_JUDGE
#define dbg(x) cout << #x <<" "; _print(x); cout << endl;
#else
#define dbg(x)
#endif

// void _print(int x) {cout << x;}
void _print(long x) {cout << x;}
void _print(long long x) {cout << x;}
void _print(unsigned x) {cout << x;}
void _print(unsigned long x) {cout << x;}
void _print(unsigned long long x) {cout << x;}
void _print(float x) {cout << x;}
void _print(double x) {cout << x;}
void _print(long double x) {cout << x;}
void _print(char x) {cout << '\'' << x << '\'';}
void _print(const char *x) {cout << '\"' << x << '\"';}
void _print(const string &x) {cout << '\"' << x << '\"';}
void _print(bool x) {cout << (x ? "true" : "false");}

template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

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

bool sortByVal2(const pair<int, int> &a, const pair<int, int> &b){ return (a.second < b.second); } 

bool isSquare(int n) {return floor(sqrt(n)) == ceil(sqrt(n));}
bool isPower(int x, int y) {float t = log(x)/log(y);    return ceil(t)==floor(t);}

int pw(int a, int b){
    if(b == 0)  return 1;
    if(b % 2 == 0){
        int temp = pw(a, b/2);
        return temp * temp;
    }
    else{
        int temp = pw(a, (b-1)/2);
        return a * temp * temp;
    }
}

bool checkPrime(int x){
  for (int i = 2; i * i <= x; i++) {
      if (x % i == 0)
          return false;
  }
  return true;
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

//Prime factorisation (sqrt(n))
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

void solve(){
    int n, x;      cin>>n>>x;
    vpii a;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin>> y;
        a.pb({y, i});
    }
    // string s;    cin>>s;
    srt(a);
    int i =0;
    int j=n-1;
    bool ok=0;
    int l, r;
    dbg(a);
    while(i<j){
        if(a[i].ff + a[j].ff == x)    {ok=1; l=a[i].ss; r=a[j].ss; break;}

        else if(a[i].ff + a[j].ff > x)    j--;
        else i++;
    }
    if(ok)  cout<< l+1 << " " << r+1 << nl;
    else  cout<<"IMPOSSIBLE"<< nl;
    
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}