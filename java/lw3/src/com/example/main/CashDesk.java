package com.example.main;

public class CashDesk {
    private Bill bill = new Bill();
    private PaymentMethod pay = new PaymentMethod();

    public int GetSumCustomer(Customer customer) {
        this.bill.SetBill(customer);
        return this.bill.GetSum();
    }

    public String GetCustomerPaymentMethod() {
        this.pay.DefinitionPaymentMethod();
        return this.pay.GetPaymentMethod();
    }
}
