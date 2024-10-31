#ifndef GETS_H_
#define GETS_H_
#include <cstring>
#include <iostream>
#include <istream>
#include <string>
#include <limits>
namespace gets{
        template<class T>
        T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {
                T a;
                while(true) {
                        std::cin >> a;
                        if(std::cin.eof()) // обнаружен конец файла
                        throw std::runtime_error("Failed: EOF");
                        else if(std::cin.bad()) // обнаружена невосстановимая ошибка входного потока
                        throw std::runtime_error(std::string("Failed to read number: ") + std::strerror(errno));
                        // прочие ошибки (неправильный формат ввода) либо число не входит в заданный диапазон
                        else if(std::cin.fail() || a < min || a > max) {
                        std::cin.clear(); // очищаем флаги состояния потока
                        // игнорируем все символы до конца строки
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "You are wrong; repeat please!" << std::endl;
                        }
                        else // успешный ввод
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        return a;
                }
        }
}
#endif