#include "../include/koishi.hpp"
extern LEVEL getlevel();
int main(){
    std::string level[4] = {"easy", "normal", "hard", "extreme"};
    LEVEL l;
    l = getlevel();
    while (  l < 1  ||  l > 4  ){
        std::cout << "the number you input(" << l << ") is not listed" << std::endl << 
        "please input again:" << std::ends << std::endl;
        l = getlevel();
    }
    std::cout << "you choose " << l << " " << level[l-1] << std::endl;
    return 0;
}