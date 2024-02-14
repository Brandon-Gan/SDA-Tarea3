#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "administradorneuronas.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conecta la señal del botón "Guardar" con la función correspondiente
    connect(ui->Guardar, SIGNAL(clicked()), this, SLOT(guardarDatosNeurona()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::guardarDatosNeurona()
{
    // Obtén los valores de los TextEdit
    int id = ui->NeuronaID->toPlainText().toInt();
    double voltaje = ui->Voltaje->toPlainText().toDouble();
    int x = ui->X->toPlainText().toInt();
    int y = ui->Y->toPlainText().toInt();
    int rojo = ui->rojo->toPlainText().toInt();
    int verde = ui->verde->toPlainText().toInt();
    int azul = ui->azul->toPlainText().toInt();

    // Crear run objeto Neurona con los datos recopilados
    Neurona nuevaNeurona(id, voltaje, x, y, rojo, verde, azul);

    // Agregar nueva neurona al AdministradorNeuronas
    AdministradorNeuronas::getInstance().agregar_final(nuevaNeurona);

}

void MainWindow::on_Mostrar_clicked()
{
    // limpia los datos para hacerlo mas comodo
    ui->plainTextEdit->clear();

    // Obtén las neuronas del AdministradorNeuronas
    const std::vector<Neurona>& neuronas = AdministradorNeuronas::getInstance().getNeuronas();

    ui->plainTextEdit->appendPlainText("-------------------------------");
    //muestra la información en el QPlainTextEdit
    for (const auto& neurona : neuronas) {
        ui->plainTextEdit->appendPlainText("Neurona ID: " + QString::number(neurona.getId()));
        ui->plainTextEdit->appendPlainText("Voltaje: " + QString::number(neurona.getVoltaje()));
        ui->plainTextEdit->appendPlainText("Posición X: " + QString::number(neurona.getPosX()));
        ui->plainTextEdit->appendPlainText("Posición Y: " + QString::number(neurona.getPosY()));
        ui->plainTextEdit->appendPlainText("Rojo: " + QString::number(neurona.getRed()));
        ui->plainTextEdit->appendPlainText("Verde: " + QString::number(neurona.getGreen()));
        ui->plainTextEdit->appendPlainText("Azul: " + QString::number(neurona.getBlue()));
        ui->plainTextEdit->appendPlainText("-------------------------------");
    }
}

