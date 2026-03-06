#include <iostream>
#include <cstdlib>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    // ========== Subject's test ==========
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    // ========== Additional tests ==========

    std::cout << "\n=== Empty array ===" << std::endl;
    Array<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;
    try
    {
        std::cout << empty[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Int array of 5 ===" << std::endl;
    Array<int> intArr(5);
    std::cout << "Size: " << intArr.size() << std::endl;
    std::cout << "Default values: ";
    for (unsigned int i = 0; i < intArr.size(); i++)
        std::cout << intArr[i] << " ";
    std::cout << std::endl;

    for (unsigned int i = 0; i < intArr.size(); i++)
        intArr[i] = (i + 1) * 10;
    std::cout << "After assignment: ";
    for (unsigned int i = 0; i < intArr.size(); i++)
        std::cout << intArr[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Copy constructor ===" << std::endl;
    Array<int> copy(intArr);
    std::cout << "Copy: ";
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

    copy[0] = 999;
    std::cout << "After modifying copy[0] = 999:" << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;
    std::cout << "Original[0]: " << intArr[0] << std::endl;

    std::cout << "\n=== Assignment operator ===" << std::endl;
    Array<int> assigned;
    assigned = intArr;
    std::cout << "Assigned: ";
    for (unsigned int i = 0; i < assigned.size(); i++)
        std::cout << assigned[i] << " ";
    std::cout << std::endl;

    assigned[0] = 777;
    std::cout << "After modifying assigned[0] = 777:" << std::endl;
    std::cout << "Assigned[0]: " << assigned[0] << std::endl;
    std::cout << "Original[0]: " << intArr[0] << std::endl;

    std::cout << "\n=== Out of bounds ===" << std::endl;
    try
    {
        std::cout << intArr[42] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== String array ===" << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "hello";
    strArr[1] = "world";
    strArr[2] = "42";
    for (unsigned int i = 0; i < strArr.size(); i++)
        std::cout << strArr[i] << " ";
    std::cout << std::endl;

    return 0;
}
