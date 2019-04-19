//
// Created by fernando9825 on 04-18-19.
//

#ifndef DESING3D_MATERIALS_H
#define DESING3D_MATERIALS_H

#include <GL/freeglut.h>

// material list

class Materials {
private:
    GLfloat glAmbient[3] = {0.0, 0.0, 0.0};
    GLfloat glDiffuse[3] = {0.0, 0.0, 0.0};
    GLfloat glSpecular[3] = {0.0, 0.0, 0.0};
    GLfloat glShininess[1] = {0.0};

    // setters
    void setGlAmbient(GLfloat *glAmbient);

    void setGlDiffuse(GLfloat *glDiffuse);

    void setGlSpecular(GLfloat *glSpecular);

    void setGlShininess(GLfloat shininess);

    // shine getter
public:
    const GLfloat *getGlShininess() const;

private:

    void materialList(int MATERIAL);

public:

    int CURRENT_MATERIAL = -1;

    // MATERIALS
    int EMERALD = 0,
            JADE = 1,
            OBSIDIAN = 2,
            PEARL = 3,
            RUBY = 4,
            TURQUOISE = 5,
            BRASS = 6,
            BRONZE = 7,
            CHROME = 8,
            COPPER = 9,
            GOLD = 10,
            SILVER = 11,
            BLACK_PLASTIC = 12,
            CYAN_PLASTIC = 13,
            GREEN_PLASTIC = 14,
            RED_PLASTIC = 15,
            WHITE_PLASTIC = 16,
            YELLOW_PLASTIC = 17,
            BLACK_RUBBER = 18,
            CYAN_RUBBER = 19,
            GREEN_RUBBER = 20,
            RED_RUBBER = 21,
            WHITE_RUBBER = 22,
            YELLOW_RUBBER = 23;

    void setMaterial(int MATERIAL);

};


#endif //DESING3D_MATERIALS_H
