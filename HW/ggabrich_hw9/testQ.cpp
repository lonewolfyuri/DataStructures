// George Gabricht
//
// 56735102 - ggabrich

#include "PriorityQueue.hpp"
using namespace std;

void cont() {
	string tester;
	cout << "Press Enter to Continue" << endl;
	getline(cin, tester);
	cout << endl;
}

void testInsert() {
        PriorityQueue<vNode> pq(10);

        vNode a(0, 10), b(1, 3), c(2, 7), d(3, 1), e(4, 9), f(5, 2), g(6, 8), h(7, 5);

        pq.insert(a);
        pq.insert(b);
        pq.insert(c);
        pq.insert(d);
        pq.insert(e);
        pq.insert(f);
        pq.insert(g);
        pq.insert(h);

        pq.print(cout);
}

void testExtract() {
	PriorityQueue<vNode> pq(10);

	vNode a(0, 10), b(1, 3), c(2, 7), d(3, 1), e(4, 9), f(5, 2), g(6, 8), h(7, 5);

	pq.insert(a);
	pq.insert(b);
	pq.insert(c);
	pq.insert(d);
	pq.insert(e);
	pq.insert(f);
	pq.insert(g);
	pq.insert(h);

	pq.print(cout);

	pq.extractMin();

	pq.print(cout);

	pq.extractMin();

	pq.print(cout);

	pq.extractMin();

	pq.print(cout);
}

void testSift() {
        PriorityQueue<vNode> pq(10);

        vNode a(0, 10), b(1, 3), c(2, 7), d(3, 1), e(4, 9), f(5, 2), g(6, 8), h(7, 5);

        pq.insert(a);
        pq.print(cout);
        pq.insert(b);
        pq.print(cout);
        pq.insert(c);
        pq.print(cout);
        pq.insert(d);
        pq.print(cout);
        pq.insert(e);
        pq.print(cout);
        pq.insert(f);
        pq.print(cout);
        pq.insert(g);
        pq.print(cout);
        pq.insert(h);
        pq.print(cout);

        pq.print(cout);
}

void testHeap() {
        PriorityQueue<vNode> pq(10);

        vNode a(0, 10), b(1, 3), c(2, 7), d(3, 1), e(4, 9), f(5, 2), g(6, 8), h(7, 5);

        pq.insert(a);
        pq.insert(b);
        pq.insert(c);
        pq.insert(d);
        pq.insert(e);
        pq.insert(f);
        pq.insert(g);
        pq.insert(h);

        pq.print(cout);
}

void testEnqueue() {
        PriorityQueue<vNode> pq(10);

        vNode a(0, 10), b(1, 3), c(2, 7), d(3, 1), e(4, 9), f(5, 2), g(6, 8), h(7, 5);

        pq.enqueue(a);
        pq.enqueue(b);
        pq.enqueue(c);
        pq.enqueue(d);
        pq.enqueue(e);
        pq.enqueue(f);
        pq.enqueue(g);
        pq.enqueue(h);

        pq.print(cout);
	
	vNode z(0, 6), x(4, 1), y(7, 10);

	pq.enqueue(z);
	pq.print(cout);
	
	pq.enqueue(x);
	pq.print(cout);

	pq.enqueue(y);
	pq.print(cout);
}

void testDequeue() {
        PriorityQueue<vNode> pq(10);

        vNode a(0, 10), b(1, 3), c(2, 7), d(3, 1), e(4, 9), f(5, 2), g(6, 8), h(7, 5);

        pq.insert(a);
        pq.insert(b);
        pq.insert(c);
        pq.insert(d);
        pq.insert(e);
        pq.insert(f);
        pq.insert(g);
        pq.insert(h);

        pq.print(cout);
}

int main() {
	testInsert();
	cont();
	testExtract();
	cont();
	testSift();
	cont();
	//testHieap();
	cont();
	testEnqueue();
	cont();
	//testDequeue();
	return 0;
}
