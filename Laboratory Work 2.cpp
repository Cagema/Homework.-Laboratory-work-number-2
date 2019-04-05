#include "pch.h"
#include <iostream>
#include "Map.h"

using namespace std;

int main(int argc, char* argv[]) {

	Map<char, int> lst;

	cout << "\n~Now make tree and show result~\n\n";

	lst.insert('a', 5);
	lst.insert('b', 4);
	lst.insert('c', 3);
	lst.insert('d', 2);
	lst.insert('e', 1);
	lst.show();

	cout << "\n~Now remove node with key d and show result~\n\n";
	lst.remove('d');
	lst.show();

	cout << "\n~Now found a node with key b and show his value~\n";
	cout << lst.find('b')->value;

	cout << "\n\n~Now clear tree and show result~\n";
	lst.clear();
	lst.show();
	cout << "\n";

	return 0;
}