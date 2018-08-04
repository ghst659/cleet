// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "data.h"
#include "combination_sum.h"
#include "gtest/gtest.h"

#include <iostream>

namespace {
    /*
     * Given a set of candidate numbers (candidates) (without
     * duplicates) and a target number (target), find all unique
     * combinations in candidates where the candidate numbers sums to
     * target.  The same repeated number may be chosen from candidates
     * unlimited number of times.  Note: All numbers (including target)
     * will be positive integers.  The solution set must not contain
     * duplicate combinations.
     * Example 1:
     * Input: candidates = [2,3,6,7], target = 7,
     * A solution set is:
     * [
     * [7],
     * [2,2,3]
     * ]
     * Example 2:
     * Input: candidates = [2,3,5], target = 8,
     * A solution set is:
     * [
     * [2,2,2,2],
     * [2,3,3],
     * [3,5]
     * ]
     */
    TEST(CombinationSum, Examples) {
        Solution s;
        std::vector<std::vector<int>> input_candidates{
            {2, 3, 6, 7},
            {2, 3, 5}
        };
        std::vector<int> input_targets{7, 8};
        std::vector<std::vector<std::vector<int>>> want_outputs{
            {
                {2,2,3},
                {7}
            },
            {
                {2, 2, 2, 2},
                {2, 3, 3},
                {3, 5}
            }
        };
        for (size_t i = 0; i < input_candidates.size(); ++i) {
            const std::vector<int>& combination(input_candidates.at(i));
            const int target(input_targets.at(i));
            const std::vector<std::vector<int>>& want(want_outputs.at(i));

            const std::vector<std::vector<int>> got(s.combinationSum(combination, target));
            EXPECT_EQ(got, want);
        }
    } // TEST
}  // namespace
