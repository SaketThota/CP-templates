ll fact[MAX_N + 1], invfact[MAX_N + 1];

ll pow(ll a, ll b, ll m) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

ll modinv(ll k) { return pow(k, MOD - 2, MOD); }

void precompute() {
    fact[0] = fact[1] = 1;

    for (ll i = 2; i < MAX_N; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }

    invfact[MAX_N - 1] = modinv(fact[MAX_N - 1]);

    for (ll i = MAX_N - 2; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= MOD;
    }
}

ll nCr(ll x, ll y) {
    if (y > x) return 0;

    ll num = fact[x];
    num *= invfact[y];
    num %= MOD;
    num *= invfact[x - y];
    num %= MOD;

    return num;
}
