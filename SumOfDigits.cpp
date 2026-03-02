# include <iostream>
using namespace std;

int sumOfDigits(int n);

int main()  {
    int n = 123;
    cout << sumOfDigits(n);
}

int sumOfDigits(int n)  {
    if (n / 10 == 0) return n;
    return (n % 10) + sumOfDigits(n / 10);
}