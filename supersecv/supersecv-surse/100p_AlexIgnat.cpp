#include <iostream>
#include <fstream>
#include <vector>
#define ll long long 
#define mod 999983
using namespace std;

ifstream f("supersecv.in");
ofstream g("supersecv.out");
ll v[1000005];
ll fact[1000005], inv_fact[1000005], ctr;

ll n, k, x, z, y;

void euclid_extins(ll a, ll b) {
    if (b != 0) {
        euclid_extins(b, a % b);
    }
    if (b == 0) {
        x = 1;
        y = 0;
    }
    else {
        ll aux = y;
        y = x - (a / b) * y;
        x = aux;
    }
}

ll inv_mod(ll nr) {
    x = y = 0;
    euclid_extins(nr, mod);
    if (x < 1) {
        x += -((x / mod) - 1) * mod;
    }
    return x;
}

ll comb(ll n, ll k) {
    return (((fact[n] * inv_fact[k]) % mod) * inv_fact[n - k]) % mod;
}


int main() {
    f >> n;
    fact[0] = 1;
    inv_fact[0] = inv_mod(1);
    for (ll i = 1; i <= 1000000; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv_fact[i] = inv_mod(fact[i]);
    }
    for (int i = 1; i <= n; i++) {
        f >> v[i];
    }
    f >> k >> x >> z;
    ll s = 0, st = 1, ans = 0, dr = 0;
    while (dr < n) {
        s += v[++dr];
        while (st <= dr && s > x) {
            s -= v[st++];
        }
        if (s == x) {
            ll lung = dr - st + 1;
            if (lung >= k * z) {
                ans = (ans + comb(lung - (k * (z - 1)) - 1, k - 1)) % mod;
            }
        }
    }
    g << ans;
    return 0;
}