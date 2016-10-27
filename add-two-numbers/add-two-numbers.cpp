//
//  add-two-numbers.cpp
//  leetcode
//
//  Created by Fedor Zhukov on 26.10.16.
//
//
#include <iostream>
#include  <algorithm>
#include "add-two-numbers.h"

void print(ListNode *l)
{
    for (ListNode *i = l; i != NULL; i=i->next)
    {
        std::cout << i->val << std::endl;
    }
}


int main()
{
    ListNode l1(9);
    ListNode l2(1);
    Solution s;
    print(s.addTwoNumbers(&l1, &l2));
    std::cout << "END" << std::endl;
    return 0;
}