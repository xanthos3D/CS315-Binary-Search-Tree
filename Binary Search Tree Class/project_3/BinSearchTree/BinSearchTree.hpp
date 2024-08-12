//
// Created by Ali Kooshesh on 3/1/23.
//

#ifndef BINSEARCHTREE_BINSEARCHTREE_HPP
#define BINSEARCHTREE_BINSEARCHTREE_HPP


#include "TreeNode.hpp"

class BinSearchTree {
public:
    BinSearchTree();
    void insert( int v );
    bool find( int v );
    bool iterFind( int v );
    int size();
    void inorderDump();
    int maxDepth();
    void iterInsert( int v );
    void levelOrderDump();
    bool remove( int v );
    int kthSmallest( int k );
    void valuesAtLevel( int k );
    void iterValuesAtLevel( int k );
    int iterMaxDepth();
    bool hasRootToLeafSum( int sum );
    bool areIdentical( BinSearchTree *bst );
    BinSearchTree *intersectWith( BinSearchTree *bst );
    BinSearchTree *unionWith( BinSearchTree *bst );
    BinSearchTree *differenceOf( BinSearchTree *bst );

    //temporary:


    ~BinSearchTree();

private:
    TreeNode *insert( TreeNode *, int );
    int sizeHelper(TreeNode *);
    bool findHelper(TreeNode *, int v);
    bool iterFindHelper(TreeNode *, int v);
    void inorderDumpHelper(TreeNode *);
    int maxDepthHelper(TreeNode *);
    void deconstructor(TreeNode *);
    bool remove(TreeNode *, int v );
    void valuesAtLevel(TreeNode *, int k );
    int kthSmallest(TreeNode *, int* k );
    void kthSmallest(TreeNode * curRoot,int k,int* counter,int* smallestK);
    bool areIdentical( TreeNode *,TreeNode * );
    bool hasRootToLeafSum(TreeNode *curNode, int sum);
    BinSearchTree *intersectWith(TreeNode* curNode1,BinSearchTree *tree2, BinSearchTree *returnTree);
     void AddNodesToTreeForIntersection( TreeNode* curNode1,BinSearchTree *tree2, BinSearchTree *returnTree);
    BinSearchTree *unionWith(TreeNode* curNode1,TreeNode* curNode2,BinSearchTree *tree2, BinSearchTree *returnTree);
    void AddNodesFromTree1IntoReturnTreeForUnion(TreeNode* curNode1,BinSearchTree *tree2, BinSearchTree *returnTree);
    void AddNodesFromTree2IntoReturnTreeForUnion(TreeNode* curNode2, BinSearchTree *returnTree);
    BinSearchTree *differenceOf(TreeNode* curNode1,BinSearchTree *tree2, BinSearchTree *returnTree);
    void AddNodesFromTree1IntoReturnTreeForDiff(TreeNode* curNode1, BinSearchTree *returnTree);

    TreeNode *findPredecessorParent(TreeNode *);

    TreeNode *root;
};


#endif //BINSEARCHTREE_BINSEARCHTREE_HPP
