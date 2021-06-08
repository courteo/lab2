#include "iostream"
#include "ArraySequence.h"
#include "linkseq.h"
#include "polynomial.h"
#include "ArraySequenceTest.h"
#include "LinkSeqTest.h"
#include "DynamicArrayTest.h"
#include "link_listTest.h"
#include "PolTest.h"
#include "complex"
#include "typeinfo"

#ifndef DAR_H_INTERFACE_H
#define DAR_H_INTERFACE_H
void deletePolynomial(int item, ArraySequence<Polynomial<int>> *polynomialInt,
                      ArraySequence<Polynomial<double>> *polynomialDouble, ArraySequence<Polynomial<std::complex<int>>> *polynomialComp);

template<class T>
void deleteTypePolynomial(ArraySequence<Polynomial<T>> *polynomial);

void testFunc();

void printPol(int item, ArraySequence<Polynomial<int>> polInt,
              ArraySequence<Polynomial<double>> polDouble, ArraySequence<Polynomial<std::complex<int>>> polComp);

template<class T>
void printTypePol(ArraySequence<Polynomial<T>> *polynomial);


void printArr(int item, Polynomial<int> polInt,
              Polynomial<double> polDouble, Polynomial<std::complex<int>> polComp);

template<class T>
void printTypeArr(Polynomial<T> polynomial);


void readPolynomial(int item, ArraySequence<Polynomial<int>> *polynomialInt,
                    ArraySequence<Polynomial<double>> *polynomialDouble, ArraySequence<Polynomial<std::complex<int>>> *polynomialComp);
template<class T>
Polynomial<T> readTypePolynomial(int count);


int get_type();


void OperationWithPolynomial(int item, ArraySequence<Polynomial<int>> *polynomialInt,
                             ArraySequence<Polynomial<double>> *polynomialDouble, ArraySequence<Polynomial<std::complex<int>>> *polynomialComp);
template<class T>
void OperationWithTypePolynomial(ArraySequence<Polynomial<T>> *polynomials);

int get_int() {
    int a;
    std::cin >> a;
    return a;
}
int get_int(int up) {
    int a;
    std::cin >> a;
    if (a > up) {
        std::cout << "Число вне диапозона. Повторите попытку\n";
        return get_int(up);
    }
    return a;
}

int get_int(int down, int up) {
    int a;
    std::cin >> a;
    if (a > up || a < down) {
        std::cout << "Число вне диапозона. Повторите попытку\n";
        return get_int(down, up);
    }
    return a;
}

double get_double() {
    double a;
    std::cin >> a;
    return a;
}

std::complex<int> get_complex() {
    int real = get_int();
    int imag = get_int();
    std::complex<int> a(real, imag);
    return a;
}

std::ostream& operator << (std::ostream& cout, std::complex<int> num) {
    if (num.imag() == 0) return cout << num.real();

    if (num.real() != 0) {
        cout << num.real();
    }

    if (num.imag() > 0) {
        if (num.real() != 0)
            cout << '+';
        if (num.imag() != 1)
            cout << num.imag();
        return cout << 'i';
    }
    else {
        if (num.imag() == -1)
            return cout << "-i";
        return cout << num.imag() << 'i';
    }
}

void interface(){
    ArraySequence<Polynomial<int>> polInt;
    ArraySequence<Polynomial<double>> polDouble;
    ArraySequence<Polynomial<std::complex<int>>> polComp;
    int item;
    while (true) {
        std::cout << "Choose option:\n"
                  << "\t1 - enter polynom\n"
                  << "\t2 - choose operation\n"
                  << "\t3 - print all Polynoms\n"
                  << "\t4 - print polynom[i]\n"
                  << "\t5 - tests\n"
                  << "\t6 - delete\n"
                  << "\t0 - exit\n";
        item = get_int(0, 6);
        if (item == 0) break;

        int item2 = get_type();
        switch (item) {
            case 1:
                readPolynomial(item2, &polInt, &polDouble,&polComp);
                break;

            case 2:
                OperationWithPolynomial(item2, &polInt, &polDouble, &polComp);
                break;

            case 3:
                printPol(item2, polInt, polDouble,polComp);
                break;
            case 4: {
                int item3;
                if (item2 == 1)
                     item3 =get_int(0, polInt.get_len());
                else
                    if (item2 == 2)
                         item3 =get_int(0, polDouble.get_len());
                    else  item3 =get_int(0, polComp.get_len());

                Polynomial<int> polInt1;
                Polynomial<double> polDouble1;
                Polynomial<std::complex<int>> polComp1;
                if (polInt.get_len() <= item3)
                    if (polInt.get_len() > 0)
                        polInt1 = polInt.get_i(polInt.get_len() - 1);
                    else
                        polInt1 = Polynomial<int>();
                else
                    polInt1 = polInt.get_i(item3);


                if (polDouble.get_len() <= item3)
                    if (polDouble.get_len() > 0)
                        polDouble1 = polDouble.get_i(polDouble.get_len() - 1);
                    else
                        polDouble1 = Polynomial<double>();
                else
                    polDouble1 = polDouble.get_i(item3);

                if (polComp.get_len() <= item3)
                    if (polComp.get_len() > 0)
                        polComp1 = polComp.get_i(polComp.get_len() - 1);
                    else
                        polComp1 = Polynomial<std::complex<int>>();
                else
                    polComp1 = polComp.get_i(item3);


                printArr(item2, polInt.get_i(item3), polDouble.get_i(item3), polComp.get_i(item3));
                break;
            }
            case 5:
                testFunc();
                break;
            case 6:
                deletePolynomial(item2, &polInt, &polDouble,&polComp);
                break;
        }
    }

}

