#include <stdlib.h>
#include <math.h>
#include "slike.h"
#include <GL/glut.h>
#include<stdio.h>
#include<time.h>
#include"bitno.h"
   /* Konstanta pi. */
   const static float pi = 3.141592653589793;
    
   /* Deklaracije callback funkcija. */
   static void on_keyboard(unsigned char key, int x, int y);
   static void on_reshape(int width, int height);
   static void on_display(void);
   
   //deklaracija funkcija koje pozivaju odredjenu tablu na kojoj se nalazi jedna od varijanti tangrama za slagenje
   static void on_display1(void);
   static void on_display2(void);
   static void on_display3(void);
   static void on_display4(void);
   static void on_display5(void);
   static void on_display6(void);

   static void on_timer(int);
    
  
  static void draw_debug_coosys();
   
    
   /* Parametar animacije, fleg koji odredjuje da li je
    * animacija u toku ili nije */
 #define TIMER_ID 0
 #define TIMER_INTERVAL 10
 
 
 
 float animation_parameter = 0;
 int animation_ongoing = 0;
 float animation_parameter2=-10.0;
 int animacija_u_pokretu = 0;
 
 
 
 
 int kraj = 0;
 int ind=0,ind1=-1; //ind -> indikator za       ind2 -> indikator za
 int red = 0;
/* struktura koja pamti pozicije trenutnih transformacija koje su se izvele nad
odredjenim elementom*/ 


//promeniljive za tangram
int pocni = 0;



static float rotation_parameter= 0;
static float translaton_parameter_X = 0;
static float translaton_parameter_Y = 0;

/*Transformacija *koordinate ;*/

static int ID = 0, br=-5; //id ->        br->

//kordinate mreze

Transformacija *koordinate;

Slika *tacke;
       int smer = 1;
    
void linije(float x11, float y11, float x22, float y22)
{
    glBegin(GL_LINES);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(x11, y11, 0);
        glVertex3f(x22, y22, 0);
    glEnd();
    
}

