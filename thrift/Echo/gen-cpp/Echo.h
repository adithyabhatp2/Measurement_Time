/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Echo_H
#define Echo_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "echo_types.h"



#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class EchoIf {
 public:
  virtual ~EchoIf() {}
  virtual void echo(std::string& _return, const std::string& msg) = 0;
};

class EchoIfFactory {
 public:
  typedef EchoIf Handler;

  virtual ~EchoIfFactory() {}

  virtual EchoIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(EchoIf* /* handler */) = 0;
};

class EchoIfSingletonFactory : virtual public EchoIfFactory {
 public:
  EchoIfSingletonFactory(const boost::shared_ptr<EchoIf>& iface) : iface_(iface) {}
  virtual ~EchoIfSingletonFactory() {}

  virtual EchoIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(EchoIf* /* handler */) {}

 protected:
  boost::shared_ptr<EchoIf> iface_;
};

class EchoNull : virtual public EchoIf {
 public:
  virtual ~EchoNull() {}
  void echo(std::string& /* _return */, const std::string& /* msg */) {
    return;
  }
};

typedef struct _Echo_echo_args__isset {
  _Echo_echo_args__isset() : msg(false) {}
  bool msg :1;
} _Echo_echo_args__isset;

class Echo_echo_args {
 public:

  Echo_echo_args(const Echo_echo_args&);
  Echo_echo_args& operator=(const Echo_echo_args&);
  Echo_echo_args() : msg() {
  }

  virtual ~Echo_echo_args() throw();
  std::string msg;

  _Echo_echo_args__isset __isset;

  void __set_msg(const std::string& val);

  bool operator == (const Echo_echo_args & rhs) const
  {
    if (!(msg == rhs.msg))
      return false;
    return true;
  }
  bool operator != (const Echo_echo_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Echo_echo_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Echo_echo_pargs {
 public:


  virtual ~Echo_echo_pargs() throw();
  const std::string* msg;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Echo_echo_result__isset {
  _Echo_echo_result__isset() : success(false) {}
  bool success :1;
} _Echo_echo_result__isset;

class Echo_echo_result {
 public:

  Echo_echo_result(const Echo_echo_result&);
  Echo_echo_result& operator=(const Echo_echo_result&);
  Echo_echo_result() : success() {
  }

  virtual ~Echo_echo_result() throw();
  std::string success;

  _Echo_echo_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const Echo_echo_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Echo_echo_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Echo_echo_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Echo_echo_presult__isset {
  _Echo_echo_presult__isset() : success(false) {}
  bool success :1;
} _Echo_echo_presult__isset;

class Echo_echo_presult {
 public:


  virtual ~Echo_echo_presult() throw();
  std::string* success;

  _Echo_echo_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class EchoClient : virtual public EchoIf {
 public:
  EchoClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  EchoClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void echo(std::string& _return, const std::string& msg);
  void send_echo(const std::string& msg);
  void recv_echo(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class EchoProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<EchoIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (EchoProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_echo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  EchoProcessor(boost::shared_ptr<EchoIf> iface) :
    iface_(iface) {
    processMap_["echo"] = &EchoProcessor::process_echo;
  }

  virtual ~EchoProcessor() {}
};

class EchoProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  EchoProcessorFactory(const ::boost::shared_ptr< EchoIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< EchoIfFactory > handlerFactory_;
};

class EchoMultiface : virtual public EchoIf {
 public:
  EchoMultiface(std::vector<boost::shared_ptr<EchoIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~EchoMultiface() {}
 protected:
  std::vector<boost::shared_ptr<EchoIf> > ifaces_;
  EchoMultiface() {}
  void add(boost::shared_ptr<EchoIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void echo(std::string& _return, const std::string& msg) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->echo(_return, msg);
    }
    ifaces_[i]->echo(_return, msg);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class EchoConcurrentClient : virtual public EchoIf {
 public:
  EchoConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  EchoConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void echo(std::string& _return, const std::string& msg);
  int32_t send_echo(const std::string& msg);
  void recv_echo(std::string& _return, const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif



#endif
