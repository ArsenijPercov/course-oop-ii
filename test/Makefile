run-test-all: test-all
	./testoperators
	./testfunctions
	./testduration
	./testexceptions

test-all: testoperators testfunctions testduration testexceptions

run-testoperators: testoperators
	./testoperators

testoperators: Date3.h Date3.cpp TestOperators.cpp
	g++ -Wall -o testoperators Date3.cpp TestOperators.cpp
	
run-testfunctions: testfunctions
	./testfunctions
	
testfunctions: Date3.h Date3.cpp TestFunctions.cpp
	g++ -Wall -o testfunctions Date3.cpp TestFunctions.cpp
	
run-testduration: testduration
	./testduration

testduration: Date3.h Date3.cpp TestDuration.cpp
	g++ -Wall -o testduration Date3.cpp TestDuration.cpp
	
run-testexceptions: testexceptions
	./testexceptions

testexceptions: Date3.h Date3.cpp TestExceptions.cpp
	g++ -Wall -o testexceptions Date3.cpp TestExceptions.cpp
	
doc:
	doxygen

clear:
	rm testoperators
	rm testfunctions
	rm testduration
	rm testexceptions
	
clobber:
	rm -rf html latex