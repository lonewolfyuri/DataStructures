// George Gabricht
//
// ggabrich - 56735102

#include "LinkedStack.hpp"
using namespace std;

bool isBalanced(string & word);

int main(int argc, char *argv[]) { // O(N)
	
	string check = argc == 2 ? argv[1] : "({(())})((([({})])))(((((<>([{()}])(<>))))))()";
	string result = isBalanced(check) == true ? "True" : "False";
	cout << result << endl;
	return 0;
}

bool isBalanced(string & word) { // O(N)
	string sub;
	LinkedStack stk;
	int len = word.length();
	try {
		for (int ndx = 0; ndx < len; ndx++) {
			sub = word.substr(ndx, 1);
			// cout << "Sub: " << sub << endl;	
			switch(sub[0]) {
				case '(': {
					stk.push(sub);
					break;
				}
				case '{': {
					stk.push(sub);
					break;
				}
				case '<': {
					stk.push(sub);
					break;
				}
				case '[': {
					stk.push(sub);
					break;
				}
				case ')': {
					if (stk.top() == "(") {
						stk.pop();
					} else {
						return false;
					}
					break;
				}
				case '}': {
                                	if (stk.top() == "{") {
                                        	stk.pop();
                                	} else {
                                        	return false;
                                	}
                                	break;  
                        	} 
				case '>': {
                                	if (stk.top() == "<") {
                                	        stk.pop();
                                	} else {
                                        	return false;
                                	}
                                	break;  
                        	} 
				case ']': {
                                	if (stk.top() == "[") {
                                        	stk.pop();
                                	} else {
                                 		return false;
                                	}
                                	break;  
                        	} 
				default:
					return false;
			}
			//if (!stk.isEmpty()) {	
			//	cout << "Stk.top(): " << stk.top() << endl;
			//}
		}
		return stk.isEmpty();
	} catch (ContainerUnderflow) {
		return false;
	}
}
