GEN_SRC := Key_Value_Database_Service.cpp key_values_constants.cpp key_values_types.cpp
GEN_OBJ := $(patsubst %.cpp,%.o, $(GEN_SRC))

THRIFT_DIR := /usr/local/include/thrift
BOOST_DIR := /usr/local/include

INC := -I$(THRIFT_DIR) -I$(BOOST_DIR)

all: KeyValueClient

%.o: %.cpp
		$(CXX) -Wall -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H $(INC) -c $< -o $@

KeyValueClient: KeyValueClient.o $(GEN_OBJ)
		$(CXX) $^ -o $@ -L/usr/local/lib -lthrift 

clean:
		$(RM) *.o KeyValueClient