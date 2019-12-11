package tests;
import concreteTestClasses.*;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertTrue;

public class UITests {
    @Test
    public void authorizationTesting() {
        userAuthorization authorizationCase = new userAuthorization();
        authorizationCase.authorizationTest();
        assertTrue(authorizationCase.successfullMessage(), "check adding process");
    }

    @Test
    public void buyProductTesting() {
        buyProduct buyProductCase = new buyProduct();
        buyProductCase.buyProductTest();
        assertTrue(buyProductCase.successfullMessage(), "check successfull message");
    }

    @Test
    public void addProductToBasketTesting() {
        addProductToBasket addProductToBasketCase = new addProductToBasket();
        addProductToBasketCase.addProductTest();
        assertTrue(addProductToBasketCase.successfullMessage(), "successfull meessage");
    }

    @Test
    public void searchTesting() {
        searchProduct searchCase = new searchProduct();
        searchCase.searchProductTest();
    }
}
