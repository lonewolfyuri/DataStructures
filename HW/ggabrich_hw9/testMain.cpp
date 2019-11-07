// George Gabricht
//
// 56735102 - ggabrich

#define UNDF -1

#include <climits>

#include "Graph.hpp"
#include "PriorityQueue.hpp"

// O(|E + V| log V)
void dijkstras(Graph & g, int src, int * dist, int * prv) {
	dist[src] = 0; // 1

	int num_vertex = g.numVert();	 // 1
	
	// cout << "Num Vertex: " << num_vertex << endl;
	
	PriorityQueue<vNode> pq(num_vertex); // 1

	// Total = V log V
	for (int ndx = 0; ndx < num_vertex; ndx++) { // V
		if (ndx != src) { // 1
			dist[ndx] = INT_MAX; // 1
		}

		prv[ndx] = UNDF; // 1

		vNode newNode(ndx, dist[ndx]); // 1

		pq.enqueue(newNode); // log V

		// cout << "New Node - " <<  newNode.getKey() << "\t Wt: " << newNode.getVal() << endl;
	}

	// cout << "PQ length: " << pq.length() << endl;
	// pq.print(cout);
	
	// Total = E log V
	while (!pq.isEmpty()) { // V -> e*V = E since all edges from each vertex = Edges E
		vNode curNode = pq.dequeue(); // log V

		//cout << "Cur Node - " <<  curNode.getKey() << "\t Wt: " << curNode.getVal() << endl;
		//cout << "PQ Length: " << pq.length() << endl;
		Vertex curVert = g.getVert()[curNode.vertex]; // 1

		/*
  		if (pq.length() < 5) {
			pq.print(cout);
		}
		*/

		for (Edge eg : curVert.getEdges()) { // e = # edges in vertex 
			int newWeight; // 1

			//cout << "Edge - " << eg.getSrc() << " - " << eg.getDst();
			//cout << "\t Wt: " << eg.getWeight() << endl;

			if (curNode.weightSum == INT_MAX) { // 1
				newWeight = eg.getWeight(); // 1
			} else {
				newWeight = curNode.weightSum + eg.getWeight(); // 1
			}			

			if (newWeight < dist[eg.getDst()]) { // 1
				dist[eg.getDst()] = newWeight; // 1
				prv[eg.getDst()] = curNode.vertex; // 1
				vNode newNode(eg.getDst(), newWeight); // 1
				// cout << "New Weight - " << eg.getDst() << "\tDist: " << dist[eg.getDst()] << endl;
				pq.enqueue(newNode); // 1
			} 
		}
	}
}

// O(V)
void buildPath(int src, int ndx, int *prv, vector<int> path) {
	for (int cur = ndx; cur != src; cur = prv[cur]) { // V
		path.push_back(cur); // 1
	}
}

// O(V^2)
int main(int argc, char *argv[]) {
	char *file_name =(char *) (argc >= 3 ? argv[2] : "small.graph.txt"); // 1
	int src = 0; // 1
	try { 
		src = argc >= 2 ? stoi(argv[1]) : -1; // 1 
	} catch(...) {
		src = -1; // 1
		file_name = argv[1]; // 1
	}

	Graph g(file_name); // V + E

	if (src < 0) { // 1
		g.print(cout); // VE

		while(true) { // I = # of incorrect inputs
			cout << "Please choose a Vertex Number to begin Dijkstras (0-"; // `
			cout << g.numVert() - 1 << "): "; // `

			cin >> src; // `

			if (src < 0 || src > g.numVert()-1) { // 1
				cout << "Invalid Vertex, Please Try Again!" << endl; // 1
			} else { 
				break; // 1
			}
		}
	}

	int *dist = new int[g.numVert()], *prv = new int[g.numVert()]; // 1
	
	dijkstras(g, src, dist, prv); // |E + V| log V

	/*
	cout << "Result: " << endl;
	for (int ndx = 0; ndx < g.numVert(); ndx++) {
		cout << "\tdist: " << dist[ndx] << "\t\tprv: " << prv[ndx] << endl;
	}
	*/


	cout << "Results for Shortest Path Single Source from Vertex: " << src << endl; // 1

	for (int ndx = 0; ndx < g.numVert(); ndx++) { // V
		if (dist[ndx] == INT_MAX) {
			continue;
		}
	
		vector<int> result; // 1
		for (int cur = ndx; cur != src && cur > -1; cur = prv[cur]) { // V
			result.push_back(cur); // 1	
		}

		result.push_back(src); // 1
	
		cout << ndx << " [ "; // 1

		for (int cur = result.size() - 1; cur > 0; cur--) { // V
			cout << result[cur] << "-"; // 1
		}

		cout << result[0] << " ] ( " << dist[ndx] << " )" << endl; // 1
	}
	

	//g.print(cout); // 1
	// cout << "num vert: " << g.numVert() << endl;

	delete[] dist; // 1
	delete[] prv; // 1
	return 0; // 1
}


