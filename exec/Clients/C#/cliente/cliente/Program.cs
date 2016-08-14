using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Thrift;
using Thrift.Protocol;
using Thrift.Server;
using Thrift.Transport;

namespace cliente
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("Estableciendo sesion...");
                TTransport transport = new TSocket("localhost", 9090);
                TProtocol protocol = new TBinaryProtocol(transport);
                Key_Value_Database_Service.Client client = new Key_Value_Database_Service.Client(protocol);
                transport.Open();
                
                Console.WriteLine("cliente corriendo");
                //------------------------------------------------------------
                bool exitFlag = false;
                String input;
                //String input_split[];
                String command = null;
                Char delimiter = ' ';
                int key;
        
                while(!exitFlag) {

                    Console.WriteLine(">> ");
                    input=Console.ReadLine();
                    //input = input_scanner.nextLine();
                    //Console.WriteLine(input);
                    String[] input_split = input.Split(delimiter);
                    if (input_split.Length == 0) {
                      continue;
                    }
                    command = input_split[0];

                    if (command.Equals("get") && !input_split[1].Equals("")) {
                        key = Int32.Parse(input_split[1]);

                        Console.WriteLine(client.get(key));
                    } else if (command.Equals("put") && !input_split[1].Equals("")) {
                        key = Int32.Parse(input_split[1]);
                        String name, apellido;
                        int edad = 0, seleccion = 0;
                        City ciudad = new City();
                        Console.WriteLine("Ingrese el nombre: ");
                        name = Console.ReadLine();
                        Console.WriteLine("Ingrese el apellido: ");
                        apellido = Console.ReadLine();
                        while (edad == 0) {
                            try {
                                Console.WriteLine("Ingrese la edad: ");
                                edad = Int32.Parse(Console.ReadLine());
                            } catch (Exception ex) {
                                Console.WriteLine("Error ingrese un numero entero ");
                            }
                        }
                        while (seleccion == 0) {
                            try {
                                Console.WriteLine("1."+City.QUITO+"\n"+
                                                   "2."+City.GUAYAQUIL+"\n"+
                                                   "3."+City.AMBATO+"\n"+
                                                   "4."+City.CUENCA);
                                Console.WriteLine("Ingrese el numero de la ciudad: ");
                                seleccion = Int32.Parse(Console.ReadLine());
                                switch (seleccion) {
                                    case 1:
                                        ciudad = City.QUITO;
                                        break;
                                    case 2:
                                        ciudad = City.GUAYAQUIL;
                                        break;
                                    case 3:
                                        ciudad = City.AMBATO;
                                        break;
                                    case 4:
                                        ciudad = City.CUENCA;
                                        break;
                                }
                                if(ciudad == null){
                                    Console.WriteLine("Error ingrese el numero correspondiente de la ciudad ");
                                    seleccion = 0;
                                }
                            } catch (Exception ex) {
                                Console.WriteLine("Error ingrese el numero correspondiente de la ciudad ");
                            }
                        }
                        //-----------------------------
                        Person p = new Person();
                        p.Name=name;
                        p.LastName=apellido;
                        p.Age=edad;
                        p.City = ciudad;
                        client.put(key, p);
                    }else if (command.Equals("list")) {
                        //client.list().stream().forEach((p) -> {
                            Console.WriteLine("no implementado");
                        //});

                    } else if (command.Equals("delete") && !input_split[1].Equals("")) {
                        key = Int32.Parse(input_split[1]);
                        //client.delete(key);
                    } else if (command.Equals("close")) {
                        exitFlag = true;
                    } else {
                        Console.WriteLine("Error comando invalido");
                    }
                    
                  }
                System.Threading.Thread.Sleep(5000);
                transport.Close();
                
            }
            catch (TApplicationException x)
            {
                Console.WriteLine(x.StackTrace);
            }
        }
    }

    
    
}
