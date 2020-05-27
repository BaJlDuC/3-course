package com.lexer;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

import static com.lexer.LexicalAnalyzer.error;

public class Main {
    public static void main(String[] args) {
        if (args.length > 0) {
            try {
                File inputFile = new File(args[0]);
                Scanner scanner = new Scanner(inputFile);
                StringBuilder source = new StringBuilder(" ");
                while (scanner.hasNext()) {
                    source.append(scanner.nextLine()).append("\n");
                }
                LexicalAnalyzer lexer = new LexicalAnalyzer(source.toString());
                lexer.printTokens();
            } catch(FileNotFoundException e) {
                error(-1, -1, e.getMessage());
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            error(-1, -1, "Incorrect input. Enter: java -jar lexicalAnalyzerJar.jar inputFile.txt");
        }
    }
}
