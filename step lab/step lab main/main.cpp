#include "classcustvar_template.hpp"
#include <iostream>
#include <thread>
#include <random>


// void func(number of steps) {

    // recursivly do this for number of steps{

    //  generate random number
    //  get a +1 or -1 value from the random number
    // }

    // add the final value after the steps onto the que

//}


typedef cstd::array_dynamic_container<int> container_int;


class cordinate {
    
    int x;
    int y;
    int z;
    
public:
    
    cordinate (int x, int y, int z) : x(x) , y(y) , z(z) {}
    
}; // end of class


typedef cordinate cordinate_point;


void test_function (int i, container_int *container) {
    
    container->append(i);
}


// returns the final step count
int step_core (size_t n) {                                 // (que, step count)
    
    std::random_device rd;                                           // obtain a random number from hardware
    std::mt19937 gen(rd());                                      // seed the generator
    std::uniform_int_distribution<> distr(1, std::numeric_limits<int>::max());             // define the range
    
    int T = (distr(gen) % 2);
    
    if (T != 0) T = -1;
    else T = 1;
    
    if (n == 1) return 1;
    
    else return T + step_core(n-1);
}


// will add the final value to the que
void step (size_t n, container_int *que) {
    
    for (size_t i = 0; i < n; i++) {
        que->append(step_core(n));
    }
}

cordinate* cord (container_int *que1, container_int *que2, container_int *que3,size_t n) {
    
    auto *cord1 = new cordinate(que1->[n],que2->[n],que3->[n]);
    
    return cord1;
}



int main() {

    // containers for each dimension
    auto *data1 = new container_int;                // 1st dimension
    auto *data2 = new container_int;                // 2nd dimension
    auto *data3 = new container_int;                // 3rd dimension
    
    
    
    

    step(10, data1);
    step(4,data2);
    step(9,data3);
    
    
    
    
    // take elements from the ques and create objects
    
    
    
    for (size_t i = 0;  i < 10; i++) std::cout << (*data1)[i];
    for (size_t i = 0;  i < 10; i++) std::cout << (*data2)[i];
    for (size_t i = 0;  i < 10; i++) std::cout << (*data3)[i];
    
    return 0;
}
