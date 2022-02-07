/*
    wuerfel.cpp definiert einen Würfel über seine 6 Seiten
    Last Update:  13.10.2011   W.-D. Groch
*/ 
#include <GL/freeglut.h>
#include "Wuerfel.h"


void Wuerfel(GLfloat fSeitenL)
{ 
	glBegin(GL_POLYGON);   //Vorderseite
	glColor4f(1.0f,0.0f,0.0f,1.0f);	//ROT
	glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
	glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB
	glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
	glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS
	glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
	glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA
	glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rechte Seite
	glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB
	glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
	glColor4f(0.0f,1.0f,0.0f,1.0f); //GRUEN
	glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
	glColor4f(0.0f,1.0f,1.0f,1.0f);	//CYAN
	glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
	glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS
	glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rueckseite
	glColor4f(0.0f,1.0f,1.0f,1.0f); //CYAN
	glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
	glColor4f(0.0f,1.0f,0.0f,1.0f); //GRUEN
	glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
	glColor4f(0.0f,0.0f,0.0f,1.0f); //SCHWARZ
	glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
	glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
	glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite
	glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
	glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
	glColor4f(0.0f,0.0f,0.0f,1.0f); //SCHWARZ
	glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
	glColor4f(1.0f,0.0f,0.0f,1.0f); //ROT	
	glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
	glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA
	glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA
	glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
	glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS
	glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
	glColor4f(0.0f,1.0f,1.0f,1.0f); //CYAN
	glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
	glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
	glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glColor4f(0.0f,0.0f,0.0f,1.0f); //SCHWARZ
	glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
	glColor4f(0.0f,1.0f,0.0f,1.0f); //GRUEN
	glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
	glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB
	glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
	glColor4f(1.0f,0.0f,0.0f,1.0f); //ROT
	glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
	glEnd();

	return;
}