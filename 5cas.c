#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>

/* Deklaracije callback funkcija. */
static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);


static float rotation_parameter= 0;
static float translaton_parameter_X = 0;
static float translaton_parameter_Y = 0;

//Transformacija *koordinate ;

static int ID = 0;

//kordinate mreze
static float x1,x2,y1,y2;


// struktura koja pamti pozicije trenutnih transformacija koje su se izvele nad
//odredjenim elementom 
typedef struct 
{
    GLfloat TR_X ;
    GLfloat TR_Y ;
    GLfloat RT ;
}Transformacija;


//struktura koja cuva transformacije koje su primenjene da bi se nacrtala slika
typedef struct
{
    GLfloat slika_TX;
    GLfloat slika_TY;
    GLfloat slika_R;
}Slika;

Transformacija *koordinate;

Slika *tacke;

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

    
     koordinate = calloc(30, sizeof(Transformacija));
    if(koordinate == NULL)
        return -1;
    
    
    tacke = calloc(30, sizeof(Slika));
    if(tacke == NULL)
        return -1;
    
    
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
        {
            ID = 1;
            translaton_parameter_X= koordinate[1].TR_X;
            translaton_parameter_Y = koordinate[1].TR_Y;
            rotation_parameter= koordinate[1].RT;
        }
        glutPostRedisplay();
	     break;
	case '2':
		if(ID != 2){
			ID = 2;
            translaton_parameter_X= koordinate[2].TR_X;
            translaton_parameter_Y = koordinate[2].TR_Y;
            rotation_parameter= koordinate[2].RT;
        }
        glutPostRedisplay();
	     break;
	case '3':
        if(ID != 3){
			ID = 3;
            translaton_parameter_X= koordinate[3].TR_X;
            translaton_parameter_Y = koordinate[3].TR_Y;
            rotation_parameter= koordinate[3].RT;
        }
        glutPostRedisplay();
	     break;
             
	case '4':
         if(ID != 4)
         {
            ID = 4;
            translaton_parameter_X= koordinate[4].TR_X;
            translaton_parameter_Y = koordinate[4].TR_Y;
            rotation_parameter= koordinate[4].RT;
         }
            glutPostRedisplay();
	     break;

	case '5':
         if(ID != 5){
             ID=5;
			translaton_parameter_X= koordinate[5].TR_X;
            translaton_parameter_Y = koordinate[5].TR_Y;
            rotation_parameter= koordinate[5].RT;
         }
         glutPostRedisplay();
	     break;
	
	case '6':
         if(ID != 6)
         {
			ID = 6;
            translaton_parameter_X= koordinate[6].TR_X;
            translaton_parameter_Y = koordinate[6].TR_Y;
            rotation_parameter= koordinate[6].RT;
         }
         glutPostRedisplay();
	     break;
	
	case '7':
         if(ID != 7)
         {
			ID = 7;
            translaton_parameter_X= koordinate[7].TR_X;
            translaton_parameter_Y = koordinate[7].TR_Y;
            rotation_parameter= koordinate[7].RT;
         }
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
    //printf("%f%f%f\n", a, b, c);
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
   //glTranslatef(-0.25,0,0);
 
     
   //VELIKI TROUGAO 1 
    
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            tacke[1].slika_TX = 0;
            tacke[1].slika_TY = 0.25;
            tacke[1].slika_R = 180;
            
            glTranslatef(tacke[1].slika_TX, tacke[1].slika_TY,0);
            glRotatef(tacke[1].slika_R,0,0,1);
                        
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    //VELIKI TROUGAO 2
    glPushMatrix();
            
            glColor3f(1, 0, 0);
            
            tacke[2].slika_TX = -0.5;
            tacke[2].slika_TY = -0.25;
            tacke[2].slika_R = 0;
            
            glTranslatef(tacke[2].slika_TX, tacke[2].slika_TY,0);
            glRotatef(tacke[2].slika_R,0,0,1);
            
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0, 0.5, 0);
            glEnd();
    glPopMatrix();
    
    
    // MALI TROUGAO 1
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            
            tacke[3].slika_TX = 0;
            tacke[3].slika_TY = -0.25;
            tacke[3].slika_R = 0;
            
            glTranslatef(tacke[3].slika_TX, tacke[3].slika_TY,0);
            glRotatef(tacke[3].slika_R,0,0,1);
            
            
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //MALI TROUGAO 2
    glPushMatrix();
            glColor3f(1, 0, 0);
            
            tacke[4].slika_TX = 0.25;
            tacke[4].slika_TY = 0;
            tacke[4].slika_R = 180;
            
            glTranslatef(tacke[4].slika_TX, tacke[4].slika_TY,0);
            glRotatef(tacke[4].slika_R,0,0,1);
            
            
            //glTranslatef(0.25,0,0);
            //glRotatef(180,0,0,1);
                        
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.25, 0);
                glVertex3f(0.25, 0, 0);
            glEnd();
    glPopMatrix();
    
    
    //KVADRAT
    glPushMatrix();
            glColor3f(1,0,0);
            
            tacke[5].slika_TX = 0;
            tacke[5].slika_TY = 0;
            tacke[5].slika_R = 0;
            
            glTranslatef(tacke[5].slika_TX, tacke[5].slika_TY,0);
            glRotatef(tacke[5].slika_R,0,0,1);
            
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
            
            
            tacke[6].slika_TX = -0.25;
            tacke[6].slika_TY = 0.25;
            tacke[6].slika_R = 0;
            
            glTranslatef(tacke[6].slika_TX, tacke[6].slika_TY,0);
            glRotatef(tacke[6].slika_R,0,0,1);
            
            //glTranslatef(-0.25,0.25,0);
            
                       
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
            
            
            tacke[7].slika_TX = -0.5;
            tacke[7].slika_TY = 0.25;
            tacke[7].slika_R = 0;
            
            glTranslatef(tacke[7].slika_TX, tacke[7].slika_TY,0);
            glRotatef(tacke[7].slika_R,0,0,1);
            
            //glTranslatef(-0.5,0.25,0);
            
            glBegin(GL_POLYGON);
                glVertex3f(0, 0, 0);
                glVertex3f(0.5, 0, 0);
                glVertex3f(0.25, 0.25, 0);
            glEnd();
    glPopMatrix();
    
    
    
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
    /*
    translaton_parameter_X = koordinate[ID].TR_X;
    translaton_parameter_Y = koordinate[ID].TR_Y;
    rotation_parameter = koordinate[ID].RT; 
    */
    
    glTranslatef(0+translaton_parameter_X,0+translaton_parameter_Y,0);
    glRotatef(-(0+rotation_parameter), 0, 0, 1);
    
}


      
        


