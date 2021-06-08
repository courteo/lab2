#ifndef DAR_H_INTERFACEFORLINEFORM_H
#define DAR_H_INTERFACEFORLINEFORM_H
#include "ArraySequence.h"
#include "Line_Form.h"
#include "complex"

void deleteLine_Form(int item, ArraySequence<Line_Form<int>> *Line_FormInt,
                  ArraySequence<Line_Form<double>> *Line_FormDouble, ArraySequence<Line_Form<std::complex<int>>> *Line_FormComp);

template<class T>
void deleteTypeLine_Form(ArraySequence<Line_Form<T>> *Line_Form);

void testFunc();

void printLineF(int item, ArraySequence<Line_Form<int>> LineFInt,
              ArraySequence<Line_Form<double>> LineFDouble, ArraySequence<Line_Form<std::complex<int>>> LineFComp);

template<class T>
void printTypeLineF(ArraySequence<Line_Form<T>> *Line_Form);


void printArr(int item, Line_Form<int> LineFInt,
              Line_Form<double> LineFDouble, Line_Form<std::complex<int>> LineFComp);

template<class T>
void printTypeArr(Line_Form<T> Line_Form);


void readLine_Form(int item, ArraySequence<Line_Form<int>> *Line_FormInt,
                ArraySequence<Line_Form<double>> *Line_FormDouble, ArraySequence<Line_Form<std::complex<int>>> *Line_FormComp);
template<class T>
Line_Form<T> readTypeLine_Form(int count);


int GET_type();


void OperationWithLine_Form(int item, ArraySequence<Line_Form<int>> *Line_FormInt,
                         ArraySequence<Line_Form<double>> *Line_FormDouble, ArraySequence<Line_Form<std::complex<int>>> *Line_FormComp);
template<class T>
void OperationWithTypeLine_Form(ArraySequence<Line_Form<T>> *Line_Forms);

int GET_int() {
    int a;
    std::cin >> a;
    return a;
}
int GET_int(int up) {
    int a;
    std::cin >> a;
    if (a > up) {
        std::cout << "Число вне диапозона. Повторите попытку\n";
        return GET_int(up);
    }
    return a;
}

int GET_int(int down, int up) {
    int a = -2;
    std::cin >> a;
    if (a > up || a < down) {
        std::cout << "Retry\n";
        return GET_int(down, up);
    }
    return a;
}

double GET_double() {
    double a;
    std::cin >> a;
    return a;
}

std::complex<int> GET_complex() {
    int real = GET_int();
    int imag = GET_int();
    std::complex<int> a(real, imag);
    return a;
}

void interfaceForLine_Form(){
    ArraySequence<Line_Form<int>> LineFInt;
    ArraySequence<Line_Form<double>> LineFDouble;
    ArraySequence<Line_Form<std::complex<int>>> LineFComp;
    int item;
    while (true) {
        std::cout << "Choose option:\n"
                  << "\t1 - enter Line_Form\n"
                  << "\t2 - choose operation\n"
                  << "\t3 - print all Line_Forms\n"
                  << "\t4 - print Line_Form[i]\n"
                  << "\t5 - tests\n"
                  << "\t6 - delete\n"
                  << "\t0 - exit\n";
        item = GET_int(0, 6);
        if (item == 0) break;

        int item2 = GET_type();
        switch (item) {
            case 1:
                readLine_Form(item2, &LineFInt, &LineFDouble,&LineFComp);
                break;

            case 2:
                OperationWithLine_Form(item2, &LineFInt, &LineFDouble, &LineFComp);
                break;

            case 3:
                printLineF(item2, LineFInt, LineFDouble,LineFComp);
                break;
            case 4: {
                int item3;
                std::cout << "enter number of element\n";
                if (item2 == 1)
                    item3 = GET_int(0, LineFInt.get_len() - 1);
                else
                if (item2 == 2)
                    item3 =GET_int(0, LineFDouble.get_len() - 1);
                else  item3 =GET_int(0, LineFComp.get_len() - 1);

                Line_Form<int> LineFInt1;
                Line_Form<double> LineFDouble1;
                Line_Form<std::complex<int>> LineFComp1;
                if (LineFInt.get_len() <= item3)
                    if (LineFInt.get_len() > 0)
                        LineFInt1 = LineFInt.get_i(LineFInt.get_len() - 1);
                    else
                        LineFInt1 = Line_Form<int>();
                else
                    LineFInt1 = LineFInt.get_i(item3);


                if (LineFDouble.get_len() <= item3)
                    if (LineFDouble.get_len() > 0)
                        LineFDouble1 = LineFDouble.get_i(LineFDouble.get_len() - 1);
                    else
                        LineFDouble1 = Line_Form<double>();
                else
                    LineFDouble1 = LineFDouble.get_i(item3);

                if (LineFComp.get_len() <= item3)
                    if (LineFComp.get_len() > 0)
                        LineFComp1 = LineFComp.get_i(LineFComp.get_len() - 1);
                    else
                        LineFComp1 = Line_Form<std::complex<int>>();
                else
                    LineFComp1 = LineFComp.get_i(item3);

                printArr(item2, LineFInt1, LineFDouble1, LineFComp1);
                break;
            }
            case 5:
                testFunc();
                break;
            case 6:
                deleteLine_Form(item2, &LineFInt, &LineFDouble,&LineFComp);
                break;
        }
    }

}

