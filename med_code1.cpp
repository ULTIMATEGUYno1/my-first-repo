#include <iostream>
#include <functional>

int main() {
    // Define a lambda function that takes two integers and returns their sum
    auto sumFunction = [](int a, int b) {
        return a + b;
    };

    // Store the lambda function in a std::function variable
    std::function<int(int, int)> customFunction = sumFunction;

    // Now you can use customFunction like any other function
    int result = customFunction(3, 5);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
