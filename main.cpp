#include <QCoreApplication>
#include <iostream>
#include "Stack.h"
#include "PersonKeeper.h"

int main()
{

    try
    {
        int test_tindex=0;
        std:: cout << "input test number" << std::endl;
        std::cin >> test_tindex;

        switch (test_tindex)
        {
        case 1:
        {
            // Тестирование 1. Мы не можем открыть файл на чтение (Его нет)
            std::fstream File; // Открываем файл
            File.open("0input.txt", std::ios_base::in); // Открываем его на чтение
            Stack<Person> Persons = PersonKeeper::instance().readPersons(File); // Считываем
            std::fstream File1; // Открываем файл1
            File1.open("output.txt", std::ios_base::out); // Открываем его на запись
            PersonKeeper::instance().writePersons(Persons, File1); // Записываем
            break;
        }

        case 2:
        {
            // Тестирование 2. Всё впорядке, мы вводим данные разных форматов.
            std::fstream File; // Открываем файл
            File.open("input.txt", std::ios_base::in); // Открываем его на чтение
            Stack<Person> Persons = PersonKeeper::instance().readPersons(File); // Считываем
            std::fstream File1; // Открываем файл1
            File1.open("output.txt", std::ios_base::out); // Открываем его на запись
            PersonKeeper::instance().writePersons(Persons, File1); // Записываем
            break;

        }
        }
    }
    catch (const exep_stack::EStackEmpty & e) // Исключение - пустой стек
    {
        std::cout<< e.what();
    }

    return 0;
}
