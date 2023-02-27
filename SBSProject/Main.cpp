#include <iostream>
#include <fstream>
#include <string>
#include "Idle.cpp"

using namespace std;

int main11()
{
    system("mode con:cols=203 lines=65");

    Idle temp = Idle();
    temp.JustPrint();

    return 0;
}