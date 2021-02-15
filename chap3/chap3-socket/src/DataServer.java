import java.net.*;
import java.io.*;

public class DataServer {
	public static void main(String[] args) throws Exception{
		
		ServerSocket server = new ServerSocket(6013);
	
		while(true)
		{
			Socket client = server.accept();
			PrintWriter pout = new PrintWriter(client.getOutputStream(),true);

			pout.println(new java.util.Date().toString());
			client.close();
		}

	}

}
