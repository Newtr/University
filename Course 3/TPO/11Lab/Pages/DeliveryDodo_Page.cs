using OpenQA.Selenium;
using OpenQA.Selenium.Support.UI;
using SeleniumExtras.WaitHelpers;
using System;

namespace _11Lab
{
    // Delivery
    public class Delivery_DodoPizzaPage
    {
        private IWebDriver driver;
        private WebDriverWait wait;
        private Data data;

        private By cookieButton = By.Id("c-s-bn");
        private By drinksButton = By.XPath("//*[@id='react-app']/nav/div/nav/ul[1]/li[5]/a");
        private By lemonadeButton = By.XPath("//article[@data-testid='menu__meta-product_11eee5fe987da96da3319803c80fda00']//button[@data-testid='product__button' and @type='button' and @data-type='secondary' and @data-size='medium' and @data-loading='false' and contains(@class, 'product-control')]");
        private By deliveryButton = By.XPath("/html/body/div[3]/div/div[2]/div/div/div[1]/button");
        private By addressInput = By.XPath("//*[@id='animated-input-1']");
        private By addressSelectButton = By.XPath("/html/body/div[3]/div/div[2]/div/div/form/div[1]/div/div/ul/li[1]/button");
        private By addButton = By.XPath("/html/body/div[3]/div/div[2]/div/div/form/div[3]/button");
        private By cartButton = By.XPath("//button[@data-testid='navigation__cart']");
        private By checkoutButton = By.XPath("//button[@data-testid='cart__button_next']");
        private By phoneInput = By.XPath("//input[@data-testid='checkout-form__phone-input']");
        private By sendCodeButton = By.XPath("//button[@data-testid='login_submit_button']");
        private By codeInputs = By.XPath("//input[@type='tel']");
        private string minskLinkXPath = "//a[@class='sc-1c0ft0g-0 lhNEaG locality-selector-popup__link ' and @href='/minsk']";

        public Delivery_DodoPizzaPage(IWebDriver driver)
        {
            this.driver = driver;
            wait = new WebDriverWait(driver, TimeSpan.FromSeconds(10));
            data = new Data();
        }

        public void OpenSite()
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

        public void AcceptCookies()
        {
            driver.FindElement(cookieButton).Click();
            Console.WriteLine("Убрали куки");
            Thread.Sleep(3000);
        }

        public void SelectDrinks()
        {
            driver.FindElement(drinksButton).Click();
            Console.WriteLine("Выбрана категория напитки");
            Thread.Sleep(3000);
        }

        public void SelectLemonade()
        {
            driver.FindElement(lemonadeButton).Click();
            Console.WriteLine("Выбран лимонад");
            Thread.Sleep(3000);
        }

        public void ChooseDelivery()
        {
            driver.FindElement(deliveryButton).Click();
            Console.WriteLine("Выбрана доставка");
            Thread.Sleep(3000);
        }

        public void EnterAddress(string address)
        {
            driver.FindElement(addressInput).SendKeys(address);
            Console.WriteLine("Введен желаемый адрес");
            Thread.Sleep(3000);
        }

        public void SelectAddress()
        {
            driver.FindElement(addressSelectButton).Click();
            Console.WriteLine("Выбран желаемый адрес");
            Thread.Sleep(3000);
        }

        public void AddToCart()
        {
            driver.FindElement(addButton).Click();
            Console.WriteLine("Добавление в корзину");
            Thread.Sleep(3000);
        }

        public void OpenCart()
        {
            driver.FindElement(cartButton).Click();
            Console.WriteLine("Открыта корзина");
            Thread.Sleep(3000);
        }

        public void ProceedToCheckout()
        {
            driver.FindElement(checkoutButton).Click();
            Console.WriteLine("Переход к оформлению заказа");
            Thread.Sleep(3000);
        }

        public void EnterPhoneNumber(string phoneNumber)
        {
            driver.FindElement(phoneInput).SendKeys(phoneNumber);
            Console.WriteLine("Введен номер телефона: " + phoneNumber);
            Thread.Sleep(3000);
        }

        public void SendCode()
        {
            driver.FindElement(sendCodeButton).Click();
            Console.WriteLine("Код отправлен");
            Thread.Sleep(40000);
        }

        public void EnterCode(string code)
        {
            var codeElements = driver.FindElements(codeInputs);
            for (int i = 0; i < code.Length; i++)
            {
                codeElements[i].SendKeys(code[i].ToString());
            }
            Console.WriteLine("Введен код: " + code);
            Thread.Sleep(3000);
        }
    }
}
