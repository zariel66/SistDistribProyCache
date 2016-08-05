/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server;

import Handler.KeyValueHandler;
import Server.Implementations.ThreadPoolServer;
import Server.Implementations.SimpleServer;
import Server.Implementations.Server;

/**
 *
 * @author ricardo
 */
public class KeyValueServer {
    /* Puerto de escucha */
    private static int port = 9090;
    
    public static void main(String[] args) {
        Server server;
        try{
            port = Integer.parseInt(args[0]);
            if(args[1].equals("simple")){
                server = new SimpleServer(port);
            }else{
                server = new ThreadPoolServer(port);
            }
            new Thread(server).start();
        }catch(ArrayIndexOutOfBoundsException ex){
            server = new ThreadPoolServer(port);
            new Thread(server).start();
        }
        
    }

}