int GET_type() {
    std::cout << "Enter number to operate with certain data type: \n"
              << "\t1: int\n"
              << "\t2: double\n"
              << "\t3: complex<int>\n"
              << "\t0: exit\n"
              << ": ";
    return GET_int(0, 3);
}


void readLine_Form(int item, ArraySequence<Line_Form<int>> *Line_FormInt,
                ArraySequence<Line_Form<double>> *Line_FormDouble, ArraySequence<Line_Form<std::complex<int>>> *Line_FormComp) {
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

    Line_Form<int> Line_FormInt1;
    Line_Form<double> Line_FormDouble1;
    Line_Form<std::complex<int>> Line_FormComp1;
    switch (item) {
        case 1:
            Line_FormInt1 = readTypeLine_Form<int>(count);
            Line_FormInt->append(Line_FormInt1);
            break;
        case 2:
            Line_FormDouble1 = readTypeLine_Form<double>(count);
            Line_FormDouble->append(Line_FormDouble1);
            break;
        case 3:
            Line_FormComp1 = readTypeLine_Form<std::complex<int>>(count);
            Line_FormComp->append(Line_FormComp1);
            break;
        default:
            break;
    }
}


void OperationWithLine_Form(int item, ArraySequence<Line_Form<int>> *Line_FormInt,
                         ArraySequence<Line_Form<double>> *Line_FormDouble, ArraySequence<Line_Form<std::complex<int>>> *Line_FormComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            OperationWithTypeLine_Form<int>(Line_FormInt);
            break;
        case 2:
            OperationWithTypeLine_Form<double>(Line_FormDouble);
            break;
        case 3:
            OperationWithTypeLine_Form<std::complex<int>>(Line_FormComp);
            break;
    }
}

template<class T>
void OperationWithTypeLine_Form(ArraySequence<Line_Form<T>> *Line_Forms){
    if (Line_Forms->get_len() == 0){
        std::cout << "Line_Form doesnt exist\n";
        return;
    }

    while (true){
        auto length = Line_Forms->get_len();
        std::cout << "You have " << length << " Line_Forms\n"
                  << "\t - negative number for exit\n"
                  << "\t - index of LineFynom\n"
                  << "\t - number bigger than length for print all LineFynom\n";
        int item1 = GET_int();
        if (item1 < 0) break;

        if (item1 >= length){
            printTypeLineF(Line_Forms);
            continue;
        }
        Line_Form<T> Line_Form1;
        Line_Form1 = Line_Forms->get_i(item1);

        std::cout << "What operation do you want to choose:\n"
                  << "\t0: exit\n"
                  << "\t1: sum Line_Form\n"
                  << "\t2: sub Line_Form\n"
                  << "\t3: mult On Scalar Line_Form\n"
                  << "\t4: value Line_Form\n";
        int item = GET_int(0, 5);

        if (item == 0) break;

        Line_Form<T> LineF1;
        Line_Form<T> LineFres;
        T value;

        if (item == 3 || item == 4){
            T element;
            std::cout << "Enter scalar:\n";
            std::cin >> element;

            if (item == 3){
                LineFres = *Line_Form1.scalarMult(element);
            }

            if (item == 5){

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


                std::cout << "Enter the elements:\n";
                auto arr = new ArraySequence<T>(count);

                for (int i = 0; i < count; i++) {
                    T item;
                    std::cin >> item;

                    arr->set_i(i, item);
                }


                std::cout << "Value is " << Line_Form1.Value(*arr) << "\n";
            }
            Line_Forms->append(LineFres);
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

            LineF1 = readTypeLine_Form<T>(count);

            switch (item) {
                default: break;
                case 1: LineFres = LineF1 + Line_Form1; break;
                case 2: LineFres = Line_Form1 - LineF1; break;
            }
            printTypeArr(LineFres);
            std::cout << "Do you want to save Line_Form?\n"
                      << "\t0 - no\n"
                      << "\t1 - yes\n";
            int item2 = GET_int(0, 1);

            if (item2 == 1){
                Line_Forms->append(LineFres);
            }
        }
    }
}

