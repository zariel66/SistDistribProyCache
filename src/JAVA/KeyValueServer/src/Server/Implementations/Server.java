/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server.Implementations;

import Handler.KeyValueHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import key_value_database.Key_Value_Database_Service;
import org.apache.thrift.server.TServer;
import org.apache.thrift.transport.TServerSocket;
import org.apache.thrift.transport.TServerTransport;
import org.apache.thrift.transport.TTransportException;

/**
 *
 * @author ricardo
 */
public abstract class Server implements Runnable{
    
    /* Puerto por el cual escucha el proceso*/
    protected int port;
    protected TServerTransport serverTransport;
    /* Depende del tipo de servidor que se seleccione (TSimpleServer,TThreadPoolServer)*/
    protected TServer server;
    /* Manejador de las interfaces */
    private KeyValueHandler handler;
    /* Encapsula la funcionalidad de poder leer y escribir flujo de datos*/
    protected Key_Value_Database_Service.Processor processor;
    
    public Server(int port){
        try {
            this.port = port;
            serverTransport = new TServerSocket(port);
            handler = new KeyValueHandler();
            processor = new Key_Value_Database_Service.Processor(handler);
        
        } catch (TTransportException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    @Override
    public abstract void run();
    
}
