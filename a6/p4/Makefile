all: test-all
	./testLogicOperators
	./testArithmeticOperators
	./testIOOperators
	./testExceptions

test-all: testLogicOperators testArithmeticOperators testIOOperators testExceptions

run-testLogicOperators: testLogicOperators
		./testLogicOperators

testLogicOperators: Fraction.h Fraction.cpp testLogicOperators.cpp 
		g++ -Wall Fraction.cpp testLogicOperators.cpp -o testLogicOperators


run-testArithmeticOperators: testArithmeticOperators
		./testArithmeticOperators

testArithmeticOperators: Fraction.h Fraction.cpp testArithmeticOperators.cpp 
		g++ -Wall Fraction.cpp testArithmeticOperators.cpp -o testArithmeticOperators


run-testIOOperators: testIOOperators
		./testIOOperators

testIOOperators: Fraction.h Fraction.cpp testIOOperators.cpp 
		g++ -Wall Fraction.cpp testIOOperators.cpp -o testIOOperators


run-testExceptions: testExceptions
		./testExceptions

testExceptions: Fraction.h Fraction.cpp testExceptions.cpp 
		g++ -Wall Fraction.cpp testExceptions.cpp -o testExceptions

clean:
		rm testLogicOperators
		rm testArithmeticOperators
		rm testIOOperators
		rm testExceptions