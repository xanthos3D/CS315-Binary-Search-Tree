//
// Created by Ali Kooshesh on 3/1/23.
//
//xander maniaci


#include "BinSearchTree.hpp"
#include<iostream>
#include<string>
#include<algorithm>
#include <queue>
#include <utility>


BinSearchTree::BinSearchTree(): root{nullptr} {}

TreeNode *BinSearchTree::insert( TreeNode *root, int v ) {
    if( root == nullptr )
        return new TreeNode( v );
    if( root->value() < v )
        root->rightSubtree( insert( root->rightSubtree(), v ) );
    else
        root->leftSubtree( insert( root->leftSubtree(), v ) );
    return root;
}

void BinSearchTree::insert(int v) {
    // Insert v in the tree if it is not already a member.
    if( ! find(v) ) {
        root = insert(root, v);
    }
}

int BinSearchTree::size() {
    // Write this function first!
    return sizeHelper(root);
}
int BinSearchTree::sizeHelper(TreeNode * curRoot){
    if(nullptr == curRoot){
        return 0;
    }
    return 1 + sizeHelper(curRoot->leftSubtree()) + sizeHelper(curRoot->rightSubtree());

}


bool BinSearchTree::find(int v) {
    // You need to write a recursive implementation for this function.
    // Right now, it returns false so that insert can do its job.
    // That means, it will add duplicates to the tree, which is not desirable.


    return findHelper(root,v);
}
bool BinSearchTree::findHelper(TreeNode * curRoot, int v){
    if(nullptr == curRoot) {
        return false;
    }
    if(curRoot->value() == v){
        return true;
    }
    if(curRoot->value() > v){
        return findHelper(curRoot->leftSubtree(),v);
    }
    return findHelper(curRoot->rightSubtree(),v);

}
bool BinSearchTree::iterFind( int v ){
    return iterFindHelper(root,v);
}
bool BinSearchTree::iterFindHelper(TreeNode * curRoot, int v){
     if(nullptr == curRoot){
      return false;
     }

     while(nullptr != curRoot){
         //std::cout<<"curRoot value: "<< curRoot->value()<<std::endl;
         if(curRoot->value() == v){
             return true;
         }

         if(curRoot->value() < v) {
             curRoot = curRoot->rightSubtree();

         }else{
             curRoot = curRoot->leftSubtree();
         }


     }

     return false;
}
void BinSearchTree::inorderDump(){

    inorderDumpHelper(root);

}
void BinSearchTree::inorderDumpHelper(TreeNode * curRoot){
    //std::cout<<" "<<curRoot->value();
    if(nullptr == curRoot){
       return;
    }

    inorderDumpHelper(curRoot->leftSubtree());
    std::cout<<curRoot->value()<<std::endl;
    inorderDumpHelper(curRoot->rightSubtree());
}
int BinSearchTree::maxDepth(){
    return maxDepthHelper(root);
}
int BinSearchTree::maxDepthHelper(TreeNode * curRoot){

    if(nullptr == curRoot){
        return 0;
    }
    return 1 + std::max(maxDepthHelper(curRoot->leftSubtree()) , maxDepthHelper(curRoot->rightSubtree()));

}



