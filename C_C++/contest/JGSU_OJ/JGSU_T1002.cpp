#pragma clang diagnostic push
#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"
#pragma ide diagnostic ignored "misc-no-recursion"
//
// Created by zxilly on 2022/2/26.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e5 + 5;
int init[maxN];

struct Edge {
    int left, right, val;
} tree[maxN * 4];

inline int ls(int k) { return k << 1; }

inline int rs(int k) { return k << 1 | 1; }

inline void push_up(int k) { tree[k].val = tree[ls(k)].val + tree[rs(k)].val; } // Cal sons value

void build(int l, int r, int k = 1) {
    tree[k].left = l, tree[k].right = r;
    if (l == r) {
        tree[k].val = init[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, ls(k));
    build(m + 1, r, rs(k));
    push_up(k);
}

void modify_single(int target_p_index, int mod_val, int p_index = 1) {
    int l = tree[p_index].left, r = tree[p_index].right;
    if (l == r) {
        //cout << l << "+=" << mod_val << endl;
        tree[p_index].val += mod_val;
        return;
    }
    int m = (l + r) >> 1;
    if (target_p_index <= m) modify_single(target_p_index, mod_val, ls(p_index));
    else modify_single(target_p_index, mod_val, rs(p_index));
    push_up(p_index); // current index
}

int query(int target_p_index, int k = 1) {
    auto node = tree[k];
    int l = node.left, r = node.right;
    if (l == r) return tree[k].val;
    int m = (l + r) >> 1;
    if (target_p_index <= m) return query(target_p_index, ls(k));
    else return query(target_p_index, rs(k));
}

int query_seg(int x, int y, int k = 1) {
    // cout << "querying " << x << ":" << y << " at:" << k << endl;
    int l = tree[k].left, r = tree[k].right;
    if (x <= l && y >= r) return tree[k].val; // is sub seg
    int m = (l + r) >> 1;
    int sum = 0;
    if (x <= m) sum += query_seg(x, y, ls(k));
    if (y > m) sum += query_seg(x, y, rs(k));
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> init[i];
    }
    build(1, n);
    while (m--) {
        int op;
        cin >> op;
        switch (op) {
            case 1: {
                int p;
                cin >> p;
                cout << query(p) << endl;
                break;
            }
            case 2: {
                int p, z;
                cin >> p >> z;
                modify_single(p, z);
                break;
            }
            case 3: {
                int l, r;
                cin >> l >> r;
                cout << query_seg(l, r) << endl;
                break;
            }
        }
    }
    return 0;
}
