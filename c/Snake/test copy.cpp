#include<conio.h>
#include<iostream>
 
using namespace std;
 
int main()
{
    while(!kbhit()) //当没有键按下
    {
            cout << "无键按下" << endl;
    }
        cout << "有键按下" << endl;
        system("pause");
        return 0;
}