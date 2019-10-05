package com.example.typesTable;

public class TypesTable {
    public static void main(String[] args) {
        System.out.printf("Type");
        System.out.printf("%20s", "Min");
        System.out.printf("%32s", "Max");//+6
        System.out.printf("%30s","Size\n");//+14

        System.out.printf("Long\t");
        System.out.printf("%24s", Long.MIN_VALUE);
        System.out.printf("%32s", Long.MAX_VALUE);
        System.out.printf("%20s", Long.BYTES + "\n");

        System.out.printf("Integer\t");
        System.out.printf("%15s", Integer.MIN_VALUE);
        System.out.printf("%32s", Integer.MAX_VALUE);
        System.out.printf("%29s", Integer.BYTES + "\n");

        System.out.printf("Short\t");
        System.out.printf("%10s", Short.MIN_VALUE);
        System.out.printf("%32s", Short.MAX_VALUE);
        System.out.printf("%34s", Short.BYTES + "\n");

        System.out.printf("Byte\t");
        System.out.printf("%8s", Byte.MIN_VALUE);
        System.out.printf("%32s", Byte.MAX_VALUE);
        System.out.printf("%36s", Byte.BYTES + "\n");

        System.out.printf("Double\t");
        System.out.printf("%12s", Double.MIN_VALUE);
        System.out.printf("%47s", Double.MAX_VALUE);
        System.out.printf("%17s", Double.BYTES + "\n");

        System.out.printf("Float\t");
        System.out.printf("%11s", Float.MIN_VALUE);
        System.out.printf("%38s", Float.MAX_VALUE);
        System.out.printf("%27s", Float.BYTES + "\n");

        System.out.printf("Char\t");
        System.out.printf("%5s", Character.MIN_CODE_POINT);
        System.out.printf("%39s", Character.MAX_CODE_POINT);
        System.out.printf("%32s", Character.BYTES + "\n");
    }
}
