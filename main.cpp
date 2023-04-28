#include <iostream>
#include <queue>
#include <random>
#include <thread>
#include <chrono>
#include <ncurses.h>

// Clase Vehiculo
class Vehiculo {
public:
    int categoria; // Categoría del vehículo

    // Constructor
    Vehiculo(int cat) {
        categoria = cat;
    }

    // Método para obtener la tarifa del peaje
    float obtenerTarifa() {
        float tarifa;
        switch (categoria) {
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
};

// Función para generar un vehículo aleatorio
Vehiculo generarVehiculoAleatorio() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 3);

    int categoria = distr(gen);
    Vehiculo vehiculo(categoria);

    return vehiculo;
}

int main() {
    // Inicializar ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    // Crear colas
    std::queue<Vehiculo> cola1;
    std::queue<Vehiculo> cola2;

    // Generar vehículos aleatorios y agregar a colas
    for (int i = 0; i < 10; i++) {
        Vehiculo vehiculo = generarVehiculoAleatorio();
        if (vehiculo.categoria == 1) {
            cola1.push(vehiculo);
        } else {
            cola2.push(vehiculo);
        }
    }

    // Loop principal
    while (true) {
        // Limpiar pantalla
        clear();

        // Mostrar colas
        mvprintw(0, 0, "Cola 1:");
        int i = 1;
        std::queue<Vehiculo> cola1_temp = cola1;
        while (!cola1_temp.empty()) {
            Vehiculo vehiculo = cola1_temp.front();
            mvprintw(i, 0, "Categoria %d", vehiculo.categoria);
            cola1_temp.pop();
            i++;
        }
        mvprintw(i+1, 0, "---------------------");
        mvprintw(i+2, 0, "Cola 2:");
        int j = i+3;
        std::queue<Vehiculo> cola2_temp = cola2;
        while (!cola2_temp.empty()) {
            Vehiculo vehiculo = cola2_temp.front();
            mvprintw(j, 0, "Categoria %d", vehiculo.categoria);
            cola2_temp.pop();
            j++;
        }

        // Actualizar pantalla
        refresh();

        // Generar vehículo aleatorio y agregar a cola
        Vehiculo vehiculo = generarVehiculoAleatorio();
        if (vehiculo.categoria == 1) {
            cola1.push(vehiculo);
        } else {
            cola2.push(vehiculo);
        }

        // Esperar un tiempo
    // Esperar un tiempo aleatorio entre 1 y 10 segundos
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 10);
    int tiempo = distr(gen);
    std::this_thread::sleep_for(std::chrono::seconds(tiempo));
}

// Finalizar ncurses
endwin();

return 0;
}
