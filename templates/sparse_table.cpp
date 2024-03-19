#include <vector>

template <typename T, typename Op>
class sparse_table {
public:
    explicit sparse_table(std::vector<T> a = {}) : op(Op()) {
        if (!a.empty()) {
            reset(a);
        }
    }
    void reset(std::vector<T> &a) {
        int n = a.size();
        int sz = static_cast<int>(log2(n)) + 1;
        st.assign(n, std::vector<T>(sz));
        for (int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
        for (int j = 1; 1 << j <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = op(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
            }
        }
    }
    // 0 <= l < r <= n
    int query(int l, int r) {
        int k = static_cast<int>(log2(r - l));
        return op(st[l][k], st[r - (1 << k)][k]);
    }
private:
    Op op;
    std::vector<std::vector<T>> st;
};
template <typename T>
struct Op {
    T operator()(const T &lhs, const T &rhs) const {
        return std::max(lhs, rhs);
    }
};
sparse_table<int, Op<int>> st;