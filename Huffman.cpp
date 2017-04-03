/* Huffman.cpp
	main class of program, contains the run method that does all of the work

	by Chris Staudigel
*/
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>

#include "HeapNode.h"
#include "HuffmanNode.h"
#include "Huffman.h"


using namespace std;

/* Constructor
	sets file name to file.txt and includes the end of file character
*/
Huffman::Huffman() {
	filename = "file.txt";
	counts[PSEUDOEOF] = 1;
}

/* run
	main method of program, does all of the work.
	steps:
		creates heap
		loads file
		creates output file
		reads file characters and increments the amount of times they show up
		build tree
		traverse tree
		records output to output file
*/
void Huffman::run() {
	// the heap
	priority_queue<HeapNode> theHeap;

	// the file to be read in
	ifstream infile;
	infile.open(filename.c_str());

	// create output file
	// same as filename with ".output" appended to the end
	ofstream outfile;
	string outfileName = filename + ".output";
	outfile.open(outfileName.c_str());

	// used to build first half of output string
	// using this method to parse integers easily
	ostringstream sstream;

	// reads each character in file and records to array
	while(infile.peek() && !infile.eof()) {
		// does not work when compiled with -std=c++11 flag
		// no idea why
		char ch = infile.get();
		counts[ch]++;
	}

	// creates nodes for each character in the file that was read in
	for (int i = 0; i < counts.size(); i++) {
		if (counts[i] > 0) 	{
			HeapNode *node = new HeapNode();
			node->buildLeaf(counts[i], (char) i);
			theHeap.push(*node);
			// builds first half of string, cout style
			sstream << char(i) << counts[i] << " ";
		}
	}
	// records first half of string to be printed to output file
	outputChars = sstream.str();

	// begin loop that builds tree
	bool done = false;

	while(!theHeap.empty() && !done) {
		HeapNode r = theHeap.top();
		theHeap.pop();
		// if there is at least two nodes in the heap
		if (!theHeap.empty()) {
			HeapNode l = theHeap.top();
			theHeap.pop();
			// debug prints
			//cout << "Left: " << l.value()->Value() << "(" << char(l.value()->Value()) << "): " << l.value()->Weight() << endl;
			//cout << "Right: " << r.value()->Value() << "(" << char(r.value()->Value()) << "): " << r.value()->Weight() << endl;
			HeapNode *h = new HeapNode();
			// builds huffman node with two children nodes
			h->buildNode(l.value(), r.value());
			theHeap.push(*h);
		} else {
			// if there was only one node left in the heap
			done = true;
			theHeap.push(r);
		}
	}

	// traverse the heap starting with first (and hopefully only) node
	HeapNode h = theHeap.top();
	traverse(h.value());

	// reload file
	infile.close();
	infile.clear();
	infile.open(filename.c_str());

	// reads file in while recording string as bits that were determined while traversing
	while(infile.peek() && !infile.eof()) {
		char ch = infile.get();
		outputBits += locations[ch];
	}

	// prints full string to output file
	outfile << outputChars << " " << outputBits;
	// notifies the user of their output file name
	cout << "Your output has been saved in a file called " << outfileName << endl;

	// close files
	infile.close();
	outfile.close();
}

/* traverse
	in-order traversal of the huffman tree to determine paths for each character
*/
void Huffman::traverse(HuffmanNode *node, string path) {
	// if node doesn't exist, return
	if (node == NULL) return;
	// if there is a left node, traverse that node
	if (node->Left() != NULL) traverse(node->Left(), path+"0");
	// if the current node has a value, record path for character to location vector
	if (node->Value() != -1) locations[node->Value()] = path;
	// if right node exists, traverse that node
	if (node->Right() != NULL) traverse(node->Right(), path+"1");
}
