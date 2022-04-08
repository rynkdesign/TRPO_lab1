#include "person.h"

Person::Person(const Person& other) // Конструктор копирования
{
    last_name = other.last_name;
    first_name = other.first_name;
    patronymic = other.patronymic;
}

Person::Person(const std::string& full_name) // Конструктор копирования строки
{
    unsigned i = 0;
    for (;i < full_name.size(); i++) // Идем по строке
    {
        if (full_name[i] == ' ') // Если встречаем пробел
            break; // Выходим из цикла
        last_name.push_back(full_name[i]); // Записываем в Фамилию
    }

    for (i++ ;i < full_name.size(); i++) // Идём дальше по строке
    {
        if (full_name[i] == ' ') // Если встречаем пробел
            break; // Выходим из цикла
        first_name.push_back(full_name[i]); // Записываем в Имя
    }

    for (i++;i < full_name.size(); i++) // Все остальное записываем в Отчество
    {
        patronymic.push_back(full_name[i]);
    }
}

const std::string& Person::getFirstName() const
{
    return first_name;
}

const std::string& Person::getLastName() const
{
    return last_name;
}

const std::string& Person::getPatronymic() const
{
    return patronymic;
}


void Person::setFirstName(const std::string& first_name_)
{
    first_name = first_name_;
}

void Person::setLastName(const std::string& last_name_)
{
    last_name = last_name_;
}

void Person::setPatronymic(const std::string& patronymic_)
{
    patronymic = patronymic_;
}
