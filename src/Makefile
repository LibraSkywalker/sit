CXX = g++
CXXFLAGS = -Wall -O3 -std=c++11 -DENV64 -DENABLE_COMPRESSION
LIBS = -lpthread -lboost_system -lboost_filesystem -lboost_date_time -lboost_program_options -lz

OBJECTS = Color.o Config.o Core.o Diff.o FileSystem.o Index.o \
	MurmurHash3.o Objects.o Refs.o sit.o Status.o Util.o
EXECUTABLE = sit

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

Color.o: Color.cc Color.hpp
Config.o: Config.cc Config.hpp FileSystem.hpp Util.hpp
Core.o: Core.cc Core.hpp FileSystem.hpp Util.hpp Index.hpp Config.hpp Refs.hpp Status.hpp
Diff.o: Diff.cc Diff.hpp Refs.hpp Objects.hpp MurmurHash3.hpp Index.hpp Util.hpp
FileSystem.o: FileSystem.cc FileSystem.hpp Util.hpp
Index.o: Index.cc Index.hpp Refs.hpp Objects.hpp FileSystem.hpp Util.hpp
MurmurHash3.o: MurmurHash3.cc MurmurHash3.hpp
Objects.o: Objects.cc Index.hpp Objects.hpp FileSystem.hpp Util.hpp
Refs.o: Refs.cc Refs.hpp FileSystem.hpp Util.hpp
sit.o: sit.cc Core.hpp Util.hpp FileSystem.hpp
Status.o: Status.cc Diff.hpp Index.hpp Status.hpp FileSystem.hpp Refs.hpp Util.hpp
Util.o: Util.cc Util.hpp FileSystem.hpp Color.hpp

.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@
