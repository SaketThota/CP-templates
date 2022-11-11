vll bit(MAX_N + 2);

void update(int idx, ll val) {
    while (idx <= MAX_N) {
        bit[idx] += val;
        idx += (idx & (-idx));
    }
}

ll pref(int idx) {
    ll ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}
