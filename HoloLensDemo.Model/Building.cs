using System;
using System.Collections.Generic;

namespace HoloLensDemo.Model
{
    public class Building
    {
        public string name { get; set; }
        public string Id { get; set; }
        public string address { get; set; }
        public List<Floor> floors { get; set; }
        public DateTime timeStamp { get; set; }
    }
}