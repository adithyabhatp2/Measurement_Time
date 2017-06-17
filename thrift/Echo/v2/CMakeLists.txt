cmake_minimum_required(VERSION 3.6)
project(v2)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCE_FILES ../gen-cpp/Echo.cpp ../gen-cpp/echo_types.cpp Echo_client.cpp Echo_server.cpp)

#add_executable(v2 ${SOURCE_FILES})

include_directories(/unsup/thrift-0.9.3/include /unsup/boost-1.58.0/include ../gen-cpp)

#link_directories(/unsup/boost-1.58.0/lib /unsup/thrift-0.9.3/lib)

add_executable(CppServer Echo_server.cpp ../gen-cpp/Echo.cpp ../gen-cpp/echo_constants.cpp ../gen-cpp/echo_types.cpp)
add_executable(CppClient Echo_client.cpp  ../gen-cpp/Echo.cpp ../gen-cpp/echo_constants.cpp ../gen-cpp/echo_types.cpp)

find_library(THRIFT_LIBRARY thrift HINTS /unsup/thrift-0.9.3/lib)

target_link_libraries(CppServer PUBLIC ${THRIFT_LIBRARY})
target_link_libraries(CppClient PUBLIC ${THRIFT_LIBRARY})

set_source_files_properties( Echo_client.cpp PROPERTIES COMPILE_FLAGS "-std=c++11" )

# Corresponding makefile
# ref http://stackoverflow.com/questions/9956861/thrift-cpp-sample-code-compile-error

#USR_DIR    =/usr
#THRIFT_DIR =/unsup/thrift-0.9.3
#BOOST_DIR  =/unsup/boost-1.58.0
#INCS_DIRS  =-I${BOOST_DIR}/include -I${THRIFT_DIR}/include 
# original file has I${USR_DIR}/include -I${THRIFT_DIR}/include/thrift ${USR_DIR}/boost/1.49.0/include/boost
#LIBS_DIRS  =-L${BOOST_DIR}/lib -L${THRIFT_DIR}/lib
#CPP_DEFS   =-D=HAVE_CONFIG_H
#CPP_OPTS   =-Wall -O2
#LIBS       =-lthrift

#service name from thrift file
#GEN_SRC    = ../gen-cpp/Echo.cpp  \
#             ../gen-cpp/echo_types.cpp
#GEN_INC    = -I../gen-cpp

#default: server client

#server: Echo_server.cpp
#	g++ ${CPP_OPTS} ${CPP_DEFS} -o CppServer ${GEN_INC} ${INCS_DIRS} Echo_server.cpp ${GEN_SRC} ${LIBS_DIRS} ${LIBS}

#client: Echo_client.cpp
#	g++ ${CPP_OPTS} -std=c++11 ${CPP_DEFS} -o CppClient ${GEN_INC} ${INCS_DIRS} Echo_client.cpp ${GEN_SRC} ${LIBS_DIRS} ${LIBS}

#clean:
#	$(RM) -r CppClient CppServer

# -std=c++11 throws weird errors in server, about shared_ptr etc
