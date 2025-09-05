CXX:=g++
CXX_FLAGS:=-Wall -Wextra -pedantic -std=c++17 -ISource -ILibrary -LLibrary

Packet: Source/Network/Packet.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o Binary/Object/Packet.o

Socket: Source/Network/Socket.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o Binary/Object/Socket.o