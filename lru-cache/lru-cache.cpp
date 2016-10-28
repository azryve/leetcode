//
//  lru-cache.cpp
//  leetcode
//
//  Created by Fedor Zhukov on 28.10.16.
//
//

#include "lru-cache.h"
#include <set>
#include <iostream>

int main()
{
    LRUCache lru(2);
    lru.set(1,2);
    lru.set(2,3);
    lru.get(2);
    lru.set(2,6);
    lru.get(1);
    lru.set(1,5);
    lru.set(1,2);
    lru.get(1);
    std::cout << lru.get(2) << std::endl;
    return 0;
}
