package com.example.main;

import java.util.Vector;

public class superMarketSimulator {
    public static void main(String[] args) {
        Supermarket superMart = new Supermarket();
        Report report = new Report();

        System.out.println(superMart.Open());
        superMart.CreatingProducts();
        superMart.CreatingCustomers();
        superMart.BuyingProducts();
        superMart.Payment();
        System.out.println(superMart.Close());
        report.PrintReport(superMart);
    }
}
