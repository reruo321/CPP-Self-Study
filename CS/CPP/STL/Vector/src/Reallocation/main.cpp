/*
    This code shows why we must
    be careful on the reallocation
    of vector data!
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {100, 101};
    int *ptr = &vec.at(1);
    
    for(int i=102; i<=109; ++i){
        cout << "capacity=" << vec.capacity() << endl;
        // ptr: Not changed.
        // *ptr: Changed.
        // ptr will point to alien data
        // after the first reallocation.
        // (After the vector having the 3rd element.)
        cout << "ptr=" << ptr << "   *ptr=" << *ptr << endl;
        // &vec: Address of the vector object. Not reallocated.
        cout << "&vec=" << &vec << endl;
        // &vec.at(n): Address of the vector data.
        // Reallocated whenever the vector hits its capacity.
        // All data will follow the address of an internal array.
        cout << "&vec.at(0)=" << &vec.at(0) << endl;
        cout << "&vec.at(1)=" << &vec.at(1) << endl << endl;
        vec.push_back(i);
    }

    return 0;
}
