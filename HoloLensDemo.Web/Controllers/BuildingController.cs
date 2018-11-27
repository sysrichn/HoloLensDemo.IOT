namespace HoloBlueprint.Sensors.WebAPI.Controllers
{
    using HoloLensDemo.Model;
    using HoloLensDemo.Web;
    using System.Web.Http;

    /// <summary>
    /// Building Control API Class
    /// </summary>
    /// <seealso cref="System.Web.Http.ApiController" />
    public class BuildingController : ApiController
    {
        /// <summary>
        /// Gets the building.
        /// </summary>
        /// <returns>Building object</returns>
        public IHttpActionResult GetBuilding()
        {
            string buildingId = "18";
            Building building = new BuildingCreator().LoadBuilding(buildingId);

            if (building == null)
            {
                return NotFound();
            }

            return (Ok(building));
        }

        /// <summary>
        /// Gets the building.
        /// </summary>
        /// <param name="id">The identifier.</param>
        /// <returns>Building object</returns>
        public IHttpActionResult GetBuilding(int id)
        {
            Building building = new BuildingCreator().LoadBuilding(id.ToString());

            if (building == null)
            {
                return NotFound();
            }

            return (Ok(building));
        }
    }
}