int get_type() {
    std::cout << "Enter number to operate with certain data type: \n"
         << "\t1: int\n"
         << "\t2: double\n"
         << "\t3: complex<int>\n"
         << "\t0: exit\n"
         << ": ";
    return get_int(0, 3);
}


void readPolynomial(int item, ArraySequence<Polynomial<int>> *polynomialInt,
                    ArraySequence<Polynomial<double>> *polynomialDouble, ArraySequence<Polynomial<std::complex<int>>> *polynomialComp) {
    if (item == 0) return;

    std::cout << "Enter count of elements or -1 to exit: \n";
    int count;
    std::cin >> count;
    while(count < 0) {
        if (count < 0) {
            std::cout << "count can't be less than 0!\n: ";
        }
        std::cin >> count;

        if (count == -1)
            return;
    } ;

    Polynomial<int> polynomialInt1;
    Polynomial<double> polynomialDouble1;
    Polynomial<std::complex<int>> polynomialComp1;
        switch (item) {
            case 1:
                polynomialInt1 = readTypePolynomial<int>(count);
                polynomialInt->append(polynomialInt1);
                break;
            case 2:
                polynomialDouble1 = readTypePolynomial<double>(count);
                polynomialDouble->append(polynomialDouble1);
                break;
            case 3:
                polynomialComp1 = readTypePolynomial<std::complex<int>>(count);
                polynomialComp->append(polynomialComp1);
                break;
            default:
                break;
        }
}


void OperationWithPolynomial(int item, ArraySequence<Polynomial<int>> *polynomialInt,
                             ArraySequence<Polynomial<double>> *polynomialDouble, ArraySequence<Polynomial<std::complex<int>>> *polynomialComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            OperationWithTypePolynomial<int>(polynomialInt);
            break;
        case 2:
            OperationWithTypePolynomial<double>(polynomialDouble);
            break;
        case 3:
            OperationWithTypePolynomial<std::complex<int>>(polynomialComp);
            break;
    }
}

template<class T>
void OperationWithTypePolynomial(ArraySequence<Polynomial<T>> *polynomials){
    if (polynomials->get_len() == 0){
        std::cout << "Polynomial doesnt exist\n";
        return;
    }

    while (true){
        auto length = polynomials->get_len();
        std::cout << "You have " << length << " polynomials\n"
                  << "\t - negative number for exit\n"
                  << "\t - index of polynom\n"
                  << "\t - number bigger than length for print all polynom\n";
        int item1 = get_int();
        if (item1 < 0) break;

        if (item1 >= length){
            printTypePol(polynomials);
            continue;
        }
        Polynomial<T> polynomial;
        polynomial = polynomials->get_i(item1);

        std::cout << "What operation do you want to choose:\n"
                  << "\t0: exit\n"
                  << "\t1: sum polynomial\n"
                  << "\t2: sub polynomial\n"
                  << "\t3: mult On Scalar polynomial\n"
                  << "\t4: mult polynomial\n"
                  << "\t5: value polynomial\n";
        int item = get_int(0, 5);

        if (item == 0) break;

        Polynomial<T> pol1;
        Polynomial<T> polres;
        T value;

        if (item == 3 || item == 5){
            T element;
            std::cout << "Enter scalar:\n";
            std::cin >> element;

            if (item == 3){
                polres = polynomial.onScalar(element);
            }

            if (item == 5){
                std::cout << "Value is " << polynomial.value(element) << "\n";
            }
                polynomials->append(polres);
        }
        else{

            std::cout << "Enter count of elements or -1 to exit: \n";
            int count;
            std::cin >> count;
            while(count < 0) {
                if (count < 0) {
                    std::cout << "count can't be less than 0!\n: ";
                }
                std::cin >> count;

                if (count == -1)
                    return;
            } ;

            pol1 = readTypePolynomial<T>(count);

            switch (item) {
                default: break;
                case 1: polres = pol1 + polynomial; break;
                case 2: polres = polynomial - pol1; break;
                case 4: polres = pol1 * polynomial; break;
            }
            printTypeArr(polres);
            std::cout << "Do you want to save polynomial?\n"
                      << "\t0 - no\n"
                      << "\t1 - yes\n";
            int item2 = get_int(0, 1);

            if (item2 == 1){
                polynomials->append(polres);
            }
        }
    }
}

