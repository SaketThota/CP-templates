vi adj[MAX_N], vis(MAX_N), in(MAX_N), pos_low(MAX_N);
map<int, int> bridges;
int timer, cnt;

void dfs(int node, int par) {
    vis[node] = 1;
    in[node] = pos_low[node] = timer++;

    for (auto child : adj[node]) {
        if (child == par) continue;

        if (vis[child]) {
            pos_low[node] = min(pos_low[node], in[child]);
        } else {
            dfs(child, node);

            if (in[node] < pos_low[child]) cnt++;

            pos_low[node] = min(pos_low[node], pos_low[child]);
        }
    }
}
