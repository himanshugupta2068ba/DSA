#include <iostream>
#include <vector>
#include <cmath>       // For abs, sqrt, pow
#include <limits>      // For numeric_limits
#include <iomanip>     // For setprecision
#include <algorithm>   // For max

using namespace std;

// Structure to hold coordinates
struct Point {
    int x, y;
};

/**
 * Calculates the area of the polygon using the Shoelace Formula.
 */
double getArea(const vector<Point>& coords) {
    double area = 0.0;
    int N = coords.size();
    for (int i = 0; i < N; ++i) {
        Point p1 = coords[i];
        Point p2 = coords[(i + 1) % N]; // Wrap around to the first point
        area += (p1.x * p2.y) - (p2.x * p1.y);
    }
    return abs(area) / 2.0;
}

/**
 * Calculates the perimeter and the minimum edge length of the polygon.
 */
pair<double, double> getPerimeterAndMinEdge(const vector<Point>& coords) {
    double perimeter = 0.0;
    double min_edge = numeric_limits<double>::max();
    int N = coords.size();

    for (int i = 0; i < N; ++i) {
        Point p1 = coords[i];
        Point p2 = coords[(i + 1) % N];
        
        // Since it's rectilinear, edge length is just the difference
        // in x or y
        double edge_len = abs(p1.x - p2.x) + abs(p1.y - p2.y);
        
        perimeter += edge_len;
        if (edge_len < min_edge) {
            min_edge = edge_len;
        }
    }
    return {perimeter, min_edge};
}

int main() {
    // Optimize C++ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Point> coords(N);
    for (int i = 0; i < N; ++i) {
        cin >> coords[i].x >> coords[i].y;
    }

    // 1. Get original shape properties
    double original_area = getArea(coords);
    auto perim_data = getPerimeterAndMinEdge(coords);
    double perimeter = perim_data.first;
    double min_edge = perim_data.second;

    // 2. Find max allowed height
    double H_max = (min_edge - 0.1) / 2.0;

    double max_volume = 0.0;

    // 3. Iterate through all possible heights
    // Use a small epsilon for floating point comparison
    for (double H = 0.1; H <= H_max + 1e-9; H += 0.1) {
        
        // Calculate the area of the box's base
        double base_area = original_area - (perimeter * H) + (4.0 * H * H);
        
        // Calculate the volume
        double current_volume = base_area * H;
        
        // Update max volume
        max_volume = max(max_volume, current_volume);
    }

    // 4. Print the result
    cout << fixed << setprecision(2) << max_volume << endl;

    return 0;
}