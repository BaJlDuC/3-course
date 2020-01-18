package com.example.main;

import java.util.Random;

public class PaymentMethod {
    private String payment = "";

    public void DefinitionPaymentMethod() {
        Random random = new Random();
        int method = random.nextInt(4);
        switch (method) {
            case 0:
                this.payment = "cash";
                break;
            case 1:
                this.payment = "card";
                break;
            case 2:
                this.payment = "apple pay";
                break;
            case 3:
                this.payment = "google pay";
                break;
        }
    }

    public String GetPaymentMethod() {
        return this.payment;
    }
}
