#include <iostream>
#include <string>
class Vehiculo {
    static int cont_vehiculos;
    public:
        float precio;
        Vehiculo();
        ~Vehiculo();
        void generaVehiculo();        
};
class Moto : public Vehiculo{
    static int contMoto;
    private:
        char miChar;
    public :
        Moto();
        ~Moto();
};

