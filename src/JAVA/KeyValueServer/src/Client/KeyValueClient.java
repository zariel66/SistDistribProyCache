/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Client;

import Client.Implementations.Client;
import apacheThrift.City;
import apacheThrift.Person;
import java.util.Scanner;
import org.apache.thrift.transport.TTransportException;

/**
 *
 * @author ricardo
 */
public class KeyValueClient {

    private static int port;
    private static String host;

    public static void main(String[] args) {
        Client client;

        if (args.length != 2) {
            System.out.println("Error al obtener los parametros");
            return;
        }

        try {
            host = args[0];
            port = Integer.parseInt(args[1]);
        } catch (NumberFormatException ex) {
            System.out.println("Error al leer los parametros de entrada");
            return;
        }

        try {
            System.out.println("Estableciendo sesion...");
            client = new Client(host, port);
            client.connect();
            manage_Request_commands(client);
            System.out.println("Cerrando sesion...");
            client.disconnect();
        } catch (TTransportException exception) {
            System.out.println("Error al establecer la coneccion");
        }
    }

    public static void manage_Request_commands(Client client) {

        boolean exitFlag = false;
        String input;
        String input_split[];
        String command = null;
        Scanner input_scanner = new Scanner(System.in);

        int key;

        while (!exitFlag) {

            System.out.print(">> ");
            input = input_scanner.nextLine();

            try {
                input_split = input.split(" ");
                if (input_split.length == 0) {
                    continue;
                }
                command = input_split[0];

                if (command.equals("get") && !input_split[1].equals("")) {
                    key = Integer.valueOf(input_split[1]);

                    System.out.println(client.get(key));
                } else if (command.equals("put") && !input_split[1].equals("")) {
                    key = Integer.valueOf(input_split[1]);
                    Person p = newValue();
                    client.put(key, p);
                    System.out.println("");
                } else if (command.equals("list")) {
                    client.list().stream().forEach((p) -> {
                        System.out.println(p);
                    });

                } else if (command.equals("delete") && !input_split[1].equals("")) {
                    key = Integer.valueOf(input_split[1]);
                    client.delete(key);
                } else if (command.equals("close")) {
                    exitFlag = true;
                } else {
                    System.out.println("Error comando invalido");
                }

            } catch (IndexOutOfBoundsException exception) {
                System.out.println("Error parametros incorrectos para el comando " + command);
            } catch (NumberFormatException exception) {
                System.out.println("Error la clave debe de ser un entero ");
            }

        }
    }

    public static Person newValue() {
        String name, apellido;
        Integer edad = null, seleccion = null;
        City ciudad = null;
        Scanner input_scanner = new Scanner(System.in);
        System.out.print("Ingrese el nombre: ");
        name = input_scanner.nextLine();
        System.out.print("Ingrese el apellido: ");
        apellido = input_scanner.nextLine();
        while (edad == null) {
            try {
                System.out.print("Ingrese la edad: ");
                edad = Integer.parseInt(input_scanner.nextLine());
            } catch (NumberFormatException ex) {
                System.out.println("Error ingrese un numero entero ");
            }
        }
        while (seleccion == null) {
            try {
                System.out.println("1."+City.QUITO+"\n"+
                                   "2."+City.GUAYAQUIL+"\n"+
                                   "3."+City.AMBATO+"\n"+
                                   "4."+City.CUENCA);
                System.out.print("Ingrese el numero de la ciudad: ");
                seleccion = Integer.parseInt(input_scanner.nextLine());
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
                if(ciudad==null){
                    System.out.println("Error ingrese el numero correspondiente de la ciudad ");
                    seleccion = null;
                }
            } catch (NumberFormatException ex) {
                System.out.println("Error ingrese el numero correspondiente de la ciudad ");
            }
        }
        return new Person(name, apellido, edad, ciudad);
    }

    public static void test() {
        Runnable simple = new Runnable() {
            public void run() {
                Client client = new Client(host, port);
                client.get(3);
                client.disconnect();
            }
        };
        Runnable simple2 = new Runnable() {
            public void run() {
                Client client = new Client(host, port);
                client.get(2);
                client.disconnect();
            }
        };
        Runnable simple3 = new Runnable() {
            public void run() {
                Client client = new Client(host, port);
                Person p = new Person("Carlos", "Armando", 40, City.QUITO);
                client.get(3);
                client.put(3, p);
                client.disconnect();
            }
        };
        Runnable simple4 = new Runnable() {
            public void run() {
                Client client = new Client(host, port);
                client.get(4);
                client.list();
                client.disconnect();
            }
        };
        Runnable simple5 = new Runnable() {
            public void run() {
                Client client = new Client(host, port);
                client.get(5);
                client.disconnect();
            }
        };

        new Thread(simple).start();
        new Thread(simple2).start();
        new Thread(simple3).start();
        new Thread(simple4).start();
        new Thread(simple5).start();
    }

}
