#include <GL/freeglut.h>
#include <GL/SOIL.h>
#include <string>
using namespace std;
#include "Wuerfel_mit_Normalen.h"

/**
 * Alle Textur-IDs, sortiert nach
 * Namen, benannt nach der Dateid
 */
GLuint textureids[10];

/**
 * @name loadTexture
 * @brief
 */
void loadTexture(const string path, const GLuint texture)
{
	int width = 0; // 200
	int height = 0;
	int nrChannels = 0;
	unsigned char* data = SOIL_load_image(path.c_str(), &width, &height, &nrChannels, 0);
	if (data == nullptr)
	{
		throw string("Texture could not be loaded.");
	}
	glBindTexture(GL_TEXTURE_2D, texture); // Textur assoziieren mit Name GL_TEXTURE_2D
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	SOIL_free_image_data(data);
}

void loadAllTextures()
{
	glGenTextures((sizeof(textureids) / sizeof(textureids[0])), textureids);
	loadTexture("D:\\workspace\\gdvWorkspace\\project_idk\\project_idk\\moonproto.jpg", textureids[0]);
	loadTexture("D:\\workspace\\gdvWorkspace\\project_idk\\project_idk\\robotface.jpg", textureids[1]);
	loadTexture("D:\\workspace\\gdvWorkspace\\project_idk\\project_idk\\robottile.jpg", textureids[2]);
	loadTexture("D:\\workspace\\gdvWorkspace\\project_idk\\project_idk\\robotbodyfront.jpg", textureids[3]);
	loadTexture("D:\\workspace\\gdvWorkspace\\project_idk\\project_idk\\schrott.jpg", textureids[4]);
}

/**
 * @name  draw_floor
 * @brief erzeugt die Flaeche, auf der sich der Roboter
 *        bewegen soll
 */
void draw_floor()
{
	glPushMatrix();
		glTranslatef(0.0, -0.5, 0.0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureids[0]);
		glBegin(GL_POLYGON);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glColor4f(1, 1, 1, 1);
			glTexCoord2f(0, 0);
			glVertex3f(0.0, 0.0, -25.0);
			glTexCoord2f(0, 1);
			glVertex3f(-25.0, 0.0, 25.0);
			glTexCoord2f(1, 1);
			glVertex3f(0.0, 0.0, 25.0);
			glTexCoord2f(1, 0);
			glVertex3f(25.0, 0.0, 0.0);
			glTexCoord2f(0, 0);
			glVertex3f(0.0, 0.0, -25.0);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Wuerfel_mit_Normalen(GLfloat fSeitenL)
{
	glBegin(GL_POLYGON);   //Vorderseite
		glNormal3f(0.0f, 0.0f, 1.0f);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	//ROT
		glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
		glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //WEISS
		glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
		glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   // Rechte Seite
		glNormal3f(1.0f, 0.0f, 0.0f);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
		glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
		glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
		glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //WEISS
		glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rueckseite
		glNormal3f(0.0f, 0.0f, -1.0f);
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f); //CYAN
		glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
		glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0f); //SCHWARZ
		glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
		glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
		glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0f); //SCHWARZ
		glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //ROT	
		glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
		glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
		glNormal3f(0.0f, 1.0f, 0.0f);
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
		glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //WEISS
		glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f); //CYAN
		glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
		glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
		glNormal3f(0.0f, -1.0f, 0.0f);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0f); //SCHWARZ
		glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
		glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
		glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //ROT
		glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	return;
}

void Wuerfel_mit_Normalen(GLfloat fSeitenLX, GLfloat fSeitenLY, GLfloat fSeitenLZ)
{
	glBegin(GL_POLYGON); // Vorderseite
		glNormal3f(0.0f, 0.0f, 1.0f);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // ROT
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f); // GELB
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // WEISS
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f); // MAGENTA
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();


	glBegin(GL_POLYGON); // Rechte Seite
		glNormal3f(1.0f, 0.0f, 0.0f);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f); // GELB
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f); // GRUEN
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f); // CYAN
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // WEISS
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Rueckseite
		glNormal3f(0.0f, 0.0f, -1.0f);
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f); // CYAN
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f); // GRUEN
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0f); // SCHWARZ
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // BLAU
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glEnd();


	glBegin(GL_POLYGON); // Linke Seite
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // BLAU
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0f); // SCHWARZ
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // ROT	
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f); // MAGENTA
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Deckflaeche
		glNormal3f(0.0f, 1.0f, 0.0f);
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f); // MAGENTA
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // WEISS
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f); // CYAN
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // BLAU
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Bodenflaeche
		glNormal3f(0.0f, -1.0f, 0.0f);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0f); // SCHWARZ
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f); // GRUEN
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f); // GELB
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // ROT
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();
	return;
}

