CXXFLAGS = -Wall
CC=g++

# to compile
track: track.o proglog.o
	$(CXX) -o $@ $^

execs = track
# to clean
clean:
	rm -f $(execs) *.o
