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

/**
 * @brief Searches for a specific value based on a given key.
 *
 * This function checks if the provided key matches a predefined value (42).
 * If there's a match, it returns the corresponding value; otherwise, it returns std::nullopt.
 *
 * @param key The integer key to search for.
 *
 * @return An std::optional<int> which contains:
 *         - The integer value 42 if the key matches.
 *         - std::nullopt if no matching value is found for the given key.
 */
std::optional<int> find_value(int key)
{
    if (key == 42)
    {
        return 42;
    }
    return std::nullopt;
}

/**
 * @brief Demonstrates the usage of std::optional by attempting to find a value for a given key.
 *
 * This function calls find_value(key) and prints whether a value was found or not.
 * It showcases how to check and access the value of an std::optional.
 *
 * @param key The key to search for in the find_value function.
 *
 * @return This function doesn't return a value, but prints either:
 *         - The found value if it exists.
 *         - A message indicating that no value was found for the given key.
 */
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

/**
 * @brief Performs integer division and handles potential division by zero.
 *
 * This function attempts to divide two integers and returns the result.
 * If the denominator is zero, it returns an error instead.
 *
 * @param a The numerator for the division operation.
 * @param b The denominator for the division operation.
 *
 * @return An expected containing either:
 *         - The result of the division if successful.
 *         - An error message "Division by zero" if b is 0.
 */
std::expected<int, std::string> divide(int a, int b)
{
    if (b == 0)
    {
        return std::unexpected("Division by zero");
    }
    return a / b;
}

/**
 * @brief Demonstrates the usage of the divide function and handles its result.
 *
 * This function attempts to divide two integers and prints the result or an error message.
 * It showcases error handling with std::expected.
 *
 * @param a The numerator for the division operation.
 * @param b The denominator for the division operation.
 *
 * @return This function doesn't return a value, but prints either:
 *         - The result of the division if successful.
 *         - An error message if the division fails (e.g., division by zero).
 */
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

/**
 * @brief Attempts to parse an optional string into an integer.
 *
 * This function takes an optional string input and tries to convert it to an integer.
 * It handles three possible scenarios:
 * 1. No input provided (nullopt)
 * 2. Successful parsing of the string to an integer
 * 3. Parsing failure
 *
 * @param input An optional string that may contain an integer value.
 *
 * @return An optional containing an expected integer value.
 *         - If input is nullopt, returns nullopt.
 *         - If parsing succeeds, returns an expected containing the parsed integer.
 *         - If parsing fails, returns an expected containing an error message.
 */
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

/**
 * @brief Demonstrates the usage of std::optional and std::expected together.
 *
 * This function attempts to parse an optional string input into an integer,
 * showcasing error handling with both std::optional and std::expected.
 *
 * @param input An optional string that may contain an integer value.
 *
 * @return This function doesn't return a value, but prints the result of the parsing operation:
 *         - "No input provided" if the input is empty (std::nullopt).
 *         - The parsed integer value if parsing is successful.
 *         - An error message if parsing fails.
 */
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

/**
 * @brief The main entry point of the program.
 *
 * This function initializes the program, runs example usage of std::expected, std::optional, and std::optional std::expected,
 * and then exits.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 *
 * @return 0 if the program runs successfully, otherwise an error code.
 */
int main(int argc, const char *argv[])
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
