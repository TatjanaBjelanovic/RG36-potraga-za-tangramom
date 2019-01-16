#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "slike.h"

void slika6()
{
    //VELIKI TROUGAO 1 
    
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(0.25,0.25,0);
             glRotatef(180,0,0,1);
                        
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    //VELIKI TROUGAO 2
    glPushMatrix();
            
            glColor3f(1, 0, 0);
            
            glTranslatef(-0.25,-0.25,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    // MALI TROUGAO 1
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(0.25/2,-0.25,0);
            glRotatef(-90,0,0,1);
                        
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //MALI TROUGAO 2
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(-0.25/2,-0.25,0);
            glRotatef(180,0,0,1);
                        
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //KVADRAT
    glPushMatrix();
            glColor3f(1,0,0);
            
            glTranslatef(-0.25/2,-0.5,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25,0.25,0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //PARALELOGRAM
    glPushMatrix();
            glColor3f(1,0,0);
            
            glTranslatef(0.25,0.6,0);
            glRotatef(135,0,0,1);
            
                       
            glBegin(GL_POLYGON);
                glVertex3f(0.25, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
                glVertex3f(0, 0.25, 0);
            glEnd();
    glPopMatrix();
    
    
    //SEREDNJI TROUGAO
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(-0.25,0.25,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
            glEnd();
    glPopMatrix();
}

//////////////////////////////////slika 5555555555555555555555555555555555555
void slika5()
{
    //VELIKI TROUGAO 1 
    
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(0,0.25,0);
            glRotatef(180,0,0,1);
                        
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    //VELIKI TROUGAO 2
    glPushMatrix();
            
            glColor3f(1, 0, 0);
            
            glTranslatef(-0.5,-0.25,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    // MALI TROUGAO 1
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(0,-0.25,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //MALI TROUGAO 2
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(0.25,0,0);
            glRotatef(180,0,0,1);
                        
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //KVADRAT
    glPushMatrix();
            glColor3f(1,0,0);
            
            
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25,0.25,0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //PARALELOGRAM
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(-0.25,0.25,0);
            
                       
            glBegin(GL_POLYGON);
                glVertex3f(0.25, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
                glVertex3f(0, 0.25, 0);
            glEnd();
    glPopMatrix();
    
    
    //SEREDNJI TROUGAO
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(-0.5,0.25,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
            glEnd();
    glPopMatrix();
}

////////////////////////////////slika 444444444444444444444444444444444444
void slika4()
{
    //VELIKI TROUGAO 1 
    
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glRotatef(90,0,0,1);
            
                        
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    //VELIKI TROUGAO 2
    glPushMatrix();
            
            glColor3f(1, 0, 0);
            
            glRotatef(180,0,0,1);
            
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    // MALI TROUGAO 1
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(0,0.25/2,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //MALI TROUGAO 2
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            
            glTranslatef(0,-0.25/2,0);
            glRotatef(-90,0,0,1);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //KVADRAT
    glPushMatrix();
            glColor3f(1,0,0);
            
            glTranslatef(0,-0.25/2,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25,0.25,0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //PARALELOGRAM
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(0.5,-0.25/2,0);
            glRotatef(90,0,0,1);
            
            
            
            glBegin(GL_POLYGON);
                glVertex3f(0.25, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
                glVertex3f(0, 0.25, 0);
            glEnd();
    glPopMatrix();
    
    
    //SEREDNJI TROUGAO
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(0.5,-0.25-0.25/2,0);
            glRotatef(90,0,0,1);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
            glEnd();
    glPopMatrix();
}

///////////////////////////////////////slika 33333333333333333333333333333333333333333
void slika3()
{
  //VELIKI TROUGAO 1 
    
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(0,0.5,0);
            glRotatef(180,0,0,1);
                        
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    //VELIKI TROUGAO 2
    glPushMatrix();
            
            glColor3f(1, 0, 0);
            
            
            
             glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    // MALI TROUGAO 1
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(-0.5,0.25,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //MALI TROUGAO 2
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(0.5,0.35,0);
            glRotatef(-45,0,0,1);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //KVADRAT
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(0.5,0,0);
            glRotatef(45,0,0,1);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25,0.25,0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //PARALELOGRAM
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            glTranslatef(-0.5,0,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0.25, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
                glVertex3f(0, 0.25, 0);
            glEnd();
    glPopMatrix();
    
    
    //SEREDNJI TROUGAO
    glPushMatrix();
            glColor3f(1, 0, 0);
                        
            glTranslatef(0.5+0.2,0.5+0.25/4-0.01,0);
            glRotatef(180,0,0,1);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
            glEnd();
    glPopMatrix();
}

// SLIKA 222222222222222222222222222222222222222222222222222222
void slika2()
{
     //VELIKI TROUGAO 1 
    
    glPushMatrix();
            glColor3f(1, 0, 1);
            
            glRotatef(-90,0,0,1);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    //VELIKI TROUGAO 2
    glPushMatrix();
            
            glColor3f(1, 0, 1);
            
            glTranslatef(0.5,-0.5,0);
            glRotatef(90,0,0,1);
                        
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    // MALI TROUGAO 1
    glPushMatrix();
            glColor3f(1, 0, 1);
            
            glTranslatef(0.25,0.25,0);
            glRotatef(180,0,0,1);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //MALI TROUGAO 2
    glPushMatrix();
            glColor3f(1, 0,1); 
            
            glTranslatef(0.25,0,0);
            
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //KVADRAT
    glPushMatrix();
            glColor3f(1, 0, 1);
            
            glTranslatef(0.25/2,0.25,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25,0.25,0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //PARALELOGRAM
    glPushMatrix();
            glColor3f(1, 0, 1);
            
            glTranslatef(0.25,0,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0.25, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
                glVertex3f(0, 0.25, 0);
            glEnd();
    glPopMatrix();
    
    
    //SEREDNJI TROUGAO
    glPushMatrix();
            glColor3f(1, 0, 1);
            
            glTranslatef(-0.25,0,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
            glEnd();
    glPopMatrix();
}
////// SLIKA 111111111111111111111111111111111111111111111111111111111111111111

void slika1()
{
    //VELIKI 1
    glPushMatrix();
            glColor3f(0, 0, 1);
            
            glTranslatef(0,-0.5,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    //VELIKI 2
    glPushMatrix();
            glColor3f(0, 0, 1);
            
            glTranslatef(0.5,0,0);
            glRotatef(180,0,0,1);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    //MALI 1
    glPushMatrix();
            glColor3f(0, 0, 1);
            
            glTranslatef(0.25,0.5,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    //MALI 2
    glPushMatrix();
            glColor3f(0, 0, 1);
            
            glTranslatef(0.25,0.5,0);
            glRotatef(90,0,0,1);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    //KVADRAT
    glPushMatrix();
            glColor3f(0, 0, 1);
            
            glTranslatef(0.25/2,0.25,0);

            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25,0.25,0);
                glVertex3f(0.25, 0, 0);
            glEnd();
	
    glPopMatrix();
    
    
    // PARALELOPIPED
    glPushMatrix();
            glColor3f(0, 0, 1);
            
            glTranslatef(0.25/2,0,0);
            
            
            glBegin(GL_POLYGON);
                glVertex3f(0.25, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
                glVertex3f(0, 0.25, 0);
            glEnd();
    glPopMatrix();
    
    //SREDNJI TROUGAO
    glPushMatrix();
            glColor3f(0, 0, 1);
            
            glTranslatef(-0.25/2,0,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
            glEnd();
    glPopMatrix();
    
}



void podloga()
{

	glScalef(5,2,5);
	glTranslatef(0,-5,0);
	glutSolidCube(5);
	

}









































