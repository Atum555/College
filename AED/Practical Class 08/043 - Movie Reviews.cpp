#include <iostream>
#include <map>
#include <string>

using namespace std;
typedef long long ll;

int main() {
    ll                   movies;
    multimap<string, ll> reviews;
    string               name;
    ll                   review;

    cin >> movies;
    for (ll i = 0; i < movies; i++) {
        cin >> name >> review;
        reviews.insert({ name, review });
    }


    auto it                      = reviews.begin();
    ll   movieCount              = 0;
    ll   maxNumberOfReviews      = 0;
    ll   maxNumberOfReviewsCount = 0;
    ll   numberOfPositiveMovies  = 0;

    while (it != reviews.end()) {
        string movie = (*it).first;
        movieCount++;
        ll reviewCount     = 0;
        ll positiveReviews = 0;

        while ((*it).first == movie) {
            reviewCount++;
            if ((*it).second >= 5) positiveReviews++;
            else positiveReviews--;
            it++;
            if (it == reviews.end()) break;
        }

        if (reviewCount == maxNumberOfReviews) maxNumberOfReviewsCount++;
        if (reviewCount > maxNumberOfReviews) {
            maxNumberOfReviews      = reviewCount;
            maxNumberOfReviewsCount = 1;
        }

        if (positiveReviews > 0) numberOfPositiveMovies++;
    }

    cout << movieCount << endl;
    cout << maxNumberOfReviews << " " << maxNumberOfReviewsCount << endl;
    cout << numberOfPositiveMovies << endl;
}
