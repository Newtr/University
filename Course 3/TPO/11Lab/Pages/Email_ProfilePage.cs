using OpenQA.Selenium;
using OpenQA.Selenium.Support.UI;
using SeleniumExtras.WaitHelpers;
using System;

namespace _11Lab
{
    // Email Check
    public class EmailProfilePage
    {
        private IWebDriver driver;
        private WebDriverWait wait;
        public Data data;

        private string profileButtonXPath = "//a[@class='sc-1c0ft0g-0 lhNEaG sc-x055k6-2 fgNnch' and @href='/minsk/profile' and @data-active='false']";
        private string emailInputXPath = "//input[@data-testid='profile__email-input' and @id='eml-input']";
        private string saveButtonXPath = "//a[@data-testid='profile__email-save' and @class='sc-1c0ft0g-0 lhNEaG action-button undefined']";

        public EmailProfilePage(IWebDriver driver)
        {
            this.driver = driver;
            wait = new WebDriverWait(driver, TimeSpan.FromSeconds(10));
            data = new Data();
        }

        public void EnterEmail()
        {
            wait.Until(ExpectedConditions.ElementIsVisible(By.XPath(emailInputXPath))).SendKeys(data.email);
            Console.WriteLine("Введен email: " + data.email);
        }

        public void ClickSaveButton()
        {
            wait.Until(ExpectedConditions.ElementToBeClickable(By.XPath(saveButtonXPath))).Click();
            Console.WriteLine("Нажата кнопка 'Сохранить'");
        }
    }
}
