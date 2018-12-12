#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>


static int headlight = 0;
const static float pi = 3.141592653589793;
static float phi, theta;
static float delta_phi, delta_theta;


static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);


int main(int argc, char **argv)
{
    
    GLfloat light_ambient[] = { 1, 0.1, 0.1, 1 };
    GLfloat light_diffuse[] = { 0, 0.7, 0, 1 };
    GLfloat light_specular[] = { 1, 0.2, 0.1, 1 };

    GLfloat ambient_coeffs[] = { 0.3, 0.7, 0.3, 1 };
    GLfloat diffuse_coeffs[] = { 0.2, 1, 0.2, 1 };
    GLfloat specular_coeffs[] = { 1, 1, 0 , 1 };
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    
    phi = theta = 0;
    delta_phi = delta_theta = pi / 90;

    
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);

    
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    

    
    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;

    case 'd':
        
        phi -= delta_phi;
        if (phi > 2 * pi) {
            phi -= 2 * pi;
        } else if (phi < 0) {
            phi += 2 * pi;
        }
        glutPostRedisplay();
        break;

    case 'a':
        
        phi += delta_phi;
        if (phi > 2 * pi) {
            phi -= 2 * pi;
        } else if (phi < 0) {
            phi += 2 * pi;
        }
        glutPostRedisplay();
        break;

    case 'r':
    case 'R':
        
        phi = theta = 0;
        glutPostRedisplay();
        break;

    case 'w':
    
        theta -= delta_theta;
        if (theta < -(pi / 2 - pi / 180)) {
            theta = -(pi / 2 - pi / 180);
        }
        glutPostRedisplay();
        break;

    case 's':
        
        theta += delta_theta;
        if (theta > pi / 2 - pi / 180) {
            theta = pi / 2 - pi / 180;
        }
        glutPostRedisplay();
        break;
    }
}

static void on_reshape(int width, int height)
{
    
    glViewport(0, 0, width, height);

    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float) width / height, 1, 10);
}

static void on_display(void)
{

    GLfloat light_position[] = { 0, 1, 1, 0 };

    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
    gluLookAt(6 * cos(theta) * cos(phi),
              6 * cos(theta) * sin(phi),
              6 * sin(theta),
              0, 0, 0, 0, 0, 1);




    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    glRotatef(90, 0, 0, 1);
    glRotatef(90, 1, 1, 0);
    glutWireCube(3);


    glutSwapBuffers();
}
