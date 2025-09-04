windows-build: logger socket server programm
	g++ -o bin/core.exe -Wall -Wextra -pedantic -std=c++17 \
	src/main.cpp \
	bin/of/logger bin/of/socket bin/of/server bin/of/programm \
	-lws2_32 -Iinclude
run:
	./bin/core.exe