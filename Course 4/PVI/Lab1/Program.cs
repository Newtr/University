var builder = WebApplication.CreateBuilder(args);
// ��������� ��������� ������
builder.Services.AddDistributedMemoryCache();
builder.Services.AddSession(options =>
{
    options.IdleTimeout = TimeSpan.FromMinutes(30); // ����� ��������� ������
    options.Cookie.HttpOnly = true; // ������ ���� ������ ������������ ��� JavaScript
    options.Cookie.IsEssential = true; // ���� ���������� ��� ���������������� ������
});
var app = builder.Build();
// ���������� ������
app.UseSession();

app.MapGet("/", () => "Hello World!");

app.Run();