BinSearchTree::~BinSearchTree() {
    // This function should delete every node in the tree.
    // To do that, you will have to recursively traverse the tree, using
    // a post-order traversal.
    //std::cout<<" "<<curRoot->value();
    //std::cout<<" calling deconstructor";
    deconstructor(root);


}
void BinSearchTree::deconstructor(TreeNode * curRoot){
    //std::cout<<" calling deconstructor";
    if(nullptr == curRoot){
        return;
    }

    deconstructor(curRoot->leftSubtree());
    deconstructor(curRoot->rightSubtree());
    std::cout<<" calling deconstructor, deleting: "<<curRoot->value()<<std::endl;
    delete curRoot;
    //curRoot = nullptr;

}
/*prints the values in the tree, one per line, using a level-order traversal. You must write an iterative solution using a FCFS queue, first in first out queue.*/
void BinSearchTree::levelOrderDump(){

    // if the root points to nullptr then we have a empty binary tree and thus have nothing to print.
    if(root == nullptr){
        //std::cout<<" binary tree is empty."<<std::endl;
        return;
    }
    //used to store tree nodes for printing
    std::queue<TreeNode*> printQueue;
    
    //if the root is not a nullptr then we want to push it on the queue
    printQueue.push(root);
    // makes a temp tree node that we can use to print and traverse the queue.
    TreeNode *temp = printQueue.front();
    // now we need to run through the binary tree. loops while the queue is not empty.
    while(!printQueue.empty()){
        //first we need to print the value in the node. if this is the root we also want to print it before doing any other operations
        std::cout<<printQueue.front()->value()<< std::endl;
        //we then want to set our temp node to the value we just printed
        //so that after we pop it we can check if it has a left or right node, then add both to the queue
        temp = printQueue.front();
        //then we want to remove the current node
        printQueue.pop();
        // then we test if the left and right nodes on our current node are nullptr.
        // if not add them to the queue. the next while loop with then add the left and right nodes of the next pointer
        // them move on to its sibling and do the same. that way we can preserver the level order in a itterative way by
        // taking advantage of a first in first out queue.
        if(temp->leftSubtree() != nullptr){
            printQueue.push(temp->leftSubtree());
        }

        if(temp->rightSubtree() != nullptr){
            printQueue.push(temp->rightSubtree());
        }

    }
}


/*removes the node containing the value v from the tree, if it exists. It returns true if the value was in the tree and false otherwise.
You can choose to write an iterative solution or a recursive solution for this function.*/
// note a good way to remove node is to check leftsub tree for predecessor and have that predecessor replace that nodes data. then find and delete the predecessor
bool BinSearchTree::remove( int v ){
    // making a temperary node that will be deleted after use to prevent memory leaks in some scenarios
    TreeNode* delNode = root;
    // base case, if root is nullptr
    if(delNode == nullptr){
        return false;
    }
    // if the root is the value we want to remove it has special casses.
    if(delNode->value() == v){
        //first we create a temp variable to hold stuff. its currently set to delNode which is pointing to the root.
        TreeNode *temp = delNode;
        // if both branches of the root are nullptr then we set the root to nullptr then return.
        if(delNode->leftSubtree() == nullptr && delNode->rightSubtree() == nullptr) {
            root = nullptr;
            return true;
            //if the root has a node to the right only then we
        }else if(delNode->leftSubtree() == nullptr){
            //set temp to that right node
            temp = delNode->rightSubtree();
            // set the root value to the right node
            root->value() = temp->value();
            // then set the left and right subtree of the root to the right subtree node.
            root->rightSubtree(temp->rightSubtree());
            root->leftSubtree(temp->leftSubtree());
            return true;
            // same as case above but if the only branch is in the right subtree of the root
        }else if(delNode->rightSubtree() == nullptr){
            //set temp to that left node
            temp = delNode->leftSubtree();
            // set the root value to the left node
            root->value() = temp->value();
            // then set the left and right subtree of the root to the left subtree node.
            root->leftSubtree(temp->leftSubtree());
            root->rightSubtree(temp->rightSubtree());
            return true;
        }
        //falls through
    }

    // since we need to delete nodes deeper in the tree we create a temp treenode called parent to tail behind our search for the node to be deleted.
    TreeNode *parent = delNode;
    // loop until we hit our desired value or we drop out if we hit nullptr.
    while(nullptr != delNode){
        //std::cout<<"value of current delnode at the top of the while loop: "<<delNode->value()<<std::endl;
        // if we find the value we are looking for then we remove it then return true.
        if(delNode->value() == v){
            // first we need to know the structure of the tree. if tree has a left subtree then we need to find the precessor in that tree
            //we then replace the current node value with the predecessor and delete the predecessor from the subtree. if there is no left subtree
            // then we replace current node with its right sub tree if there is one.
            //if there is no left or right subtree we remove delNode
            if(delNode->leftSubtree() == nullptr && delNode->rightSubtree() == nullptr) {
                //case checks to see which branch the node to be dleted is on
                if(parent->leftSubtree() == delNode){
                    parent->leftSubtree(nullptr);
                }else if(parent->rightSubtree() == delNode){
                    parent->rightSubtree(nullptr);
                }
            // this case tests to see if the node to be deleted has a left branch
            }else if(delNode->leftSubtree() == nullptr){
                // if so then we set the left subtree of the parent node to the deleted nodes right subtree
                if(parent->leftSubtree() == delNode){
                    parent->leftSubtree(delNode->rightSubtree());
                    //otherwise we set the right parent subtree to the deleted nodes left subtree
                }else if(parent->rightSubtree() == delNode){

                       parent->rightSubtree(delNode->rightSubtree());
                    //parent->rightSubtree(delNode->leftSubtree());

                }
            // same as above case but inverse if the node to be deleted has a right subtree
            }else if(delNode->rightSubtree() == nullptr){
                if(parent->leftSubtree() == delNode){
                    parent->leftSubtree(delNode->leftSubtree());
                }else if(parent->rightSubtree() == delNode){
                    parent->rightSubtree(delNode->leftSubtree());
                }
            }else{// if both are not null ptr then we need to find precessor and replace current node with it
                // we can find the predecessor by going to the left child of curnode
                //then from that left child we keep going through the right children until we hit nullptr
                // once we hit nullptr that is when we know that we have reached the predecessor.
                // there will be two cases. one to check of the predecessor is a leaf and one to test if
                // the predecessor has a left branch. in both we can repeat above cases to delete predecessor
                // after it replaces the node we want to delete/replace
                TreeNode *predecessorParent = findPredecessorParent(delNode);
                TreeNode *predecessor = delNode;
                if(predecessorParent != delNode){
                    predecessor = predecessorParent->rightSubtree();
                    delNode->value() = predecessor->value();
                    predecessorParent->rightSubtree(predecessor->leftSubtree());
                }else{
                    predecessor = predecessorParent->leftSubtree();
                    delNode->value() = predecessor->value();
                    predecessorParent->leftSubtree(predecessor->leftSubtree());
                }

                delNode = predecessor;
            }

            // deletes delNode to prevent memory leaks
            delete delNode;
            return true;
        }
        // if the value is larger than current node value it must be in the right tree
        if(delNode->value() < v) {
            parent = delNode;
            delNode = delNode->rightSubtree();

        }else{// if the value is less than current node vale it must be in the left tree
            parent = delNode;
            delNode = delNode->leftSubtree();
        }
    }
    return false;
}

