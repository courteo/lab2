#include "link_list.h"
#include "assert.h"

#ifndef DAR_H_LINK_LISTTEST_H
#define DAR_H_LINK_LISTTEST_H

void LinkListTestInt(){
    Linked_List<int> pol(4);
    pol.set_i(0, 1);
    pol.set_i(1, 3);
    pol.set_i(2, 3);
    pol.set_i(3, 4);
    pol.set_i(1,2);
    Linked_List<int> pol1(4);
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
    pol1.append(3);
    assert(1 == pol1.get_i(0));
    assert(2 == pol1.get_i(1));
    assert(3 == pol1.get_i(2));
    assert(4 == pol1.get_i(3));
    assert(3 == pol1.get_i(4));
}

void LinkListTestDouble(){
    Linked_List<double> pol(4);
    pol.set_i(0, 1);
    pol.set_i(1, 3);
    pol.set_i(2, 3);
    pol.set_i(3, 4);
    pol.set_i(1,2);
    Linked_List<double> pol1(4);
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
    pol1.append(3);
    assert(1 == pol1.get_i(0));
    assert(2 == pol1.get_i(1));
    assert(3 == pol1.get_i(2));
    assert(4 == pol1.get_i(3));
    assert(3 == pol1.get_i(4));
}
#endif //DAR_H_LINK_LISTTEST_H
