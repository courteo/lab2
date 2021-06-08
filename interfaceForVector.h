#ifndef DAR_H_INTERFACEFORVECTOR_H
#define DAR_H_INTERFACEFORVECTOR_H
#include "ArraySequence.h"
#include "Vector.h"
#include "complex"

void deleteVector(int item, ArraySequence<Vector<int>> *VectorInt,
ArraySequence<Vector<double>> *VectorDouble, ArraySequence<Vector<std::complex<int>>> *VectorComp);

template<class T>
void deleteTypeVector(ArraySequence<Vector<T>> *Vector);

void testFunc();

void printVec(int item, ArraySequence<Vector<int>> VecInt,
ArraySequence<Vector<double>> VecDouble, ArraySequence<Vector<std::complex<int>>> VecComp);

template<class T>
void printTypeVec(ArraySequence<Vector<T>> *Vector);


void printArr(int item, Vector<int> VecInt,
              Vector<double> VecDouble, Vector<std::complex<int>> VecComp);

template<class T>
void printTypeArr(Vector<T> Vector);


void readVector(int item, ArraySequence<Vector<int>> *VectorInt,
ArraySequence<Vector<double>> *VectorDouble, ArraySequence<Vector<std::complex<int>>> *VectorComp);
template<class T>
Vector<T> readTypeVector(int count);


int get_type();


void OperationWithVector(int item, ArraySequence<Vector<int>> *VectorInt,
ArraySequence<Vector<double>> *VectorDouble, ArraySequence<Vector<std::complex<int>>> *VectorComp);
template<class T>
void OperationWithTypeVector(ArraySequence<Vector<T>> *Vectors);

int Get_int() {
    int a;
    std::cin >> a;
    return a;
}
int Get_int(int up) {
    int a;
    std::cin >> a;
    if (a > up) {
        std::cout << "Число вне диапозона. Повторите попытку\n";
        return Get_int(up);
    }
    return a;
}

int Get_int(int down, int up) {
    int a = -2;
    std::cin >> a;
    if (a > up || a < down) {
        std::cout << "Retry\n";
        return Get_int(down, up);
    }
    return a;
}

double Get_double() {
    double a;
    std::cin >> a;
    return a;
}

std::complex<int> Get_complex() {
    int real = Get_int();
    int imag = Get_int();
    std::complex<int> a(real, imag);
    return a;
}

void interfaceForVector(){
    ArraySequence<Vector<int>> VecInt;
    ArraySequence<Vector<double>> VecDouble;
    ArraySequence<Vector<std::complex<int>>> VecComp;
    int item;
    while (true) {
        std::cout << "Choose option:\n"
                  << "\t1 - enter Vector\n"
                  << "\t2 - choose operation\n"
                  << "\t3 - print all Vectors\n"
                  << "\t4 - print Vector[i]\n"
                  << "\t5 - tests\n"
                  << "\t6 - delete\n"
                  << "\t0 - exit\n";
        item = Get_int(0, 6);
        if (item == 0) break;

        int item2 = get_type();
        switch (item) {
            case 1:
                readVector(item2, &VecInt, &VecDouble,&VecComp);
                break;

            case 2:
                OperationWithVector(item2, &VecInt, &VecDouble, &VecComp);
                break;

            case 3:
                printVec(item2, VecInt, VecDouble,VecComp);
                break;
            case 4: {
                int item3;
                std::cout << "enter number of element\n";
                if (item2 == 1)
                    item3 = Get_int(0, VecInt.get_len() - 1);
                else
                    if (item2 == 2)
                        item3 =Get_int(0, VecDouble.get_len() - 1);
                    else  item3 =Get_int(0, VecComp.get_len() - 1);

                Vector<int> VecInt1;
                Vector<double> VecDouble1;
                Vector<std::complex<int>> VecComp1;
                if (VecInt.get_len() <= item3)
                    if (VecInt.get_len() > 0)
                        VecInt1 = VecInt.get_i(VecInt.get_len() - 1);
                    else
                        VecInt1 = Vector<int>();
                else
                    VecInt1 = VecInt.get_i(item3);


                if (VecDouble.get_len() <= item3)
                    if (VecDouble.get_len() > 0)
                        VecDouble1 = VecDouble.get_i(VecDouble.get_len() - 1);
                    else
                        VecDouble1 = Vector<double>();
                else
                    VecDouble1 = VecDouble.get_i(item3);

                if (VecComp.get_len() <= item3)
                    if (VecComp.get_len() > 0)
                        VecComp1 = VecComp.get_i(VecComp.get_len() - 1);
                    else
                        VecComp1 = Vector<std::complex<int>>();
                else
                    VecComp1 = VecComp.get_i(item3);

                printArr(item2, VecInt1, VecDouble1, VecComp1);
                break;
            }
            case 5:
                testFunc();
                break;
            case 6:
                deleteVector(item2, &VecInt, &VecDouble,&VecComp);
                break;
        }
    }

}

