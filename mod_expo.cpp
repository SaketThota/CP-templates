ll power(ll x, ll y, ll p = MOD) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
