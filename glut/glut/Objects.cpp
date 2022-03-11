#include <iostream> 
#include <GL/freeglut.h> 
#include "Wuerfel.h"
#include "Wuerfel_mit_Normalen.h"
using namespace std;

/**
 * @name  draw_cylinder 
 * @brief Erzeugt einen 3D-Zylinder 
 */
void draw_cylinder(GLfloat radius, GLfloat height, GLubyte R, GLubyte G, GLubyte B)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;
    float PI = 3.141;

    // Erzeuge die "Roehre"
    glColor3ub(R - 40, G - 40, B - 40);
    glBegin(GL_QUAD_STRIP);
        glNormal3f(0.0f, 0.0f, 1.0f);
        angle = 0.0;
        while (angle < 2 * PI)
        {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y, height);
            glVertex3f(x, y, 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    // Erzeuge den Kreis auf dem Zylinder 
    glColor3ub(R, G, B);
    glBegin(GL_POLYGON);
        glNormal3f(0.0f, 0.0f, 1.0f);
        angle = 0.0;
        while (angle < 2 * PI) 
        {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y, height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}

/**
 * @name  draw_robot
 * @brief Erzeugt einen kleinen Roboter mit 2 Raedern 
 */
void draw_robot()
{
    glPushMatrix();
        // Kopf
        glPushMatrix();
            glTranslatef(0.0, 0.15, 0.0); // Kopf positionieren
            Wuerfel_mit_Normalen(0.1, 0.1, 0.1); // Wuerfel mit Breite (x), Höhe (y), Laenge (z)
        glPopMatrix();

        // Koerper
        glPushMatrix();
            Wuerfel_mit_Normalen(0.2, 0.2, 0.2); // Koerper erzeugen
        glPopMatrix();

        // rechter Arm
        glPushMatrix();
            glRotatef(90, 1., 0., 0.);
            glTranslatef(0.13, 0.14, -0.02);
            Wuerfel_mit_Normalen(0.05, 0.2, 0.05);
        glPopMatrix();

        // linker Arm
        glPushMatrix();
            glRotatef(90, 1., 0., 0.);
            glTranslatef(-0.13, 0.14, -0.02);
            Wuerfel_mit_Normalen(0.05, 0.2, 0.05);
        glPopMatrix();

        // linkes Rad
        glPushMatrix();
            glTranslatef(-0.1, -0.11, 0.0); // (links/rechts, oben/unten, vorne/hinten)
            glRotatef(-90, 0.0, 1.0, 0.0);
            draw_cylinder(0.05, 0.04, 0.0, 1.0, 0.0);
        glPopMatrix();

        // rechtes Rad
        glPushMatrix();
            glTranslatef(0.1, -0.11, 0.0); // (links/rechts, oben/unten, vorne/hinten)
            glRotatef(90, 0.0, 1.0, 0.0);
            draw_cylinder(0.05, 0.04, 0.0, 1.0, 0.0);
            glPopMatrix();
    glPopMatrix();
}


/**
 * @name  draw_floor
 * @brief erzeugt eine Flaeche, auf der sich der Roboter
 *        bewegen soll
 */
void draw_floor()
{
    glPushMatrix();
        glTranslatef(0.0, -0.5, 0.0);
        glColor4f(0.5, 0.5, 0.5, 1.0);
        glBegin(GL_POLYGON);
            glVertex3f(0.0, 0.0, -10.0);
            glVertex3f(-10.0, 0.0, 10.0);
            glVertex3f(0.0, 0.0, 10.0);
            glVertex3f(10.0, 0.0, 0.0);
            glVertex3f(0.0, 0.0, -10.0);
        glEnd();
    glPopMatrix();
}