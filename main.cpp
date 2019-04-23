#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h> // freeglut instead of glut because glut is deprecated
#include <iostream>

// proper Material class
#include "tools/Materials.h"

// proper Lighting class
#include "tools/Lighting.h"

using namespace std;

// window title
#define WINDOW_TITLE_PREFIX "3D design"

// default window's size, but these settings are override later
int
        CurrentWidth = 800,
        CurrentHeight = 600,
        WindowHandle = 0;

// frame-counter var
unsigned FrameCount = 0;

// default orthogonal view
GLfloat ortho[] = {-300, 300, -300, 300, -300, 300};

// 10, 230, 100
// Lighting constructor placed at center of the screen
Lighting light = Lighting(0, 0, abs(ortho[0]));

Materials materials;

// function prototypes
void Initialize(int, char*[]);
void InitWindow(int, char*[]);
void ResizeFunction(int, int);
void RenderFunction();
void TimerFunction(int);
void IdleFunction();
void display();

void lightKeys(unsigned char, int, int);

//draws
void plano3D();

void primero();

void primeroAlambrico();

void segundo();

void segundoAlambrico();

void tercero();

void pintarSuelo();

// entry point
int main(int argc, char* argv[])
{
    Initialize(argc, argv);

    glutMainLoop();

    exit(EXIT_SUCCESS);
}

// all drawings here
void display() {

    //light.activateLight();
    //light.glDisableLight();



    //primero();
    //primeroAlambrico();

    //segundo();
    //segundoAlambrico();

    //pintarSuelo();


    tercero();

}

//plano 3D para ubicar mejor
void plano3D() {

    materials.setMaterialColor(255, 255, 200, 5);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(300, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 300, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 300);
    glEnd();

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0101);    // Dotted stipple pattern for the lines
    glBegin(GL_LINES);

    glVertex3f(-300, 0, 0);
    glVertex3f(0, 0, 0);
    glColor3f(300.0, 0.0, 0.0);    // Red for y axis
    glVertex3f(0, 0, 0);
    glVertex3f(0, -300, 0);
    glColor3f(0.0, 0.0, 300.0);    // Blue for z axis
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, -300);
    glEnd();

    glDisable(GL_LINE_STIPPLE);    // Disable the line stipple
}

void primero() {

    //rotacion
    glRotated(45.0, 1.0, 0.0, 0.0);
    glRotated(30.0, 0.0, 1.0, 0.0);
    plano3D();
    glBegin(GL_QUADS);



    //para el techo flotante
    //cara de arriba (arriba)
    materials.setMaterialColor(142, 141, 155, 100);
    glVertex3f(100.0f, 280.0f, -100.0f);
    glVertex3f(-100.0f, 280.0f, -100.0f);
    glVertex3f(-100.0f, 280.0f, 100.0f);
    glVertex3f(100.0f, 280.0f, 100.0f);

    //cara de arriba (abajo)
    glVertex3f(100.0f, 265.0f, -100.0f);
    glVertex3f(-100.0f, 265.0f, -100.0f);
    glVertex3f(-100.0f, 265.0f, 100.0f);
    glVertex3f(100.0f, 265.0f, 100.0f);

    //cara de arriba (enfrente)
    glVertex3f(100.0f, 280.0f, 100.0f);
    glVertex3f(-100.0f, 280.0f, 100.0f);
    glVertex3f(-100.0f, 265.0f, 100.0f);
    glVertex3f(100.0f, 265.0f, 100.0f);

    //cara de arriba (izquierda)
    materials.setMaterialColor(90, 100, 110, 8);
    glVertex3f(-100.0f, 280.0f, 100.0f);
    glVertex3f(-100.0f, 280.0f, -100.0f);
    glVertex3f(-100.0f, 265.0f, -100.0f);
    glVertex3f(-100.0f, 265.0f, 100.0f);

    //cara de arriba (derecha)
    glVertex3f(100.0f, 280.0f, -100.0f);
    glVertex3f(100.0f, 280.0f, 100.0f);
    glVertex3f(100.0f, 265.0f, 100.0f);
    glVertex3f(100.0f, 265.0f, -100.0f);

    //cara de arriba (atras)
    glVertex3f(100.0f, 280.0f, -100.0f);
    glVertex3f(-100.0f, 280.0f, -100.0f);
    glVertex3f(-100.0f, 265.0f, -100.0f);
    glVertex3f(100.0f, 265.0f, -100.0f);
    //fin del techo flotante



    //suelo
    materials.setMaterialColor(142, 141, 155, 20);
    glVertex3f(100.0f, -100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, -100.0f);
    glVertex3f(100.0f, -100.0f, -100.0f);
    //fin del suelo :v

    // cara frente
    materials.setMaterialColor(88, 90, 103, 10);
    glVertex3f(100.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);
    glVertex3f(100.0f, -100.0f, 100.0f);

    //cara frente (adelante)
    glVertex3f(100.0f, 100.0f, 85.0f);
    glVertex3f(-100.0f, 100.0f, 85.0f);
    glVertex3f(-100.0f, -100.0f, 85.0f);
    glVertex3f(100.0f, -100.0f, 85.0f);

    //cara frente (arriba)
    glVertex3f(100.0f, 100.0f, 85.0f);
    glVertex3f(-100.0f, 100.0f, 85.0f);
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, 100.0f, 100.0f);
    //fin de cara enfrente

    // cara de atras
    //cara de atras (enfrente)
    materials.setMaterialColor(88, 90, 103, 10);
    glVertex3f(100.0f, -100.0f, -85.0f);
    glVertex3f(-100.0f, -100.0f, -85.0f);
    glVertex3f(-100.0f, 100.0f, -85.0f);
    glVertex3f(100.0f, 100.0f, -85.0f);

    //cara de atras (trasera)
    glVertex3f(100.0f, -100.0f, -100.0f);
    glVertex3f(-100.0f, -100.0f, -100.0f);
    glVertex3f(-100.0f, 100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, -100.0f);

    //cara de atras (arriba)
    glVertex3f(100.0f, 100.0f, -85.0f);
    glVertex3f(-100.0f, 100.0f, -85.0f);
    glVertex3f(-100.0f, 100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, -100.0f);
    //fin de cara de atras


    // cara izquierda
    //cara izquierda (adelante)
    materials.setMaterialColor(148, 148, 148, 0);
    glVertex3f(-85.0f, 100.0f, 100.0f);
    glVertex3f(-85.0f, 100.0f, -100.0f);
    glVertex3f(-85.0f, -100.0f, -100.0f);
    glVertex3f(-85.0f, -100.0f, 100.0f);

    //cara izquierda (atras)
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, 100.0f, -100.0f);
    glVertex3f(-100.0f, -100.0f, -100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);

    //cara izquierda (arriba)
    glVertex3f(-85.0f, 100.0f, -100.0f);
    glVertex3f(-100.0f, 100.0f, -100.0f);
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(-85.0f, 100.0f, 100.0f);

    //cara izquierda (enfrente)
    glVertex3f(-85.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);
    glVertex3f(-85.0f, -100.0f, 100.0f);
    //fin de cara izquierda

    // cara derecha
    materials.setMaterialColor(148, 148, 148, 100);
    glVertex3f(100.0f, 100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, -100.0f, 100.0f);
    glVertex3f(100.0f, -100.0f, -100.0f);

    //cara derecha (adelante)
    glVertex3f(85.0f, 100.0f, -100.0f);
    glVertex3f(85.0f, 100.0f, 100.0f);
    glVertex3f(85.0f, -100.0f, 100.0f);
    glVertex3f(85.0f, -100.0f, -100.0f);

    //cara derecha (arriba)
    glVertex3f(100.0f, 100.0f, -100.0f);
    glVertex3f(85.0f, 100.0f, -100.0f);
    glVertex3f(85.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, 100.0f, 100.0f);

    //cara derecha (enfrente)
    glVertex3f(85.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, -100.0f, 100.0f);
    glVertex3f(85.0f, -100.0f, 100.0f);
    //fin de la cara derecha

    //pared interna izquierda
    materials.setMaterialColor(90, 100, 110, 120);
    glVertex3f(-30.0f, -100.0f, -15.0f);
    glVertex3f(-85.0f, -100.0f, -15.0f);
    glVertex3f(-85.0f, 100.0f, -15.0f);
    glVertex3f(-30.0f, 100.0f, -15.0f);

    glVertex3f(-30.0f, -100.0f, -0.0f);
    glVertex3f(-85.0f, -100.0f, -0.0f);
    glVertex3f(-85.0f, 100.0f, -0.0f);
    glVertex3f(-30.0f, 100.0f, -0.0f);

    glVertex3f(-30.0f, 100.0f, -15.0f);
    glVertex3f(-85.0f, 100.0f, -15.0f);
    glVertex3f(-85.0f, 100.0f, 0.0f);
    glVertex3f(-30.0f, 100.0f, 0.0f);
    //fin pared interna izquierda


    //pared interna derecha
    materials.setMaterialColor(90, 100, 110, 120);
    glVertex3f(85.0f, -100.0f, -0.0f);
    glVertex3f(30.0f, -100.0f, -0.0f);
    glVertex3f(30.0f, 100.0f, -0.0f);
    glVertex3f(85.0f, 100.0f, -0.0f);

    glVertex3f(85.0f, -100.0f, -15.0f);
    glVertex3f(30.0f, -100.0f, -15.0f);
    glVertex3f(30.0f, 100.0f, -15.0f);
    glVertex3f(85.0f, 100.0f, -15.0f);

    glVertex3f(30.0f, 100.0f, -15.0f);
    glVertex3f(85.0f, 100.0f, -15.0f);
    glVertex3f(85.0f, 100.0f, 0.0f);
    glVertex3f(30.0f, 100.0f, 0.0f);
    //fin pared interna derecha
    glEnd();
}

