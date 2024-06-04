#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

class Node {

public:

	Node(char name) {

		this->name = name; // Sets the node's name to a letter
	}
	
	// Adds a connection to a neighborbouring node, and the weight of the path
	void addPath(Node* nodeToAdd, int weight) {

		neighbours.push_back(pair <Node*, int>(nodeToAdd, weight));
	}
	vector<pair<Node*, int>> neighbours;
	char name;
	int distance = 1000;
	bool discovered = false;
};

// Creates the graph of nodes and connections
void addPaths(vector<Node>& nodes) {

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

// Prints the path that Dijkstra took
void printDijkstraPath(vector<Node>& nodes, int startNode, int targetNode) {

	string pathTaken = "";
	Node* currentNode = &nodes[targetNode];
	pair<Node*, int> closestNode;

	auto findClosestNeighbour = [](pair<Node*, int> a, pair<Node*, int> b) { return a.first->distance < b.first->distance; }; // Lambda function for sorting neighbours by closeness to start node

	while (currentNode != &nodes[startNode]) { // While the starting node has not been reached

		pathTaken = currentNode->name + pathTaken; // Adds node to the front of the path taken (because it's working backwards)
		closestNode = *min_element(currentNode->neighbours.begin(), currentNode->neighbours.end(), findClosestNeighbour); // Finds the current node's neighbour that is closest to the start node
		currentNode = closestNode.first; // Moves to the neighbour closest to the start node
	}
	pathTaken = nodes[startNode].name + pathTaken; // Adds the start node to the path
	cout << "path: " << pathTaken << endl;
}

// Path finds using Dijkstra
void dijkstra(vector<Node>& nodes, int startNode, int targetNode) {

	auto cmpDistance = [](Node* a, Node* b) { return a->distance > b->distance; }; // Lambda function for sorting priority queue by distance, smallest to largest
	priority_queue<Node*, vector<Node*>, decltype(cmpDistance)> unvisitedQueue(cmpDistance); // Creates priority queue with min heap

	nodes[startNode].distance = 0; // Set the starting node's distance to zero
	nodes[startNode].discovered = true; // Set the starting node to visited
	unvisitedQueue.push(&nodes[startNode]);

	Node* currentNode;

	while (!unvisitedQueue.empty()) {

		currentNode = unvisitedQueue.top(); // Gets the next closest node
		unvisitedQueue.pop(); // Removes new node from the queue

		cout << currentNode->name << " " << currentNode->distance << endl;

		if (currentNode == &nodes[targetNode]) { // If node is the target node

			break; // Stop searching
		}

		// Selects the node from top of queue and iterates through its neighbours
		for (auto &neighbour : currentNode->neighbours) {

			// If the node's current distance from the start plus the neighbour's weight is shorter than the neighbour's currently found distance
			if (currentNode->distance + neighbour.second < neighbour.first->distance) {

				neighbour.first->distance = currentNode->distance + neighbour.second; // Update the neighbour's distance to the shorter path

				if (!neighbour.first->discovered) { // If neightbour has not been visited yet

					unvisitedQueue.push(neighbour.first); // Get ready to add it to the queue
					neighbour.first->discovered = true; // Mark neighbour as discovered
				}
			}
		}
	}
	printDijkstraPath(nodes, startNode, targetNode);
}

int main() {

	vector<Node> nodes = { {'A'}, {'B'}, {'C'}, {'D'}, {'E'}, {'F'}, {'G'}, {'H'} };
	addPaths(nodes);

	dijkstra(nodes, 0, 2); // (nodes, starting node, target node)

	return 0;
}