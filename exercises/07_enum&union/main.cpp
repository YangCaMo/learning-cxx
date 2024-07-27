#include "../exercise.h"
//类型双关
// READ: 枚举类型 <https://zh.cppreference.com/w/cpp/language/enum>

// `enum` 是 C 的兼容类型，本质上其对应类型的常量。
// 在 `enum` 中定义标识符等价于定义 constexpr 常量，
// 这些标识符不需要前缀，可以直接引用。
// 因此 `enum` 定义会污染命名空间。
enum ColorEnum : unsigned char {
    COLOR_RED = 31,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_BLUE,
};

// 有作用域枚举型是 C++ 引入的类型安全枚举。
// 其内部标识符需要带前缀引用，如 `Color::Red`。
// 作用域枚举型可以避免命名空间污染，并提供类型安全保证。
enum class Color : int {//枚举值 Red、Green、Yellow 和 Blue 对应 ColorEnum 中定义的值。
    Red = COLOR_RED,
    Green,
    Yellow,
    Blue,
};

ColorEnum convert_by_pun(Color c) {
    // READ: <https://zh.cppreference.com/w/cpp/language/union>
    // `union` 表示在同一内存位置存储的不同类型的值。
    // 其常见用法是实现类型双关转换，即将一种类型的值转换为另一种无关类型的值。
    // 但这种写法实际上仅在 C 语言良定义，在 C++ 中是未定义行为。
    // 这是比较少见的 C++ 不与 C 保持兼容的特性。
    // READ: 类型双关 <https://tttapa.github.io/Pages/Programming/Cpp/Practices/type-punning.html>
    union TypePun {
        ColorEnum e;
        Color c;
    };

    TypePun pun;
    // TODO: 补全类型双关转换
    pun.c=c;
    return pun.e;
}

int main(int argc, char **argv) {
    ASSERT(convert_by_pun(Color::Red) == COLOR_RED, "Type punning conversion");
    ASSERT(convert_by_pun(Color::Green) == COLOR_GREEN, "Type punning conversion");
    ASSERT(convert_by_pun(Color::Yellow) == COLOR_YELLOW, "Type punning conversion");
    ASSERT(convert_by_pun(Color::Blue) == COLOR_BLUE, "Type punning conversion");
    return 0;
}
/*有作用域的枚举类型（enum class 或 enum struct）
通过将枚举值限定在枚举类型的作用域内，解决了上述问题。
枚举值只能通过其枚举类型的名称和作用域限定符（::）访问，
因此不会污染外部作用域。*/
/*在上面的代码中，虽然 ColorEnum 的底层类型是 unsigned char，
但枚举值 COLOR_RED 被初始化为 31，这是合法的，因为 31 在 unsigned char 的范围（0-255）内。
枚举值 COLOR_GREEN、COLOR_YELLOW 和 COLOR_BLUE 自动递增，
并且它们的值也在 unsigned char 的范围内。*/
/*定义了一个名为 TypePun 的联合体，其中包含两个成员：e 和 c。这两个成员分别是 ColorEnum 类型和 Color 类型。
详细说明
内存共享：
union 中的所有成员共享同一块内存。ColorEnum e 和 Color c 共享相同的内存位置，
因此在任意时刻只能有一个成员存储有效值。
内存布局：
union 的大小等于其最大成员的大小。即使 ColorEnum 和 Color 的大小不同，union 的大小也将是两者中较大的那个。
存储某个成员会覆盖其他成员的值。
用途：
可以用于类型转换或内存优化。例如，当你需要在不同类型之间进行二进制转换时，union 可以提供便捷的方法。*/