void primeroAlambrico() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);

    //para el techo flotante
    //cara de arriba (arriba)
    materials.setMaterial(materials.BLACK_PLASTIC);
    glVertex3f(100.0f, 280.0f, -100.0f);
    glVertex3f(-100.0f, 280.0f, -100.0f);
    glVertex3f(-100.0f, 280.0f, 100.0f);
    glVertex3f(100.0f, 280.0f, 100.0f);

    //cara de arriba (abajo)
    glVertex3f(100.0f, 265.0f, -100.0f);
    glVertex3f(-100.0f, 265.0f, -100.0f);
    glVertex3f(-100.0f, 265.0f, 100.0f);
    glVertex3f(100.0f, 265.0f, 100.0f);

    //cara de arriba (enfrente)
    glVertex3f(100.0f, 280.0f, 100.0f);
    glVertex3f(-100.0f, 280.0f, 100.0f);
    glVertex3f(-100.0f, 265.0f, 100.0f);
    glVertex3f(100.0f, 265.0f, 100.0f);

    //cara de arriba (izquierda)
    glVertex3f(-100.0f, 280.0f, 100.0f);
    glVertex3f(-100.0f, 280.0f, -100.0f);
    glVertex3f(-100.0f, 265.0f, -100.0f);
    glVertex3f(-100.0f, 265.0f, 100.0f);

    //cara de arriba (derecha)
    glVertex3f(100.0f, 280.0f, -100.0f);
    glVertex3f(100.0f, 280.0f, 100.0f);
    glVertex3f(100.0f, 265.0f, 100.0f);
    glVertex3f(100.0f, 265.0f, -100.0f);

    //cara de arriba (atras)
    glVertex3f(100.0f, 280.0f, -100.0f);
    glVertex3f(-100.0f, 280.0f, -100.0f);
    glVertex3f(-100.0f, 265.0f, -100.0f);
    glVertex3f(100.0f, 265.0f, -100.0f);
    //fin del techo flotante



    //suelo
    glVertex3f(100.0f, -100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, -100.0f);
    glVertex3f(100.0f, -100.0f, -100.0f);
    //fin del suelo :v

    // cara frente
    glVertex3f(100.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);
    glVertex3f(100.0f, -100.0f, 100.0f);

    //cara frente (adelante)
    glVertex3f(100.0f, 100.0f, 85.0f);
    glVertex3f(-100.0f, 100.0f, 85.0f);
    glVertex3f(-100.0f, -100.0f, 85.0f);
    glVertex3f(100.0f, -100.0f, 85.0f);

    //cara frente (arriba)
    glVertex3f(100.0f, 100.0f, 85.0f);
    glVertex3f(-100.0f, 100.0f, 85.0f);
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, 100.0f, 100.0f);
    //fin de cara enfrente

    // cara de atras
    //cara de atras (enfrente)
    glVertex3f(100.0f, -100.0f, -85.0f);
    glVertex3f(-100.0f, -100.0f, -85.0f);
    glVertex3f(-100.0f, 100.0f, -85.0f);
    glVertex3f(100.0f, 100.0f, -85.0f);

    //cara de atras (trasera)

    glVertex3f(100.0f, -100.0f, -100.0f);
    glVertex3f(-100.0f, -100.0f, -100.0f);
    glVertex3f(-100.0f, 100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, -100.0f);

    //cara de atras (arriba)
    glVertex3f(100.0f, 100.0f, -85.0f);
    glVertex3f(-100.0f, 100.0f, -85.0f);
    glVertex3f(-100.0f, 100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, -100.0f);
    //fin de cara de atras


    // cara izquierda
    //cara izquierda (adelante)
    glVertex3f(-85.0f, 100.0f, 100.0f);
    glVertex3f(-85.0f, 100.0f, -100.0f);
    glVertex3f(-85.0f, -100.0f, -100.0f);
    glVertex3f(-85.0f, -100.0f, 100.0f);

    //cara izquierda (atras)
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, 100.0f, -100.0f);
    glVertex3f(-100.0f, -100.0f, -100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);

    //cara izquierda (arriba)
    glVertex3f(-85.0f, 100.0f, -100.0f);
    glVertex3f(-100.0f, 100.0f, -100.0f);
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(-85.0f, 100.0f, 100.0f);

    //cara izquierda (enfrente)
    glVertex3f(-85.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);
    glVertex3f(-85.0f, -100.0f, 100.0f);
    //fin de cara izquierda

    // cara derecha
    glVertex3f(100.0f, 100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, -100.0f, 100.0f);
    glVertex3f(100.0f, -100.0f, -100.0f);

    //cara derecha (adelante)
    glVertex3f(85.0f, 100.0f, -100.0f);
    glVertex3f(85.0f, 100.0f, 100.0f);
    glVertex3f(85.0f, -100.0f, 100.0f);
    glVertex3f(85.0f, -100.0f, -100.0f);

    //cara derecha (arriba)
    glVertex3f(100.0f, 100.0f, -100.0f);
    glVertex3f(85.0f, 100.0f, -100.0f);
    glVertex3f(85.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, 100.0f, 100.0f);

    //cara derecha (enfrente)
    glVertex3f(85.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, -100.0f, 100.0f);
    glVertex3f(85.0f, -100.0f, 100.0f);
    //fin de la cara derecha

    //pared interna izquierda
    glVertex3f(-30.0f, -100.0f, -15.0f);
    glVertex3f(-85.0f, -100.0f, -15.0f);
    glVertex3f(-85.0f, 100.0f, -15.0f);
    glVertex3f(-30.0f, 100.0f, -15.0f);

    glVertex3f(-30.0f, -100.0f, -0.0f);
    glVertex3f(-85.0f, -100.0f, -0.0f);
    glVertex3f(-85.0f, 100.0f, -0.0f);
    glVertex3f(-30.0f, 100.0f, -0.0f);

    glVertex3f(-30.0f, 100.0f, -15.0f);
    glVertex3f(-85.0f, 100.0f, -15.0f);
    glVertex3f(-85.0f, 100.0f, 0.0f);
    glVertex3f(-30.0f, 100.0f, 0.0f);
    //fin pared interna izquierda


    //pared interna derecha
    glVertex3f(85.0f, -100.0f, -0.0f);
    glVertex3f(30.0f, -100.0f, -0.0f);
    glVertex3f(30.0f, 100.0f, -0.0f);
    glVertex3f(85.0f, 100.0f, -0.0f);

    glVertex3f(85.0f, -100.0f, -15.0f);
    glVertex3f(30.0f, -100.0f, -15.0f);
    glVertex3f(30.0f, 100.0f, -15.0f);
    glVertex3f(85.0f, 100.0f, -15.0f);

    glVertex3f(30.0f, 100.0f, -15.0f);
    glVertex3f(85.0f, 100.0f, -15.0f);
    glVertex3f(85.0f, 100.0f, 0.0f);
    glVertex3f(30.0f, 100.0f, 0.0f);
    //fin pared interna derecha
    glEnd();
}

