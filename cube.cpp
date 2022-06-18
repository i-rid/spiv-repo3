#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

GLfloat d = 0;
GLfloat T = 45.0;
GLfloat a=1,b=1,c=0;
static float	tx	=  0.0;
static float	ty	=  0.0;
static float	tz	=  0.0;


void MyInit()
{
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
}

void Spin()
{
    d = d + 1;
    if(d > 360)
        d = 0;
    glutPostRedisplay();
}

void my_keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 'w':
            d+=1;
            a=1;
            glutPostRedisplay();
            break;
        case 's':
            d-=1;
            glutPostRedisplay();
            break;
        case 'd':
            d+=1;
            //a=0;
            b=1;
            glutPostRedisplay();
            break;
        case 'a':
            d-=1;
            //a=0;
            //b=1;
            glutPostRedisplay();
            break;
        case 'e':
            d+=1;
            //a=0;
            //b=0;
            c=1;
            glutPostRedisplay();
            break;
        case 'q':
            d-=1;
            //a=0;
            //b=0;
            //c=1;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void Face(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[])
{
    glBegin(GL_POLYGON);
        glVertex3fv(A);
        glVertex3fv(B);
        glVertex3fv(C);
        glVertex3fv(D);
    glEnd();
}

void Cube(GLfloat V0[],GLfloat V1[],GLfloat V2[],GLfloat V3[],GLfloat V4[],GLfloat V5[],GLfloat V6[],GLfloat V7[])
{
    glColor3f(1,0,0);
    Face(V0,V1,V2,V3); //Front
    glColor3f(0,1,0);
    Face(V4,V5,V6,V7); //Back
    glColor3f(0,0,1);
    Face(V0,V4,V7,V3); //Left
    glColor3f(1,1,0);
    Face(V1,V5,V6,V2); //Right
    glColor3f(1,0,1);
    Face(V2,V3,V7,V6); //Bot
    glColor3f(0,1,1);
    Face(V0,V1,V5,V4); //Top
}

void Draw()
{
    GLfloat V[8][3] =   {
                            {-0.5, 0.5, 0.5},
                            { 0.5, 0.5, 0.5},
                            { 0.5,-0.5, 0.5},
                            {-0.5,-0.5, 0.5},
                            {-0.5, 0.5,-0.5},
                            { 0.5, 0.5,-0.5},
                            { 0.5,-0.5,-0.5},
                            {-0.5,-0.5,-0.5},
                        };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(tx,ty,tz);
    glRotatef(d,a,b,c);
    Cube(V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(50,150);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Cube Spin with Matrices");
    MyInit();
    glutDisplayFunc(Draw);
    glutIdleFunc(Spin);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();
    return 0;
}
