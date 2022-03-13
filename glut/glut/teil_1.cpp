#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <GL/freeglut.h>
#include <GL/SOIL.h>
using namespace std;
#include "Wuerfel.h"
#include "Objects.h"
#include "Wuerfel_mit_Normalen.h"

// siehe keyPressedUp und keyPressedDown
bool movingUp = false;
bool movingDown = false;
bool movingLeft = false;
bool movingRight = false;

// Aktuelle Position des Roboters
float currentX = 0.0;
float currentZ = 0.0;

// Detektionsgrenzen der Cubes
float cubeXmin = 0.0;
float cubeXmax = 0.0;
float cubeZmin = 0.0;
float cubeZmax = 0.0;

/**
 * Zeitlimit in ms
 */
int timeLeft = 60000;

/**
 * true, wenn player collected everything
 * or time is up
 */
bool gameOver = false;

/**
 * wird inkrementiert, sobald ein
 * Cube gesammelt wurde, damit der naechste
 * gespawnt werden kann
 */
int currentCubeIndex = 0;

/**
 * Rotation des Cubes
 */
GLfloat drehwinkel = 0.0;

/**
 * facing direction des Roboters
 */
float currentangle = 0.0;

/**
 * aktueller Punktestand des Spielers
 */
int points = 0;

struct CubeCoordinate
{
    float xpos;
    float zpos;
};

/**
 * alle Koordinaten der Cubes,
 * die der Roboter sammeln soll
 */
vector<CubeCoordinate> cubecoordinates{};

/**
 * @name  dateilesen
 * @brief Hier werden alle Koordinaten aus coordinates.txt für die
 *        sammelbaren Gegenstände gelesen und in cubecoordinates
 *        gespeichert,
 *        wird in main() aufgerufen
 */
void readFile()
{
    ifstream inFile("coordinates.txt");

    if (!inFile.is_open())
    {
        throw invalid_argument("coordinates.txt cannot be opened!\n");
    }

    string line {};
    while(getline(inFile, line))
    {
        string XPOS{};
        string ZPOS{};
        istringstream iss(line);
        getline(iss, XPOS, ';');
        getline(iss, ZPOS);
        CubeCoordinate* newCubeCoordinate = new CubeCoordinate;
        newCubeCoordinate->xpos = stof(XPOS);
        newCubeCoordinate->zpos = stof(ZPOS);
        cubecoordinates.push_back(*newCubeCoordinate);
    }
    cout << "Cube-Count: " << cubecoordinates.size() << endl;
    inFile.close();
}

/**
 * @name  handleCamera
 * @brief Hier kann man die Kameraposition einstellen
 */
void handleCamera()
{
    // Kameraposition, Blickwinkel, Up-Vector
    //gluLookAt(0.75, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Ansicht schraeg
    //gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  // Ansicht von vorne
    //gluLookAt(0.0, 0.7, -1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Ansicht von hinten
    //gluLookAt(0.0, 5.0, -1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Ansicht von oben
    //gluLookAt(0.0, 0.7, 1.5, currentX, 0.0, currentZ, 0.0, 1.0, 0.0); // folgende Kamera
    //gluLookAt(currentX, 5.0, currentZ - 1.5, currentX, 0.0, currentZ, 0.0, 1.0, 0.0); // Ansicht von oben (folgend)
    gluLookAt(currentX, 4.0, currentZ - 1.9, currentX, 0.0, currentZ, 0.0, 1.0, 0.0); // Ansicht von oben (folgend)
}

/**
 * @name  keyPressedDown
 * @brief Hier reagiert das Programm auf gedrückte Tasten
 *        wird in main() aufgerufen
 */
void keyPressedDown(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w': // vorwaerts
        {
            movingUp = true;
            break;
        }
        case 's': // rueckwaerts
        {
            movingDown = true;
            break;
        }
        case 'a': // links
        {
            movingLeft = true;
            break;
        }
        case 'd': // rechts
        {
            movingRight = true;
            break;
        }
        case 'e':
        {
            cout << "\nx = " << currentX << endl
                << "z = " << currentZ << "\n\n";
            break;
        }
        default:
        {
            break;
        }
    }
}

