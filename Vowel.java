import java.util.Scanner;

public class Vowel{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String word;

        System.out.print("Enter word: ");
        word = scan.nextLine();

        System.out.println("Word reversed:");

        int length = word.length();
        int index = length - 1;
        int vowelCount = 0;
        int consonantCount = 0;

        while(index >= 0){
            char ch = word.charAt(index);

            if(isVowel(ch)){
                System.out.println(ch + " - Vowel");
                vowelCount++;
            }else if(Character.isLetter(ch)){
                System.out.println(ch + " - Consonant");
                consonantCount++;
            }
            index--;
        }
        
        System.out.println("The total count of vowel is: " + vowelCount);
        System.out.println("The total count of consonant is: " + consonantCount);

        scan.close();
    }

    public static boolean isVowel(char ch){
         ch = Character.toLowerCase(ch);

         return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
}