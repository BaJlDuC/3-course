package com.example.main;

public class Bill {
    private int sum = 0;

    public int GetSum() {
        return this.sum;
    }
    public void SetBill(Customer customer) {
        this.sum = customer.GetBasketWithProducts().GetSumFromBasket();
    }
}
