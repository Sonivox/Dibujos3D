//
// Created by fernando9825 on 04-20-19.
//

#ifndef DESING3D_LIGHTING_H
#define DESING3D_LIGHTING_H

#include <GL/freeglut.h>
#include <iostream>

using namespace std;

class Lighting {
public:

    Lighting(GLfloat posX, GLfloat posY, GLfloat posZ);

    void activateLight();

    void glDisableLight();

    void setPosition(GLfloat posX, GLfloat posY, GLfloat posZ);

private:
    GLfloat light_ambient[4] = {0.0, 0.0, 1.0, 1.0};
    GLfloat light_diffuse[4] = {1.0, 1.0, 1.0, 1.0};
public:
    const GLfloat *getLightPosition() const;

private:
    GLfloat light_specular[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[4] = {100.0, 100.0, 100.0, 0.0};
    GLfloat light_shininess[1] = {50.0};
};


#endif //DESING3D_LIGHTING_H
