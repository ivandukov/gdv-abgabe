/*
 *   wuerfel.cpp definiert einen Wuerfel ueber seine 6 Seiten
 *   Last Update:  13.10.2011   W.-D. Groch
 */
#include <GL/freeglut.h>
#include "Wuerfel.h"


void Wuerfel(GLfloat fSeitenL)
{
	glBegin(GL_POLYGON); // Vorderseite
	glNormal3f(0.0f, 0.0f, 1.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // ROT
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); // GELB
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // WEISS
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); // MAGENTA
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON); // Rechte Seite
	glNormal3f(1.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); // GELB
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); // GRUEN
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f); // CYAN
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // WEISS
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON); // Rueckseite
	glNormal3f(0.0f, 0.0f, -1.0f);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f); // CYAN
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); // GRUEN
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); // SCHWARZ
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON); // Linke Seite
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); // SCHWARZ
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // ROT	
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); // MAGENTA
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Deckflaeche
	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); // MAGENTA
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // WEISS
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f); // CYAN
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Bodenflaeche
	glNormal3f(0.0f, -1.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); // SCHWARZ
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); // GRUEN
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); // GELB
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // ROT
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	return;
}

void Wuerfel(GLfloat fSeitenLX, GLfloat fSeitenLY, GLfloat fSeitenLZ)
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


void Wuerfel_ohne_Farben(GLfloat fSeitenL)
{
	glBegin(GL_POLYGON); // Vorderseite
	glNormal3f(0.0f, 0.0f, 1.0f);
	glColor4f(0, 0, 0, 1.0);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);

	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);

	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON); // Rechte Seite
	glNormal3f(1.0f, 0.0f, 0.0f);
	glColor4f(0, 0, 0, 1.0);
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);

	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);

	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON); // Rueckseite
	glNormal3f(0.0f, 0.0f, -1.0f);
	glColor4f(0, 0, 0, 1.0);
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);

	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);

	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON); // Linke Seite
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glColor4f(0, 0, 0, 1.0);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);

	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);

	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Deckflaeche
	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(0, 0, 0, 1.0);
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);

	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);

	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);

	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON); // Bodenflaeche
	glNormal3f(0.0f, -1.0f, 0.0f);
	glColor4f(0, 0, 0, 1.0);
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);

	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);

	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);

	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	return;
}