#include <math.h>
#include <GL/glut.h>

static void on_display(void);


int main(int argc, char **argv)
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    
    
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    
    glutDisplayFunc(on_display);

    
    glClearColor(0, 0, 0, 0);

    
    glutMainLoop();
    
    return 0;
}

static void on_display(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(5, 0, 1);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(-0.5, 0.5, 0);
        glVertex3f(0.5, 0.5, 0);
    glEnd();
    
    
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(-0, 0, 0);
    glEnd();
    
    glColor3f(0, 2, 1);
    glBegin(GL_POLYGON);
        glVertex3f(0, 0, 0);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(-0.5, 0.5, 0);
    glEnd();
    
    
    glColor3f(0, 0.8, 1);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0, 0);
        glVertex3f(0, 0.5, 0);
        glVertex3f(0.5, 0.5, 0);
    glEnd();
    
    
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex3f(0, 0, 0);
        glVertex3f(-0.25, 0.25, 0);
        glVertex3f(0, 0.5, 0);
        glVertex3f(0.25, 0.25, 0);
    glEnd();
    
    
    
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.25, 0.25, 0);
        glVertex3f(-0.5, 0.5, 0);
        glVertex3f(0, 0.5, 0);
    glEnd();
    
    
    glColor3f(0, 0.3, 0);
    glBegin(GL_POLYGON);
        glVertex3f(0.25, -0.25, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0.25, 0.25, 0);
    glEnd();
    
    
    glColor3f(0.4, 0, 0);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(0.25, -0.25, 0);
        glVertex3f(0.25, 0.25, 0);
        glVertex3f(0.5, 0, 0);
    glEnd();
   
    
    glutSwapBuffers();
}
