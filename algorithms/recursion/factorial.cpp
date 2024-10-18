#include <iostream>

long long factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }

    return num * factorial(num - 1);
}

int main()
{
    long long number = 0;

    std::cout << "Enter the number for factorial\n";
    std::cin >> number;

    std::cout << "The factorial of number " << number << " is " << factorial(number);
    std::cout << std::endl;
    return 0;
}