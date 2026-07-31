CXX = g++
CXXFLAGS = -I/home/elroy/Desktop/programming/levelDB/include
LDFLAGS = -L/home/elroy/Desktop/programming/levelDB/build
LDLIBS = -lleveldb

TARGET = initLeveldb
SRCS = initLeveldb.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(TARGET)

.PHONY: clean