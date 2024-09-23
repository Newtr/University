using ServiceStack.Host;
using System.Web;
using Newtonsoft;

namespace Lab1
{
    public class HandlerHTTP : IHttpHandler
    {
        // Хранимое значение RESULT
        private int RESULT = 0;

        // Используем стек для поддержки PUSH/POP операций
        private Stack<int> stack = new Stack<int>();

        public void ProcessRequest(HttpContext context)
        {
            // Инициализация данных сессии
            context.Session.TryGetValue("RESULT", out byte[] resultBytes);
            RESULT = resultBytes != null ? BitConverter.ToInt32(resultBytes, 0) : 0;

            context.Session.TryGetValue("stack", out byte[] stackBytes);
            stack = stackBytes != null ? DeserializeStack(stackBytes) : new Stack<int>();

            // Обработка типов запросов
            switch (context.Request.Method)
            {
                case "GET":
                    HandleGetRequest(context);
                    break;
                case "POST":
                    HandlePostRequest(context);
                    break;
                case "PUT":
                    HandlePutRequest(context);
                    break;
                case "DELETE":
                    HandleDeleteRequest(context);
                    break;
                default:
                    context.Response.StatusCode = 405; // Method Not Allowed
                    break;
            }

            // Обновляем сессию перед завершением
            context.Session.Set("RESULT", BitConverter.GetBytes(RESULT));
            context.Session.Set("stack", SerializeStack(stack));
        }

        // Метод для сериализации стека в массив байтов
        private byte[] SerializeStack(Stack<int> stack)
        {
            using (var stream = new MemoryStream())
            {
                using (var writer = new BinaryWriter(stream))
                {
                    foreach (var item in stack)
                    {
                        writer.Write(item);
                    }
                }
                return stream.ToArray();
            }
        }

        // Метод для десериализации стека из массива байтов
        private Stack<int> DeserializeStack(byte[] bytes)
        {
            var stack = new Stack<int>();
            using (var stream = new MemoryStream(bytes))
            {
                using (var reader = new BinaryReader(stream))
                {
                    while (stream.Position < stream.Length)
                    {
                        stack.Push(reader.ReadInt32());
                    }
                }
            }
            return stack;
        }


        private void HandleGetRequest(HttpContext context)
        {
            // Возвращаем RESULT как JSON-объект
            context.Response.ContentType = "application/json";
            var jsonResult = new { RESULT };
            context.Response.WriteAsync(Newtonsoft.Json.JsonConvert.SerializeObject(jsonResult));
        }

        private void HandlePostRequest(HttpContext context)
        {
            // Получаем значение RESULT из параметров POST-запроса
            if (int.TryParse(context.Request.Form["RESULT"], out int newResult))
            {
                RESULT = newResult;
                context.Response.StatusCode = 200; // OK
            }
            else
            {
                context.Response.StatusCode = 400; // Bad Request
                context.Response.WriteAsync("Invalid RESULT value.");
            }
        }

        private void HandlePutRequest(HttpContext context)
        {
            // Добавляем элемент в стек
            if (int.TryParse(context.Request.Query["ADD"], out int addValue))
            {
                stack.Push(addValue);
                context.Response.StatusCode = 200; // OK
            }
            else
            {
                context.Response.StatusCode = 400; // Bad Request
                context.Response.WriteAsync("Invalid ADD value.");
            }
        }

        private void HandleDeleteRequest(HttpContext context)
        {
            // Удаляем элемент из стека (POP)
            if (stack.Count > 0)
            {
                int poppedValue = stack.Pop();
                RESULT += poppedValue;
                context.Response.StatusCode = 200; // OK
            }
            else
            {
                context.Response.StatusCode = 400; // Bad Request
                context.Response.WriteAsync("Stack is empty.");
            }
        }

        public bool IsReusable => false; // Обработчик нельзя переиспользовать
    }
}


