#ifndef __leetcode__lru_cache__
#define __leetcode__lru_cache__

#include <unordered_map>
#include <set>
#include <list>

class LRUCache{
public:
    LRUCache(int capacity) : C(capacity) {
        cache.reserve(C);
        Hm.reserve(C);
    }
    
    int get(int key) {
        auto v = cache.find(key);
        if (v == cache.end())
            return -1;
        update_heat(key);
        return v->second;
    }
    
    void set(int key, int value) {
        if (cache.find(key) == cache.end() && cache.size() == C)
        {
            auto b = H.rbegin();
            cache.erase(b->second);
            Hm.erase(b->second);
            H.erase(*b);
        }
        cache.erase(key);
        cache[key] = value;
        update_heat(key);
    }
private:
    void update_heat(int key) {
        int nh = 0;
        if (!H.empty()) {
            nh = H.begin()->first - 1;
        }
        auto oh = Hm.find(key);
        if (oh != Hm.end())
        {
            Hm.erase(oh);
            H.erase(H.find(std::pair<int, int>(oh->second, key)));
        }
        Hm[key] = nh;
        H.insert(std::pair<int, int>(nh,key));
    }
    int C;
    std::unordered_map<int, int> cache; // key, value
    std::unordered_map<int, int> Hm;    // key, heat
    std::set<std::pair<int, int> >H;    // heat, key
};

// From https://discuss.leetcode.com/topic/25792/clean-short-standard-c-solution-not-writing-c-in-c-like-all-other-lengthy-ones
namespace std {
class BetterLRUCache {
    size_t m_capacity;
    unordered_map<int,  list<pair<int, int> >::iterator> m_map; //m_map_iter->first: key, m_map_iter->second: list iterator;
    list<pair<int, int> > m_list;                               //m_list_iter->first: key, m_list_iter->second: value;
public:
    BetterLRUCache(size_t capacity):m_capacity(capacity) {
    }
    int get(int key) {
        auto found_iter = m_map.find(key);
        if (found_iter == m_map.end()) //key doesn't exist
            return -1;
        m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
        return found_iter->second->second;                         //return value of the node
    }
    void set(int key, int value) {
        auto found_iter = m_map.find(key);
        if (found_iter != m_map.end()) //key exists
        {
            m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
            found_iter->second->second = value;                        //update value of the node
            return;
        }
        if (m_map.size() == m_capacity) //reached capacity
        {
            int key_to_del = m_list.back().first;
            m_list.pop_back();            //remove node in list;
            m_map.erase(key_to_del);      //remove key in map
        }
        m_list.push_front(pair<int, int>(key, value));  //create new node in list
        m_map[key] = m_list.begin();       //create correspondence between key and node
    }
};
};
#endif /* defined(__leetcode__lru_cache__) */
