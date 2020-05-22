hw4: main.o driver.o drivers.o passenger.o passengers.o ride.o rides.o base.o economy.o basic.o group.o luxury.o
	g++ -o hw4 main.o driver.o drivers.o passenger.o passengers.o ride.o rides.o base.o economy.o basic.o group.o luxury.o
driver.o: driver.cpp driver.h
	g++ -c driver.cpp
drivers.o: drivers.cpp drivers.h base.h
	g++ -c drivers.cpp
passenger.o: passenger.cpp passenger.h
	g++ -c passenger.cpp
passengers.o: passengers.cpp passengers.h
	g++ -c passengers.cpp
ride.o: ride.cpp ride.h
	g++ -c ride.cpp
rides.o: rides.cpp rides.h
	g++ -c rides.cpp
base.o: base.cpp base.h
	g++ -c base.cpp
economy.o: economy.cpp economy.h base.h
	g++ -c economy.cpp
basic.o: basic.cpp basic.h base.h
	g++ -c basic.cpp
group.o: group.cpp group.h base.h
	g++ -c group.cpp
luxury.o: luxury.cpp luxury.h base.h
	g++ -c luxury.cpp
main.o: main.cpp drivers.h passengers.h rides.h
	g++ -c main.cpp
clean:
	rm *.o