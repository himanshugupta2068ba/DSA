// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minMeetingRooms(vector<pair<int, int>>& intervals) {
    vector<int> starts, ends;
    for (const auto& interval : intervals) {
        starts.push_back(interval.first);
        ends.push_back(interval.second);
    }
    
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    
    int s_ptr = 0, e_ptr = 0;
    int used_rooms = 0, max_rooms = 0;
    
    while (s_ptr < starts.size()) {
        if (starts[s_ptr] < ends[e_ptr]) {
            used_rooms++;
            max_rooms = max(max_rooms, used_rooms);
            s_ptr++;
        } else {
            used_rooms--;
            e_ptr++;
        }
    }
    
    return max_rooms;
}
int main() {
    vector<pair<int, int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    
    int result = minMeetingRooms(intervals);
    cout << "Minimum number of conference rooms required: " << result << endl;
    
    return 0;
}