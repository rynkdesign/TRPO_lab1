#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person // Класс для хранения ФИО
{
private:
    std::string first_name{}; // Имя
    std::string last_name{}; // Фамилия
    std::string patronymic{}; // Отчество
public:
    Person()= default; // Конструктор по умолчанию
    Person(const Person& other); // Конструктор копирования
    Person(const std::string& full_name); // Конструктор копирования строки
    ~Person()= default; // Деструктор


    // Геттеры
    const std::string& getFirstName() const; // Имя
    const std::string& getLastName() const; // Фамилия
    const std::string& getPatronymic() const; // Отчёство

    // Сеттеры
    void setFirstName(const std::string& first_name_); // Имя
    void setLastName(const std::string& last_name_); // Фамилия
    void setPatronymic(const std::string& patronymic_); // Отчёство

};

#endif // PERSON_H
