#include "linkseq.h"
#include "assert.h"
#include "complex"

#ifndef DAR_H_LINKSEQTEST_H
#define DAR_H_LINKSEQTEST_H

void LinkedSequenceTestInt(){


    LinkedSequence<int> pol(3);
    pol.set_i(0, 0);
    pol.set_i(1, 1);
    pol.set_i(2, 2);

    pol.append(5);
    assert(pol.get_i(3) == 5);

    pol.prepend(4);
    assert(pol.get_i(0) == 4);
    assert(pol.get_len() == 5);


    LinkedSequence<int> pol2(7);
    pol2.set_i(0, 4);
    pol2.set_i(1, 0);
    pol2.set_i(2, 1);
    pol2.set_i(3, 2);
    pol2.set_i(4, 5);
    pol2.set_i(5, 1);
    pol2.set_i(6, 2);

    LinkedSequence<int> pol1(2);
    pol1.set_i(0, 1);
    pol1.set_i(1, 2);


    pol.concat(&pol1);
    assert(pol2.get_i(0) == pol.get_i(0));
    assert(pol2.get_i(1) == pol.get_i(1));
    assert(pol2.get_i(2) == pol.get_i(2));
    assert(pol2.get_i(3) == pol.get_i(3));
    assert(pol2.get_i(4) == pol.get_i(4));
    assert(pol2.get_i(5) == pol.get_i(5));
    assert(pol2.get_i(6) == pol.get_i(6));

    pol.insert(2, 1);
    assert(pol.get_i(0) == 4);
    assert(pol.get_i(1) == 2);
    assert(pol.get_i(2) == 0);

    auto *res = pol.getSubSequence(1, 3);
    assert(res->get_len() == 3);
    assert(res->get_i(0) == 2);
    assert(res->get_i(1) == 0);
    assert(res->get_i(2) == 1);
    auto *res1 = pol.split(3);

    assert(res1->get_i(0)->get_i(0) == 4);
    assert(res1->get_i(0)->get_i(1) == 2);
    assert(res1->get_i(0)->get_i(2) == 0);
    assert(res1->get_i(1)->get_i(0) == 2);
    assert(res1->get_i(1)->get_i(1) == 5);
    assert(res1->get_i(1)->get_i(2) == 1);
    assert(res1->get_i(1)->get_i(3) == 2);

    auto *res2 = pol.zip(pol1);
    assert(res2->get_i(0)->get_i(0) == 4);
    assert(res2->get_i(0)->get_i(1) == 1);
    assert(res2->get_i(1)->get_i(0) == 2);
    assert(res2->get_i(1)->get_i(1) == 2);


    assert(pol.where(2) == 1);



}

void LinkedSequenceTestDouble(){

    LinkedSequence<int> pol(3);
    pol.set_i(0, 0);
    pol.set_i(1, 1);
    pol.set_i(2, 2);

    pol.append(5);
    assert(pol.get_i(3) == 5);

    pol.prepend(4);
    assert(pol.get_i(0) == 4);
    assert(pol.get_len() == 5);

    LinkedSequence<int> pol2(7);
    pol2.set_i(0, 4);
    pol2.set_i(1, 0);
    pol2.set_i(2, 1);
    pol2.set_i(3, 2);
    pol2.set_i(4, 5);
    pol2.set_i(5, 1);
    pol2.set_i(6, 2);

    LinkedSequence<int> pol1(2);
    pol1.set_i(0, 1);
    pol1.set_i(1, 2);

    pol.concat(&pol1);
    assert(pol2.get_i(0) == pol.get_i(0));
    assert(pol2.get_i(1) == pol.get_i(1));
    assert(pol2.get_i(2) == pol.get_i(2));
    assert(pol2.get_i(3) == pol.get_i(3));
    assert(pol2.get_i(4) == pol.get_i(4));
    assert(pol2.get_i(5) == pol.get_i(5));
    assert(pol2.get_i(6) == pol.get_i(6));

    pol.insert(2, 1);
    assert(pol.get_i(0) == 4);
    assert(pol.get_i(1) == 2);
    assert(pol.get_i(2) == 0);

    auto *res = pol.getSubSequence(1, 3);
    assert(res->get_len() == 3);
    assert(res->get_i(0) == 2);
    assert(res->get_i(1) == 0);
    assert(res->get_i(2) == 1);
    auto *res1 = pol.split(3);

    assert(res1->get_i(0)->get_i(0) == 4);
    assert(res1->get_i(0)->get_i(1) == 2);
    assert(res1->get_i(0)->get_i(2) == 0);
    assert(res1->get_i(1)->get_i(0) == 2);
    assert(res1->get_i(1)->get_i(1) == 5);
    assert(res1->get_i(1)->get_i(2) == 1);
    assert(res1->get_i(1)->get_i(3) == 2);

    auto *res2 = pol.zip(pol1);
    assert(res2->get_i(0)->get_i(0) == 4);
    assert(res2->get_i(0)->get_i(1) == 1);
    assert(res2->get_i(1)->get_i(0) == 2);
    assert(res2->get_i(1)->get_i(1) == 2);








}

#endif //DAR_H_LINKSEQTEST_H
