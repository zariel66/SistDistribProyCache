/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Key_Value_Database_Service_H
#define Key_Value_Database_Service_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "key_values_types.h"

namespace key_value_database {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class Key_Value_Database_ServiceIf {
 public:
  virtual ~Key_Value_Database_ServiceIf() {}
  virtual void get(Person& _return, const int32_t key) = 0;
  virtual void put(const int32_t key, const Person& value) = 0;
  virtual void list_values(std::vector<Person> & _return) = 0;
  virtual void delete_value(const int32_t key) = 0;
};

class Key_Value_Database_ServiceIfFactory {
 public:
  typedef Key_Value_Database_ServiceIf Handler;

  virtual ~Key_Value_Database_ServiceIfFactory() {}

  virtual Key_Value_Database_ServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(Key_Value_Database_ServiceIf* /* handler */) = 0;
};

class Key_Value_Database_ServiceIfSingletonFactory : virtual public Key_Value_Database_ServiceIfFactory {
 public:
  Key_Value_Database_ServiceIfSingletonFactory(const boost::shared_ptr<Key_Value_Database_ServiceIf>& iface) : iface_(iface) {}
  virtual ~Key_Value_Database_ServiceIfSingletonFactory() {}

  virtual Key_Value_Database_ServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(Key_Value_Database_ServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<Key_Value_Database_ServiceIf> iface_;
};

class Key_Value_Database_ServiceNull : virtual public Key_Value_Database_ServiceIf {
 public:
  virtual ~Key_Value_Database_ServiceNull() {}
  void get(Person& /* _return */, const int32_t /* key */) {
    return;
  }
  void put(const int32_t /* key */, const Person& /* value */) {
    return;
  }
  void list_values(std::vector<Person> & /* _return */) {
    return;
  }
  void delete_value(const int32_t /* key */) {
    return;
  }
};

typedef struct _Key_Value_Database_Service_get_args__isset {
  _Key_Value_Database_Service_get_args__isset() : key(false) {}
  bool key :1;
} _Key_Value_Database_Service_get_args__isset;

class Key_Value_Database_Service_get_args {
 public:

  Key_Value_Database_Service_get_args(const Key_Value_Database_Service_get_args&);
  Key_Value_Database_Service_get_args& operator=(const Key_Value_Database_Service_get_args&);
  Key_Value_Database_Service_get_args() : key(0) {
  }

  virtual ~Key_Value_Database_Service_get_args() throw();
  int32_t key;

  _Key_Value_Database_Service_get_args__isset __isset;

  void __set_key(const int32_t val);

  bool operator == (const Key_Value_Database_Service_get_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const Key_Value_Database_Service_get_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Key_Value_Database_Service_get_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Key_Value_Database_Service_get_pargs {
 public:


  virtual ~Key_Value_Database_Service_get_pargs() throw();
  const int32_t* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Key_Value_Database_Service_get_result__isset {
  _Key_Value_Database_Service_get_result__isset() : success(false) {}
  bool success :1;
} _Key_Value_Database_Service_get_result__isset;

class Key_Value_Database_Service_get_result {
 public:

  Key_Value_Database_Service_get_result(const Key_Value_Database_Service_get_result&);
  Key_Value_Database_Service_get_result& operator=(const Key_Value_Database_Service_get_result&);
  Key_Value_Database_Service_get_result() {
  }

  virtual ~Key_Value_Database_Service_get_result() throw();
  Person success;

  _Key_Value_Database_Service_get_result__isset __isset;

  void __set_success(const Person& val);

  bool operator == (const Key_Value_Database_Service_get_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Key_Value_Database_Service_get_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Key_Value_Database_Service_get_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Key_Value_Database_Service_get_presult__isset {
  _Key_Value_Database_Service_get_presult__isset() : success(false) {}
  bool success :1;
} _Key_Value_Database_Service_get_presult__isset;

class Key_Value_Database_Service_get_presult {
 public:


  virtual ~Key_Value_Database_Service_get_presult() throw();
  Person* success;

  _Key_Value_Database_Service_get_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Key_Value_Database_Service_put_args__isset {
  _Key_Value_Database_Service_put_args__isset() : key(false), value(false) {}
  bool key :1;
  bool value :1;
} _Key_Value_Database_Service_put_args__isset;

class Key_Value_Database_Service_put_args {
 public:

  Key_Value_Database_Service_put_args(const Key_Value_Database_Service_put_args&);
  Key_Value_Database_Service_put_args& operator=(const Key_Value_Database_Service_put_args&);
  Key_Value_Database_Service_put_args() : key(0) {
  }

  virtual ~Key_Value_Database_Service_put_args() throw();
  int32_t key;
  Person value;

  _Key_Value_Database_Service_put_args__isset __isset;

  void __set_key(const int32_t val);

  void __set_value(const Person& val);

  bool operator == (const Key_Value_Database_Service_put_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const Key_Value_Database_Service_put_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Key_Value_Database_Service_put_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Key_Value_Database_Service_put_pargs {
 public:


  virtual ~Key_Value_Database_Service_put_pargs() throw();
  const int32_t* key;
  const Person* value;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Key_Value_Database_Service_put_result {
 public:

  Key_Value_Database_Service_put_result(const Key_Value_Database_Service_put_result&);
  Key_Value_Database_Service_put_result& operator=(const Key_Value_Database_Service_put_result&);
  Key_Value_Database_Service_put_result() {
  }

  virtual ~Key_Value_Database_Service_put_result() throw();

  bool operator == (const Key_Value_Database_Service_put_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Key_Value_Database_Service_put_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Key_Value_Database_Service_put_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Key_Value_Database_Service_put_presult {
 public:


  virtual ~Key_Value_Database_Service_put_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Key_Value_Database_Service_list_values_args {
 public:

  Key_Value_Database_Service_list_values_args(const Key_Value_Database_Service_list_values_args&);
  Key_Value_Database_Service_list_values_args& operator=(const Key_Value_Database_Service_list_values_args&);
  Key_Value_Database_Service_list_values_args() {
  }

  virtual ~Key_Value_Database_Service_list_values_args() throw();

  bool operator == (const Key_Value_Database_Service_list_values_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Key_Value_Database_Service_list_values_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Key_Value_Database_Service_list_values_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Key_Value_Database_Service_list_values_pargs {
 public:


  virtual ~Key_Value_Database_Service_list_values_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Key_Value_Database_Service_list_values_result__isset {
  _Key_Value_Database_Service_list_values_result__isset() : success(false) {}
  bool success :1;
} _Key_Value_Database_Service_list_values_result__isset;

class Key_Value_Database_Service_list_values_result {
 public:

  Key_Value_Database_Service_list_values_result(const Key_Value_Database_Service_list_values_result&);
  Key_Value_Database_Service_list_values_result& operator=(const Key_Value_Database_Service_list_values_result&);
  Key_Value_Database_Service_list_values_result() {
  }

  virtual ~Key_Value_Database_Service_list_values_result() throw();
  std::vector<Person>  success;

  _Key_Value_Database_Service_list_values_result__isset __isset;

  void __set_success(const std::vector<Person> & val);

  bool operator == (const Key_Value_Database_Service_list_values_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Key_Value_Database_Service_list_values_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Key_Value_Database_Service_list_values_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Key_Value_Database_Service_list_values_presult__isset {
  _Key_Value_Database_Service_list_values_presult__isset() : success(false) {}
  bool success :1;
} _Key_Value_Database_Service_list_values_presult__isset;

class Key_Value_Database_Service_list_values_presult {
 public:


  virtual ~Key_Value_Database_Service_list_values_presult() throw();
  std::vector<Person> * success;

  _Key_Value_Database_Service_list_values_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Key_Value_Database_Service_delete_value_args__isset {
  _Key_Value_Database_Service_delete_value_args__isset() : key(false) {}
  bool key :1;
} _Key_Value_Database_Service_delete_value_args__isset;

class Key_Value_Database_Service_delete_value_args {
 public:

  Key_Value_Database_Service_delete_value_args(const Key_Value_Database_Service_delete_value_args&);
  Key_Value_Database_Service_delete_value_args& operator=(const Key_Value_Database_Service_delete_value_args&);
  Key_Value_Database_Service_delete_value_args() : key(0) {
  }

  virtual ~Key_Value_Database_Service_delete_value_args() throw();
  int32_t key;

  _Key_Value_Database_Service_delete_value_args__isset __isset;

  void __set_key(const int32_t val);

  bool operator == (const Key_Value_Database_Service_delete_value_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const Key_Value_Database_Service_delete_value_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Key_Value_Database_Service_delete_value_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Key_Value_Database_Service_delete_value_pargs {
 public:


  virtual ~Key_Value_Database_Service_delete_value_pargs() throw();
  const int32_t* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Key_Value_Database_Service_delete_value_result {
 public:

  Key_Value_Database_Service_delete_value_result(const Key_Value_Database_Service_delete_value_result&);
  Key_Value_Database_Service_delete_value_result& operator=(const Key_Value_Database_Service_delete_value_result&);
  Key_Value_Database_Service_delete_value_result() {
  }

  virtual ~Key_Value_Database_Service_delete_value_result() throw();

  bool operator == (const Key_Value_Database_Service_delete_value_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Key_Value_Database_Service_delete_value_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Key_Value_Database_Service_delete_value_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Key_Value_Database_Service_delete_value_presult {
 public:


  virtual ~Key_Value_Database_Service_delete_value_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class Key_Value_Database_ServiceClient : virtual public Key_Value_Database_ServiceIf {
 public:
  Key_Value_Database_ServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  Key_Value_Database_ServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void get(Person& _return, const int32_t key);
  void send_get(const int32_t key);
  void recv_get(Person& _return);
  void put(const int32_t key, const Person& value);
  void send_put(const int32_t key, const Person& value);
  void recv_put();
  void list_values(std::vector<Person> & _return);
  void send_list_values();
  void recv_list_values(std::vector<Person> & _return);
  void delete_value(const int32_t key);
  void send_delete_value(const int32_t key);
  void recv_delete_value();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class Key_Value_Database_ServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<Key_Value_Database_ServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (Key_Value_Database_ServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_get(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_put(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_list_values(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_delete_value(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  Key_Value_Database_ServiceProcessor(boost::shared_ptr<Key_Value_Database_ServiceIf> iface) :
    iface_(iface) {
    processMap_["get"] = &Key_Value_Database_ServiceProcessor::process_get;
    processMap_["put"] = &Key_Value_Database_ServiceProcessor::process_put;
    processMap_["list_values"] = &Key_Value_Database_ServiceProcessor::process_list_values;
    processMap_["delete_value"] = &Key_Value_Database_ServiceProcessor::process_delete_value;
  }

  virtual ~Key_Value_Database_ServiceProcessor() {}
};

class Key_Value_Database_ServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  Key_Value_Database_ServiceProcessorFactory(const ::boost::shared_ptr< Key_Value_Database_ServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< Key_Value_Database_ServiceIfFactory > handlerFactory_;
};

class Key_Value_Database_ServiceMultiface : virtual public Key_Value_Database_ServiceIf {
 public:
  Key_Value_Database_ServiceMultiface(std::vector<boost::shared_ptr<Key_Value_Database_ServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~Key_Value_Database_ServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<Key_Value_Database_ServiceIf> > ifaces_;
  Key_Value_Database_ServiceMultiface() {}
  void add(boost::shared_ptr<Key_Value_Database_ServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void get(Person& _return, const int32_t key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->get(_return, key);
    }
    ifaces_[i]->get(_return, key);
    return;
  }

  void put(const int32_t key, const Person& value) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->put(key, value);
    }
    ifaces_[i]->put(key, value);
  }

  void list_values(std::vector<Person> & _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->list_values(_return);
    }
    ifaces_[i]->list_values(_return);
    return;
  }

  void delete_value(const int32_t key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->delete_value(key);
    }
    ifaces_[i]->delete_value(key);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class Key_Value_Database_ServiceConcurrentClient : virtual public Key_Value_Database_ServiceIf {
 public:
  Key_Value_Database_ServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  Key_Value_Database_ServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void get(Person& _return, const int32_t key);
  int32_t send_get(const int32_t key);
  void recv_get(Person& _return, const int32_t seqid);
  void put(const int32_t key, const Person& value);
  int32_t send_put(const int32_t key, const Person& value);
  void recv_put(const int32_t seqid);
  void list_values(std::vector<Person> & _return);
  int32_t send_list_values();
  void recv_list_values(std::vector<Person> & _return, const int32_t seqid);
  void delete_value(const int32_t key);
  int32_t send_delete_value(const int32_t key);
  void recv_delete_value(const int32_t seqid);
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

} // namespace

#endif
