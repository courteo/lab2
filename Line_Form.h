#ifndef DAR_H_LINE_FORM_H
#define DAR_H_LINE_FORM_H
#include "ArraySequence.h"

template<class T>
class Line_Form{
private:
    ArraySequence<T> Line_Form_arr;
    size_t type = sizeof(T);
public:
    Line_Form(){}

    Line_Form(const Line_Form<T> &Line_Form1){
        this->Line_Form_arr = Line_Form1.Line_Form_arr;
    }

    explicit Line_Form(ArraySequence <T> &arraySeq) {
        this->Line_Form_arr = ArraySequence<T>(arraySeq);
    }

    Line_Form(T *array) {
        Line_Form_arr = ArraySequence<T>(array);
    }

    Line_Form<T> *add(Line_Form<T> Line_Form2) {
        if (type != Line_Form2.type)
            return nullptr;
        ArraySequence<T> arraySeq;
        int size = Line_Form_arr.get_len();
        if (Line_Form_arr.get_len() >= Line_Form2.Line_Form_arr.get_len()) {
            arraySeq = ArraySequence<T>(Line_Form_arr);
            size = Line_Form2.Line_Form_arr.get_len();
        } else {
            arraySeq= ArraySequence<T>(Line_Form2.Line_Form_arr);
        }
        for (int i = 0; i < size; i++) {
            arraySeq.set_i(i, Line_Form2.Line_Form_arr.get_i(i) + Line_Form_arr.get_i(i));
        }
        auto Line = new Line_Form<T>(arraySeq);
        return Line;
    }

    Line_Form<T> *scalarMult(T a) {
        ArraySequence <T> arraySeq(Line_Form_arr);
        for (int i = 0; i < Line_Form_arr.get_len(); ++i) {
            arraySeq.set_i(i, Line_Form_arr.get_i(i) * a);
        }
        auto Line_Form1 = new Line_Form<T>(arraySeq);
        return Line_Form1;
    }

    Line_Form<T> *sub(Line_Form<T> Line_Form2) {
        if (type != Line_Form2.type)
            return nullptr;
        ArraySequence<T> arraySeq;
        int size = Line_Form_arr.get_len();
        Line_Form2= *(Line_Form2.scalarMult(-1));
        if (Line_Form_arr.get_len() >= Line_Form2.Line_Form_arr.get_len()) {
            arraySeq = ArraySequence<T>(Line_Form_arr);
            size = Line_Form2.Line_Form_arr.get_len();
        } else {
            arraySeq = ArraySequence<T>(Line_Form2.Line_Form_arr);
        }
        for (int i = 0; i < size; i++) {
            arraySeq.set_i(i, Line_Form_arr.get_i(i) + Line_Form2.Line_Form_arr.get_i(i));
        }
        auto Line_Form1 = new Line_Form<T>(arraySeq);
        return Line_Form1;
    }

    T Value(ArraySequence<T> &arr) {
        T res = (T) 0;
        for (int i = 0; i < arr.get_len(); i++) {
            res += Line_Form_arr.get_i(i) * arr.get_i(i);
        }
        return res;
    }

    int get_len(){
        return Line_Form_arr.get_len();
    }


    Line_Form<T> operator*(T a) {
        return *Line_Form<T>(*this).scalarMult(a);
    }


    Line_Form<T> operator-(Line_Form<T> Line_Form1) {
        auto *resPtr = Line_Form<T>(*this).sub(Line_Form1);
        auto res = *resPtr;
        delete resPtr;
        return res;
    }

    Line_Form<T> operator -= (Line_Form<T> Line_Form) {
        return *sub(Line_Form);
    }


    T &operator[](int index) {
        return Line_Form_arr[index];
    }


    Line_Form<T> operator +(Line_Form<T> Line_Form2) {
        auto *resPtr = Line_Form<T>(*this).add(Line_Form2);
        auto res = *resPtr;
        delete resPtr;
        return res;
    }

    Line_Form<T>* operator += (Line_Form<T> Line_Form) {
        return add(Line_Form);
    }


    Line_Form<T> operator *= (T item) {
        return scalarMult(item);
    }

    int operator == (Line_Form<T> Line_Form) {
        if (Line_Form_arr.get_len() != Line_Form.Line_Form_arr.get_len())
            return 0;

        for (int i = 0; i < Line_Form_arr.get_len(); i++) {
            if (Line_Form_arr[i] != Line_Form.Line_Form_arr[i])
                return 0;
        }

        return 1;
    }

    int operator != (Line_Form<T> Line_Form) {
        return !(*this == Line_Form);
    }


    int operator != (T value) {
        return !(*this == value);
    }

    Line_Form<T> &operator = (const Line_Form<T> &Line_Form) {
        Line_Form_arr = Line_Form.Line_Form_arr;
        return *this;
    }
};

template<class T>
std::ostream &operator<<(std::ostream &cout, Line_Form<T> Line_Form) {
    cout << '{';
    for (int i = 0; i < Line_Form.get_len(); i++) {
        cout << Line_Form[i];
        if (i != Line_Form.get_len() - 1) {
            cout << "x["<<i<<"]+";
        }
    }
    cout <<"x[" <<Line_Form.get_len()-1<<"]}";
    return cout;
}


#endif //DAR_H_LINE_FORM_H
