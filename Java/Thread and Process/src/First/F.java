package First;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

/**
 * Created by Еф on 18.12.2016.
 */
public class F {
    static boolean f(int x)
    {
        return x>0;
    }
    public static void main(String[] args) throws Throwable {

        Socket s = new Socket("localhost",8080);
        BufferedReader bf=new BufferedReader(new InputStreamReader(s.getInputStream()));
        String line;
        int x=0;
        while((line=bf.readLine())!=null)
        {
            x=Integer.parseInt(line);
        }
        boolean res=f(x);
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
        bw.write(""+res);
    }
}
