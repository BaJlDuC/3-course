package com.example.GetNetAddress;
import java.util.Scanner;

public class GetNetAddress {
    public static void main(String[] args) {
        //lets do this
        Scanner in = new Scanner(System.in);
        if (in.hasNextLine()) {
            String ipWithMask = in.nextLine();

            if (ipWithMask.indexOf(" ") == -1) {
                System.out.println("GetNetAddress <IP address> <Subnet mask>");
                System.exit(0);
            }
            String ip = ipWithMask.substring(0, ipWithMask.indexOf(" "));
            String subnetMask = ipWithMask.substring(ipWithMask.indexOf(" ") + 1);
            if ((subnetMask.charAt(subnetMask.length() - 1) == '.')) {
                System.out.println("Wrong mask");
                System.exit(0);
            }
            if ((ip.charAt(ip.length() - 1) == '.')) {
                System.out.println("Wrong ip address");
                System.exit(0);
            }


            String ipUpd = ip.replace('.', '-');
            String maskUpd = subnetMask.replace('.', '-');

            if (ip.isEmpty()) {
                System.out.println("GetNetAddress <IP address> <Subnet mask>");
                System.exit(0);
            }
            if (subnetMask.isEmpty()) {
                System.out.println("GetNetAddress <IP address> <Subnet mask>");
                System.exit(0);
            }
            String[] ipArray = ipUpd.split("-");
            String[] maskArray = maskUpd.split("-");
            int[] ipArrayInt = new int[ipArray.length];
            int[] maskArrayInt = new int[maskArray.length];

            for (int i = 0; i < ipArray.length; i++) {
                try {
                    ipArrayInt[i] = Integer.parseInt(ipArray[i]);
                } catch (NumberFormatException e) {
                    System.out.println("Wrong ip address");
                    System.exit(0);
                }
                if (ipArrayInt[i] > 255) {
                    System.out.println("Wrong ip address");
                    System.exit(0);
                }
            }
            if (ipArrayInt.length != 4) {
                System.out.println("Wrong ip address");
                System.exit(0);
            }

            for (int i = 0; i < maskArray.length; i++) {
                try {
                    maskArrayInt[i] = Integer.parseInt(maskArray[i]);
                } catch (NumberFormatException e) {
                    System.out.println("Wrong mask");
                    System.exit(0);
                }
                if (maskArrayInt[i] > 255) {
                    System.out.println("Wrong mask");
                    System.exit(0);
                }
            }
            if (maskArrayInt.length != 4) {
                System.out.println("Wrong mask");
                System.exit(0);
            }

            Boolean correctOur = false;
            for (int j = 0; j < 4; j++) {
                correctOur = false;
                for (int i = 0; i != 9; i++) {
                    double correctOctet = 255 - (Math.pow(2, i) - 1);
                    int correctOctInt = (int) correctOctet;
                    if (maskArrayInt[j] == correctOctInt) {
                        correctOur = true;
                    }
                }
                if (correctOur == false) {
                    System.out.println("Wrong mask");
                    System.exit(0);
                }
            }

            int[] netAddress = new int[4];
            for (int i = 0; i < netAddress.length; i++) {
                netAddress[i] = (ipArrayInt[i] & maskArrayInt[i]);
                if (i != 3) {
                    System.out.print(netAddress[i] + ".");
                } else {
                    System.out.print(netAddress[i]);
                }
            }
        } else {
            System.out.println("GetNetAddress <IP address> <Subnet mask>");
            System.exit(0);
        }
    }
}
