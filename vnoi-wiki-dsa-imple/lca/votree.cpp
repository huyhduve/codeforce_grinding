//  ^------^
// ( '(oo)' )
// (  u  u  )

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

#define ff first
#define sc second
#define all(x) (x).begin(), (x).end()
mt19937 rgn (chrono::steady_clock::now().time_since_epoch().count());

#define IN "A.IN"
#define OUT "A.OUT"
#define cerr if(0) cerr

const int MOD = 1e9 + 7;
const int MAXN = 7e4 + 5, LG = 20;
int depth[MAXN], up[MAXN][LG + 3];

vector<int> adj[MAXN];

void dfs(int u, int prev){
    depth[u] = depth[prev] + 1;
    up[u][0] = (u == 0 ? -1 : prev);

    for(int k = 1; k <= LG; k++){
        int next = up[u][k - 1];

        if(next != -1){
            up[u][k] = up[next][k - 1];
        }
    }
    for(int &v : adj[u]) if(v != prev){
        dfs(v, u);
    }
}

int find_lca(int u, int v){
    if(depth[u] != depth[v]){
        if(depth[u] > depth[v]) swap(u, v);
        int dif = depth[v] - depth[u];
        for(int k = 0; k <= LG; k++){
            if(dif & (1 << k)) v = up[v][k];
        }
    }

    if(u == v) return u;

    for(int k = LG; k >= 0; k--){
        int nextu = up[u][k], nextv = up[v][k];
        if(nextu != nextv){
            u = nextu;
            v = nextv;
        }
    }

    return up[u][0];
}

template<typename T>
struct SEGTREE{
    vector<T> tree;
    int n;
    T merge_val;
    function<T(T, T)> merge_;

    SEGTREE(int _n, T e_, function<T(T,T)> f_m){
        n = _n;
        merge_val = e_;
        merge_ = f_m;
        tree.assign(4*n, e_);
    }

    void build(int id, int l, int r, vector<T> &a){
        if(l == r){
            tree[id] = a[l];
            return;
        }
        int m = (l + r)/2;
        build(id*2 + 1, l, m, a);
        build(id*2 + 2, m + 1, r, a);
        tree[id] = merge_(tree[id*2 + 1], tree[id*2 + 2]);
    }
    void build(vector<T> &a){
        build(0, 0, n - 1, a);
    }

    void update(int id, int l, int r, int pos, T val){
        if(l == r){
            tree[id] = val;
            return;
        }
        int m = (l + r)/2;
        if(pos <= m) update(id*2 + 1, l, m, pos, val);
        else update(id*2 + 2, m + 1, r, pos, val);

        tree[id] = merge_(tree[id*2 + 1], tree[id*2 + 2]);
    }

    void update(int pos, T val){
        update(0, 0, n - 1, pos, val);
    }

    T get(int id, int l, int r, int lb, int rb){
        if(r < lb || rb < l) return merge_val;
        if(lb <= l && r <= rb){
            return tree[id];
        }


        int m = (l + r)/2;
        T c1 = get(id*2 + 1, l, m, lb, rb);
        T c2 = get(id*2 + 2, m + 1, r, lb, rb);

        if(c1 == merge_val) return c2;
        if(c2 == merge_val) return c1;
        return merge_(c1, c2);
    }

    T get(int l, int r){
        return get(0, 0, n - 1, l, r);
    }

};

int merge_(int u, int v){
    return find_lca(u, v);
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u --;
        v --;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[0] = -1;
    dfs(0, 0);

    vector<int> node(n);
    for(int i = 0; i < n; i++) node[i] = i;

    SEGTREE<int> lca(n, -1, merge_);
    lca.build(node);

    while(q--){
        int u, v; cin >> u >> v;
        u--;
        v--;
        cout << lca.get(u, v) + 1 << "\n";
    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    if(fopen(IN, "r")){
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen("CERR.txt", "w", stderr);
    }

    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j <= LG; j++){
            up[i][j] = -1;
        }
    }

    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
