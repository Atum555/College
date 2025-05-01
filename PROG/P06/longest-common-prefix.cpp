#include <string>
#include <vector>

std::string longest_prefix(const std::vector<std::string> &v) {
    std::string result = "";
    size_t      i      = 0;
    while (true) {
        char l = v[0][i];
        for (const std::string str : v)
            if (str[i] != l) l = 0;
        if (!l) return result;
        result.push_back(l);
        ++i;
    }
}
