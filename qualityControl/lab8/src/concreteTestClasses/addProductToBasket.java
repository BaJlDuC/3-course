package concreteTestClasses;

import com.codeborne.selenide.Configuration;
import org.junit.jupiter.api.Test;
import userConfig.configClass;

import static org.junit.jupiter.api.Assertions.*;
import static com.codeborne.selenide.Selectors.byId;
import static com.codeborne.selenide.Selectors.byText;
import static com.codeborne.selenide.Selenide.$;
import static com.codeborne.selenide.Selenide.open;

public class addProductToBasket {

    private String price = "";
    public void addProductTest() {
        Configuration.browser = configClass.browser;
        Configuration.baseUrl = configClass.baseUrl;

        open(configClass.testingUrl);
        $(byText(configClass.testingWatches)).click();
        $(byText(configClass.addToCart)).click();
        String priceString = $(byId(configClass.priceId)).toString();
        String price = priceString.substring(priceString.length() - 9, priceString.length() - 5);
        this.price = price;
    }


    public boolean successfullMessage() {
        return $(byText(this.price)).isDisplayed();
    }
}
