main: Passenger.o Passengers.o Driver.o Drivers.o Ride.o Rides.o Basic.o Economy.o Group.o Luxury.o main.o
	g++ Passenger.cpp Passengers.cpp Driver.cpp Drivers.cpp Ride.cpp Rides.cpp Basic.cpp Economy.cpp Group.cpp Luxury.cpp main.cpp -o main

Passenger.o: Passenger.cpp
	g++ -c Passenger.cpp

Passengers.o: Passengers.cpp
	g++ -c Passengers.cpp

Driver.o: Driver.cpp
	g++ -c Driver.cpp

Drivers.o: Drivers.cpp
	g++ -c Drivers.cpp

Ride.o: Ride.cpp
	g++ -c Ride.cpp
Rides.o: Rides.cpp
	g++ -c Rides.cpp
Basic.o: Basic.cpp
	g++ -c Basic.cpp
Economy.o: Economy.cpp
	g++ -c Economy.cpp
Group.o: Group.cpp
	g++ -c Group.cpp
Luxury.o: Luxury.cpp
	g++ -c Luxury.cpp

clean:
	rm *.o main