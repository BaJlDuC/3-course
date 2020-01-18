package com.example.main;

public class Customer {
    private int age;
    private String name;
    private Basket customerBasket = new Basket();

    public Customer (String name, int age) {
        this.age = age;
        this.name = name;
    }
    public String GetCustomerCategory() {
        if (this.age < 18) {
            return "Child";
        }
        else if ((this.age >= 18) && (this.age < 60)) {
            return "Adult";
        }
        else {
            return "Retired";
        }
    }

    public String GetName() {
        return this.name;
    }

    public void AddProductInBasket(Product someProduct) {
        this.customerBasket.AddProduct(someProduct);
    }

    public Basket GetBasketWithProducts() {
        return this.customerBasket;
    }
}
