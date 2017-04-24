/**
 * Created by Еф on 18.12.2016.
 */
import com.sun.corba.se.spi.activation.Server;

import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class Main {

    class ThreadExecute extends Thread
    {

        String command;
        ServerSocket server;
        public ThreadExecute(String com,ServerSocket s)
        {
            server=s;
            command=com;
        }
        public void run()
        {
            try{

                Process p=Runtime.getRuntime().exec(command);

            }
            catch(Exception e)
            {

            }
        }
    }
    class ThreadCompile extends Thread
    {
        String command;
        public ThreadCompile(String com)
        {
            command=com;
        }
        public void run()
        {
            try{

                Process p=Runtime.getRuntime().exec(command);
            }
            catch(Exception e)
            {

            }
        }
    }
    public static void main(String[] args) {

            ThreadCompile tc1=new ThreadCompile("javac .../First/F");
        ThreadCompile tc2=new ThreadCompile("javac .../Second/G");
        tc1.start();
        tc2.start();
        tc1.join();
        tc2.join();
        //...
        ServerSocket server=new ServerSocket(8080,0, InetAddress.getByName("localhost"));

        ThreadExecute te1=new ThreadExecute("java -cp .../src First.F",server);
        ThreadExecute te2=new ThreadExecute("java -cp .../src Second.G",server);
        while(true)
        {

            Socket s=server.accept();

        }



    }
}
