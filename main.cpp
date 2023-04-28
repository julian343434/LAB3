#include "Vehiculo.cpp"
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
        if (vehiculo.categoria <= 1) {
            cola1.push(vehiculo);
        } else {
            cola2.push(vehiculo);
        }
    }

    // Inicializar contador de tiempo
    int tiempo_total = 0;

    // Loop principal
    while (tiempo_total < 120) {
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
        int num_aleatorio = std::rand() % 2; // Generar número aleatorio entre 0 y 1
        if (std::round(num_aleatorio) == 0) { // Redondear al entero más cercano
            cola1.push(vehiculo);
        } else {
            cola2.push(vehiculo);
        }

        // Esperar un tiempo aleatorio entre 1 y 10 segundos
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, 10);
        int tiempo = distr(gen);
        tiempo_total += tiempo;
        std::this_thread::sleep_for(std::chrono::seconds(tiempo));
    }

    // Finalizar ncurses
    endwin();

    return 0;
}
