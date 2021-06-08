#ifndef DAR_H_VECTOR_H
#define DAR_H_VECTOR_H
#include "ArraySequence.h"
#include "cmath"

template<class T>
class Vector {
private:
    ArraySequence<T> vector_arr;
    size_t type = sizeof(T);
public:
    Vector() {
    }

    int get_len(){
        return vector_arr.get_len();
    }

    Vector(const Vector<T> &vector1){
        this->vector_arr = vector1.vector_arr;
    }

    explicit Vector(ArraySequence<T> &arraySequence) {
        this->vector_arr = ArraySequence<T>(arraySequence);
    }

    Vector( T *array ) {
        vector_arr = ArraySequence<T>(array);
    }

    Vector<T> *add(Vector<T> vector) {
        if (type != vector.type)
            return nullptr;
        ArraySequence<T> arraySeq;
        int size = vector_arr.get_len();
        if (vector_arr.get_len() >= vector.vector_arr.get_len()) {
            arraySeq = ArraySequence<T>(vector_arr);
            size = vector.vector_arr.get_len();
        } 
        else {
            arraySeq = ArraySequence<T>(vector.vector_arr);
        }
        for (int i = 0; i < size; i++) {
            arraySeq.set_i(i, vector.vector_arr.get_i(i) + vector_arr.get_i(i));
        }

        auto vector1 = new Vector<T>(arraySeq);
        return vector1;
    }

    Vector<T> *scalarMult(T value) {
        ArraySequence<T> arraySeq(vector_arr);
        for (int i = 0; i < vector_arr.get_len(); ++i) {
            arraySeq.set_i(i, vector_arr.get_i(i) * value);
        }
        auto vector1 = new Vector<T>(arraySeq);
        return vector1;
    }

    Vector<T> *sub(Vector<T> vector) {
        if (type != vector.type)
            return nullptr;
        ArraySequence<T> arraySequence1;
        int size = vector_arr.get_len();
        vector = *(vector.scalarMult(-1));
        if (vector_arr.get_len() >= vector.vector_arr.get_len()) {
            arraySequence1 = ArraySequence<T>(vector_arr);
            size = vector.vector_arr.get_len();
        } else {
            arraySequence1 = ArraySequence<T>(vector.vector_arr);
        }
        for (int i = 0; i < size; i++) {
            arraySequence1.set_i(i, vector_arr.get_i(i) + vector.vector_arr.get_i(i));
        }
        auto vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    Vector<T> *mult(Vector<T> vector) {
        if (type != vector.type)
            return nullptr;
        ArraySequence<T> arraySequence1;
        int size = vector_arr.get_len();
        if (vector_arr.get_len() >= vector.vector_arr.get_len()) {
            arraySequence1 = ArraySequence<T>(vector_arr);
            size = vector.vector_arr.get_len();
        } else {
            arraySequence1 = ArraySequence<T>(vector.vector_arr);
        }
        for (int i = 0; i < size; i++) {
            arraySequence1.set_i(i, vector.vector_arr.get_i(i) * vector_arr.get_i(i));
        }
        auto *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    T Value() {
        T res = (T) 0;
        for (int i = 1; i < vector_arr.get_len(); i++) {
            if (vector_arr[i] != 0)
                res += (vector_arr[i]) * (vector_arr[i]);
        }
        return sqrt(res);
    }


    Vector<T> operator*(Vector<T> vec) {
        return *Vector<T>(*this).mult(vec);
    }


    Vector<T> operator*(T a) {
        return *Vector<T>(*this).scalarMult(a);
    }

    Vector<T> operator *= (T item) {
        return scalarMult(item);
    }



    Vector<T> operator-(Vector<T> vec) {
        auto *resPtr = Vector<T>(*this).sub(vec);
        auto res = *resPtr;
        delete resPtr;
        return res;
    }


    Vector<T> operator -= (Vector<T> vec) {
        return *sub(vec);
    }


    T &operator[](int index) {
        return vector_arr[index];
    }


    Vector<T> operator +(Vector<T> vec) {
        auto *resPtr = Vector<T>(*this).add(vec);
        auto res = *resPtr;
        delete resPtr;
        return res;
    }

    Vector<T> operator += (Vector<T> vec) {
        return add(vec);
    }


    int operator == (Vector<T> vec) {
        if (vector_arr.get_len() != vec.vector_arr.get_len())
            return 0;

        for (int i = 0; i < vector_arr.get_len(); i++) {
            if (vector_arr[i] != vec.vector_arr[i])
                return 0;
        }

        return 1;
    }

    int operator != (Vector<T> vec) {
        return !(*this == vec);
    }

    int operator == (T value) {
        if (vector_arr.get_len() == 1 && vector_arr[0] == value)
            return 1;

        if (vector_arr.get_len() == 0 && value == 0)
            return 1;

        return 0;
    }

    int operator != (T value) {
        return !(*this == value);
    }

    Vector<T> &operator = (const Vector<T> &vec) {
        vector_arr = vec.vector_arr;
        return *this;
    }
};
template <class T>
std::ostream &operator<<(std::ostream &cout, Vector<T> vector) {
    cout << '{';
    for (int i = 0; i < vector.get_len(); i++) {
        cout << vector[i];
        if (i != vector.get_len() - 1)
            cout << ", ";

    }
    cout << '}';
    return cout;
}

#endif //DAR_H_VECTOR_H
