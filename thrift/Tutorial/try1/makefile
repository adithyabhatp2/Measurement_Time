# ref http://stackoverflow.com/questions/9956861/thrift-cpp-sample-code-compile-error

USR_DIR    =/usr
THRIFT_DIR =/unsup/thrift-0.9.3
BOOST_DIR  =/unsup/boost-1.58.0
INCS_DIRS  =-I${BOOST_DIR}/include -I${THRIFT_DIR}/include 
# original file has I${USR_DIR}/include -I${THRIFT_DIR}/include/thrift ${USR_DIR}/boost/1.49.0/include/boost
LIBS_DIRS  =-L${BOOST_DIR}/lib -L${THRIFT_DIR}/lib
CPP_DEFS   =-D=HAVE_CONFIG_H
CPP_OPTS   =-Wall -O2
LIBS       =-lthrift


GEN_SRC    = ../gen-cpp/SharedService.cpp  \
             ../gen-cpp/shared_types.cpp   \
             ../gen-cpp/tutorial_types.cpp \
             ../gen-cpp/Calculator.cpp
GEN_INC    = -I../gen-cpp

default: server client

server: CppServer.cpp
	g++ ${CPP_OPTS} ${CPP_DEFS} -o CppServer ${GEN_INC} ${INCS_DIRS} CppServer.cpp ${GEN_SRC} ${LIBS_DIRS} ${LIBS}

client: CppClient.cpp
	g++ ${CPP_OPTS} ${CPP_DEFS} -o CppClient ${GEN_INC} ${INCS_DIRS} CppClient.cpp ${GEN_SRC} ${LIBS_DIRS} ${LIBS}

clean:
	$(RM) -r CppClient CppServer
