package com.example.main;
import java.util.Vector;

public class Report {
    public void PrintReport(Supermarket superMart) {
        Vector<Product> boughtProducts = superMart.GetBoughtProducts();
        System.out.println("Bought products: ");
        for (int i = 0; i < boughtProducts.size(); i++) {
            Product productForInfo = boughtProducts.elementAt(i);
            System.out.println("-" + productForInfo.GetName() + ", count: " + productForInfo.GetCount() + ", total sum: " +
                    productForInfo.GetSum());
        }
    }
}
