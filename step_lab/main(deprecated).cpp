#include <thread>
#include <cassert>
#include "classcustvar_template.hpp"
#include <iostream>

/*
 
        main flow of use of threads
 
    create thread
        - pass in a container
        - generate random number
        - get a +1 or -1 from it
        - store that value
 
 */

typedef cstd::array_dynamic_container<int> container_int;


class cordinate {
    
    double x;
    double y;
    
public:
    
    cordinate (double x, double y) : x(x) , y(y) {}
    
}; // end of class


typedef cordinate cordinate_point;


void test_function (int i, container_int *container) {
    
    container->append(i);
}

// will add the final value to the que
void step (size_t n, container_int *que) {
    
    que->append(step_core(n));
}


int main() {
    
    auto *data = new container_int;
 
    std::thread thread1(test_function,5,data);
    
    std::thread thread2(test_function,7876,data);
    
    std::thread thread3(test_function,96786786,data);
    
    
    thread1.join();
    
    thread2.join();
    
    assert((*data)[1] == 7876);
    
    thread3.join();

    assert((*data)[2] == 96786786);
    
    
    auto *data4 = new container_int;
    auto *data5 = new container_int;
    auto *data6 = new container_int;
    
    std::thread thread4(test_function,111,data4);           // like 1st dimension
    
    std::thread thread5(test_function,122,data5);           // like second dimension
    
    std::thread thread6(test_function,133,data6);           // like third dimension
    
    thread4.join();
    
    assert((*data4)[0] == 111);
    
    thread5.join();
    
    assert((*data5)[1] == 122);
    
    thread6.join();
    
    assert((*data6)[2] == 133);
    
    // take the front most elment from the 3 ques and combine to a single cordinate
    
    
    return 0;
}
