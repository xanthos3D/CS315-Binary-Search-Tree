#include <iostream>

#include "BinSearchTree.hpp"
#include "TreeNode.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"

int main( int argc, char *argv[] ) {
    // create a tree and then print the values of its nodes
    // from the smallest to the largest.

    if( argc != 2 ) {
        std::cout << "usage: executable name-of-input-file\n";
        exit(5);
    }
    std::fstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if(!inputStream.is_open()) {
        std::cout << "Unable to open the input file " <<
                  argv[1] << std::endl;
        std::cout << "Terminating...\n";
        exit(7);
    }


    BinSearchTree *tree1 = new BinSearchTree();

    int aValue;
    while( inputStream >> aValue )
        tree1->insert( aValue );

    // size has not been implemented. It currently returns zero
    // just so that the program compiles. You should write
    // an implementation for size first. Then, write an implementation for
    // find.


    int treeOriginalValues[] = {36, 104,89,32,43,79,30,54,41,120,117,56,41,35,122,108,41,85,39,75,67,87,31,117,38,116,54,55,84,34,101,72};

    BinSearchTree *emptyTree = new BinSearchTree();


    BinSearchTree *tree2 = new BinSearchTree();
    int tree2Values1[] = {};
    for(int i = 0; i < sizeof(tree2Values1)/sizeof(tree2Values1[0]) ;i++) {
    tree2->insert(tree2Values1[i]);
}

    std::cout<<"case 1===================================================================================="<< std::endl;
     tree2->insert(25);
    std::cout<<"testing if removing a node from a tree with only one node works."<<std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 25 from tree2 if it exists: "<< tree2->remove(25) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 25: "<<tree2->find(25)<<std::endl;
    tree2->insert(25);

    std::cout<<"case 2===================================================================================="<< std::endl;
    std::cout<<"testing if removing the root while it has a left node works"<<std::endl;
    tree2->insert(25);
    tree2->insert(20);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 25 from tree2 if it exists: "<< tree2->remove(25) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 25: "<<tree2->find(25)<<std::endl;
    std::cout<<"Removing Element 20 from tree2 if it exists: "<< tree2->remove(20) << std::endl;

    std::cout<<"case 3===================================================================================="<< std::endl;
    std::cout<<"testing if removing the root while it has a left node works if that left node has children"<<std::endl;
    tree2->insert(25);
    tree2->insert(20);
    tree2->insert(23);
    tree2->insert(15);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 25 from tree2 if it exists: "<< tree2->remove(25) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 25: "<<tree2->find(25)<<std::endl;
    tree2->remove(20);
    tree2->remove(23);
    tree2->remove(15);

    std::cout<<"case 4===================================================================================="<< std::endl;
    std::cout<<"testing if removing the root while it has a left node works if that left node has children but to an extreme degree"<<std::endl;
    tree2->insert(25);
    tree2->insert(20);
    tree2->insert(21);
    tree2->insert(15);
    tree2->insert(14);
    tree2->insert(10);
    tree2->insert(2);
    tree2->insert(23);
    tree2->insert(23);
    tree2->insert(24);
    tree2->insert(22);
    tree2->insert(18);
    tree2->insert(17);
    tree2->insert(13);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 25 from tree2 if it exists: "<< tree2->remove(25) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 25: "<<tree2->find(25)<<std::endl;
    tree2->remove(25);
    tree2->remove(20);
    tree2->remove(21);
    tree2->remove(15);
    tree2->remove(14);
    tree2->remove(10);
    tree2->remove(2);
    tree2->remove(23);
    tree2->remove(23);
    tree2->remove(24);
    tree2->remove(22);
    tree2->remove(18);
    tree2->remove(17);
    tree2->remove(13);

    std::cout<<"case 6===================================================================================="<< std::endl;
    std::cout<<"testing if removing the root while it has a right node works"<<std::endl;
    tree2->insert(25);
    tree2->insert(30);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 25 from tree2 if it exists: "<< tree2->remove(25) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 25: "<<tree2->find(25)<<std::endl;
    std::cout<<"Removing Element 30 from tree2 if it exists: "<< tree2->remove(30) << std::endl;

    std::cout<<"case 6===================================================================================="<< std::endl;
    std::cout<<"testing if removing the root while it has a right node works if that right node has children"<<std::endl;
    tree2->insert(25);
    tree2->insert(30);
    tree2->insert(26);
    tree2->insert(35);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 25 from tree2 if it exists: "<< tree2->remove(25) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 25: "<<tree2->find(25)<<std::endl;
    tree2->remove(30);
    tree2->remove(26);
    tree2->remove(35);

    std::cout<<"case 7===================================================================================="<< std::endl;
    std::cout<<"testing if removing the root while it has a right node works if that right node has children but to an extreme degree"<<std::endl;
    tree2->insert(25);
    tree2->insert(30);
    tree2->insert(26);
    tree2->insert(28);
    tree2->insert(27);
    tree2->insert(29);
    tree2->insert(31);
    tree2->insert(35);
    tree2->insert(34);
    tree2->insert(37);
    tree2->insert(36);
    tree2->insert(38);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 25 from tree2 if it exists: "<< tree2->remove(25) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 25: "<<tree2->find(25)<<std::endl;
    tree2->remove(25);
    tree2->remove(30);
    tree2->remove(26);
    tree2->remove(28);
    tree2->remove(27);
    tree2->remove(29);
    tree2->remove(31);
    tree2->remove(35);
    tree2->remove(34);
    tree2->remove(37);
    tree2->remove(36);
    tree2->remove(38);

    std::cout<<"case 8===================================================================================="<< std::endl;
    std::cout<<"testing if removing the root while it has a left and right node works"<<std::endl;
    tree2->insert(25);
    tree2->insert(15);
    tree2->insert(35);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 25 from tree2 if it exists: "<< tree2->remove(25) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 25: "<<tree2->find(25)<<std::endl;
    std::cout<<"Removing Element 15 from tree2 if it exists: "<< tree2->remove(15) << std::endl;
    std::cout<<"Removing Element 35 from tree2 if it exists: "<< tree2->remove(35) << std::endl;

    std::cout<<"case 9===================================================================================="<< std::endl;
    std::cout<<"testing if removing the root while it has a right node works if that right node has children but to an extreme degree"<<std::endl;
    tree2->insert(25);
    tree2->insert(15);
    tree2->insert(35);
    tree2->insert(10);
    tree2->insert(20);
    tree2->insert(30);
    tree2->insert(40);
    tree2->insert(5);
    tree2->insert(9);
    tree2->insert(18);
    tree2->insert(23);
    tree2->insert(38);
    tree2->insert(45);
    tree2->insert(17);
    tree2->insert(19);
    tree2->insert(22);
    tree2->insert(24);
    tree2->insert(44);
    tree2->insert(49);
    tree2->insert(16);
    tree2->insert(21);
    tree2->insert(43);
    tree2->insert(48);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 25 from tree2 if it exists: "<< tree2->remove(25) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 25: "<<tree2->find(25)<<std::endl;
    tree2->remove(25);
    tree2->remove(15);
    tree2->remove(35);
    tree2->remove(10);
    tree2->remove(20);
    tree2->remove(30);
    tree2->remove(40);
    tree2->remove(5);
    tree2->remove(9);
    tree2->remove(18);
    tree2->remove(23);
    tree2->remove(38);
    tree2->remove(45);
    tree2->remove(17);
    tree2->remove(19);
    tree2->remove(22);
    tree2->remove(24);
    tree2->remove(44);
    tree2->remove(49);
    tree2->remove(16);
    tree2->remove(21);
    tree2->remove(43);
    tree2->remove(48);

    std::cout<<"case 10===================================================================================="<< std::endl;
    std::cout<<"testing if removing the root while it has a left and right node works while the predecessor has a left node."<<std::endl;
    tree2->insert(25);
    tree2->insert(15);
    tree2->insert(35);
    tree2->insert(17);
    tree2->insert(23);
    tree2->insert(19);
    tree2->insert(18);
    tree2->insert(20);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 25 from tree2 if it exists: "<< tree2->remove(25) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 25: "<<tree2->find(25)<<std::endl;
    tree2->remove(25);
    tree2->remove(15);
    tree2->remove(35);
    tree2->remove(17);
    tree2->remove(23);
    tree2->remove(19);
    tree2->remove(18);
    tree2->remove(20);

    std::cout<<"case 11===================================================================================="<< std::endl;
    std::cout<<"testing if single branch deletions work"<<std::endl;
    tree2->insert(50);
    tree2->insert(25);
    tree2->insert(75);
    tree2->insert(10);
    tree2->insert(35);
    tree2->insert(60);
    tree2->insert(90);
    tree2->insert(8);
    tree2->insert(40);
    tree2->insert(57);
    tree2->insert(100);
    tree2->insert(5);
    tree2->insert(9);
    tree2->insert(36);
    tree2->insert(41);
    tree2->insert(55);
    tree2->insert(59);
    tree2->insert(95);
    tree2->insert(105);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 10 from tree2 if it exists: "<< tree2->remove(10) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 10: "<<tree2->find(10)<<std::endl;
    tree2->remove(50);
    tree2->remove(25);
    tree2->remove(75);
    tree2->remove(10);
    tree2->remove(35);
    tree2->remove(60);
    tree2->remove(90);
    tree2->remove(8);
    tree2->remove(40);
    tree2->remove(57);
    tree2->remove(100);
    tree2->remove(5);
    tree2->remove(9);
    tree2->remove(36);
    tree2->remove(41);
    tree2->remove(55);
    tree2->remove(59);
    tree2->remove(95);
    tree2->remove(105);

    std::cout<<"case 12===================================================================================="<< std::endl;
    std::cout<<"testing if single branch deletions work"<<std::endl;
    tree2->insert(50);
    tree2->insert(25);
    tree2->insert(75);
    tree2->insert(10);
    tree2->insert(35);
    tree2->insert(60);
    tree2->insert(90);
    tree2->insert(8);
    tree2->insert(40);
    tree2->insert(57);
    tree2->insert(100);
    tree2->insert(5);
    tree2->insert(9);
    tree2->insert(36);
    tree2->insert(41);
    tree2->insert(55);
    tree2->insert(59);
    tree2->insert(95);
    tree2->insert(105);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 35 from tree2 if it exists: "<< tree2->remove(35) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 35: "<<tree2->find(35)<<std::endl;
    tree2->remove(50);
    tree2->remove(25);
    tree2->remove(75);
    tree2->remove(10);
    tree2->remove(35);
    tree2->remove(60);
    tree2->remove(90);
    tree2->remove(8);
    tree2->remove(40);
    tree2->remove(57);
    tree2->remove(100);
    tree2->remove(5);
    tree2->remove(9);
    tree2->remove(36);
    tree2->remove(41);
    tree2->remove(55);
    tree2->remove(59);
    tree2->remove(95);
    tree2->remove(105);

    std::cout<<"case 13===================================================================================="<< std::endl;
    std::cout<<"testing if single branch deletions work"<<std::endl;
    tree2->insert(50);
    tree2->insert(25);
    tree2->insert(75);
    tree2->insert(10);
    tree2->insert(35);
    tree2->insert(60);
    tree2->insert(90);
    tree2->insert(8);
    tree2->insert(40);
    tree2->insert(57);
    tree2->insert(100);
    tree2->insert(5);
    tree2->insert(9);
    tree2->insert(36);
    tree2->insert(41);
    tree2->insert(55);
    tree2->insert(59);
    tree2->insert(95);
    tree2->insert(105);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 60 from tree2 if it exists: "<< tree2->remove(60) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 60: "<<tree2->find(60)<<std::endl;
    tree2->remove(50);
    tree2->remove(25);
    tree2->remove(75);
    tree2->remove(10);
    tree2->remove(35);
    tree2->remove(60);
    tree2->remove(90);
    tree2->remove(8);
    tree2->remove(40);
    tree2->remove(57);
    tree2->remove(100);
    tree2->remove(5);
    tree2->remove(9);
    tree2->remove(36);
    tree2->remove(41);
    tree2->remove(55);
    tree2->remove(59);
    tree2->remove(95);
    tree2->remove(105);

    std::cout<<"case 14===================================================================================="<< std::endl;
    std::cout<<"testing if single branch deletions work"<<std::endl;
    tree2->insert(50);
    tree2->insert(25);
    tree2->insert(75);
    tree2->insert(10);
    tree2->insert(35);
    tree2->insert(60);
    tree2->insert(90);
    tree2->insert(8);
    tree2->insert(40);
    tree2->insert(57);
    tree2->insert(100);
    tree2->insert(5);
    tree2->insert(9);
    tree2->insert(36);
    tree2->insert(41);
    tree2->insert(55);
    tree2->insert(59);
    tree2->insert(95);
    tree2->insert(105);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 90 from tree2 if it exists: "<< tree2->remove(90) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 90: "<<tree2->find(90)<<std::endl;
    tree2->remove(50);
    tree2->remove(25);
    tree2->remove(75);
    tree2->remove(10);
    tree2->remove(35);
    tree2->remove(60);
    tree2->remove(90);
    tree2->remove(8);
    tree2->remove(40);
    tree2->remove(57);
    tree2->remove(100);
    tree2->remove(5);
    tree2->remove(9);
    tree2->remove(36);
    tree2->remove(41);
    tree2->remove(55);
    tree2->remove(59);
    tree2->remove(95);
    tree2->remove(105);

    std::cout<<"case 15===================================================================================="<< std::endl;
    std::cout<<"testing if single branch deletions work"<<std::endl;
    tree2->insert(50);
    tree2->insert(25);
    tree2->insert(75);
    tree2->insert(10);
    tree2->insert(35);
    tree2->insert(60);
    tree2->insert(90);
    tree2->insert(15);
    tree2->insert(30);
    tree2->insert(65);
    tree2->insert(85);
    tree2->insert(13);
    tree2->insert(16);
    tree2->insert(29);
    tree2->insert(33);
    tree2->insert(63);
    tree2->insert(66);
    tree2->insert(83);
    tree2->insert(87);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 10 from tree2 if it exists: "<< tree2->remove(10) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 10: "<<tree2->find(10)<<std::endl;
    tree2->remove(50);
    tree2->remove(25);
    tree2->remove(75);
    tree2->remove(10);
    tree2->remove(35);
    tree2->remove(60);
    tree2->remove(90);
    tree2->remove(15);
    tree2->remove(30);
    tree2->remove(65);
    tree2->remove(85);
    tree2->remove(13);
    tree2->remove(16);
    tree2->remove(29);
    tree2->remove(33);
    tree2->remove(63);
    tree2->remove(66);
    tree2->remove(83);
    tree2->remove(87);

    std::cout<<"case 16===================================================================================="<< std::endl;
    std::cout<<"testing if single branch deletions work"<<std::endl;
    tree2->insert(50);
    tree2->insert(25);
    tree2->insert(75);
    tree2->insert(10);
    tree2->insert(35);
    tree2->insert(60);
    tree2->insert(90);
    tree2->insert(15);
    tree2->insert(30);
    tree2->insert(65);
    tree2->insert(85);
    tree2->insert(13);
    tree2->insert(16);
    tree2->insert(29);
    tree2->insert(33);
    tree2->insert(63);
    tree2->insert(66);
    tree2->insert(83);
    tree2->insert(87);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 35 from tree2 if it exists: "<< tree2->remove(35) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 35: "<<tree2->find(35)<<std::endl;
    tree2->remove(50);
    tree2->remove(25);
    tree2->remove(75);
    tree2->remove(10);
    tree2->remove(35);
    tree2->remove(60);
    tree2->remove(90);
    tree2->remove(15);
    tree2->remove(30);
    tree2->remove(65);
    tree2->remove(85);
    tree2->remove(13);
    tree2->remove(16);
    tree2->remove(29);
    tree2->remove(33);
    tree2->remove(63);
    tree2->remove(66);
    tree2->remove(83);
    tree2->remove(87);

    std::cout<<"case 17===================================================================================="<< std::endl;
    std::cout<<"testing if single branch deletions work"<<std::endl;
    tree2->insert(50);
    tree2->insert(25);
    tree2->insert(75);
    tree2->insert(10);
    tree2->insert(35);
    tree2->insert(60);
    tree2->insert(90);
    tree2->insert(15);
    tree2->insert(30);
    tree2->insert(65);
    tree2->insert(85);
    tree2->insert(13);
    tree2->insert(16);
    tree2->insert(29);
    tree2->insert(33);
    tree2->insert(63);
    tree2->insert(66);
    tree2->insert(83);
    tree2->insert(87);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 60 from tree2 if it exists: "<< tree2->remove(60) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 60: "<<tree2->find(60)<<std::endl;
    tree2->remove(50);
    tree2->remove(25);
    tree2->remove(75);
    tree2->remove(10);
    tree2->remove(35);
    tree2->remove(60);
    tree2->remove(90);
    tree2->remove(15);
    tree2->remove(30);
    tree2->remove(65);
    tree2->remove(85);
    tree2->remove(13);
    tree2->remove(16);
    tree2->remove(29);
    tree2->remove(33);
    tree2->remove(63);
    tree2->remove(66);
    tree2->remove(83);
    tree2->remove(87);

    std::cout<<"case 18===================================================================================="<< std::endl;
    std::cout<<"testing if single branch deletions work"<<std::endl;
    tree2->insert(50);
    tree2->insert(25);
    tree2->insert(75);
    tree2->insert(10);
    tree2->insert(35);
    tree2->insert(60);
    tree2->insert(90);
    tree2->insert(15);
    tree2->insert(30);
    tree2->insert(65);
    tree2->insert(85);
    tree2->insert(13);
    tree2->insert(16);
    tree2->insert(29);
    tree2->insert(33);
    tree2->insert(63);
    tree2->insert(66);
    tree2->insert(83);
    tree2->insert(87);
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 90 from tree2 if it exists: "<< tree2->remove(90) << std::endl;
    std::cout<<"printing the tree2 by level Order."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<std::endl<<"trying to find 90: "<<tree2->find(90)<<std::endl;
    tree2->remove(50);
    tree2->remove(25);
    tree2->remove(75);
    tree2->remove(10);
    tree2->remove(35);
    tree2->remove(60);
    tree2->remove(90);
    tree2->remove(15);
    tree2->remove(30);
    tree2->remove(65);
    tree2->remove(85);
    tree2->remove(13);
    tree2->remove(16);
    tree2->remove(29);
    tree2->remove(33);
    tree2->remove(63);
    tree2->remove(66);
    tree2->remove(83);
    tree2->remove(87);
    /*std::cout << " testing size:"<<tree1->size() << std::endl;
    std::cout << "testing if 55 is in binary tree: "<< tree1->find(55) << std::endl;
    std::cout << "testing if 135 is in binary tree: "<< tree1->find(135) << std::endl;
    std::cout << "testing if 55 is in binary tree: "<< tree1->iterFind(55) << std::endl;
    std::cout << "testing if 135 is in binary tree: "<< tree1->iterFind(135) << std::endl;
    std::cout<< "dumping out binary tree1 :";
    tree1->inorderDump();
    std::cout<<std::endl;
    std::cout << "maxDepth: "<< tree1->maxDepth() << std::endl;

    std::cout<<"levelOrderDump"<<std::endl;
    tree1->levelOrderDump();

    std::cout<<"Removing Element 32 if its in the binary tree. "<< tree1->remove(32) << std::endl;
    std::cout<<"printing the tree1."<<std::endl;
    tree1->levelOrderDump();
    std::cout<<"trying to find 32: "<<tree1->find(32)<<std::endl;


    std::cout<<"printing the tree2."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"Removing Element 36 if its in tree2. "<< tree2->remove(36) << std::endl;
    std::cout<<"printing the tree2."<<std::endl;
    tree2->levelOrderDump();
    std::cout<<"trying to find 36: "<<tree2->find(36)<<std::endl;

    /*std::cout<<"testing kSmallest, 0 smallest: "<<tree1->kthSmallest(0) <<std::endl;
    std::cout<<"testing kSmallest, 1 smallest: "<<tree1->kthSmallest(1) <<std::endl;
    std::cout<<"testing kSmallest, 2 smallest: "<<tree1->kthSmallest(2) <<std::endl;
    std::cout<<"testing kSmallest, 3 smallest: "<<tree1->kthSmallest(3) <<std::endl;
    std::cout<<"testing kSmallest, 4 smallest: "<<tree1->kthSmallest(4) <<std::endl;
    std::cout<<"testing kSmallest, 5 smallest: "<<tree1->kthSmallest(5) <<std::endl;
    std::cout<<"testing kSmallest, 25 smallest: "<<tree1->kthSmallest(25) <<std::endl;
    std::cout<<"testing kSmallest, 26 smallest: "<<tree1->kthSmallest(26) <<std::endl;
    std::cout<<"testing kSmallest, 27 smallest: "<<tree1->kthSmallest(27) <<std::endl;
    std::cout<<"testing kSmallest, 28 smallest: "<<tree1->kthSmallest(28) <<std::endl;
    std::cout<<"testing kSmallest, 29 smallest: "<<tree1->kthSmallest(29) <<std::endl;


    /*std::cout<<"printing out layer 1;"<<std::endl;
    tree1->valuesAtLevel(1);
    std::cout<<std::endl;
    std::cout<<"printing out layer 2;"<<std::endl;
    tree1->valuesAtLevel(2);
    std::cout<<std::endl;
    std::cout<<"printing out layer 3;"<<std::endl;
    tree1->valuesAtLevel(3);
    std::cout<<std::endl;
    std::cout<<"printing out layer 4;"<<std::endl;
    tree1->valuesAtLevel(4);
    std::cout<<std::endl;
    std::cout<<"printing out layer 5;"<<std::endl;
    tree1->valuesAtLevel(5);
    std::cout<<std::endl;
    std::cout<<"printing out layer 6;"<<std::endl;
    tree1->valuesAtLevel(6);
    std::cout<<std::endl;
    std::cout<<"printing out layer 7;"<<std::endl;
    tree1->valuesAtLevel(7);
    std::cout<<std::endl;
    std::cout<<"printing out layer 8;"<<std::endl;
    tree1->valuesAtLevel(8);
    std::cout<<std::endl;
    std::cout<<"printing out layer 9;"<<std::endl;
    tree1->valuesAtLevel(9);
    std::cout<<std::endl;
    std::cout<<"printing out layer 10;"<<std::endl;
    tree1->valuesAtLevel(10);
    std::cout<<std::endl;
    std::cout<<"printing out layer 11;"<<std::endl;
    tree1->valuesAtLevel(11);
    std::cout<<std::endl;

    //std::cout<<"Removing Element 32 if its in the binary tree. "<< tree1->remove(32) << std::endl;

    std::cout<<"iter printing out layer 1;"<<std::endl;
    tree1->iterValuesAtLevel(1);
    std::cout<<std::endl;
    std::cout<<"iter printing out layer 2;"<<std::endl;
    tree1->iterValuesAtLevel(2);
    std::cout<<std::endl;
    std::cout<<"iter printing out layer 3;"<<std::endl;
    tree1->iterValuesAtLevel(3);
    std::cout<<std::endl;
    std::cout<<"iter printing out layer 4;"<<std::endl;
    tree1->iterValuesAtLevel(4);
    std::cout<<std::endl;
    std::cout<<"iter printing out layer 5;"<<std::endl;
    tree1->iterValuesAtLevel(5);
    std::cout<<std::endl;
    std::cout<<"iter printing out layer 6;"<<std::endl;
    tree1->iterValuesAtLevel(6);
    std::cout<<std::endl;
    std::cout<<"iter printing out layer 7;"<<std::endl;
    tree1->iterValuesAtLevel(7);
    std::cout<<std::endl;
    std::cout<<"iter printing out layer 8;"<<std::endl;
    tree1->iterValuesAtLevel(8);
    std::cout<<std::endl;
    std::cout<<"iter printing out layer 9;"<<std::endl;
    tree1->iterValuesAtLevel(9);
    std::cout<<std::endl;
    std::cout<<"iter printing out layer 10;"<<std::endl;
    tree1->iterValuesAtLevel(10);
    std::cout<<std::endl;
    std::cout<<"iter printing out layer 11;"<<std::endl;
    tree1->iterValuesAtLevel(11);
    std::cout<<std::endl;

    std::cout<<"iterative MaxDepth of tree1 "<< tree1->iterMaxDepth();
    std::cout<<std::endl;

    //std::cout<<"Removing Element 72 if its in the binary tree. "<< tree1->remove(72) << std::endl;

    std::cout<<"iterative MaxDepth of tree1 "<< tree1->iterMaxDepth();
    std::cout<<std::endl;

    std::cout<<"iterative MaxDepth of tree2 "<< tree2->iterMaxDepth();
    std::cout<<std::endl;

    std::cout<<"testing if root to leaf sum for 330 on tree1: "<< tree1->hasRootToLeafSum(330);
    std::cout<<std::endl;
    std::cout<<"testing if root to leaf sum for 675 on tree1: "<< tree1->hasRootToLeafSum(675);
    std::cout<<std::endl;
    std::cout<<"testing if root to leaf sum for 5 on tree1: "<< tree1->hasRootToLeafSum(5);
    std::cout<<std::endl;
    std::cout<<"testing if root to leaf sum for 1546 on tree1: "<< tree1->hasRootToLeafSum(1546);
    std::cout<<std::endl;

    std::cout<<"printing the tree1."<<std::endl;
    tree1->levelOrderDump();

    std::cout<<"printing the tree2."<<std::endl;
    tree2->levelOrderDump();

    std::cout<<"making tree3 which is the intersection of tree1 and tree2"<<std::endl;
    BinSearchTree *tree3 = tree1->intersectWith(tree2);

    std::cout<<"printing the tree3."<<std::endl;
    tree3->levelOrderDump();

    std::cout<<"making tree4 which is the union of tree1 and tree2"<<std::endl;
    BinSearchTree *tree4 = tree1->unionWith(tree2);

    std::cout<<"printing the tree4."<<std::endl;
    tree4->levelOrderDump();

    std::cout<<"making tree5 which is the difference of tree2 - tree1"<<std::endl;
    BinSearchTree *tree5 = tree2->differenceOf(tree1);

    std::cout<<"printing the tree5."<<std::endl;
    tree5->levelOrderDump();

    std::cout<<"making tree which is the difference of tree1 - emptyTree"<<std::endl;
    BinSearchTree *tree6 = tree1->differenceOf(emptyTree);

    std::cout<<"printing the tree6."<<std::endl;
    tree6->levelOrderDump();

    std::cout<<"making tree which is the difference of emptyTree - tree1"<<std::endl;
    BinSearchTree *tree7 = emptyTree->differenceOf(tree1);

    std::cout<<"printing the tree7."<<std::endl;
    tree7->levelOrderDump();




    /*std::cout<<"testing if tree1 is equal to tree2: "<< tree1->areIdentical(tree2);
    std::cout<<std::endl;*/



    //std::cout<<"kthSmallest value using whole size of the binary tree which is 28, smallest value is: "<< tree->kthSmallest(28)<<std::endl;

    //delete tree;
    std::cout<<std::endl;
    return 0;
}
