cmake_minimum_required(VERSION 3.13)
project(AVL_tree_v2)

set(CMAKE_CXX_STANDARD 14)

add_executable(AVL_tree_v2 main.cpp
        BinnaryTree.cpp BinnaryTree.h
        Element.cpp Element.h
        ITree.h
        Tree.cpp Tree.h
        AVLTree.cpp AVLTree.h
        Node.cpp Node.h
        BTreeNode.h BTreeNode.cpp
        BTree.h BTree.cpp
        LinkedHashEntry.h LinkedHashEntry.cpp
        HashMap.h HashMap.h)