void printLineF(int item, ArraySequence<Line_Form<int>> LineFInt,
              ArraySequence<Line_Form<double>> LineFDouble, ArraySequence<Line_Form<std::complex<int>>> LineFComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            printTypeLineF<int>(&LineFInt);
            break;
        case 2:
            printTypeLineF<double>(&LineFDouble);
            break;
        case 3:
            printTypeLineF<std::complex<int>>(&LineFComp);
            break;
    }
}


void printArr(int item, Line_Form<int> LineFInt,
              Line_Form<double> LineFDouble, Line_Form<std::complex<int>> LineFComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            printTypeArr<int>(LineFInt);
            break;
        case 2:
            printTypeArr<double>(LineFDouble);
            break;
        case 3:
            printTypeArr<std::complex<int>>(LineFComp);
            break;
    }
}

template<class T>
void printTypeLineF(ArraySequence<Line_Form<T>> *Line_Form1){
    for (int i = 0; i < Line_Form1->get_len(); i++) {
        std::cout << Line_Form1->get_i(i) << "  ";
    }
    std::cout << "\n";
}

template<class T>
void printTypeArr(Line_Form<T> Line_Form){
    std::cout << Line_Form << "\n";
}

template<class T>
Line_Form<T> readTypeLine_Form(int count) {
    std::cout << "Enter the elements:\n";
    auto arr = new ArraySequence<T>(count);

    for (int i = 0; i < count; i++) {
        T item;
        std::cin >> item;

        arr->set_i(i, item);
    }
    Line_Form<T> element(*arr);
    return element;
}

void deleteLine_Form(int item, ArraySequence<Line_Form<int>> *Line_FormInt,
                  ArraySequence<Line_Form<double>> *Line_FormDouble, ArraySequence<Line_Form<std::complex<int>>> *Line_FormComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            deleteTypeLine_Form<int>(Line_FormInt);
            break;
        case 2:
            deleteTypeLine_Form<double>(Line_FormDouble);
            break;
        case 3:
            deleteTypeLine_Form<std::complex<int>>(Line_FormComp);
            break;
    }
}


template<class T>
void deleteTypeLine_Form(ArraySequence<Line_Form<T>> *Line_Form){
    if (Line_Form->get_len() == 0){
        std::cout << " LineFynom doesnt exist\n";
        return;
    }

    while (true){
        int length = Line_Form->get_len();
        if (length == 0){
            std::cout<< " LineFynom doesnt exist\n";
            break;
        }

        std::cout << "You have " << length << " Line_Forms\n"
                  << "\t - negative number for exit\n"
                  << "\t - index of LineFynom\n"
                  << "\t - number bigger than length for print all LineFynom\n";
        int item1 = GET_int();
        if (item1 < 0) break;

        if (item1 >= length){
            printTypeLineF(Line_Form);
            continue;
        }

        std::cout << "Choose operation:\n"
                  << "\t-1:  return to choosing index\n"
                  << "\t0: delete\n";

        int item2 = GET_int(-1,0);

        if (item2 == -1) continue;

        if (item2 == 0){
            std::cout << "Do you really want to delete LineF[" << item1 <<"]?"
                      << "\t0 - no\n"
                      << "\t1 - yes\n";
            int item3 = GET_int(0, 1);
            if (item3 == 1) {
                Line_Form->pop(item1);
            }
            continue;
        }
    }
}





#endif //DAR_H_INTERFACEFORLINEFORM_H
