// George Gabricht
//
// 56735102 - ggabrich


#ifndef GRAPH_HPP

#define GRAPH_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Edge {

private:
	int src, dst, weight;

public:
	// O(1)
	Edge(int s, int d, int w) 
	: src(s), dst(d), weight(w)
	{}

	// O(1)
	int getSrc() {
		return src;
	}

	// O(1)
	int getDst() {
		return dst;
	}

	// O(1)
	int getWeight() {
		return weight;
	}

	// O(1)
	void print(ostream & out) {
		out<< "\t\tEdge - Src: " <<src<< " | Dst: " <<dst<< " | Weight: " <<weight<<endl;
	}
};

class Vertex {

private:
	int id;
	vector<Edge> edges;

public:
	// O(1)
	Vertex() : id(-1) {}
	
	// O(1)
	Vertex(int i) : id(i) {}

	// O(1)
	int getId() {
		return id;
	}

	// O(1)
	void setId(int i) {
		id = i;
	}

	// O(1)
	vector<Edge> getEdges() {
		return edges;
	}

	// O(1)
	void add_edge(const Edge & e) {
		edges.push_back(e);
	}

	// O(e) -> O(1) | e = number of edges in vertex
	void print(ostream & out) {
		out << "\tVertex - ID: " << id << endl;
		for (Edge eg : edges) {
			eg.print(out);
		}
	}

};

class Graph {

private:
	int num_vertex, num_edge;
	Vertex *vertices;
	vector<Edge> edges;

public:
	// O(V + E)
	Graph(string file_name)
	: num_vertex(0), num_edge(0) {
		ifstream iFile(file_name); // 1

		if (!iFile.is_open()) { // 1
			cerr << "File could not be opened! Goodbye!" << endl;
			exit(-1);
		}

		string curLine; // 1
		getline(iFile, curLine); // 1
		num_vertex = stoi(curLine); // 1

		vertices = new Vertex[num_vertex]; // 1

		for (int ndx = 0; ndx < num_vertex; ndx++) { // V
			vertices[ndx] = Vertex(ndx); // 1
		}

		while (getline(iFile, curLine)) { // E
			int src, dst, weight; // 1
			istringstream strm(curLine); // 1

			strm >> src; // 1
			strm >> dst; // 1
			strm >> weight; // 1

			add_edge(src, dst, weight); // 1 
		}

		iFile.close(); // 1
	}

	// O(1)
	void add_edge(int src, int dst, int weight) {
		const Edge eg(src, dst, weight); // 1
		vertices[src].add_edge(eg); // 1
		edges.push_back(eg); // 1
		num_edge++; // 1
	}
	
	// O(1)
	int numVert() {
		return num_vertex;
	}

	// O(1)
	int numEdge() {
		return num_edge;
	}

	// O(1)
	Vertex * getVert() {
		return vertices;
	}

	// O(1)
	vector<Edge> getEdge() {
		return edges;
	}

	// O(VE)
	void print(ostream & out) {
		out<< "Graph - Num Vertices: " << num_vertex << " | Num Edges: " << num_edge <<endl;// 1

		for (int ndx = 0; ndx < num_vertex; ndx++) { // V
			vertices[ndx].print(out); // E
		}
		
		out << endl; // 1
	}

	// O(1)
	~Graph() {
		delete[] vertices; // 1
	}

};

#endif // GRAPH_HPP


