package com.example.CaesarCipher;
import java.util.Scanner;

public class CaesarCipher {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        if (!input.hasNextLine()) {
            System.out.println("CaesarCipher <Mode> <Key> <Text>");
            System.exit(0);
        }
        String inputString = input.nextLine();
        if (inputString.isEmpty()) {
            System.out.println("CaesarCipher <Mode> <Key> <Text>");
            System.exit(0);
        }

        String[] inputArray = inputString.split(" ");
        if (inputArray.length != 3) {
            System.out.println("CaesarCipher <Mode> <Key> <Text>");
            System.exit(0);
        }

        String mode = inputArray[0];
        if ((!mode.equals("-e")) && (!mode.equals("-d"))) {
            System.out.println("CaesarCipher <Mode> <Key> <Text>");
            System.exit(0);
        }

        try {
            int key = Integer.parseInt(inputArray[1]);
        } catch (NumberFormatException e) {
            System.out.println("CaesarCipher <Mode> <Key> <Text>");
            System.exit(0);
        }

        String text = inputArray[2];
        int cipherKey = Integer.parseInt(inputArray[1]);
        cipherKey %= 26;
        char[] textArray = text.toCharArray();
        for (int i = 0; i < textArray.length; i++) {
            if (((textArray[i] >= 'a') && (textArray[i] <= 'z')) || ((textArray[i] >= 'A') && (textArray[i] <= 'Z'))) {
            }
            else {
                System.out.println("CaesarCipher <Mode> <Key> <Text>");
                System.exit(0);
            }
        }

        char element;
        char[] result = new char[textArray.length];

        for (int i = 0; i < textArray.length; i++) {
            element = textArray[i];
            if ((element >= 'a') && (element <= 'z')) {
                if (mode.equals("-e")) {
                    element += cipherKey;
                    while (element > 'z') {
                        int indexElementEncoding = (int) element - (int) 'z';
                        element = 'a';
                        element += (indexElementEncoding - 1);
                    }
                    result[i] = element;
                } else {
                    element -= cipherKey;
                    while (element < 'a') {
                        int indexElementDecoding = (int) 'a' - (int) element;
                        element = 'z';
                        element -= (indexElementDecoding - 1);
                    }
                    result[i] = element;
                }
            } else {
                if (mode.equals("-e")) {
                    element += cipherKey;
                    while (element > 'Z') {
                        int indexElementEncoding = (int) element - (int) 'Z';
                        element = 'A';
                        element += (indexElementEncoding - 1);
                    }
                    result[i] = element;
                } else {
                    element -= cipherKey;
                    while (element < 'A') {
                        int indexElementDecoding = (int) 'A' - (int) element;
                        element = 'Z';
                        element -= (indexElementDecoding - 1);
                    }
                    result[i] = element;
                }
            }
        }

        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i]);
        }
    }
}
