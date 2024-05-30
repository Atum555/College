#include <list>
#include <map>
#include <string>

using namespace std;

string cat_keys(list<map<string, unsigned>> lst) {
    unsigned              mValue = __UINT32_MAX__;
    map<string, unsigned> mMap;

    for (auto mapa : lst) {
        for (auto par : mapa) {
            if (par.second < mValue) {
                mValue = par.second;
                mMap   = mapa;
            }
        }
    }

    string result;
    for (auto par : mMap) result += par.first;
    return result;
}