package concreteTestClasses;

import com.codeborne.selenide.Configuration;
import org.junit.jupiter.api.Test;
import userConfig.configClass;

import static org.junit.jupiter.api.Assertions.*;
import static com.codeborne.selenide.Selectors.byName;
import static com.codeborne.selenide.Selectors.byText;
import static com.codeborne.selenide.Selenide.$;
import static com.codeborne.selenide.Selenide.open;

public class userAuthorization {

    public void authorizationTest() {
        Configuration.browser = configClass.browser;
        Configuration.baseUrl = configClass.baseUrl;

        open(configClass.testingUrl);
        $(byText(configClass.account)).click();
        $(byText(configClass.signIn)).click();
        $(byName(configClass.login)).setValue(configClass.userLogin);
        $(byName(configClass.password)).setValue(configClass.userPassword);
        $(configClass.loginSelector).find(byText(configClass.signIn)).click();
    }


    public boolean successfullMessage() {
       return $(byText(configClass.successfullAuthorization)).isDisplayed();
    }
}
