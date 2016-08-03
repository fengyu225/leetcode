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
    vector<bool> v;
    vector<int> l;
    int maxNumbers;
    int l_bound;
    int r_bound;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        this->maxNumbers = maxNumbers;
        this->v = vector<bool>(maxNumbers, true);
        this->l = vector<int>(maxNumbers);
        this->l_bound = 0;
        this->r_bound = 0;
        for(int i=0; i<maxNumbers; i++){
            this->l[r_bound] = i; 
            r_bound = (r_bound+1)%(this->maxNumbers+1);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if((this->r_bound - this->l_bound)%(this->maxNumbers+1) == 0) return -1;
        int res = this->l[this->l_bound];
        this->l_bound = (this->l_bound+1)%(this->maxNumbers+1);
        v[res] = false;
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(number<0 || number>=this->maxNumbers) return false;
        return v[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        int sz = (this->r_bound - this->l_bound)%(this->maxNumbers+1);
        if(sz+1<=this->maxNumbers && number<this->maxNumbers && number>=0 && v[number]==false){
            this->l[this->r_bound] = number;
            this->r_bound = (this->r_bound+1)%(this->maxNumbers+1);
            this->v[number] = true;
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
