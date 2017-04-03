/* HuffmanNode.cpp
	Huffman node, holds character and value used for the building of the tree

	by Chris Staudigel
*/

#include <string>
#include "HuffmanNode.h"

using namespace std;

/* Constructor 1
	builds huffman node representing the leaf of tree with a weight and value
*/
HuffmanNode::HuffmanNode(int weight, int value) {
	this->weight = weight;
	this->value = value;
	rc = lc = NULL;
}

/* Constructor 2
	builds huffman node representing a branch of the tree with two leaves of huffman nodes
*/
HuffmanNode::HuffmanNode(HuffmanNode *left, HuffmanNode *right) {
	lc = left;
	rc = right;

	// omitting this caused problems when building tree.
	// no way to set weight and value without this
	this->value = -1;
	this->weight = left->Weight()+right->Weight();
}

/*
 returns value of node
*/
int HuffmanNode::Value() {
	return value;
}

/*
 returns weight of node
*/
int HuffmanNode::Weight() {
	return weight;
}

/*
 returns left child of node
*/
HuffmanNode* HuffmanNode::Left() {
	return lc;
}

/*
	returns right child of node
*/
HuffmanNode* HuffmanNode::Right() {
	return rc;
}
