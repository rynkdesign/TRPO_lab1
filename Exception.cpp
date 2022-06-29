#include <iostream>
#include <cstring>

namespace exep_stack
{

    class EStackException // Класс для исключений стека
    {
       private:
         char* message; // Сообщение о сработавшем исключении
       public:

        EStackException(const char* arg_message) // Конструктор из строки
        {
            message = new char[strlen(arg_message)+1];
            strcpy(message,arg_message);
        }

        EStackException(const EStackException& arg) // Конструктор копирования
        {
            message = new char[strlen(arg.message)+1];
            strcpy(message,arg.message);
        }

        ~EStackException() // Деструктор
        {
            delete [] message;
        }

        const char* what() const { return message; } // Функция возвращает сообщение об исключении

    };

    class EStackEmpty : public EStackException // Наследование от Класса исключений, Класс исключений, что стек пустой
    {
        public:
        EStackEmpty(const EStackEmpty& arg): EStackException(arg) {} // Конструктор из строки
        explicit EStackEmpty(const char * arg) : EStackException(arg) {} // Конструктор копирования
    };
}
