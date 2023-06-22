template <typename T>
class Fenwick_Tree {
public:
    // Constructor
    Fenwick_Tree(T n) : tree_(n + 1, 0) {}

    Fenwick_Tree(vector<T> &a)
        : tree_(a.size() + 1, 0), original(a.size() + 1, 0) {
        build(a);
        original = a;
    }

    void update(T x, T new_) { // 1-based index, new value to overwrite
        T temp = x - 1;
        T delta = new_ - original[temp];
        while (x <= (T)tree_.size()) {
            tree_[x] += delta;
            x += lsb(x);
        }
        original[temp] = new_;
    }

    void build(vector<int> &a) {
        for (int i = 0; i < (int)a.size(); i++)
            update(i + 1, a[i]);
    }

    T query(T x) const {
        T sum = 0;
        while (x) {
            sum += tree_[x];
            x -= lsb(x);
        }
        return sum;
    }

    T query(T x, T y) const {
        return query(y) - query(x - 1);
    }

private:
    static inline T lsb(T x) { return x & (-x); }
    vector<T> tree_;
    vector<T> original;
};