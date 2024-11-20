#include <iostream>
#include <cmath> // Include <cmath> for the pow function
using namespace std;

// Non-template Sum function for integers
int Sum(int* a, const int size);

// Template function for Sum (general numerical types)
template <typename T>
T Sum(T* a, const int size);

int main()
{
    const int n = 10;

    // Integer array
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int s1 = Sum(a, n);
    cout << "Sum(a, n) = " << s1 << endl;

    // Template specialization for integers
    int s2 = Sum<int>(a, n);
    cout << "Sum<int>(a, n) = " << s2 << endl;

    // Double array
    double b[n] = { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    double s3 = Sum<double>(b, n);
    cout << "Sum<double>(a, n) = " << s3 << endl;

    return 0;
}

// Non-template implementation of Sum for integers
int Sum(int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        s += pow(a[i], 2); // Square each element
    return s;
}

// Template implementation of Sum for numerical types
template <typename T>
T Sum(T* a, const int size)
{
    T s = T(); // Initialize to zero for the specific type
    for (int i = 0; i < size; i++)
        s += pow(a[i], 2); // Square each element and add
    return s;
}
