
using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;
using _11Lab;
using System.Reflection.Emit;
using System.Reflection.Metadata.Ecma335;

namespace Tests
{
    public class EmailLoginAndProfileTests
    {
        private IWebDriver driver;
        private EmailLoginPage emailLoginPage;
        private EmailProfilePage emailProfilePage;
        private Pizza_DodoPizzaPage pizzaSizePage;
        private Promo_DodoPizzaPage promoPizzaPage;
        private Delivery_DodoPizzaPage deliveryPizzaPage;
        private ChooseCity_Page chooseCityPage;
        private Order_DodoPizzaPage orderPizzaPage;

        [SetUp]
        public void Setup()
        {
            var options = new ChromeOptions();
            options.AddArgument("--incognito"); // Добавляем опцию инкогнито

            driver = new ChromeDriver(options); // Или новый FirefoxDriver() для Firefox
            emailLoginPage = new EmailLoginPage(driver);
            emailProfilePage = new EmailProfilePage(driver);
            pizzaSizePage = new Pizza_DodoPizzaPage(driver);
            promoPizzaPage = new Promo_DodoPizzaPage(driver);
            deliveryPizzaPage = new Delivery_DodoPizzaPage(driver);
            chooseCityPage = new ChooseCity_Page(driver);
            orderPizzaPage = new Order_DodoPizzaPage(driver);
        }

        [Test]
        public void TestLoginAndProfileUpdateProcess()
        {
            emailLoginPage.GoToSite();
            emailLoginPage.ClickMinskLink();
            emailLoginPage.ClickLoginButton();
            emailLoginPage.EnterPhoneNumber();
            emailLoginPage.ClickSendCodeButton();

            Thread.Sleep(20000);

            string newCode = File.ReadAllText("D://Документы БГТУ//5.TPO//11Lab//11Lab//11Lab//Code.txt");


            emailLoginPage.data.code = newCode;
            emailLoginPage.EnterCode();

            Thread.Sleep(5000); // Пауза

            emailProfilePage.EnterEmail();
            emailProfilePage.ClickSaveButton();

            // Здесь можно добавить проверку успешного обновления профиля
            Assert.Pass();
        }

/*        [Test]
        public void TestOrderProcess()
        {
            orderPizzaPage.OpenSite();
            orderPizzaPage.ClickMinskLink();
            orderPizzaPage.AcceptCookies();
            orderPizzaPage.SelectDrinks();
            orderPizzaPage.SelectLemonade();
            deliveryPizzaPage.ChooseDelivery();

            string address = "Минск, улица Свердлова, 13А";
            orderPizzaPage.EnterAddress(address);
            orderPizzaPage.SelectAddress();
            orderPizzaPage.AddToCart();
            orderPizzaPage.OpenCart();
            orderPizzaPage.ProceedToCheckout();

            string phoneNumber = "296022799";
            orderPizzaPage.EnterPhoneNumber(phoneNumber);
            orderPizzaPage.SendCode();

            // Пауза для изменения кода в файле
            Thread.Sleep(7000);

            // Чтение кода из файла
            string code = File.ReadAllText("D:\\Документы БГТУ\\5.TPO\\11Lab\\11Lab\\11Lab\\Code.Txt");
            if (code.Length != 4)
            {
                Console.WriteLine("Код должен состоять из 4 цифр.");
                Assert.Fail("Код должен состоять из 4 цифр.");
            }

            orderPizzaPage.EnterCode(code);

            string cardNumber = "1234567812345678";
            string cardCvc = "123";
            string cardMonthYear = "12/23";
            orderPizzaPage.EnterCardDetails(cardNumber, cardCvc, cardMonthYear);
        }*/

        [Test]
        public void TestSelectPizzaAndChooseSizes()
        {
            pizzaSizePage.OpenSite();
            pizzaSizePage.ClickMinskLink();
            pizzaSizePage.SelectPizza();

            pizzaSizePage.ChooseSmallSize();
            pizzaSizePage.ChooseMediumSize();
            pizzaSizePage.ChooseLargeSize();
        }

        [Test]
        public void TestChooseCity()
        {
            chooseCityPage.OpenSite();
            chooseCityPage.ClickCityLink();
            chooseCityPage.SelectAddress();
        }

        [Test]
        public void TestApplyPromocode()
        {
            pizzaSizePage.OpenSite();
            pizzaSizePage.ClickMinskLink();
            promoPizzaPage.AcceptCookies();
            promoPizzaPage.SelectPizza();
            promoPizzaPage.AddToCart();
            promoPizzaPage.ChoosePickup();
            promoPizzaPage.ChooseAddress();
            promoPizzaPage.ConfirmPizzaSelection();
            promoPizzaPage.OpenCart();
            promoPizzaPage.ProceedToCheckout();

            string phoneNumber = "296022799";
            promoPizzaPage.EnterPhoneNumber(phoneNumber);
            promoPizzaPage.SendCode();

            // Добавьте паузу здесь для ввода кода вручную или используйте автоматическое чтение кода из файла
            Thread.Sleep(7000);

            // Чтение кода из файла
            string code = File.ReadAllText("D:\\Документы БГТУ\\5.TPO\\11Lab\\11Lab\\11Lab\\Code.Txt");
            if (code.Length != 4)
            {
                Console.WriteLine("Код должен состоять из 4 цифр.");
                Assert.Fail("Код должен состоять из 4 цифр.");
            }

            promoPizzaPage.EnterCode(code);

            string promocode = "Random text";
            promoPizzaPage.EnterPromocode(promocode);
            promoPizzaPage.ApplyPromocode();
        }

        [Test]
        public void TestDeliveryOrder()
        {
            pizzaSizePage.OpenSite();
            pizzaSizePage.ClickMinskLink();
            deliveryPizzaPage.AcceptCookies();
            deliveryPizzaPage.SelectDrinks();
            deliveryPizzaPage.SelectLemonade();
            deliveryPizzaPage.ChooseDelivery();

            string address = "Минск, улица Свердлова, 13А";
            deliveryPizzaPage.EnterAddress(address);
            deliveryPizzaPage.SelectAddress();
            deliveryPizzaPage.AddToCart();
            deliveryPizzaPage.OpenCart();
            deliveryPizzaPage.ProceedToCheckout();

            string phoneNumber = "296022799";
            deliveryPizzaPage.EnterPhoneNumber(phoneNumber);
            deliveryPizzaPage.SendCode();

            // Пауза для изменения кода в файле
            Thread.Sleep(7000);

            // Чтение кода из файла
            string code = File.ReadAllText("D:\\Документы БГТУ\\5.TPO\\11Lab\\11Lab\\11Lab\\Code.Txt");
            if (code.Length != 4)
            {
                Console.WriteLine("Код должен состоять из 4 цифр.");
                Assert.Fail("Код должен состоять из 4 цифр.");
            }

            deliveryPizzaPage.EnterCode(code);
        }

        [TearDown]
        public void TearDown()
        {
            if (driver != null)
            {
                driver.Quit();
                driver.Dispose();
            }
        }
    }

    
}
