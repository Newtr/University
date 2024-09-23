using OpenQA.Selenium;
using OpenQA.Selenium.Support.UI;
using SeleniumExtras.WaitHelpers;
using System;
using System.Collections.Generic;

namespace _11Lab
{
    // Promocode
    public class Promo_DodoPizzaPage
    {
        private IWebDriver driver;
        private WebDriverWait wait;
        private Data data;

        private By cookieButton = By.Id("c-s-bn");
        private By selectButton = By.XPath("//button[@data-testid='product__button' and @type='button' and @data-type='secondary' and @data-size='medium' and @data-loading='false' and @class='sc-qlzmyl-0 kDsrCr product-control']");
        private By addToCartButton = By.XPath("//button[@data-testid='button_add_to_cart']");
        private By pickupButton = By.XPath("//button[@data-testid='how_to_get_order_pickup_action']");
        private By addressButton = By.Id("00000007-0000-0000-0000-000000000000");
        private By selectPizzaButton = By.XPath("//button[@data-testid='menu_product_select']");
        private By cartButton = By.XPath("//button[@data-testid='navigation__cart']");
        private By checkoutButton = By.XPath("//button[@data-testid='cart__button_next']");
        private By phoneInput = By.XPath("//input[@data-testid='checkout-form__phone-input']");
        private By sendCodeButton = By.XPath("//button[@data-testid='login_submit_button']");
        private By codeInputs = By.XPath("//input[@type='tel']");
        private By promocodeInput = By.XPath("//input[@class='input promocode-checkout-input ']");
        private By applyPromocodeButton = By.XPath("//button[@class='sc-qlzmyl-0 cmQPyq promocode-checkout-confirm-button']");
        private string minskLinkXPath = "//a[@class='sc-1c0ft0g-0 lhNEaG locality-selector-popup__link ' and @href='/minsk']";

        public Promo_DodoPizzaPage(IWebDriver driver)
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

        public void SelectPizza()
        {
            driver.FindElement(selectButton).Click();
            Console.WriteLine("Выбрана пицца");
            Thread.Sleep(3000);
        }

        public void AddToCart()
        {
            driver.FindElement(addToCartButton).Click();
            Console.WriteLine("Пицца добавлена в корзину");
            Thread.Sleep(3000);
        }

        public void ChoosePickup()
        {
            driver.FindElement(pickupButton).Click();
            Console.WriteLine("Выбран способ получения пиццы");
            Thread.Sleep(3000);
        }

        public void ChooseAddress()
        {
            driver.FindElement(addressButton).Click();
            Console.WriteLine("Выбран адрес");
            Thread.Sleep(3000);
        }

        public void ConfirmPizzaSelection()
        {
            driver.FindElement(selectPizzaButton).Click();
            Console.WriteLine("Подтвержден выбраный адрес");
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
            Thread.Sleep(10000);
        }

        public void EnterPromocode(string promocode)
        {
            driver.FindElement(promocodeInput).SendKeys(promocode);
            Console.WriteLine("Введен промокод: " + promocode);
        }

        public void ApplyPromocode()
        {
            driver.FindElement(applyPromocodeButton).Click();
            Console.WriteLine("Применен промокод");
        }
    }
}
