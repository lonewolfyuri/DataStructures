#include <iostream>
#include <fstream> // for doing file I/O
using namespace std;

static int NumAllocations = 0; // 1

// Class MyString defines a class similar to "std::string"
class MyString
{
	char * buf; // points to the array holding the characters in this MyString object.
	//Must be allocated in constructor and, maybe in other functions as well
	//This C-string must be null termiated and that is how you know the length
      	// strlen() will count the number of characters up to the first null character

      	// utility method to handle errors, note throws an exception to prevent
 	// access to undefined values.  Always call this method when you detect a 
 	// fatal error from any of your methods.
      	// T(N) = 1001
	void error(const char *s)
 	{
 		cerr << "Error: " << s << endl; // 1000
 	        throw 0; // 1
 	}

public:

	// T(N) = 6N + 1009
	explicit MyString( const char * s = "")
	// constructs this object from a c-string s (s is an array of char terminated by ‘\0’)
	// parameter, s, defaults to the empty string “”
	// write and use strdup() to implment this constructor, 
	// it allocates a new array, then uses strcpy() to copy chars from 
	// array s to the new array
	{
		buf = strdup(s); // 6N + 1008 + 1
	}

	// copy constructor for a MyString, must make a deep copy of
	// s for this.  You can use strdup() you wrote
	// T(N) = 6N + 1009
	MyString( const MyString & s )
	{	
		buf = strdup(s.buf); // 6N + 1008 + 1
	}

	// assigns this MyString from MyString s, MUST DO DEEP ASSIGNMENT
	// remember, both this and s have been previously constructed
	// so they each have storage pointed to by buf
	// T(N) = 6N + 2012
	MyString & operator = ( const MyString & s )
	{
		if (this != &s) { // 1
			delete[] buf; // 1000
			NumAllocations--; // 1
			buf = strdup(s.buf); // 6N + 1008 + 1
		}
		return *this; // 1
	}

	// return a reference to the char at position index, 0 is the first element and so on
	// index must be in bounds (see method above)
	// T(N) = 3N + 9
	char & operator [] ( const int index )
	{
		if ((index >= 0) && (index <= length())) { // 3N + 4 + 3 
			return buf[index]; // 2
		} else {
			char msg = '\0';
			error(&msg);
		}
	}

	// T(N) = 3N + 4
	int length() const
	{
		return strlen(buf); // 3N + 3 + 1 
	}

	// returns the index of the first occurance of c in this MyString
	// indices range from 0 to length()-1
	// returns -1 if the character c is not in this MyString
	// T(N) = 7N + 8
	int indexOf( char c ) const
	{
		int len = length(); // 3N + 4 + 1
		// int i = 1
		// i <= N
		// i++ = N
		// ------------------------
		// total = 4N + 2
		for (int i = 0; i <= len; i++) {
			if (buf[i] == c) { // 2*N
				return i; // 1
			}
		}
		return -1; // 1
	}

	// returns the index of the first occurance of pat in this MyString
	// indices range from 0 to length()-1
	// returns -1 if the character string pat is not in this MyString
	// write and use strstr() to implement this function
	// T(N) = 8M + 3N + 18
	int indexOf( const MyString & pat ) const	
	{
		// 3M + 6
		if (pat.length() == 0) { // 3M + 5
			return 0; // 1
		}
		// 3N + 5M + 8
		char* pos = strstr(buf, pat.buf);
		// 3
		if (pos != nullptr) { // 1
			return (pos - buf); // 2
		} 
		return -1; // 1
	}

	// True if the two MyStrings contain the same chars in same position
	// e.g, "abc"=="abc" returns true
	// write and use strcmp() to implement this function
	// T(N) = 11N + 3M + 18
	bool operator == ( const MyString & s ) const
	{
		// 11N + 3M + 18
		if (strcmp(buf, s.buf) == 0) { // 11N + 3M + 16
			return true; // 1
		} else {
			return false; // 1
		}
	}

	// concatenates this and s to make a new MyString
	// e.g., "abc"+"def" returns "abcdef"
	// write and use str2dup() to implement this function, it should 
	// allocate a new array then call strcpy() and strcat()
	// T(N) = 24N + 3M + 3032
	MyString operator + ( const MyString & s ) const
	{	
		// result = str2dup = 18N + 3M + 1022
		// const = 6N + 1009
		// del = 1000
		// return = 1
		char *result = str2dup(buf, s.buf);
		MyString newStr(result);
		delete[] result;
		NumAllocations--;
		return newStr;
		
	}

