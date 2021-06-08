#ifndef PROSTO_POLTEST_H
#define PROSTO_POLTEST_H
#include "polynomial.h"
#include "assert.h"

void PolTestInt(){
    Polynomial<int> pol(3);

    pol.set_i(0, 1);
    pol.set_i(1, 2);
    pol.set_i(2, 3);

    assert(17 == pol.value(2));

    Polynomial<int> pol1(2);
    pol1.set_i(0, 2);
    pol1.set_i(1, 3);

    pol.add(pol1);
    assert(pol.get_i(0) == 3);
    assert(pol.get_i(1) == 5);

    pol.sub(pol1);
    assert(pol.get_i(0) == 1);
    assert(pol.get_i(1) == 2);

    pol.onScalar(2);
    assert(pol.get_i(0) == 2);
    assert(pol.get_i(1) == 4);
    assert(pol.get_i(2) == 6);


    pol.mult(pol1);


    assert(pol.get_i(0) == 4);
    assert(pol.get_i(1) == 5);
    assert(pol.get_i(2) == 6);
    assert(pol.get_i(3) == 7);
    assert(pol.get_i(4) == 8);
    assert(pol.get_i(5) == 9);

    pol = pol + pol1;
    assert(pol.get_i(0) == 6);
    assert(pol.get_i(1) == 8);
    assert(pol.get_i(2) == 6);
    assert(pol.get_i(3) == 7);
    assert(pol.get_i(4) == 8);
    assert(pol.get_i(5) == 9);

    pol += pol1;
    assert(pol.get_i(0) == 8);
    assert(pol.get_i(1) == 11);
    assert(pol.get_i(2) == 6);
    assert(pol.get_i(3) == 7);
    assert(pol.get_i(4) == 8);
    assert(pol.get_i(5) == 9);

    pol = pol - pol1;
    assert(pol.get_i(0) == 6);
    assert(pol.get_i(1) == 8);
    assert(pol.get_i(2) == 6);
    assert(pol.get_i(3) == 7);
    assert(pol.get_i(4) == 8);
    assert(pol.get_i(5) == 9);

    pol -= pol1;
    assert(pol.get_i(0) == 4);
    assert(pol.get_i(1) == 5);
    assert(pol.get_i(2) == 6);
    assert(pol.get_i(3) == 7);
    assert(pol.get_i(4) == 8);
    assert(pol.get_i(5) == 9);

    Polynomial<int> pol2(3);
    pol2.set_i(0, 2);
    pol2.set_i(1, 4);
    pol2.set_i(2, 6);

    pol2 = pol2 * pol1;
    assert(pol2.get_i(0) == 4);
    assert(pol2.get_i(1) == 5);
    assert(pol2.get_i(2) == 6);
    assert(pol2.get_i(3) == 7);
    assert(pol2.get_i(4) == 8);
    assert(pol2.get_i(5) == 9);

    Polynomial<int> pol3(3);
    pol3.set_i(0, 2);
    pol3.set_i(1, 4);
    pol3.set_i(2, 6);

    pol3 *= pol1;
    assert(pol3.get_i(0) == 4);
    assert(pol3.get_i(1) == 5);
    assert(pol3.get_i(2) == 6);
    assert(pol3.get_i(3) == 7);
    assert(pol3.get_i(4) == 8);
    assert(pol3.get_i(5) == 9);
}

#endif //PROSTO_POLTEST_H
