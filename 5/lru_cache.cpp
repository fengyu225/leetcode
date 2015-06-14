/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

#include "header.h"

class LRUCache{
public:
    LRUCache(int capacity) {
        capacity = capacity;     
    }
    int get(int key) {
        return 0;    
    }
    void set(int key, int value) {
            
    }
    int capacity;
};

int main(){
    LRUCache cache(10);
    cout<<cache.capacity<<endl;
    return 0;
}