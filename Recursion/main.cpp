#include <iostream>

long double factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    std::cout << factorial(1) << '\n';
}
