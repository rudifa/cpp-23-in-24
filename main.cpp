//
//  main.cpp
//  cpp-23-in-24
//
//  Created by Rudolf Farkas on 12.12.2024.
//

#include <iostream>
#include <expected>
#include <string>
#include <optional>

// Function that returns an optional int
std::optional<int> find_value(int key)
{
    if (key == 42)
    {
        return 42;
    }
    return std::nullopt;
}

void demo_optional(int key)
{
    auto result = find_value(key);
    if (result.has_value())
    {
        std::cout << "Found value: " << *result << std::endl;
    }
    else
    {
        std::cout << "Value not found for key: " << key << std::endl;
    }
    std::cout << std::endl;
}

// A function that might fail
std::expected<int, std::string> divide(int a, int b)
{
    if (b == 0)
    {
        return std::unexpected("Division by zero");
    }
    return a / b;
}

void demo_divide(int a, int b)
{
    auto result = divide(a, b);
    if (result)
    {
        std::cout << a << " / " << b << " = " << *result << std::endl;
    }
    else
    {
        std::cout << "Error: " << result.error() << std::endl;
    }
    std::cout << std::endl;
}

int main(int, const char *[])
{
    std::cout << "Hello, World!\n"
              << std::endl;
    ;

    // Example usage of std::expected
    demo_divide(10, 2);
    demo_divide(10, 0);

    // Example usage of std::optional
    demo_optional(42);
    demo_optional(7);

    return 0;
}
