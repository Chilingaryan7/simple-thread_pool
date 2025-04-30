#include "header.hpp"

template <int num> 
void foo() {
    std::cout << num << std::endl;
}

int main(){
    ThreadPool threadpool;

    threadpool.push_task(&foo<1>);
    threadpool.push_task(&foo<2>);
    threadpool.push_task(&foo<3>);
    threadpool.push_task(&foo<4>);
    threadpool.push_task(&foo<5>);
    threadpool.push_task(&foo<6>);
    threadpool.push_task(&foo<7>);
    threadpool.push_task(&foo<8>);
    threadpool.push_task(&foo<9>);
      
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); 

    threadpool.end_wark();

     std::this_thread::sleep_for(std::chrono::milliseconds(100)); 

    return 0;
}