int Get_type() {
    std::cout << "Enter number to operate with certain data type: \n"
              << "\t1: int\n"
              << "\t2: double\n"
              << "\t3: complex<int>\n"
              << "\t0: exit\n"
              << ": ";
    return Get_int(0, 3);
}


void readVector(int item, ArraySequence<Vector<int>> *VectorInt,
ArraySequence<Vector<double>> *VectorDouble, ArraySequence<Vector<std::complex<int>>> *VectorComp) {
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

    Vector<int> VectorInt1;
    Vector<double> VectorDouble1;
    Vector<std::complex<int>> VectorComp1;
    switch (item) {
        case 1:
            VectorInt1 = readTypeVector<int>(count);
            VectorInt->append(VectorInt1);
            break;
        case 2:
            VectorDouble1 = readTypeVector<double>(count);
            VectorDouble->append(VectorDouble1);
            break;
        case 3:
            VectorComp1 = readTypeVector<std::complex<int>>(count);
            VectorComp->append(VectorComp1);
            break;
        default:
            break;
    }
}


void OperationWithVector(int item, ArraySequence<Vector<int>> *VectorInt,
ArraySequence<Vector<double>> *VectorDouble, ArraySequence<Vector<std::complex<int>>> *VectorComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            OperationWithTypeVector<int>(VectorInt);
            break;
        case 2:
            OperationWithTypeVector<double>(VectorDouble);
            break;
        case 3:
            OperationWithTypeVector<std::complex<int>>(VectorComp);
            break;
    }
}

template<class T>
void OperationWithTypeVector(ArraySequence<Vector<T>> *Vectors){
    if (Vectors->get_len() == 0){
        std::cout << "Vector doesnt exist\n";
        return;
    }

    while (true){
        auto length = Vectors->get_len();
        std::cout << "You have " << length << " Vectors\n"
                  << "\t - negative number for exit\n"
                  << "\t - index of Vecynom\n"
                  << "\t - number bigger than length for print all Vecynom\n";
        int item1 = Get_int();
        if (item1 < 0) break;

        if (item1 >= length){
            printTypeVec(Vectors);
            continue;
        }
        Vector<T> Vector1;
        Vector1 = Vectors->get_i(item1);

        std::cout << "What operation do you want to choose:\n"
                  << "\t0: exit\n"
                  << "\t1: sum Vector\n"
                  << "\t2: sub Vector\n"
                  << "\t3: mult On Scalar Vector\n"
                  << "\t4: mult Vector\n"
                  << "\t5: value Vector\n";
        int item = get_int(0, 5);

        if (item == 0) break;

        Vector<T> Vec1;
        Vector<T> Vecres;
        T value;

        if (item == 3 || item == 5){
            T element;
            std::cout << "Enter scalar:\n";
            std::cin >> element;

            if (item == 3){
                Vecres = *Vector1.scalarMult(element);
            }

            if (item == 5){
                std::cout << "Value is " << Vector1.Value() << "\n";
            }
                Vectors->append(Vecres);
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

            Vec1 = readTypeVector<T>(count);

            switch (item) {
                default: break;
                case 1: Vecres = Vec1 + Vector1; break;
                case 2: Vecres = Vector1 - Vec1; break;
                case 4: Vecres = Vec1 * Vector1; break;
            }
            printTypeArr(Vecres);
            std::cout << "Do you want to save Vector?\n"
                      << "\t0 - no\n"
                      << "\t1 - yes\n";
            int item2 = Get_int(0, 1);

            if (item2 == 1){
                Vectors->append(Vecres);
            }
        }
    }
}

