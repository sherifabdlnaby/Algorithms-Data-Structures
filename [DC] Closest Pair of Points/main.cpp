#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "closestpair.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int n;
    vector<Point> points;

    cin >> n;
    double xt, yt;
    for (int i = 0; i < n; ++i) {
        cin >> xt >> yt;
        points.push_back({xt, yt});
    }

    double distance = closestPair(points);

    cout << fixed << setprecision(4) << distance << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
