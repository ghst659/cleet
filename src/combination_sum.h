#ifndef CLEET_COMBINATION_SUM_H_
#define CLEET_COMBINATION_SUM_H_

#include <algorithm>            // std::sort
#include <set>

class Solution {
private:
    void helper(const std::vector<int>& candidates, int target,
                std::multiset<int>& trace,
                std::set<std::multiset<int>>& result) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            result.insert(trace);
        } else {
            for (size_t i = 0; i < candidates.size() && candidates.at(i) <= target; ++i) {
                int addition = candidates.at(i);
                trace.insert(addition);
                helper(candidates, target - addition, trace, result);
                trace.erase(trace.find(addition));
            }
        }
    }
public:
    std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> sorted_candidates(candidates);
        std::sort(sorted_candidates.begin(), sorted_candidates.end());
        std::multiset<int> trace;
        std::set<std::multiset<int>> raw_result;
        helper(sorted_candidates, target, trace, raw_result);
        for (const auto& mulset : raw_result) {
            std::vector<int> vtrace(mulset.begin(), mulset.end());
            result.push_back(vtrace);
        }
        return result;
    }
};

#endif // CLEET_COMBINATION_SUM_H_
