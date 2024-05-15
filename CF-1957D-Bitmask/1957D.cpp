#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf             1e18
#define TRC
#ifdef TRC
#define trc(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {cout << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
#else
#define trc(...)
#endif
const int N = 5e5 + 5;
const int max_bit = 30;
int m[N][max_bit][2];
int rev_m[N][max_bit][2];
int a[N];
ll n;
ll count_ith_bit() {
  ll prev_count_zero = 0;
  ll prev_count_one = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < max_bit; j++) {
      ll prev_count_zero = 0;
      ll prev_count_one = 0;
      if (i > 0) {
        prev_count_zero = m[i - 1][j][0];
        prev_count_one = m[i - 1][j][1];
      }
      if (a[i] & (1ll << j)) {

        m[i][j][1] = 1;
        m[i][j][1] += prev_count_zero;
        m[i][j][0] += prev_count_one;


      }
      else {
        m[i][j][0] = 1;
        m[i][j][0] += prev_count_zero;
        m[i][j][1] += prev_count_one;

      }
    }
  }
}

ll rev_count_ith_bit() {

  for (ll i = n - 1; i >= 0; i--) {
    for (ll j = 0; j < max_bit; j++) {
      ll prev_count_zero = 0;
      ll prev_count_one = 0;
      if (i < (n - 1)) {
        prev_count_zero = rev_m[i + 1][j][0];
        prev_count_one = rev_m[i + 1][j][1];
      }
      if (a[i] & (1ll << j)) {


        rev_m[i][j][1] = 1;
        rev_m[i][j][1] += prev_count_zero;
        rev_m[i][j][0] += prev_count_one;


      }
      else {
        rev_m[i][j][0] = 1;
        rev_m[i][j][0] += prev_count_zero;
        rev_m[i][j][1] += prev_count_one;

      }
      
    }
  }
}


void sol()
{
  cin >> n;
  ll ct = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  //clear memory
  for (ll i = 0; i < n; i++) {
    for (ll j = 0 ; j < max_bit; j++) {
      for (ll k = 0; k < 2; k++) {
        m[i][j][k] = 0, rev_m[i][j][k] = 0;
      }
    }
  }


  count_ith_bit();
  rev_count_ith_bit();

  long long total = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = max_bit - 1 ; j >= 0; j--) {
      if (a[i] & (1LL << j)) {
        long long triplets = 0;
        ll p1 = 0, p0 = 0, q1 = 0 , q0 = 0;
        if (i) {
          p1 = m[i - 1][j][1];
          p0 = m[i - 1][j][0];
        }

        if (i < (n - 1)) {
          q1 = rev_m[i + 1][j][1];
          q0 = rev_m[i + 1][j][0];
        }
        triplets += (p1 * q0);
        triplets += (p0 * q1);
        triplets += p1;
        
        triplets += q1;
        total += triplets;
        break;
      }
    }
  }
  cout << total << endl;

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