TreeNode *BinSearchTree::findPredecessorParent(TreeNode * curNode) {
    TreeNode *predecessor = curNode->leftSubtree();
    while(predecessor->rightSubtree() != nullptr){
        //std::cout<<"in find predecessor parent while loop, Current Value: "<<curNode->value()<<std::endl;
        curNode = predecessor;
        predecessor = predecessor->rightSubtree();
    }
    return curNode;

}

/*returns the k-th smallest value in the tree.The pre-condition for this function is: size() >= k.
 * Returns zero if the pre-condition is not met. Write a recursive solution for this function.*/
int BinSearchTree::kthSmallest( int k ){
    int temp = k;
    int* counter = &temp;
    int smallestK = 0;
    int *smallestKPtr = &smallestK;
  kthSmallest(root, k,counter,smallestKPtr);
  return smallestK;

}
// the goal of this function is to be able to print the smallest nth element
// first would be 30 then 31 and so on up to the largest number
void BinSearchTree::kthSmallest(TreeNode * curNode,int k,int* counter,int* smallestK){
    // if the binary tree is empty return zero;
    //std::cout<<" "<<curRoot->value();
    if(nullptr == curNode){
        return;
    }

    kthSmallest(curNode->leftSubtree(),k,counter,smallestK);
    // here is where we need to test and increment the pointer to counter
    //when we reach the smallest we need to first deincrement counter by one
    *counter = *counter-1;
    // then we check if the counter is zero which means we have reached our nth smallest value
    if(*counter == 0){

        *smallestK = curNode->value();
        // reduces the counter by one again so that repeat calls do not change the nthsmallest value after we find it.
        *counter = *counter-1;

    }
    //std::cout<<" "<<curRoot->value()<<std::endl;
    kthSmallest(curNode->rightSubtree(),k,counter,smallestK);
    //repeats the if check above if the tree has no left subtree
    if(*counter == 0){

        *smallestK = curNode->value();
        // reduces the counter by one again so that repeat calls do not change the nthsmallest value after we find it.
        *counter = *counter-1;

    }

}
int BinSearchTree::kthSmallest(TreeNode *curNode, int* k ){
    // so traverse through the tree using k as an ancor for when to stop. we are traversing
    // through this tree looking for the smallest value as long as k is not zero an current node not nullptr
    //if k is ever less than 1 or curNode == nullptr then return 0;
    //std::cout<<std::endl;
    //std::cout<<" current K: "<< *k<<std::endl;
    if(root == nullptr) {
        return 0;
    }
    if(size() < *k || *k <= 0){
        return 0;
    }

        if(*k > 1){
            *k = *k-1;
            if(curNode->leftSubtree() != nullptr && curNode->rightSubtree() != nullptr){
                //this in the min of (recursive call leftsubtree, recursive call right subtree)
                return std::min(std::min(curNode->value(),kthSmallest(curNode->rightSubtree(),k)),std::min(curNode->value(),kthSmallest(curNode->leftSubtree(),k)));
            }
            //if curNode only has one branch we want to recursive call down it comparing curNode->value() to the recursive call.
            if(curNode->leftSubtree() != nullptr){

                return std::min(curNode->value(),kthSmallest(curNode->leftSubtree(),k));
            }
            if(curNode->rightSubtree() != nullptr){

                return std::min(curNode->value(),kthSmallest(curNode->rightSubtree(),k));
            }
            //both are null ptr then we are at a leaf and want to return the current value.
        }
    return curNode->value();

}

