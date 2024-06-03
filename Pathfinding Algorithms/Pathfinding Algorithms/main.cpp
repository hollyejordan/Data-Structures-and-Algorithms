#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class Node {

public:

	Node(char name) {

		this->name = name; // Sets the node's name to a letter
	}

	// Adds a connection to a neighborbouring node, and the weight of the path
	void addPath(char nodeToAdd, int weight) {

		neighbours.push_back(pair <char, int> (nodeToAdd, weight));
	}
	vector<pair<char, int>> neighbours;
	char name;
	int distance = 1000;
};

void addPaths(vector<Node> &nodes) {

	nodes[0].addPath('B', 10);
	nodes[0].addPath('D', 12);
	nodes[0].addPath('G', 11);
	nodes[0].addPath('H', 4);
	nodes[1].addPath('A', 10);
	nodes[1].addPath('D', 8);
	nodes[1].addPath('H', 20);
	nodes[2].addPath('D', 17);
	nodes[2].addPath('E', 8);
	nodes[2].addPath('G', 13);
	nodes[2].addPath('H', 10);
	nodes[3].addPath('A', 12);
	nodes[3].addPath('B', 8);
	nodes[3].addPath('C', 17);
	nodes[3].addPath('F', 16);
	nodes[3].addPath('G', 24);
	nodes[3].addPath('H', 14);
	nodes[4].addPath('C', 8);
	nodes[4].addPath('F', 8);
	nodes[4].addPath('G', 11);
	nodes[4].addPath('H', 5);
	nodes[5].addPath('D', 16);
	nodes[5].addPath('E', 8);
	nodes[5].addPath('G', 18);
	nodes[5].addPath('H', 21);
	nodes[6].addPath('A', 11);
	nodes[6].addPath('C', 13);
	nodes[6].addPath('D', 24);
	nodes[6].addPath('E', 11);
	nodes[6].addPath('F', 18);
	nodes[6].addPath('H', 30);
	nodes[7].addPath('A', 4);
	nodes[7].addPath('B', 20);
	nodes[7].addPath('C', 10);
	nodes[7].addPath('D', 14);
	nodes[7].addPath('E', 5);
	nodes[7].addPath('F', 21);
	nodes[7].addPath('G', 30);
}


int main() {

	vector<Node> nodes = { {'A'}, {'B'}, {'C'}, {'D'}, {'E'}, {'F'}, {'G'}, {'H'}};
	
	addPaths(nodes);

	nodes[0].distance = 0;

	return 0;
}