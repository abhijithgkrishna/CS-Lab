import java.util.*;

public class Tokenizer {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String array;
		Integer sum = 0, n, i = 0;
		System.out.println("Input array");
		array = sc.nextLine();
		System.out.println(array);
		StringTokenizer st = new StringTokenizer(array);
		while (st.hasMoreTokens()) {
			int v = Integer.parseInt(st.nextToken());
			System.out.print(v + " ");
			sum += v;
		}
		System.out.println("sum is " + sum);
	}
}