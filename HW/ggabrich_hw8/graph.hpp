// George Gabricht
//
// ggabrich - 56735102


#ifndef GRAPH_HPP

#define GRAPH_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Edge {

private:
	int src, dst, weight;

public:
	Edge(int s, int d, int w)
	: src(s), dst(d), weight(w)
	{}

	// O(1)
	Edge reverse() {
		return Edge(dst, src, weight);
	}

	// O(1)
	int getWeight() {
		return weight;
	}

	// O(1)
	void setWeight(int w) {
		weight = w;
	}

	// O(1)
	int getSrc() {
		return src;
	}

	// O(1)
	int getDst() {
		return dst;
	}
};

class Vertex {

private:
	int id;
	vector<Edge> edges;

public:
	Vertex()
	: id(-1)
	{}

	Vertex(int i)
	: id(i)
	{}

	// O(1)
	void add_edge(const Edge & e) {
		edges.push_back(e); // 1
	}

	// O(e) where e is # edges in vertex
	void print(ostream & out) {
		out << "\tVector - ID: " << id << endl; // 1
		for (Edge eg : edges) { // E
			out << "\t\tEdge - Src: " << eg.getSrc() << " Dst: "; // 1
			out << eg.getDst() << " Weight: " << eg.getWeight() << endl; // 1
		}
	}

	// O(1)
	int getId() {
		return id; // 1
	}

	// O(1)
	vector<Edge> getEdges() {
		return edges; // 1
	}

	// O(e) where e is # edges in vertex
	bool isEdge(Edge e) {
		for (Edge eg : edges) { // E
			if (eg.getDst() == e.getDst()) { // 1
				eg.setWeight(e.getWeight()); // 1
				return true; // 1
			}
		}
		return false; // 1
	}
};


class Graph {

private:

	int num_vertex, num_edge;
	Vertex *vertices;

	/*
	int cap;
	void resizeVert() {
		if (num_vertex >= cap * 0.8) {
			cap *= 2;
			Vertex *newVert = new Vertex[cap];

			for (int ndx = 0; ndx < num_vertex; ndx++) {
				newVert[ndx] = vertices[ndx];
			}

			delete[] vertices;
			vertices = newVert;
		}
	}
	*/

public:

	// O(V + E)
	Graph(string file_name) 
	: num_vertex(0), num_edge(0)
	{
		ifstream iFile(file_name); // 1

		if (!iFile.is_open()) { // 1
			cerr << "File Could Not be Opened!" << endl; // 1
			exit(-1); // 1
		}

		string curLine; // 1
		getline(iFile, curLine); // 1
		num_vertex = stoi(curLine); // 1

		//cout << num_vertex << endl;

		vertices = new Vertex[num_vertex]; // 1

		for (int ndx = 0; ndx < num_vertex; ndx++) { // V
			vertices[ndx] = Vertex(ndx); // 1
		}

		while (getline(iFile, curLine)) { // E
			istringstream strm(curLine); // 1
			int src, dst, wt; // 1
			strm >> src; // 1
			strm >> dst; // 1
			strm >> wt; // 1
			
			// cout << src << " | " << dst << " | " << wt << endl;

			/*
			if (vertices[src].getId() == -1) {
				Vertex newVert(src);
				vertices[src] = newVert;
			}

			if (vertices[dst].getId() == -1) {
				Vertex newVert(dst);
				vertices[dst] = newVert;
			}
			*/

			Edge newEdge(src, dst, wt); // 1
			
			if (!vertices[src].isEdge(newEdge)) { // e
				vertices[src].add_edge(newEdge); // 1
			}

			if (!vertices[dst].isEdge(newEdge.reverse())) { // e
				vertices[dst].add_edge(newEdge.reverse()); // 1
			}

			num_edge++; // 1
		}
	}

	// O(1)
	int numVert() {
		return num_vertex; // 1
	}

	// O(1)
	int numEdge() {
		return num_edge; // 1
	}
	
	// O(1)
	Vertex * getVert() {
		return vertices; // 1
	}

	// O(Ve) == O(E) where e is # edges in given V
	void print(ostream & out) {
		out << "Graph - Num Vert: " << num_vertex << " Num Edge: " << num_edge << endl; // 1
		for (int ndx = 0; ndx < num_vertex; ndx++) { // V
			vertices[ndx].print(out); // e
		}
		out << endl; // 1
	}

	~Graph() {
		delete[] vertices;
	}

};


#endif // GRAPH_HPP