	// concatenates s onto end of this
	// e.g., s = "abc"; s+="def" now s is "abcdef"
	// use str2dup()
	// T(N) = 18N + 3M + 2025
	MyString & operator += ( const MyString & s )
	{	
		char *temp = buf; // 1
		buf = str2dup(buf, s.buf); // 18N + 3M + 1022
		delete[] temp; // 1000
		NumAllocations--; // 1
		return *(this); // 1
	}

	// returns another MyString that is the reverse of this MyString
	// e.g., s = "abc"; s.reverse() returns "cba"
	// write strrev(char *dest, char *src) like strcpy but copies the 
	// reverse of src into dest, then use it
	// T(N) = 18N + 3029
	MyString reverse() const
	{
		int buflen = strlen(buf); // 3N + 4
		char *result = new char[buflen+1]; // 1002
		NumAllocations++; // 1
		result[buflen] = '\0'; // 2
		// const = 6N + 1009
		// strrev = 9N + 9
		MyString newStr(strrev(result, buf)); // 15N + 1018
		delete[] result; // 1000
		NumAllocations--; // 1
		return newStr; // 1
	}

	// prints out this MyString to the ostream out
	// T(N) = 1000
	void print( ostream & out ) const
	{
		out << buf;
	}

	// reads a word from the istream in and this MyString
	// becomes the same as the characters in that word
	// use getline() to implement read()
	// T(N) = 6N + 3011
	void read( istream & in )
	{
		char inBuf[1024]; // 1
		in.getline(inBuf, 1024); // 1000
		delete[] buf; // 1000
		NumAllocations--; // 1
		buf = strdup(inBuf); // 6N + 1009		
	}

	// destruct a MyString, must free up any storage allocated within MyString
	// T(N) = 1001
	~MyString()
	{
		delete[] buf; // 1000
		NumAllocations--; // 1
	}

private:
	
	// T(N) = 6N + 1008
        char * strdup(const char *s) const {
                NumAllocations++; // 1 
		// strlen + 1 = 3N + 4
		// new = 1000
		// strcpy = 3N + 2
		// return = 1
		// ----------------------
		// total =  7N + 1008
                return strcpy(new char[strlen(s)+1], s);
        }
	
	// T(N) = 3N + 3
        char * strcpy(char *dest, const char *src) const {
                char *cur = dest; // 1
		const char *get = src; // 1
                while (*cur++ = *get++); // 3N
                return dest; // 1
        }
	
	// T(N) = 3N + 3
        int strlen(const char *s) const {
                int len = 0; // 1
		// int i = 1
		// s[i] comp = 2*N
		// ++i = 1*N
		// ------------------------
		// total = 3N + 1
                for(int i = 0; s[i] != '\0'; ++i) {
                        ++len; // 1*N
                }
                return len; // 1
        }

	// T(N) = 3N + 5M + 7
        char * strstr(const char *base, const char *comp) const {
                const char *b = base; // 1
                const char *c = comp; // 1
                char *result;
		// total = 3N + 1
                while (*b != *c) { // N
			// 2*N
                        if (*b++ == '\0') {
				// 1
                                return nullptr;
                        }
                }
                result = (char*)b; // 2
		// total = 5M + 1
                while (*b++ == *c++) { // 3*M
			// 2*M
                        if (*c == '\0') {
                                return result; // 1
                        }
                }
                return nullptr; // 1
        }
	
	// T(N) = 11N + 3M + 15
        int strcmp(const char *left, const char *right) const {
                int leftlen = strlen(left); // 3N + 4
                int rightlen = strlen(right); // 3M + 4
                int min;
		// total = 3
                if (leftlen < rightlen) { // 1
                        min = leftlen; // 1
                } else {
                        min = rightlen; // 1
                }
		// int i = 1
		// i<=min = N
		// i++ = N
		// -----------------------
		// total = 8N + 3
                for (int i = 0; i <= min; i++) {
                        if(left[i] < right[i]) { // 3*N
                                return -1; // 1
                        } else if (left[i] > right[i]) { // 3*N
                                return 1; // 1
                        }
                }
                return 0; // 1
        }
	
