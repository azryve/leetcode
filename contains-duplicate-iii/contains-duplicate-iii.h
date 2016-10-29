//
//  contains-duplicate-iii.h
//  leetcode
//
//  Created by Fedor Zhukov on 27.10.16.
//
//

#ifndef __leetcode__contains_duplicate_iii__
#define __leetcode__contains_duplicate_iii__

#include <set>


class Solution {
public:
    bool containsNearbyAlmostDuplicate(const std::vector<int>& nums, int k, int t) {
        if (k == 0)
            return false;

        std::set<int> set;
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (it - nums.begin() > k) set.erase(*(it-k-1));
            auto lb = set.lower_bound(*it - t);
            if (lb != set.end() && *lb - *it <= t)
                return true;
            set.insert(*it);
        }
        return false;
    }
};

#endif /* defined(__leetcode__contains_duplicate_iii__) */