void Roboter_Kopf(GLfloat fSeitenLX, GLfloat fSeitenLY, GLfloat fSeitenLZ)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureids[1]);
	glColor4f(1, 1, 1, 1);
	glBegin(GL_POLYGON); // Vorderseite
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glTexCoord2f(0, 1);
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glTexCoord2f(1, 1);
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glTexCoord2f(1, 0);
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureids[2]);
	glColor4f(1, 1, 1, 1);
	glBegin(GL_POLYGON); // Rechte Seite
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glTexCoord2f(0, 1);
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glTexCoord2f(1, 1);
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glTexCoord2f(1, 0);
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);


	glColor4f(0.60, 0.85, 0.92, 1);
	glBegin(GL_POLYGON); // Rueckseite
		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glEnd();

	glColor4f(0.60, 0.85, 0.92, 1);
	glBegin(GL_POLYGON); // Linke Seite
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);

		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);

		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);

		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();

	glColor4f(0.60, 0.85, 0.92, 1);
	glBegin(GL_POLYGON); // Deckflaeche
		glNormal3f(0.0f, 1.0f, 0.0f);

		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);

		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);

		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);

		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glEnd();

	glColor4f(0.60, 0.85, 0.92, 1);
	glBegin(GL_POLYGON); // Bodenflaeche
		glNormal3f(0.0f, -1.0f, 0.0f);

		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);

		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);

		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);

		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();
	return;
}

void Roboter_Body(GLfloat fSeitenLX, GLfloat fSeitenLY, GLfloat fSeitenLZ)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureids[3]);
	glColor4f(1, 1, 1, 1);
	glBegin(GL_POLYGON); // Vorderseite
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glTexCoord2f(0, 1);
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glTexCoord2f(1, 1);
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glTexCoord2f(1, 0);
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);


	glBegin(GL_POLYGON); // Rechte Seite
		glColor4f(0.60, 0.85, 0.92, 1);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Rueckseite
	glColor4f(0.60, 0.85, 0.92, 1);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Linke Seite
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glColor4f(0.60, 0.85, 0.92, 1);
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Deckflaeche
	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(0.60, 0.85, 0.92, 1);
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Bodenflaeche
	glNormal3f(0.0f, -1.0f, 0.0f);
	glColor4f(0.60, 0.85, 0.92, 1);
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();
	return;
}

void Wuerfel_blau(GLfloat fSeitenLX, GLfloat fSeitenLY, GLfloat fSeitenLZ)
{
	glBegin(GL_POLYGON); // Vorderseite
		glNormal3f(0.0f, 0.0f, 1.0f);
		glColor4f(0.60, 0.85, 0.92, 1);
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Rechte Seite
		glNormal3f(1.0f, 0.0f, 0.0f);
		glColor4f(0.60, 0.85, 0.92, 1);
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Rueckseite
		glNormal3f(0.0f, 0.0f, -1.0f);
		glColor4f(0.60, 0.85, 0.92, 1);
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Linke Seite
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glColor4f(0.60, 0.85, 0.92, 1);
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();


	glBegin(GL_POLYGON); // Deckflaeche
		glNormal3f(0.0f, 1.0f, 0.0f);
		glColor4f(0.60, 0.85, 0.92, 1);
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Bodenflaeche
		glNormal3f(0.0f, -1.0f, 0.0f);
		glColor4f(0.60, 0.85, 0.92, 1);
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();
	return;
}

void Wuerfel_schrott(GLfloat fSeitenLX, GLfloat fSeitenLY, GLfloat fSeitenLZ)
{
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureids[4]);
		glBegin(GL_POLYGON); // Vorderseite
			glColor4f(1, 1, 1, 1);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
			glTexCoord2f(0, 1);
			glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
			glTexCoord2f(1, 1);
			glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
			glTexCoord2f(1, 0);
			glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureids[4]);
		glBegin(GL_POLYGON); // Rechte Seite
			glColor4f(1, 1, 1, 1);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
			glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
			glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
			glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureids[4]);
		glBegin(GL_POLYGON); // Rueckseite
			glColor4f(1, 1, 1, 1);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
			glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
			glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
			glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureids[4]);
		glBegin(GL_POLYGON); // Linke Seite
			glColor4f(1, 1, 1, 1);	
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
			glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
			glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
			glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureids[4]);
		glColor4f(1, 1, 1, 1);
		glBegin(GL_POLYGON); // Deckflaeche
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
			glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
			glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
			glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureids[4]);
		glBegin(GL_POLYGON); // Bodenflaeche
			glColor4f(1, 1, 1, 1);
			glNormal3f(0.0f, -1.0f, 0.0f);
			glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
			glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
			glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
			glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	return;
}
