#ifndef NEURONA_H
#define NEURONA_H

class Neurona {
private:
    int id;
    double voltaje;
    int pos_x;
    int pos_y;
    int red;
    int green;
    int blue;

public:
    Neurona(int neuron_id, double voltage, int x, int y, int r, int g, int b);
    void print_info() const;  // Marcar la función como constante.

    int getId() const { return id; }
    double getVoltaje() const { return voltaje; }
    int getPosX() const { return pos_x; }
    int getPosY() const { return pos_y; }
    int getRed() const { return red; }
    int getGreen() const { return green; }
    int getBlue() const { return blue; }
};

#endif // NEURONA_H
