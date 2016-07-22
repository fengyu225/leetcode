/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

#include "header.h"

class LRUCache{
public:
    struct cacheEntry{
        int key;
        int val;
        cacheEntry(int k, int v):key(k),val(v){}
    };
    LRUCache(int capacity):capacity(capacity){}
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        moveToFront(key);
        return lst.front().val;
    }
    void set(int key, int value) {
        if(map.find(key) == map.end()){
            cacheEntry* e = new cacheEntry(key,value);
            while(lst.size() >= capacity){
                map.erase(lst.back().key);
                lst.pop_back();
            }
            lst.push_front(*e);
            map[key] = lst.begin();
        }
        else{
            moveToFront(key);
            (*map[key]).val = value;
        }
    }
private:
    int capacity;
    unordered_map<int, list<cacheEntry>::iterator> map;
    list<cacheEntry> lst;
    void moveToFront(int key){
        cacheEntry entry = *map[key];
        lst.erase(map[key]);
        lst.push_front(entry);
        map[key] = lst.begin();
    }    
};

int main(){
    LRUCache cache(5);
    cache.set(1,1);
    cache.set(1,1);
    cache.set(1,1);
    cache.set(1,1);
    cache.set(1,1);
    return 0;
}