void printVec(int item, ArraySequence<Vector<int>> VecInt,
ArraySequence<Vector<double>> VecDouble, ArraySequence<Vector<std::complex<int>>> VecComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            printTypeVec<int>(&VecInt);
            break;
        case 2:
            printTypeVec<double>(&VecDouble);
            break;
        case 3:
            printTypeVec<std::complex<int>>(&VecComp);
            break;
    }
}


void printArr(int item, Vector<int> VecInt,
              Vector<double> VecDouble, Vector<std::complex<int>> VecComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            printTypeArr<int>(VecInt);
            break;
        case 2:
            printTypeArr<double>(VecDouble);
            break;
        case 3:
            printTypeArr<std::complex<int>>(VecComp);
            break;
    }
}

template<class T>
void printTypeVec(ArraySequence<Vector<T>> *Vector1){
    for (int i = 0; i < Vector1->get_len(); i++) {
        std::cout << Vector1->get_i(i) << "  ";
    }
    std::cout << "\n";
}

template<class T>
void printTypeArr(Vector<T> Vector){
    std::cout << Vector << "\n";
}

template<class T>
Vector<T> readTypeVector(int count) {
    std::cout << "Enter the elements:\n";
    auto arr = new ArraySequence<T>(count);

    for (int i = 0; i < count; i++) {
        T item;
        std::cin >> item;

        arr->set_i(i, item);
    }
    Vector<T> element(*arr);
    return element;
}

void deleteVector(int item, ArraySequence<Vector<int>> *VectorInt,
ArraySequence<Vector<double>> *VectorDouble, ArraySequence<Vector<std::complex<int>>> *VectorComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            deleteTypeVector<int>(VectorInt);
            break;
        case 2:
            deleteTypeVector<double>(VectorDouble);
            break;
        case 3:
            deleteTypeVector<std::complex<int>>(VectorComp);
            break;
    }
}


template<class T>
void deleteTypeVector(ArraySequence<Vector<T>> *Vector){
    if (Vector->get_len() == 0){
        std::cout << " Vecynom doesnt exist\n";
        return;
    }

    while (true){
        int length = Vector->get_len();
        if (length == 0){
            std::cout<< " Vecynom doesnt exist\n";
            break;
        }

        std::cout << "You have " << length << " Vectors\n"
                  << "\t - negative number for exit\n"
                  << "\t - index of Vecynom\n"
                  << "\t - number bigger than length for print all Vecynom\n";
        int item1 = Get_int();
        if (item1 < 0) break;

        if (item1 >= length){
            printTypeVec(Vector);
            continue;
        }

        std::cout << "Choose operation:\n"
                  << "\t-1:  return to choosing index\n"
                  << "\t0: delete\n";

        int item2 = Get_int(-1,0);

        if (item2 == -1) continue;

        if (item2 == 0){
            std::cout << "Do you really want to delete Vec[" << item1 <<"]?"
                      << "\t0 - no\n"
                      << "\t1 - yes\n";
            int item3 = Get_int(0, 1);
            if (item3 == 1) {
                Vector->pop(item1);
            }
            continue;
        }
    }
}




#endif //DAR_H_INTERFACEFORVECTOR_H
