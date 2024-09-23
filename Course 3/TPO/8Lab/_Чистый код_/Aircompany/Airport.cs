using Aircompany.Models;
using Aircompany.Planes;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Aircompany
{
    public class Airport
    {
        private readonly List<Plane> _planes;

        public Airport(IEnumerable<Plane> planes)
        {
            _planes = planes.ToList();
        }

        public List<PassengerPlane> GetPassengerPlanes()
        {
            return _planes.OfType<PassengerPlane>().ToList();
        }

        public List<MilitaryPlane> GetMilitaryPlanes()
        {
            return _planes.OfType<MilitaryPlane>().ToList();
        }

        public PassengerPlane GetPassengerPlaneWithMaxPassengersCapacity()
        {
            return GetPassengerPlanes().OrderByDescending(p => p.GetPassengersCapacity()).FirstOrDefault();
        }

        public List<MilitaryPlane> GetTransportMilitaryPlanes()
        {
            return GetMilitaryPlanes().Where(p => p.GetPlaneType() == MilitaryType.TRANSPORT).ToList();
        }

        public Airport SortByMaxDistance()
        {
            return new Airport(_planes.OrderBy(p => p.GetMaxFlightDistance()));
        }

        public Airport SortByMaxSpeed()
        {
            return new Airport(_planes.OrderBy(p => p.GetMaxSpeed()));
        }

        public Airport SortByMaxLoadCapacity()
        {
            return new Airport(_planes.OrderBy(p => p.GetMaxLoadCapacity()));
        }

        public IEnumerable<Plane> GetPlanes()
        {
            return _planes;
        }

        public override string ToString()
        {
            return "Airport{" +
                    "planes=" + string.Join(", ", _planes.Select(x => x.GetModel())) +
                    '}';
        }
    }
}

//Изменён модификатор доступа поля _planes на private readonly,
//чтобы сделать его доступным только для чтения и ограничить его область видимости до класса Airport.
//Это помогает предотвратить нежелательные изменения значения этого поля.
//Также добавил LINQ для упрощения и улучшения читаемости методов
//GetPassengerPlanes, GetMilitaryPlanes, GetPassengerPlaneWithMaxPassengersCapacity и GetTransportMilitaryPlanes.
//Это делает код более кратким и понятным.
//Кроме того, изменил имена методов
//MAXFlightDistance, GetMS и MAXLoadCapacity на GetMaxFlightDistance, GetMaxSpeed и GetMaxLoadCapacity соответственно,
//чтобы сделать их более понятными и соответствующими соглашениям о стиле кода C#.