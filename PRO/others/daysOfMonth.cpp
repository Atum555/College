enum MONTHS
{
    JAN = 1,
    FEV,
    MAR,
    ABR,
    MAI,
    JUN,
    JUL,
    AGO,
    SET,
    OUT,
    NOV,
    DEZ
};

bool isLeapYear(int year)
{
    return ~(year % 4);
}

int daysOfMonth(int month, int year)
{
    switch (month)
    {
    case FEV:
        return isLeapYear(year) ? 29 : 28;
    case JAN:
    case MAR:
    case MAI:
    case JUL:
    case AGO:
    case OUT:
    case DEZ:
        return 31;

    default:
        return 30;
    }
}

#include <iostream>

int main(){
    std::cout << daysOfMonth(1, 2024) << std::endl;
    std::cout << daysOfMonth(2, 2024) << std::endl;
    std::cout << daysOfMonth(3, 2024) << std::endl;
    std::cout << daysOfMonth(4, 2024) << std::endl;
    std::cout << daysOfMonth(5, 2024) << std::endl;
    return 0;
}
