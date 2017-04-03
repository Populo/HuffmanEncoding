/* HuffmanNode.h
	class definition for huffman node

	by Chris Staudigel
*/
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>

using namespace std;

class HuffmanNode {
	private:
		// integer weight and integer char value for the node
		int weight;
		int value;
		// left and right children for the node
		HuffmanNode *lc;
		HuffmanNode *rc;
	public:
		// constructor to build leaf
		HuffmanNode(int weight, int value);
		// constructor to build branch
		HuffmanNode(HuffmanNode *left, HuffmanNode *right);
		// returns char value of node
		int Value();
		// returns frequency of value present
		int Weight();
		// returns left child node
		HuffmanNode* Left();
		// returns right child node
		HuffmanNode* Right();
};


#endif
