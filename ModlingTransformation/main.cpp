
#include <string.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
//#include <GL/freeglut.h>
GLdouble T_Theta = 0;
GLdouble T_Trans = -3.0;
GLdouble t_the = 0;
GLdouble T_Tra = 2.0;
GLdouble t_t = -1.0;
GLdouble t_th = 0;
bool flag1;
bool flag2;
bool flag3;



static int slices = 16;
static int stacks = 16;




using namespace std;

bool WireFrame= false;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


/* GLUT callback Handlers */

static void resize(int width, int height)
{
     double Ratio;

   if(width<=height)
     {
         glViewport(0,(GLsizei) (height-width)/2,(GLsizei) width,(GLsizei) width);
         Ratio =  height/width;
      }
    else
      {
        glViewport((GLsizei) (width-height)/2 ,0 ,(GLsizei) height,(GLsizei) height);
        Ratio = width /height;
      }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective (50.0f,Ratio,0.1f, 100.0f);
 }

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_COLOR_MATERIAL); // to give different color to all the different shapes
      glColor3f(1.0f, 0.0f, 0.0f);
      glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0,5,10,0.0,0.0,0.0,0.0,1.0,0.0);

    if(WireFrame)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);		//Draw Our Mesh In Wireframe Mesh
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);		//Toggle WIRE FRAME

    /* your code here */

//teaport //to display the images
 glPushMatrix();
   glTranslated(0.0,2.0,T_Trans);
   glRotatef(T_Theta, 0, 1, 0);
   glColor3f(1.0f, 0.0f, 0.0f);
   glutSolidTeapot ( 1.5);
 glPopMatrix();

   // solidcube

 glPushMatrix();
   glTranslated(3.0 ,0.0,T_Tra);
   glRotatef(t_the,0,1,0);
  glColor3f(0.0f, 1.0f, 0.0f);
   glutSolidCube ( 1.5 );
 glPopMatrix();

 //SolidSphere

 glPushMatrix();
    glTranslated(-3.5,0.0,t_t);
    glRotatef(t_th,0,1,0);
   glColor3f(1.0f, 0.0f, 1.0f);
    glutSolidSphere ( 1,slices,stacks);
 glPopMatrix();


    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
        case 't': //to select one image to do the rotation. 3 images , 3 different cases.
            flag1 = true;
            flag2 = false;
            flag3 = false;
            break;
             case 's':
            flag1 = false;
            flag2 = true;
            flag3 = false;
            break; case 'c':
            flag1 = false;
            flag2 = false;
            flag3 = true;
            break;
    }
}




void Specialkeys(int key, int x, int y)
{
    if(flag1== true && flag2 == false && flag3 == false){ //if else statement to run the code using keys as t,c,s for different images
switch (key){ // these 4 keys are to do the rotation using all the keys.
     case GLUT_KEY_DOWN:
      T_Trans -= 0.5;
  break;

   case GLUT_KEY_UP:
       T_Trans += 0.5;
     break;
   case GLUT_KEY_LEFT:
    T_Theta += 5.0;
    break;
     case GLUT_KEY_RIGHT:
    T_Theta -= 5.0;
    break;}
    }

    else if(flag1==false && flag2 == true && flag3 == false){
            switch (key){
     case GLUT_KEY_DOWN:
      T_Tra -= 0.5;
  break;

   case GLUT_KEY_UP:
       T_Tra += 0.5;
     break;
   case GLUT_KEY_LEFT:
    t_the += 5.0;
    break;
     case GLUT_KEY_RIGHT:
    t_the -= 5.0;
    break;}



    }
else if(flag1==false && flag2 == false && flag3 == true) {
        switch (key){
     case GLUT_KEY_DOWN:
      t_t -= 0.5;
  break;

   case GLUT_KEY_UP:
       t_t += 0.5;
     break;
   case GLUT_KEY_LEFT:
    t_th += 5.0;
    break;
     case GLUT_KEY_RIGHT:
    t_th -= 5.0;
    break;}


}
    glutPostRedisplay();

   }


static void idle(void)
{
    glutPostRedisplay();
}

static void init(void)
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
}


/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowSize(800,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");
    init();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(Specialkeys);


    glutIdleFunc(idle);
    glutMainLoop();

    return EXIT_SUCCESS;
}
