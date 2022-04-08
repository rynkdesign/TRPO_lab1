#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#include "person.h"
#include "Stack.h"
#include <fstream>

class PersonKeeper // Класс для чтения/записи Стека из Person, реализован в соответствии с шаблоном Singleton.
{
public:
    static PersonKeeper& instance();
    Stack<Person> readPersons(std::fstream& ifile); // Считывает ФИО из файла в Стек
    void writePersons(Stack<Person> stack, std::fstream& ofile); // Записывает из Стека в файл
private:
    PersonKeeper() = default; // Конструктор
    PersonKeeper(const PersonKeeper& other); // Конструктор копирования
    ~PersonKeeper() = default; // Деструктор

};

#endif // PERSONKEEPER_H
