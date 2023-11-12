#include <iostream>
#include <stdexcept>

class DoublyArray 
{
private:
    static const int capacity = 5;  // Размер статического массива
    int data[capacity];
    int size;  // Текущий размер массива

public:
    // Конструктор по умолчанию
    DoublyArray() : size(0) {}

    // Функция добавления элемента в конец массива
void append(int value) 
{
    if (size < capacity) 
    {
        data[size++] = value;
    } 
    else 
    {
        // Массив переполнен, генерируем исключение
        throw std::overflow_error("Переполнение массива");
    }
}



    // Функция удаления последнего элемента из массива
    void removeLast() 
    {
        if (size > 0) 
        {
            --size;
        } else 
        {
            // Массив пуст, генерируем исключение
            throw std::underflow_error("Удаление из пустого массива");
        }
    }

    // Функция очистки массива
    void clear() 
    {
        size = 0;
    }

    // Функция вывода элементов массива
    void display() 
    {
        for (int i = 0; i < size; ++i) 
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() 
{
    setlocale(LC_ALL, "rus");
    try 
    {
        // Создаю массив
        DoublyArray myArray;

        // Добавляю элементы
        myArray.append(1);
        myArray.append(2);
        myArray.append(3);
        myArray.append(4);
        myArray.append(5);

        // Вывод массива
        std::cout << "Массив: ";
        myArray.display();

        // Пытаюсь удалить из пустого массива (генерирует исключение)
        myArray.removeLast(); // не срабатывает если массив не пустой для демонстрации работы переместить строчку на 67 строку

        // Добавляю элемент для демонстрации ошибки при переполнении
        myArray.append(6);
        myArray.append(7);
        std::cout << "Массив: ";
        myArray.display();

    } catch (std::exception& e) 
    {
        // Обработка общих исключений
        std::cerr << "Произошло исключение: " << e.what() << std::endl;
    }

    return 0;
}
