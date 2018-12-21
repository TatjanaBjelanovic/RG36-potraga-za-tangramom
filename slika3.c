#include <GL/glut.h>
#include <stdlib.h>

/* Deklaracije callback funkcija. */
static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);


static int rotation_parametar= 0;

int main(int argc, char **argv)
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(300, 300);
    glutInitWindowPosition(200, 200);
    glutCreateWindow(argv[0]);

    
    glutDisplayFunc(on_display);
    glutKeyboardFunc(on_keyboard);
    
    
    glClearColor(0.75, 0.75, 0.75, 0);


    glutMainLoop();

    return 0;
}


static void on_keyboard(unsigned char key, int x, int y)
     {
         switch (key) {
         case 27:
             exit(0);
             break;
         
             
         }      
     }



static void on_display(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);

    //VELIKI TROUGAO 1 
    
    glPushMatrix();
            glColor3f(1, 0, 0);
            glTranslatef(-0.5,0.25,0);
            glRotatef(270,0,0,1);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    //VELIKI TROUGAO 2
    glPushMatrix();
            
            glColor3f(1, 0, 0);
            glTranslatef(0.25,0,0);
             glRotatef(90,0,0,1);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    // MALI TROUGAO 1
    glPushMatrix();
            glColor3f(1, 0, 0);
            glTranslatef(-0.5,0.5,0);
            glRotatef(180,0,0,1);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //MALI TROUGAO 2
    glPushMatrix();
            glColor3f(1, 0, 0);
            glTranslatef(-0.25,-0.25,0);
            glRotatef(90,0,0,1);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //KVADRAT
    glPushMatrix();
            glColor3f(1, 0, 0);
            glTranslatef(0,-0.25,0);
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
            glRotatef(90,0,0,1);
            glTranslatef(0.5,-0.5,0);
            
            
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
            glTranslatef(0.25,0.5,0);
                        
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
            glEnd();
    glPopMatrix();
    
    

    glutSwapBuffers();
}
