#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
//
// Created by zxilly on 2022/2/26.
//

const int maxN = 1e5 + 5;
int init[maxN];

struct Node {
    int left, r, val;
} t[maxN * 4];

inline int ls(int k) { return k << 1; }

inline int rs(int k) { return k << 1 | 1; }

inline void pushUp(int k) { t[k].val = t[ls(k)].val + t[rs(k)].val; }

void build(int l, int r, int k = 1) {
    t[k].left = l, t[k].r = r;
    if (l == r) {
        t[k].val = init[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, ls(k));
    build(m + 1, r, rs(k));
    pushUp(k);
}

void modify_single(int p, int z, int k = 1) {
    int l = t[k].left, r = t[k].r;
    if (l == r) {
        t[k].val += z;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) modify_single(p, z, ls(k));
    else modify_single(p, z, rs(k));
    pushUp(k);
}

int query_p(int p, int k = 1) {
    auto node = t[k];
    int l = node.left, r = node.r;
    if (l == r) return t[k].val;
    int m = (l + r) >> 1;
    if (p <= m) return query_p(p, ls(k));
    else return query_p(p, rs(k));
}

int query(int x, int y, int k = 1) {
    int l = t[k].left, r = t[k].r;
    if (x <= l && y >= r) return t[k].val;
    int m = (l + r) >> 1;
    int sum = 0;
    if (x <= m) sum += query(x, y, ls(k));
    if (y > m) sum += query(x, y, rs(k));
    return sum;
}
