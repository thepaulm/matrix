#include <iostream>

template <class T>
class Matrix
{
    public:
        Matrix(int rows, int columns);
        Matrix(const Matrix<T> &m);
        ~Matrix();

        Matrix<T> dot(const Matrix<T> &m);
        void setr(int rindex, T data[], int count);
        void setrc(int rindex, int cindex, T d);
        T getrc(int rindex, int cindex) const;
    private:
        T *data;
        int rows;
        int columns;

    template <class U>
    friend std::ostream &operator<<(std::ostream &, const Matrix<U> &);
};

/*
 * Instatiation and printing
 */
template <class T>
Matrix<T>::Matrix(int rows, int columns):
rows(rows),
columns(columns)
{
    this->data = new T[rows * columns];
    std::memset(this->data, 0, sizeof(T) * this->rows * this->columns);
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &m)
{
    this->rows = m.rows;
    this->columns = m.columns;
    this->data = new T[this->rows * this->columns];
    std::memcpy(this->data, m.data, sizeof(T) * this->rows * this->columns);
}

template <class T>
Matrix<T>::~Matrix()
{
    delete this->data;
}

template <class U>
std::ostream &operator<<(std::ostream &o, const Matrix<U> &m)
{
    for (int i = 0; i < m.rows; i++) {
        o << "[";
        for (int j = 0; j < m.columns; j++) {
            if (j != 0) {
                o << ", ";
            }
            o << m.data[i * m.columns + j];
        }
        o << "]";
        if (i < m.rows - 1) {
            o << ",";
        }
        o << std::endl;
    }
    return o;
}

/*
 * Setting / Getting Elements
 */
template <class T>
void Matrix<T>::setr(int rindex, T data[], int count)
{
    std::memcpy(this->data + rindex * this->columns, data, sizeof(T) * count);
}

template <class T>
void Matrix<T>::setrc(int rindex, int cindex, T d)
{
    this->data[rindex * this->columns + cindex] = d;
}

template <class T>
T Matrix<T>::getrc(int rindex, int cindex) const
{
    return this->data[rindex * this->columns + cindex];
}

/*
 * dot
 */
template <class T>
Matrix<T> Matrix<T>::dot(const Matrix<T> &m)
{
    Matrix<T> r(this->rows, m.columns);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < m.columns; j++) {
            T accum = (T)0;
            for (int l = 0; l < this->columns; l++) {
                /*
                lr = i;
                lc = l;
                rr = l;
                rc = j;
                */
                accum += this->getrc(i, l) * m.getrc(l, j);
            }
            r.setrc(i, j, accum);
        }
    }
    return r;
}
