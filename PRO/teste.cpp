#include <iostream>

int main()
{
    int a = 2;
    int b = 0;
    switch (a)
    {
    case 2:
    x:
        b++;
    case 3:
        b++;
        goto x;
        break;
    
    default:
        b = 7;
    }
    std::cout << b << std::endl;
    return 0;
}