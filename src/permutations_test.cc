// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "permutations.h"
#include "gtest/gtest.h"

#include <iostream>
#include <vector>

namespace {

  // Given a collection of distinct integers, return all possible permutations.
  // Example:
  // Input: [1,2,3]
  // Output:
  // [
  //   [1,2,3],
  //   [1,3,2],
  //   [2,1,3],
  //   [2,3,1],
  //   [3,1,2],
  //   [3,2,1]
  // ]

  TEST(Permutations, Examples) {
    Solution s;
    std::vector<std::vector<int>> inputs{
      {1,2,3}
      , {4,5}
    };
    std::vector<std::set<std::vector<int>>> outputs{
      {{1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,2,1}, {3,1,2}}
      , {{4,5}, {5,4}}
    };
    for (size_t i = 0; i < inputs.size(); ++i) {
      const std::vector<int>& nums(inputs.at(i));
      const std::set<std::vector<int>>& want(outputs.at(i));
      const std::vector<std::vector<int>>& got(s.permute(nums));
      std::set<std::vector<int>> gots;
      for (const auto& item : got) {
        gots.insert(item);
      }
      EXPECT_EQ(gots, want);
    }
  }
}  // namespace
