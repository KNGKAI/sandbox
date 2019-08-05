#include <iostream>
#include "list.h"

int main(int ac, char ** av)
{
    List<int> list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    for (int i = 0; i < list.lenght(); i++)
    {
        std::cout << std::to_string(i) << ": " << std::to_string(list.get(i)) << std::endl;
    }
    
    return (0);
}