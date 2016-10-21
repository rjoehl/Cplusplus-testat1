#include "pocketcalculator.h"
#include "calc.h"
#include "sevensegment.h"
#include <string>
#include <sstream>

void pocketcalculator(std::istream &in, std::ostream &out) {
	std::string input{};
	while (std::getline(in, input)) {
		std::istringstream line{input};
		try {
			auto const result = calc(line);
			if (result <= 99999999) {
				printLargeNumber(result, out);
			} else {
				printError(out);
			}
		} catch (std::invalid_argument &e) {
			printError(out);
		}

	}
}
