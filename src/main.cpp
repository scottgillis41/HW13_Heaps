/**
 * @file main.cpp
 * @brief This is a test of CMake, doxygen, and GitHub.
 * @details This is the long brief at the top of main.cpp.
 * @author Scott Gillis
 * @date 3/30/2020
 * 
 */

#include <iostream>
#include <queue>
using namespace std;

/**
 * Binary Tree Node
 * 
 * This is from Open Data Structures in C++ by Pat Morin
 */
class BTNode {
public:
  BTNode* left;
  BTNode* right;
  BTNode* parent;

  /**
   * BTNode constructor
   */
  BTNode(int dataVal) {
      cout << "name = " << name << endl;
      left = NULL;
      right = NULL;
      parent = NULL;
      objName = name++;
      data = dataVal;
  }

    /**
     * This reports the node's name
     */
    char nodeName() {
        return(objName);
    }

    /**
     * This reports the node's data
     */
    int nodeData() {
        return(data);
    }

private:
  char objName; // The object number created
  static char name;
  int data; // Data that is stored in the node
};


char BTNode::name = 'A'; // initialize static variable

/**
 * This function adds a node to a binary search tree.
 * 
 * @param rootNode is the pointer to the tree's root node
 * @param n is the node to add
 * @returns pointer to rootNode if successful, NULL otherwise
 */
BTNode* addNode(BTNode* rootNode, BTNode* n) {
    BTNode* prev = NULL;
    BTNode* w = rootNode;
    if(rootNode == NULL) { // starting an empty tree
        rootNode = n;
    } else {
        // Find the node n belongs under, prev, n's new parent
        while(w != NULL) {
            prev = w;
            if(n->nodeData() < w->nodeData()){
                w = w->left;
            } else if(n->nodeData() > w->nodeData()) {
                w = w->right;
            } else { // data already in the tree
                return(NULL);
            }
        }
        // now prev should contain the node that should be n's parent
        // Add n to prev
        if(n->nodeData() < prev->nodeData()) {
            prev->left = n;
        } else {
            prev->right = n;
        }
    }
    return(rootNode);
}


/**
 * Adds a new node with the passed data value
 * 
 * @param rootNode pointer to root node
 * @param dataval an integer for the new node's data
 * @returns pointer to root node or NULL if not successful
 */
BTNode* addNode(BTNode* rootNode, int dataval) {
    BTNode* newNode = new BTNode(dataval);
    if(addNode(rootNode, newNode) == NULL) {
        cout << dataval << " already in tree" << endl;
    } else {
        cout << dataval << " succesfully added" << endl;
    }
    return(rootNode);
}

BTNode* merge(BTNode *h1, BTNode *h2) {
if (h1 == NULL) 
    return h2;
if (h2 == NULL) 
    return h1;
if (h1->nodeData() > h2->nodeData()) //if h1 data is greater than h2 data
    return merge(h2, h1);

// now we know h1->x <= h2->x
if(rand() % 2) {
    h1->left = merge(h1->left, h2);
    if (h1->left != NULL) 
        h1->left->parent = h1;
} else {
    h1->right = merge(h1->right, h2);
    if (h1->right != NULL) 
    h1->right->parent = h1;
}
return h1;
}

bool add(int x, BTNode*& rootNode) {
    BTNode *u = new BTNode(x);
    u->left = u->right = u->parent = NULL;
    rootNode = merge(u, rootNode);
    rootNode->parent = NULL;
    //n++;
    return true;
}

int remove(BTNode*& rootNode) {
    int x = rootNode->nodeData();
    BTNode *tmp = rootNode;
    rootNode = merge(rootNode->left, rootNode->right);
    delete tmp;
    if (rootNode != NULL) 
        rootNode->parent = NULL;
    //n--;
    return x;
}

/**
 * Print a binary tree
 * 
 * This example is modified from:
 * https://stackoverflow.com/a/51730733
 * 
 * @param prefix is a string of characters to start the line with
 * @param node is the current node being printed
 * @param isLeft bool true if the node is a left node
 */
void printBT(const string& prefix, BTNode* node, bool isLeft)
{
    if( node != NULL )
    {
        cout << prefix;

        cout << (isLeft ? "L--" : "R--" );

        // print the value of the node
        //cout << node->nodeName() << ':' << node->nodeData() << std::endl;
        cout << node->nodeData() << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

/**
 * An overload to simplify calling printBT
 * 
 * @param node is the root node of the tree to be printed
 */
void printBT(BTNode* node)
{
    printBT("", node, false);
}

int main(int, char**) {
BTNode* rootNode = new BTNode(5); // pointer to the root node  ;
add(3, rootNode);
printBT(rootNode);
add(10, rootNode);
printBT(rootNode);
add(15, rootNode);
printBT(rootNode);
add(32, rootNode);
printBT(rootNode);
add(8, rootNode);
printBT(rootNode);
remove(rootNode);
cout << "value removed: " << remove(rootNode) << endl;
printBT(rootNode);
remove(rootNode);
cout << "value removed: " << remove(rootNode) << endl;
printBT(rootNode);
add(38,rootNode);
add(198, rootNode);
add(65,rootNode);
remove(rootNode);
printBT(rootNode);

}