void BinSearchTree::valuesAtLevel( int k ){
    valuesAtLevel(root,k );

}
/*prints a list of values at level k in the tree, in increasing order of values. The level of the root node is 1. That is,
 * valuesAtLevel( 1 ) should print the value at the root-node of the tree. The children of root, if any, are at level 2, etc.
 * Write a recursive solution for this function.*/
void BinSearchTree::valuesAtLevel(TreeNode *curNode, int k ){
    //std::cout<<" "<<curRoot->value();
    if(nullptr == curNode){
        return;
    }
    if(k < 1){
        //std::cout<<" invalid layer."<<std::endl;
        return;
    }
    if(k < 2) {
        std::cout << curNode->value() <<std::endl;
        return;
    }
    valuesAtLevel(curNode->leftSubtree(),k-1);
    valuesAtLevel(curNode->rightSubtree(),k-1);

}

void BinSearchTree::iterValuesAtLevel( int k ){
    // base case if the tree is empty
    if(root == nullptr){
        //std::cout<<" binary tree is empty."<<std::endl;
        return;
    }
    if(k < 1){
        //std::cout<<" invalid layer."<<std::endl;
        return;
    }
    //used to store tree nodes for printing
    // idea for iterative values at level. if we pair the tree nodes with a int representing depth pushed onto the queue using a pair, at each pass we may be able to keep track of the depth.
    std::pair<TreeNode*,int> temp;
    std::queue<std::pair<TreeNode*,int>> printQueue;

    //if the root is not a nullptr then we want to push it on the queue
    temp = std::make_pair(root,1);
    printQueue.push(temp);
    // makes a temp tree node that we can use to print and traverse the queue.
    //TreeNode *temp = printQueue.front();
    // now we need to run through the binary tree. loops while the queue is not empty.
    while(!printQueue.empty() && temp.second <=k){
        //first we need to print the value in the node. if this is the root we also want to print it before doing any other operations
        if(temp.second == k){
            std::cout<<temp.first->value()<<std::endl;
        }

        //we then want to set our temp node to the value we just printed
        //so that after we pop it we can check if it has a left or right node, then add both to the queue
        //then we want to remove the current node
        printQueue.pop();
        // then we test if the left and right nodes on our current node are nullptr.
        // if not add them to the queue. the next while loop with then add the left and right nodes of the next pointer
        // them move on to its sibling and do the same. that way we can preserver the level order in a itterative way by
        // taking advantage of a first in first out queue.
        if(temp.first->leftSubtree() != nullptr){
            printQueue.push(std::make_pair(temp.first->leftSubtree(),temp.second+1));
        }

        if(temp.first->rightSubtree() != nullptr){
            printQueue.push(std::make_pair(temp.first->rightSubtree(),temp.second+1));
        }
        temp = printQueue.front();
    }
}