//mreza iza poligona koji se slaze
void mreza()
{
    static float x1,x2,y1,y2;

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


//kako se krecu elementi od kojih se sastavlja
void kretanje()
{    
    glTranslatef(0+translaton_parameter_X,0+translaton_parameter_Y,0);
    glRotatef(-(0+rotation_parameter), 0, 0, 1);
}
    
      
      
      
     static void on_keyboard(unsigned char key, int x, int y)
     {
        if(kraj==0){
                    switch (key) {
                    case 27:
                        exit(0);
                        break;
                    case 'g':
                    case 'G':
                        animacija_u_pokretu = 1;
                            if(!animation_ongoing){
                
                                    animation_ongoing=1;
                                    glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
                            }
                        break;
                    
                    
                    case 'r':
                        animation_parameter = 0;
                        animation_ongoing = 0;
                        animation_parameter2=-10.0;
                        animacija_u_pokretu = 0;
                        kraj = 0;
                        ind=0,ind1=-1; //ind -> indikator za       ind2 -> indikator za
                        red = 0;
                        glutDisplayFunc(on_display);
                        break;
                        
                    case 's':
                    case 'S':
                        if(animacija_u_pokretu != 0 ){ // MOZEMO DA ZAUSTAVIMO SAM AKO JE VEC U POKRETU INACE NISTA
                            kraj =1;
                            if(ind==0){
                                ind=1;
                                srand(time(0)); // random od ponudjenih 6 biramo onu koja treba da se slaze  
                                ind1=rand()%6; //ind1 koja ce da se slaze...
                                
                                if(ind1 % 2 != 0)
                                    smer = -1;
                                
                                printf("indikator ind1 : %d\n", ind1);
                                printf("indikator ind : %d\n", ind);
                                red = 1;
                                animation_ongoing=0;
                                animation_parameter = 0;
                                animation_parameter2=-10.0;
                                glutDisplayFunc(on_display);
                                
                            }
                            animacija_u_pokretu = 0;
                            
                        }
                        break;
                    }
            }
            else{
             /*  if(ind1==0)
                    glutDisplayFunc(on_display1);
                else if(ind1==1)
                    glutDisplayFunc(on_display2);
                else if(ind1==2)
                    glutDisplayFunc(on_display3);
                else if(ind1==3)
                        glutDisplayFunc(on_display4);
                else if(ind1==4)
                    glutDisplayFunc(on_display5);
                else if(ind1==5)
                    glutDisplayFunc(on_display6);
           */
                
            
               
            switch (key) {
            case 27:
                    exit(0);
                    break;
            
            case 'r':
                    animation_parameter = 0;
                    animation_ongoing = 0;
                    animation_parameter2=-10.0;
                    animacija_u_pokretu = 0;
 
 
 
 
                     kraj = 0;
                     ind=0,ind1=-1; //ind -> indikator za       ind2 -> indikator za sliku koja  ce da se primenjuje
                     red = 0;
                     glutDisplayFunc(on_display);
                        
                    break;
                    
            case 'o':
            {
                
                
                if(ind1==0){
                    red = 5;
                    smer = -1;
                    glutDisplayFunc(on_display1);
                    
                }
                else if(ind1==1){
                    glutDisplayFunc(on_display2);
                }
                else if(ind1==2){
                    glutDisplayFunc(on_display3);
                }
                else if(ind1==3){
                    smer = -1;
                    glutDisplayFunc(on_display4);
                    
                }
                else if(ind1==4){
                    glutDisplayFunc(on_display5);
                }
                else if(ind1==5){
                    smer = -1;
                    glutDisplayFunc(on_display6);
                }
                
                break;
                
                
            }   
            case 'a':
                    translaton_parameter_X -= 0.01;   
                break;
            case 'd':
                    translaton_parameter_X += 0.01;   
                break;
            case 'w':
                    translaton_parameter_Y += 0.01;   
                break;
            case 'x':
                    translaton_parameter_Y -= 0.01;   
                break;
            
            case 'l':
                    rotation_parameter += 1;
                break;
                
            case 'j':
                    rotation_parameter -= 1;
                break;    
            
                
            
                    
                    
            case '1':
                if(ID != 1)
                {
                    ID = 1;
                    translaton_parameter_X=koordinate[1].TR_X;
                    translaton_parameter_Y= koordinate[1].TR_Y;
                    rotation_parameter=koordinate[1].RT;
                }
                    break;
                case '2':
                        if(ID != 2){
                                ID = 2;
                    translaton_parameter_X=koordinate[2].TR_X;
                    translaton_parameter_Y= koordinate[2].TR_Y;
                    rotation_parameter=koordinate[2].RT;
                }
                    break;
                case '3':
                if(ID != 3){
                                ID = 3;
                    translaton_parameter_X=koordinate[3].TR_X;
                    translaton_parameter_Y= koordinate[3].TR_Y;
                    rotation_parameter=koordinate[3].RT;
                }
                    break;
                    
                case '4':
                if(ID != 4)
                {
                    ID = 4;
                    translaton_parameter_X=koordinate[4].TR_X;
                    translaton_parameter_Y= koordinate[4].TR_Y;
                    rotation_parameter=koordinate[4].RT;
                }
                    break;

                case '5':
                if(ID != 5){
                                ID = 5; 
                    translaton_parameter_X=koordinate[5].TR_X;
                    translaton_parameter_Y= koordinate[5].TR_Y;
                    rotation_parameter=koordinate[5].RT;
                }
                    break;
                
                case '6':
                if(ID != 6)
                {
                                ID = 6;
                    translaton_parameter_X=koordinate[6].TR_X;
                    translaton_parameter_Y= koordinate[6].TR_Y;
                    rotation_parameter=koordinate[6].RT;
                }
                    break;
                
                case '7':
                if(ID != 7)
                {
                                ID = 7;
                    translaton_parameter_X=koordinate[7].TR_X;
                    translaton_parameter_Y= koordinate[7].TR_Y;
                    rotation_parameter=koordinate[7].RT;
                }
                
                    break;
            
    
         } 
            



                
                
                
            }
              	   glutPostRedisplay();

     }
    
    

    
    static void on_display(void)
     {
         
          glClear(GL_COLOR_BUFFER_BIT);
          glClearColor(0, 0, 0, 0);
          glEnable(GL_DEPTH_TEST);
        /* Pozicija svetla (u pitanju je beskonacno daleko svetlo). */
         GLfloat light_position[] = {10,10,10, 0 };
      
         /* Brise se prethodni sadrzaj prozora. */
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      
         /* Inicijalizuje se matrica transformacije. */
         glMatrixMode(GL_MODELVIEW);
         glLoadIdentity();
      
        
         
         
         printf("\n%d\n", red);
         if(ind == 1){
                    if(ind1==0){
                        
                        
                        if(red != 1)
                        {
                            
                            gluLookAt(0,0,2,0,0,0,0,1,1);
                        }
                        else{
                            red += 5;
                            gluLookAt(3,0,0, 0, 0, 0, 0, 1, 0);
                            

                        }
                    }
                    
                    else if(ind1 ==1){
                        if(red != 1)
                        {
                            
                            gluLookAt(0,0,2,0,0,0,0,1,1);
                        }
                        else{
                            red += 5;
                            gluLookAt(smer*3,0,0, 0, 0, 0, 0, 1, 0);// mnozi se sa smer da bi se videla slika sa prave strane
                        }
                    }
                    else if(ind1 == 2){
                        
                        if(red != 1)
                        {
                            
                            gluLookAt(0,0,2,0,0,0,0,1,0);
                        }
                        else{
                            red += 5;
                            gluLookAt(0,0,3, 0, 0, 0, 0, 1, 0);
                            
                        }
                    }
                    else if(ind1 == 3){
                       
                        if(red != 1)
                        {
                            
                            gluLookAt(0,0,2,0,0,0,0,1,0);
                        }
                        else{
                            red += 5;
                            gluLookAt(0,0,smer*3, 0, 0, 0, 0, 1, 0); // mnozi se sa smer da bi se videla slika sa prave strane
                            

                        }
                    }
                    else if(ind1 == 4){
                        
                        if(red != 1)
                        {
                            
                            gluLookAt(0,0,2,0,0,0,0,1,1);
                        }
                        else{
                            red += 5;
                            gluLookAt(0,3,0, 0, 0, 0, 0, 0, 1);
                            
                        }
                    }
                    else if(ind1 == 5){
                        
                        if(red != 1)
                        {
                           
                            gluLookAt(0,0,2,0,0,0,0,1,1);
                        }
                        else{
                            red += 5;
                            gluLookAt(0,smer*3,0, 0, 0, 0, 0, 0, 1);
                            
                        }
                    }
                
                }
                
            else
            {
                    gluLookAt(5+animation_parameter2,5,5,0,0,0,0,1,0);
            }
        
        
        //gluLookAt(-2,8,3,0,0,0,0,1,0);
        //glShadeModel(GL_SMOOTH);
      
        
        
         
         draw_debug_coosys();
      
         /* Postavljamo svetlo */
         glLightfv(GL_LIGHT0, GL_POSITION, light_position);

      
        glPushMatrix();
        
        
        glRotatef(-animation_parameter,0,0,1);
        glRotatef(animation_parameter-0.25 ,0,1,0);
        glRotatef(-animation_parameter,1,0,0);
        //glEnable(GL_CULL_FACE);
      
        
        
// pocetna kocka        
        
        glPushMatrix();
            //glTranslatef(0,0.25,0);
            glutSolidCube(2);
        glPopMatrix();

        
        // slike koje su "zalepljene na kocku"  
        
        
        glPushMatrix();
        	// strana pozitivna x-osa
         	glTranslatef(1.01,0,0);
         	glRotatef(90,0,1,0); 
            slika1();
        glPopMatrix();

	glPushMatrix();
         	//strana negativna x-osa
         	glTranslatef(-1.01,0,0);
         	glRotatef(270,0,1,0);
         	slika2();
	glPopMatrix();
	
	glPushMatrix();
        	//strana pozitivna z-osa
        	glTranslatef(0,0,1.01);
        	slika3();
	glPopMatrix();

	glPushMatrix();
        	//strana negativna z-osa
        	glTranslatef(0,0,-1.01);
        	slika4();
	glPopMatrix();

	glPushMatrix();
        	//strana pozitivna y-ose
        	glTranslatef(0,1.01,0);
        	glRotatef(90,1,0,0);
        	slika5();
	glPopMatrix();

	glPushMatrix();
        	//strana pozitivna y-ose
		glTranslatef(0,-1.01,0);
        	glRotatef(90,1,0,0);
		slika6();
	glPopMatrix();

    glPopMatrix();


	   
        /* Nova slika se salje na ekran. */
         glutSwapBuffers();
     }
      
      
      
     int main(int argc, char **argv)
     {
         /* Parametri svetla i podrazumevanog materijala */
         GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1 };
         GLfloat light_diffuse[] = { 0.7, 0.7, 0.7, 1 };
         GLfloat light_specular[] = { 0.1, 0.1, 0.1, 1 };
      
         GLfloat ambient_coeffs[] = { 0.3, 0.7, 0.3, 1 };
         GLfloat diffuse_coeffs[] = { 0.2, 1, 0.2, 1 };
         GLfloat specular_coeffs[] = { 1, 1, 1, 1 };
         GLfloat shininess = 30;
     
         /* Inicijalizuje se GLUT. */
         glutInit(&argc, argv);
         glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
      
         /* Kreira se prozor. */
         glutInitWindowSize(500, 500);
         glutInitWindowPosition(300, 300);
         glutCreateWindow(argv[0]);
      
         /* Registruju se callback funkcije. */
         glutKeyboardFunc(on_keyboard);
         glutReshapeFunc(on_reshape);
         if(ind == 0)
            glutDisplayFunc(on_display);
      
         /* Obavlja se OpenGL inicijalizacija. */
         glClearColor(0, 0, 0, 0);
         glEnable(GL_DEPTH_TEST);
     
         glEnable(GL_LIGHTING);
      
         /* Postavljaju se svojstva prvog svetla */
         glEnable(GL_LIGHT0);
      
         glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
         glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
         glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
      
         /* Postavljaju se svojstva materijala */
         glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
         glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
         glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
         glMaterialf(GL_FRONT, GL_SHININESS, shininess);
         glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,1);
         glEnable(GL_COLOR_MATERIAL);


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
      
     static void on_timer(int id)
     {
         if(id != TIMER_ID)
          return;
         /*postavljamo tajmer dok je manje od 90 stepeni animacija se pokrece i povecavaju se
          ili smanjuju odredjeni parmetri*/
         if(animation_parameter<=3600){
             
            animation_parameter += 0.5;
            animation_parameter2+=0.017;
      /*
          if(animation_parameter2>=8)
              animation_parameter2=0;
         
             */
        }
         
         
         if (animation_ongoing) {
             glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
         }
      
        glutPostRedisplay();
     }
      
     static void on_reshape(int width, int height)
     {
         /* Podesava se viewport. */
         glViewport(0, 0, width, height);
      
         /* Podesava se projekcija. */
         glMatrixMode(GL_PROJECTION);
         glLoadIdentity();
         gluPerspective(60, (float) width / height, 1, 100);
     }
      
      
