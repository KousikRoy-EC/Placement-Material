#include <iostream>
#include <memory>
using namespace std;

/* Unique Pointer in C++ */
// unique_ptr automatically deallocates memory when it goes out of scope it has exclusive ownership only one unique_ptr can own the memory however ownership can be transferred using move
// ptr1 is moved to ptr2, so ptr1 becomes nullptr   

/*
int main(){
    unsigned int variable=400;
    unique_ptr<int> ptr1 = make_unique<int>(variable);
    unique_ptr<int> ptr2 = move(ptr1);
    // cout<<*ptr1<<endl; crashes the program as it is nullptr now
    cout<<*ptr2<<endl;
    return 0;
}
*/


/* Shared Pointer */
// shared_ptr allows multiple pointers to share ownership of the same memory when the last shared_ptr pointing to the memory is destroyed or reset the memory is deallocated
// reference count is maintained by shared pointer to count how many pointer is pointing to that referencw and when this count becomes zero it deallocates memory for that shared pointer variable that it was pointing to

/*
int main(){
    unsigned int variable=500;
    shared_ptr<int> ptr1 = make_shared<int>(variable);
    shared_ptr<int> ptr2 = ptr1; // both ptr1 and ptr2 share ownership
    cout<<*ptr1<<endl;
    cout<<*ptr2<<endl;
    cout<<"Reference Count: "<<ptr1.use_count()<<endl; // shows how many shared_ptr point to the same memory
    ptr1.reset(); // ptr1 no longer owns the memory
    cout<<"After resetting ptr1"<<endl;
    cout<<"Reference Count: "<<ptr2.use_count()<<endl; // shows how many shared_ptr point to the same memory    
    return 0;
}
*/



/* Weak pointer */

// weak pointer has no ownership it is only for counting references in shared pointer it has no role in reference count too
// weak pointer prevents circular loop that could create memory leak