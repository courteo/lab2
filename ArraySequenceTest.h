#ifndef DAR_H_ARRAYSEQUENCETEST_H
#define DAR_H_ARRAYSEQUENCETEST_H
#include "ArraySequence.h"
#include "assert.h"
#include "complex"

void ArraySequenceTestInt(){

    int arr[] = {0, 1, 2};
    ArraySequence<int> pol(3, arr);

    pol.append(5);
    assert(pol.get_i(3) == 5);

    pol.prepend(4);
    assert(pol.get_i(0) == 4);
    assert(pol.get_len() == 5);

    int arr1[] = {1, 2 };
    int arr2[] = {4, 0, 1, 2, 5, 1 , 2};
    ArraySequence<int> pol2(7, arr2);
    ArraySequence<int> pol1(2, arr1);

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

void ArraySequenceTestDouble(){

    double arr[] = {0, 1, 2};
    ArraySequence<double> pol(3, arr);

    pol.append(5);
    assert(pol.get_i(3) == 5);

    pol.prepend(4);
    assert(pol.get_i(0) == 4);
    assert(pol.get_len() == 5);

    double arr1[] = {1, 2 };
    double arr2[] = {4, 0, 1, 2, 5, 1 , 2};
    ArraySequence<double> pol2(7, arr2);
    ArraySequence<double> pol1(2, arr1);

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

void ArraySequenceTestComp(){

    std::complex<int> arr[] = {0, 1, 2};
    ArraySequence<std::complex<int>> pol(3, arr);

    pol.append(5);
    assert(pol.get_i(3) == 5);

    pol.prepend(4);
    assert(pol.get_i(0) == 4);
    assert(pol.get_len() == 5);

    std::complex<int> arr1[] = {1, 2 };
    std::complex<int> arr2[] = {4, 0, 1, 2, 5, 1 , 2};
    ArraySequence<std::complex<int>> pol2(7, arr2);
    ArraySequence<std::complex<int>> pol1(2, arr1);

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

#endif //DAR_H_ARRAYSEQUENCETEST_H
