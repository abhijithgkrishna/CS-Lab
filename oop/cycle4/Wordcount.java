import java.io.*;

public class Wordcount{
	public static void main(String[] args) {
		int line = 0, word = 0, ch = 0;
		String linestr;

		try{
			FileReader file = new FileReader("file2.txt");
			BufferedReader reader = new BufferedReader(file);
			while((linestr = reader.readLine()) != null){
				line++;
				String words[] = linestr.split(" ");
				word += words.length;
				for (String w : words ) {
					ch += w.length();
				}
			}
			ch += word-1;
			System.out.println("Lines = " + line);
			System.out.println("Words = " + word);
			System.out.println("Characters = " + ch);
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