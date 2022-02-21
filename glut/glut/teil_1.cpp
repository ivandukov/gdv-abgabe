#include <iostream> 
#include <GL/freeglut.h> 
#include <GL/SOIL.h>
#include "Wuerfel.h"
#include <string>
using namespace std;

bool ismovingforward = false;
bool ismovingbackwards = false;
bool ismovingleft = false;
bool ismovingright = false;

/*  Macro for sin & cos in degrees */
#define Cos(th) cos(PI_2/180*(th))
#define Sin(th) sin(PI_2/180*(th))
#define DEF_D 3
#define PI_2 3.1415926535898
double translateforwardbackwards = 0.0;
double translateleftright = 0.0;
int points = 0;
int timeLeft = 60000;
GLuint tex_2d;         // Textur-ID

void move_robot()
{
    glTranslatef(0.0, 0.0, translateforwardbackwards); // tatsaechliche Bewegung d. Baggers (vorwaerts)
    glTranslatef(translateleftright, 0.0, 0.0); // tatsaechliche Bewegung d. Baggers (seitlich)
    glRotatef(atan2(translateleftright, translateforwardbackwards) * 180 / 3.14, 0, 1, 0);
}

void displayText(float x, float y, int r, int g, int b, string input) {

    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    for (int i = 0; i < input.size(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, input[i]);
    }
}

void draw_cylinder(GLfloat radius, GLfloat height, GLubyte R, GLubyte G, GLubyte B)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;
    float PI = 3.141;

    /** Draw the tube */
    glColor3ub(R - 40, G - 40, B - 40);
    glBegin(GL_QUAD_STRIP);
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

    /** Draw the circle on top of cylinder */
    glColor3ub(R, G, B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}

void handleUserInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    {
        ismovingforward = true;
        break;
    }
    case 's':
    {
        ismovingbackwards = true;
        break;
    }
    case 'a':
    {
        ismovingleft = true;
        break;
    }
    case 'd':
    {
        ismovingright = true;
        break;
    }
    }
}

double handleRobotForwardMovement(double current_z)
{
    if (ismovingforward)
    {
        if (current_z >= 2.9)
        {
            current_z = 2.7;
        }
        else if (current_z <= -2.9)
        {
        current_z = -2.7;
        }
        else
        {
            current_z += 0.1;
            ismovingforward = false;
        }
    }
    return current_z;
}

double handleRobotBackwardsMovement(double current_z)
{
    if (ismovingbackwards)
    {
        if (current_z >= 2.9)
        {
            current_z = 2.7;
        }
        else if (current_z <= -2.9)
        {
            current_z = -2.7;
        }
        else
        {
            current_z -= 0.1;
            ismovingbackwards = false;
        }
    }
    return current_z;
}

double handleRobotLeftMovement(double current_x)
{
    if (ismovingleft)
    {
        if (current_x >= 2.9)
        {
            current_x = 2.7;
        }
        else if (current_x <= -2.9)
        {
            current_x = -2.7;
        }
        else
        {
            current_x += 0.1;
            ismovingleft = false;
        }
    }
    return current_x;
}

double handleRobotRightMovement(double current_x)
{
    if (ismovingright)
    {
        if (current_x >= 2.9)
        {
            current_x = 2.7;
        }
        else if (current_x <= -2.9)
        {
            current_x = -2.7;
        }
        else
        {
            current_x -= 0.1;
            ismovingright = false;
        }
    }
    return current_x;
}

