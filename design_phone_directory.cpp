/*
Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
*/

#include "header.h"


class PhoneDirectory {
    unordered_set<int> s;
    int maxNumbers;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        this->maxNumbers = maxNumbers;
        for(int i=0; i<maxNumbers; i++) s.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(s.size() == 0) return -1;
        int res = *(s.begin());
        s.erase(s.begin());
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return s.find(number) != s.end(); 
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        int sz = s.size();
        if(sz+1<=this->maxNumbers){
            s.insert(number);    
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

int main(){
    PhoneDirectory* directory = new PhoneDirectory(3);
    cout<<directory->get()<<endl;
    cout<<directory->get()<<endl;
    cout<<directory->check(2)<<endl;
    cout<<directory->get()<<endl;
    cout<<directory->check(2)<<endl;
    directory->release(2);
    cout<<directory->check(2)<<endl;
    return 0;
}