/**
 * @name  keyPressedUp
 * @brief Hier reagiert das Programm, wenn die Tasten NICHT mehr
 *        gedrückt werden
 *        wird in main() augerufen
 */
void keyPressedUp(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w': // vorwaerts
        {
            movingUp = false;
            break;
        }
        case 's': // rueckwaerts
        {
            movingDown = false;
            break;
        }
        case 'a': // links
        {
            movingLeft = false;
            break;
        }
        case 'd': // rechts
        {
            movingRight = false;
            break;
        }
        default:
        {
            break;
        }
    }
}

/**
 * @name  robot_movement
 * @brief this is where the directio of movement is decided and the
 *        paramters are set
 *        wird in RenderScene() aufgerufen
 */
void robot_movement()
{
    if(gameOver == false)
    {
        if (movingUp)
        {
            currentangle = 360.0;
            currentZ += 0.02f;
        }
        else if (movingDown)
        {
            currentangle = 180.0;
            currentZ -= 0.02f;
        }
        else if (movingLeft)
        {
            currentangle = 90.0;
            currentX += 0.02f;
        }
        else if (movingRight)
        {
            currentangle = 270.0;
            currentX -= 0.02f;
        }
    }
}

/**
 * @name  displayText
 * @brief gibt den String text in RGB-Farben aus
 */
