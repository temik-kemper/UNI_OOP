#include <iostream>

#include "bad_unique.hpp"
#include "bad_shared.hpp"
#include "bad_weak.hpp"

using namespace std;

int main()
{
    {//unique_test
        int a = 3;
        int b = 5;
        auto ptr1 = make_badUnique(&a);
        auto ptr2 = make_badUnique(&b);
        UniqueBadPtr<int> ptr3;
        ptr3 = std::move(ptr1);
        cout << "unique_test_start" <<endl;
        cout << "ptr1 : " << ptr1.get() << endl;
        cout << "ptr2 : " << ptr2.get() << endl;
        cout << "ptr3 : " << ptr3.get() << endl;
        cout << "unique_test_finish\n\n" <<endl;
    }


    {//shared_test
        int a = 3;
        SharedBadPtr<int> ptr1(&a);
        SharedBadPtr<int> ptr2 = ptr1;
        SharedBadPtr<int> ptr3 = ptr2;
        cout << "shared_test_start" <<endl;
        cout << "sharedCounter: " << ptr1.count().sharedCounter <<endl;
        ptr3.reset();
        cout << "sharedCounter: " << ptr1.count().sharedCounter <<endl;
        ptr2.reset();
        cout << "sharedCounter: " << ptr1.count().sharedCounter <<endl;
        cout << "shared_test_finish\n\n" <<endl;
    }
    
    {//weak test
        int a = 3;
        WeakBadPtr<int> ptr2;
        WeakBadPtr<int> ptr3;
        {
            SharedBadPtr<int> ptr1(&a);
            ptr2 = ptr1;
            ptr3 = ptr2;
            cout << "weak_test_start" <<endl;
            cout << "Counter{shared, weak}: " << ptr1.count().sharedCounter << ", " << ptr1.count().weakCounter <<endl;
        }
        cout << "Counter{shared, weak}: " << ptr2.count().sharedCounter << ", " << ptr2.count().weakCounter <<endl;
        cout << "weak_test_finish" <<endl;
        


    }





    return 0;
}