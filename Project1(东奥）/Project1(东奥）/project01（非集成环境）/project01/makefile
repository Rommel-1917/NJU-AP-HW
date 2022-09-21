main:Administrator.o SQL.o Users.o Users.h Administrator.h main.o SQL.h Date.o Date.h
	g++ Administrator.o SQL.o Users.o  main.o Administrator.h Users.h SQL.h Date.o Date.h -o main
main.o:main.cpp
	g++ -c  main.cpp -o main.o
Administrator.o: Administrator.cpp
	g++ -c  Administrator.cpp -o Administrator.o
Users.o:Users.cpp
	g++  -c Users.cpp -o Users.o
SQL.o:SQL.cpp 
	g++ -c SQL.cpp -o SQL.o
Date.o: Date.cpp
	g++ -c Date.cpp -o Date.o

clean:
	rm *.o
	rm main