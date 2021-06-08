#ifndef PROSTO_DYNAMICARRAYTEST_H
#define PROSTO_DYNAMICARRAYTEST_H
#include "Dynamic_array.h"
#include "assert.h"


void DynamicArrayTestInt(){
    Dynamic_array<int> pol(4);
    pol.set_i(0, 1);
    pol.set_i(1, 3);
    pol.set_i(2, 3);
    pol.set_i(3, 4);
    pol.set_i(1,2);
    Dynamic_array<int> pol1(4);
    pol1.set_i(0, 1);
    pol1.set_i(1, 2);
    pol1.set_i(2, 3);
    pol1.set_i(3, 4);
    assert(pol.get_i(0) == pol1.get_i(0));
    assert(pol.get_i(1) == pol1.get_i(1));
    assert(pol.get_i(2) == pol1.get_i(2));
    assert(pol.get_i(3) == pol1.get_i(3));
    assert(pol.get_i(0) == 1);
    assert(pol.get_i(0) == pol.get_first());
    pol1.resize(5);
    assert(1 == pol1.get_i(0));
    assert(2 == pol1.get_i(1));
    assert(3 == pol1.get_i(2));
    assert(4 == pol1.get_i(3));
    assert(0 == pol1.get_i(4));
}

void DynamicArrayTestDouble(){
    Dynamic_array<double> pol(4);
    pol.set_i(0, 1);
    pol.set_i(1, 3);
    pol.set_i(2, 3);
    pol.set_i(3, 4);
    pol.set_i(1,2);
    Dynamic_array<double> pol1(4);
    pol1.set_i(0, 1);
    pol1.set_i(1, 2);
    pol1.set_i(2, 3);
    pol1.set_i(3, 4);
    assert(pol.get_i(0) == pol1.get_i(0));
    assert(pol.get_i(1) == pol1.get_i(1));
    assert(pol.get_i(2) == pol1.get_i(2));
    assert(pol.get_i(3) == pol1.get_i(3));
    assert(pol.get_i(0) == 1);
    assert(pol.get_i(0) == pol.get_first());
    pol1.resize(5);
    assert(1 == pol1.get_i(0));
    assert(2 == pol1.get_i(1));
    assert(3 == pol1.get_i(2));
    assert(4 == pol1.get_i(3));
    assert(0 == pol1.get_i(4));
}

void DynamicArrayTestComplex(){
    Dynamic_array<int> pol(4);
    pol.set_i(0, 1);
    pol.set_i(1, 3);
    pol.set_i(2, 3);
    pol.set_i(3, 4);
    pol.set_i(1,2);
    Dynamic_array<int> pol1(4);
    pol1.set_i(0, 1);
    pol1.set_i(1, 2);
    pol1.set_i(2, 3);
    pol1.set_i(3, 4);
    assert(pol.get_i(0) == pol1.get_i(0));
    assert(pol.get_i(1) == pol1.get_i(1));
    assert(pol.get_i(2) == pol1.get_i(2));
    assert(pol.get_i(3) == pol1.get_i(3));
    assert(pol.get_i(0) == 1);
    assert(pol.get_i(0) == pol.get_first());
    pol1.resize(5);
    assert(1 == pol1.get_i(0));
    assert(2 == pol1.get_i(1));
    assert(3 == pol1.get_i(2));
    assert(4 == pol1.get_i(3));
    assert(0 == pol1.get_i(4));
}

#endif //PROSTO_DYNAMICARRAYTEST_H
