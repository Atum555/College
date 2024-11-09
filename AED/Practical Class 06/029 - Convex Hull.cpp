#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>


using namespace std;

struct Point {
    int x;
    int y;
};

bool operator==(const Point &a, const Point &b) { return a.x == b.x and a.y == b.y; }

Point operator-(const Point &a, const Point &b) { return Point{ b.x - a.x, b.y - a.y }; }

// Returns true if a b and c make a counter-clock-wise turn
bool ccw(const Point &a, const Point &b, const Point &c) {
    Point vecAB = b - a;
    Point vecBC = c - b;

    return vecAB.x * vecBC.y - vecAB.y * vecBC.x > 0;
}

int main() {
    vector<Point> points;
    vector<Point> outside;
    u_int64_t     N;
    int           x, y;
    Point         lowest;

    // Read Data
    cin >> N;
    for (size_t i = 0; i < N; i++) {
        cin >> x >> y;
        points.push_back(Point{ x, y });
    }

    // Find lowest point
    lowest = points[0];
    for (const Point &p : points)
        if (p.y < lowest.y) lowest = p;
        else if (p.y == lowest.y and p.x < lowest.x) lowest = p;

    // Add it to stack and remove from point list
    outside.push_back(lowest);
    points.erase(find(points.begin(), points.end(), lowest));

    // Sort by polar angle relative to the lowest point
    sort(points.begin(), points.end(), [&lowest](Point a, Point b) {
        a = lowest - a;
        b = lowest - b;
        return atan2(a.y, a.x) < atan2(b.y, b.x);
    });


    // Graham's Algorithm
    for (const Point &p : points) {
        while (outside.size() > 1
               and not ccw(outside[outside.size() - 2], outside[outside.size() - 1], p))
            outside.pop_back();
        outside.push_back(p);
    }

    // Print Out Results
    cout << outside.size() << endl;
    for (const Point &p : outside) cout << p.x << ' ' << p.y << endl;
}
