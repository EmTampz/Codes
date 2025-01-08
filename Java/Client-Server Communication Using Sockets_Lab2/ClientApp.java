//Client Application
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;
public class ClientApp extends Frame implements ActionListener,Runnable
{
	Socket s;
	BufferedReader br;
	BufferedWriter bw;
	TextField text;
	Button button1,button2;
	List list;
	public static void main(String arg[])
	{
		new ClientApp("Client Applicaton:");
		
	}
	public void run()
	{
		try{s.setSoTimeout(1);}catch(Exception e){}
		while (true)
		{
			try{list.addItem(br.readLine());
			}catch (Exception h){}
		}
	}
	
	public ClientApp(String m)
	{
		super(m);
		setSize(200,300);
		setLocation(300,0);

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
			s = new Socket("127.0.0.1",8000);
			br = new BufferedReader(new InputStreamReader(
					s.getInputStream()));
			bw = new BufferedWriter(new OutputStreamWriter(
					s.getOutputStream()));
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
