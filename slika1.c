#include <GL/glut.h>
#include <stdlib.h>

/* Deklaracije callback funkcija. */
static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);


static int rotation_parametar= 0;

int main(int argc, char **argv)
{
    /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    /* Kreira se prozor. */
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(200, 200);
    glutCreateWindow(argv[0]);

    /* Registruju se callback funkcije. */
    glutDisplayFunc(on_display);
    glutKeyboardFunc(on_keyboard);
    
    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0.75, 0.75, 0.75, 0);

    /* Program ulazi u glavnu petlju. */
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

    
    //VELIKI 1
    glPushMatrix();
            glColor3f(0, 0, 1);
            //glRotatef(-225+rotation_parametar,0,0,1);
            //glTranslatef(0,0,0);
            
            glRotatef(225,0,0,1);
            glTranslatef(0.25,0.25,0);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    //VELIKI 2
    glPushMatrix();
            //glRotatef(45+rotation_parametar,0,0,1);
            glRotatef(135,0,0,1);
            glTranslatef(-0.25,0,0);
            glColor3f(0, 0, 1);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    //MALI 1
    glPushMatrix();
            glColor3f(0, 0, 1);
            //glRotatef(45+rotation_parametar,0,0,1);
            glRotatef(-45,0,0,1);
            glTranslatef(0.25,-0.25,0);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    //MALI 2
    glPushMatrix();
            glColor3f(0, 0, 1);
            //glRotatef(-45+rotation_parametar,0,0,1);
            //glTranslatef(0,0.25,0);
            glRotatef(-45,0,0,1);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    //KVADRAT
    glPushMatrix();
            glColor3f(0, 0, 1);
            //glRotatef(45,0,0,1);
            //glTranslatef(0,0.25,0);
            glTranslatef(-0.25/2,0.25,0);
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
            //glRotatef(-45,0,0,1);
            //glTranslatef(0,0.25,0);
            glRotatef(125,0,0,1);
            glTranslatef(0.40,-0.55,0);
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
            //glRotatef(-45,0,0,1);
            //glTranslatef(-0.250,0.25,0);
            glRotatef(180,0,0,1);
            glTranslatef(-0.25,-0.25,0);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
            glEnd();
    glPopMatrix();
    
    

    glutSwapBuffers();
}
