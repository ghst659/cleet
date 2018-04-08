// -*-mode: c++-*-
#ifndef CLEET_TWO_SUM_H_
#define CLEET_TWO_SUM_H_

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result; // RVO?
    unordered_map<int,int> p;
    for (size_t i = 0; i < nums.size(); i++) {
      int v = nums[i];
      int delta = target - v;
      auto search = p.find(delta);
      if (search != p.end()) {
	result.push_back(search->second);
	result.push_back(i);
	break;
      } else {
	p.insert({v, i});
      }
    }
    return result;
  }
};

#endif // CLEET_TWO_SUM_H_
