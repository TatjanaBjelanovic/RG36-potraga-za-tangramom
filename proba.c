#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>

/* Deklaracije callback funkcija. */
static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);


static float rotation_parameter= 0;
static float translaton_parameter_X = 0;
static float translaton_parameter_Y = 0;

static int ID = 0;

//kordinate mreze
static float x1,x2,y1,y2;


static void draw_debug_coosys()
{
    
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(1, 0, 0);
    glVertex3f(0, 0, 0);
 
    glColor3f(0, 1, 0);
    glVertex3f(0, 1, 0);
    glVertex3f(0, 0, 0);
 
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glEnd();

}

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
             
           
         case 'a':
             translaton_parameter_X -= 0.01;   
             glutPostRedisplay();
        break;
    case 'd':
            translaton_parameter_X += 0.01;   
            glutPostRedisplay();
        break;
    case 'w':
            translaton_parameter_Y += 0.01;   
            glutPostRedisplay();
        break;
    case 's':
            translaton_parameter_Y -= 0.01;   
            glutPostRedisplay();
        break;
    
    case 'j':
            rotation_parameter += 1;
            glutPostRedisplay();
        break;
        
    case 'l':
            rotation_parameter -= 1;
            glutPostRedisplay();
        break;    
             
             
             
             
             
             
             
    case '1':
        if(ID != 1)
            ID = 1;
        glutPostRedisplay();
	     break;
	case '2':
		if(ID != 2)
			ID = 2;
        glutPostRedisplay();
	     break;
	case '3':
        if(ID != 3)
			ID = 3;           
        glutPostRedisplay();
	     break;
             
	case '4':
         if(ID != 4)    
			ID = 4;       
         glutPostRedisplay();
	     break;

	case '5':
         if(ID != 5)
			ID = 5;           
         glutPostRedisplay();
	     break;
	
	case '6':
         if(ID != 6)
			ID = 6;           
         glutPostRedisplay();
	     break;
	
	case '7':
         if(ID != 7)
			ID = 7;           
         glutPostRedisplay();
	     break;
         
    
         }      
     }


void VELIKI_TROUGAO1()
{
	glPushMatrix();
            glColor3f(0, 0.2, 0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
}

void VELIKI_TROUGAO2()
{
	glPushMatrix();
            glColor3f(0.1, 0.1, 0.41);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
}

void MALI_TROUGAO1()
{
	glPushMatrix();
            glColor3f(0.8, 0.2, 0.8);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
}


void MALI_TROUGAO2()
{
	glPushMatrix();
            glColor3f(0, 0, 0.7);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
}


void KVADRAT()
{
	glPushMatrix();
            glColor3f(0.25, 0.47, 0.8);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25,0.25,0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
}


void PARALELOGRA()
{
	glPushMatrix();
            glColor3f(0.8, 1, 0.8);
            glBegin(GL_POLYGON);
                glVertex3f(0.25, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
                glVertex3f(0, 0.25, 0);
            glEnd();
    glPopMatrix();
}

void SREDNJI_TROUGAO()
{
	glPushMatrix();
            glColor3f(0, 0.25, 0.8);
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
            glEnd();
    glPopMatrix();
}

void slika(){
     glPushMatrix();
   glTranslatef(-0.25,0,0);
 
     
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
                GLfloat x = 0;
                glVertex3f(x, 0, 0);
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
    
    ;
    
    glPopMatrix();

}

void linije(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(x1, y1, 0);
        glVertex3f(x2, y2, 0);
    glEnd();
    
}

void mreza()
{
    
    for((x1=(-1)) && (x2=(-1)); (x1<=1) && (x2<=1);(x1= x1+0.1) && (x2 = x2+ 0.1))
    {
        y1=1;
        y2=-1;
         linije(x1,y1,x2,y2);
           
    }
     for((y1=(-1)) && (y2=(-1)); (y1<=1) && (y2<=1);(y1= y1+0.1) && (y2 = y2+ 0.1))
    {
        x1=1;
        x2=-1;
         linije(x1,y1,x2,y2);
           
    }
}

void kretanje()
{
    glTranslatef(0+translaton_parameter_X,0+translaton_parameter_Y,0);
    glRotatef(-(0+rotation_parameter), 0, 0, 1);
}

static void on_display(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);
	//glTranslatef(0,0,2);
    
    mreza();
    draw_debug_coosys();
    
    slika();
    
    glPushMatrix();
        if(ID == 1)
        {
            //glRotatef(0+rotation_parameter, 0, 0, 1);
            //glTranslatef(0+translaton_parameter_X,0+translaton_parameter_Y,0);
            //glRotatef(-(0+rotation_parameter), 0, 0, 1);
            kretanje();
        }
        VELIKI_TROUGAO1();
        
        
    glPopMatrix(); 
    
    
   
    glPushMatrix();
        if(ID == 2)
        {
            
            kretanje();
            
        }
    VELIKI_TROUGAO2();
    glPopMatrix();
    
    glPushMatrix();
        if(ID == 3)
        {
            kretanje();
            
        }
    
    MALI_TROUGAO1();
    glPopMatrix();
    
    glPushMatrix();
        if(ID == 4)
        {
            kretanje();
            
        }
    
    MALI_TROUGAO2();
    glPopMatrix();
    
    
    glPushMatrix();
        if(ID == 5)
        {
            kretanje();
            
        }
    
    KVADRAT();
    glPopMatrix();
    
    
    glPushMatrix();
        if(ID == 6)
        {
            kretanje();
            
        }
    
    PARALELOGRA();
    glPopMatrix();
    
    
    glPushMatrix();
        if(ID == 7)
        {
            kretanje();
            
        }
    
    SREDNJI_TROUGAO();
    glPopMatrix();
    

    





































	
    glutSwapBuffers();
}
