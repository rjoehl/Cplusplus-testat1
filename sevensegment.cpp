#include "sevensegment.h"
#include <vector>
#include <algorithm>
#include <ostream>

std::vector<std::vector<std::string>> const v {
		{" - ","   "," - "," - ","   "," - "," - "," - "," - "," - "},
		{"| |","  |","  |","  |","| |","|  ","|  ","  |","| |","| |"},
		{"   ","   "," - "," - "," - "," - "," - ","   "," - "," - "},
		{"| |","  |","|  ","  |","  |","  |","| |","  |","| |","  |"},
		{" - ","   "," - "," - ","   "," - "," - ","   "," - ","   "},
};
std::vector<std::vector<std::string>> const e {
	{" - ","   ","   ","   ","   "},
	{"|  ","   ","   ","   ","   "},
	{" - "," - "," - "," - "," - "},
	{"|  ","|  ","|  ","| |","|  "},
	{" - ","   ","   "," - ","   "},
};
void printError(std::ostream &out){
	for_each(begin(e), end(e),[&](auto const line) {
		for_each(begin(line), end(line), [&](auto const digit) {
			out<< digit;
		});
		out << '\n';
	});
}

void printLargeNumber(int i, std::ostream &out) {
	std::vector<int> digits{};
	do {
		int const last { i % 10 };
		digits.push_back(last);
		i = (i - last) / 10;
	} while(i != 0);
	for_each(begin(v),end(v),[&](auto const line) {
		for_each(rbegin(digits), rend(digits), [&](auto const digit) {
			out<< line[digit];
		});
		out << '\n';
	});
}

void printLargeDigit(int i, std::ostream &out) {
	for_each(begin(v),end(v),[&](auto const x){
		out<< x[i] << '\n';
	});
}
