#include "../include/koishi.hpp"
LEVEL getlevel()
{
    short int l;
    std::cout << "please input the level number:" << std::endl
              << "1.easy" << std::endl
              << "2.normal" << std::endl
              << "3.hard" << std::endl
              << "4.extreme" << std::endl;
    std::cin >> l;
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    return (LEVEL)l;
}