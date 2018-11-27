namespace HoloLensDemo.Simulator
{
    using HoloLensDemo.Model;
    using Microsoft.Azure.EventHubs;
    using System;
    using System.Text;
    using System.Threading.Tasks;

    /// <summary>
    /// Simulator class
    /// </summary>
    class Program
    {
        private const string EhConnectionString = "Endpoint=sb://......."; //REPLACE WITH YOUR CONNECTION STRING
        private const string EhEntityPath = "hololensdemo"; //REPLACE WITH YOUR HUB NAME

        static void Main(string[] args)
        {
            Building building = BuildingCreator.LoadBuildingsData(0);
            string data = Newtonsoft.Json.JsonConvert.SerializeObject(building);
            SendMessagesToEventHub(2,building).Wait();
            Console.WriteLine("Press any key to exit.");
            Console.ReadLine();
        }

        private static async Task SendMessagesToEventHub(int numMessagesToSend, Building building)
        {
            var connectionStringBuilder = new EventHubsConnectionStringBuilder(EhConnectionString)
            {
                EntityPath = EhEntityPath
            };

            var eventHubClient = EventHubClient.CreateFromConnectionString(connectionStringBuilder.ToString());



            for (var i = 0; i < numMessagesToSend; i++)
            {
                try
                {
                    var message = $"Message {i}";
                    Console.WriteLine($"Sending message: {message}");
                    await eventHubClient.SendAsync(new EventData(Encoding.UTF8.GetBytes(Newtonsoft.Json.JsonConvert.SerializeObject(building))));
                }
                catch (Exception exception)
                {
                    Console.WriteLine($"{DateTime.Now} > Exception: {exception.Message}");
                }

                await Task.Delay(1000);
            }

            Console.WriteLine($"{numMessagesToSend} messages sent.");
        }
    }
}
