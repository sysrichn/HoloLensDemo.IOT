# HoloLensDemo.IoT
1. HoloLensDemo.Model - consists of all entities related to building, floors and rooms
2. HoloLensDemo.Simulator - consists of  simulator for building sensors, and pushes data to Azure IOT Hub on a periodic interval
3. HoloLensDemo.Web - Web API project, reads data from the cosmos DB, and exposes as an API
To make it work, make following configuration changes;
1. Within HoloLensDemo.Simulator\Program.cs file, update following IOT Hub connection settings,
        private const string EhConnectionString = "[Connection string for IOT Hub]";
        private const string EhEntityPath = "[IOT Hub Entity Path Name]";
2. Within HoloLensDemo.Web\Data\BuildingCreator.cs, update following settings related to DocumentDB;
        private const string EndpointUri = "https://[Cosmos DB Name].documents.azure.com:443/";
        private const string PrimaryKey = "[Primary Key Cosmos DB]";
        private const string DatabaseName = "[Database name Cosmos DB]";
        private const string CollectionName = "[Collection name Cosmos DB]"