int BinSearchTree::iterMaxDepth(){
    // base case if the tree is empty
    if(root == nullptr){
        std::cout<<" binary tree is empty."<<std::endl;
        return 0;
    }

    //used to store tree nodes for printing
    // idea for iterative values at level. if we pair the tree nodes with a int representing depth pushed onto the queue using a pair, at each pass we may be able to keep track of the depth.
    std::pair<TreeNode*,int> temp;
    std::queue<std::pair<TreeNode*,int>> printQueue;

    //if the root is not a nullptr then we want to push it on the queue
    temp = std::make_pair(root,1);
    printQueue.push(temp);
    int maxDepth = 0;
    // makes a temp tree node that we can use to print and traverse the queue.
    //TreeNode *temp = printQueue.front();
    // now we need to run through the binary tree. loops while the queue is not empty.
    while(!printQueue.empty()){
        //first we need to print the value in the node. if this is the root we also want to print it before doing any other operations
        if(temp.second > maxDepth){
            maxDepth = temp.second;
        }

        //we then want to set our temp node to the value we just printed
        //so that after we pop it we can check if it has a left or right node, then add both to the queue
        //then we want to remove the current node
        printQueue.pop();
        // then we test if the left and right nodes on our current node are nullptr.
        // if not add them to the queue. the next while loop with then add the left and right nodes of the next pointer
        // them move on to its sibling and do the same. that way we can preserver the level order in a itterative way by
        // taking advantage of a first in first out queue.
        if(temp.first->leftSubtree() != nullptr){
            printQueue.push(std::make_pair(temp.first->leftSubtree(),temp.second+1));
        }

        if(temp.first->rightSubtree() != nullptr){
            printQueue.push(std::make_pair(temp.first->rightSubtree(),temp.second+1));
        }
        temp = printQueue.front();
    }
    return maxDepth;
}
/*returns true if there is a root-to-leaf path in the tree where the sum of the values on that path is equal to the input argument, sum.
 *Otherwise, it returns false. You should write a recursive solution for this function.*/
bool BinSearchTree::hasRootToLeafSum( int sum ){
    return hasRootToLeafSum(root,sum);
}

bool BinSearchTree::hasRootToLeafSum(TreeNode *curNode, int sum ){
    //plan, subtract the current value and recurse down the tree until the value is zero or we hit nullptr.
    //use or operator so if one valid root to leaf is found then it wil return true.
    // if the root is nullptr return false, empty tree
    if(root == nullptr){
        return false;
    }
    // if sum is zero then we found a valid path from root to a leaf that adds to the sum.
    if(sum == 0){
        return true;
    }
    //if we are not at a nullptr recursive call to function and subtract sum by current value
    if(curNode != nullptr){
        return(hasRootToLeafSum(curNode->leftSubtree(),sum - curNode->value()) || hasRootToLeafSum(curNode->rightSubtree(),sum - curNode->value()));
    }

    return false;
}




bool BinSearchTree::areIdentical( BinSearchTree *bst ){
    return areIdentical(root, bst->root);
}

bool BinSearchTree::areIdentical( TreeNode * curNode1,TreeNode * curNode2 ){
    // first we need to travers through all of one tree comparing it to the other
    //if they are both currently nullptr then return true.
    if(nullptr == curNode1 && nullptr == curNode2) {
        return true;
    }
    // if one is nullptr but the other is not then we return false.
    if((nullptr != curNode1 && nullptr == curNode2) ||(nullptr == curNode1 && nullptr != curNode2)){
        return false;
    }
    // if the values of a given node match then we return true+ recursive call to the left and right branch of binarytrees 1 and 2
    if(curNode1->value() == curNode2->value()){
        return (true && areIdentical( curNode1->leftSubtree(),curNode2->leftSubtree()) && areIdentical( curNode1->rightSubtree(),curNode2->rightSubtree()));
    }
    //otherwise if the both not nullptr but there values do not match then we return false;
        return false;



}

BinSearchTree *BinSearchTree::intersectWith( BinSearchTree *bst ){
    BinSearchTree *tree = new BinSearchTree();
    return intersectWith(root,bst,tree);
}

