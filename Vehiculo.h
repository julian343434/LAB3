#include <iostream>
#include <queue>
#include <random>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <cmath>
#include <string>
// Clase Vehiculo
class Vehiculo
{
public:
    int categoria;
    float tarifa ;
    std::string nombreCategoria = "";
    // Constructor
    Vehiculo(int categoria);
    // Método para obtener la tarifa del peaje
    float obtenerTarifa();
    Vehiculo generarVehiculoAleatorio();
};
// Función para generar un vehículo aleatorio
