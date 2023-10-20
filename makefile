main: Passenger.o Passengers.o Driver.o Drivers.o Ride.o main.o
	g++ Passenger.cpp Passengers.cpp Driver.cpp Drivers.cpp Ride.cpp main.cpp -o main

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

clean:
	rm *.o main