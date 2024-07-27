#include "../exercise.h"

constexpr unsigned long long fibonacci(int i) {
    switch (i) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return fibonacci(i - 1) + fibonacci(i - 2);
    }
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 90;
    constexpr auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
//constexpr 是一个强大的工具，可以用于定义在编译时计算的常量表达式，从而提高程序的效率。
//它可以用于变量和函数，使得常量表达式的计算在编译时进行，减少运行时的开销。
//auto 是 C++11 引入的关键字，用于自动推导变量的类型。它可以根据初始化表达式的类型自动确定变量的类型，这使得代码更简洁和易于维护。