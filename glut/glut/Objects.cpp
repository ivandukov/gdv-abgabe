#include <iostream> 
#include <GL/freeglut.h> 
#include "Wuerfel.h"
#include "Wuerfel_mit_Normalen.h"
using namespace std;

#define Cos(th) cos(PI_2/180*(th))
#define Sin(th) sin(PI_2/180*(th))
#define DEF_D 3
#define PI_2 3.1415926535898

/**
 * @name  draw_cylinder
 * @brief Erzeugt einen 3D-Zylinder mit Höhe, Radius und Farben
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
            Roboter_Kopf(0.1, 0.1, 0.1); // Wuerfel mit Breite (x), Höhe (y), Laenge (z)
        glPopMatrix();

        // Koerper
        glPushMatrix();
            Roboter_Body(0.2, 0.2, 0.2); // Koerper erzeugen
        glPopMatrix();

        // rechter Arm
        glPushMatrix();
            glRotatef(90, 1., 0., 0.);
            glTranslatef(0.13, 0.14, -0.02);
            Wuerfel_blau(0.05, 0.2, 0.05);
        glPopMatrix();

        // linker Arm
        glPushMatrix();
            glRotatef(90, 1., 0., 0.);
            glTranslatef(-0.13, 0.14, -0.02);
            Wuerfel_blau(0.05, 0.2, 0.05);
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

void draw_kegel()
{
    glPushMatrix();
        glScalef(0.25, 0.25, 0.5);
        glTranslatef(-0.75, -0.5, 0.0);
        glutSolidCone(1.0, 2.0, 70, 12);
    glPopMatrix();

}

/**
 * @name draw_rocket
 * @brief Erzeugt eine Rakete
 */
void draw_rocket()
{
    
    
    glPushMatrix();
       
    glPopMatrix();

    // KEGEL
    glPushMatrix();
        glTranslatef(-0.91, 1.5, -0.41);
        glRotatef(260, 1.0, 0.0, 0.0);
        draw_kegel();
    glPopMatrix();

    // ZYLINDER
    glPushMatrix();
        glColor3f(0.85, 0.85, 0.85);
        glTranslatef(-1.099, 0.07, -0.03); // x -1.1
        glRotatef(260, 1.0, 0.0, 0.0);
        glutSolidCylinder(0.25, 1.55, 70, 12);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-0.91, -0.11, -0.05);
        glBegin(GL_TRIANGLES);
            glVertex3f(0.5, 0.0, 0.0);
            glVertex3f(0.0, 0.5, 0.0);
            glVertex3f(0.0, 0.0, 0.0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-1.34, -0.11, -0.05);
        glRotatef(180.0, 0.0, 1.0, 0.0);
        glBegin(GL_TRIANGLES);
            glVertex3f(0.5, 0.0, 0.0);
            glVertex3f(0.0, 0.5, 0.0);
            glVertex3f(0.0, 0.0, 0.0);
        glEnd();
    glPopMatrix();
}
