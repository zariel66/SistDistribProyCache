#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "Key_Value_Database_Service.h"
using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace key_value_database;

void manage_Request_commands(Key_Value_Database_ServiceClient client);

int main(int argc, char **argv) {
  if(argc != 3)
  {
    printf ("Número incorrecto de parametros\n");
    exit(EXIT_FAILURE);
  }
  char *host = argv[1];
  char *pport = argv[2];
  int port = atoi(pport);
  if(port==0){
    printf ("Puerto no valido\n");
    exit(EXIT_FAILURE);
  }
  boost::shared_ptr<TSocket> socket(new TSocket(host, pport));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  Key_Value_Database_ServiceClient client(protocol);
  transport->open();
  manage_Request_commands(client);
  transport->close();
  return 0;
}


void manage_Request_commands(Key_Value_Database_ServiceClient client) {
  bool exitFLag = false;
  while(!exitFLag)
  {
    printf(">> ");
    string cmd;
    std::string delimiter = " ";
    getline( std::cin, cmd );
    int pos = cmd.find(delimiter);
    std::string token = cmd.substr(0, pos);
    if(token.compare("close") == 0){
      exitFLag = true;
      printf("Cerrando Conexión\n");
    }
    else if(token.compare("list") == 0){
      std::vector<Person> output;
      client.list_values(output);
      for(int i=0; i<output.size(); ++i){
        std::cout << output[i] << '\n';
      }
    }
    else if(token.compare("put") == 0){
      string nombre;
      string apellido;
      string e;
      string k;
      string c;
      City::type ciudad;
      cout << "Ingrese la clave" << "\n";
      getline( std::cin, k );
      int key = atoi(k.c_str());
      cout << "Ingrese el nombre" << "\n";
      getline( std::cin, nombre );
      cout << "Ingrese el apellido" << "\n";
      getline( std::cin, apellido );
      cout << "Ingrese la edad" << "\n";
      getline( std::cin, e );
      int edad = atoi(e.c_str());
      cout << "1.QUITO\n" << "2.GUAYAQUIL\n" << "3.AMBATO\n" << "4.CUENCA\nIngrese el numero de la ciudad\n";
      getline( std::cin, c );
      int c2 = atoi(c.c_str());
      switch(c2){
        case 1:{ciudad = City::QUITO;}break;
        case 2:{ciudad = City::GUAYAQUIL;}break;
        case 3:{ciudad = City::AMBATO;}break;
        case 4:{ciudad = City::CUENCA;}break;
      }
      try{
        Person per;
        per.name = nombre;
        per.lastName = apellido;
        per.age = edad;
        per.city = ciudad;
        client.put(key,per);
        cout << "Ingreso exitoso" << "\n";
      }
      catch(apache::thrift::TApplicationException e){
        cout << "Error en el ingreso de datos. Intente de nuevo" << "\n";
      }
      
    }
    else if(token.compare("delete") == 0){
      string k = cmd.substr(pos + delimiter.length());
      int key = atoi(k.c_str());
      try{
        client.delete_value(key);
        cout << "La persona ha sido eliminada" << "\n";    
      }
      catch(apache::thrift::TApplicationException e){
        cout << "No existe tal Persona" << "\n"; 
      }  
    }
    else if(token.compare("get") == 0){
      string k = cmd.substr(pos + delimiter.length());
      int key = atoi(k.c_str());
      Person p;
      try{
        client.get(p,key);
        cout << p << "\n";    
      }
      catch(apache::thrift::TApplicationException e){
        cout << "No existe tal Persona" << "\n"; 
      }  
    }

  }
  
}