void segundo() {
    light.setPosition(300, 300, 275);

    //plano3D();
    glBegin(GL_QUADS);
    //para la lampara
    materials.setMaterialColor(255, 255, 255, 5);
    glVertex3f(30.0f, 140.0f, -100.0f);
    glVertex3f(-30.0f, 140.0f, -100.0f);
    glVertex3f(-35.0f, 180.0f, -100.0f);
    glVertex3f(35.0f, 180.0f, -100.0f);
    glPopMatrix();

    //para el techo
    materials.setMaterialColor(88, 99, 82, 20);
    glVertex3f(100.0f, 100.0f, -300.0f);
    glVertex3f(-100.0f, 100.0f, -300.0f);
    glVertex3f(-150.0f, 300.0f, 300.0f);
    glVertex3f(150.0f, 300.0f, 300.0f);
    glPopMatrix();

    //para el suelo
    //materials.setMaterial(materials.BLACK_PLASTIC);
    materials.setMaterialColor(170, 183, 173, 10);
    glVertex3f(100.0f, -100.0f, -300.0f);
    glVertex3f(-100.0f, -100.0f, -300.0f);
    glVertex3f(-300.0f, -300.0f, 300.0f);
    glVertex3f(300.0f, -300.0f, 300.0f);
    glPopMatrix();

    //oara el fondo del cuarto
    materials.setMaterialColor(179, 192, 182, 20);
    glVertex3f(100.0f, -100.0f, -200.0f);
    glVertex3f(-100.0f, -100.0f, -200.0f);
    glVertex3f(-100.0f, 100.0f, -200.0f);
    glVertex3f(100.0f, 100.0f, -200.0f);
    glPopMatrix();

    //para la pared izquierda roja
    materials.setMaterialColor(119, 25, 21, 10);
    glVertex3f(-300.0f, 300.0f, 300.0f);
    glVertex3f(-300.0f, -300.0f, 300.0f);
    glVertex3f(-100.0f, -300.0f, -300.0f);
    glVertex3f(-100.0f, 300.0f, -300.0f);
    glPopMatrix();

    //para la pared derecha verde
    materials.setMaterialColor(84, 157, 16, 10);
    glVertex3f(300.0f, 300.0f, 300.0f);
    glVertex3f(300.0f, -300.0f, 300.0f);
    glVertex3f(100.0f, -300.0f, -300.0f);
    glVertex3f(100.0f, 300.0f, -300.0f);
    glPopMatrix();

    materials.setMaterialColor(148, 153, 147, 30);
    //Cubo de enfrente
    glVertex3f(60.0f, -120.0f, 150.0f);
    glVertex3f(60.0f, -300.0f, 200.0f);
    glVertex3f(120.0f, -300.0f, 200.0f);
    glVertex3f(120.0f, -120.0f, 150.0f);


    glVertex3f(50.0f, -110.0f, 150.0f);
    glVertex3f(50.0f, -300.0f, 100.0f);
    glVertex3f(60.0f, -300.0f, 200.0f);
    glVertex3f(60.0f, -120.0f, 150.0f);

    glVertex3f(60.0f, -120.0f, 100.0f);
    glVertex3f(120.0f, -120.0f, 100.0f);
    glVertex3f(110.0f, -110.0f, 100.0f);
    glVertex3f(50.0f, -110.0f, 100.0f);
    glPopMatrix();

    //Cubo de atras
    materials.setMaterialColor(159, 168, 140, 10);
    glVertex3f(-50.0f, -120.0f, 150.0f);
    glVertex3f(-50.0f, -50.0f, 200.0f);
    glVertex3f(-100.0f, -50.0f, 200.0f);
    glVertex3f(-100.0f, -120.0f, 150.0f);


    glVertex3f(-40.0f, -110.0f, 150.0f);
    glVertex3f(-40.0f, -40.0f, 100.0f);
    glVertex3f(-50.0f, -50.0f, 200.0f);
    glVertex3f(-50.0f, -120.0f, 150.0f);

    glVertex3f(-50.0f, -50.0f, 100.0f);
    glVertex3f(-100.0f, -50.0f, 100.0f);
    glVertex3f(-90.0f, -40.0f, 100.0f);
    glVertex3f(-40.0f, -40.0f, 100.0f);
    glPopMatrix();
    glEnd();
}

void segundoAlambrico() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
    materials.setMaterial(materials.BLACK_PLASTIC);
    //para la lampara
    glVertex3f(30.0f, 140.0f, -100.0f);
    glVertex3f(-30.0f, 140.0f, -100.0f);
    glVertex3f(-35.0f, 180.0f, -100.0f);
    glVertex3f(35.0f, 180.0f, -100.0f);


    //para el techo
    glVertex3f(100.0f, 100.0f, -300.0f);
    glVertex3f(-100.0f, 100.0f, -300.0f);
    glVertex3f(-150.0f, 300.0f, 300.0f);
    glVertex3f(150.0f, 300.0f, 300.0f);

    //para el suelo
    glVertex3f(100.0f, -100.0f, -300.0f);
    glVertex3f(-100.0f, -100.0f, -300.0f);
    glVertex3f(-300.0f, -300.0f, 300.0f);
    glVertex3f(300.0f, -300.0f, 300.0f);


    //oara el fondo del cuarto
    glVertex3f(100.0f, -100.0f, -200.0f);
    glVertex3f(-100.0f, -100.0f, -200.0f);
    glVertex3f(-100.0f, 100.0f, -200.0f);
    glVertex3f(100.0f, 100.0f, -200.0f);


    //para la pared izquierda roja
    glVertex3f(-300.0f, 300.0f, 300.0f);
    glVertex3f(-300.0f, -300.0f, 300.0f);
    glVertex3f(-100.0f, -300.0f, -300.0f);
    glVertex3f(-100.0f, 300.0f, -300.0f);


    //para la pared derecha verde
    glVertex3f(300.0f, 300.0f, 300.0f);
    glVertex3f(300.0f, -300.0f, 300.0f);
    glVertex3f(100.0f, -300.0f, -300.0f);
    glVertex3f(100.0f, 300.0f, -300.0f);
    glPopMatrix();

    //Cubo de enfrente
    glVertex3f(60.0f, -120.0f, 150.0f);
    glVertex3f(60.0f, -300.0f, 200.0f);
    glVertex3f(120.0f, -300.0f, 200.0f);
    glVertex3f(120.0f, -120.0f, 150.0f);


    glVertex3f(50.0f, -110.0f, 150.0f);
    glVertex3f(50.0f, -300.0f, 100.0f);
    glVertex3f(60.0f, -300.0f, 200.0f);
    glVertex3f(60.0f, -120.0f, 150.0f);

    glVertex3f(60.0f, -120.0f, 100.0f);
    glVertex3f(120.0f, -120.0f, 100.0f);
    glVertex3f(110.0f, -110.0f, 100.0f);
    glVertex3f(50.0f, -110.0f, 100.0f);


    //Cubo de atras
    glVertex3f(-50.0f, -120.0f, 150.0f);
    glVertex3f(-50.0f, -50.0f, 200.0f);
    glVertex3f(-100.0f, -50.0f, 200.0f);
    glVertex3f(-100.0f, -120.0f, 150.0f);


    glVertex3f(-40.0f, -110.0f, 150.0f);
    glVertex3f(-40.0f, -40.0f, 100.0f);
    glVertex3f(-50.0f, -50.0f, 200.0f);
    glVertex3f(-50.0f, -120.0f, 150.0f);

    glVertex3f(-50.0f, -50.0f, 100.0f);
    glVertex3f(-100.0f, -50.0f, 100.0f);
    glVertex3f(-90.0f, -40.0f, 100.0f);
    glVertex3f(-40.0f, -40.0f, 100.0f);
    glPopMatrix();
    glEnd();
}

