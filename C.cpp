/*
 ANIKET ASH
*/
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;
 
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pi 3.14159265358979323846
#define mod 1000000007
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mset(a , b) memset(a , b , sizeof(a))
#define mp make_pair
#define ff            first
#define ss            second
#define nline '\n'
#define all(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define  dbg(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif
typedef set <int> si;
typedef vector <int> vi;
typedef multiset <int> msi;
typedef vector <string> vs;
typedef pair <int , int> pii;
typedef vector <char> vch;
typedef vector <pair <int, int>> vpi;
// typedef tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
void _print(int t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(deque <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(deque <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
const int inf =1e18;
/*----------------------------- # --- MATH ALGORITHMS --- # -----------------------------*/
 int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
template <class T> T gcd(T a , T b){ while(a != 0){T temp = a; a = b % a; b = temp;}return b;}
template <class T> T egcd(T a , T b , T &x , T &y){T gcd , xt , yt;if(a == 0){gcd = b;x = 0 , y = 1;}else {gcd = egcd(b % a , a , xt , yt);x = yt - (b/a)*xt; y = xt;}return gcd;}
template <class T> T expo(T base , T exp ){T res = 1;base = base % mod;while (exp > 0){if (exp & 1)res = (res*base) % mod;exp = exp>>1;base = (base*base) % mod;}return res;}
template <class T> T modinv(T a ){T x , y; egcd<T>(a , mod , x , y);while(x < 0) x += mod; while(x >= mod) x -= mod; return x;}
template <class T> T modinvfermat(T a ){return expo<T>(a , mod - 2 , mod);}
template <class T> bool rev(T a , T b){return a > b;}
template <class T> int maxpower(T a , T b){int ans = 0;while(a >	 0 && a % b == 0){ans++;a /= b;}return ans;}
template <class T> T mceil(T a, T b){if(a % b == 0) return a/b; else return a/b + 1;}
template <class T> T lcm(T a, T b){return (a*b)/gcd<T>(a, b);}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do something instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	*try to check like n is even or odd or ith index even or odd
	* try to observe by using brute force for first few cases if not getting idea
*/
/*----------------------------- # --- MAIN CODE --- # -----------------------------*/
vi graph[500001];
vi vis;
vi height (14);
vi depth (14);
// unordered_set<int> how_much;
int cnt=0;
void dfs(int vertex,int par)
{
  //after entering the vertex
  // dbg(graph[vertex])
  for(int child : graph[vertex])
  {
    //before entering child
    if(child==par)continue;
    depth[child]=depth[vertex]+1;
    dfs(child,vertex);
    height[vertex]=max(height[child]+1,height[vertex]);
  }
  
}
void solve()
{
   int n,m;
   cin>>n>>m;
  //  vis .assign(n+1,0);
   rep(i,0,m)
   {
     
       int x ,y;
       cin>>x>>y;
       graph[x].pb(y);
       graph[y].pb(x);
   
}
dbg(graph[1]);
    dfs(1,0);
    rep(i,1,m+1)cout<<depth[i]<<" "<<height[i]<<nline;
    dbg(depth);
}
int32_t main()
{
    
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
ios
int test_case=1;
// cin>>test_case;
for(int _=1;_<=test_case;_++)
{
	// cout << "Case #" << _ << ": ";
  auto start1 = high_resolution_clock::now();
	solve();
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
  #ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}   

return 0;    
}