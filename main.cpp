#include "header.hpp"
void foo1() {
    std::cout << 1 << std::endl;
}
void foo2() {
    std::cout << 2 << std::endl;
}
void foo3() {
    std::cout << 3 << std::endl;
}
void foo4() {
    std::cout << 4 << std::endl;
}
void foo5() {
    std::cout << 5 << std::endl;
}
void foo6() {
    std::cout << 6 << std::endl;
}
void foo7() {
    std::cout << 7 << std::endl;
}
void foo8() {
    std::cout << 8 << std::endl;
}
void foo9() {
    std::cout << 9 << std::endl;
}


int main(){
    ThreadPool threadpool;
    threadpool.push_task(foo1);
    threadpool.push_task(foo2);
    threadpool.push_task(foo3);
    threadpool.push_task(foo4);
    threadpool.push_task(foo5);
    threadpool.push_task(foo6);
    threadpool.push_task(foo7);
    threadpool.push_task(foo8);
    threadpool.push_task(foo9);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
    threadpool.end_wark();
     std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
    return 0;
}