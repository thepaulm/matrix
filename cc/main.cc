#include <iostream>

#include "matrix.h"

using namespace std;

void do_ints()
{
    Matrix<int> m1(4, 1);
    Matrix<int> m2(1, 4);

    cout << "m1: " << m1 << "m2: " << m2 << endl;

    int x[] = {0};

    for (int i = 0; i < 4; i++) {
        x[0] = i+1;
        m1.setr(i, x, 1);
    }

    int y[] = {10, 20, 30, 40};
    m2.setr(0, y, 4);

    cout << "m1: " << m1 << "m2: " << m2 << endl;

    cout << m1.dot(m2) << endl;
    cout << m2.dot(m1) << endl;
}

void do_floats()
{
    Matrix<float> m1(4, 1);
    Matrix<float> m2(1, 4);

    cout << "m1: " << m1 << "m2: " << m2 << endl;

    float x[] = {0.0};

    for (int i = 0; i < 4; i++) {
        x[0] = (i+1)/100.0;
        m1.setr(i, x, 1);
    }

    float y[] = {0.10, 0.20, 0.30, 0.40};
    m2.setr(0, y, 4);

    cout << "m1: " << m1 << "m2: " << m2 << endl;

    cout << m1.dot(m2) << endl;
    cout << m2.dot(m1) << endl;
}

int main(int argc, char *argv[])
{
    do_ints();
    do_floats();
    return 0;
}


