CXX = g++
CXXFLAGS = -std=c++11
SRC = main.cpp admission.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main_new  # Change the executable name to "main_new"

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

