# Measuring Communication - Custom ReliableUDP vs Apache Thrift vs GRPC

Distributed Systems - CS 838
Main repo : https://github.com/f2008700/739_A1/

THRIFT 

Serialization : 
	https://github.com/thekvs/cpp-serializers
	http://www.eprosima.com/index.php/resources-all/performance/apache-thrift-vs-protocol-buffers-vs-fast-buffers
	Protocol - binary
	Transport - TMemoryBuffer
	Purpose - compute the overhead of marshalling(serialization), unmarshalling (deserialization) in Apache Thrift.
	

Cpp Tutorial : https://thrift.apache.org/tutorial/cpp
Echo : https://github.com/kazuho/manymanythreads/tree/master/thrift
https://diwakergupta.github.io/thrift-missing-guide/


CMake (for CLion compatibility) :
see Echo/v2/CMakeLists.txt for a good sample.


Makefile : 
# ref http://stackoverflow.com/questions/9956861/thrift-cpp-sample-code-compile-error
# -std=c++11 throws weird errors in server, about shared_ptr etc
http://stackoverflow.com/questions/13703647/how-to-properly-add-include-directories-with-cmake


