using System;

namespace Aircompany.Planes
{
    public class PassengerPlane : Plane
    {
        private readonly int _passengersCapacity;

        public PassengerPlane(string model, int maxSpeed, int maxFlightDistance, int maxLoadCapacity, int passengersCapacity)
            : base(model, maxSpeed, maxFlightDistance, maxLoadCapacity)
        {
            _passengersCapacity = passengersCapacity;
        }

        public override bool Equals(object obj)
        {
            var plane = obj as PassengerPlane;
            return plane != null &&
                   base.Equals(obj) &&
                   _passengersCapacity == plane._passengersCapacity;
        }

        public override int GetHashCode()
        {
            var hashCode = 751774561;
            hashCode = hashCode * -1521134295 + base.GetHashCode();
            hashCode = hashCode * -1521134295 + _passengersCapacity.GetHashCode();
            return hashCode;
        }

        public int GetPassengersCapacity()
        {
            return _passengersCapacity;
        }

        public override string ToString()
        {
            return base.ToString().Replace("}",
                    ", passengersCapacity=" + _passengersCapacity +
                    '}');
        }
    }
}

//Изменено имя метода PassengersCapacityIs на GetPassengersCapacity,
//чтобы сделать его более понятным и соответствующим соглашениям о стиле кода C#.
//Также модификатор доступа поля _passengersCapacity на private readonly,
//чтобы сделать его доступным только для чтения и ограничить его область видимости до класса PassengerPlane.
//Это помогает предотвратить нежелательные изменения значения этого поля.