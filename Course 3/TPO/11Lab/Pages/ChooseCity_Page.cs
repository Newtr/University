using OpenQA.Selenium;
using OpenQA.Selenium.Support.UI;
using SeleniumExtras.WaitHelpers;
using System;
using System.Net;

namespace _11Lab
{
    // Delivery
    public class ChooseCity_Page
    {
        private IWebDriver driver;
        private WebDriverWait wait;
        private Data data;

        private By chooseCity = By.XPath("/html/body/div[3]/div/div[2]/div/div/div/div[2]/div/div/input");
        private By Borisov = By.XPath("/html/body/div[3]/div/div[2]/div/div/div/div[3]/div/div[2]/div[1]/div/div/div/a");
        public ChooseCity_Page(IWebDriver driver)
        {
            this.driver = driver;
            wait = new WebDriverWait(driver, TimeSpan.FromSeconds(10));
            data = new Data();
        }

        public void OpenSite()
        {
            driver.Navigate().GoToUrl(data.url);
            Console.WriteLine("Открыт сайт " + data.url);
            Thread.Sleep(5000);
        }

        public void ClickCityLink()
        {
            driver.FindElement(chooseCity).SendKeys("Борисов");
            Console.WriteLine("Нажата ссылка 'Минск'");
            Thread.Sleep(5000);
        }
        public void SelectAddress()
        {
            driver.FindElement(Borisov).Click();
            Console.WriteLine("Выбран желаемый адрес");
            Thread.Sleep(3000);
        }


    }
}
