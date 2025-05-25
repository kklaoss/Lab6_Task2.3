#include <iostream>
#include "Factory.h"
#include "Menu.h"
#include "SymbString.h"
#include "HexString.h"
using namespace std;

#define MAX_LEN_STR 100

void Factory::AddObject() {
	cout << "Select object type:\n1. Symbolic string\n2. Hexadecimal string\n";
	int item = Menu::SelectItem(2);
	string name, value;
	cout << "Enter object name: ";
	cin >> name;
	cin.get();
	cout << "Enter object value: ";
	char buf[MAX_LEN_STR];
	cin.getline(buf, MAX_LEN_STR);
	value = buf;

	AString* pNewObj = nullptr;
	switch (item) {
	case 1: pNewObj = new SymbString(name, value); break;
	case 2:
		if (IsHexStrVal(value)) pNewObj = new HexString(name, value);
		else cout << "Invalid hex string!\n";
		break;
	}
	if (pNewObj) pObj.push_back(pNewObj);
}

void Factory::DeleteObject() {
	int nItem = pObj.size();
	if (!nItem) {
		cout << "No objects to delete.\n";
		return;
	}
	cout << "Select object to delete:\n";
	for (int i = 0; i < nItem; ++i)
		cout << i + 1 << ". " << pObj[i]->GetName() << endl;
	int item = Menu::SelectItem(nItem);
	delete pObj[item - 1];
	pObj.erase(pObj.begin() + item - 1);
}