void handleCamera()
{
    //Kameraposition, Blickwinkel und Up-Vector
    //gluLookAt(0.75, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Ansicht schraeg
    //gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Ansicht von vorne
     //gluLookAt(0.0, 0.5, -1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Ansicht von hinten
    gluLookAt(0.0, 7.0, -1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Ansicht von hinten
}


void draw_robot()
{
    glPushMatrix();
    // Kopf
    glPushMatrix();
    glTranslatef(0.0, 0.15, 0.0); // Kopf positionieren
    glPushMatrix();
    glTranslatef(0.0, 0.6, 0.2);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    for (int k = 0; k <= 360; k += DEF_D) {
        glColor4f(1.0, 1.0, 0.0,1.0);
        glVertex3f(0, 0, 1);
        glVertex3f(Cos(k), Sin(k), 0);
        glVertex3f(Cos(k + DEF_D), Sin(k + DEF_D), 0);
    }
    glEnd();
    glPopMatrix();
    Wuerfel(0.1, 0.1, 0.1); // Wuerfel mit Breite (x), Höhe (y), Länge (z)
    glPopMatrix();

    // Koerper
    glPushMatrix();
    Wuerfel(0.2, 0.2, 0.2); // Koerper erzeugen
    glPopMatrix();

    // rechter Arm
    glPushMatrix();
    glRotatef(90, 1., 0., 0.);
    glTranslatef(0.13, 0.14, -0.02);
    Wuerfel(0.05, 0.2, 0.05);
    glPopMatrix();

    // linker Arm
    glPushMatrix();
    glRotatef(90, 1., 0., 0.);
    glTranslatef(-0.13, 0.14, -0.02);
    Wuerfel(0.05, 0.2, 0.05);
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
 * @brief erstellt die Flaeche, auf der sich der Roboter
 *        bewegen soll
 */
void draw_floor()
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glTranslatef(0.0, -0., 0.0);
    glColor4f(0, 0, 0, 1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0, 0.0, -10.0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-10.0, 0.0, 10.0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0, 0.0, 10.0);
    glTexCoord2f(0.0f, 1.0f); 
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -10.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

/**
 * @brief Aktionen, die zum Programmstart einmalig
 *		  durchgefuehrt werden sollen
 */
void Init()
{

    //tex_2d = SOIL_load_OGL_texture("moon.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
      //  SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    glBindTexture(GL_TEXTURE_2D, tex_2d);
    glClearColor(0, 0, 0, 1); // 
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHTING);
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
    GLfloat light_position[] = { 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); // Licht Nr. 0 rechts oben
    GLfloat light_position1[] = { -0.5, -1.0, -1.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1); // Licht Nr. 0 rechts oben
    GLfloat light_position2[] = { -1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT2, GL_POSITION, light_position2); // Licht Nr. 0 rechts oben
    glEnable(GL_COLOR_MATERIAL);
    // z-Buffer
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    // Normalen fuer korrekte Beleuchtungs-Berechnung normalisieren
    glEnable(GL_NORMALIZE);
}

/**
 * @brief Code der in jedem Frame ausgefuehrt werden soll
 *        Die Arm- und Beinrotation geschehen um die x-Achse
 */
void RenderScene()
{
    glLoadIdentity(); // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    handleCamera();
    //fake sun
    glPushMatrix();
    glTranslatef(0.0, 1.8, 1.5);
    glRotatef(90, 1, 0, 0);
    draw_cylinder(0.3, 0, 255, 255, 0);
    glPopMatrix();
    

    displayText(1, 4.7, 1, 1, 0, "time left: " + to_string(timeLeft / 1000 ));

    draw_floor();
    glPushMatrix();
    move_robot();
    draw_robot();
    glPopMatrix();
    //secret wuerfel 1
    glPushMatrix();
    glTranslatef(1, 2, 0.5);
    Wuerfel_ohne_Farben(0.2);
    glPopMatrix();
    //secret wuerfel 2
    glPushMatrix();
    glTranslatef(-1, 2, -0.5);
    Wuerfel_ohne_Farben(0.2);
    glPopMatrix();
    //secret wuerfel 3
    glPushMatrix();
    glTranslatef(-3, 2, -1.5);
    Wuerfel_ohne_Farben(0.2);
    glPopMatrix();


    glutSwapBuffers();
}

/**
 * @brief Reaktionen auf eine Veraenderung der Groeße des
 *        Grafikfensters
 */
void Reshape(int width, int height)
{
    // Matrix fuer Transformation: Frustum -> viewport
    glMatrixMode(GL_PROJECTION);
    // Aktuelle Transformations-Matrix zuruecksetzen
    glLoadIdentity();
    // Viewport definieren
    glViewport(0, 0, width, height);
    // Kamera definieren (intrinsische Kameraparameter)
    //glOrtho(-1., 1., -1., 1., 0., 10.); // orthogonale Kamera
    gluPerspective(45.0, 1, 0.1, 10.0); // perspektivische Kamera
    // Matrix fuer Modellierung/Viewing
    glMatrixMode(GL_MODELVIEW);
}

/**
 * @brief Berechnungen durchgefuehrt, die zu einer Animation der Szene
 *		  erforderlich sind. Dieser Prozess laeuft im Hintergrund und wird alle
 *		  1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins
 *		  inkrementiert und dem Callback wieder uebergeben.
 */
void Animate(int value)
{
    // RenderScene aufrufen
    glutPostRedisplay();
    // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
    int wait_msec = 1;
    glutTimerFunc(wait_msec, Animate, timeLeft-=5);
    cout << translateforwardbackwards << endl;
    cout << translateleftright << endl;
    displayText(0, 0, 1, 1, 0, "timeleft=" + to_string(timeLeft));

    if (timeLeft == 0)
    {
        displayText(0.0, 0, 1, 0, 0, "GAME OVER");
        exit(0);
    }


    translateforwardbackwards = handleRobotForwardMovement(translateforwardbackwards);
    translateforwardbackwards = handleRobotBackwardsMovement(translateforwardbackwards);
    translateleftright = handleRobotLeftMovement(translateleftright);
    translateleftright = handleRobotRightMovement(translateleftright);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // GLUT initialisieren
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600); // Fenster-Konfiguration
    glutCreateWindow("glut output");	// Fenster-Erzeugung
    glutDisplayFunc(RenderScene); // Zeichenfunktion bekannt machen
    glutReshapeFunc(Reshape);
    // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
    glutTimerFunc(10, Animate, 0);
    glutKeyboardFunc(handleUserInput);
    Init();
    glutMainLoop();
    return 0;
}