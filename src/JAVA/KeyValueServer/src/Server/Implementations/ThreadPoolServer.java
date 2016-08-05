/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server.Implementations;

import org.apache.thrift.server.TServer;
import org.apache.thrift.server.TSimpleServer;
import org.apache.thrift.server.TThreadPoolServer;

/**
 *
 * @author ricardo
 */
public class ThreadPoolServer extends Server{

    public ThreadPoolServer(int port) {
        super(port);
        server = new TThreadPoolServer(new TThreadPoolServer.Args(serverTransport).processor(processor));
    }

    @Override
    public void run() {
         System.out.println("Levantando un servidor multihilo por "+port+"...");
         server.serve();
    }
    
}
