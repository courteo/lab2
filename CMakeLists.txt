cmake_minimum_required(VERSION 3.17)
project(prosto)
SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_CXX_STANDARD 14)

add_executable(prosto main.cpp Dynamic_array.h DynamicArrayTest.h link_list.h link_listTest.h linkseq.h LinkSeqTest.h  ArraySequence.h ArraySequenceTest.h polynomial.h PolTest.h  sequence.h interface.h  Vector.cpp Vector.h Line_Form.h Line_Form.cpp interfaceForVector.h interfaceForLineForm.h)