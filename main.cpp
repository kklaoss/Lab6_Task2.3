#include <iostream>
#include <vector>
#include "Factory.h"
#include "Menu.h"
#include "ShowStr.h"
#include "ShowDec.h"
#include "ShowBin.h"

int main() {
	std::vector<Action*> actions = { &show_str, &show_dec, &show_bin };
	Factory factory;
	Menu menu(actions);

	while (true) {
		switch (menu.SelectJob()) {
		case AddObj: factory.AddObject(); break;
		case DelObj: factory.DeleteObject(); break;
		case WorkWithObj: {
			AString* obj = menu.SelectObject(factory);
			if (obj) {
				Action* act = menu.SelectAction(obj);
				act->Operate(obj);
			}
			break;
		}
		case Exit: return 0;
		}
	}
}