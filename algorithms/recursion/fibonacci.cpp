#include <iostream>
#include <cstring>
#define MAX_N 1000
int memo[MAX_N];

int fibonacciNumbers(int num)
{
    if (num == 2 || num == 1)
    {
        return 1;
    }
    else if (num == 0)
    {
        return 0;
    }

    return fibonacciNumbers(num - 1) + fibonacciNumbers(num - 2);
}

int fibonacciForLoop(int num)
{
    int a = 0, b = 1, next;
    for (int i = 0; i < num + 1; i++)
    {
        if (i <= 1)
        {
            next = i;
        }
        else
        {
            next = a + b;
            a = b;
            b = next;
        }
    }
    return next;
}

int fibonacciNumbersMemoized(int num)
{
    if (num == 2 || num == 1)
    {
        return 1;
    }
    else if (num == 0)
    {
        return 0;
    }

    if (memo[num] != -1)
    {
        return memo[num];
    }

    // Calculate and store the result
    memo[num] = fibonacciNumbers(num - 1) + fibonacciNumbers(num - 2);
    return memo[num];
}

int main()
{
    std::cout << "Enter the number: ";
    int number = 0;

    std::cin >> number;
    memset(memo, -1, sizeof(memo));

    std::cout << "Fibonnaci number for " << number << " is " << fibonacciNumbers(number);
    std::cout << std::endl;
    std::cout << "Fibonnaci number for " << number << " is " << fibonacciForLoop(number);
    std::cout << std::endl;
    std::cout << "Fibonnaci number for " << number << " is " << fibonacciNumbersMemoized(number);
    std::cout << std::endl;
    return 0;
}