void printPol(int item, ArraySequence<Polynomial<int>> polInt,
              ArraySequence<Polynomial<double>> polDouble, ArraySequence<Polynomial<std::complex<int>>> polComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            printTypePol<int>(&polInt);
            break;
        case 2:
            printTypePol<double>(&polDouble);
            break;
        case 3:
            printTypePol<std::complex<int>>(&polComp);
            break;
    }
}


void printArr(int item, Polynomial<int> polInt,
              Polynomial<double> polDouble, Polynomial<std::complex<int>> polComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            printTypeArr<int>(polInt);
            break;
        case 2:
            printTypeArr<double>(polDouble);
            break;
        case 3:
            printTypeArr<std::complex<int>>(polComp);
            break;
    }
}

template<class T>
void printTypePol(ArraySequence<Polynomial<T>> *polynomial){
    for (int i = 0; i < polynomial->get_len(); i++) {
        std::cout << '(';
           for (int j = 0; j < polynomial->get_i(i).get_len(); j++){
               std::cout << polynomial->get_i(i).get_i(j) << ", ";
           }
           std::cout << "\b\b), ";
    }
    std::cout << "\n";
}

template<class T>
void printTypeArr(Polynomial<T> polynomial){
    for (int i = 0; i < polynomial.get_len(); i++) {
        std::cout << polynomial.get_i(i) << " ";
    }
    std::cout << "\n";
}

template<class T>
Polynomial<T> readTypePolynomial(int count) {
    std::cout << "Enter the elements:\n";
    Polynomial<T> element(count);
    for (int i = 0; i < count; i++) {
        T item;
        std::cin >> item;

        element.set_i(i, item);
    }
    return element;
}

void deletePolynomial(int item, ArraySequence<Polynomial<int>> *polynomialInt,
                             ArraySequence<Polynomial<double>> *polynomialDouble, ArraySequence<Polynomial<std::complex<int>>> *polynomialComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            deleteTypePolynomial<int>(polynomialInt);
            break;
        case 2:
            deleteTypePolynomial<double>(polynomialDouble);
            break;
        case 3:
            deleteTypePolynomial<std::complex<int>>(polynomialComp);
            break;
    }
}


template<class T>
void deleteTypePolynomial(ArraySequence<Polynomial<T>> *polynomial){
    if (polynomial->get_len() == 0){
        std::cout << " polynom doesnt exist\n";
        return;
    }

    while (true){
        int length = polynomial->get_len();
        if (length == 0){
            std::cout<< " polynom doesnt exist\n";
            break;
        }

        std::cout << "You have " << length << " polynomials\n"
                  << "\t - negative number for exit\n"
                  << "\t - index of polynom\n"
                  << "\t - number bigger than length for print all polynom\n";
        int item1 = get_int();
        if (item1 < 0) break;

        if (item1 >= length){
            printTypePol(polynomial);
            continue;
        }

        std::cout << "Choose operation:\n"
                  << "\t-1:  return to choosing index\n"
                  << "\t0: delete\n";

        int item2 = get_int(-1,0);

        if (item2 == -1) continue;

        if (item2 == 0){
            std::cout << "Do you really want to delete pol[" << item1 <<"]?"
                      << "\t0 - no\n"
                      << "\t1 - yes\n";
            int item3 = get_int(0, 1);
            if (item3 == 1) {
                polynomial->pop(item1);
            }
            continue;
        }
    }
}

void testFunc() {
    std::cout << "Enter:\n"
                 "\t - positive number for enter iterate tests\n"
                 "\t - 0 or negative number for exit\n";

    int count = get_int();
    if (count <= 0)
        return;

    ArraySequenceTestInt();
    ArraySequenceTestComp();
    ArraySequenceTestDouble();
    DynamicArrayTestInt();
    DynamicArrayTestDouble();
    DynamicArrayTestComplex();
    LinkListTestInt();
    LinkListTestDouble();
    LinkedSequenceTestInt();
    LinkedSequenceTestDouble();
    PolTestInt();

    std::cout << "Do you want to repeat test?\n"
                 "\t0 - no\n"
                 "\t1 - yes\n: ";
    count = get_int(0, 1);
    if (count == 1)
        testFunc();
}
#endif //DAR_H_INTERFACE_H
