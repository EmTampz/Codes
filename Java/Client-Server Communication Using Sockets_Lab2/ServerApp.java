//Server Application
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;
public class ServerApp extends Frame implements ActionListener,Runnable 
{
	ServerSocket s;
	Socket s1;
	BufferedReader br;
	BufferedWriter bw;
	TextField text;
	Button button1,button2;
	List list;
	public void run()
	{
		try{s1.setSoTimeout(1);}catch(Exception e){}
		while (true)
		{
			try{
			list.addItem(br.readLine());
			}catch (Exception h){}
		}
	}
	public static void main(String arg[])
	{
		new ServerApp("Server Applicaton:");
		
	}
	
	public ServerApp(String m)
	{
		super(m);
		setSize(200,300);
		setLocation(0,0);
		this.setLayout(new BorderLayout());
		button1 = new Button("Send");
		button2 = new Button("Exit");
		button1.addActionListener(this);
		button2.addActionListener(this);
		list = new List();
		text = new TextField();
		add(list,"Center");
		add(button1,"West");
		add(button2,"East");		
		add(text,"South");
		setVisible(true);
		try{
			s = new ServerSocket(8000);
			
			s1=s.accept();
			br = new BufferedReader(new InputStreamReader(
					s1.getInputStream()));
			bw = new BufferedWriter(new OutputStreamWriter(
					s1.getOutputStream()));
			bw.write("Hello");bw.newLine();bw.flush();
			 Thread th;
			 th = new Thread(this);
			 th.start();
			 
			
		}catch(Exception e){}
	}
	public void actionPerformed ( ActionEvent e)
	{
		 if (e.getSource().equals(button2))
			 System.exit(0);
		 else{try{
			 bw.write(text.getText());
			 bw.newLine();bw.flush();
			 }catch(Exception m){}
		 }
				  
	}
	
}
