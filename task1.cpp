#include <iostream>
#include <cmath>

using namespace std;

int composition(int i, int b)
{
    int pr = 1;
    for (i; i <= b; i++)
    {
        pr *= i*i;
    }
    return pr;
}

int main() {

    double xi[] = {-3.6, 7.8, -4.2, 3.5, -0.6, 2.8, 4.2};
    double a = 7.63, b = 4.85, y;

    for(size_t i = 0; i <= 6; i++)
    {
        y = (
             a * b + sqrt(pow((composition(1, 5) * xi[i]),2 )) + pow(a,2)   // Чисельник
             / pow(sqrt(pow(b,2)) + pow((composition(1, 7) * xi[i]),2) , 4)  // Знаменник
             + sin(sqrt(pow(a,2) + pow(b, 2 )))) * exp(-1 * sqrt(1 + pow(b,2))
             );
        cout << "x = " << xi[i] << endl;
        cout << "y = " << y << endl;
        cout << "----------------" << endl;
    }
    return 0;
}
