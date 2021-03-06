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
            // Появляется ошибка сообщающая о проблеме чтения, такого файла нет. (Ошибка)
        }

        case 2:
        {
            // Тестирование 2. Файл существует, но файл пустой.
            std::fstream File; // Открываем файл
            File.open("empty.txt", std::ios_base::in); // Открываем его на чтение
            Stack<Person> Persons = PersonKeeper::instance().readPersons(File); // Считываем
            std::fstream File1; // Открываем файл1
            File1.open("output.txt", std::ios_base::out); // Открываем его на запись
            PersonKeeper::instance().writePersons(Persons, File1); // Записываем
            break;
            // На выходе получаем пустой файл "output.txt" (Рабочий вариант)
        }

        case 3:
        {
            // Тестирование 3. Файл существует, данные введены корректно.
            std::fstream File; // Открываем файл
            File.open("normal.txt", std::ios_base::in); // Открываем его на чтение
            Stack<Person> Persons = PersonKeeper::instance().readPersons(File); // Считываем
            std::fstream File1; // Открываем файл1
            File1.open("output.txt", std::ios_base::out); // Открываем его на запись
            PersonKeeper::instance().writePersons(Persons, File1); // Записываем
            break;
            // На выходе получаем файл "output.txt" с корректно переписанными ФИО (Рабочий вариант)
        }

        case 4:
        {
            // Тестирование 4. Файл существует, но введено больше данных, чем 3 (ФИО состоит из 3)
            std::fstream File; // Открываем файл
            File.open("4item.txt", std::ios_base::in); // Открываем его на чтение
            Stack<Person> Persons = PersonKeeper::instance().readPersons(File); // Считываем
            std::fstream File1; // Открываем файл1
            File1.open("output.txt", std::ios_base::out); // Открываем его на запись
            PersonKeeper::instance().writePersons(Persons, File1); // Записываем
            break;
            // На выходе получаем файл "output.txt" с корректно переписанными ФИО, лишнее данные записываться не будут. (Рабочий вариант)
        }

        case 5:
        {
            // Тестирование 5. Файл существует, но некоторые данные введены через запятую
            std::fstream File; // Открываем файл
            File.open("commas.txt", std::ios_base::in); // Открываем его на чтение
            Stack<Person> Persons = PersonKeeper::instance().readPersons(File); // Считываем
            std::fstream File1; // Открываем файл1
            File1.open("output.txt", std::ios_base::out); // Открываем его на запись
            PersonKeeper::instance().writePersons(Persons, File1); // Записываем
            break;
            // На выходе получаем файл "output.txt" с корректно переписанными ФИО, данные записанные через запятую не будут записываться. (Рабочий вариант)
        }

        case 6:
        {
            // Тестирование 6. Файл существует, но некоторые данные введены с некорректными символами
            std::fstream File; // Открываем файл
            File.open("num-sym.txt", std::ios_base::in); // Открываем его на чтение
            Stack<Person> Persons = PersonKeeper::instance().readPersons(File); // Считываем
            std::fstream File1; // Открываем файл1
            File1.open("output.txt", std::ios_base::out); // Открываем его на запись
            PersonKeeper::instance().writePersons(Persons, File1); // Записываем
            break;
            // На выходе получаем файл "output.txt" с корректно переписанными ФИО, данные с некорректными символами записываться не будут. (Рабочий вариант)
        }
        }
    }
    catch (const exep_stack::EStackEmpty & e) // Исключение - пустой стек
    {
        std::cout<< e.what();
    }

    return 0;
}
