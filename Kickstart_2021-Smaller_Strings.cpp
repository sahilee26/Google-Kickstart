#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
using namespace std;
 
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
 
#define ld long double
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(v,n) for(ll i=0; i<n; i++) cin>>v[i]
#define output(v,n) for(ll i=0; i<n; i++) cout<<v[i]<<" "
#define ll long long
#define ff first
#define se second
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
 typedef tree<ll, null_type, less<ll>, rb_tree_tag,
              tree_order_statistics_node_update>
     new_data_set;
 
// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
 
// Driver function to sort the vector elements by
// first element of pair in descending order
bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}
 
// Driver function to sort the vector elements by
// second element of pair in descending order
bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second>b.second;
}
 
 
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
 
}

ll exp(ll x, ll p){
  if(p==0)
    return 1;
  else if(p%2==0)
    return exp(x, p/2)*exp(x, p/2);
  else
    return x*exp(x, p/2)*exp(x, p/2);
}

/* Iterative Function to calculate (x^y)%p in O(log y) */
ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
    // equal to p
    while (y > 0){
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

//algorithm to get updated array after array range
// add operation in constant time
// void add(ll arr[], ll N, ll lo, ll hi, ll val)
// {
//     arr[lo] += val;
//     if (hi != N - 1)
//       arr[hi + 1] -= val;
// }
 
// //  Utility method to get actual array from operation array
// void updateArray(ll arr[], ll N)
// {
//     //  convert array into prefix sum array
//     for (ll i = 1; i < N; i++)
//         arr[i] += arr[i - 1];
// }
 
// //  method to print final updated array
// void finalArr(ll arr[], ll N)
// {
//     updateArray(arr, N);
// }

// ll tree1[1000000], arr[1000000], level[1000000];

// void update(ll node, ll start, ll end, ll idx, ll val){
//     if(start==end){
//         // updating array[idx]
//         arr[idx]=val;
//         // updating leaf node representing idx
//         tree1[node]=val;
//     }
//     else{
//         ll mid=(end+start)/2;
//         if(start<=idx && idx<=mid)
//             update(2*node, start, mid, idx, val);
//         else if(mid+1<=idx && idx<=end)
//             update(2*node+1, mid+1, end, idx, val);

//         if(level[node]%2==0)
//             tree1[node]=tree1[2*node]|tree1[2*node+1];
//         else
//             tree1[node]=tree1[2*node]^tree1[2*node+1];
//     }
// }

// ll query(ll node, ll start, ll end, ll l, ll r){
//     // if (l,r) completely outside of (start, end)
//     if(r<start || l>end )
//         return 0;
//      // if (start, end) completely inside of (l,r)
//     else if(l<=start && r>=end)
//         return tree1[node];
//     else{
//         ll mid =(start+end)/2;

//         ll x=query(2*node, start, mid, l, r);
//         ll y=query(2*node, mid+1, start, l, r);
//         return x+y;
//     }
// }

// void build(ll start, ll end, ll node){

//     if(start==end){
//         tree1[node]=arr[start];
//         level[node]=1;
//     }
//     else{
//         ll mid = (start+end)/2;
        
//         build(start, mid, 2*node);
//         build(mid+1, end, 2*node+1);
//         level[node] = level[2*node]+1;
        
//         if(level[node]%2==0)
//             tree1[node]=tree1[2*node]|tree1[2*node+1];
//         else
//             tree1[node]=tree1[2*node]^tree1[2*node+1];
//     }
// }

#define MAXN 1000005

ll spf[MAXN];
void sieve() { 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every  number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even number as 2 
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<MAXN; i++) { 
        // checking if i is prime 
        if (spf[i] == i) { 
            // marking SPF for all numbers divisible by i 
            for (ll j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

// Common mistakes
// always check whether container is empty before accessing its elements and size
// always put ((ans)%n+n)%n to avoid negative output
// always check if values are not overflowing (use long long where required)
// always check minor mistake endl at end of every statement 
// for binary search also check if array/vector size is not equal to one
// always read problem twice carefully beacuse wrong assumption can lead to double(30) time devoted to same problem

struct Edge{
    ll u, v, wght;
    bool operator<(Edge const& other) {
        return wght<other.wght;
    }
};

vector<ll> rnk, par;

ll find(ll i)  {  
    // find root and make root as parent of i(path compression)  
    if(par[i]!=i)
        par[i]=find(par[i]);
    return par[i];
}  

// A function that does union of two sets of x and y  (uses union by rank)  
void Union(ll x, ll y)  {  
   
    // Attach smaller rank tree under root of high rank tree (Union by Rank)  
    ll xroot=find(x);
    ll yroot=find(y);
    if(rnk[xroot]> rnk[yroot])
        par[yroot]=xroot;
    else if(rnk[yroot]> rnk[xroot])
        par[xroot]=yroot;

    // If ranks are same, then make one as root and increment its rank by one  
    else{
        rnk[yroot]++;
        par[xroot]=yroot;
    }
}  
 
# define ALPHABET_SIZE 26
# define CHAR_TO_INDEX(c) (int(c)- int('a')) 
  
struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    
    bool isWordend;
};

ll MOD=1e9+7;

// Algorithm for calculating factors od numbers upto n in O(n*logn)

  
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    for (ll m=1; m<=t; m++){
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string s1=s;
        ll res=0;
        ll mid=(n+1)/2;
        for(ll i=0; i<mid; i++){
            ll pos=min((ll)s[i]-'a', k);
            ll temp=(pos*power(k, mid-i-1, MOD))%MOD;
            res=(res+temp)%MOD;
            s1[n-i-1]=s1[i];
        }
        if(s1<s){
            res++;
        }
        cout<<"Case #"<<m<<": "<<res%MOD<<endl;
    }
    return 0;   
}
