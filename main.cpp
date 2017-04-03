/* main.cpp
	contains main method for running the program

	by Chris Staudigel
*/
#include <iostream>
#include <fstream>
#include "Huffman.h"
using namespace std;

int main (int argc, char *argv[]) {
	Huffman *h = new Huffman();
	h->run();
}
