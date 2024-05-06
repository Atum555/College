#include <sstream>
#include <vector>
#include <list>
#include <string>

template <typename Itr> std::string to_string(Itr start, Itr end) {
    std::ostringstream out;
    out << "[ ";
    for (; start != end; ++start) out << *start << ' ';
    out << ']';
    return out.str();
}

template <typename Itr, typename T>
int replace(Itr start, Itr end, const T &a, const T &b) {
    int changed = 0;
    for (; start != end; ++start) {
        if (*start != a) continue;
        *start = b;
        ++changed;
    }
    return changed;
}
