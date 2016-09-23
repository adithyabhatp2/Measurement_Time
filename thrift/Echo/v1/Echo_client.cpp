

#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "../gen-cpp/Echo.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

int main() {
    boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    EchoClient client(protocol);

    try {
        transport->open();

        string msg = "adbhat Hellow World";
        string returnVal;

        client.echo(returnVal, msg);

        cout << "Echoing: " <<  returnVal << endl;
        transport->close();

    } catch (TException& tx) {
        cout << "ERROR: " << tx.what() << endl;
    }

    int temp = 0;
    cin >> temp;


}
