//
//  contains-duplicate-iii.h
//  leetcode
//
//  Created by Fedor Zhukov on 27.10.16.
//
//

#ifndef __leetcode__contains_duplicate_iii__
#define __leetcode__contains_duplicate_iii__

#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <set>


class Solution {
public:
    bool containsNearbyAlmostDuplicate(const std::vector<int>& nums, int k, int t) {
        std::set<int> window; // set is ordered automatically
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto pos = window.lower_bound(nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t
            // x - nums[i] <= t ==> |x - nums[i]| <= t
            if (pos != window.end() && *pos - nums[i] <= t) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};

#endif /* defined(__leetcode__contains_duplicate_iii__) */
