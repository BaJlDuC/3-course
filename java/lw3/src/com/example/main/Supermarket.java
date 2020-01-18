package com.example.main;
import java.util.Random;
import java.util.Vector;

public class Supermarket {
    private Vector<Product> products = new Vector<Product>();
    private Vector<Customer> customers = new Vector<Customer>();
    private Vector<Customer> customersWithProducts = new Vector<Customer>();
    private Vector<Product> boughtProducts = new Vector<Product>();

   public String Open() {
       return "Supermarket is opened";
   }
   public void CreatingProducts() {
       Random random = new Random();
       String[] products = {"Milk", "Cigarettes", "Bread", "Chocolate", "Potato"};
       int productCount = random.nextInt(5) + 1;
       Vector productsWhichWas = new Vector();
       Vector<Product> generatedProducts = new Vector<Product>();
       Vector<Customer> customers = new Vector<Customer>();

       System.out.println("Supermarket products have been formed:");
       for (int i = 0; i < productCount; i++) {
           int productId = random.nextInt(products.length);

           if (!productsWhichWas.contains(productId)) {
               productsWhichWas.add(productId);
           } else {
               while (productsWhichWas.contains(productId)) {
                   productId = random.nextInt(products.length);
               }
               productsWhichWas.add(productId);
           }

           int concreteProductCount = random.nextInt(10) + 1;
           switch (productId) {
               case (0): // milk
                   Product milk = new Product("Milk", 50, concreteProductCount);
                   generatedProducts.add(milk);
                   System.out.println("Generated " + milk.GetName() + ", " + milk.GetCount() + " units");
                   break;
               case (1): // cigarettes
                   Product cigarettes = new Product("Cigarettes", 150, concreteProductCount);
                   generatedProducts.add(cigarettes);
                   System.out.println("Generated " + cigarettes.GetName() + ", " + cigarettes.GetCount() + " units");
                   break;
               case (2): // bread
                   Product bread = new Product("Bread", 25, concreteProductCount);
                   generatedProducts.add(bread);
                   System.out.println("Generated " + bread.GetName() + ", " + bread.GetCount() + " units");
                   break;
               case (3): // chocolate
                   Product chocolate = new Product("Chocolate", 75, concreteProductCount);
                   generatedProducts.add(chocolate);
                   System.out.println("Generated " + chocolate.GetName() + ", " + chocolate.GetCount() + " units");
                   break;
               case (4): // potato
                   Product potato = new Product("Potato", 30, concreteProductCount);
                   generatedProducts.add(potato);
                   System.out.println("Generated " + potato.GetName() + ", " + potato.GetCount() + " kg");
                   break;
           }
       }
       System.out.println("");
       this.products = generatedProducts;
   }
   public void CreatingCustomers() {
       Vector<Customer> customers = new Vector<Customer>();
       Random random = new Random();
       int customersCount = random.nextInt(10) + 1;
       for (int i = 0; i < customersCount; i++) {
           String customerName = "customer#" + String.valueOf(i + 1);
           int minAge = 14;
           int maxAge = 70;
           int diff = maxAge - minAge;
           int customerAge = random.nextInt(diff) + 1;
           customerAge += minAge;

           Customer customer = new Customer(customerName, customerAge);
           customers.add(customer);
           System.out.println("New customer " + customer.GetName() + " arrived");
       }
       this.customers = customers;
   }
   public void BuyingProducts() {
       Vector<Customer> customersWithProducts = new Vector<Customer>();
       Random random = new Random();

       for (int i = 0; i < this.customers.size(); i++) {
           int productId = random.nextInt(this.products.size());
           int productCount = random.nextInt(10) + 1;

           Product someProduct = new Product(products.elementAt(productId).GetName(), products.elementAt(productId).GetCost(), products.elementAt(productId).GetCount());
           if (someProduct.GetCount() == 0) {
               System.out.println(customers.elementAt(i).GetName() + " wanted to buy " + someProduct.GetName() +
                       " " + productCount + " units, but its ended");
           } else if (someProduct.GetCount() < productCount) {
               System.out.println(customers.elementAt(i).GetName() + " wanted to buy " + someProduct.GetName() +
                       ", " + productCount + " units, but buy the last " + someProduct.GetCount() +
                       " units");
               Customer customerWithProduct = customers.elementAt(i);
               customerWithProduct.AddProductInBasket(someProduct);// someProduct was
               customersWithProducts.add(customerWithProduct);
               if (!boughtProducts.isEmpty()) {
                   boolean updated = false;
                   for (int j = 0; j < boughtProducts.size(); j++) {
                       if ((someProduct.GetName().equals(boughtProducts.elementAt(j).GetName())) && (!updated))
                       {
                           boughtProducts.elementAt(j).SetNewCount(boughtProducts.elementAt(j).GetCount() + someProduct.GetCount());
                           updated = true;
                       }
                       else if ((j == boughtProducts.size() - 1) && (!updated))
                       {
                           boughtProducts.add(someProduct);
                           boughtProducts.elementAt(boughtProducts.size() - 1).SetNewCount(someProduct.GetCount() / 2);
                       }
                   }
               }
               else {
                   boughtProducts.add(someProduct);
               }
               customerWithProduct.GetBasketWithProducts().GetSumFromBasket();

               products.elementAt(productId).SetNewCount(0);
               //System.out.println(someProduct.GetSum());
           } else {
               this.products.elementAt(productId).SetNewCount(someProduct.GetCount() - productCount);
               someProduct.SetNewCount(productCount);
               System.out.println(customers.elementAt(i).GetName() + " buying " + someProduct.GetName() +
                       ", " + productCount + " units");
               Customer customerWithProduct = customers.elementAt(i);
               customerWithProduct.AddProductInBasket(someProduct);
               customersWithProducts.add(customerWithProduct);
               if (!boughtProducts.isEmpty()) {
                   boolean updated = false;
                   for (int j = 0; j < boughtProducts.size(); j++) {
                       if ((someProduct.GetName().equals(boughtProducts.elementAt(j).GetName())) && (!updated))
                       {
                           boughtProducts.elementAt(j).SetNewCount(boughtProducts.elementAt(j).GetCount() + someProduct.GetCount());
                           updated = true;
                       }
                       else if ((j == boughtProducts.size() - 1) && (!updated))
                       {
                           boughtProducts.add(someProduct);
                           boughtProducts.elementAt(boughtProducts.size() - 1).SetNewCount(someProduct.GetCount() / 2);
                       }
                   }
               }
               else {
                   boughtProducts.add(someProduct);
               }
               customerWithProduct.GetBasketWithProducts().GetSumFromBasket();
           }
       }
       this.customersWithProducts = customersWithProducts;
   }
   public void Payment() {
       System.out.println();
       //CashDesk cashDesk = new CashDesk();
       for (int i = 0; i < this.customersWithProducts.size(); i++) {
           CashDesk cashDesk = new CashDesk();
           Customer customerForService = this.customersWithProducts.elementAt(i);
           int cost = cashDesk.GetSumCustomer(customerForService) / 2;
           System.out.println(customerForService.GetName() + " at the cash desk, amount to pay: " +
                   cost);
           System.out.println("Customer paid " + cost + " by " +
                   cashDesk.GetCustomerPaymentMethod());
       }
   }
   public Vector<Product> GetBoughtProducts() {
       return boughtProducts;
   }
   public Vector<Customer> GetCustomersWithProducts() {
       return this.customersWithProducts;
   }
   public String Close() {
       return "Supermarket is closed";
   }
}