void tercero() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);

    int d = 20, p, gx = 0, hy = 0, hxc = 495, gyc = 795, ha, gb;
    /* clear all pixels */
    glClear(GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/

//wall left-right
    glColor3ub(105, 87, 62);
    glBegin(GL_POLYGON);
    glVertex3f(0, 250, 0);
    glVertex3f(390, 350, 0);
    glVertex3f(390, 1000, 0);
    glVertex3f(0, 1000, 0);
    glEnd();

//wall right-left
    glColor3ub(131, 108, 92);
    glBegin(GL_POLYGON);
    glVertex3f(390, 350, 0);
    glVertex3f(1000, 250, 0);
    glVertex3f(1000, 1000, 0);
    glVertex3f(390, 1000, 0);
    glEnd();

//photo frame - outer
    glColor3ub(255, 108, 92);
    glBegin(GL_POLYGON);
    glVertex3f(450, 700, 0);
    glVertex3f(540, 700, 0);
    glVertex3f(540, 870, 0);
    glVertex3f(450, 870, 0);
    glEnd();

//photo frame - inner
    glColor3ub(178, 235, 242);
    glBegin(GL_POLYGON);
    glVertex3f(455, 705, 0);
    glVertex3f(535, 705, 0);
    glVertex3f(535, 865, 0);
    glVertex3f(455, 865, 0);
    glEnd();

//photo frame - man
    glColor3ub(171, 39, 176);
    glBegin(GL_POLYGON);
    glVertex3f(455, 705, 0);
    glVertex3f(535, 705, 0);
    glVertex3f(535, 745, 0);
    glVertex3f(525, 770, 0);
    glVertex3f(465, 770, 0);
    glVertex3f(455, 745, 0);
    glEnd();


//photo frame - man color
    glColor3ub(178, 235, 242);
    glBegin(GL_POLYGON);
    glVertex3f(485, 770, 0);
    glVertex3f(495, 750, 0);
    glVertex3f(505, 770, 0);
    glEnd();

//photo frame - man head
    glColor3ub(97, 97, 97);
    glBegin(GL_POLYGON);
    glVertex3f(485, 770, 0);
    glVertex3f(495, 750, 0);
    glVertex3f(505, 770, 0);
    glVertex3f(505, 795, 0);
    glVertex3f(485, 795, 0);
    glEnd();

//roof  top
    glColor3ub(155, 142, 126);
    glBegin(GL_POLYGON);
    glVertex3f(650, 1000, 0);
    glVertex3f(390, 950, 0);
    glVertex3f(180, 1000, 0);
    glEnd();

//wall right-right
    glColor3ub(195, 182, 166);
    glBegin(GL_POLYGON);
    glVertex3f(600, 300, 0);
    glVertex3f(1000, 250, 0);
    glVertex3f(1000, 1000, 0);
    glVertex3f(600, 1000, 0);
    glEnd();

//clock outer
    glColor3ub(55, 71, 79);
    glBegin(GL_POLYGON);
    glVertex3f(680, 800, 0);
    glVertex3f(630, 800, 0);
    glVertex3f(630, 900, 0);
    glVertex3f(680, 900, 0);
    glEnd();
//clock inner
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(675, 805, 0);
    glVertex3f(635, 805, 0);
    glVertex3f(635, 895, 0);
    glVertex3f(675, 895, 0);
    glEnd();

//clock second
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
//glBegin(GL_POINT_SIZE);
    glVertex3f(655, 850, 0);
    glVertex3f(655, 890, 0);
    glEnd();


//clock minute
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
//glBegin(GL_POINT_SIZE);
    glVertex3f(655, 850, 0);
    glVertex3f(670, 850, 0);
    glEnd();


//clock hour
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
//glBegin(GL_POINT_SIZE);
    glVertex3f(655, 850, 0);
    glVertex3f(645, 810, 0);
    glEnd();

//ac front
    glColor3ub(120, 144, 156);
    glBegin(GL_POLYGON);
    glVertex3f(700, 850, 0);
    glVertex3f(850, 850, 0);
    glVertex3f(850, 900, 0);
    glVertex3f(700, 900, 0);
    glEnd();

//ac top
    glColor3ub(69, 90, 100);
    glBegin(GL_POLYGON);
    glVertex3f(710, 920, 0);
    glVertex3f(860, 920, 0);
    glVertex3f(850, 900, 0);
    glVertex3f(700, 900, 0);
    glEnd();

//ac bottom
    glColor3ub(69, 90, 100);
    glBegin(GL_POLYGON);
    glVertex3f(700, 850, 0);
    glVertex3f(850, 850, 0);
    glVertex3f(860, 840, 0);
    glVertex3f(710, 840, 0);
    glEnd();

//ac side
    glColor3ub(38, 50, 56);
    glBegin(GL_POLYGON);
    glVertex3f(860, 840, 0);
    glVertex3f(850, 850, 0);
    glVertex3f(850, 900, 0);
    glVertex3f(860, 920, 0);
    glEnd();


// left wall - right
    glColor3ub(201, 192, 183);
    glBegin(GL_POLYGON);
    glVertex3f(200, 250, 0);
    glVertex3f(0, 250, 0);
    glVertex3f(0, 1000, 0);
    glVertex3f(200, 1000, 0);
    glEnd();


//floor - white
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 250, 0);
    glVertex3f(390, 350, 0);
    glVertex3f(1000, 250, 0);
    glVertex3f(1000, 0, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 50, 0);
    glVertex3f(50, 50, 0);
    glVertex3f(50, 0, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0, 100, 0);
    glVertex3f(0, 150, 0);
    glVertex3f(50, 150, 0);
    glVertex3f(50, 100, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0, 200, 0);
    glVertex3f(0, 250, 0);
    glVertex3f(50, 250, 0);
    glVertex3f(50, 200, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(100, 0, 0);
    glVertex3f(100, 50, 0);
    glVertex3f(150, 50, 0);
    glVertex3f(150, 0, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(100, 100, 0);
    glVertex3f(100, 150, 0);
    glVertex3f(150, 150, 0);
    glVertex3f(150, 100, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(100, 200, 0);
    glVertex3f(100, 250, 0);
    glVertex3f(150, 250, 0);
    glVertex3f(150, 200, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(200, 0, 0);
    glVertex3f(200, 50, 0);
    glVertex3f(250, 50, 0);
    glVertex3f(250, 0, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(200, 100, 0);
    glVertex3f(200, 150, 0);
    glVertex3f(250, 150, 0);
    glVertex3f(250, 100, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(200, 200, 0);
    glVertex3f(200, 250, 0);
    glVertex3f(250, 250, 0);
    glVertex3f(250, 200, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(200, 300, 0);
    glVertex3f(200, 315, 0);
    glVertex3f(250, 315, 0);
    glVertex3f(250, 300, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(300, 0, 0);
    glVertex3f(300, 50, 0);
    glVertex3f(350, 50, 0);
    glVertex3f(350, 0, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(300, 300, 0);
    glVertex3f(300, 328, 0);
    glVertex3f(350, 340, 0);
    glVertex3f(350, 300, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(400, 0, 0);
    glVertex3f(400, 50, 0);
    glVertex3f(450, 50, 0);
    glVertex3f(450, 0, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(500, 0, 0);
    glVertex3f(500, 50, 0);
    glVertex3f(550, 50, 0);
    glVertex3f(550, 0, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(600, 0, 0);
    glVertex3f(600, 50, 0);
    glVertex3f(650, 50, 0);
    glVertex3f(650, 0, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(600, 100, 0);
    glVertex3f(600, 150, 0);
    glVertex3f(650, 150, 0);
    glVertex3f(650, 100, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(700, 0, 0);
    glVertex3f(700, 50, 0);
    glVertex3f(750, 50, 0);
    glVertex3f(750, 0, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(700, 100, 0);
    glVertex3f(700, 150, 0);
    glVertex3f(750, 150, 0);
    glVertex3f(750, 100, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(800, 0, 0);
    glVertex3f(800, 50, 0);
    glVertex3f(850, 50, 0);
    glVertex3f(850, 0, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(800, 100, 0);
    glVertex3f(800, 150, 0);
    glVertex3f(850, 150, 0);
    glVertex3f(850, 100, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(800, 200, 0);
    glVertex3f(800, 250, 0);
    glVertex3f(850, 250, 0);
    glVertex3f(850, 200, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(900, 0, 0);
    glVertex3f(900, 50, 0);
    glVertex3f(950, 50, 0);
    glVertex3f(950, 0, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(900, 100, 0);
    glVertex3f(900, 150, 0);
    glVertex3f(950, 150, 0);
    glVertex3f(950, 100, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(50, 50, 0);
    glVertex3f(50, 100, 0);
    glVertex3f(100, 100, 0);
    glVertex3f(100, 50, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(50, 150, 0);
    glVertex3f(50, 200, 0);
    glVertex3f(100, 200, 0);
    glVertex3f(100, 150, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(150, 50, 0);
    glVertex3f(150, 100, 0);
    glVertex3f(200, 100, 0);
    glVertex3f(200, 50, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(150, 150, 0);
    glVertex3f(150, 200, 0);
    glVertex3f(200, 200, 0);
    glVertex3f(200, 150, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(250, 50, 0);
    glVertex3f(250, 100, 0);
    glVertex3f(300, 100, 0);
    glVertex3f(300, 50, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(250, 250, 0);
    glVertex3f(250, 300, 0);
    glVertex3f(300, 300, 0);
    glVertex3f(300, 250, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(350, 50, 0);
    glVertex3f(350, 100, 0);
    glVertex3f(400, 100, 0);
    glVertex3f(400, 50, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(450, 50, 0);
    glVertex3f(450, 100, 0);
    glVertex3f(500, 100, 0);
    glVertex3f(500, 50, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(550, 50, 0);
    glVertex3f(550, 100, 0);
    glVertex3f(600, 100, 0);
    glVertex3f(600, 50, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(650, 50, 0);
    glVertex3f(650, 100, 0);
    glVertex3f(700, 100, 0);
    glVertex3f(700, 50, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(750, 50, 0);
    glVertex3f(750, 100, 0);
    glVertex3f(800, 100, 0);
    glVertex3f(800, 50, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(750, 150, 0);
    glVertex3f(750, 200, 0);
    glVertex3f(800, 200, 0);
    glVertex3f(800, 150, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(850, 50, 0);
    glVertex3f(850, 100, 0);
    glVertex3f(900, 100, 0);
    glVertex3f(900, 50, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(950, 50, 0);
    glVertex3f(950, 100, 0);
    glVertex3f(1000, 100, 0);
    glVertex3f(1000, 50, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(950, 200, 0);
    glVertex3f(950, 150, 0);
    glVertex3f(1000, 150, 0);
    glVertex3f(1000, 200, 0);
    glEnd();
//floor - black
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(950, 260, 0);
    glVertex3f(950, 250, 0);
    glVertex3f(1000, 250, 0);
    glVertex3f(1000, 260, 0);
    glEnd();

//window left
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(230, 500, 0);
    glVertex3f(325, 520, 0);
    glVertex3f(325, 900, 0);
    glVertex3f(230, 900, 0);
    glEnd();

//window left - right inner
    glColor3ub(131, 102, 92);
    glBegin(GL_POLYGON);
    glVertex3f(310, 890, 0);
    glVertex3f(325, 900, 0);
    glVertex3f(325, 520, 0);
    glVertex3f(310, 525, 0);
    glEnd();

//window left - bottom
    glColor3ub(195, 182, 166);
    glBegin(GL_POLYGON);
    glVertex3f(230, 500, 0);
    glVertex3f(325, 520, 0);
    glVertex3f(310, 525, 0);
    glVertex3f(230, 510, 0);
    glEnd();

//window left - top
    glColor3ub(195, 182, 166);
    glBegin(GL_POLYGON);
    glVertex3f(230, 900, 0);
    glVertex3f(325, 900, 0);
    glVertex3f(310, 890, 0);
    glVertex3f(230, 890, 0);
    glEnd();

//window left grill-middle-vertical
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(275, 512, 0);
    glVertex3f(280, 512, 0);
    glVertex3f(280, 895, 0);
    glVertex3f(275, 895, 0);
    glEnd();

//window left grill-bottom
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(230, 600, 0);
    glVertex3f(320, 615, 0);
    glVertex3f(320, 625, 0);
    glVertex3f(230, 610, 0);
    glEnd();

//window left grill-middle
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(230, 700, 0);
    glVertex3f(320, 715, 0);
    glVertex3f(320, 725, 0);
    glVertex3f(230, 710, 0);
    glEnd();

//window left grill-top-horizontal
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(230, 800, 0);
    glVertex3f(320, 810, 0);
    glVertex3f(320, 820, 0);
    glVertex3f(230, 810, 0);
    glEnd();

//wear drop front
    glColor3ub(89, 39, 25);
    glBegin(GL_POLYGON);
    glVertex3f(460, 660, 0);
    glVertex3f(470, 670, 0);
    glVertex3f(330, 670, 0);
    glVertex3f(340, 660, 0);
    glVertex3f(340, 320, 0);
    glVertex3f(460, 320, 0);
    glEnd();

//wear drop front-drawer 1 - outer
    glColor3ub(42, 23, 15);
    glBegin(GL_POLYGON);
    glVertex3f(455, 431, 0);
    glVertex3f(345, 431, 0);
    glVertex3f(345, 324, 0);
    glVertex3f(455, 324, 0);
    glEnd();

//wear drop front-drawer 1 - handel
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(410, 381, 0);
    glVertex3f(390, 381, 0);
    glVertex3f(390, 375, 0);
    glVertex3f(410, 375, 0);
    glEnd();

//wear drop front-drawer 2 - outer
    glColor3ub(42, 23, 15);
    glBegin(GL_POLYGON);
    glVertex3f(455, 435, 0);
    glVertex3f(345, 435, 0);
    glVertex3f(345, 541, 0);
    glVertex3f(455, 541, 0);
    glEnd();

//wear drop front-drawer 2 - handel
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(410, 481, 0);
    glVertex3f(390, 481, 0);
    glVertex3f(390, 475, 0);
    glVertex3f(410, 475, 0);
    glEnd();
//wear drop front-drawer 3 - outer
    glColor3ub(42, 23, 15);
    glBegin(GL_POLYGON);
    glVertex3f(455, 653, 0);
    glVertex3f(345, 653, 0);
    glVertex3f(345, 545, 0);
    glVertex3f(455, 545, 0);
    glEnd();

//wear drop front-drawer 3 - handel
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(410, 585, 0);
    glVertex3f(390, 585, 0);
    glVertex3f(390, 579, 0);
    glVertex3f(410, 579, 0);
    glEnd();

//wear drop side
    glColor3ub(39, 32, 21);
    glBegin(GL_POLYGON);
    glVertex3f(470, 670, 0);
    glVertex3f(500, 667, 0);
    glVertex3f(492, 657, 0);
    glVertex3f(492, 330, 0);
    glVertex3f(460, 320, 0);
    glVertex3f(460, 660, 0);
    glEnd();

//dressing table - front
    glColor3ub(98, 47, 29);
    glBegin(GL_POLYGON);
    glVertex3f(50, 150, 0);
    glVertex3f(245, 230, 0);
    glVertex3f(245, 460, 0);
    glVertex3f(50, 400, 0);
    glEnd();

//dressing table - front  - left part
    glColor3ub(42, 23, 15);
    glBegin(GL_POLYGON);
    glVertex3f(55, 160, 0);
    glVertex3f(115, 185, 0);
    glVertex3f(115, 410, 0);
    glVertex3f(55, 390, 0);
    glEnd();
//dressing table - front  - left part - front handel
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(70, 305, 0);
    glVertex3f(75, 305, 0);
    glVertex3f(75, 255, 0);
    glVertex3f(70, 255, 0);
    glEnd();

//dressing table - front  - left part - handel bottom
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(64, 262, 0);
    glVertex3f(75, 262, 0);
    glVertex3f(75, 255, 0);
    glVertex3f(64, 255, 0);
    glEnd();

//dressing table - front  - left part - handel top
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(64, 305, 0);
    glVertex3f(75, 305, 0);
    glVertex3f(75, 310, 0);
    glVertex3f(64, 310, 0);
    glEnd();

//dressing table side
    glColor3ub(42, 23, 15);
    glBegin(GL_POLYGON);
    glVertex3f(50, 150, 0);
    glVertex3f(20, 170, 0);
    glVertex3f(20, 420, 0);
    glVertex3f(50, 400, 0);
    glEnd();

//dressing table - front  - middle part
    glColor3ub(42, 23, 15);
    glBegin(GL_POLYGON);
    glVertex3f(120, 185, 0);
    glVertex3f(180, 210, 0);
    glVertex3f(180, 430, 0);
    glVertex3f(120, 410, 0);
    glEnd();

//dressing table - front  - middle part - handel - top
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(135, 275, 0);
    glVertex3f(140, 275, 0);
    glVertex3f(140, 323, 0);
    glVertex3f(135, 323, 0);
    glEnd();

//dressing table - front  - middle part - handel - down
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(130, 328, 0);
    glVertex3f(140, 328, 0);
    glVertex3f(140, 323, 0);
    glVertex3f(130, 323, 0);
    glEnd();
//dressing table - front  - middle part - handel - top-down
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(130, 275, 0);
    glVertex3f(140, 275, 0);
    glVertex3f(140, 280, 0);
    glVertex3f(130, 280, 0);
    glEnd();

//dressing table - front  - right part
    glColor3ub(42, 23, 15);
    glBegin(GL_POLYGON);
    glVertex3f(185, 213, 0);
    glVertex3f(240, 235, 0);
    glVertex3f(240, 450, 0);
    glVertex3f(185, 430, 0);
    glEnd();

//dressing table - front  - right part - handel - top
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(200, 300, 0);
    glVertex3f(205, 300, 0);
    glVertex3f(205, 343, 0);
    glVertex3f(200, 343, 0);
    glEnd();

//dressing table - front  - right part - handel - down
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(194, 300, 0);
    glVertex3f(205, 300, 0);
    glVertex3f(205, 295, 0);
    glVertex3f(194, 295, 0);
    glEnd();
//dressing table - front  - right part - handel - top-down
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(194, 343, 0);
    glVertex3f(205, 343, 0);
    glVertex3f(205, 348, 0);
    glVertex3f(194, 348, 0);
    glEnd();

//dressing table top
    glColor3ub(128, 55, 36);
    glBegin(GL_POLYGON);
    glVertex3f(20, 420, 0);
    glVertex3f(50, 400, 0);
    glVertex3f(245, 460, 0);
    glVertex3f(215, 480, 0);
    glEnd();

//dressing table glass frame
    glColor3ub(128, 55, 36);
    glBegin(GL_POLYGON);
    glVertex3f(190, 470, 0);
    glVertex3f(48, 427, 0);
    glVertex3f(48, 770, 0);
    glVertex3f(190, 800, 0);
    glEnd();

//dressing table glass
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(180, 467, 0);
    glVertex3f(58, 430, 0);
    glVertex3f(58, 750, 0);
    glVertex3f(180, 777, 0);
    glEnd();

//object reflection
    glColor3ub(158, 158, 158);
    glBegin(GL_POLYGON);
    glVertex3f(130, 460, 0);
    glVertex3f(150, 460, 0);
    glVertex3f(160, 575, 0);
    glVertex3f(120, 570, 0);
    glEnd();
//object flower1 reflection
    glColor3ub(229, 115, 115);
    glBegin(GL_POLYGON);
    glVertex3f(140, 600, 0);
    glVertex3f(150, 650, 0);
    glVertex3f(130, 650, 0);
    glEnd();
//object flower4 reflection
    glColor3ub(255, 213, 79);
    glBegin(GL_POLYGON);
    glVertex3f(150, 690, 0);
    glVertex3f(140, 740, 0);
    glVertex3f(130, 690, 0);
    glEnd();

//object flower2 reflection
    glColor3ub(129, 199, 132);
    glBegin(GL_POLYGON);
    glVertex3f(130, 690, 0);
    glVertex3f(100, 670, 0);
    glVertex3f(130, 650, 0);
    glEnd();

//object flower3 reflection
    glColor3ub(2, 136, 209);
    glBegin(GL_POLYGON);
    glVertex3f(150, 690, 0);
    glVertex3f(180, 670, 0);
    glVertex3f(150, 650, 0);
    glEnd();


//object flower5 - reflection
    glColor3ub(206, 140, 216);
    glBegin(GL_POLYGON);
    glVertex3f(150, 690, 0);
    glVertex3f(130, 690, 0);
    glVertex3f(130, 650, 0);
    glVertex3f(150, 650, 0);
    glEnd();

//object flower stand reflection
    glColor3ub(165, 214, 167);
    glBegin(GL_POLYGON);
    glVertex3f(137, 655, 0);
    glVertex3f(143, 655, 0);
    glVertex3f(143, 570, 0);
    glVertex3f(137, 570, 0);
    glEnd();


//dressing table glass frame-bottom
    glColor3ub(128, 55, 36);
    glBegin(GL_POLYGON);
    glVertex3f(190, 470, 0);
    glVertex3f(48, 427, 0);
    glVertex3f(48, 442, 0);
    glVertex3f(190, 485, 0);
    glEnd();

//object
    glColor3ub(117, 117, 117);
    glBegin(GL_POLYGON);
    glVertex3f(170, 450, 0);
    glVertex3f(190, 455, 0);
    glVertex3f(200, 575, 0);
    glVertex3f(160, 570, 0);
    glEnd();

//object flower stand
    glColor3ub(76, 175, 80);
    glBegin(GL_POLYGON);
    glVertex3f(177, 650, 0);
    glVertex3f(183, 650, 0);
    glVertex3f(183, 570, 0);
    glVertex3f(177, 570, 0);
    glEnd();

//object flower1
    glColor3ub(244, 67, 54);
    glBegin(GL_POLYGON);
    glVertex3f(180, 600, 0);
    glVertex3f(190, 650, 0);
    glVertex3f(170, 650, 0);
    glEnd();

//object flower2
    glColor3ub(27, 94, 32);
    glBegin(GL_POLYGON);
    glVertex3f(170, 690, 0);
    glVertex3f(140, 670, 0);
    glVertex3f(170, 650, 0);
    glEnd();

//object flower3
    glColor3ub(2, 136, 209);
    glBegin(GL_POLYGON);
    glVertex3f(190, 690, 0);
    glVertex3f(220, 670, 0);
    glVertex3f(190, 650, 0);
    glEnd();

//object flower4
    glColor3ub(251, 140, 0);
    glBegin(GL_POLYGON);
    glVertex3f(190, 690, 0);
    glVertex3f(180, 740, 0);
    glVertex3f(170, 690, 0);
    glEnd();

//object flower5
    glColor3ub(123, 31, 62);
    glBegin(GL_POLYGON);
    glVertex3f(190, 690, 0);
    glVertex3f(170, 690, 0);
    glVertex3f(170, 650, 0);
    glVertex3f(190, 650, 0);
    glEnd();


//bed
//bed head
    glColor3ub(77, 40, 26);
    glBegin(GL_POLYGON);
    glVertex3f(550, 650, 0);
    glVertex3f(850, 600, 0);
    glVertex3f(850, 250, 0);
    glVertex3f(550, 300, 0);
    glEnd();

//bed leg
    glColor3ub(88, 40, 19);
    glBegin(GL_POLYGON);
    glVertex3f(250, 200, 0);
    glVertex3f(550, 150, 0);
    glVertex3f(550, 50, 0);
    glVertex3f(250, 100, 0);
    glEnd();


//bed right side
    glColor3ub(128, 55, 36);
    glBegin(GL_POLYGON);
    glVertex3f(850, 250, 0);
    glVertex3f(550, 50, 0);
    glVertex3f(550, 150, 0);
    glVertex3f(850, 350, 0);
    glEnd();

//bed right side - box left
    glColor3ub(77, 40, 26);
    glBegin(GL_POLYGON);
    glVertex3f(695, 160, 0);
    glVertex3f(555, 65, 0);
    glVertex3f(555, 140, 0);
    glVertex3f(695, 235, 0);
    glEnd();

//bed right side - box left - handle

    glColor3ub(128, 55, 36);
    glBegin(GL_POLYGON);
    glVertex3f(650, 160, 0);
    glVertex3f(600, 125, 0);
    glVertex3f(600, 140, 0);
    glVertex3f(650, 175, 0);
    glEnd();

//bed right side - 2nd box
    glColor3ub(77, 40, 26);
    glBegin(GL_POLYGON);
    glVertex3f(845, 260, 0);
    glVertex3f(705, 165, 0);
    glVertex3f(705, 240, 0);
    glVertex3f(845, 335, 0);
    glEnd();

//bed right side - 2nd box - handle

    glColor3ub(128, 55, 36);
    glBegin(GL_POLYGON);
    glVertex3f(800, 260, 0);
    glVertex3f(750, 225, 0);
    glVertex3f(750, 240, 0);
    glVertex3f(800, 275, 0);
    glEnd();

//bed rig
//bed top right
    glColor3ub(198, 40, 40);
    glBegin(GL_POLYGON);
    glVertex3f(550, 150, 0);
    glVertex3f(850, 350, 0);
    glVertex3f(850, 400, 0);
    glVertex3f(550, 200, 0);
    glEnd();

//bed leg left
    glColor3ub(177, 160, 140);
    glBegin(GL_POLYGON);
    glVertex3f(250, 200, 0);
    glVertex3f(250, 250, 0);
    glVertex3f(550, 450, 0);
    glVertex3f(550, 400, 0);

    glEnd();

//bed leg top
    glColor3ub(183, 28, 28);
    glBegin(GL_POLYGON);
    glVertex3f(250, 200, 0);
    glVertex3f(550, 150, 0);
    glVertex3f(550, 200, 0);
    glVertex3f(250, 250, 0);
    glEnd();

//bed sheet
    glColor3ub(244, 67, 55);
    glBegin(GL_POLYGON);
    glVertex3f(550, 200, 0.0);
    glVertex3f(250, 250, 0.0);
    glVertex3f(550, 450, 0.0);
    glVertex3f(850, 400, 0.0);
    glEnd();

//bed pillo

//bed pillo - left
    glColor3ub(255, 245, 157);
    glBegin(GL_POLYGON);
    glVertex3f(604, 375, 0.0);
    glVertex3f(500, 395, 0.0);
    glVertex3f(550, 435, 0.0);
    glVertex3f(655, 415, 0.0);
    glEnd();


//bed pillo - left - side
    glColor3ub(255, 145, 0);
    glBegin(GL_POLYGON);
    glVertex3f(604, 375, 0.0);
    glVertex3f(655, 415, 0.0);
    glVertex3f(655, 405, 0.0);
    glVertex3f(604, 365, 0.0);
    glEnd();

//bed pillo - left - bottom
    glColor3ub(255, 145, 0);
    glBegin(GL_POLYGON);
    glVertex3f(604, 375, 0.0);
    glVertex3f(500, 395, 0.0);
    glVertex3f(500, 385, 0.0);
    glVertex3f(604, 365, 0.0);
    glEnd();

//bed pillo right
    glColor3ub(255, 245, 157);
    glBegin(GL_POLYGON);
    glVertex3f(737, 360, 0.0);
    glVertex3f(624, 375, 0.0);
    glVertex3f(675, 410, 0.0);
    glVertex3f(790, 390, 0.0);
    glEnd();
//bed pillo right-side
    glColor3ub(255, 145, 0);
    glBegin(GL_POLYGON);
    glVertex3f(737, 360, 0.0);
    glVertex3f(790, 390, 0.0);
    glVertex3f(790, 380, 0.0);
    glVertex3f(737, 350, 0.0);
    glEnd();

//bed pillo bottom
    glColor3ub(255, 145, 0);
    glBegin(GL_POLYGON);
    glVertex3f(737, 360, 0.0);
    glVertex3f(624, 375, 0.0);
    glVertex3f(624, 365, 0.0);
    glVertex3f(737, 350, 0.0);
    glEnd();

//bed blanket
    glColor3ub(94, 53, 177);
    glBegin(GL_POLYGON);
    glVertex3f(550, 220, 0.0);
    glVertex3f(280, 260, 0.0);
    glVertex3f(400, 340, 0.0);
    glVertex3f(670, 300, 0.0);
    glEnd();

//window right
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(1000, 500, 0);
    glVertex3f(900, 500, 0);
    glVertex3f(900, 900, 0);
    glVertex3f(1000, 900, 0);
    glEnd();
//window right-inner bottom
    glColor3ub(105, 87, 62);
    glBegin(GL_POLYGON);
    glVertex3f(1000, 500, 0);
    glVertex3f(900, 500, 0);
    glVertex3f(910, 510, 0);
    glVertex3f(1000, 510, 0);
    glEnd();
//window right-inner left
    glColor3ub(131, 102, 92);
    glBegin(GL_POLYGON);
    glVertex3f(900, 900, 0);
    glVertex3f(910, 890, 0);
    glVertex3f(910, 510, 0);
    glVertex3f(900, 500, 0);
    glEnd();

//window right-inner top
    glColor3ub(102, 87, 62);
    glBegin(GL_POLYGON);
    glVertex3f(900, 900, 0);
    glVertex3f(910, 890, 0);
    glVertex3f(1000, 890, 0);
    glVertex3f(1000, 900, 0);
    glEnd();

//window right grill bottom-vertical
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(905, 600, 0);
    glVertex3f(1000, 600, 0);
    glVertex3f(1000, 610, 0);
    glVertex3f(905, 610, 0);
    glEnd();

//window right grill middle-vertical
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(905, 700, 0);
    glVertex3f(1000, 700, 0);
    glVertex3f(1000, 710, 0);
    glVertex3f(905, 710, 0);
    glEnd();

//window right grill top-vertical
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(905, 800, 0);
    glVertex3f(1000, 800, 0);
    glVertex3f(1000, 810, 0);
    glVertex3f(905, 810, 0);
    glEnd();

//window right grill bottom-horizontal
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(965, 505, 0);
    glVertex3f(965, 895, 0);
    glVertex3f(970, 895, 0);
    glVertex3f(970, 505, 0);
    glEnd();
//bed side box front
    glColor3ub(60, 23, 9);
    glBegin(GL_POLYGON);
    glVertex3f(960, 410, 0);
    glVertex3f(960, 120, 0);
    glVertex3f(830, 135, 0);
    glVertex3f(830, 415, 0);
    glVertex3f(820, 435, 0);
    glVertex3f(970, 435, 0);
    glEnd();

//bed side box front - box bottom
    glColor3ub(128, 55, 36);
    glBegin(GL_POLYGON);
    glVertex3f(955, 260, 0);
    glVertex3f(955, 130, 0);
    glVertex3f(835, 145, 0);
    glVertex3f(835, 270, 0);
    glEnd();

//bed side box front - box bottom - handel
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(907, 200, 0);
    glVertex3f(907, 190, 0);
    glVertex3f(883, 190, 0);
    glVertex3f(883, 200, 0);
    glEnd();

//bed side box front - box top
    glColor3ub(128, 55, 36);
    glBegin(GL_POLYGON);
    glVertex3f(955, 265, 0);
    glVertex3f(955, 400, 0);
    glVertex3f(835, 405, 0);
    glVertex3f(835, 275, 0);
    glEnd();

//bed side box front - box top - handel
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex3f(907, 337.5, 0);
    glVertex3f(907, 327.5, 0);
    glVertex3f(883, 327.5, 0);
    glVertex3f(883, 337.5, 0);
    glEnd();
//bed side box side
    glColor3ub(113, 55, 34);
    glBegin(GL_POLYGON);
    glVertex3f(970, 435, 0);
    glVertex3f(960, 410, 0);
    glVertex3f(960, 120, 0);
    glVertex3f(985, 140, 0);
    glVertex3f(985, 430, 0);
    glVertex3f(995, 460, 0);
    glEnd();

//bed side box top
    glColor3ub(192, 99, 82);
    glBegin(GL_POLYGON);
    glVertex3f(820, 435, 0);
    glVertex3f(970, 435, 0);
    glVertex3f(995, 460, 0);
    glVertex3f(845, 460, 0);
    glEnd();

//bed side box lamp base
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(875, 440, 0);
    glVertex3f(915, 440, 0);
    glVertex3f(910, 450, 0);
    glVertex3f(890, 450, 0);
    glEnd();

//bed side box lamp stand
    glColor3ub(77, 49, 26);
    glBegin(GL_POLYGON);
    glVertex3f(895, 445, 0);
    glVertex3f(905, 445, 0);
    glVertex3f(905, 550, 0);
    glVertex3f(895, 550, 0);
    glEnd();

//bed side box lamp stand
    glColor3ub(244, 67, 59);
    glBegin(GL_POLYGON);
    glVertex3f(875, 650, 0);
    glVertex3f(925, 650, 0);
    glVertex3f(935, 550, 0);
    glVertex3f(865, 550, 0);
    glEnd();

//bed right papos - 1
    glColor3ub(213, 0, 249);
    glBegin(GL_POLYGON);
    glVertex3f(705, 150, 0);
    glVertex3f(570, 60, 0);
    glVertex3f(680, 60, 0);
    glVertex3f(815, 150, 0);
    glEnd();


//bed right papos - 2
    glColor3ub(255, 61, 0);
    glBegin(GL_POLYGON);
    glVertex3f(725, 150, 0);
    glVertex3f(590, 60, 0);
    glVertex3f(660, 60, 0);
    glVertex3f(795, 150, 0);
    glEnd();


//bed right papos - 2
    glColor3ub(255, 61, 0);
    glBegin(GL_POLYGON);
    glVertex3f(725, 150, 0);
    glVertex3f(590, 60, 0);
    glVertex3f(660, 60, 0);
    glVertex3f(795, 150, 0);
    glEnd();

//bed right papos - 3
    glColor3ub(57, 73, 171);
    glBegin(GL_POLYGON);
    glVertex3f(745, 150, 0);
    glVertex3f(610, 60, 0);
    glVertex3f(640, 60, 0);
    glVertex3f(775, 150, 0);
    glEnd();



/* don't wait!
* start processing buffered OpenGL routines
*/

    p = 1 - d;
    if (p < 0) {
        gx = gx + 1;
        hy = d;
        p = p + (2 * gx) + 1;
    } else {
        gx = gx + 1;
        hy = d - 1;
        p = p + (2 * gx) + 1 - (2 * hy);
    }
    ha = gx;
    gb = hy;
    glColor3f(1.0, 0.0, 0.0);
    //glBegin(GL_POINTS);
    glBegin(GL_POLYGON);
    glVertex2i(ha + hxc, gb + gyc);
    glVertex2i(gb + hxc, ha + gyc);
    glVertex2i(ha + hxc, -1 * gb + gyc);
    glVertex2i(-1 * ha + hxc, gb + gyc);
    glVertex2i(-1 * ha + hxc, -1 * gb + gyc);
    glVertex2i(gb + hxc, -1 * ha + gyc);
    glVertex2i(-1 * gb + hxc, ha + gyc);
    glVertex2i(-1 * gb + hxc, -1 * ha + gyc);
    glEnd();

    while (gx < hy) {
        //printf("a=%d\tb=%d\tp=%d\n",a,b,p);
        if (p < 0) {
            gx = gx + 1;
            hy = hy;
            p = p + (2 * gx) + 1;
        } else {
            gx = gx + 1;
            hy = hy - 1;
            p = p + (2 * gx) + 1 - (2 * hy);
        }
        //printf("%d %d ",x,y);
        ha = gx;
        gb = hy;
        glColor3f(1.0, 0.0, 0.0);
        //glBegin(GL_POINTS);
        glBegin(GL_POLYGON);
        glVertex2i(ha + hxc, gb + gyc);
        glVertex2i(gb + hxc, ha + gyc);
        glVertex2i(ha + hxc, -1 * gb + gyc);
        glVertex2i(-1 * ha + hxc, gb + gyc);
        glVertex2i(-1 * ha + hxc, -1 * gb + gyc);
        glVertex2i(gb + hxc, -1 * ha + gyc);
        glVertex2i(-1 * gb + hxc, ha + gyc);
        glVertex2i(-1 * gb + hxc, -1 * ha + gyc);
        glEnd();
    }
}


//dibujar cuadro del suelo
void cuadro(float x, float y, float z, float tam) {
    tam = tam / 2;
    glBegin(GL_QUADS);
    glVertex3f(x + tam, 0, z + tam);
    glVertex3f(x + tam, 0, z - tam);
    glVertex3f(x - tam, 0, z - tam);
    glVertex3f(x - tam, 0, z + tam);
    glEnd();
}

//pintar suelo
void pintarSuelo(void) {
    for (int i = -30; i <= 30; i++) {
        if ((i % 2) == 0) {
            for (int j = -30; j < 30; j++) {
                if (((j) % 2) == 0) {
                    cuadro(j, 0, i, 1);
                }
            }
        } else {
            for (int j = -30; j <= 30; j++) {
                if (((j) % 2) != 0) {
                    cuadro(j, 0, i, 1);
                }
            }
        }
    }

}

// it sets I = up,J = left, K = down, L = right
void lightKeys(unsigned char key, int x, int y) {
    double increment = 10;

    double actualX = light.getLightPosition()[0];
    double actualY = light.getLightPosition()[1];
    double actualZ = light.getLightPosition()[2];


    switch (key) {
        // left
        case 'j':
        case 'J':
            light.setPosition(actualX - increment, actualY, actualZ);
            break;

            // right
        case 'l':
        case 'L':
            light.setPosition(actualX + increment, actualY, actualZ);
            break;

            // up
        case 'i':
        case 'I':
            light.setPosition(actualX, actualY + increment, actualZ);
            break;

            // down
        case 'k':
        case 'K':
            light.setPosition(actualX, actualY - increment, actualZ);
            break;
    }

}

void Initialize(int argc, char *argv[]) {

    GLenum GlewInitResult;

    InitWindow(argc, argv);

    GlewInitResult = glewInit();

    if (GLEW_OK != GlewInitResult) {
        fprintf(
                stderr,
                "ERROR: %s\n",
                glewGetErrorString(GlewInitResult)
        );
        exit(EXIT_FAILURE);
    }

    // print system's capability
    fprintf(
            stdout,
            "INFO: OpenGL Version: %s\n",
            glGetString(GL_VERSION)
    );

    // OpenGL clear color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //glClearColor(1.0f, 0.0f, 0.0f, 0.0f); // red
    //glClearColor(0.0f, 1.0f, 0.0f, 0.0f); // green
    //glClearColor(0.0f, 0.0f, 1.0f, 0.0f); // blue
    //glClearColor(1.0f, 0.0f, 1.0f, 0.0f); // purple
    //glClearColor(0.0f, 0.0f, 0.5f, 0.0f); // dark blue

    // flags to enable Materials and Lighting
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glDepthFunc(GL_LESS);
    //glEnable(GL_DEPTH_TEST);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void InitWindow(int argc, char *argv[]) {
    glutInit(&argc, argv);

    // set OpenGL's major and minor versions
    glutInitContextVersion(1, 0);

    // Only not deprecated methods allowed
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    // set behavior on window close by user
    glutSetOption(
            GLUT_ACTION_ON_WINDOW_CLOSE,
            GLUT_ACTION_GLUTMAINLOOP_RETURNS
    );

    // settings initial values for the window, this override deafult values on top
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));

    // way to render frames
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    // if windowHandle is greater than 0, then no errors on creating the window
    WindowHandle = glutCreateWindow(WINDOW_TITLE_PREFIX);

    if(WindowHandle < 1) {
        fprintf(
                stderr,
                "ERROR: Could not create a new rendering window.\n"
        );
        exit(EXIT_FAILURE);
    }

    // reset draws to the new size
    glutReshapeFunc(ResizeFunction);
    glutDisplayFunc(RenderFunction);

    // behavior to run at idle
    glutIdleFunc(IdleFunction);
    glutTimerFunc(0, TimerFunction, 0);

    // key listener
    //glutSpecialFunc(lightKeys);
    glutKeyboardFunc(lightKeys);
}

void ResizeFunction(int Width, int Height) {
    CurrentWidth = Width;
    CurrentHeight = Height;

    // X, Y, width, height
    glViewport(0, 0, CurrentWidth, CurrentHeight);

    // activating projection matrix
    glMatrixMode(GL_PROJECTION);

    // clean projection matrix with the identity matrix
    glLoadIdentity();

    //aqui va ir el menu cuando se haga
    // Usamos proyeccion ortogonal
    glOrtho(ortho[0], ortho[1], ortho[2], ortho[3], ortho[4], ortho[5]);
    // Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);

    // clean projection matrix with the identity matrix
    glLoadIdentity();
}

void RenderFunction() {
    ++FrameCount; // aumentando el contador de FPS
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW_MATRIX);
    glLoadIdentity();

    // DRAWINGS START
    display();
    // DRAWINGS END

    // send all draws
    glFlush();

    // OpenGL is the front when calling to glutSwapBuffers();
    glutSwapBuffers();
    glutPostRedisplay();
}

void IdleFunction() {
    glutPostRedisplay();
}

void TimerFunction(int Value) {
    if (0 != Value) {
        char* TempString = (char*)
                malloc(512 + strlen(WINDOW_TITLE_PREFIX));

        sprintf(
                TempString,
                "%s: %d FPS @ %d x %d",
                WINDOW_TITLE_PREFIX,
                FrameCount * 4,
                CurrentWidth,
                CurrentHeight
        );

        glutSetWindowTitle(TempString);
        free(TempString);
    }

    FrameCount = 0;
    glutTimerFunc(250, TimerFunction, 1);
}