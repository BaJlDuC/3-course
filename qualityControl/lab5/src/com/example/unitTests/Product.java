package com.example.unitTests;

public class Product {
    private int cost;
    private int count;
    private String productName;

    public Product(String name, int cost, int count) {
        this.productName = name;
        this.cost = cost;
        this.count = count;
    }

    public int GetSum() {
        return this.cost * this.count;
    }

    public String GetName() {
        return this.productName;
    }

    public int GetCount() {
        return this.count;
    }

    public int GetCost() {
        return this.cost;
    }

    public void SetNewCost(int cost) {
        this.cost = cost;
    }

    public Boolean ProductIsEmpty() {
        if (this.count == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}
