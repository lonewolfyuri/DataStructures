// George Gabricht
//
// ggabrich - 56735102

#include <queue>
#include "set.hpp"
#include "graph.hpp"

using namespace std;

class Compare {

public:
	// O(1)
	bool operator() (Edge left, Edge right) {
		if (left.getWeight() >= right.getWeight()) { // 1
			return true; // 1
		}
		return false; // 1
	}
};

// O(E) where E is # Edges
void printKruskals(int result, int **tree, int treeSize) {
	cout << "Total Cost: " << result << endl; // 1

	for (int ndx = 0; ndx < treeSize; ndx++) { // E
		cout << "[ " << tree[ndx][0] << "-" << tree[ndx][1] << " ] ( "; // 1
		cout << tree[ndx][2] << " )" << endl; // 1
	}

}

// O(E + V)
void kruskals(Graph & g) {
	int num_vertex = g.numVert(), totalWeight = 0, num_edge = g.numEdge(); // 1
	Set sets(num_vertex); // 1
	Vertex *vertices = g.getVert(); // 1
	int **tree = new int*[num_edge], treeNdx = 0; // 1
	for (int ndx = 0; ndx < num_edge; ndx++) { // E
		tree[ndx] = new int[3]; // 1
	}
	
	for (int ndx = 0; ndx < num_vertex; ndx++) { // V
		if (vertices[ndx].getId() != -1) { // 1
			sets.makeSet(ndx); // 1
		}
	}

	priority_queue<Edge, vector<Edge>, Compare> pq; // 1
	// Total = E
	for (int ndx = 0; ndx < num_vertex; ndx++) { // V
		// Make Priority Queue - Ascending by Weight
		for (Edge eg : vertices[ndx].getEdges()) { // e = # edges in vertex
			pq.push(eg); // 1
		}
	}
	
	// for each edge in Priority Queue:
	// Total = E
	while (!pq.empty()) { // E
		Edge eg = pq.top(); // 1
		int u = eg.getSrc(), v = eg.getDst(); // 1
		if (sets.find(u) != sets.find(v)) { // 1 -> H = height of set
			totalWeight += eg.getWeight(); // 1
			tree[treeNdx][0] = u; // 1
			tree[treeNdx][1] = v; // 1
			tree[treeNdx++][2] = eg.getWeight(); // 1
			sets.unionSet(u, v); // 1
		}	
		pq.pop(); // 1
	}

	printKruskals(totalWeight, tree, treeNdx); // E
	
	for (int ndx = 0; ndx < num_edge; ndx++) { // E
		delete[] tree[ndx]; // 1
	}
	delete[] tree; // 1
}

int main( int argc, char *argv[]) {
	
	const char* fileName = argc == 2 ? argv[1] : "large.graph.txt";

	Graph grph(fileName);
	//grph.print(cout);
	
	kruskals(grph);

	return 0;
}

