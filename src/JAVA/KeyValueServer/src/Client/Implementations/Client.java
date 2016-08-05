/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Client.Implementations;

import apacheThrift.Person;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import key_value_database.Key_Value_Database_Service;
import org.apache.thrift.TException;
import org.apache.thrift.protocol.TBinaryProtocol;
import org.apache.thrift.protocol.TProtocol;
import org.apache.thrift.transport.TSocket;
import org.apache.thrift.transport.TTransport;
import org.apache.thrift.transport.TTransportException;

/**
 *
 * @author ricardo
 */
public class Client {

    private TTransport transport;
    private Key_Value_Database_Service.Client client;
    private int port;
    private String host;

    public Client(String host, int port) {
        this.host = host;
        this.port = port;
    }

    public void connect() throws TTransportException {
        transport = new TSocket(host, port);
        transport.open();

        TProtocol protocol = new TBinaryProtocol(transport);
        client = new Key_Value_Database_Service.Client(protocol);
    }

    public Person get(int key) {
        Person p = null;
        try {
            p = client.get(key);
        } catch (TException ex) {
        }
        //System.out.println("JAVA GET " + key + " " + p);
        return p;
    }

    public void put(int key, Person value) {
        try {
            client.put(key, value);
        } catch (TException ex) {
            //Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        }
        //System.out.println("JAVA PUT " + key + " " + value);
    }

    public ArrayList<Person> list() {
        ArrayList<Person> list = null;
        try {
            list = (ArrayList<Person>) client.list_values();
        } catch (TException ex) {
            //Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        }
        //System.out.println("JAVA LIST " + list);
        return list;
    }
    
    public void delete(int key) {
        try {
            client.delete_value(key);
        } catch (TException ex) {
            //Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        }
        //System.out.println("JAVA PUT " + key + " " + value);
    }
    public void disconnect() {
        transport.close();
    }

}
