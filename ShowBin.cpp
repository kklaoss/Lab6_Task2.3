#include <iostream>
#include "ShowBin.h"
using namespace std;

void ShowBin::Operate(AString* pObj) {
	cout << pObj->GetName() << ": " << GetBinary(pObj) << endl;
	cin.get();
}

string ShowBin::GetBinary(AString* pObj) const {
	int nBinDigit = 4 * pObj->GetSize();
	char* binStr = new char[nBinDigit + 1];
	for (int k = 0; k < nBinDigit; ++k) binStr[k] = '0';
	binStr[nBinDigit] = 0;
	long decVal = GetDecimal(pObj);
	if (decVal == -1) return "";
	int i = nBinDigit - 1;
	while (decVal > 0) {
		binStr[i--] = (decVal % 2) + '0';
		decVal >>= 1;
	}
	string temp(binStr);
	delete[] binStr;
	return temp;
}

ShowBin show_bin;