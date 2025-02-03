#include "classcustvar_template.hpp"
#include <iostream>
#include <thread>
#include <random>
#include "singlelink.hpp"
#include <chrono>
#include <fstream>




typedef cstd::array_dynamic_container<int> container_int;


class cordinate {
    
    int x;
    int y;
    int z;
    
public:
    
    cordinate (int x, int y, int z) : x(x) , y(y) , z(z) {}
    
    void print_cord () const {std::cout << x << "," << y << "," << z << std::endl;}
    
//    std::string get_cord () {}
    
}; // end of class


typedef cordinate cordinate_point;


void test_function (int i, container_int *container) {
    
    container->append(i);
}


std::random_device rd;                                           // obtain a random number from hardware
std::mt19937 gen(rd());                                      // seed the generator

// returns the final step count using an recursive aproach
int step_core_recursive (size_t n) {                                 // (que, step count)
    
    std::uniform_int_distribution<> distr(1, std::numeric_limits<int>::max());             // define the range
    
    int T = (distr(gen) % 2);
    
    if (T != 0) T = -1;
    else T = 1;
    
    if (n == 1) return 1;
    
    else return T + step_core_recursive(n-1);
}

// returns final value step count using iterative aproach
int step_core (size_t n) {
    
    int result = 0;
    
    std::uniform_int_distribution<> distr(1, std::numeric_limits<int>::max());             // define the range
    
    for (size_t i = 0; i < n; i++) {
        
        int T = (distr(gen) % 2);
        
        if (T != 0) T += -1;
        else T += 1;
            
        result += T;
    }
    
    return result;
}


// will add the final value to the que
void step (size_t n, container_int *que) {que->append(step_core(n));}


void trial_fill(size_t trials,size_t steps,container_int *que) {
    
    for (size_t i = 0; i < trials; i++) {
        
        step(steps, que);
    }
}

void trial_fill_threads(size_t trials, size_t steps, container_int *que, bool thread_per_trial) {
    
    for (size_t i = 0; i < trials; i++) {
        
        
        
        
    }
    
}

const cordinate_point* cord (const container_int *que1, const container_int *que2, const container_int *que3,size_t n) {
    
    auto *cord1 = new const cordinate_point((*que1)[n],(*que2)[n],(*que3)[n]);
    
    return cord1;
}

typedef std::chrono::time_point<std::chrono::system_clock> timer_object;


void step_lab (size_t steps, size_t trials, size_t steps1, size_t trials1) {
    
    
    timer_object start0, end0;              // timer object for time for threads to complete

    // containers for each dimension
    auto *data1 = new container_int;                // 1st dimension
    auto *data2 = new container_int;                // 2nd dimension
    auto *data3 = new container_int;                // 3rd dimension
        
    start0 = std::chrono::system_clock::now();                          // start timer before threads created
    
    // creat thread obejcts to fill que with final values
    std::thread thread1(trial_fill,trials,steps,data1);
    std::thread thread2(trial_fill,trials,steps,data2);
    std::thread thread3(trial_fill,trials,steps,data3);
    
    // wait til the threads completed
    thread1.join();
    thread2.join();
    thread3.join();
    
    end0 = std::chrono::system_clock::now();                        // end time once all threads are completed
    
    std::chrono::duration<double> elapsed_seconds0 = end0 - start0;                                  // calculate time elapsed
    std::cout << "all threads completed, trials:" << trials << "  elapsed time: " << elapsed_seconds0.count() << "s\n";  // print time elapsed
    
    
    
    
    //section for not using threads
    timer_object start2, end2;              // timer object for time for threads to complete

    // containers for each dimension
    auto *data4 = new container_int;                // 1st dimension
    auto *data5 = new container_int;                // 2nd dimension
    auto *data6 = new container_int;                // 3rd dimension
    
    start2 = std::chrono::system_clock::now();                          // start timer before threads created
    
    trial_fill(trials1,steps1,data4);
    trial_fill(trials1,steps1,data5);
    trial_fill(trials1,steps1,data6);
    
    end2 = std::chrono::system_clock::now();                        // end time once all threads are completed
    
    std::chrono::duration<double> elapsed_seconds2 = end2 - start2;                                  // calculate time elapsed
    std::cout << "all functions completed, trials:" << trials << "  elapsed time: " << elapsed_seconds2.count() << "s\n";  // prin
    
    
    
    
    timer_object start1, end1;              // timer object for time for cordinate instantiation and linked list appending
    
    start1 = std::chrono::system_clock::now();      // start timer
    
    // buffer to store node type
    auto *buffer = new node_container::single::slist<node_container::node<const cordinate_point*>>;
    
    for (size_t i = 0; i < trials; i++) {
        
        // these are to use when calling the fucniton to create cordinate objects
        const cordinate_point* cordinate_object = cord(data1, data2, data3,i);
        node_container::node<const cordinate_point*> Node(cordinate_object);
        
        // these are when to not call fucniton, for use
//        auto *cordinate_object = new const cordinate_point((*data1)[i],(*data2)[i],(*data3)[i]);
//        node_container::node<const cordinate_point*> Node(cordinate_object);
//
        buffer->add(Node);              // to add created node to node linked single container
    }
    
    end1 = std::chrono::system_clock::now();            // end timer
    
    std::chrono::duration<double> elapsed_seconds1 = end1 - start1;                              // calculates the time elapsed
    std::cout << "cordnites created and added to bufefr, elapsed time: " << elapsed_seconds1.count() << "s\n";   // time elapsed
    
    buffer->ret_value_first().data->print_cord();
    
    // for printing data from linked list
    // create file stream object
    // stream linked list data to csv file
    
    std::fstream file;
    file.open("steplab.txt",std::ios::app);
    
//    for (size_t i = 0; i < trials; i++) {buffer->ret_value_index(i).data->}
    
/*
    use of threads on both a step and per trial basis for evaluaiton
 
    
 
 
 
 
 */
    
    

    
// this section for use with testing and crodinate object instantioation per line
    // creates cord objects from a que and the index of it
    
    std::cout << std::endl << std::endl << "wthout using the sinlge linked node container\n";
    const cordinate_point* cord1 = cord(data1,data2,data3,0);
    const cordinate_point* cord2 = cord(data1,data2,data3,1);
    const cordinate_point* cord3 = cord(data1,data2,data3,3);
    
    // for outputting que data
    for (size_t i = 0;  i < 10; i++) std::cout << (*data1)[i];
    std::cout << std::endl;
    for (size_t i = 0;  i < 10; i++) std::cout << (*data2)[i];
    std::cout << std::endl;
    for (size_t i = 0;  i < 10; i++) std::cout << (*data3)[i];
    std::cout << std::endl;
    
    // to print cord point
    cord1->print_cord();
    cord2->print_cord();
    cord3->print_cord();
}

