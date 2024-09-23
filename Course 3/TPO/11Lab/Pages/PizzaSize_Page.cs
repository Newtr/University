//Pizza Size
using _11Lab;
using OpenQA.Selenium;
using OpenQA.Selenium.Support.UI;
using SeleniumExtras.WaitHelpers;

public class Pizza_DodoPizzaPage
{
    private IWebDriver driver;
    private WebDriverWait wait;
    private Data data;
    private string siteUrl = "https://dodopizza.by";
    private string selectButtonXPath = "//button[@data-testid='product__button' and @type='button' and @data-type='secondary' and @data-size='medium' and @data-loading='false' and @class='sc-qlzmyl-0 kDsrCr product-control']";
    private string smallSizeLabelXPath = "//label[@data-testid='menu__pizza_size_Маленькая' and @for='Маленькая']";
    private string mediumSizeLabelXPath = "//label[@data-testid='menu__pizza_size_Средняя' and @for='Средняя']";
    private string largeSizeLabelXPath = "//label[@data-testid='menu__pizza_size_Большая' and @for='Большая']";
    private string minskLinkXPath = "//a[@class='sc-1c0ft0g-0 lhNEaG locality-selector-popup__link ' and @href='/minsk']";
    public Pizza_DodoPizzaPage(IWebDriver driver)
    {
        this.driver = driver;
        wait = new WebDriverWait(driver, TimeSpan.FromSeconds(10));
        data = new Data();
    }

    private void CheckSize(string size)
    {
        string sizeImageXPath = "";

        switch (size)
        {
            case "small":
                sizeImageXPath = "/html/body/div[3]/div/div[2]/div/div/div[1]/div/picture/img";
                break;
            case "medium":
                sizeImageXPath = "/html/body/div[3]/div/div[2]/div/div/div[1]/div/picture/img";
                break;
            case "large":
                sizeImageXPath = "/html/body/div[3]/div/div[2]/div/div/div[1]/div/picture/img";
                break;
        }

        var sizeImage = driver.FindElement(By.XPath(sizeImageXPath));

        if (sizeImage.Displayed)
        {
            Console.WriteLine("OK: " + size + " button corresponds to " + size + " image");
        }
        else
        {
            Console.WriteLine("ERROR: " + size + " button does not correspond to " + size + " image");
        }
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

    public void SelectPizza()
    {
        driver.FindElement(By.XPath(selectButtonXPath)).Click();
        Thread.Sleep(2000); // Пауза для загрузки страницы
        Console.WriteLine("Выбрана пицца");
    }

    public void ChooseSmallSize()
    {
        driver.FindElement(By.XPath(smallSizeLabelXPath)).Click();
        CheckSize("small");
        Thread.Sleep(2000); // Пауза для загрузки страницы
        Console.WriteLine("Выбран маленький размер");
    }

    public void ChooseMediumSize()
    {
        driver.FindElement(By.XPath(mediumSizeLabelXPath)).Click();
        CheckSize("medium");
        Thread.Sleep(2000); // Пауза для загрузки страницы
        Console.WriteLine("Выбран средний размер");
    }

    public void ChooseLargeSize()
    {
        driver.FindElement(By.XPath(largeSizeLabelXPath)).Click();
        CheckSize("large");
        Thread.Sleep(2000); // Пауза для загрузки страницы
        Console.WriteLine("Выбран большой размер");
    }
}