#ifndef CLEET_GAS_STATION_H_
#define CLEET_GAS_STATION_H_

#include <vector>
#include <limits>

class Solution {
public:
    int canCompleteCircuit(const std::vector<int>& gas, const std::vector<int>& cost) {
        int result = -1;
        const size_t len = gas.size();
        int total = 0;
        int min_total = std::numeric_limits<int>::max();
        size_t min_i = 0;
        for (size_t i = 0; i < len; ++i) {
            total += gas.at(i) - cost.at(i);
            if (total < min_total) {
                min_total = total;
                min_i = i;
            }
        }
        if (total >= 0) {
            result = (min_i + 1) % len;
        }
        return result;
    }
};

#endif // CLEET_GAS_STATION_H_
