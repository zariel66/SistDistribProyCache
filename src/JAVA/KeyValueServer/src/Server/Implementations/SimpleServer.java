/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server.Implementations;

import org.apache.thrift.server.TServer;
import org.apache.thrift.server.TSimpleServer;

/**
 *
 * @author ricardo
 */
public class SimpleServer extends Server{
    
    public SimpleServer(int port) {
        super(port);
        server = new TSimpleServer(new TServer.Args(serverTransport).processor(processor));
    }

    @Override
    public void run() {
        System.out.println("Levantando un servidor simple por "+port+"...");
        server.serve();
    }

    
}
