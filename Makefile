main: main.cpp sum_functions.cpp
	g++ -ggdb -O0 -std=c++20 -Wall -Werror main.cpp sum_functions.cpp -o main

clean:
	rm main
