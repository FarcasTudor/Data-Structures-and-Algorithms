#include <iostream>
#include "TestExtins.h"
#include "TestScurt.h"
using namespace std;


int main() {
	cout << "All tests started..." << endl;
	testAll();
	testAllExtins();
	cout << "All tests passed...";
}
