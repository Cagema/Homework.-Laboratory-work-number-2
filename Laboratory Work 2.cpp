#include "pch.h"
#include <iostream>
#include "Map.h"
#include "List.h"

using namespace std;

int main(int argc, char* argv[]) {

	Map<int, int> lst;

	cout << "\n~Now make tree and show result~\n\n";

	lst.insert(7, 5);
	lst.show();

	cout << lst.get_values();

	/*List<char> listofkey;
	listofkey = lst.get_keys();
	cout << listofkey << endl;
	listofkey.clear();*/

	/*cout << "\n~Now remove node with key d and show result~\n\n";
	lst.remove('d');
	lst.show();

	cout << "\n~Now found a node with key b and show his value~\n";
	cout << lst.find('b')->value;

	cout << "\n\n~Now clear tree and show result~\n";
	lst.clear();
	lst.show();
	cout << "\n";*/

	return 0;
}