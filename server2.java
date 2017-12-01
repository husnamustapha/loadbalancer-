import java.io.*;
import java.net.*;

public class server2{

public static void main(String []args)throws IOException{
ServerSocket s2=new ServerSocket(2346);
while(true){
Socket connectionsocket=s2.accept();
BufferedReader messagefromloadbalancer=new BufferedReader(new InputStreamReader(connectionsocket.getInputStream()));
String sentence=messagefromloadbalancer.readLine();
System.out.println("received from Client:"+sentence);
}
}
}

