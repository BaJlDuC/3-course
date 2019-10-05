package com.example.PasswordGenerator;
import java.util.Scanner;
import java.util.Random;

public class PasswordGenerator {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        if (!input.hasNextLine()) {
            System.out.println("PasswordGenerator <Length> <Alphabet>");
            System.exit(0);
        }

        String inputString = input.nextLine();
        String[] inputArray = inputString.split(" ");
        if (inputArray.length != 2) {
            System.out.println("PasswordGenerator <Length> <Alphabet>");
            System.exit(0);
        }

        try {
            int passwordLength = Integer.parseInt(inputArray[0]);
            if (passwordLength <= 0) {
                System.out.println("PasswordGenerator <Length> <Alphabet>");
                System.exit(0);
            }
        } catch (NumberFormatException e){
            System.out.println("PasswordGenerator <Length> <Alphabet>");
            System.exit(0);
        }

        int length = Integer.parseInt(inputArray[0]);
        String alphabet = inputArray[1];
        //char[] alphabetArray = alphabet.toCharArray();
        char[] resultPassword = new char[length];
        Random random = new Random();

        for (int i = 0; i < resultPassword.length; i++) {
            resultPassword[i] = alphabet.charAt(random.nextInt(alphabet.length()));
        }

        for (int i = 0; i < resultPassword.length; i++) {
            System.out.print(resultPassword[i]);
        }
    }
}
