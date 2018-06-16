cmake_minimum_required(VERSION 3.8)
project(MyCodeWareHouse)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Non-recursive-BinTree.cpp Non-recursive-BinTree.h Heap.h HuffmanTree.h fileCompress.h adaptive-huffman.cpp vitter.cppp AVL-Tree.h RBTree.h BloomFilter.h BitMap.h cLib/str.cpp bigNum.cpp cLib/myA2i.cpp algorithm/quickSort.h)
add_executable(MyCodeWareHouse ${SOURCE_FILES})