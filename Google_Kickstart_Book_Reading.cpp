#include<bits/stdc++.h>
// Important header files
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;

#define ff first
#define ss second
#define ll long long
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(v,n) for(ll i=0; i<n; i++) cin>>v[i]
#define output(v,n) for(ll i=0; i<n; i++) cout<<v[i]<<" "
#define MOD 1000000007
#define deb(x) cout<<#x <<" "<<x<<endl;

ll* ans = NULL;
void countSieve(ll arr[], ll n)
{
    ll MAX = *max_element(arr, arr + n);
    ll cnt[200000];
    ans = new ll[200000];
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, (200000) * sizeof(ll));
    for (ll i = 0; i < n; ++i)
        ++cnt[arr[i]];
    for (ll i = 1; i <= MAX; ++i)
        for (ll j = i; j <= MAX; j += i)
            ans[i] += cnt[j];
    return;
}

ll countMultiples(ll k) {
    return ans[k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for(ll i=0; i<t; i++){
        ll n, m , q;
        cin >> n >> m >> q;
        vector<ll> arr(q);
        ll torn[m];
        for(ll i=0; i<m; i++){
            cin >> torn[i];
        }
        for(ll i=0; i<q; i++){
            cin>> arr[i];
        }
        countSieve(torn, m);
        ll ans1=0;
        for(ll i=0; i<q; i++){
            ans1+=(n/arr[i]);

            ans1=ans1-countMultiples(arr[i]);
        }
        cout<<"Case #"<<i+1<<": "<<ans1<<endl;
    }
    return 0;
}
