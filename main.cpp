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
#include <charconv>

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
}

// Function that returns an optional expected
std::optional<std::expected<int, std::string>> parse_int(const std::optional<std::string> &input)
{
    if (!input.has_value())
    {
        return std::nullopt;
    }

    int result;
    auto [ptr, ec] = std::from_chars(input->data(), input->data() + input->size(), result);

    if (ec == std::errc())
    {
        return std::expected<int, std::string>(result);
    }
    else
    {
        return std::expected<int, std::string>(std::unexpected("Parsing failed"));
    }
}

void demo_optional_expected(const std::optional<std::string> &input)
{
    auto result = parse_int(input);

    if (!result.has_value())
    {
        std::cout << "No input provided" << std::endl;
    }
    else if (result.value())
    {
        std::cout << "Parsed value: " << *result.value() << std::endl;
    }
    else
    {
        std::cout << "Error: " << result.value().error() << std::endl;
    }
}

int main(int, const char *[])
{
    std::cout << "Hello, World!\n"
              << std::endl;

    std::cout << "Example usage of std::expected:\n"
              << std::endl;

    demo_divide(10, 2);
    demo_divide(10, 0);

    std::cout << std::endl;

    std::cout << "Example usage of std::optional:\n"
              << std::endl;

    demo_optional(42);
    demo_optional(7);

    std::cout << std::endl;

    std::cout << "Example usage of std::optional std::expected:\n"
              << std::endl;

    demo_optional_expected(std::nullopt);
    demo_optional_expected("42");
    demo_optional_expected("not a number");

    std::cout << std::endl;

    return 0;
}
