CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter -I.
TARGET = program
OBJ_DIR = obj

SRCS = main.cpp \
       task1.cpp \
       task2.cpp \
       task3.cpp \
       task4.cpp \
       task5.cpp \
       task6.cpp \
       task7.cpp \
       stackN1.cpp

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean