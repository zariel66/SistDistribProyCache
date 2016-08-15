/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef key_values_TYPES_H
#define key_values_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace key_value_database {

struct City {
  enum type {
    GUAYAQUIL = 1,
    QUITO = 2,
    CUENCA = 3,
    AMBATO = 4
  };
};

extern const std::map<int, const char*> _City_VALUES_TO_NAMES;

class Person;

typedef struct _Person__isset {
  _Person__isset() : name(false), lastName(false), age(false), city(false) {}
  bool name :1;
  bool lastName :1;
  bool age :1;
  bool city :1;
} _Person__isset;

class Person {
 public:

  Person(const Person&);
  Person& operator=(const Person&);
  Person() : name(), lastName(), age(0), city((City::type)0) {
  }

  virtual ~Person() throw();
  std::string name;
  std::string lastName;
  int32_t age;
  City::type city;

  _Person__isset __isset;

  void __set_name(const std::string& val);

  void __set_lastName(const std::string& val);

  void __set_age(const int32_t val);

  void __set_city(const City::type val);

  bool operator == (const Person & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(lastName == rhs.lastName))
      return false;
    if (!(age == rhs.age))
      return false;
    if (!(city == rhs.city))
      return false;
    return true;
  }
  bool operator != (const Person &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Person & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Person &a, Person &b);

inline std::ostream& operator<<(std::ostream& out, const Person& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
