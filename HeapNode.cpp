/* HeapNode.cpp
	heap nodes are used to build huffman nodes for the tree. Each contains a
	char value and the frequency of that char appearing

	by Chris Staudigel
*/

#include <queue>
#include <string>
#include "HeapNode.h"

using namespace std;

// blank constructor
HeapNode::HeapNode() {}

// returns the huffman node that the node is representing
HuffmanNode* HeapNode::value() {
	return huffNode;
}

// overloads operator < used when nodes are inserted into the priority queue
bool HeapNode::operator<(const HeapNode rhs) const {
	return (rhs.huffNode->Weight() < (*this).huffNode->Weight());
}

// assigns represented huffman node as a leaf on the tree with a specified
// value and weight.
void HeapNode::buildLeaf(int weight, int value) {
	huffNode = new HuffmanNode(weight, value);
}

// assigns represented huffman node as a branch on the tree with a value
// of -1 and a weight of the sum of both leaf nodes
//
void HeapNode::buildNode(HuffmanNode *left, HuffmanNode *right) {
	huffNode = new HuffmanNode(left, right);
}
