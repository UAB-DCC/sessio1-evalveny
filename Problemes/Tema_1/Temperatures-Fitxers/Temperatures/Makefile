all: temps

temps: main.o TemperaturaDia.o TemperaturaSetmana.o
	g++ main.o TemperaturaDia.o TemperaturaSetmana.o -o temps

main.o: main.cpp
	g++ -c main.cpp

TemperaturaDia.o: TemperaturaDia.cpp
	g++ -c TemperaturaDia.cpp

TemperaturaSetmana.o: TemperaturaSetmana.cpp
	g++ -c TemperaturaSetmana.cpp

clean:
	rm *o temps
