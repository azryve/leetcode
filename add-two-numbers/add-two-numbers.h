//
//  add-two-numbers.h
//  leetcode
//
//  Created by Fedor Zhukov on 26.10.16.
//
//

#ifndef __leetcode__add_two_numbers__
#define __leetcode__add_two_numbers__

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//typedef struct sListNode ListNode;

class Solution {
public:
    Solution() {};
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = ListAlloc(std::max(Count(l1), Count(l2)));
        size_t cum = 0;
        ListNode *i1 = l1, *i2 = l2, *tail;
        for (ListNode *c = head; c != NULL; tail = c, c = c->next)
        {
            size_t sum = cum;
            if (i1 != NULL)
            {
                sum += i1->val;
                i1 = i1->next;
            }
            if (i2 != NULL)
            {
                sum += i2->val;
                i2 = i2->next;
            }
            c->val = sum % 10;
            cum = sum / 10;
        }
        // Overflow
        if (cum != 0)
        {
            tail->next = (ListNode*) calloc(1, sizeof(ListNode));
            tail->next->val = cum;
        }
        return head;
    };
    ListNode *ListAlloc(size_t len) {
            if (len == 0)
                return NULL;
            ListNode *head = (ListNode*) calloc(1, sizeof(ListNode));
            ListNode *tail = head;
            for (size_t i = 0; i < len - 1; i++)
            {
                ListNode *n = (ListNode*) calloc(1, sizeof(ListNode));
                tail->next = n;
                tail = n;
            }
            return head;
    };
    size_t Count(ListNode *l) {
        size_t len = 0;
        for (ListNode *i = l; i != NULL; i=i->next)
            len++;
        return len;
    };
};

#endif /* defined(__leetcode__add_two_numbers__) */
