namespace HoloLensDemo.Web
{
    using HoloLensDemo.Model;
    using Microsoft.Azure.Documents.Client;
    using System;
    using System.Linq;

    /// <summary>
    /// Building Creator Class
    /// </summary>
    public class BuildingCreator
    {
        private const string EndpointUri = "https://[NAME].documents.azure.com:443/";
        private const string PrimaryKey = "SECRET KEY";
        private DocumentClient client;
        private const string DatabaseName = "Buildings";
        private const string CollectionName = "DevicesCollection";

        /// <summary>
        /// Loads the building.
        /// </summary>
        /// <param name="buildingNumber">The building number.</param>
        /// <returns>Retuns Building object.</returns>
        public Building LoadBuilding(string buildingNumber)
        {
            this.client = new DocumentClient(new Uri(EndpointUri), PrimaryKey);

            // Set some common query options
            FeedOptions queryOptions = new FeedOptions { MaxItemCount = -1 };

            // Here we find the Andersen family via its LastName
            IQueryable<Building> buildingQuery = this.client.CreateDocumentQuery<Building>(
                    UriFactory.CreateDocumentCollectionUri(DatabaseName, CollectionName), queryOptions)
                    .Where(f => f.Id == buildingNumber);

            // The query is executed synchronously here, but can also be executed asynchronously via the IDocumentQuery<T> interface
            foreach (Building building in buildingQuery)
            {
                return building;
            }

            return null;
        }
    }
}