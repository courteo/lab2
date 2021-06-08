#ifndef PROSTO_POLYNOMIAL_H
#define PROSTO_POLYNOMIAL_H

#include <iostream>
#include "ArraySequence.h"

template<class T>
class Polynomial {
private:
    ArraySequence<T> elements;

    static T pow(int x, T value) {
        T result = 1;
        for (int i = 0; i < x; i ++){
            result = result * value;
        }
        return result;
    }
public:
    class IndexOutOfRange{
    public:
        int length;
        int index;
        IndexOutOfRange(int length, int index): length(length), index(index) {};
        IndexOutOfRange(): length(-1), index(-1) {};
    };

    Polynomial<T> &operator = (const Polynomial<T> &polynomial) {
        elements = polynomial.elements;

        return *this;
    }

    Polynomial<T> &operator = (Polynomial<T> *polynomial) {
        elements = polynomial->elements;
        return *this;
    }

    Polynomial(){
        elements = ArraySequence<T>();
    }

    Polynomial(int size){
        elements = ArraySequence<T>(size);
    }

    Polynomial(const Polynomial<T> &polynomial) {
        elements = polynomial.elements;
    }

    void set_i(int index, T item) {
        if (index < 0 || index >= elements.get_len()) throw IndexOutOfRange(get_len(), index);
        elements.set_i(index, item);
    }

    T get_i(int index) {
        if (index < 0 || index >= elements.get_len()) throw IndexOutOfRange(get_len(), index);
        return elements.get_i(index);
    }

    int get_len() {
        return this->elements.get_len();
    }

    Polynomial<T> add(Polynomial<T> pol) {
        if (pol.get_len() <= 0) throw IndexOutOfRange();
        int q = -1;
        int max_len;
        int min_len;
        if (this->get_len() > pol.get_len()) {
            max_len = this->get_len();
            q = 1;
            min_len = pol.get_len();
        }
        else {
            max_len = pol.get_len();
            q = 0;
            min_len = this->get_len();
        }
        Polynomial<T> NewPol;
        for (int i = 0; i < min_len; i++){
            NewPol.elements.append(this->elements.get_i(i) + pol.elements.get_i(i));
        }
        for ( int i = min_len; i < max_len; i++) {
            if (q == 0) {
                NewPol.elements.append(pol.elements.get_i(i));
            } else {
                NewPol.elements.append(this->elements.get_i(i));
            }
        }
        elements = NewPol.elements;
        return *this;
    }

    Polynomial<T> sub(Polynomial<T> pol) {
        if (pol.get_len() <= 0) throw IndexOutOfRange();
        int q = -1;
        int max_len;
        int min_len;
        if (this->get_len() > pol.get_len()) {
            max_len = this->get_len();
            q = 1;
            min_len = pol.get_len();
        }
        else{
            max_len = pol.get_len();
            q = 0;
            min_len = this->get_len();
        }
        Polynomial<T> NewPol;
        for (int i = 0; i < min_len; i++){
            NewPol.elements.append((this->elements.get_i(i) - pol.elements.get_i(i)));
        }
        for ( int i = min_len; i < max_len; i++){
            if (q == 0){
                NewPol.elements.append(pol.elements.get_i(i));
            }
            else {
                NewPol.elements.append(this->elements.get_i(i));
            }
        }
        elements = NewPol.elements;
        return *this;
    }


    Polynomial<T> onScalar(T scalar){

        Polynomial<T> NewPol;
        for (int i = 0; i < this->get_len(); i++){
            NewPol.elements.append(this->elements.get_i(i) * scalar);
        }
        this->elements = NewPol.elements;
        return *this;
    }



    T value(T symbol) {


        T value = this->elements.get_i(0);
        if (this->get_len() == 0) {
            return value;
        }
        else {
            for (int i = 1; i < this->get_len(); i++){
                value += this->elements.get_i(i) * pow(i, symbol);
            }

            return value;
        }
    }

    Polynomial<T> mult(Polynomial<T> pol) {
        if (pol.get_len() <= 0) throw IndexOutOfRange();

        Polynomial<T> NewPol;

        for (int i = 0; i < this->get_len(); i++)
            for (int j = 0; j < pol.get_len(); j++){
                NewPol.elements.append(this->elements.get_i(i) + pol.elements.get_i(j));
            }
        this->elements = NewPol.elements;
        return *this;
    }


    Polynomial<T> &operator +(Polynomial<T> pol){
        this->add(pol);
        return *this;
    }

    Polynomial<T> &operator +=(Polynomial<T> pol){
        (*this) = add(pol);
        return *this;
    }

    Polynomial<T> &operator -(Polynomial<T> pol){
        this->sub(pol);
        return *this;
    }

    Polynomial<T> &operator -=(Polynomial<T> pol){
        (*this) = sub(pol);
        return *this;
    }

    Polynomial<T> &operator *(Polynomial<T> pol){
        this->mult(pol);
        return *this;
    }

    Polynomial<T> &operator *=(Polynomial<T> pol){
        (*this) = mult(pol);
        return *this;
    }
};










/*
std::ostream &operator << (std::ostream &cout, Polynomial<int> polynomial) {
    int count = 0;
    for (int i = 0; i < polynomial.get_len() - 1; i++){
        if (polynomial.elements.get_i(i) == 0) continue;
        count++;
        cout << '(' << polynomial.get_i(i) << ')';
        if (i != 0) {
            cout << '*' << 'x' << '^' << i;
        }
        cout << " + ";
    }
    if (count == 0) cout << '(' << (int) 0 << ')';
    else cout << "\b\b\b";
    return cout;
};
*/



#endif //PROSTO_POLYNOMIAL_H
