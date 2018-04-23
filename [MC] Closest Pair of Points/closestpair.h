#ifndef INC_08_CLOSESTPAIR_H
#define INC_08_CLOSESTPAIR_H

#include <iostream>
#include <cmath>    //sqrt
#include <vector>
#include <algorithm>

using namespace std;

///// UTILITIES ////
struct Point {
    double x, y;
};
bool sortByX(Point &a, Point &b) { return a.x < b.x; };
bool sortByY(Point *a, Point *b) { return a->y < b->y; };
double euclideanDistance(Point &a, Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
};
////////////////////

double closestPairRecursive(vector<Point> &points, int offset, int n) {

    if (n == 2)
        return euclideanDistance(points[offset], points[offset + 1]);

    if (n == 3)
        return min(euclideanDistance(points[offset], points[offset + 1]),
                   min(euclideanDistance(points[offset], points[offset + 2]),
                       euclideanDistance(points[offset + 1], points[offset + 2])));

    int mid = n / 2;

    // recurse on the left side
    double leftSection = closestPairRecursive(points, offset, mid);

    // recurse on the right side
    double rightSection = closestPairRecursive(points, offset + mid, n - mid);

    // compare both sides
    double minDistance = std::min(leftSection, rightSection);

    //create the strip
    vector<Point *> strip;
    for (int i = offset; i < offset + n; ++i)
        if (abs(points[i].x - points[offset + mid].x) < minDistance)
            strip.push_back(&points[i]);

    //Sort strip according to Y
    sort(strip.begin(), strip.end(), sortByY);

    double stripMin = minDistance;
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size(); ++j) {
            // Proven to only check at max 7 iterations.
            if ((strip[j]->y - strip[i]->y) > stripMin)
                break;

            stripMin = min(stripMin, euclideanDistance(*strip[i], *strip[j]));
        }
    }

    return min(stripMin, minDistance);
}

double closestPair(vector<Point> points) {
    //sort points by X;
    sort(points.begin(), points.end(), sortByX);

    //start recursion
    return closestPairRecursive(points, 0, points.size());
}

#endif //INC_08_CLOSESTPAIR_H
