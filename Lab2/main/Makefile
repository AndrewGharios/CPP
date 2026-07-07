CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = program.exe
SOURCES = main.cpp Region.cpp City.cpp Location.cpp Metropolis.cpp Place.cpp TObject.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o $(TARGET) 2>nul || true

.PHONY: clean