static void on_display(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);
	//glTranslatef(0,1,2);
    
    mreza();
    draw_debug_coosys();
    
    slika();
    
    
    //Transformacija koordinate[];
    
    glPushMatrix();
    
     
        if(ID == 1)
        {
            
            kretanje();
            
            koordinate[1].TR_X = translaton_parameter_X;
            koordinate[1].TR_Y = translaton_parameter_Y;
            koordinate[1].RT = rotation_parameter;
            
        }
        else
        {
             glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
             glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
        }
    
        
        if( (koordinate[1].TR_X = tacke[1].slika_TX) && (koordinate[1].TR_Y = tacke[1].slika_TY) && ( koordinate[1].RT = tacke[1].slika_R) )
        {
            printf("Na dobrom je mestu");
        }
            
            printf("%.2f %.2f %.2f\n",koordinate[1].TR_X, koordinate[1].TR_Y, koordinate[1].RT);
            printf("%.2f %.2f %.2f\n", tacke[1].slika_TX, tacke[1].slika_TY, tacke[1].slika_R);
            
        
             
        VELIKI_TROUGAO1();
        
       
    glPopMatrix(); 
    
    
   
    glPushMatrix();
        if(ID == 2)
        {
            kretanje();
            
            koordinate[2].TR_X = translaton_parameter_X;
            koordinate[2].TR_Y = translaton_parameter_Y;
            koordinate[2].RT = rotation_parameter;
            
        }
        else
        {
             glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
             glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
        }

        if( (koordinate[2].TR_X = tacke[2].slika_TX) && (koordinate[2].TR_Y = tacke[2].slika_TY) && ( koordinate[2].RT = tacke[2].slika_R) )
        {
            printf("Na dobrom je mestu");
        }
            
            printf("%.2f %.2f %.2f\n",koordinate[2].TR_X, koordinate[2].TR_Y, koordinate[2].RT);
            printf("%.2f %.2f %.2f\n", tacke[2].slika_TX, tacke[2].slika_TY, tacke[2].slika_R);
            
        
        
        VELIKI_TROUGAO2();
        
    glPopMatrix();
    
    glPushMatrix();
    
    
         if(ID == 3)
        {
            
                 
            kretanje();
            
            koordinate[3].TR_X = translaton_parameter_X;
            koordinate[3].TR_Y = translaton_parameter_Y;
            koordinate[3].RT = rotation_parameter;
            
            
        }
        else
        {
             glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
             glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
        }
        
        if( (koordinate[3].TR_X = tacke[3].slika_TX) && (koordinate[3].TR_Y = tacke[3].slika_TY) && ( koordinate[3].RT = tacke[3].slika_R) )
        {
            printf("Na dobrom je mestu");
        }
            
            printf("%.2f %.2f %.2f\n",koordinate[3].TR_X, koordinate[3].TR_Y, koordinate[3].RT);
            printf("%.2f %.2f %.2f\n", tacke[3].slika_TX, tacke[3].slika_TY, tacke[3].slika_R);
            
    
    MALI_TROUGAO1();
    glPopMatrix();
    
    glPushMatrix();
         if(ID == 4)
        {
                   
            
            kretanje();
            
            koordinate[4].TR_X = translaton_parameter_X;
            koordinate[4].TR_Y = translaton_parameter_Y;
            koordinate[4].RT = rotation_parameter;
            
        }
        else
        {
             glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
             glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
        }
        
        
        if( (koordinate[4].TR_X = tacke[4].slika_TX) && (koordinate[4].TR_Y = tacke[4].slika_TY) && ( koordinate[4].RT = tacke[4].slika_R) )
        {
            printf("Na dobrom je mestu");
        }
            
            printf("%.2f %.2f %.2f\n",koordinate[4].TR_X, koordinate[4].TR_Y, koordinate[4].RT);
            printf("%.2f %.2f %.2f\n", tacke[4].slika_TX, tacke[4].slika_TY, tacke[4].slika_R);
            
    MALI_TROUGAO2();
    glPopMatrix();
    
    
    glPushMatrix();
         if(ID == 5)
        {
            kretanje();
            
            koordinate[5].TR_X = translaton_parameter_X;
            koordinate[5].TR_Y = translaton_parameter_Y;
            koordinate[5].RT = rotation_parameter;
            
        }
        else
        {
             glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
             glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
        }
    
    
    if( (koordinate[5].TR_X = tacke[5].slika_TX) && (koordinate[5].TR_Y = tacke[6].slika_TY) && ( koordinate[5].RT = tacke[5].slika_R) )
        {
            printf("Na dobrom je mestu");
        }
            
            printf("%.2f %.2f %.2f\n",koordinate[5].TR_X, koordinate[5].TR_Y, koordinate[5].RT);
            printf("%.2f %.2f %.2f\n", tacke[5].slika_TX, tacke[5].slika_TY, tacke[5].slika_R);
            
    
    
    KVADRAT();
    glPopMatrix();
    
    
    glPushMatrix();
         if(ID == 6)
        {
                                 
            kretanje();
            
            koordinate[6].TR_X = translaton_parameter_X;
            koordinate[6].TR_Y = translaton_parameter_Y;
            koordinate[6].RT = rotation_parameter;
            
        }
        else
        {
             glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
             glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
        }
    
    if( (koordinate[6].TR_X = tacke[6].slika_TX) && (koordinate[6].TR_Y = tacke[6].slika_TY) && ( koordinate[6].RT = tacke[6].slika_R) )
        {
            printf("Na dobrom je mestu");
        }
            
            printf("%.2f %.2f %.2f\n",koordinate[6].TR_X, koordinate[6].TR_Y, koordinate[6].RT);
            printf("%.2f %.2f %.2f\n", tacke[6].slika_TX, tacke[6].slika_TY, tacke[6].slika_R);
            
    PARALELOGRA();
    glPopMatrix();
    
    
    glPushMatrix();
        
            if(ID == 7)
            {
                kretanje();
            
                koordinate[7].TR_X = translaton_parameter_X;
                koordinate[7].TR_Y = translaton_parameter_Y;
                koordinate[7].RT = rotation_parameter;
            
            }
            else
            {
                glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
            }
        
    
    if( (koordinate[7].TR_X = tacke[7].slika_TX) && (koordinate[7].TR_Y = tacke[7].slika_TY) && ( koordinate[7].RT = tacke[7].slika_R) )
        {
            printf("Na dobrom je mestu");
        }
            
            printf("%.2f %.2f %.2f\n",koordinate[7].TR_X, koordinate[7].TR_Y, koordinate[7].RT);
            printf("%.2f %.2f %.2f\n", tacke[7].slika_TX, tacke[7].slika_TY, tacke[7].slika_R);
            
    
    SREDNJI_TROUGAO();
    glPopMatrix();
    

    
	
    glutSwapBuffers();
}
