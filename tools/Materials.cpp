//
// Created by fernando9825 on 04-18-19.
//

#include "Materials.h"

// setters
void Materials::setGlAmbient(GLfloat *glAmbient) {
    for (int i = 0; i < 2; ++i) {
        this->glAmbient[i] = glAmbient[i];
    }
}

void Materials::setGlDiffuse(GLfloat *glDiffuse) {
    for (int i = 0; i < 2; ++i) {
        this->glDiffuse[i] = glDiffuse[i];
    }
}

void Materials::setGlSpecular(GLfloat *glSpecular) {
    for (int i = 0; i < 2; ++i) {
        this->glSpecular[i] = glSpecular[i];
    }
}

void Materials::setGlShininess(GLfloat shininess) {
    this->glShininess[0] = shininess;
}


void Materials::setMaterial(int material) {
    materialList(material);
    glMaterialfv(GL_FRONT, GL_AMBIENT, glAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, glDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, glSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, glShininess);
    glPushMatrix();
}

void Materials::materialList(int MATERIAL) {
    CURRENT_MATERIAL = MATERIAL;


    switch (MATERIAL) {
        case 0:
            setGlAmbient(new GLfloat[3]{0.0215, 0.1745, 0.0215});
            setGlDiffuse(new GLfloat[3]{0.07568, 0.61424, 0.07568});
            setGlSpecular(new GLfloat[3]{0.633, 0.727811, 0.633});
            setGlShininess(0.6);
            break;
        case 1:
            setGlAmbient(new GLfloat[3]{0.135, 0.2225, 0.1575});
            setGlDiffuse(new GLfloat[3]{0.54, 0.89, 0.63});
            setGlSpecular(new GLfloat[3]{0.316228, 0.316228, 0.316228});
            setGlShininess(0.1);
            break;
        case 2:
            setGlAmbient(new GLfloat[3]{0.05375, 0.05, 0.06625});
            setGlDiffuse(new GLfloat[3]{0.18275, 0.17, 0.22525});
            setGlSpecular(new GLfloat[3]{0.332741, 0.328634, 0.346435});
            setGlShininess(0.3);
            break;
        case 3:
            setGlAmbient(new GLfloat[3]{0.25, 0.20725, 0.20725});
            setGlDiffuse(new GLfloat[3]{1, 0.829, 0.829});
            setGlSpecular(new GLfloat[3]{0.296648, 0.296648, 0.296648});
            setGlShininess(0.088);
            break;
        case 4:
            setGlAmbient(new GLfloat[3]{0.1745, 0.01175, 0.01175});
            setGlDiffuse(new GLfloat[3]{0.61424, 0.04136, 0.04136});
            setGlSpecular(new GLfloat[3]{0.727811, 0.626959, 0.626959});
            setGlShininess(0.6);
            break;
        case 5:
            setGlAmbient(new GLfloat[3]{0.1, 0.18725, 0.1745});
            setGlDiffuse(new GLfloat[3]{0.396, 0.74151, 0.69102});
            setGlSpecular(new GLfloat[3]{0.297254, 0.30829, 0.306678});
            setGlShininess(0.1);
            break;
        case 6:
            setGlAmbient(new GLfloat[3]{0.329412, 0.223529, 0.027451});
            setGlDiffuse(new GLfloat[3]{0.780392, 0.568627, 0.113725});
            setGlSpecular(new GLfloat[3]{0.992157, 0.941176, 0.807843});
            setGlShininess(0.21794872);
            break;
        case 7:
            setGlAmbient(new GLfloat[3]{0.2125, 0.1275, 0.054});
            setGlDiffuse(new GLfloat[3]{0.714, 0.4284, 0.18144});
            setGlSpecular(new GLfloat[3]{0.393548, 0.271906, 0.166721});
            setGlShininess(0.2);
            break;
        case 8:
            setGlAmbient(new GLfloat[3]{0.25, 0.25, 0.25});
            setGlDiffuse(new GLfloat[3]{0.4, 0.4, 0.4});
            setGlSpecular(new GLfloat[3]{0.774597, 0.774597, 0.774597});
            setGlShininess(0.6);
            break;
        case 9:
            setGlAmbient(new GLfloat[3]{0.19125, 0.0735, 0.0225});
            setGlDiffuse(new GLfloat[3]{0.7038, 0.27048, 0.0828});
            setGlSpecular(new GLfloat[3]{0.256777, 0.137622, 0.086014});
            setGlShininess(0.1);
            break;
        case 10:
            setGlAmbient(new GLfloat[3]{0.24725, 0.1995, 0.0745});
            setGlDiffuse(new GLfloat[3]{0.75164, 0.60648, 0.22648});
            setGlSpecular(new GLfloat[3]{0.628281, 0.555802, 0.366065});
            setGlShininess(0.4);
            break;
        case 11:
            setGlAmbient(new GLfloat[3]{0.23125f, 0.23125f, 0.23125f});
            setGlDiffuse(new GLfloat[3]{0.2775f, 0.2775f, 0.2775f});
            setGlSpecular(new GLfloat[3]{0.773911f, 0.773911f, 0.773911f});
            setGlShininess(0.7);
            break;
        case 12:
            setGlAmbient(new GLfloat[3]{0.0, 0.0, 0.0});
            setGlDiffuse(new GLfloat[3]{0.01, 0.01, 0.01});
            setGlSpecular(new GLfloat[3]{0.50, 0.50, 0.50});
            setGlShininess(.25);
            break;
        case 13:
            setGlAmbient(new GLfloat[3]{0.0, 0.1, 0.06});
            setGlDiffuse(new GLfloat[3]{0.0, 0.50980392, 0.50980392});
            setGlSpecular(new GLfloat[3]{0.50196078, 0.50196078, 0.50196078});
            setGlShininess(.25);
            break;
        case 14:
            setGlAmbient(new GLfloat[3]{0.0, 0.0, 0.0});
            setGlDiffuse(new GLfloat[3]{0.1, 0.35, 0.1});
            setGlSpecular(new GLfloat[3]{0.45, 0.55, 0.45});
            setGlShininess(.25);
            break;
        case 15:
            setGlAmbient(new GLfloat[3]{0.0, 0.0, 0.0});
            setGlDiffuse(new GLfloat[3]{0.5, 0.0, 0.0});
            setGlSpecular(new GLfloat[3]{0.7, 0.6, 0.6});
            setGlShininess(.25);
            break;
        case 16:
            setGlAmbient(new GLfloat[3]{0.0, 0.0, 0.0});
            setGlDiffuse(new GLfloat[3]{0.55, 0.55, 0.55});
            setGlSpecular(new GLfloat[3]{0.70, 0.70, 0.70});
            setGlShininess(.25);
            break;
        case 17:
            setGlAmbient(new GLfloat[3]{0.0, 0.0, 0.0});
            setGlDiffuse(new GLfloat[3]{0.5, 0.5, 0.0});
            setGlSpecular(new GLfloat[3]{0.60, 0.60, 0.50});
            setGlShininess(.25);
            break;
        case 18:
            setGlAmbient(new GLfloat[3]{0.02, 0.02, 0.02});
            setGlDiffuse(new GLfloat[3]{0.01, 0.01, 0.01});
            setGlSpecular(new GLfloat[3]{0.4, 0.4, 0.4});
            setGlShininess(.078125);
            break;
        case 19:
            setGlAmbient(new GLfloat[3]{0.0, 0.05, 0.05});
            setGlDiffuse(new GLfloat[3]{0.4, 0.5, 0.5});
            setGlSpecular(new GLfloat[3]{0.04, 0.7, 0.7});
            setGlShininess(.078125);
            break;
        case 20:
            setGlAmbient(new GLfloat[3]{0.0, 0.05, 0.0});
            setGlDiffuse(new GLfloat[3]{0.4, 0.5, 0.4});
            setGlSpecular(new GLfloat[3]{0.04, 0.7, 0.04});
            setGlShininess(.078125);
            break;
        case 21:
            setGlAmbient(new GLfloat[3]{0.05, 0.0, 0.0});
            setGlDiffuse(new GLfloat[3]{0.5, 0.4, 0.4});
            setGlSpecular(new GLfloat[3]{0.7, 0.04, 0.04});
            setGlShininess(.078125);
            break;
        case 22:
            setGlAmbient(new GLfloat[3]{0.05, 0.05, 0.05});
            setGlDiffuse(new GLfloat[3]{0.5, 0.5, 0.5});
            setGlSpecular(new GLfloat[3]{0.7, 0.7, 0.7});
            setGlShininess(.078125);
            break;
        case 23:
            setGlAmbient(new GLfloat[3]{0.05, 0.05, 0.0});
            setGlDiffuse(new GLfloat[3]{0.5, 0.5, 0.4});
            setGlSpecular(new GLfloat[3]{0.7, 0.7, 0.04});
            setGlShininess(.078125);
            break;
        default:
            // no material
            setGlAmbient(new GLfloat[3]{0.0, 0.0, 0.0});
            setGlDiffuse(new GLfloat[3]{0.0, 0.0, 0.0});
            setGlSpecular(new GLfloat[3]{0.0, 0.0, 0.0});
            setGlShininess(0.0);
            CURRENT_MATERIAL = -1;
            break;
    }

    setGlShininess(getGlShininess()[0] * 128);

}

const GLfloat *Materials::getGlShininess() const {
    return glShininess;
}

void Materials::setMaterialColor(GLfloat red, GLfloat green, GLfloat blue, double shininess) {
    red = red / 255;
    green = green / 255;
    blue = blue / 255;

    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat diffuseMaterial[4] = {red, green, blue, 1.0};

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

}


