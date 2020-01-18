package com.example.main;
import java.util.Vector;

public class Basket {
    private int totalSum = 0;
    Vector<Product> productsInBasket = new Vector<Product>();

    public void AddProduct(Product productToBasket) {
        this.productsInBasket.add(productToBasket);
    }

    public Vector<Product> GetProductsInBasket() {
        return this.productsInBasket;
    }

    public int GetSumFromBasket() {
        for (int i = 0; i < productsInBasket.size(); i++) {
             this.totalSum += productsInBasket.elementAt(i).GetSum();
        }
        return this.totalSum;
    }
}
