#include <vector>

class union_find {
public:
    explicit union_find(int n = -1) {
        if (n > 0) {
            reset(n);
        }
    }
    void reset(int n) {
        uf.assign(n, -1);
    }
    int find(int x) {
        return uf[x] < 0 ? x : uf[x] = find(uf[x]);
    }
    int unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (-uf[x] < -uf[y]) {
                std::swap(x, y);
            }
            uf[x] += uf[y];
            uf[y] = x;
        }
        return x;
    }
    int size(int x) {
        return -uf[x];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
private:
    std::vector<int> uf;
};
union_find uf;