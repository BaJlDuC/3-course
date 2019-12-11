package concreteTestClasses;

import com.codeborne.selenide.Configuration;
import org.junit.jupiter.api.Test;
import userConfig.configClass;

import static com.codeborne.selenide.Selectors.*;
import static org.junit.jupiter.api.Assertions.*;
import static com.codeborne.selenide.Selenide.$;
import static com.codeborne.selenide.Selenide.open;

public class searchProduct {

    public void searchProductTest() {
        Configuration.browser = configClass.browser;
        Configuration.baseUrl = configClass.baseUrl;

        open(configClass.testingUrl);
        $(byName(configClass.searchField)).setValue(configClass.searchingValue).pressEnter();
    }
}
