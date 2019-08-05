#include <iostream>
#include "list.h"
#include "sandbox.h"

int main(int ac, char ** av)
{
    List<char> list;
    char a[6] = {6, 7, 8, 9, 10, 11};

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    for (int i = 0; i < list.length(); i++)
    {
        std::cout << std::to_string(i) << ": " << std::to_string(list.get(i)) << std::endl;
    }
    list.remove(2);
    list.remove(1);
    std::cout << list.to_string();
    return (0);
}