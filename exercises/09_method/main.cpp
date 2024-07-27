#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        for (cached; cached<=i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    fib.cache[0]=0;
    fib.cache[1]=1;
    fib.cached=2;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
/*在 C++ 中，静态成员变量在类的所有实例中共享，并且只有一个副本。
它们在类声明中进行声明，但不能在类声明中定义和初始化。
这是因为静态成员变量的实际存储位置必须在全局范围内分配，而不是在类的实例中分配。*/
/*作用域解析运算符的作用
静态成员变量初始化：

在类或结构体外部定义和初始化静态成员变量时，需要使用作用域解析运算符 :: 来指定该静态成员变量属于哪个类或结构体。
例如，int Fibonacci::cached = 0; 表示静态成员变量 cached 属于 Fibonacci 类，并将其初始化为 0。
访问类的静态成员：

作用域解析运算符还可以用于访问类的静态成员，例如 ClassName::staticMember。
例如，可以通过 Fibonacci::cached 来访问或修改 cached 静态成员变量。
访问命名空间中的成员：

用于指定某个成员属于哪个命名空间。例如，std::cout 表示 cout 属于标准命名空间 std。*/
