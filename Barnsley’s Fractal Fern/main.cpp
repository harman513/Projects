/* Harmanpreet - 109487228 - CSCI272 */

#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
/* GLUT callback Handlers */
int n = 100000;

void resize(int width, int height)
{
    if(width<=height)
        glViewport(0,(GLsizei) (height-width)/2,(GLsizei) width,(GLsizei) width);

    else
        glViewport((GLsizei) (width-height)/2 ,0 ,(GLsizei) height,(GLsizei) height);
}

void init()
{
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-2.5,2.75,10.5,0, -1.0, 1.0); // adjusted for suitable viewport

}


void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT);
  glColor3f(0.0f, 1.0f, 0.0f); /* to give the green color */
       // clear display screen

    int num = 0;
    float px = 0.0 , py = 0.0;
float tempx = 0.5, tempy = 0.5;
int i;
for ( i = 0 ; i < n ; i++)
{

num = rand()%100;

     if(num<85) /* get the 85% value */
    {
        px = 0.85* tempx + 0.04* tempy;
        py = -0.04* tempx + 0.85* tempy + 1.6;
    }
 else if(num<92) /*get the 7% value */
    {
        px = 0.2* tempx - 0.26* tempy;
        py = 0.23* tempx + 0.22* tempy + 1.6;
    }
     else if(num<99) /* get the 7%value */
    {
        px = -0.15* tempx + 0.28* tempy;
        py = 0.26* tempx + 0.24* tempy + 0.44;
    }

       else if(num=0) /*get the 1 % value */
    {
        px = 0.0;
        py = 0.16* tempy;
    }
    tempx = px, tempy = py;
    glBegin(GL_POINTS);
    glVertex3f(px,py,0);
    glEnd();
}

  glFlush ();                           // clear buffer
}


void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :                       // esc key to exit
        case 'q':
            exit(0);
            break;
    }

    glutPostRedisplay();
}


/* Program entry point */

int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (250, 250);                //window screen
   glutInitWindowPosition (100, 100);            //window position
   glutCreateWindow ("Program1");                //program title
   init();
   glutDisplayFunc(display);                     //callback function for display
   glutReshapeFunc(resize);                      //callback for reshape
   glutKeyboardFunc(key);                        //callback function for keyboard
   glutMainLoop();                               //loop

    return EXIT_SUCCESS;
}
