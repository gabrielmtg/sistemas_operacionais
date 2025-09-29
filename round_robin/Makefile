CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = main

SOURCES = main.cpp

$(TARGET) : $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SOURCES) $(TARGET)