	// T(N) = 12N + 7
        char * strcat(char *dest, const char *src) const {
                int srclen = strlen(src); // 3N + 4
                int ndx = 0; // 1
		// 3N
                while (dest[ndx] != '\0') {
                        ndx++;
                }
		// int i = 1
		// i<=len = N
		// i++ = N
		// --------------------
		// total = 6N + 1
                for (int i = 0; i <= srclen; i++) {
                        dest[ndx++] = src[i]; // 4*N
                }
                return dest; // 1
        }
	
	// T(N) = 18N + 3M + 1021
        char * str2dup(const char *left, const char *right) const {
                // strlen(left) = 3N + 3
		// strlen(right) = 3M + 3
		// len + len + 1 = 3
		// new = 1000
		// assign = 1
		// ---------------------
		// total = 3N + 3M + 1010
		char *result = new char[strlen(left) + strlen(right) + 1];
                NumAllocations++; // 1
                strcpy(result, left); // 3N + 2
                strcat(result, right); // 12N + 7
                return result; // 1
        }

	// T(N) = 9N + 9
        char * strrev(char *dest, const char *src) const {
                int srclen = strlen(src); // 3N + 4
                // total = 6N + 4
		if (srclen == 0) { // 1
                        dest[0] = '\0'; // 1
                } else { 
                        int j = 0; // 1
			// int i = 1
			// len - 1 = 1
			// i>=0 = 1 * N
			// --i = 1 * N
			// ----------------------
			// total = 6N + 2
                        for (int i = srclen - 1; i >= 0; --i) {
                                dest[j++] = src[i]; // 4*N
                        }   
                }   
                return dest; // 1
        }   

};


// these two I/O methods are complete as long as you define print and read methods correctly
// T(N) = 1001
inline ostream & operator << ( ostream & out, const MyString & str )
{
	str.print(out); // 1000         
	return out; // 1
}

// T(N) = 6N + 3012
inline istream & operator >> ( istream & in, MyString & str )
{
	str.read(in); // 6N + 3011
	return in; // 1
}

// TBD: Write all these testing functions and add more of your own
// follow my example and write a function to test each method.
// Name each of these functions so they clearly indicate what they are testing
// T(N) = 6N + 1010
MyString copyConstructorTest(MyString l)
{
	// copy construct = 6N + 1009
	return l; // 1
}

// T(N) = M*(27N + 10047) + 6N + 4009
void testReverse()
{
	cout << "---Test Reverse---" << endl; // 1000
	ifstream in("input.txt"); // 1000
	MyString l; // 6N + 1009

	while ( in >> l ) { // M*(6N + 3012 + 1000)
		// cout = 1000*M
		// len = M*(3N + 4)
		// reverse = M*(18N + 3029)
		// << copy = 1001
		// << reverse = 1001
		cout << copyConstructorTest(l) << " " << l.length() << " " << l.reverse() << endl; // M*(21N + 6035)
	}
	cout << endl; // 1000
}

// T(N) = M*(12N + 9024) + 12N + 5018 
void testAssign() {
	cout << "---Test Assign--" << endl; // 1000
	MyString load, testAss; // 12N + 2018
	ifstream in("input.txt"); // 1000
	while (in >> load) { // M*(6N + 4012)
		testAss = load; // M*(6N + 2010)
		// cout = M*1000
		// << load = M*1001
		// << reverse = M*1001
		cout << "load: " << load << " testAss: " << testAss << endl; // 3002M
	}
	cout << endl; // 1000
}

// T(N) = M*(48N + 3L + 16076) + 18N + 6027)
void testAdd() {
	cout << "---Test +---" << endl; // 1000
	MyString add1, add2, load; // 3*(6N + 1009) = 18N + 3027
	ifstream in("input.txt"); // 1000
	while (in >> load) { // M*(6N + 4012)
		add2 = add1; // M*(6N + 2010)
		add1 = load; // M*(6N + 2010)
		load = add1+add2; // M*(30N +3L + 4041)
		// cout = 1000M
		// << add1 = 1001M
		// << add2 = 1001M
		// << load = M*(1001) 
		cout << "add1: " << add1 << " add2: " << add2 << " 1+2: " << load << endl; // 4003M
	}		
	cout << endl; // 1000
}

