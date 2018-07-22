#ifndef CLEET_PERMUTATIONS_H_
#define CLEET_PERMUTATIONS_H_

#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
    std::vector<std::vector<int>> result;

    result = std::vector<std::vector<int>>({
      {
        {1,2,3},
          {1,3,2},
          {2,1,3},
          {2,3,1},
          {3,1,2},
          {3,2,1}
      }
        });
    return result;
  }
};

#endif // CLEET_PERMUTATIONS_H_
