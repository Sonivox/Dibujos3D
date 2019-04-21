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

// Lighting constructor placed at center of the screen
Lighting light = Lighting(0, 0, abs(ortho[0]));

// function prototypes
void Initialize(int, char*[]);
void InitWindow(int, char*[]);
void ResizeFunction(int, int);
void RenderFunction();
void TimerFunction(int);
void IdleFunction();
void display();

void lightKeys(unsigned char, int, int);

// entry point
int main(int argc, char* argv[])
{
    Initialize(argc, argv);

    glutMainLoop();

    exit(EXIT_SUCCESS);
}

void plano3D() {
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
    Materials materials;

//    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
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
    Materials materials;

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

// all drawings here
void display() {
    glRotated(45.0, 1.0, 0.0, 0.0);
    glRotated(30.0, 0.0, 1.0, 0.0);
    light.activateLight();
    //light.glDisableLight();

    // creating an Object of Materials class
    Materials material;

    //setMaterial
    //material.setMaterial(material.BRASS);
    material.setMaterialColor(255, 126, 14, 50.0);

    primero();
    primeroAlambrico();
    glPopMatrix();


    //material.setMaterial(material.JADE);
    material.setMaterialColor(150, 0, 215, 50.0);

    glTranslatef(200, 200, 200);
//    glutSolidSphere(10, 100, 100);
    glPopMatrix();
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

void Initialize(int argc, char* argv[])
{

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

void InitWindow(int argc, char* argv[])
{
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

void ResizeFunction(int Width, int Height)
{
    CurrentWidth = Width;
    CurrentHeight = Height;

    // X, Y, width, height
    glViewport(0, 0, CurrentWidth, CurrentHeight);

    // activating projection matrix
    glMatrixMode(GL_PROJECTION);

    // clean projection matrix with the identity matrix
    glLoadIdentity();

    // Usamos proyeccion ortogonal
    glOrtho(ortho[0], ortho[1], ortho[2], ortho[3], ortho[4], ortho[5]);
    // Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);

    // clean projection matrix with the identity matrix
    glLoadIdentity();
}

void RenderFunction()
{
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

void IdleFunction()
{
    glutPostRedisplay();
}

void TimerFunction(int Value)
{
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