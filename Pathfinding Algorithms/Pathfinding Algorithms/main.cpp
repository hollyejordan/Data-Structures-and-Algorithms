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
	void addPath(Node* nodeToAdd, int weight) {

		neighbours.push_back(pair <Node*, int> (nodeToAdd, weight));
	}

	void findShortestPaths() {

		for (auto neighbour : neighbours) { // For each of the current node's neighbours

			cout << "first neighbour: " << neighbour.first->name << endl;
			cout << "it's weight is " << neighbour.second << endl;
			cout << "it's current distance away is " << neighbour.first->distance << endl;

			// If the node's current distance from the start plus the neighbour's weight is shorter than the neighbour's currently found distance
			if (distance + neighbour.second < neighbour.first->distance) {

				neighbour.first->distance = distance + neighbour.second; // Update the neighbour's distance to the shorter path
			}
			cout << "it's new distance is " << neighbour.first->distance << endl;
			cout << endl;
		}
	}

	vector<pair<Node*, int>> neighbours;
	char name;
	int distance = 1000;
}; 

void addPaths(vector<Node> &nodes) {

	nodes[0].addPath(&nodes[1], 10);
	nodes[0].addPath(&nodes[3], 12);
	nodes[0].addPath(&nodes[6], 11);
	nodes[0].addPath(&nodes[7], 4);
	nodes[1].addPath(&nodes[0], 10);
	nodes[1].addPath(&nodes[3], 8);
	nodes[1].addPath(&nodes[7], 20);
	nodes[2].addPath(&nodes[3], 17);
	nodes[2].addPath(&nodes[4], 8);
	nodes[2].addPath(&nodes[6], 13);
	nodes[2].addPath(&nodes[7], 10);
	nodes[3].addPath(&nodes[0], 12);
	nodes[3].addPath(&nodes[1], 8);
	nodes[3].addPath(&nodes[2], 17);
	nodes[3].addPath(&nodes[5], 16);
	nodes[3].addPath(&nodes[6], 24);
	nodes[3].addPath(&nodes[7], 14);
	nodes[4].addPath(&nodes[2], 8);
	nodes[4].addPath(&nodes[5], 8);
	nodes[4].addPath(&nodes[6], 11);
	nodes[4].addPath(&nodes[7], 5);
	nodes[5].addPath(&nodes[3], 16);
	nodes[5].addPath(&nodes[4], 8);
	nodes[5].addPath(&nodes[6], 18);
	nodes[5].addPath(&nodes[7], 21);
	nodes[6].addPath(&nodes[0], 11);
	nodes[6].addPath(&nodes[2], 13);
	nodes[6].addPath(&nodes[3], 24);
	nodes[6].addPath(&nodes[4], 11);
	nodes[6].addPath(&nodes[5], 18);
	nodes[6].addPath(&nodes[7], 30);
	nodes[7].addPath(&nodes[0], 4);
	nodes[7].addPath(&nodes[1], 20);
	nodes[7].addPath(&nodes[2], 10);
	nodes[7].addPath(&nodes[3], 14);
	nodes[7].addPath(&nodes[4], 5);
	nodes[7].addPath(&nodes[5], 21);
	nodes[7].addPath(&nodes[6], 30);
}


int main() {

	vector<Node> nodes = { {'A'}, {'B'}, {'C'}, {'D'}, {'E'}, {'F'}, {'G'}, {'H'}};
	
	addPaths(nodes);

	nodes[0].distance = 0;

	nodes[0].findShortestPaths();

	return 0;
}