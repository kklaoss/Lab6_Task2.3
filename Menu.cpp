#include <iostream>
#include "Menu.h"
using namespace std;

Menu::Menu(vector<Action*> _pAct) : pAct(_pAct) {}

JobMode Menu::SelectJob() const {
	cout << "Select job mode:\n1. Add\n2. Delete\n3. Work\n4. Exit\n";
	int item = SelectItem(4);
	return static_cast<JobMode>(item - 1);
}

AString* Menu::SelectObject(const Factory& fctry) const {
	int nItem = fctry.pObj.size();
	if (!nItem) return nullptr;
	cout << "Select object:\n";
	for (int i = 0; i < nItem; ++i)
		cout << i + 1 << ". " << fctry.pObj[i]->GetName() << endl;
	int item = SelectItem(nItem);
	return fctry.pObj[item - 1];
}

Action* Menu::SelectAction(const AString* pObj) const {
	cout << "Select action:\n";
	for (size_t i = 0; i < pAct.size(); ++i)
		cout << i + 1 << ". " << pAct[i]->GetName() << endl;
	int item = SelectItem(pAct.size());
	return pAct[item - 1];
}

int Menu::SelectItem(int max) {
	int choice;
	while (true) {
		cin >> choice;
		if (choice >= 1 && choice <= max) break;
		cout << "Invalid input! Try again: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return choice;
}