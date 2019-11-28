import com.example.unitTests.Product;
import org.junit.jupiter.api.RepeatedTest;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ProductTest {

    @Test
    void getSum_someValue_returnsNumber() {
        Product milk = new Product("Milk", 50, 45);
        int expectedMilk = 2250;
        int actualMilk = milk.GetSum();
        assertEquals(actualMilk, expectedMilk, "вычисление среднего значения Integer");
    }

    @Test
    void getSum_boundaryValue_returnsNumber() {
        Product goodMilk = new Product("Good Milk", Integer.MAX_VALUE, 1);
        int expectedGoodMilk = Integer.MAX_VALUE;
        int actualGoodMilk = goodMilk.GetSum();
        assertEquals(expectedGoodMilk, actualGoodMilk, "вычисление граничного значения Integer");
    }

    @Test
    void getName_nameString_returnsName() {
        Product chocolate = new Product("Chocolate", 120, 60);
        String expected = "Chocolate";
        String actual = chocolate.GetName();
        assertEquals(expected, actual, "проверка возврата имени");
    }

    @Test
    void getCost_someValue_returnsNumber() {
        Product chocolate = new Product("Chocolate", 120, 60);
        int expectedChocolate = 120;
        int actualChocolate = chocolate.GetCost();
        assertEquals(expectedChocolate, actualChocolate, "получение среднего значения Integer");
    }

    @Test
    void getCost_boundaryValue_returnsNumber() {
        Product meat = new Product("Meat", Integer.MAX_VALUE, 2);
        int expectedMeat = Integer.MAX_VALUE;
        int actualMeat = meat.GetCost();
        assertEquals(expectedMeat, expectedMeat, "получение граничного значения Integer");
    }

    @Test
    void setNewCost_boundaryValue_returnsNumber() {
        Product potato = new Product("Potato", 30, 100);
        potato.SetNewCost(Integer.MAX_VALUE);
        int expected = Integer.MAX_VALUE;
        int actual = potato.GetCost();
        assertEquals(expected, actual, "установление граничного значения Integer");
    }

    @Test
    void productIsEmpty_empty_returnsTrue() {
        Product redTea = new Product("Red Tea", 240, 0);//ередача атрибутов
        assertTrue(redTea.ProductIsEmpty(), "проверка пустого товара (кол-во = 0)");
    }

    @Test
    void productIsEmpty_notEmpty_returnsFalse() {
        Product blackTea = new Product("Black Tea", 150, 25);
        assertFalse(blackTea.ProductIsEmpty(), "проверка непустого товара");
    }
}