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

// all drawings here
void display() {

    light.activateLight();
    //light.glDisableLight();

    // creating an Object of Materials class
    Materials material;

    //setMaterial
    //material.setMaterial(material.BRASS);
    material.setMaterialColor(255, 126, 14, 50.0);

    glutSolidTeapot(150.0);
    glPopMatrix();


    //material.setMaterial(material.JADE);
    material.setMaterialColor(150, 0, 215, 50.0);

    glTranslatef(200, 200, 200);
    glutSolidSphere(50, 100, 100);
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