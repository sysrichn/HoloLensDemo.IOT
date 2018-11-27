namespace HoloLensDemo.Simulator
{
    using HoloLensDemo.Model;
    using System;
    using System.Collections.Generic;

    /// <summary>
    /// Building Creator
    /// </summary>
    public static class BuildingCreator
    {
        /// <summary>
        /// Loads the buildings data.
        /// </summary>
        /// <param name="buildingNumber">The building number.</param>
        /// <returns>Load simulator data.</returns>
        public static Building LoadBuildingsData(int buildingNumber)
        {
            Random rnd = new Random();

            Room roomA = new Room { name = "room-a", temperature = 24, humidity = 56 };
            Room roomB = new Room { name = "room-b", temperature = 24, humidity = 57 };
            Room roomC = new Room { name = "room-c", temperature = 28, humidity = 56 };
            Room roomD = new Room { name = "room-d", temperature = 24, humidity = 58 };
            
            Floor firstFlr = new Floor { name = "First" };
            firstFlr.rooms = new List<Room>();
            firstFlr.rooms.Add(roomA);

            Floor secondFlr = new Floor { name = "Second" };
            secondFlr.rooms = new List<Room>();
            secondFlr.rooms.Add(roomB);
            
            Floor thirdFlr = new Floor { name = "Third" };
            thirdFlr.rooms = new List<Room>();
            thirdFlr.rooms.Add(roomC);
            
            Floor fourthFlr = new Floor { name = "Fourth" };
            fourthFlr.rooms = new List<Room>();
            fourthFlr.rooms.Add(roomD);
           

            Building building = new Building { Id = "18", address = "3350 157th Place NE, Redmond, WA", name = "Microsoft", timeStamp = DateTime.Now };

            building.floors = new List<Floor>();

            building.floors.Add(firstFlr);
            building.floors.Add(secondFlr);
            building.floors.Add(thirdFlr);
            building.floors.Add(fourthFlr);


            return building;
        }
    }
}