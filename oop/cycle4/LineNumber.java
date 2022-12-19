import java.io.*;

public class LineNumber{
	public static void main(String[] args) {
		int i = 1;
		String linestr;
		try{
			FileReader file = new FileReader("file2.txt");
			BufferedReader reader = new BufferedReader(file);
			while((linestr = reader.readLine()) != null){
				System.out.print((i++) + " " + linestr + "\n" );
			}
			reader.close();
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