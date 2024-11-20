#include <iostream>
#include <cmath>
using namespace std;

// Нешаблонна функція Sum для типу int
int Sum(int* a, const int size, int i);

// Шаблонна функція Sum
template <typename T>
T Sum(T* a, const int size, int i);

int main()
{
    const int n = 10;

    // Масив типу int
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int s1 = Sum(a, n, 0);
    cout << "Sum(a, n) = " << s1 << endl;

    int s2 = Sum<int>(a, n, 0);
    cout << "Sum<int>(a, n) = " << s2 << endl;

    // Масив типу double
    double b[n] = { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    double s3 = Sum<double>(b, n, 0);
    cout << "Sum<double>(a, n) = " << s3 << endl;

    return 0;
}

// Реалізація нешаблонної функції Sum для int
int Sum(int* a, const int size, int i)
{
    if (i < size)
        return pow(a[i], 2) + Sum(a, size, i + 2); // Додаємо квадрат кожного другого елемента
    else
        return 0; // Базовий випадок рекурсії
}

// Реалізація шаблонної функції Sum
template <typename T>
T Sum(T* a, const int size, int i)
{
    if (i < size)
        return pow(a[i], 2) + Sum<T>(a, size, i + 2); // Додаємо квадрат кожного другого елемента
    else
        return T(); // Базовий випадок рекурсії
}
