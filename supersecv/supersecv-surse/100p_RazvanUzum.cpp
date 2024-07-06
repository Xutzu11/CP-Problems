#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef long long lint;
ifstream fin("supersecv.in");
ofstream fout("supersecv.out");
const lint mod = 999983, maxn = 1000005;
lint v[1000005];
lint fact[maxn], imf[maxn], ctr;

lint pw(lint a, lint b) {
    if (b == 1) { return a; }
    if (b == 0) { return 1; }
    lint ans = pw(a, b / 2);
    if (b % 2 == 1) {
        return (((ans * ans) % mod) * a) % mod;
    }
    else {
        return (ans * ans) % mod;
    }
}
lint im(lint x) {
    return pw(x, mod - 2);
}

lint comb(lint n, lint k) {
    return (((fact[n] * imf[k]) % mod) * imf[n - k]) % mod;
}

int main() {
    lint n, k, x, i;
    fin >> n;

    imf[0] = im(1);
    for (i = 1, fact[0] = 1; i <= maxn - 2; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
        imf[i] = im(fact[i]);
    }
    for (i = 1; i <= n; i++) {
        fin >> v[i];
    }
    fin >> k >> x;
    lint minim, maxim;
    fin >> minim;
    lint s = 0, st = 1, ans = 0;
    for (i = 1; i <= n; i++) {
        s += v[i];
        while (st < i && s > x) {
            s -= v[st++];
        }
        if (s == x) {
            lint dif = i - st + 1;
            if (dif >= k * minim) {
                ans = (ans+comb(dif - (k * (minim - 1)) - 1, k - 1))%mod;
            }
        }
    }
    fout << ans;
    return 0;
}