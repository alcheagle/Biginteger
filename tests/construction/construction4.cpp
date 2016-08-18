#include <iostream>
#include "bigint.hpp"
#include <utility>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace bigint;

bool test_to_string(const UnsignedBigint& n, const std::string expected) {
    string s = (n.to_string());
    cout << setfill(' ') << setw(10) << "tostring " << s << ", expected: " << expected;
    if (s != expected) {
	cout << " " << false << endl;
	return false;
    } else {
	cout << " " << true << endl;
	return true;
    }
}

bool test_stream(const UnsignedBigint& n, const std::string expected) {
    cout << setfill(' ') << setw(10) << "stream " << n << ", expected: " << expected;

    stringstream ss;
    ss << n;

    if (ss.str() != expected) {
	cout << " " << false << endl;
	return false;
    } else {
	cout << " " << true << endl;
	return true;
    }
}

int main(int argc, char** argv) {
    vector<pair<UnsignedBigint*, std::string> > n;
    
    bool success = true;
    cout << "start testing: " << endl;
    for (unsigned int i = 0; i < n.size(); i++) {
	success = test_to_string(*n[i].first, n[i].second) && success;
	success = test_stream(*n[i].first, n[i].second) && success;

	delete n[i].first;
	n[i].first = NULL;
    }
    
    return success ? 0 : 1;
}

