// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "two_sum.h"
#include "gtest/gtest.h"

#include <vector>

namespace {
  // Given an array of integers, return indices of the two numbers such
  // that they add up to a specific target.  You may assume that each
  // input would have exactly one solution, and you may not use the same
  // element twice.
  // Example:
  // Given nums = [2, 7, 11, 15], target = 9,
  // Because nums[0] + nums[1] = 2 + 7 = 9,
  // return [0, 1].
  TEST(TwoSumTest, Example) {
    Solution s;
    int ary[] = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> nums(ary, ary + sizeof(ary)/sizeof(ary[0]));
    std::vector<int> got = s.twoSum(nums, target);
    EXPECT_EQ(0, got[0]);
    EXPECT_EQ(1, got[1]);
  }
}  // namespace
