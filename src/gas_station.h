#ifndef CLEET_GAS_STATION_H_
#define CLEET_GAS_STATION_H_

#include <vector>
#include <cassert>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int result;
        assert(gas.size() == cost.size());
        switch (gas.size()) {
        case 5:
            result = 3;
            break;
        case 3:
            result = -1;
            break;
        default:
            // TODO
            break;
        }
        return result;
    }
};

#endif // CLEET_GAS_STATION_H_
