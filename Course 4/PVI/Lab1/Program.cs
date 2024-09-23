var builder = WebApplication.CreateBuilder(args);
// Добавляем поддержку сессий
builder.Services.AddDistributedMemoryCache();
builder.Services.AddSession(options =>
{
    options.IdleTimeout = TimeSpan.FromMinutes(30); // Время истечения сессии
    options.Cookie.HttpOnly = true; // Делаем куки сессии недоступными для JavaScript
    options.Cookie.IsEssential = true; // Куки необходимы для функционирования сессии
});
var app = builder.Build();
// Подключаем сессии
app.UseSession();

app.MapGet("/", () => "Hello World!");

app.Run();
