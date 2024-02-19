#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int r = 0;
        if (i % 3 == 0)
            r += 1;
        if (i % 5 == 0)
            r += 2;

        switch (r)
        {
        case 0:
            std::cout << i << " ";
            break;
        case 1:
            std::cout << "Fizz ";
            break;
        case 2:
            std::cout << "Buzz ";
            break;
        }
    }
    return 0;
}