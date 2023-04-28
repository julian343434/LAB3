#include <iostream>
#include <queue>
#include <random>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <cmath>
#include <string>
#include "Vehiculo.h"
float Vehiculo::obtenerTarifa(){
        float tarifa;
        switch (categoria)
        {
        case 1:
            tarifa = 5.0;
            break;
        case 2:
            tarifa = 10.0;
            break;
        case 3:
            tarifa = 2.0;
            break;
        default:
            tarifa = 0.0;
        }
        return tarifa;
    }
Vehiculo:: Vehiculo(int categoria){
    this->categoria = categoria;
    switch(categoria){
            case 1:
                this->nombreCategoria= "Moto";
                this->tarifa= 0.0;
                break;
            case 2:
                this->nombreCategoria = "categoria 1";
                this->tarifa = 10.0;
                break;
            case 3:
                this->nombreCategoria= "categoria 2";
                this->tarifa = 100.0;
                break;
            default:
                break;
        }
}
Vehiculo generarVehiculoAleatorio() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 3);

    int categoria = distr(gen);
    Vehiculo vehiculo(categoria);

    return vehiculo;
}