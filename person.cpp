#include "person.h"

Person::Person(const Person& other) // Конструктор копирования
{
    last_name = other.last_name;
    first_name = other.first_name;
    patronymic = other.patronymic;
}

Person::Person(const std::string& full_name) // Конструктор копирования строки
{
    bool isAlph = true;
    std::string temp;
    unsigned i = 0;
    int count = 0;
    for (;count <3; i++) // Идем по строке до тех пор, пока у нас не заполнилось ФИ или ФИО
    {
        if (full_name[i] == ' ' ) // Если встречаем пробел или
        {
            break; // Выходим из цикла

        }
        else if (!isalpha(full_name[i])) // Проверяем нет ли чего-то кроме букв
        {
            isAlph = false;
        }
        else if (isalpha(full_name[i])) // Или запоминаем 1 слово
        {
            temp +=full_name[i];
        }
    }

    if(isAlph) // Если только буквы, то записываем в фамилию 1 слово
    {
        last_name = temp;
        count++;
    }

    isAlph = true;
    temp.clear();
    for (i++ ;i < full_name.size(); i++) // Идём дальше по строке
    {
        if (full_name[i] == ' ' ) // Если встречаем пробел или
        {
            break; // Выходим из цикла

        }
        else if (!isalpha(full_name[i])) // Проверяем нет ли чего-то кроме букв
        {
            isAlph = false;
        }
        else if (isalpha(full_name[i])) // Или запоминаем 2 слово
        {

            temp +=full_name[i];
        }
    }

    if(isAlph) // Если только буквы, то записываем в имя 2 слово
    {
        first_name = temp;
        count++;
    }

    isAlph = true;
    temp.clear();
    for (i++;i < full_name.size(); i++) // Записываем отчество
    {
        if (full_name[i] == ' ' ) // Если встречаем пробел или
        {
            break; // Выходим из цикла

        }
        else if (!isalpha(full_name[i])) // Проверяем нет ли чего-то кроме букв
        {
            isAlph = false;
        }
        else if (isalpha(full_name[i])) // Или запоминаем 3 слово
        {

            temp +=full_name[i];
        }
    }

    if(isAlph) // Если только буквы, то записываем в отчество 3 слово
    {
        patronymic = temp;
        count++;
    }
}

// Получить имя
const std::string& Person::getFirstName() const
{
    return first_name;
}

// Получить фамилию
const std::string& Person::getLastName() const
{
    return last_name;
}

// Получить отчество
const std::string& Person::getPatronymic() const
{
    return patronymic;
}

// Установить имя
void Person::setFirstName(const std::string& first_name_)
{
    first_name = first_name_;
}

// Установить фамилию
void Person::setLastName(const std::string& last_name_)
{
    last_name = last_name_;
}

// Установить отчество
void Person::setPatronymic(const std::string& patronymic_)
{
    patronymic = patronymic_;
}
