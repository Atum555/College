#include <algorithm>
#include <iostream>
#include <vector>

template <class T, class U> class Pair {
  public:
    Pair(T a, U b) : first_(a), second_(b) {}

    T get_first() const { return first_; }

    U get_second() const { return second_; }

    void show() const { std::cout << "{" << first_ << "," << second_ << "}"; }

  private:
    T first_;
    U second_;
};

template <class T, class U> void sort_by_first(std::vector<Pair<T, U>> &v) {
    std::sort(
        v.begin(), v.end(),
        [](const Pair<T, U> &a, const Pair<T, U> &b) -> bool {
            return a.get_first() < b.get_first();
        }
    );
}

template <class T, class U> void sort_by_second(std::vector<Pair<T, U>> &v) {
    std::sort(
        v.begin(), v.end(),
        [](const Pair<T, U> &a, const Pair<T, U> &b) -> bool {
            return a.get_second() < b.get_second();
        }
    );
}

template <class T, class U> void show(const std::vector<Pair<T, U>> &v) {
    std::cout << "{";
    for (Pair<T, U> p : v) p.show();
    std::cout << "}";
}