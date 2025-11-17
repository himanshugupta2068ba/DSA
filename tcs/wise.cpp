#include <iostream>
#include <vector>
#include <cmath>
#include <set>      // To store unique vertices (points)
#include <map>      // To build the adjacency list (graph)
#include <algorithm>
#include <iomanip>  // For setprecision
#include <list>     // Efficient for path manipulation in DFS

// Use M_PI for pi, requires <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// Epsilon for floating-point comparisons
const double EPS = 1e-9;

/**
 * @struct Point
 * @brief Represents a 2D point with custom comparators for use in maps/sets.
 */
struct Point {
    double x, y;

    // Comparator for sorting and for map/set keys
    bool operator<(const Point& other) const {
        if (abs(x - other.x) > EPS) return x < other.x;
        if (abs(y - other.y) > EPS) return y < other.y;
        return false;
    }
    
    // Equality check
    bool operator==(const Point& other) const {
        return abs(x - other.x) < EPS && abs(y - other.y) < EPS;
    }
};

/**
 * @struct Line
 * @brief Represents a stick (line segment).
 */
struct Line {
    Point p1, p2;
    double original_length;
};

// --- Helper Functions ---

/**
 * @brief Calculates the Euclidean distance between two points.
 */
double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

/**
 * @brief Checks if a point 'p' lies on the line segment 's'.
 */
bool onSegment(Point p, const Line& s) {
    double d_sp1 = dist(s.p1, p);
    double d_sp2 = dist(p, s.p2);
    double d_total = s.original_length;
    // Check if p is collinear and within the segment bounds
    return abs(d_sp1 + d_sp2 - d_total) < EPS;
}

/**
 * @brief Finds the intersection point of two line segments, if it exists.
 * @return pair<bool, Point> - {true, intersection_point} or {false, {}}
 */
pair<bool, Point> getIntersection(const Line& l1, const Line& l2) {
    double x1 = l1.p1.x, y1 = l1.p1.y;
    double x2 = l1.p2.x, y2 = l1.p2.y;
    double x3 = l2.p1.x, y3 = l2.p1.y;
    double x4 = l2.p2.x, y4 = l2.p2.y;

    double den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (abs(den) < EPS) {
        return {false, {}}; // Parallel or collinear
    }

    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
    double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

    // Check if intersection is within both segments (using EPS for float safety)
    if (t >= -EPS && t <= 1.0 + EPS && u >= -EPS && u <= 1.0 + EPS) {
        Point p = {x1 + t * (x2 - x1), y1 + t * (y2 - y1)};
        return {true, p};
    }
    
    return {false, {}}; // Intersection is not on one or both segments
}

/**
 * @brief Calculates the area of a polygon using the Shoelace Formula.
 */
double shoelaceArea(const vector<Point>& polygon) {
    if (polygon.size() < 3) return 0.0;
    double area = 0.0;
    int n = polygon.size();
    for (int i = 0; i < n; ++i) {
        area += (polygon[i].x * polygon[(i + 1) % n].y - polygon[(i + 1) % n].x * polygon[i].y);
    }
    return abs(area) / 2.0;
}

// --- Global variables for DFS Cycle Finding ---
map<Point, vector<Point>> adj; // Adjacency list for the graph
vector<Point> cycle;           // Stores the found cycle
bool cycle_found = false;
set<Point> visited_global; // Nodes visited in *any* DFS tree
set<Point> visited_path;   // Nodes in the *current* recursion stack
list<Point> current_path;  // The current DFS path

/**
 * @brief DFS to find a simple cycle in the graph.
 */
void findCycle(Point u, Point parent) {
    if (cycle_found) return;
    
    visited_global.insert(u);
    visited_path.insert(u);
    current_path.push_back(u);

    for (const Point& v : adj[u]) {
        if (v == parent) continue; // Don't go immediately back

        if (visited_path.count(v)) {
            // Cycle found!
            cycle_found = true;
            // Extract the cycle from the path
            auto it = current_path.begin();
            while (!(*it == v)) {
                it++;
            }
            cycle.assign(it, current_path.end());
            return;
        }

        if (!visited_global.count(v)) {
            findCycle(v, u);
            if (cycle_found) return;
        }
    }

    current_path.pop_back();
    visited_path.erase(u);
}

// --- Main Function ---
int main() {
    // Optimize C++ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Line> sticks(N);
    double total_stick_length = 0.0;

    for (int i = 0; i < N; ++i) {
        cin >> sticks[i].p1.x >> sticks[i].p1.y >> sticks[i].p2.x >> sticks[i].p2.y;
        sticks[i].original_length = dist(sticks[i].p1, sticks[i].p2);
        total_stick_length += sticks[i].original_length;
    }

    // --- 1. Find all critical points (graph vertices) ---
    set<Point> vertices;
    for (int i = 0; i < N; ++i) {
        vertices.insert(sticks[i].p1);
        vertices.insert(sticks[i].p2);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            auto result = getIntersection(sticks[i], sticks[j]);
            if (result.first) {
                vertices.insert(result.second);
            }
        }
    }

    // --- 2. Build the graph edges ---
    adj.clear();
    for (int i = 0; i < N; ++i) {
        vector<Point> points_on_stick;
        for (const auto& v : vertices) {
            if (onSegment(v, sticks[i])) {
                points_on_stick.push_back(v);
            }
        }

        // Sort points along the stick to find adjacent segments
        sort(points_on_stick.begin(), points_on_stick.end(), [&](Point a, Point b) {
            return dist(sticks[i].p1, a) < dist(sticks[i].p1, b);
        });

        // Add edges (segments) to adjacency list
        for (size_t j = 0; j < points_on_stick.size() - 1; ++j) {
            Point p_a = points_on_stick[j];
            Point p_b = points_on_stick[j + 1];
            
            if (p_a == p_b) continue; // Skip zero-length segments
            
            adj[p_a].push_back(p_b);
            adj[p_b].push_back(p_a);
        }
    }
    
    // --- 3. Find the cycle ---
    cycle_found = false;
    visited_global.clear();
    for (const auto& v_pair : adj) { // Only start DFS from points in the graph
        const Point& v = v_pair.first;
        if (cycle_found) break;
        if (visited_global.find(v) == visited_global.end()) {
            visited_path.clear();
            current_path.clear();
            findCycle(v, v); // Pass v as its own parent for the root
        }
    }

    // --- 4. Check result and calculate areas ---
    if (!cycle_found) {
        cout << "Abandoned" << endl;
        return 0;
    }

    double area_kalyan = shoelaceArea(cycle);
    
    // If area is zero (degenerate polygon), it's not a real figure
    if (abs(area_kalyan) < EPS) {
         cout << "Abandoned" << endl;
         return 0;
    }

    // Calculate perimeter of Kalyan's figure
    double perimeter_kalyan = 0.0;
    for (size_t i = 0; i < cycle.size(); ++i) {
        perimeter_kalyan += dist(cycle[i], cycle[(i + 1) % cycle.size()]);
    }

    double length_computer = total_stick_length - perimeter_kalyan;

    // If computer has no material, Kalyan wins
    if (length_computer < EPS) {
        cout << "Kalyan" << endl;
        return 0;
    }

    // Max area for computer is a circle
    double area_computer = (length_computer * length_computer) / (4.0 * M_PI);

    // --- 5. Output winner ---
    if (area_kalyan > area_computer) {
        cout << "Kalyan" << endl;
    } else {
        // Constraint: No ties
        cout << "Computer" << endl;
    }

    return 0;
}