// T(N) = M*(66N + 9L + 20002) + 24N + 7036
void testAddEq() {
	cout << "---Test +=---" << endl; // 1000
	MyString test, blank, load, sum; // 4*(6N + 1009) = 24N + 4036
	ifstream in("input.txt"); // 1000
	while (in >> load) { // M*(6N + 4012)
		cout << "test: " << test; // 2001M
		test += blank; // M*(18N + 3L + 2025)
		// cout = 1000M
		// << test = 1001M
		// << load = 1001M
		cout << " test+=blank: " << test << " load: " << load; // 3002M
		test += load; // M*(18N + 3L + 2025)
		sum += test; // M*(18N + 3L + 2025)
		// cout = 1000M
		// << test = 1001M
		// << sum = 1001M
		cout << " test+=load: " << test << " sum+=test: " << sum << endl; // 3002M
		test = MyString(); // M*(6N + 1010)
	}
	cout << endl; // 1000
}

// T(N) = M*(9N + 8022) + 6N + 4009
void testIndexOp() {
	cout << "---Test []---" << endl; // 1000
	MyString test; // 6N + 1009
	ifstream in("input.txt"); // 1000
	while (in >> test) { // M*(6N + 4012)
		cout << "test: " << test << endl; // 2001M
		// int i = M
		// i < length = M*(3N + 5)
		// i++ = M
		for(int i = 0; i < test.length(); i++) { // M*(3N + 7)
			cout << test[i] << " "; // M*(2002)
		}
		cout << endl << endl; // 1000
	}
}

// T(N) = M*(22N + 7041) + 6N + 4009
void testIndexChar() {
	cout << "---Test IndexChar---" << endl; // 1000
	MyString test; // 6N + 1009
	int len; 
	ifstream in("input.txt"); // 1000
	while (in >> test) { // M*(6N + 4012)
		// length = M*(3N + 4)
		// len = length - 2 = 2M
		len = test.length(); // M*(3N + 6)
		// << test = 1001M
		// test[len] = M*(3N + 7)
		// cout = 1000M
		cout << "test: " << test << " test[len]: " << test[len]; // M*(3N + 2008)
		// cout = 1000M
		// test[len] = M*(3N + 7)
		// indexOf = M*(7N + 8)
		cout << " indexOf(test[len]): " << test.indexOf(test[len]) << endl; // M*(10N + 1015)
	} 
	cout << endl; // 1000
}

// T(N) = M*(15N + 8L + 10043) + 12N + 5018
void testIndexString() {
	cout << "---Test IndexString---" << endl; // 1000
	MyString test, load; // 12N + 2018
	ifstream in("input.txt"); // 1000
	while (in >> load) { // M*(6N + 4012)
		// cout = 1000M
		// << test = 1001M
		// << load = 1001M
		cout << "test: " << test << " load: " << load; // 3002M
		// cout = 1000M
		// indexOf = M*(8L + 3N + 18)
		cout << " indexOf(test): " << load.indexOf(test) << endl; // M*(8L + 3N + 1018)
		test = load; // M*(6N + 2010)
	}
	cout << endl; // 1000
}

// T(N) = M*(23N + 3L + 9042) + 12N + 5018
void testCompare() {
	cout << "---Test ==---" << endl; // 1000
	MyString test, load; // 12N + 2018
	bool result;
	ifstream in("input.txt"); // 1000
	while (in >> load) { // M*(6N + 4012)
		// test == load = M*(11N + 3L + 18)
		// result = M
		result = (test == load); // M*(11N + 3L + 18)
		// cout == 1000M
		// << test = 1001M
		// << load = 1001M
		cout << "test: " << test << " load: " << load << " test==load: " << result << endl; // 3002M
		test = load; // M*(6N + 2010)
	}
	cout << endl; // 1000
}

int main()
{
	// This try/catch will catch any exception thrown by MyString::error()
    	// while calling test functions.
     	try {
		cout << endl;
     		testReverse();
     		testAssign();
		testAdd();
		testAddEq();
		testIndexOp();
		testIndexChar();
		testIndexString();
		testCompare();
	}
     	catch (int i) {
     		cout << "Got an exception: " << i << endl;
     	}
     	cerr << "Net memory allocated at program end: " << NumAllocations << endl;
     	cerr << "(should be zero! positive = memory leak, negative = duplicate delete)\n";
     	return 0;
}




