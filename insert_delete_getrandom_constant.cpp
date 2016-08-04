/*
Design a data structure that supports all following operations in O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 1 is the only number in the set, getRandom always return 1.
randomSet.getRandom();
*/

#include "header.h"

class RandomizedSet {
    unordered_map<int,int> pos;
    vector<int> data;
    int last_index;
    int count;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        last_index = -1;
        count = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(pos.find(val) != pos.end()) return false;
        data.push_back(val);
        last_index++;
        pos[val] = last_index;
        count++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(pos.find(val) == pos.end()) return false;
        int i = pos[val];
        int v = data[last_index];
        if(v != val){
            swap(data[last_index], data[i]);
            pos[v] = i;
        }
        data.pop_back();
        pos.erase(pos.find(val));
        count--;
        last_index--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int i = rand() % (last_index+1);
        return data[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(){
    RandomizedSet* randomSet = new RandomizedSet();
    cout<<randomSet->insert(1)<<endl;
    cout<<randomSet->remove(2)<<endl;
    cout<<randomSet->insert(2)<<endl;
    cout<<randomSet->getRandom()<<endl;
    cout<<randomSet->remove(1)<<endl;
    cout<<randomSet->insert(2)<<endl;
    cout<<randomSet->getRandom()<<endl;
    return 0;
}