void displayText(float x, float y, float z, int r, int g, int b, string text)
{
    glColor3f(r, g, b);
    glRasterPos3f(x, y, z);
    for(int i = 0; i < text.size(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

/**
 * @name  spawnCube
 * @brief spawnt 1 drehenden cube aus cubecoordinates
 *        und setzt  "Hitbox"-Koordinaten,
 *        wird in RenderScene() aufgerufen
 */
void spawnCube(int index)
{
    if (index < cubecoordinates.size()) // out of bounds verhindern
    {
        CubeCoordinate cube = cubecoordinates[index];

        // Detektionsgrenzen der Cubes definieren
        cubeXmin = cube.xpos - 0.1f;
        cubeXmax = cube.xpos + 0.1f;
        cubeZmin = cube.zpos - 0.1f;
        cubeZmax = cube.zpos + 0.1f;

        glPushMatrix();
        glNormal3d(0, 0, 1);
        glTranslatef(cube.xpos, 0.0, cube.zpos); // Wuerfel positionieren
        glRotatef(drehwinkel, 0.0, 1.0, 0.0);   // Wuerfel in Drehung versetzen 
        Wuerfel_mit_Normalen(0.1, 0.1, 0.1); // Wuerfel erzeugen
        glPopMatrix();
    }

}

/**
 * @name  handleLight
 * @brief übernimmt Licht-Konfiguration der Szene,
 *        wird in Init() aufgerufen
 */
void handleLight()
{
    glEnable(GL_LIGHTING); // enable lighting
    glEnable(GL_LIGHT0);   // Es gibt ein Licht Nr. 0 

    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_COLOR_MATERIAL);
    glClearDepth(1.0);
    glEnable(GL_NORMALIZE);
}

/**
 * @name  Init
 * @brief Aktionen, die zum Programmstart einmalig
 *		  durchgefuehrt werden sollen
 */
void Init()
{
    glClearColor(0, 0, 0, 1);
    handleLight();
    loadAllTextures();
    glEnable(GL_DEPTH_TEST); // z-Buffer
}

/**
 *  @name  RenderScene
 *  @brief Code der in jedem Frame ausgefuehrt werden soll
 *         Die Arm- und Beinrotation geschehen um die x-Achse
 */
void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Puffer loeschen
    glLoadIdentity(); // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen

    handleCamera(); // Kameraposition und Richtung
    draw_floor();   // Boden erzeugen
    glPushMatrix();
        robot_movement(); // Berechnung der Bewegung d. Roboters
        glTranslatef(currentX, 0.0, currentZ); // Tatsaechliche Bewegung
        glRotatef(currentangle, 0.0, 1.0, 0.0); // Facing Direction 
        draw_robot(); // Roboter erzeugen
    glPopMatrix();

    spawnCube(currentCubeIndex); // spawnt Cube aus cubecoordinates

    draw_rocket();
   
    displayText(currentX + 2.1, 0.0, currentZ + 2.1, 0, 1, 0, "time left: " + to_string(timeLeft / 1000));
    displayText(currentX + 2.1, 0.0, currentZ + 1.9, 0, 1, 0, "points: " + to_string(points -1 ));
    if(timeLeft <= 0 || currentCubeIndex >= cubecoordinates.size())
    {
        gameOver = true;
        displayText(currentX + 1.5, 0.0, currentZ, 0, 1, 0, "GAME OVER!");
        displayText(currentX + 1.5, 0.0, currentZ - 0.5 , 0, 1, 0, "YOU HAVE COLLECTED: " + to_string(points - 1) + " CUBES IN 1 MINUTE");
    }

    glutSwapBuffers();
    glFlush(); // forces execution of OpenGL functions in finite time.
}

/**
 * @name  Reshape
 * @brief Reaktionen auf eine Veraenderung der Groeße des
 *        Grafikfensters
 */
void Reshape(int width, int height)
{
    glMatrixMode(GL_PROJECTION); // Matrix fuer Transformation: Frustum -> viewport
    glLoadIdentity(); // Akt. Transformations-Matrix zuruecksetzen
    glViewport(0, 0, width, height);      // Viewport definieren
    gluPerspective(45.0, 1, 0.1, 10.0);   // perspektivische Kamera
    glMatrixMode(GL_MODELVIEW); // Matrix fuer Modellierung/Viewing
}

/**
 * @name  animateCube
 * @param uebernimmt Drehung der einzusammelnden Cubes
 *        und die "Hitbox", prueft also ob der Roboter
 *        einen Cube eingesammelt hat.
 *        wird in Animate() aufgerufen
 */
void animateCube()
{
    // Drehung der Cubes ausfuehren
    drehwinkel += 5.0f;
    if(drehwinkel > 360.0f)
    {
        drehwinkel -= 360.0f;
    }

    if (gameOver == false)
    {
        // Pruefen, ob der Cube vom Roboter eingesammelt wurde
        if ((currentX <= cubeXmax && currentX >= cubeXmin) &&
            (currentZ <= cubeZmax && currentZ >= cubeZmin))
        {
            cout << "gotcha!\n";
            currentCubeIndex++;
            points = currentCubeIndex;
        }
    }
}

/**
 * @name  Animate
 * @brief Berechnungen, die zu einer Animation der Szene erforderlich sind.
 *		  Prozess laeuft im Hintergrund und wird alle 1000 msec aufgerufen.
 *		  Der Parameter "value" wird einfach nur um eins inkrementiert
 *		  und dem Callback wieder uebergeben.
 */
void Animate(int value)
{
    glutPostRedisplay(); // RenderScene aufrufen
    int wait_msec = 10; // Timer wieder registrieren 
    if (gameOver == false)
    {
        glutTimerFunc(wait_msec, Animate, timeLeft -= 10);
    }
    //glutTimerFunc(wait_msec, Animate, ++value); // Animate wird nach 10 msec mit value+=1 aufgerufen
    animateCube();
}

/**
 * @name  main
 * @brief Hauptprogramm
 */
int main(int argc, char** argv)
{
    readFile();
    glutInit(&argc, argv); // GLUT initialisieren
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600); // Fenster-Konfiguration
    glutCreateWindow("Roboter"); // Fenster-Erzeugung
    glutDisplayFunc(RenderScene); // Zeichenfunktion bekannt machen
    glutReshapeFunc(Reshape);
    // TimerCallback registrieren 
    glutTimerFunc(10, Animate, 0); // wird nach 10 msec aufgerufen mit Parameter 0  
    glutKeyboardFunc(keyPressedDown); // Taste gedrueckt
    glutKeyboardUpFunc(keyPressedUp); // Taste losgelassen
    Init();
    glutMainLoop();
    return 0;
}
