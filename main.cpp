#include <QCoreApplication>
#include <iostream>
#include "Stack.h"
#include "Exception.cpp"

int main()
{

    try
    {
        Stack Bandana;
        std::cout<<"Razmer: "<<Bandana.getSize()<< std::endl;
        Bandana.topFunc();

    }
    catch (const exep_stack::EStackEmpty & e) //исключение - пустой стек
    {
        std::cout<< e.what();
    }

//          std::cout<<"Razmer: "<<Bandana.getSize()<< std::endl;
//          Bandana.push(3);
//          std::cout<<"Razmer: "<<Bandana.getSize()<< std::endl;
//          std::cout<<"Top: "<<Bandana.topFunc()<< std::endl;
//          std::cout<<"-----------------------------------"<< std::endl;
//          Bandana.push(5);
//          std::cout<<"Razmer: "<<Bandana.getSize()<< std::endl;
//          std::cout<<"Top: "<<Bandana.topFunc()<< std::endl;
//          std::cout<<"-----------------------------------"<< std::endl;
//          Bandana.push(9);
//          std::cout<<"Razmer: "<<Bandana.getSize()<< std::endl;
//          std::cout<<"Top: "<<Bandana.topFunc()<< std::endl;
//          std::cout<<"-----------------------------------"<< std::endl;
//          Bandana.push(2);
//          std::cout<<"Razmer: "<<Bandana.getSize()<< std::endl;
//          std::cout<<"Top: "<<Bandana.topFunc()<< std::endl;
//          std::cout<<"-----------------------------------"<< std::endl;
//          Bandana.pop();
//          std::cout<<"Razmer: "<<Bandana.getSize()<< std::endl;
//          std::cout<<"Top: "<<Bandana.topFunc()<< std::endl;
//          std::cout<<"-----------------------------------"<< std::endl;


    return 0;
}
