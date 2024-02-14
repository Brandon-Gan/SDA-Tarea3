#ifndef ADMINISTRADORNEURONAS_H
#define ADMINISTRADORNEURONAS_H

#include "neurona.h"
#include <vector>

class AdministradorNeuronas {
private:
    std::vector<Neurona> neuronas;

public:
    void agregar_inicio(const Neurona& neurona);
    void agregar_final(const Neurona& neurona);
    void mostrar();
    static AdministradorNeuronas& getInstance();

    const std::vector<Neurona>& getNeuronas() const {
        return neuronas;
    }

};

#endif // ADMINISTRADORNEURONAS_H
