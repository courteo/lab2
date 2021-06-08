#include <iostream>
#include "interface.h"
#include "interfaceForVector.h"
#include "interfaceForLineForm.h"
#include "Vector.h"
#include "Line_Form.h"


using namespace std;

int main() {
    while (true){
        std::cout << "Choose type of data struct\n"
                  << "\t0 - exit\n"
                  << "\t1 - Polynom\n"
                  << "\t2 - Vector\n"
                  << "\t3 - Line Form\n";
        int item = GET_int(0, 3);

        if (item == 0)
            break;

        switch (item) {
            case 1:
                    interface();
                    break;
            case 2:
                    interfaceForVector();
                    break;
            case 3:
                    interfaceForLine_Form();
                    break;

        }
    }

    return 0;
}
