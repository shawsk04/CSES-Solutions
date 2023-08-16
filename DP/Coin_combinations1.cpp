#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vst;
typedef vector<bool> vbl;
typedef set<int> sti;
typedef map<int, int> mii;

#define nl "\n"
#define Pe cout<<nl
#define Psp cout<<" "
#define pyes cout<<"YES"<<nl
#define pno cout<<"NO"<<nl
#define lcm(a,b) (a*b)/(__gcd(a,b))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define rev(x) reverse(x.begin(), x.end())
#define mni(x) (min_element(x.begin(), x.end()) - x.begin())
#define mxi(x) (max_element(x.begin(), x.end()) - x.begin())
#define mne(x) *min_element(x.begin(), x.end())
#define mxe(x) *max_element(x.begin(), x.end())
#define acc(x) accumulate(x.begin(), x.end(), 0ll)
#define lb(x, val) (lower_bound(x.begin(), x.end(), val) - x.begin())
#define ub(x, val) (upper_bound(x.begin(), x.end(), val) - x.begin())

#define mod 1000000007LL
#define modd 998244353LL
#define inf 1e18
#define pi 3.141592653589793238462
//-------------------------------------------------------------------------------------------------------------------//
template<typename typC, typename typD> istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template<typename typC> istream &operator>>(istream &cin, vector<typC> &a) { for (auto &x : a) cin >> x; return cin; }
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a) { for (auto &x : a) cout << x << '\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout, const vector<typC> &a) { int n = a.size(); if (!n) return cout; cout << a[0]; for (int i = 1; i < n; i++) cout << ' ' << a[i]; return cout; }
//------------------------------------------------------------------------------------------------------------------//
#ifdef SHAWSK
#define dbg(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif

// void _print(int x) {cerr << x;}
void _print(long x) {cerr << x;}
void _print(long long x) {cerr << x;}
void _print(unsigned x) {cerr << x;}
void _print(unsigned long x) {cerr << x;}
void _print(unsigned long long x) {cerr << x;}
void _print(float x) {cerr << x;}
void _print(double x) {cerr << x;}
void _print(long double x) {cerr << x;}
void _print(char x) {cerr << '\'' << x << '\'';}
void _print(const char *x) {cerr << '\"' << x << '\"';}
void _print(const string &x) {cerr << '\"' << x << '\"';}
void _print(bool x) {cerr << (x ? "true" : "false");}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//------------------------------------------------------------------------------------------------------------------//
int modSum(int a, int b, int m) { return ((a % m) + (b % m)) % m; }
int modDiff(int a, int b, int m) { return ((a % m) - (b % m) + m) % m; }
int modProd(int a, int b, int m) { return ((a % m) * (b % m)) % m; }
int modpw(int a, int b, int m) { if (b == 0) return 1 % m; if (b % 2 == 0) { int temp = modpw(a, b / 2, m); return modProd(temp, temp, m); } else { int temp = modpw(a, (b - 1) / 2, m); return modProd(a, modProd(temp, temp, m), m); }}
int modInv(int b, int m) { return modpw(b, m - 2, m); }
int modDiv(int a, int b, int m) { return ((a % m) * (modInv(b, m) % m)) % m; }
//------------------------------------------------------------------------------------------------------------------//
bool isSquare(int n) {return floor(sqrtl(n)) == ceil(sqrtl(n));}
bool isPower(int x, int y) {float t = log(x) / log(y);    return ceil(t) == floor(t);}
bool checkPrime(int x) { for (int i = 2; i * i <= x; i++) { if (x % i == 0) return false; } return true; }
int noDivisors(int n) { int cnt = 0; for (int i = 1; i * i <= n; i++) { if (n % i == 0) { cnt += 2;  if (i * i == n) cnt -= 1; } } return cnt; }
int pw(int a, int b) { if (b == 0)  return 1; if (b % 2 == 0) { int temp = pw(a, b / 2); return temp * temp; } else { int temp = pw(a, (b - 1) / 2); return a * temp * temp; }}
void pyn(bool x) { if (x) pyes; else pno; }
bool sortByVal2(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }

//Prime factorisation (sqrt(n))
map<int, int> factors;
void primeFactors(int n) {
	while (n % 2 == 0) { factors[2]++; n = n / 2; }
	for (int i = 3; i <= sqrt(n); i = i + 2) { while (n % i == 0) { factors[i]++; n = n / i; } }
	if (n > 2)  factors[n]++;
}
//-----------------------------------------------------------------------------------------------------------------//


void solve() {
	int n; cin >> n;
	int x; cin >> x;
	vi a(n); cin >> a;
	// vi dp(x + 1);
	int dp[x + 1] = {0};
	dp[0] = 1;
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= a[j]) dp[i] = (dp[i] + dp[i - a[j]]) % mod;
		}
	}
	dbg(dp);
	cout << dp[x] << nl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef SHAWSK
	freopen("../Input.txt", "r", stdin);
	freopen("../Output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);
#endif

	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}