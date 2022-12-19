import java.io.*;

public class Readwrite{
	public static void main(String[] args) {
		String content, line;
		content = "";
		try{
			FileReader file  = new FileReader("file4.txt");
			BufferedReader reader = new BufferedReader(file);
			FileWriter writer = new FileWriter("filecopy.txt");
			while((line = reader.readLine())!=null){
				content += line + "\n";
			}
			writer.write(content);
			reader.close();
			writer.close();
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