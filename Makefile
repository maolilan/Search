all: driver

driver: main.o driver.o driver_test.o
	g++ main.o driver.o driver_test.o -o driver

main.o: main.cpp
	g++ -c main.cpp

driver.o: driver.cpp
	g++ -c driver.cpp

driver_test.o: driver_test.cpp
	g++ -c driver_test.cpp

clean:
	rm -rf *o driver
