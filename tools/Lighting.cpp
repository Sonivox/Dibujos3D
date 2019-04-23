//
// Created by fernando9825 on 04-20-19.
//

#include "Lighting.h"

void Lighting::activateLight() {
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // apply Lighting settings
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

}

void Lighting::glDisableLight() {
    glDisable(GL_LIGHT0);
}

void Lighting::setPosition(GLfloat posX, GLfloat posY, GLfloat posZ) {
    light_position[0] = posX;
    light_position[1] = posY;
    light_position[2] = posZ;

    cout << "(" << posX << ", " << posY << ", " << posZ << ") " << endl;
}

const GLfloat *Lighting::getLightPosition() const {
    return light_position;
}

Lighting::Lighting(GLfloat posX, GLfloat posY, GLfloat posZ) {
    setPosition(posX, posY, posZ);
}



