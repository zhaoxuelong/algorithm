#include <vector>

template <typename T>
std::vector<T> discretization(std::vector<T> &a) {
    auto sorted = a;
    std::ranges::sort(sorted);
    sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
    return sorted;
}
template <typename T>
int index(std::vector<T> &sorted, T v) {
    return std::ranges::lower_bound(sorted, v) - sorted.begin();
}
template <typename T>
class fenwick_tree {
public:
    explicit fenwick_tree(int n = -1) {
        if (n > 0) {
            reset(n);
        }
    }
    void reset(int n) {
        data.assign(n, T());
    }
    void add(int x, T v) {
        while (x < data.size()) {
            data[x] += v;
            x |= x + 1;
        }
    }
    T sum(int x) {
        T ans{};
        while (x >= 0) {
            ans += data[x];
            x = (x & (x + 1)) - 1;
        }
        return ans;
    }
private:
    std::vector<T> data;
};
struct Node {

    Node operator+=(Node other) const {
        Node c;
        return c;
    }
};