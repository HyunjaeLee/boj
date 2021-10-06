import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	private static ArrayList<Integer> solveAlphabetDistance(String s1, String s2) {
		ArrayList<Integer> answer = new ArrayList<Integer>();
		int n = s1.length();
		for (int i = 0; i < n; i++) {
			int x = (26 + (s2.charAt(i) & 0x1F) - (s1.charAt(i) & 0x1F)) % 26;
			answer.add(x);
		}
		return answer;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int numCases = sc.nextInt();
		for (int i = 0; i < numCases; i++) {
			String s1 = sc.next();
			String s2 = sc.next();
			ArrayList<Integer> answer = solveAlphabetDistance(s1, s2);
			System.out.print("Distances: ");
			for(Integer d : answer) {
				System.out.print(d+" ");
			}
			System.out.println();
		}
		sc.close();
	}
}
