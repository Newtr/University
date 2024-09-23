using OpenQA.Selenium;
using OpenQA.Selenium.Support.UI;
using SeleniumExtras.WaitHelpers;
using System;

namespace _11Lab
{
    // Email Check
    public class EmailLoginPage
    {
        private IWebDriver driver;
        private WebDriverWait wait;
        public Data data;

        private string minskLinkXPath = "//a[@class='sc-1c0ft0g-0 lhNEaG locality-selector-popup__link ' and @href='/minsk']";
        private string loginButtonXPath = "//button[@data-testid='header_login' and @type='button']";
        private string phoneInputXPath = "//input[@data-testid='checkout-form__phone-input' and @type='tel']";
        private string sendCodeButtonXPath = "//button[@data-testid='login_submit_button' and @type='button']";
        private string[] codeInputXPaths = new string[4]
        {
            "//input[@type='tel' and @data-id='0']",
            "//input[@type='tel' and @data-id='1']",
            "//input[@type='tel' and @data-id='2']",
            "//input[@type='tel' and @data-id='3']"
        };

        public EmailLoginPage(IWebDriver driver)
        {
            this.driver = driver;
            wait = new WebDriverWait(driver, TimeSpan.FromSeconds(10));
            data = new Data();
        }

        public void GoToSite()
        {
            driver.Navigate().GoToUrl(data.url);
            wait.Until(ExpectedConditions.ElementExists(By.XPath(minskLinkXPath)));
            Console.WriteLine("Открыт сайт " + data.url);
            Thread.Sleep(5000);
        }

        public void ClickMinskLink()
        {
            wait.Until(ExpectedConditions.ElementToBeClickable(By.XPath(minskLinkXPath))).Click();
            Console.WriteLine("Нажата ссылка 'Минск'");
            Thread.Sleep(5000);
        }

        public void ClickLoginButton()
        {
            wait.Until(ExpectedConditions.ElementToBeClickable(By.XPath(loginButtonXPath))).Click();
            Console.WriteLine("Нажата кнопка 'Войти'");
            Thread.Sleep(5000);
        }

        public void EnterPhoneNumber()
        {
            wait.Until(ExpectedConditions.ElementIsVisible(By.XPath(phoneInputXPath))).SendKeys(data.phoneNumber);
            Console.WriteLine("Введен номер телефона: " + data.phoneNumber);
            Thread.Sleep(5000);
        }

        public void ClickSendCodeButton()
        {
            wait.Until(ExpectedConditions.ElementToBeClickable(By.XPath(sendCodeButtonXPath))).Click();
            Console.WriteLine("Нажата кнопка 'Выслать код'");
            Thread.Sleep(40000);
        }

        public void EnterCode()
        {
            for (int i = 0; i < 4; i++)
            {
                wait.Until(ExpectedConditions.ElementIsVisible(By.XPath(codeInputXPaths[i]))).SendKeys(data.code[i].ToString());
            }
            Console.WriteLine("Введен код: " + data.code);
        }

        public void Close()
        {
            driver.Quit();
        }
    }
}
