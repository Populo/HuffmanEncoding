/* HeapNode.h
	class definition for heapnode

	by Chris Staudigel
*/
#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <queue>

#include "HuffmanNode.h"

using namespace std;

class HeapNode {
	private:
		// huffman node that each heapnode represents
		HuffmanNode *huffNode;
	public:
		// blank constructor
		HeapNode();
		// returns huffman node
		HuffmanNode* value();
		// overloads operator <
		bool operator<(const HeapNode rhs) const;
		// sets huffman node to a leaf on the tree
		void buildLeaf(int weight, int value);
		// sets huffman node to a branch on the tree
		void buildNode(HuffmanNode *left, HuffmanNode *right);
};


#endif
