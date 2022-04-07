#include <QCoreApplication>
#include <iostream>
#include "Stack.h"

int main()
{

    try
    {
        Stack<int> massiv;
        std::cout<<"Razmer: "<<massiv.getSize()<< std::endl;
        //std::cout<<"Top: "<<massiv.topFunc()<< std::endl; // Вызов top в пустом стеке для проверки
        //massiv.pop(); // Вызов pop в пустом стеке для проверки
        massiv.push(3);
        std::cout<<"Razmer: "<<massiv.getSize()<< std::endl;
        std::cout<<"Top: "<<massiv.topFunc()<< std::endl;
        std::cout<<"-----------------------------------"<< std::endl;
        massiv.push(5);
        std::cout<<"Razmer: "<<massiv.getSize()<< std::endl;
        std::cout<<"Top: "<<massiv.topFunc()<< std::endl;
        std::cout<<"-----------------------------------"<< std::endl;
        massiv.push(9);
        std::cout<<"Razmer: "<<massiv.getSize()<< std::endl;
        std::cout<<"Top: "<<massiv.topFunc()<< std::endl;
        std::cout<<"-----------------------------------"<< std::endl;
        massiv.push(2);
        std::cout<<"Razmer: "<<massiv.getSize()<< std::endl;
        std::cout<<"Top: "<<massiv.topFunc()<< std::endl;
        std::cout<<"-----------------------------------"<< std::endl;
        massiv.pop();
        std::cout<<"Razmer: "<<massiv.getSize()<< std::endl;
        std::cout<<"Top: "<<massiv.topFunc()<< std::endl;
        std::cout<<"-----------------------------------"<< std::endl;
    }
    catch (const exep_stack::EStackEmpty & e) //исключение - пустой стек
    {
        std::cout<< e.what();
    }

    return 0;
}
