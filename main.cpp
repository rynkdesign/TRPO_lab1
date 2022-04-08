#include <QCoreApplication>
#include <iostream>
#include "Stack.h"
#include "PersonKeeper.h"

int main()
{

    try
    {
        std::fstream File; // Открываем файл
        File.open("input.txt", std::ios_base::in); // Открываем его на чтение
        Stack<Person> Persons = PersonKeeper::instance().readPersons(File); // Считываем
        std::fstream File1; // Открываем файл1
        File1.open("output.txt", std::ios_base::out); // Открываем его на запись
        PersonKeeper::instance().writePersons(Persons, File1); // Записываем

    }
    catch (const exep_stack::EStackEmpty & e) // Исключение - пустой стек
    {
        std::cout<< e.what();
    }

    return 0;
}
