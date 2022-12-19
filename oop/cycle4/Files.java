import java.io.*;
import java.util.Scanner;

public class Files {
	public static void main(String[] args) {
		int i;
		String str;
		Scanner sc  = new Scanner(System.in);
		System.out.println("Enter line of text : ");
		str = sc.nextLine();
		try{
			FileWriter Writer = new FileWriter("file.txt");
			Writer.write(str);
			Writer.close();
			System.out.println("Written");
		}		
		catch(IOException e){
			System.out.println("Error");
			e.printStackTrace();
		}
		try{
			FileReader Reader = new FileReader("file.txt");
			while((i = Reader.read()) != -1){
				System.out.print((char)i);
			}
			Reader.close();
		}
		catch(FileNotFoundException e)
		{
			System.out.println("Error");
		}
		catch(IOException d){
			System.out.println("error2");
		}
	}
}