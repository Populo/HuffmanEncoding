/* Huffman.h
	Header file for main class of program. contains variables used and method declarations

	by Chris Staudigel
*/
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <vector>

#include "HeapNode.h"

using namespace std;

class Huffman {

private:
	// pseudo end of file character
	static const int PSEUDOEOF = 256;
	// vector of frequencies for each character
	vector<int> counts {257, 0};
	// vector of paths for each character
	vector<string> locations {257, ""};
	// input filename
	string filename;
	// first half of output string
	string outputChars = "";
	// second half of output string
	string outputBits = "";
public:
	// constructor
	Huffman();
	// run method
	void run();
	// traverse method
	void traverse(HuffmanNode *node, string path = "");
};

#endif
