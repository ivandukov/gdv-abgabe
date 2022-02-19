#include <iostream> 
#include <GL/freeglut.h> 
#include "Wuerfel.h"
using namespace std;

bool ismovingforward = false;
bool ismovingbackwards = false;
bool ismovingleft = false;
bool ismovingright = false;

double translateforwardbackwards = 0.0;
double translateleftright = 0.0;

void move_robot()
{
    glTranslatef(0.0, 0.0, translateforwardbackwards); // tatsaechliche Bewegung d. Baggers (vorwaerts)
    glTranslatef(translateleftright, 0.0, 0.0); // tatsaechliche Bewegung d. Baggers (seitlich)
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
        if (current_z <= -7.00)
        {
            current_z = -7.00;
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
        if (current_z <= -7.00)
        {
            current_z = -7.00;
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
        if (current_x <= -7.00)
        {
            current_x = -7.00;
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
        if (current_x <= -7.00)
        {
            current_x = -7.00;
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
    gluLookAt(0.0, 0.5, -1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Ansicht von hinten
}


void draw_robot()
{
    glPushMatrix();
    // Kopf
    glPushMatrix();
    glTranslatef(0.0, 0.15, 0.0); // Kopf positionieren
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

/**
 * @brief Aktionen, die zum Programmstart einmalig
 *		  durchgefuehrt werden sollen
 */
void Init()
{
    glClearColor(0, 0, 0, 1); // 
    glEnable(GL_DEPTH_TEST);  // 
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

    draw_floor();
    glPushMatrix();
    move_robot();
    draw_robot();
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
    std::cout << "value=" << value << std::endl;
    // RenderScene aufrufen
    glutPostRedisplay();
    // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
    int wait_msec = 10;
    glutTimerFunc(wait_msec, Animate, ++value);

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