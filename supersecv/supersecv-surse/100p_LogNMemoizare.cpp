#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef long long lint;
ifstream fin("supersecv.in");
ofstream fout("supersecv.out");
const lint mod = 999983, maxn = 1000005;
lint v[1000005];
lint fact[maxn], imf[maxn], sp[maxn];

typedef pair<lint, lint> pr;
pr ee(lint a, lint b)
{
    if (b == 0) {
        return { 1, 0 };
    }
    pr r = ee(b, a % b);
    return { r.second, r.first - (a / b) * r.second };
}

lint im(int a)
{
    lint r = ee(a, mod).first;
    if (r < 0) {
        r = mod + (r % mod);
    }
    return r;
}


lint comb(lint n, lint k) {
    if (imf[k] == 0) imf[k] = im(fact[k]);
    if (imf[n - k] == 0) imf[n - k] = im(fact[n - k]);
    return (((fact[n] * imf[k]) % mod) * imf[n - k]) % mod;
}

lint query(lint a, lint b) {
    lint n, k, ans = 1;
    while (a > 0) {
        n = a % mod; k = b % mod;
        if (n < k) { return 0; }
        ans *= comb(n, k); ans %= mod;
        a /= mod; b /= mod;
    }
    return ans;
}


int main()
{
    lint n, k, x, i, j;
    fin >> n;

    lint limitafactorial = min(maxn - 2, n);
    for (i = 1, fact[0] = 1; i <= limitafactorial; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    for (i = 1; i <= n; i++) {
        fin >> v[i];
        sp[i] = sp[i - 1] + v[i];
    }
    fin >> k >> x;
    lint minim, maxim;
    fin >> minim;
    lint s = 0, st = 1, ans = 0;
    for (i = 1; i <= n; i++) {
        lint p = 1LL << 20, r = i;
        while (p > 0) {
            if (r + p <= n && sp[r + p] - sp[i - 1] <= x)
                r += p;
            p >>= 1;
        }
        if (sp[r] - sp[i - 1] == x) {
            lint dif = r - i + 1;
            if (dif >= k * minim) {
                ans += comb(dif - (k * (minim - 1)) - 1, k - 1);
                ans %= mod;
            }

        }
    }
    fout << ans;
    return 0;
}