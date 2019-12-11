package concreteTestClasses;

import com.codeborne.selenide.Configuration;
import org.junit.jupiter.api.Test;
import userConfig.configClass;

import static org.junit.jupiter.api.Assertions.*;
import static com.codeborne.selenide.Selectors.byName;
import static com.codeborne.selenide.Selectors.byText;
import static com.codeborne.selenide.Selenide.$;
import static com.codeborne.selenide.Selenide.open;

public class buyProduct {
    public void buyProductTest() {
        Configuration.browser = configClass.browser;
        Configuration.baseUrl = configClass.baseUrl;

        open(configClass.testingUrl);
        $(byText(configClass.buyingWatches)).click();
        $(byText(configClass.addToCart)).click();
        $(byText(configClass.rifinireOrder)).click();
        $(byName(configClass.login)).setValue(configClass.buyingUserLogin);
        $(byName(configClass.password)).setValue(configClass.buyingUserPassword);
        $(byName(configClass.name)).setValue(configClass.userName);
        $(byName(configClass.email)).setValue(configClass.userEmail);
        $(byName(configClass.address)).setValue(configClass.address);
        $(byText(configClass.rifinire)).click();
    }

    public boolean successfullMessage() {
        return $(byText(configClass.successMessage)).isDisplayed();
    }
}

