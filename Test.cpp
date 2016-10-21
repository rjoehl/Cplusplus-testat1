#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "src/sevensegment.h"
#include "src/calc.h"
#include "src/pocketcalculator.h"
#include <ostream>

void test_calc_addition() {
	ASSERT_EQUAL(calc(4,'+',4), 8);
}

void test_calc_multiplication() {
	ASSERT_EQUAL(calc(4,'*',4), 16);
}

void test_calc_division() {
	ASSERT_EQUAL(calc(8,'/',2), 4);
}

void test_calc_divzero() {
	ASSERT_THROWS(calc(5, 0, '/'), std::invalid_argument);
}

void test_stream_calc() {
	std::istringstream is("5 + 6");
	ASSERT_EQUAL(calc(is), 11);
}

void test_printLargeDigit() {
	std::ostringstream os{};
	printLargeDigit(0, os);
	ASSERT_EQUAL(" - \n| |\n   \n| |\n - \n", os.str());
}

void test_printLargeNumber() {
	std::ostringstream os{};
	printLargeNumber(24, os);
	ASSERT_EQUAL(" -    \n  || |\n -  - \n|    |\n -    \n", os.str());
}

void test_pocketcalculator() {
	std::istringstream is("13 + 11");
	std::ostringstream os{};
	pocketcalculator(is, os);
	ASSERT_EQUAL(" -    \n  || |\n -  - \n|    |\n -    \n", os.str());
}

void test_pocketcalculator_invalid_input() {
	std::istringstream is("13 // 12");
	std::ostringstream os{};
	pocketcalculator(is, os);
	ASSERT_EQUAL(" -             \n|              \n -  -  -  -  - \n|  |  |  | ||  \n -        -    \n", os.str());
}

void test_pocketcalculator_too_big() {
	std::istringstream is("10000000000000 + 1");
	std::ostringstream os{};
	pocketcalculator(is, os);
	ASSERT_EQUAL(" -             \n|              \n -  -  -  -  - \n|  |  |  | ||  \n -        -    \n", os.str());
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(test_printLargeNumber));
	s.push_back(CUTE(test_printLargeDigit));
	s.push_back(CUTE(test_calc_addition));
	s.push_back(CUTE(test_calc_multiplication));
	s.push_back(CUTE(test_calc_division));
	s.push_back(CUTE(test_stream_calc));
	s.push_back(CUTE(test_calc_divzero));
	s.push_back(CUTE(test_pocketcalculator));
	s.push_back(CUTE(test_pocketcalculator_invalid_input));
	s.push_back(CUTE(test_pocketcalculator_too_big));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
