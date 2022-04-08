#include "PersonKeeper.h"
#include "person.h"

PersonKeeper& PersonKeeper::instance()
{
    static PersonKeeper keeper;
    return keeper;
}

void PersonKeeper::writePersons(Stack<Person> stack, std::fstream& ofile)
{
    if (!ofile) // Если файл не открылся
    {
            throw std::runtime_error("Error writing file. File not found\n"); // Выбрасываем исключение
    }

    for (unsigned i = 0; i < stack.getSize(); i++) // Идём по элементам стэка
    {
            ofile << stack[i].getLastName(); // Выводим в файл Фамилию
            ofile << ' ';
            ofile << stack[i].getFirstName(); // Выводим в файл Имя
            ofile << ' ';
            ofile << stack[i].getPatronymic();// Выводим в файл Отчество
            ofile << '\n';
    }
}

Stack<Person> PersonKeeper::readPersons(std::fstream& ifile)
{
    if (!ifile) // Если файл не открылся
    {
            throw std::runtime_error("File not found\n"); // Выбрасываем исключение
    }

    Stack<Person> stack;
    std::string string_;

    while (std::getline(ifile, string_)) // Пока мы можем брать строку из файла
    {
        stack.push(Person(string_)); // Кладём в Стек персону
    }

    return stack;
}
