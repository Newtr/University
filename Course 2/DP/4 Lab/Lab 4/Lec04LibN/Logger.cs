using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lec04LibN
{
    public partial class Logger : ILogger
    {
        private static Logger logger;
        private string PrivlogFileName;
        private int PrivlogID;
        private List<string> logsNamespaces;

        private Logger()
        {
            PrivlogFileName = $"../../../LOG_{DateTime.Now.ToString("yyyyMMdd-hhmmss")}.txt";
            PrivlogID = 0;
            logsNamespaces = new List<string>();
        }

        public static ILogger Create()
        {
            if (logger is not null)
            {
                //Console.WriteLine("LOGGER ALREDY EXIST");
                return logger;
            }

            logger = new Logger();

            return logger;
        }

        public void Start(string title)
        {
            PrivlogID++;

            logsNamespaces.Add(title);

            WriteToLogFile("STRT", $" Добавлен namespace {title}");
        }

        public void Stop()
        {
            PrivlogID++;

            string removedNamespace = string.Empty;

            if (logsNamespaces.Count > 0)
            {
                removedNamespace = logsNamespaces.Last();

                logsNamespaces.RemoveAt(logsNamespaces.Count - 1);

                WriteToLogFile("STOP", $" Удален namespace {removedNamespace}");

                return;
            }

            WriteToLogFile("STOP", $"No namespaces to remove");
        }

        public void Log(string message)
        {
            PrivlogID++;

            WriteToLogFile("INFO", message);
        }

        private void WriteToLogFile(string logTypeName, string message)
        {
            string logID = PrivlogID.ToString("D6");
            string logNamespace = string.Empty;
            foreach (var namespc in logsNamespaces)
            {
                logNamespace += $"{namespc}:";
            }    

            string log = $"{logID} - {DateTime.Now} - {logTypeName} {logNamespace}   {message}";

            if (File.Exists(PrivlogFileName))
            {
                using (StreamWriter sw = File.AppendText(PrivlogFileName))
                {
                    sw.WriteLine(log);
                }

                return;
            }

            using (StreamWriter sw = File.CreateText(PrivlogFileName))
            {
                sw.WriteLine($"{logID} - {DateTime.Now} - INIT");
            }

            PrivlogID++;

            WriteToLogFile(logTypeName, message);
        }
    }
}