// slike koje se pojavljuju posle pritisnutog tastera 'o'
static void on_display6(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);
	//glTranslatef(0,1,2);
        glClearColor(0.75, 0.75, 0.75, 0);
        glDisable(GL_DEPTH_TEST);
         
        

    glDisable(GL_LIGHTING);
    
    
    glPushMatrix();
            glTranslatef(0,0,1);

            
            
          
        mreza();
        slika6();
    
    //Transformacija koordinate[];
    
    glPushMatrix();
    
    
        if(ID == 1)
            {
                printf("usao\n");
                if(translaton_parameter_X == 0.25  && translaton_parameter_Y== 0.25 && rotation_parameter == 180 )
                {
                    ID=0;
                    
                    koordinate[1].TR_X = 0.25;
                    koordinate[1].TR_Y = 0.25;
                    koordinate[1].RT = 180;
                    glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
                    glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
                    
                
                }else{
                
                
                    kretanje();
            
                    koordinate[1].TR_X = translaton_parameter_X;
                    koordinate[1].TR_Y = translaton_parameter_Y;
                    koordinate[1].RT = rotation_parameter;
                    
                    
                }
            }
            else
            {
                glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
                glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
            }
    
    
        
        
             
        VELIKI_TROUGAO1();
        
       
    glPopMatrix(); 
    
   
   
    glPushMatrix();
         if(ID == 2)
            {
                
                if(translaton_parameter_X== -0.25  && translaton_parameter_Y== -0.25 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[2].TR_X = -0.25;
                    koordinate[2].TR_Y = -0.25;
                    koordinate[2].RT = 0;
                    glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
                    glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
                    
                
                }else{
                
                
                    kretanje();
            
                    koordinate[2].TR_X = translaton_parameter_X;
                    koordinate[2].TR_Y = translaton_parameter_Y;
                    koordinate[2].RT = rotation_parameter;
                    
                    
                }
            }
            else
            {
                glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
                glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
            }

        
        
        
        
        VELIKI_TROUGAO2();
        
    glPopMatrix();
    
    
   
    
    
    
    glPushMatrix();
         if(ID == 3)
            {
                
                if(translaton_parameter_X ==  0.25/2  && translaton_parameter_Y == -0.25 && rotation_parameter == -90 )
                {
                    ID=0;
                    
                    koordinate[3].TR_X = 0.25/2;
                    koordinate[3].TR_Y = -0.25;
                    koordinate[3].RT = -90;
                    glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
                    glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
                    
                
                }else{
                
                
                    kretanje();
            
                    koordinate[3].TR_X = translaton_parameter_X;
                    koordinate[3].TR_Y = translaton_parameter_Y;
                    koordinate[3].RT = rotation_parameter;
                    
                    
                }
            }
            else
            {
                glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
                glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
            }
        
        
    
    MALI_TROUGAO1();
    glPopMatrix();
    
   
    
    
    glPushMatrix();
        if(ID == 4)
            {
                
                if(translaton_parameter_X == -0.25/2  && translaton_parameter_Y == -0.25 && rotation_parameter == 180 )
                {
                    ID=0;
                    
                    koordinate[4].TR_X = -0.25/2;
                    koordinate[4].TR_Y = -0.25;
                    koordinate[4].RT = 180;
                    glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
                    glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
                                    
                }else{
                
                
                    kretanje();
            
                    koordinate[4].TR_X = translaton_parameter_X;
                    koordinate[4].TR_Y = translaton_parameter_Y;
                    koordinate[4].RT = rotation_parameter;
                    
                  
                    
                }
            }
            else
            {
                glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
                glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
            }
    
        
        
        
        
    MALI_TROUGAO2();
    glPopMatrix();
    
    
    
    
    
    glPushMatrix();
        if(ID == 5)
            {
                
                if(translaton_parameter_X == -0.25/2   && translaton_parameter_Y ==-0.5  && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[5].TR_X = -0.25/2;
                    koordinate[5].TR_Y = -0.5;
                    koordinate[5].RT = 0;
                    glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
                    glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
                    
                
                }else{
                
                
                    kretanje();
            
                    koordinate[5].TR_X = translaton_parameter_X;
                    koordinate[5].TR_Y = translaton_parameter_Y;
                    koordinate[5].RT = rotation_parameter;
                    
                    
                }
            }
            else
            {
                glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
                glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
            }
    
    
    KVADRAT();
    glPopMatrix();
    
 
    
    
    
    
    
    glPushMatrix();
         if(ID == 6)
            {
                if(translaton_parameter_X == 0.25  && translaton_parameter_Y == 0.6 && rotation_parameter == 135 )
                {
                    ID=0;
                    
                    koordinate[6].TR_X = 0.25;
                    koordinate[6].TR_Y = 0.6;
                    koordinate[6].RT = 135;
                    glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
                    glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
                
                }else{
                
                
                    kretanje();
            
                    koordinate[6].TR_X = translaton_parameter_X;
                    koordinate[6].TR_Y = translaton_parameter_Y;
                    koordinate[6].RT = rotation_parameter;
                    
                }
            }
            else
            {
                glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
                glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
            }
    
    PARALELOGRA();
    glPopMatrix();
    
    
    glPushMatrix();
        
            if(ID == 7)
            {
                if(translaton_parameter_X == -0.25  && translaton_parameter_Y == 0.25 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[7].TR_X = -0.5;
                    koordinate[7].TR_Y = 0.25;
                    koordinate[7].RT = 0;
                    glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                    glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
                
                }else{
                
                
                    kretanje();
            
                    koordinate[7].TR_X = translaton_parameter_X;
                    koordinate[7].TR_Y = translaton_parameter_Y;
                    koordinate[7].RT = rotation_parameter;
                    
                }
            }
            else
            {
                glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
            }
        
    
    
    
    SREDNJI_TROUGAO();
    glPopMatrix();
    glPopMatrix();

    
	
    glutSwapBuffers();
}
     
     
static void on_display5(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);
	//glTranslatef(0,1,2);
        glClearColor(0.75, 0.75, 0.75, 0); //boja
        
        glDisable(GL_DEPTH_TEST);
        
         glPushMatrix();
        //glTranslatef(0,0,1);
        //glRotatef(50,0,1,0);
        //glScalef(10,10,0);
        mreza();
        slika5();
    
    //Transformacija koordinate[];
    
    glPushMatrix();
    
    
    
        if(ID == 1)
            {
                if(translaton_parameter_X<= 0  && translaton_parameter_Y>= 0.25 && rotation_parameter == 180 )
                {
                    ID=0;
                    
                    koordinate[1].TR_X = 0;
                    koordinate[1].TR_Y = 0.25;
                    koordinate[1].RT = 180;
                    glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
                    glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
                
                }else{
                
                
                    kretanje();
            
                    koordinate[1].TR_X = translaton_parameter_X;
                    koordinate[1].TR_Y = translaton_parameter_Y;
                    koordinate[1].RT = rotation_parameter;
                    
                    
                }
            }
            else
            {
                glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
                glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
            }
    
    
        
        
             
        VELIKI_TROUGAO1();
        
       
    glPopMatrix(); 
    
   
   
    glPushMatrix();
         if(ID == 2)
            {
                if(translaton_parameter_X<= -0.5  && translaton_parameter_Y <= -0.25 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[2].TR_X = -0.5;
                    koordinate[2].TR_Y = -0.25;
                    koordinate[2].RT = 0;
                    glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
                    glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
                
                }else{
                
                
                    kretanje();
            
                    koordinate[2].TR_X = translaton_parameter_X;
                    koordinate[2].TR_Y = translaton_parameter_Y;
                    koordinate[2].RT = rotation_parameter;
                    
                    
                }
            }
            else
            {
                glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
                glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
            }

        
        
        
    
        
        VELIKI_TROUGAO2();
        
    glPopMatrix();
    
    
    
    
    
    
    glPushMatrix();
         if(ID == 3)
            {
                printf("usao\n");
                if(translaton_parameter_X>= 0  && translaton_parameter_Y<= -0.25 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[3].TR_X = 0;
                    koordinate[3].TR_Y = -0.25;
                    koordinate[3].RT = 0;
                    glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
                    glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
                    //printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[3].TR_X = translaton_parameter_X;
                    koordinate[3].TR_Y = translaton_parameter_Y;
                    koordinate[3].RT = rotation_parameter;
                    
                    //printf("%f %f %f\n",koordinate[3].TR_X, koordinate[3].TR_Y, koordinate[3].RT);
                    //printf("%f%f%f\n", tacke[3].slika_TX, tacke[3].slika_TY, tacke[3].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
                glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
            }
        
        //printf("%.2f %.2f %.2f\n",koordinate[3].TR_X, koordinate[3].TR_Y, koordinate[3].RT);
    
    MALI_TROUGAO1();
    glPopMatrix();
    
   
    
    
    glPushMatrix();
        if(ID == 4)
            {
                printf("usao\n");
                if(translaton_parameter_X>= 0.25  && translaton_parameter_Y<= 0 && rotation_parameter == 180 )
                {
                    ID=0;
                    
                    koordinate[4].TR_X = 0.25;
                    koordinate[4].TR_Y = 0;
                    koordinate[4].RT = 180;
                    glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
                    glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
                    //printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[4].TR_X = translaton_parameter_X;
                    koordinate[4].TR_Y = translaton_parameter_Y;
                    koordinate[4].RT = rotation_parameter;
                    
                    //printf("%f %f %f\n",koordinate[4].TR_X, koordinate[4].TR_Y, koordinate[4].RT);
                    //printf("%f%f%f\n", tacke[4].slika_TX, tacke[4].slika_TY, tacke[4].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
                glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
            }
    
        
        
        //printf("%.2f %.2f %.2f\n",koordinate[4].TR_X, koordinate[4].TR_Y, koordinate[4].RT);
        
    MALI_TROUGAO2();
    glPopMatrix();
    
    
    
    
    
    glPushMatrix();
        if(ID == 5)
            {
                printf("usao\n");
                if(translaton_parameter_X<=0   && translaton_parameter_Y<=0  && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[5].TR_X = 0;
                    koordinate[5].TR_Y = 0;
                    koordinate[5].RT = 0;
                    glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
                    glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
                    //printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[5].TR_X = translaton_parameter_X;
                    koordinate[5].TR_Y = translaton_parameter_Y;
                    koordinate[5].RT = rotation_parameter;
                    
                    //printf("%f %f %f\n",koordinate[5].TR_X, koordinate[5].TR_Y, koordinate[5].RT);
                    //printf("%f%f%f\n", tacke[5].slika_TX, tacke[5].slika_TY, tacke[5].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
                glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
            }
    
    //printf("%.2f %.2f %.2f\n",koordinate[5].TR_X, koordinate[5].TR_Y, koordinate[5].RT);
    
    KVADRAT();
    glPopMatrix();
    
 
    
    
    
    
    
    glPushMatrix();
         if(ID == 6)
            {
                printf("usao\n");
                if(translaton_parameter_X<= -0.25  && translaton_parameter_Y>= 0.25 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[6].TR_X = -0.25;
                    koordinate[6].TR_Y = 0.25;
                    koordinate[6].RT = 0;
                    glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
                    glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
                    //printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[6].TR_X = translaton_parameter_X;
                    koordinate[6].TR_Y = translaton_parameter_Y;
                    koordinate[6].RT = rotation_parameter;
                    
                    //printf("%f %f %f\n",koordinate[6].TR_X, koordinate[6].TR_Y, koordinate[6].RT);
                    //printf("%f%f%f\n", tacke[6].slika_TX, tacke[6].slika_TY, tacke[6].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
                glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
            }
    
    //printf("%.2f %.2f %.2f\n",koordinate[6].TR_X, koordinate[6].TR_Y, koordinate[6].RT);
    PARALELOGRA();
    glPopMatrix();
    
    
    glPushMatrix();
        
            if(ID == 7)
            {
                //printf("usao\n");
                if(translaton_parameter_X<= -0.5  && translaton_parameter_Y>= 0.25 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[7].TR_X = -0.5;
                    koordinate[7].TR_Y = 0.25;
                    koordinate[7].RT = 0;
                    glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                    glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
                    //printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[7].TR_X = translaton_parameter_X;
                    koordinate[7].TR_Y = translaton_parameter_Y;
                    koordinate[7].RT = rotation_parameter;
                    
                    //printf("%f %f %f\n",koordinate[7].TR_X, koordinate[7].TR_Y, koordinate[7].RT);
                    //printf("%f%f%f\n", tacke[7].slika_TX, tacke[7].slika_TY, tacke[7].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
            }
        
    
    
    //printf("%.2f %.2f %.2f\n",koordinate[7].TR_X, koordinate[7].TR_Y, koordinate[7].RT);
    
    SREDNJI_TROUGAO();
    glPopMatrix();
    
glPopMatrix();
    
	
    glutSwapBuffers();
}


static void on_display4(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);
	//glTranslatef(0,1,2);
    glClearColor(0.75, 0.75, 0.75, 0);
    
        glDisable(GL_DEPTH_TEST);

         glPushMatrix();
                // glTranslatef(0,0,1);

    //glRotatef(50,0,1,0);
      //    glScalef(10,10,0);
        mreza();
        slika4();
    
    
    //Transformacija koordinate[];
    
    glPushMatrix();
    
   
    
    
        if(ID == 1)
            {
                printf("usao\n");
                if(translaton_parameter_X<= 0  && translaton_parameter_Y<= 0 && rotation_parameter == 90 )
                {
                    ID=0;
                    
                    koordinate[1].TR_X = 0;
                    koordinate[1].TR_Y = 0;
                    koordinate[1].RT = 90;
                    glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
                    glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
                   // printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[1].TR_X = translaton_parameter_X;
                    koordinate[1].TR_Y = translaton_parameter_Y;
                    koordinate[1].RT = rotation_parameter;
                    
                   // printf("%f %f %f\n",koordinate[1].TR_X, koordinate[1].TR_Y, koordinate[1].RT);
                    //printf("%f%f%f\n", tacke[1].slika_TX, tacke[1].slika_TY, tacke[1].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
                glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
            }
    
    
       // printf("%.2f %.2f %.2f\n",koordinate[1].TR_X, koordinate[1].TR_Y, koordinate[1].RT);
        
        
             
        VELIKI_TROUGAO1();
        
       
    glPopMatrix(); 
    
   
   
    glPushMatrix();
         if(ID == 2)
            {
                printf("usao\n");
                if(translaton_parameter_X<= 0  && translaton_parameter_Y<= 0 && rotation_parameter == 180 )
                {
                    ID=0;
                    
                    koordinate[2].TR_X = 0;
                    koordinate[2].TR_Y = 0;
                    koordinate[2].RT = 180;
                    glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
                    glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
                    //printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[2].TR_X = translaton_parameter_X;
                    koordinate[2].TR_Y = translaton_parameter_Y;
                    koordinate[2].RT = rotation_parameter;
                    
                    //printf("%f %f %f\n",koordinate[2].TR_X, koordinate[2].TR_Y, koordinate[2].RT);
                    //printf("%f%f%f\n", tacke[2].slika_TX, tacke[2].slika_TY, tacke[2].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
                glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
            }

        
        
        //printf("%.2f %.2f %.2f\n",koordinate[2].TR_X, koordinate[2].TR_Y, koordinate[2].RT);
        
        VELIKI_TROUGAO2();
        
    glPopMatrix();
    
  
    
    
    
    glPushMatrix();
         if(ID == 3)
            {
                printf("usao\n");
                if(translaton_parameter_X>= 0  && translaton_parameter_Y>= 0.25/2 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[3].TR_X = 0;
                    koordinate[3].TR_Y = 0.25/2;
                    koordinate[3].RT = 0;
                    glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
                    glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
                    //printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[3].TR_X = translaton_parameter_X;
                    koordinate[3].TR_Y = translaton_parameter_Y;
                    koordinate[3].RT = rotation_parameter;
                    
                   // printf("%f %f %f\n",koordinate[3].TR_X, koordinate[3].TR_Y, koordinate[3].RT);
                   // printf("%f%f%f\n", tacke[3].slika_TX, tacke[3].slika_TY, tacke[3].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
                glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
            }
        
        //printf("%.2f %.2f %.2f\n",koordinate[3].TR_X, koordinate[3].TR_Y, koordinate[3].RT);
    
    MALI_TROUGAO1();
    glPopMatrix();
    
   
    
    
    glPushMatrix();
        if(ID == 4)
            {
                printf("usao\n");
                if(translaton_parameter_X<= 0  && translaton_parameter_Y<= -0.25/2 && rotation_parameter == -90 )
                {
                    ID=0;
                    
                    koordinate[4].TR_X = 0;
                    koordinate[4].TR_Y = -0.25/2;
                    koordinate[4].RT = -90;
                    glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
                    glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
                    //printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[4].TR_X = translaton_parameter_X;
                    koordinate[4].TR_Y = translaton_parameter_Y;
                    koordinate[4].RT = rotation_parameter;
                    
                   // printf("%f %f %f\n",koordinate[4].TR_X, koordinate[4].TR_Y, koordinate[4].RT);
                   // printf("%f%f%f\n", tacke[4].slika_TX, tacke[4].slika_TY, tacke[4].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
                glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
            }
    
        
        
        //printf("%.2f %.2f %.2f\n",koordinate[4].TR_X, koordinate[4].TR_Y, koordinate[4].RT);
        
    MALI_TROUGAO2();
    glPopMatrix();
    
    
    
    
    
    glPushMatrix();
        if(ID == 5)
            {
               //printf("usao\n");
                if(translaton_parameter_X<=0   && translaton_parameter_Y<= -0.25/2  && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[5].TR_X = 0;
                    koordinate[5].TR_Y = -0.25/2;
                    koordinate[5].RT = 0;
                    glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
                    glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
                   // printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[5].TR_X = translaton_parameter_X;
                    koordinate[5].TR_Y = translaton_parameter_Y;
                    koordinate[5].RT = rotation_parameter;
                    
                    //printf("%f %f %f\n",koordinate[5].TR_X, koordinate[5].TR_Y, koordinate[5].RT);
                    //printf("%f%f%f\n", tacke[5].slika_TX, tacke[5].slika_TY, tacke[5].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
                glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
            }
    
   // printf("%.2f %.2f %.2f\n",koordinate[5].TR_X, koordinate[5].TR_Y, koordinate[5].RT);
    
    KVADRAT();
    glPopMatrix();
    
 
    
    
    
    
    
    glPushMatrix();
         if(ID == 6)
            {
             //   printf("usao\n");
                if(translaton_parameter_X>= 0.5  && translaton_parameter_Y<= -0.25/2 && rotation_parameter == 90 )
                {
                    ID=0;
                    
                    koordinate[6].TR_X = 0.5;
                    koordinate[6].TR_Y = -0.25/2;
                    koordinate[6].RT = 90;
                    glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
                    glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
                //    printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[6].TR_X = translaton_parameter_X;
                    koordinate[6].TR_Y = translaton_parameter_Y;
                    koordinate[6].RT = rotation_parameter;
                    
                //    printf("%f %f %f\n",koordinate[6].TR_X, koordinate[6].TR_Y, koordinate[6].RT);
                //    printf("%f%f%f\n", tacke[6].slika_TX, tacke[6].slika_TY, tacke[6].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
                glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
            }
    
   // printf("%.2f %.2f %.2f\n",koordinate[6].TR_X, koordinate[6].TR_Y, koordinate[6].RT);
    PARALELOGRA();
    glPopMatrix();
    
    
    glPushMatrix();
        
            if(ID == 7)
            {
              //  printf("usao\n");
                if(translaton_parameter_X>= 0.5  && translaton_parameter_Y<= -0.25-0.25/2 && rotation_parameter == 90 )
                {
                    ID=0;
                    
                    koordinate[7].TR_X = 0.5;
                    koordinate[7].TR_Y = -0.25-0.25/2;
                    koordinate[7].RT = 90;
                    glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                    glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
                   // printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[7].TR_X = translaton_parameter_X;
                    koordinate[7].TR_Y = translaton_parameter_Y;
                    koordinate[7].RT = rotation_parameter;
                    
                  //  printf("%f %f %f\n",koordinate[7].TR_X, koordinate[7].TR_Y, koordinate[7].RT);
                   // printf("%f%f%f\n", tacke[7].slika_TX, tacke[7].slika_TY, tacke[7].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
            }
        
    
    
   // printf("%.2f %.2f %.2f\n",koordinate[7].TR_X, koordinate[7].TR_Y, koordinate[7].RT);
    
    SREDNJI_TROUGAO();
    glPopMatrix();
    glPopMatrix();

    
	
    glutSwapBuffers();
}   


static void on_display3(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);
	//glTranslatef(0,1,2);
        glClearColor(0.75, 0.75, 0.75, 0);
        
        glDisable(GL_DEPTH_TEST);
        glPushMatrix();
            //glTranslatef(0,0,1);

            //glRotatef(180,0,1,0);
            //glScalef(10,10,0);
        mreza();
        slika3();
    
    
    //Transformacija koordinate[];
    
    glPushMatrix();
    
    
    
   
    
    
        if(ID == 1)
            {
             //   printf("usao\n");
                if(translaton_parameter_X<= 0  && translaton_parameter_Y>= 0.5 && rotation_parameter == 180 )
                {
                    ID=0;
                    
                    koordinate[1].TR_X = 0;
                    koordinate[1].TR_Y = 0.5;
                    koordinate[1].RT = 180;
                    glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
                    glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
                   // printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[1].TR_X = translaton_parameter_X;
                    koordinate[1].TR_Y = translaton_parameter_Y;
                    koordinate[1].RT = rotation_parameter;
                    
                  //  printf("%f %f %f\n",koordinate[1].TR_X, koordinate[1].TR_Y, koordinate[1].RT);
                  //  printf("%f%f%f\n", tacke[1].slika_TX, tacke[1].slika_TY, tacke[1].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
                glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
            }
    
    
       // printf("%.2f %.2f %.2f\n",koordinate[1].TR_X, koordinate[1].TR_Y, koordinate[1].RT);
        
        
             
        VELIKI_TROUGAO1();
        
       
    glPopMatrix(); 
    
   
   
    glPushMatrix();
         if(ID == 2)
            {
              //  printf("usao\n");
                if(translaton_parameter_X<= 0  && translaton_parameter_Y<= 0 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[2].TR_X = 0;
                    koordinate[2].TR_Y = 0;
                    koordinate[2].RT = 0;
                    glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
                    glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
                //    printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[2].TR_X = translaton_parameter_X;
                    koordinate[2].TR_Y = translaton_parameter_Y;
                    koordinate[2].RT = rotation_parameter;
                    
                  //  printf("%f %f %f\n",koordinate[2].TR_X, koordinate[2].TR_Y, koordinate[2].RT);
                  //  printf("%f%f%f\n", tacke[2].slika_TX, tacke[2].slika_TY, tacke[2].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
                glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
            }

        
        
        //printf("%.2f %.2f %.2f\n",koordinate[2].TR_X, koordinate[2].TR_Y, koordinate[2].RT);
        
        VELIKI_TROUGAO2();
        
    glPopMatrix();
    
    
    
    
    
    glPushMatrix();
         if(ID == 3)
            {
               // printf("usao\n");
                if(translaton_parameter_X<= -0.5 && translaton_parameter_Y>= 0.25 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[3].TR_X = -0.5;
                    koordinate[3].TR_Y = 0.25;
                    koordinate[3].RT = 0;
                    glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
                    glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
               //     printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[3].TR_X = translaton_parameter_X;
                    koordinate[3].TR_Y = translaton_parameter_Y;
                    koordinate[3].RT = rotation_parameter;
                    
               //     printf("%f %f %f\n",koordinate[3].TR_X, koordinate[3].TR_Y, koordinate[3].RT);
               //     printf("%f%f%f\n", tacke[3].slika_TX, tacke[3].slika_TY, tacke[3].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
                glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
            }
        
      //  printf("%.2f %.2f %.2f\n",koordinate[3].TR_X, koordinate[3].TR_Y, koordinate[3].RT);
    
    MALI_TROUGAO1();
    glPopMatrix();
    
   
    
    
    glPushMatrix();
        if(ID == 4)
            {
               // printf("usao\n");
                if(translaton_parameter_X>= 0.5  && translaton_parameter_Y>= 0.35 && rotation_parameter == -45 )
                {
                    ID=0;
                    
                    koordinate[4].TR_X = 0.5;
                    koordinate[4].TR_Y = 0.35;
                    koordinate[4].RT = -45;
                    glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
                    glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
                 //  printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[4].TR_X = translaton_parameter_X;
                    koordinate[4].TR_Y = translaton_parameter_Y;
                    koordinate[4].RT = rotation_parameter;
                    
                  //  printf("%f %f %f\n",koordinate[4].TR_X, koordinate[4].TR_Y, koordinate[4].RT);
                  //  printf("%f%f%f\n", tacke[4].slika_TX, tacke[4].slika_TY, tacke[4].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
                glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
            }
    
        
        
     //   printf("%.2f %.2f %.2f\n",koordinate[4].TR_X, koordinate[4].TR_Y, koordinate[4].RT);
        
    MALI_TROUGAO2();
    glPopMatrix();
    
    
    
    
    
    glPushMatrix();
        if(ID == 5)
            {
              //  printf("usao\n");
                if(translaton_parameter_X<=0.5   && translaton_parameter_Y<=0  && rotation_parameter == 45 )
                {
                    ID=0;
                    
                    koordinate[5].TR_X = 0.5;
                    koordinate[5].TR_Y = 0;
                    koordinate[5].RT = 45;
                    glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
                    glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
                //    printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[5].TR_X = translaton_parameter_X;
                    koordinate[5].TR_Y = translaton_parameter_Y;
                    koordinate[5].RT = rotation_parameter;
                    
                //    printf("%f %f %f\n",koordinate[5].TR_X, koordinate[5].TR_Y, koordinate[5].RT);
                //    printf("%f%f%f\n", tacke[5].slika_TX, tacke[5].slika_TY, tacke[5].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
                glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
            }
    
    //printf("%.2f %.2f %.2f\n",koordinate[5].TR_X, koordinate[5].TR_Y, koordinate[5].RT);
    
    KVADRAT();
    glPopMatrix();
    
 
    
    
    
    
    
    glPushMatrix();
         if(ID == 6)
            {
           //     printf("usao\n");
                if(translaton_parameter_X<= -0.5  && translaton_parameter_Y>= 0 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[6].TR_X = -0.5;
                    koordinate[6].TR_Y = 0;
                    koordinate[6].RT = 0;
                    glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
                    glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
             //       printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[6].TR_X = translaton_parameter_X;
                    koordinate[6].TR_Y = translaton_parameter_Y;
                    koordinate[6].RT = rotation_parameter;
                    
              //      printf("%f %f %f\n",koordinate[6].TR_X, koordinate[6].TR_Y, koordinate[6].RT);
              //      printf("%f%f%f\n", tacke[6].slika_TX, tacke[6].slika_TY, tacke[6].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
                glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
            }
    
  //  printf("%.2f %.2f %.2f\n",koordinate[6].TR_X, koordinate[6].TR_Y, koordinate[6].RT);
    PARALELOGRA();
    glPopMatrix();
    
    
    glPushMatrix();
        
            if(ID == 7)
            {
            //    printf("usao\n");
                if(translaton_parameter_X>= -0.5+0.2  && translaton_parameter_Y>= 0.5+0.25/4-0.01 && rotation_parameter == 180 )
                {
                    ID=0;
                    
                    koordinate[7].TR_X = -0.5+0.2;
                    koordinate[7].TR_Y =  0.5+0.25/4-0.01;
                    koordinate[7].RT = 180;
                    glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                    glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
                //    printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[7].TR_X = translaton_parameter_X;
                    koordinate[7].TR_Y = translaton_parameter_Y;
                    koordinate[7].RT = rotation_parameter;
                    
              
                }
            }
            else
            {
                glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
            }
        
    
    

    
    SREDNJI_TROUGAO();
    glPopMatrix();
    glPopMatrix();

    
	
    glutSwapBuffers();
}

static void on_display2(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);
	//glTranslatef(0,1,2);
        glClearColor(0.75, 0.75, 0.75, 0);
        
        glDisable(GL_DEPTH_TEST);
    glPushMatrix();
           // glTranslatef(0,0,1);

            //glRotatef(50,0,1,0);
          //glScalef(10,10,0);
        mreza();
        slika2();
    
    //Transformacija koordinate[];
    
    glPushMatrix();
    
    
   
    
    
        if(ID == 1)
            {
              //  printf("usao\n");
                if(translaton_parameter_X<= 0  && translaton_parameter_Y<= -0.5 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[1].TR_X = 0;
                    koordinate[1].TR_Y = -0.5;
                    koordinate[1].RT = 0;
                    glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
                    glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
                 //   printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[1].TR_X = translaton_parameter_X;
                    koordinate[1].TR_Y = translaton_parameter_Y;
                    koordinate[1].RT = rotation_parameter;
                    
                  //  printf("%f %f %f\n",koordinate[1].TR_X, koordinate[1].TR_Y, koordinate[1].RT);
                  //  printf("%f%f%f\n", tacke[1].slika_TX, tacke[1].slika_TY, tacke[1].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
                glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
            }
    
    
        //printf("%.2f %.2f %.2f\n",koordinate[1].TR_X, koordinate[1].TR_Y, koordinate[1].RT);
        
        
             
        VELIKI_TROUGAO1();
        
       
    glPopMatrix(); 
    
   
   
    glPushMatrix();
         if(ID == 2)
            {
               // printf("usao\n");
                if(translaton_parameter_X>= 0.5  && translaton_parameter_Y<=0 && rotation_parameter == 180 )
                {
                    ID=0;
                    
                    koordinate[2].TR_X = 0.5;
                    koordinate[2].TR_Y = 0;
                    koordinate[2].RT = 180;
                    glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
                    glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
                 //   printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[2].TR_X = translaton_parameter_X;
                    koordinate[2].TR_Y = translaton_parameter_Y;
                    koordinate[2].RT = rotation_parameter;
                    
                   // printf("%f %f %f\n",koordinate[2].TR_X, koordinate[2].TR_Y, koordinate[2].RT);
                  //  printf("%f%f%f\n", tacke[2].slika_TX, tacke[2].slika_TY, tacke[2].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
                glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
            }

        
        
       // printf("%.2f %.2f %.2f\n",koordinate[2].TR_X, koordinate[2].TR_Y, koordinate[2].RT);
        
        VELIKI_TROUGAO2();
        
    glPopMatrix();
    
    
    
    
    
    glPushMatrix();
         if(ID == 3)
            {
             //   printf("usao\n");
                if(translaton_parameter_X>= 0.25  && translaton_parameter_Y<= 0.5 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[3].TR_X = 0.25;
                    koordinate[3].TR_Y = 0.5;
                    koordinate[3].RT = 0;
                    glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
                    glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
              //      printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[3].TR_X = translaton_parameter_X;
                    koordinate[3].TR_Y = translaton_parameter_Y;
                    koordinate[3].RT = rotation_parameter;
                    
            //        printf("%f %f %f\n",koordinate[3].TR_X, koordinate[3].TR_Y, koordinate[3].RT);
           //         printf("%f%f%f\n", tacke[3].slika_TX, tacke[3].slika_TY, tacke[3].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
                glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
            }
        
       // printf("%.2f %.2f %.2f\n",koordinate[3].TR_X, koordinate[3].TR_Y, koordinate[3].RT);
    
    MALI_TROUGAO1();
    glPopMatrix();
    
   
    
    
    glPushMatrix();
        if(ID == 4)
            {
          //      printf("usao\n");
                if(translaton_parameter_X<= 0.25  && translaton_parameter_Y<= 0.5 && rotation_parameter == 90 )
                {
                    ID=0;
                    
                    koordinate[4].TR_X = 0.25;
                    koordinate[4].TR_Y = 0.5;
                    koordinate[4].RT = 90;
                    glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
                    glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
           //         printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[4].TR_X = translaton_parameter_X;
                    koordinate[4].TR_Y = translaton_parameter_Y;
                    koordinate[4].RT = rotation_parameter;
                    
            //        printf("%f %f %f\n",koordinate[4].TR_X, koordinate[4].TR_Y, koordinate[4].RT);
            //        printf("%f%f%f\n", tacke[4].slika_TX, tacke[4].slika_TY, tacke[4].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
                glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
            }
    
        
        
      //  printf("%.2f %.2f %.2f\n",koordinate[4].TR_X, koordinate[4].TR_Y, koordinate[4].RT);
        
    MALI_TROUGAO2();
    glPopMatrix();
    
    
    
    
    
    glPushMatrix();
        if(ID == 5)
            {
             //   printf("usao\n");
                if(translaton_parameter_X<=0.25/2   && translaton_parameter_Y<=0.25  && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[5].TR_X = 0.25/2;
                    koordinate[5].TR_Y = 0.25;
                    koordinate[5].RT = 0;
                    glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
                    glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
                //    printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[5].TR_X = translaton_parameter_X;
                    koordinate[5].TR_Y = translaton_parameter_Y;
                    koordinate[5].RT = rotation_parameter;
                    
                  //  printf("%f %f %f\n",koordinate[5].TR_X, koordinate[5].TR_Y, koordinate[5].RT);
                   // printf("%f%f%f\n", tacke[5].slika_TX, tacke[5].slika_TY, tacke[5].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
                glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
            }
    
   // printf("%.2f %.2f %.2f\n",koordinate[5].TR_X, koordinate[5].TR_Y, koordinate[5].RT);
    
    KVADRAT();
    glPopMatrix();
    
 
    
    
    
    
    
    glPushMatrix();
         if(ID == 6)
            {
         //       printf("usao\n");
                if(translaton_parameter_X>= 0.25/2  && translaton_parameter_Y>= 0 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[6].TR_X = 0.25/2;
                    koordinate[6].TR_Y = 0;
                    koordinate[6].RT = 0;
                    glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
                    glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
          //          printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[6].TR_X = translaton_parameter_X;
                    koordinate[6].TR_Y = translaton_parameter_Y;
                    koordinate[6].RT = rotation_parameter;
                    
            //        printf("%f %f %f\n",koordinate[6].TR_X, koordinate[6].TR_Y, koordinate[6].RT);
            //        printf("%f%f%f\n", tacke[6].slika_TX, tacke[6].slika_TY, tacke[6].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
                glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
            }
    
   // printf("%.2f %.2f %.2f\n",koordinate[6].TR_X, koordinate[6].TR_Y, koordinate[6].RT);
    PARALELOGRA();
    glPopMatrix();
    
    
    glPushMatrix();
        
            if(ID == 7)
            {
             //   printf("usao\n");
                if(translaton_parameter_X<= -0.25/2  && translaton_parameter_Y>= 0 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[7].TR_X = -0.25/2;
                    koordinate[7].TR_Y = 0;
                    koordinate[7].RT = 0;
                    glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                    glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
                 //   printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[7].TR_X = translaton_parameter_X;
                    koordinate[7].TR_Y = translaton_parameter_Y;
                    koordinate[7].RT = rotation_parameter;
                    
                  //  printf("%f %f %f\n",koordinate[7].TR_X, koordinate[7].TR_Y, koordinate[7].RT);
                  //  printf("%f%f%f\n", tacke[7].slika_TX, tacke[7].slika_TY, tacke[7].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
            }
        
    
    
  //  printf("%.2f %.2f %.2f\n",koordinate[7].TR_X, koordinate[7].TR_Y, koordinate[7].RT);
    
    SREDNJI_TROUGAO();
    glPopMatrix();
    
glPopMatrix();
    
	
    glutSwapBuffers();
}

static void on_display1(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);
	//glTranslatef(0,1,2);
        glClearColor(0.75, 0.75, 0.75, 0);
        
        glDisable(GL_DEPTH_TEST);
               
        
         
        glPushMatrix();
            //glTranslatef(0,0,1);
            //glRotatef(50,0,1,0);
            //glScalef(10,10,0);
        mreza();
        
        slika1();
    
    
    
    //Transformacija koordinate[];
    
    glPushMatrix();
    
        if(ID == 1)
            {
              //  printf("usao\n");
                if(translaton_parameter_X<= 0  && translaton_parameter_Y<= -0.5 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[1].TR_X = 0;
                    koordinate[1].TR_Y = -0.5;
                    koordinate[1].RT = 0;
                    glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
                    glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
                //    printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[1].TR_X = translaton_parameter_X;
                    koordinate[1].TR_Y = translaton_parameter_Y;
                    koordinate[1].RT = rotation_parameter;
                    
                  //  printf("%f %f %f\n",koordinate[1].TR_X, koordinate[1].TR_Y, koordinate[1].RT);
                  //  printf("%f%f%f\n", tacke[1].slika_TX, tacke[1].slika_TY, tacke[1].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[1].TR_X,0+koordinate[1].TR_Y,0);
                glRotatef(-(0+koordinate[1].RT), 0, 0, 1);
            }
    
    
      //  printf("%.2f %.2f %.2f\n",koordinate[1].TR_X, koordinate[1].TR_Y, koordinate[1].RT);
        
        
             
        VELIKI_TROUGAO1();
        
       
    glPopMatrix(); 
    
   
   
    glPushMatrix();
         if(ID == 2)
            {
   //             printf("usao\n");
                if(translaton_parameter_X>= 0.5  && translaton_parameter_Y<=0 && rotation_parameter == 180 )
                {
                    ID=0;
                    
                    koordinate[2].TR_X = 0.5;
                    koordinate[2].TR_Y = 0;
                    koordinate[2].RT = 180;
                    glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
                    glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
   //                 printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[2].TR_X = translaton_parameter_X;
                    koordinate[2].TR_Y = translaton_parameter_Y;
                    koordinate[2].RT = rotation_parameter;
                    
   //                 printf("%f %f %f\n",koordinate[2].TR_X, koordinate[2].TR_Y, koordinate[2].RT);
   //                 printf("%f%f%f\n", tacke[2].slika_TX, tacke[2].slika_TY, tacke[2].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[2].TR_X,0+koordinate[2].TR_Y,0);
                glRotatef(-(0+koordinate[2].RT), 0, 0, 1);
            }

        
        
   //     printf("%.2f %.2f %.2f\n",koordinate[2].TR_X, koordinate[2].TR_Y, koordinate[2].RT);
        
        VELIKI_TROUGAO2();
        
    glPopMatrix();
    
    
    
    
    
    glPushMatrix();
         if(ID == 3)
            {
   //             printf("usao\n");
                if(translaton_parameter_X>= 0.25  && translaton_parameter_Y>= 0.5 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[3].TR_X = 0.25;
                    koordinate[3].TR_Y = 0.5;
                    koordinate[3].RT = 0;
                    glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
                    glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
   //                 printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[3].TR_X = translaton_parameter_X;
                    koordinate[3].TR_Y = translaton_parameter_Y;
                    koordinate[3].RT = rotation_parameter;
                    
                  //  printf("%f %f %f\n",koordinate[3].TR_X, koordinate[3].TR_Y, koordinate[3].RT);
                  //  printf("%f%f%f\n", tacke[3].slika_TX, tacke[3].slika_TY, tacke[3].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[3].TR_X,0+koordinate[3].TR_Y,0);
                glRotatef(-(0+koordinate[3].RT), 0, 0, 1);
            }
        
       // printf("%.2f %.2f %.2f\n",koordinate[3].TR_X, koordinate[3].TR_Y, koordinate[3].RT);
    
    MALI_TROUGAO1();
    glPopMatrix();
    
   
    
    
    glPushMatrix();
        if(ID == 4)
            {
             //   printf("usao\n");
                if(translaton_parameter_X<= 0.25  && translaton_parameter_Y<= 0.5 && rotation_parameter == 90 )
                {
                    ID=0;
                    
                    koordinate[4].TR_X = 0.25;
                    koordinate[4].TR_Y = 0.5;
                    koordinate[4].RT = 90;
                    glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
                    glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
              //      printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[4].TR_X = translaton_parameter_X;
                    koordinate[4].TR_Y = translaton_parameter_Y;
                    koordinate[4].RT = rotation_parameter;
                    
                  //  printf("%f %f %f\n",koordinate[4].TR_X, koordinate[4].TR_Y, koordinate[4].RT);
                   // printf("%f%f%f\n", tacke[4].slika_TX, tacke[4].slika_TY, tacke[4].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[4].TR_X,0+koordinate[4].TR_Y,0);
                glRotatef(-(0+koordinate[4].RT), 0, 0, 1);
            }
    
        
        
       // printf("%.2f %.2f %.2f\n",koordinate[4].TR_X, koordinate[4].TR_Y, koordinate[4].RT);
        
    MALI_TROUGAO2();
    glPopMatrix();
    
    
    
    
    
    glPushMatrix();
        if(ID == 5)
            {
              //  printf("usao\n");
                if(translaton_parameter_X<=0.25/2   && translaton_parameter_Y<=0.25  && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[5].TR_X = 0.25/2;
                    koordinate[5].TR_Y = 0.25;
                    koordinate[5].RT = 0;
                    glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
                    glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
                   // printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[5].TR_X = translaton_parameter_X;
                    koordinate[5].TR_Y = translaton_parameter_Y;
                    koordinate[5].RT = rotation_parameter;
                    
                    //printf("%f %f %f\n",koordinate[5].TR_X, koordinate[5].TR_Y, koordinate[5].RT);
                   // printf("%f%f%f\n", tacke[5].slika_TX, tacke[5].slika_TY, tacke[5].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[5].TR_X,0+koordinate[5].TR_Y,0);
                glRotatef(-(0+koordinate[5].RT), 0, 0, 1);
            }
    
    //printf("%.2f %.2f %.2f\n",koordinate[5].TR_X, koordinate[5].TR_Y, koordinate[5].RT);
    
    KVADRAT();
    glPopMatrix();
    
 
    
    
    
    
    
    glPushMatrix();
         if(ID == 6)
            {
              
                //  printf("usao\n");
                if(translaton_parameter_X>= 0.25/2  && translaton_parameter_Y>= 0 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[6].TR_X = 0.25/2;
                    koordinate[6].TR_Y = 0;
                    koordinate[6].RT = 0;
                    glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
                    glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
                //    printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[6].TR_X = translaton_parameter_X;
                    koordinate[6].TR_Y = translaton_parameter_Y;
                    koordinate[6].RT = rotation_parameter;
                    
                  //  printf("%f %f %f\n",koordinate[6].TR_X, koordinate[6].TR_Y, koordinate[6].RT);
                    //printf("%f%f%f\n", tacke[6].slika_TX, tacke[6].slika_TY, tacke[6].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[6].TR_X,0+koordinate[6].TR_Y,0);
                glRotatef(-(0+koordinate[6].RT), 0, 0, 1);
            }
    
    //printf("%.2f %.2f %.2f\n",koordinate[6].TR_X, koordinate[6].TR_Y, koordinate[6].RT);
    PARALELOGRA();
    glPopMatrix();
    
    
    glPushMatrix();
        
            if(ID == 7)
            {
//                printf("usao\n");
                if(translaton_parameter_X<= -0.25/2  && translaton_parameter_Y>= 0 && rotation_parameter == 0 )
                {
                    ID=0;
                    
                    koordinate[7].TR_X = -0.25/2;
                    koordinate[7].TR_Y = 0;
                    koordinate[7].RT = 0;
                    glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                    glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
//                    printf("aaaaaaaaaaaaaa");
                
                }else{
                
                
                    kretanje();
            
                    koordinate[7].TR_X = translaton_parameter_X;
                    koordinate[7].TR_Y = translaton_parameter_Y;
                    koordinate[7].RT = rotation_parameter;
                    
  //                  printf("%f %f %f\n",koordinate[7].TR_X, koordinate[7].TR_Y, koordinate[7].RT);
    //                printf("%f%f%f\n", tacke[7].slika_TX, tacke[7].slika_TY, tacke[7].slika_R);
                }
            }
            else
            {
                glTranslatef(0+koordinate[7].TR_X,0+koordinate[7].TR_Y,0);
                glRotatef(-(0+koordinate[7].RT), 0, 0, 1);
            }
        
    
    
  //  printf("%.2f %.2f %.2f\n",koordinate[7].TR_X, koordinate[7].TR_Y, koordinate[7].RT);
    
    SREDNJI_TROUGAO();
    glPopMatrix();
    
glPopMatrix();
    
	
    glutSwapBuffers();
} 


// oblici za slaganje

   
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



static void draw_debug_coosys()
     {
         glDisable(GL_LIGHTING);
         glBegin(GL_LINES);
         glColor3f (1, 0, 0);
         glVertex3f(5, 0, 0);
         glVertex3f(0, 0, 0);
         
         glColor3f (1, 0, 0);
         glVertex3f(-5, 0, 0);
         glVertex3f(0, 0, 0);
      
         glColor3f (0, 1, 0);
         glVertex3f(0, 5, 0);
         glVertex3f(0, 0, 0);
      
         glColor3f (0, 0, 1);
         glVertex3f(0, 0, 5);
         glVertex3f(0, 0, 0);
         glEnd();
         glEnable(GL_LIGHTING);
     }
