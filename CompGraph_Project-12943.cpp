#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
double hh = 1000, ww = 1000;
//int d=20,p,gx=0,hy=0,hxc=495,gyc=795,ha,gb;

void drawCircle(int xx, int yy, int rad, int r, int g, int b){

    glColor3ub(r, g, b);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++){
        float theta = i*3.142/180;
        glVertex2f(xx+rad*cos(theta), yy+rad*sin(theta));
    }
    glEnd();
}


void showGrid(double h, double w, double dis){
/// Page grid vertical
    for(int i=0; i<=w; i+=dis){
        glColor3d(1, 0, 0);
        glBegin(GL_LINES);
        glVertex2d(i, 0);
        glVertex2d(i, 1000);
        glEnd();
    }

    /// Page grid horizontal
    for(int i=0; i<=h; i+=dis){
        glColor3d(1, 0, 0);
        glBegin(GL_LINES);
        glVertex2d(0, i);
        glVertex2d(1000, i);
        glEnd();
    }
}

void display(void) {
    /* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);

/// Floor
    glColor3d(.9, .9, .9);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(1000, 0);
    glVertex2d(1000, 450);
    glVertex2d(400, 450);
    glVertex2d(0, 100);
    glEnd();

/// Floor horizontal lines
    int x, y, z=50;
    for(y=50; y<1000; y+=z, z-=2){
        glColor3d(.7, .7, .7);
        glBegin(GL_LINES);
        glVertex2d(0, y);
        glVertex2d(1000, y);
        glEnd();
    }

/// Floor vertical lines
    int x1, x2;
    for(x1 = 430, x2 = -30; x1<=1000; x1+=30, x2+=55){
        glColor3d(.7, .7, .7);
        glBegin(GL_LINES);
        glVertex2d(x1, 450);
        glVertex2d(x2, 0);
        glEnd();
    }

///  left Wall
    glColor3d(0.85, 0.85, 0.85);
    glBegin(GL_POLYGON);
    glVertex2d(0, 100);
    glVertex2d(400, 450);
    glVertex2d(400, 1000);
    glVertex2d(0, 1000);
    glVertex2d(0, 100);
    glEnd();

///  Back-Glass outer frame
    glColor3d(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2d(400, 450);
    glVertex2d(1000, 450);
    glVertex2d(1000, 1000);
    glVertex2d(400, 1000);
    glVertex2d(400, 450);
    glEnd();

///  Back-Glass
    glColor3d(0.52, 0.80, 0.92);
    glBegin(GL_POLYGON);
    glVertex2d(420, 460);
    glVertex2d(1000, 460);
    glVertex2d(1000, 870);
    glVertex2d(420, 870);

    glEnd();

///  Back-Glass inner frame top
    glColor3d(0.45, 0.45, 0.45);
    glBegin(GL_POLYGON);
    glVertex2d(410, 870);
    glVertex2d(420, 860);
    glVertex2d(1000, 860);
    glVertex2d(1000, 870);
    glVertex2d(410, 870);
    glEnd();

///  Back-Glass inner frame left
    glColor3d(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2d(410, 870);
    glVertex2d(420, 860);
    glVertex2d(420, 470);
    glVertex2d(410, 460);
    glEnd();

///  Back-Glass inner frame bottom
    glColor3d(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2d(420, 470);
    glVertex2d(1000, 470);
    glVertex2d(1000, 460);
    glVertex2d(410, 460);
    glEnd();

///  Back-Glass inner frame middle frame
    glColor3d(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2d(700, 870);
    glVertex2d(710, 870);
    glVertex2d(710, 460);
    glVertex2d(700, 460);
    glEnd();

///  Back-Glass inner frame middle shade
    glColor3d(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2d(710, 870);
    glVertex2d(720, 860);
    glVertex2d(720, 470);
    glVertex2d(710, 460);
    glEnd();

///  Top-back Wall
    glColor3d(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(370, 900);
    glVertex2d(1000, 900);
    glVertex2d(1000, 1000);
    glVertex2d(370, 1000);
    glEnd();

///  Top-back wall shadow
    glColor3d(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(370, 900);
    glVertex2d(400, 880);
    glVertex2d(1000, 880);
    glVertex2d(1000, 900);
    glVertex2d(400, 900);
    glEnd();

/// Clock
    double cl_x=405, cl_y=905, w=50, h=90;

/// Clock Outer
    glColor3d(0.21, 0.27, 0.31);
    glBegin(GL_POLYGON);
    glVertex2d(cl_x, cl_y);
    glVertex2d(cl_x+w, cl_y);
    glVertex2d(cl_x+w, cl_y+h);
    glVertex2d(cl_x, cl_y+h);
    glEnd();

/// Clock Inner
    glColor3d(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2d(cl_x+5, cl_y+5);
    glVertex2d(cl_x+w-5, cl_y+5);
    glVertex2d(cl_x+w-5, cl_y+h-5);
    glVertex2d(cl_x+5, cl_y+h-5);
    glEnd();

/// Clock Second
    glColor3d(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(cl_x+w/2, cl_y+h/2);
    glVertex2d(cl_x+10, cl_y+10);
    glEnd();

/// Clock Minute
    glColor3d(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(cl_x+w/2, cl_y+h/2);
    glVertex2d(cl_x+42, cl_y+60);
    glEnd();

/// Clock Hour
    glColor3d(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(cl_x+w/2, cl_y+h/2);
    glVertex2d(cl_x+12, cl_y+55);
    glEnd();

/// AC front
    glColor3d(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2d(620, 920);
    glVertex2d(770, 920);
    glVertex2d(770, 970);
    glVertex2d(620, 970);
    glEnd();

/// AC top
    glColor3d(.7, .7, .85);
    glBegin(GL_POLYGON);
    glVertex2d(630, 990);
    glVertex2d(780, 990);
    glVertex2d(770, 970);
    glVertex2d(620, 970);
    glEnd();

/// AC bottom
    glColor3d(0.27, 0.35, 0.39);
    glBegin(GL_POLYGON);
    glVertex2d(620, 920);
    glVertex2d(770, 920);
    glVertex2d(780, 910);
    glVertex2d(630, 910);
    glEnd();

/// AC side
    glColor3d(0.15, 0.19, 0.22);
    glBegin(GL_POLYGON);
    glVertex2d(780, 910);
    glVertex2d(770, 920);
    glVertex2d(770, 970);
    glVertex2d(780, 990);
    glEnd();

/// Table1 Left
    glColor3d(0.15, 0.19, 0.22);
    glBegin(GL_POLYGON);
    glVertex2d(180, 200);
    glVertex2d(250, 270);
    glVertex2d(250, 400);
    glVertex2d(180, 330);
    glEnd();

/// Table1 Middle
    glColor3d(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2d(210, 230);
    glVertex2d(390, 230);
    glVertex2d(390, 350);
    glVertex2d(210, 350);
    glEnd();

/// Table1 Right
    glColor3d(0.15, 0.19, 0.22);
    glBegin(GL_POLYGON);
    glVertex2d(380, 200);
    glVertex2d(435, 270);
    glVertex2d(435, 395);
    glVertex2d(380, 330);
    glEnd();

/// Table1 Desk
    glColor3d(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(180, 330);
    glVertex2d(250, 400);
    glVertex2d(435, 395);
    glVertex2d(380, 330);
    glEnd();

/// GRID
    showGrid(hh, ww, 20);
/// GRID


    /*
    ####################################################################################################################
    ##############################----------------------Start-----------------------------##############################
    ####################################################################################################################
    */

////////////////////////////////////////////////--------Wallmat START-------------/////////////////////////////
/// Wallmat background
    glColor3d(0.15, 0.19, 0.22);
    glBegin(GL_POLYGON);
    glVertex2d(220, 640);
    glVertex2d(220, 790);
    glVertex2d(320, 830);
    glVertex2d(320, 740);
    glEnd();


/// Wallmat canvas
    glColor3d(0.15, 0.19, 1);
    glBegin(GL_POLYGON);
    glVertex2d(220, 660);
    glVertex2d(220, 770);
    glVertex2d(320, 810);
    glVertex2d(320, 760);
    glEnd();

 /// Circle
    drawCircle(277,739,15, 255,255,0);

/// Hill Left
    glColor3ub(255, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(220, 660);
    glVertex2d(250, 740);
    glVertex2d(280, 720);
    glEnd();

/// Hill Right
    glColor3d(1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(280, 720);
    glVertex2d(295, 800);
    glVertex2d(320, 760);
    glEnd();
////////////////////////////////////////////////--------Wallmat-END -------------/////////////////////////////


////////////////////////////////////////////////-------- SMALL BOXDESK START-------------/////////////////////////////
/// BOXDESK FRONT
    glColor3d(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2d(580, 420);
    glVertex2d(580, 500);
    glVertex2d(660, 500);
    glVertex2d(660, 420);
    glEnd();

/// BOXDESK DRAWER
    glColor3d(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2d(585, 425);
    glVertex2d(585, 495);
    glVertex2d(655, 495);
    glVertex2d(655, 425);
    glEnd();

    drawCircle(645,460,5, 255, 255, 255);

/// BOXDESK RIGHT SIDE
    glColor3d(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2d(660, 420);
    glVertex2d(660, 500);
    glVertex2d(680, 520);
    glVertex2d(680, 440);
    glEnd();

/// BOXDESK TOP
    glColor3d(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2d(580, 500);
    glVertex2d(600, 520);
    glVertex2d(680, 520);
    glVertex2d(660, 500);
    glEnd();


int flower_r, flower_g, flower_b;
flower_r = 0;
flower_g = 0;
flower_b = 255;
    //////////////////////////////////////////////////////////------------BIG DESK LEFT----------///////////////////////////

/// DESK FRONT
    glColor3d(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2d(440, 420);
    glVertex2d(440, 740);
    glVertex2d(540, 740);
    glVertex2d(540, 420);
    glEnd();

/// DESK RIGHT SIDE
    glColor3d(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(540, 420);
    glVertex2d(540, 740);
    glVertex2d(560, 760);
    glVertex2d(560, 440);
    glEnd();

/// DESK TOP SIDE
    glColor3d(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2d(440, 740);
    glVertex2d(460, 760);
    glVertex2d(560, 760);
    glVertex2d(540, 740);
    glEnd();

/// DESK middle Border
    glColor3d(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(440, 540);
    glVertex2d(440, 550);
    glVertex2d(540, 550);
    glVertex2d(540, 540);
    glEnd();

/// DESK middle Border
    glColor3d(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2d(480, 540);
    glVertex2d(480, 550);
    glVertex2d(500, 550);
    glVertex2d(500, 540);
    glEnd();

/// DESK Stripe Border
    glColor3d(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2d(485, 540);
    glVertex2d(485, 740);
    glVertex2d(490, 740);
    glVertex2d(490, 540);
    glEnd();

/// DESK Stripe Border
    glColor3d(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2d(490, 540);
    glVertex2d(490, 740);
    glVertex2d(495, 740);
    glVertex2d(495, 540);
    glEnd();



    drawCircle(470,640,5, flower_r,flower_g,flower_b);

    drawCircle(510,640,5, flower_r,flower_g,flower_b);


/// DESK BOTTOM DRAWER 1
    glColor3d(.55, .33, 0);
    glBegin(GL_POLYGON);
    glVertex2d(450, 440);
    glVertex2d(450, 480);
    glVertex2d(530, 480);
    glVertex2d(530, 440);
    glEnd();

    drawCircle(490,460,5, flower_r,flower_g,flower_b);

/// DESK BOTTOM DRAWER 2
    glColor3d(.55, .33, 0);
    glBegin(GL_POLYGON);
    glVertex2d(450, 485);
    glVertex2d(450, 525);
    glVertex2d(530, 525);
    glVertex2d(530, 485);
    glEnd();

    drawCircle(490,500,5, flower_r,flower_g,flower_b);


///////////////////////////////////////////*************MONITOR***************////////////////////
// MAT
/// Monitor Border
    glColor3d(.55, .33, 0);
    glBegin(GL_POLYGON);
    glVertex2d(280, 420);
    glVertex2d(280, 500);
    glVertex2d(380, 500);
    glVertex2d(380, 420);
    glEnd();

/// Monitor Screen
    glColor3d(.55, 0, .33);
    glBegin(GL_POLYGON);
    glVertex2d(285, 425);
    glVertex2d(285, 495);
    glVertex2d(375, 495);
    glVertex2d(375, 425);
    glEnd();

/// Monitor Neck
    glColor3d(.55, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(320, 400);
    glVertex2d(320, 420);
    glVertex2d(340, 420);
    glVertex2d(340, 400);
    glEnd();

/// Monitor Stand
    glColor3d(.55, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(300, 380);
    glVertex2d(310, 400);
    glVertex2d(350, 400);
    glVertex2d(360, 380);
    glEnd();

/// Keyboard
    glColor3d(.55, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2d(270, 340);
    glVertex2d(280, 360);
    glVertex2d(370, 360);
    glVertex2d(360, 340);
    glEnd();


///////////////////////////////////////////////-----TABLE 1 CHAIR-----------////////////////////////

/// Chair top
    glColor3d(.55, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(240, 300);
    glVertex2d(240, 380);
    glVertex2d(300, 380);
    glVertex2d(300, 300);
    glEnd();

/// Chair seat
    glColor3d(.55, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(240, 240);
    glVertex2d(260, 280);
    glVertex2d(320, 280);
    glVertex2d(300, 240);
    glEnd();

/// Chair backbone
    glColor3d(.55, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2d(265, 180);
    glVertex2d(265, 360);
    glVertex2d(275, 360);
    glVertex2d(275, 180);
    glEnd();

/// Chair bottom bumper
    glColor3d(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(240, 180);
    glVertex2d(240, 190);
    glVertex2d(300, 190);
    glVertex2d(300, 180);
    glEnd();

/// Chair wheels
    drawCircle(240,180,5, flower_r,flower_g,flower_b);

    drawCircle(300,180,5, flower_r,flower_g,flower_b);

/// Chair bottom bumper
    glColor3d(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(245, 160);
    glVertex2d(265, 180);
    glVertex2d(275, 180);
    glVertex2d(255, 160);
    glEnd();

    drawCircle(250,160,5, flower_r,flower_g,flower_b);

    glFlush ();
}
void init (void) {
    /* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, ww, 0.0, hh, 0.0, 1000.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 800);
    glutInitWindowPosition (10, 10);
    glutCreateWindow ("Raduan_191-15-12943");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}

