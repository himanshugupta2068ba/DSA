#include <bits/stdc++.h>
using namespace std;

// Shrink polygon inward by delta
vector<pair<double, double>> shrinkPolygon(const vector<pair<double, double>>& pts, double delta) {
    double minX = 1e9, maxX = -1e9, minY = 1e9, maxY = -1e9;
    for (auto& p : pts) {
        minX = min(minX, p.first);
        maxX = max(maxX, p.first);
        minY = min(minY, p.second);
        maxY = max(maxY, p.second);
    }

    vector<pair<double, double>> newPts;
    for (auto& p : pts) {
        double x = p.first, y = p.second;
        if (fabs(x - minX) < 1e-6) x += delta;
        if (fabs(x - maxX) < 1e-6) x -= delta;
        if (fabs(y - minY) < 1e-6) y += delta;
        if (fabs(y - maxY) < 1e-6) y -= delta;
        newPts.push_back({x, y});
    }
    return newPts;
}

// Shoelace formula for area
double polygonArea(const vector<pair<double,double>>& p) {
    double area = 0;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (p[i].first * p[j].second) - (p[j].first * p[i].second);
    }
    return fabs(area) / 2.0;
}

int main() {
    int N;
    cin >> N;
    if (N < 3) {
        cerr << "Invalid polygon size." << endl;
        return 0;
    }

    vector<pair<double,double>> points(N);
    for (int i = 0; i < N; i++)
        cin >> points[i].first >> points[i].second;

    double maxVolume = 0.0;
    double bestH = 0.0;

    for (double h = 0.1; h <= 25.0; h += 0.1) {
        auto shrunk = shrinkPolygon(points, h);
        double area = polygonArea(shrunk);

        if (area < 1e-6 || isnan(area)) break; // invalid polygon area
        double volume = area * h;

        if (volume > maxVolume) {
            maxVolume = volume;
            bestH = h;
        }
    }

    cout << fixed << setprecision(2) << maxVolume << endl;
    return 0;
}
