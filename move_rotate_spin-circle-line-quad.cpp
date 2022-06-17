#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static GLfloat spin = 0.0;
static float	tx	=  0.0;
static float	ty	=  0.0;
static float	tz	=  1.0;


void drawline(void)
{
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex2i(0,0);
    glVertex2i(0, -1);

    glEnd();
}
void drawQuad(void)
{
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.3, 0.0,0.0);
    glVertex3f(0.3, -0.3,0.0);
    glVertex3f(0.0,-0.3,0.0);
    glEnd();
}
void drawCircle()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    float theta;
    for(int i=0;i<360;i++)
    {
        theta = i*3.1416/180;
        glVertex2f(1.0+.5*cos(theta),1.0+.5*sin(theta));
    }

    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //draw the left one here
    //glRectf(0.1, -0.2,0.0, 0.2);
    //circle
    drawline();
    glPushMatrix();

    glColor3f(1.0,1.0,1.0);
    glTranslatef(tx,ty,0);

    glRotatef(spin,0.0,0.0,tz);
    glRectf(0.1, -0.2,0.0, 0.2);
    glRectf(-0.1, 0.1,0.0, -0.1);
    glPopMatrix();
    glFlush();
}

void spinDisplay_left(void)
{
    spin = spin + 1;
    if (spin > 360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
}

void spinDisplay_right(void)
{
    spin = spin - 1;
    if (spin > 360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
}

void spe_key(int key,int x,int y)
{
    switch(key)
    {
        case GLUT_KEY_RIGHT:
            tx+=.05;
            glutPostRedisplay();
            break;

        case GLUT_KEY_LEFT:
            tx-=.05;
            glutPostRedisplay();
            break;

        case GLUT_KEY_UP:
            ty+=.05;
            glutPostRedisplay();
            break;

        case GLUT_KEY_DOWN:
            ty-=.05;
            glutPostRedisplay();
            break;

        default:
            break;
    }
}


void my_keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case '6':
            spin+=1;
            glutPostRedisplay();
            break;
        case '4':
            spin-=1;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}


void my_mouse(int button,int state,int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)glutIdleFunc(spinDisplay_left);
        break;
    case GLUT_MIDDLE_BUTTON:
        if (state == GLUT_DOWN)glutIdleFunc(NULL);
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)tz=1.0;glutIdleFunc(spinDisplay_right);

        break;
    default:
        break;
    }
}


void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    //glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Transformation");
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(my_keyboard);
    glutSpecialFunc(spe_key);
    glutMouseFunc(my_mouse);
    glutMainLoop();
    return 0;
}
/*
glutKeyboardFunc(unsigned char key,int x, int y)
glutMouseFunc(int key,int state,int x, int y)
glutSpecialFunc(int key,int x, int y)
glutIdealFunc(function) -> mouse
glutPostRedisplay()
glTranslatef()
glRotatef()
glRectf()
*/