BinSearchTree *BinSearchTree::intersectWith( TreeNode* curNode1,BinSearchTree *tree2, BinSearchTree *returnTree){

// pass through binary tree 1 checking if value is found in binary tree 2. if so add that value to binary tree 3
// otherwise recurse.

// first base case. if the first tree is empty then we need to return that tree because tree1 and tree2 have nothing that intersect
    if(curNode1 == nullptr){
        return returnTree;
    }
    // call to a recursive helper function that will fill the tree with values of first ree if they can be found in the second tree.
    AddNodesToTreeForIntersection(curNode1,tree2, returnTree);

    return(returnTree);

    //otherwise we ant to recursively go through first tree
}

void BinSearchTree::AddNodesToTreeForIntersection(TreeNode* curNode1,BinSearchTree *tree2, BinSearchTree *returnTree){
    if(curNode1 == nullptr){
        return;
    }

    if(tree2->find(curNode1->value())){
        returnTree->insert(curNode1->value());
    }

    AddNodesToTreeForIntersection(curNode1->leftSubtree(),tree2, returnTree);
    AddNodesToTreeForIntersection(curNode1->rightSubtree(),tree2, returnTree);

}

BinSearchTree *BinSearchTree::unionWith( BinSearchTree *bst ){
    BinSearchTree *tree = new BinSearchTree();
    return unionWith(root,bst->root,bst,tree);
}

BinSearchTree *BinSearchTree::unionWith(TreeNode* curNode1,TreeNode* curNode2,BinSearchTree *tree2, BinSearchTree *returnTree){
    //if the first tree is empty then the union of a empty tree and a tree with members is that second tree with members.
    if(curNode1 == nullptr){
        return tree2;
    }

    AddNodesFromTree1IntoReturnTreeForUnion(curNode1,tree2,returnTree);
    AddNodesFromTree2IntoReturnTreeForUnion(curNode2,returnTree);

    return(returnTree);
}

void BinSearchTree::AddNodesFromTree1IntoReturnTreeForUnion(TreeNode* curNode1,BinSearchTree *tree2, BinSearchTree *returnTree){
    //if nothing is in tree1 or we reach a nullptr just return
    if(curNode1 == nullptr){
        return;
    }
    //if the value in tree1 cannot be found in tree2 then add it here
    //this case may be redundant for union as the data structure already prevents duplicates.
    if(!tree2->find(curNode1->value())){
        returnTree->insert(curNode1->value());
    }

    AddNodesFromTree1IntoReturnTreeForUnion(curNode1->leftSubtree(),tree2, returnTree);
    AddNodesFromTree1IntoReturnTreeForUnion(curNode1->rightSubtree(),tree2, returnTree);
}

void BinSearchTree::AddNodesFromTree2IntoReturnTreeForUnion(TreeNode* curNode2, BinSearchTree *returnTree){
    //if nothing is in tree1 or we reach a nullptr just return
    if(curNode2 == nullptr){
        return;
    }
    //if the value in tree1 cannot be found in tree2 then add it here
    //this case may be redundant for union as the data structure already prevents duplicates.

    returnTree->insert(curNode2->value());


    AddNodesFromTree2IntoReturnTreeForUnion(curNode2->leftSubtree(), returnTree);
    AddNodesFromTree2IntoReturnTreeForUnion(curNode2->rightSubtree(), returnTree);
}

BinSearchTree *BinSearchTree::differenceOf( BinSearchTree *bst ){
    BinSearchTree *tree = new BinSearchTree();
    return differenceOf(root,bst,tree);
}

BinSearchTree *BinSearchTree::differenceOf(TreeNode* curNode1,BinSearchTree *tree2, BinSearchTree *returnTree){

// pass in the node root of the second tree and the return tree
    AddNodesFromTree1IntoReturnTreeForDiff(tree2->root,returnTree);


    return(returnTree);

}
void BinSearchTree::AddNodesFromTree1IntoReturnTreeForDiff(TreeNode* curNode1, BinSearchTree *returnTree){
    //if nothing is in tree1 or we reach a nullptr just return
    if(curNode1 == nullptr){
        return;
    }
    //if the value in tree1 cannot be found in tree2 then add it here
    //this case may be redundant for union as the data structure already prevents duplicates.
    if(!this->find(curNode1->value())){
        returnTree->insert(curNode1->value());
    }

    AddNodesFromTree1IntoReturnTreeForDiff(curNode1->leftSubtree(), returnTree);
    AddNodesFromTree1IntoReturnTreeForDiff(curNode1->rightSubtree(), returnTree);
}



