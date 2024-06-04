#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf             1e18
const ll N = 5e5 + 5;
const ll mod = 998244353;
struct dsu
{
  ll connected;
  vector<ll> par, sz;
  //DSU() {}
  void init(ll n)
  {
    par = sz = vector<ll> (n + 1, 0);
    for (ll i = 1; i <= n; i++)
      par[i] = i, sz[i] = 1;
    connected = n;
  }

  ll getpar(ll u)
  {
    while (u != par[u])
    {
      par[u] = par[par[u]];
      u = par[u];
    }
    return u;
  }

  ll getsize(ll u)
  {
    return sz[getpar(u)];
  }

  ll unite(ll u, ll v)
  {
    ll par1 = getpar(u), par2 = getpar(v);

    if (par1 == par2)
      return 0;

    connected--;

    if (sz[par1] > sz[par2])
      swap(par1, par2);

    sz[par2] += sz[par1];
    sz[par1] = 0;
    par[par1] = par[par2];
    return 1;
  }
};

ll binpow(ll a, ll b, ll md) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    ans %= md;
    a %= md;
    b /= 2;
  }
  return ans;
}

void sol()
{
  ll n, s;
  cin >> n >> s;
  vector<pair<ll, pair<ll, ll>>> v;
  dsu d;
  d.init(n);
  for (ll i = 0; i < n - 1; i++) {
    ll x, y, w;
    cin >> x >> y >> w;
    v.push_back({w, {x, y}});
  }
  sort(v.begin(), v.end());
  ll ct = 1;
  for (ll i = 0; i < (n - 1); i++) {
    ll w = v[i].first;
    ll x = v[i].second.first;
    ll y = v[i].second.second;
    ll t1 = d.getsize(x);
    ll t2 = d.getsize(y);

    ll e = binpow(1 + s - w, (t1 - 1) + t1 * (t2 - 1), mod);
    ct *= e;
    ct %= mod;
    //trc(e,ct);
    ll l = d.unite(x, y);




  }
  cout << ct << endl;

}

int32_t main()
{
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll tc1 = 1;
  cin >> tc1;
  while (tc1--)
  {
    sol();
  }
  return 0;
}
