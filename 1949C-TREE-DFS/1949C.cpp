#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf             1e18
const ll N = 5e5 + 5;
#define pb push_back
#define trc(x){cout<<#x<<" : "<<x<<endl;}
#define trcc(x,y){cout<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;}
#define trccc(x,y,z){cout<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;}



ll n;
vector<ll> v[N];
ll b[N];
ll fg = 0, k = -1;
void g(ll x, ll pr) {
  vector<pair<ll, ll>>a;
  for (auto i : v[x]) {
    if (i == pr) continue;
    g(i, x);
    a.push_back({b[i], i});
  }
  sort(a.begin(), a.end());

  ll ct = 1;
  if (fg) return;
  for (auto it : a) {
    ll i = it.first;
    if (ct >= i) {
      ct += i;
    }
    else {
      fg = 1;

      k = it.second;
      return;
    }
  }
  b[x] = ct;

  return;

}
void sol()
{
  cin >> n;
  for (ll i = 0; i < n - 1; i++) {
    ll x, y; cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  g(1, 0);
  //trc(k);
  if (fg == 0) {
    cout << "YES" << endl; return;
  }
  fg = 0;
  g(k, 0);
  if (fg == 0) {
    cout << "YES" << endl; return;
  }
  fg = 0;
  g(k, 0);
  if (fg == 0) {
    cout << "YES" << endl; return;
  }
  cout << "NO" << endl;

}

int32_t main()
{
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll tc1 = 1;
  while (tc1--)
  {
    sol();
  }
  return 0;
}
