#ifndef CLEET_PERMUTATIONS_H_
#define CLEET_PERMUTATIONS_H_

#include <vector>

class Solution {
private:
  void helper(const std::vector<int>& choices,
              std::vector<int>& trace,
              std::vector<std::vector<int>>& result) {
    if (choices.size() < 1) {
      result.push_back(trace);
      return;
    }
    for (size_t k = 0; k < choices.size(); ++k) {
      trace.push_back(choices.at(k));

      std::vector<int> next_choices;
      for (size_t j = 0; j < choices.size(); ++j) {
        if (j != k) {
          next_choices.push_back(choices.at(j));
        }
      }
      helper(next_choices, trace, result);
      trace.pop_back();
    }
  }

public:
  std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> trace;
    helper(nums, trace, result);
    return result;
  }
};

#endif // CLEET_PERMUTATIONS_H_
