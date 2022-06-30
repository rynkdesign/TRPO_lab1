#include <QCoreApplication>
#include <iostream>
#include "Stack.h"

int main()
{

    try
    {
        int test_tindex=0;
        std:: cout << "input test number" << std::endl;
        std::cin>>test_tindex;
        Stack<int> massiv;
        switch (test_tindex)
        {


            case 1:
            {
                // Тестирование 1 - получим размер Стека (Функция не зависит от того пустой стек или нет)
                std::cout<<"Test 1"<< std::endl;
                std::cout<<"--------------------"<< std::endl;
                std::cout<<"Razmer: "<<massiv.getSize()<< std::endl;
                break;
                // Т.к. в стек мы ничего не записывали, то получаем размер который задаётся по умолчанию – 0.
            }

            case 2:
            {
                // Тестирование 2 - вызовем функцию Top в пустом стеке
                std::cout<<"Test 2"<< std::endl;
                std::cout<<"--------------------"<< std::endl;
                std::cout<<"Top: "<<massiv.topFunc()<< std::endl;
                break;
                // При вызове функции Top в пустом стеке мы получим ошибку, которая сообщает, что в пустом стеке нельзя вызывать функцию Top, т.к. у нас нет элемента для вывода.
            }

            case 3:
            {
                // Тестирование 3 - вызовем функцию pop в пустом стеке
                std::cout<<"Test 3"<< std::endl;
                std::cout<<"--------------------"<< std::endl;
                massiv.pop();
                break;
                // При вызове функции Pop в пустом стеке мы получим ошибку, которая сообщает, что в пустом стеке нельзя вызывать функцию Pop, т.к. у нас нет элемента для удаления.
            }

            case 4:
            {
                // Тестирование 4 - Добавим элемент в Стек и покажем, что он добавился и размер увеличился
                std::cout<<"Test 4"<< std::endl;
                std::cout<<"--------------------"<< std::endl;
                massiv.push(3);
                std::cout<<"Razmer: "<<massiv.getSize()<< std::endl;
                std::cout<<"Top: "<<massiv.topFunc()<< std::endl;
                break;
                // На выходе получим Стек в который мы добавили число 3. В консоль выведется его размер – 1 и Его верхний (и единственный элемент) – 3.
            }

            case 5:
            {
                // Тестирование 5 - Добавим ещё один элемент в Стек и покажем, что функция Top работает корректно
                std::cout<<"Test 5"<< std::endl;
                std::cout<<"--------------------"<< std::endl;
                massiv.push(3);
                massiv.push(5);
                std::cout<<"Razmer: "<<massiv.getSize()<< std::endl;
                std::cout<<"Top: "<<massiv.topFunc()<< std::endl;
                break;
                // Мы сначала ввели 3, а затем 5. Поэтому на выходе получим Размер - 2 и верхний элемент (Последний записанный) - 5
            }

        }
    }
    catch (const exep_stack::EStackEmpty & e) //исключение - пустой стек
    {
        std::cout<< e.what();
    }

    return 0;
}
