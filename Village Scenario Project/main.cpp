#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
float tran_x = 10,boat_x =10,boat_xx =9,angle=0;
int r = 255,g =81, b =54;                                   //press r,h,o to change  color
int sk1= 97,sk2= 224, sk3 =255;
int m=255,o=205,n=64;//sun
int windowWidth = 900;
int windowHeight = 700;
void keyboard(unsigned char key, int w, int h) {
    switch(key) {
        case 'r':
        case 'R':
            r = 255;
            g = 0;
            b = 0;
            glutPostRedisplay();
            break;
        case 'F':
        case 'f':
            glutFullScreen();
            break;

        case 'h':
        case 'H':
            m = 255;
            o  = 255;
            n  = 255;
            glutPostRedisplay();
            break;

        case 'o':
        case 'O':
            sk1 = 0;
            sk2 = 0;
            sk3= 0;
            glutPostRedisplay();
            break;

    }
    if(key == 27) exit(0);

}
void reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 900, 0, 700);
    if(width != 900 || height != 700) {
        glutPositionWindow(400, 100);
        glutReshapeWindow(900, 700);
        glutPostRedisplay();
    }
    glMatrixMode(GL_MODELVIEW);

}
void timer(int value) {
    angle+=2;
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void makeCircle(double r, int x_center, int y_center){
    int deg =0;
    double x, y, theta;
    glPointSize(7);
    glBegin(GL_POLYGON);
    while( deg <360)
    {
        theta = (deg *M_PI)/180;
        x = x_center+r*cos(theta);
        y = y_center+r * sin(theta);
        deg++;
        glVertex2d(x,y);
    }
    glEnd();
}
void ground(){
    glBegin(GL_POLYGON);
             glColor3ub(159,193,49);//ground one
             glVertex2i(0,500);
             glVertex2i(250,500);
             glVertex2i(350,350);
             glVertex2i(300,300);
             glVertex2i(350,250);
             glVertex2i(0,250);
    glEnd();

     glBegin(GL_POLYGON);
             glColor3ub(159,193,49);//ground two
             glVertex2i(900,500);
             glVertex2i(900,250);
             glVertex2i(550,250);
             glVertex2i(500,300);
             glVertex2i(550,350);
             glVertex2i(450,500);
    glEnd();
}
void river(){
    glBegin(GL_POLYGON);
             glColor3ub(0,0,150);//glColor3ub(0,144,0);
             glVertex2i(250,500);
             glVertex2i(450,500);
             glVertex2i(550,350);
             glVertex2i(500,300);
             glVertex2i(550,250);
             glVertex2i(900,250);
             glVertex2i(900,0);
             glVertex2i(0,0);
             glVertex2i(0,250);
             glVertex2i(350,250);
             glVertex2i(300,300);
             glVertex2i(350,350);
    glEnd();

}

void boat_one(){

    glPushMatrix();
    glTranslatef(boat_x, 0, 0);
    glBegin(GL_POLYGON);
             glColor3ub(0,0,0);
             glVertex2i(450,80);
             glVertex2i(500,60);
             glVertex2i(600,60);
             glVertex2i(645,80);
             glVertex2i(600,40);
             glVertex2i(490,40);
    glEnd();
    glColor3ub(118,17,145);
    glRecti(500,60,600,100);

    glColor3ub(151,75,0);
    glRecti(580,100,590,150);

     glColor3ub(0,205,0);
     glBegin(GL_TRIANGLES);// pal
         glVertex2i(520,130);
         glVertex2i(590,200);
         glVertex2i(590,130);
    glEnd();

    glColor3ub(220,0,0);
    makeCircle(10,570,150);
    glPopMatrix();
    boat_x += .2;
    if ( boat_x> 900)
         boat_x = -900;
    glutPostRedisplay();

}
void boat_two(){

    glPushMatrix();
    glTranslatef(boat_x, 0, 0);
    glBegin(GL_POLYGON);
             glColor3ub(0,0,0);
             glVertex2i(150,190);
             glVertex2i(170,170);
             glVertex2i(290,170);
             glVertex2i(310,190);
             glVertex2i(290,150);
             glVertex2i(170,150);

    glEnd();
    glColor3ub(128,0,0);
    glRecti(180,180,290,210);

    glPopMatrix();
    boat_xx += .1;
    if ( boat_xx> 900)
         boat_xx= -900;
    glutPostRedisplay();
}
void cloud(){
     glPushMatrix();
     glTranslatef(tran_x, 0, 0);

    glColor3ub(247,247,247);//cloud one
    makeCircle(20,250,640);
    makeCircle(20,230,640);
    makeCircle(20,210,640);
    makeCircle(20,230,670);

    glColor3ub(247,247,247);//cloud two
    makeCircle(20,550,640);
    makeCircle(20,530,640);
    makeCircle(20,510,640);
    makeCircle(20,530,670);

    glColor3ub(247,247,247);//cloud three
    makeCircle(20,680,640);
    makeCircle(20,660,640);
    makeCircle(20,640,640);
    makeCircle(20,660,670);

    glPopMatrix();
    tran_x += .07;
    if (tran_x > 900)
        tran_x = -900;
    glutPostRedisplay();

}

void tree(){
    glColor3f(0.55,0.27,0.0745); // tree one
    glRecti(115,500,125,600);
    glColor3ub(0,128,0);
    makeCircle(30,120,600);
    makeCircle(30,140,600);
    makeCircle(30,100,600);
    makeCircle(30,120,650);

    glColor3ub(151,75,0); // tree two
    glRecti(825,500,835,600);
    glColor3ub(0,128,0);
    makeCircle(30,820,600);
    makeCircle(30,840,600);
    makeCircle(30,830,650);

    glColor3ub(151,75,0); // tree three
    glRecti(650,500,660,600);
    glBegin(GL_TRIANGLES);// tree_leef 1
         glColor3ub(0,128,0);
         glVertex2i(620,600);
         glVertex2i(690,600);
         glVertex2i(655,700);
    glEnd();
}

void tree_two(){
    glColor3ub(151,75,0); // tree three
    glRecti(230,260,240,300);

    glColor3ub(0,126,63);
    glBegin(GL_TRIANGLES);// tree_leef 1
         glVertex2i(210,300);
         glVertex2i(260,300);
         glVertex2i(235,370);
    glEnd();

    glColor3ub(151,75,0); // tree four
    glRecti(200,370,210,420);

    glColor3ub(0,126,63);
    glBegin(GL_TRIANGLES);// tree_leef 2
         glVertex2i(180,420);
         glVertex2i(205,470);
         glVertex2i(230,420);
    glEnd();

    glColor3ub(151,75,0); // tree five
    glRecti(280,320,290,360);

    glColor3ub(0,126,63);
    glBegin(GL_TRIANGLES);// tree_leef 2
         glVertex2i(260,360);
         glVertex2i(310,360);
         glVertex2i(285,420);
    glEnd();

    glColor3ub(151,75,0); // tree six
    glRecti(70,440,80,470);

     glColor3ub(0,126,63);
     glBegin(GL_TRIANGLES);// tree_leef 2
         glVertex2i(50,470);
         glVertex2i(100,470);
         glVertex2i(75,520);
    glEnd();

     glColor3ub(151,75,0); // tree seven
    glRecti(590,260,600,320);

     glColor3ub(0,126,63);
    glBegin(GL_TRIANGLES);// tree_leef 2
         glVertex2i(570,320);
         glVertex2i(620,320);
         glVertex2i(595,390);
    glEnd();

    glColor3ub(151,75,0); // tree eight
    glRecti(550,400,560,450);

    glColor3ub(0,126,63);
    glBegin(GL_TRIANGLES);// tree_leef 2
         glVertex2i(530,450);
         glVertex2i(580,450);
         glVertex2i(555,530);
    glEnd();

    glColor3ub(151,75,0); // tree eight
    glRecti(650,350,660,400);

    glColor3ub(0,126,63);
    glBegin(GL_TRIANGLES);// tree_leef 2
         glVertex2i(630,400);
         glVertex2i(675,400);
         glVertex2i(655,480);
    glEnd();

    }
void house(){

    glColor3ub(r,g,b);
    glBegin(GL_POLYGON);// top
             glVertex2i(10,390);
             glVertex2i(50,440);
             glVertex2i(140,440);
             glVertex2i(180,390);
    glEnd();

    glColor3ub(251,243,236);//body
    glRecti(30,310,160,390);

    glColor3ub(241,170,144);
    glRecti(80,310,110,350);

    glColor3ub(0,0,0);          //window-1
    glRecti(40,350,60,370);

    glColor3ub(0,0,0);          //window-2
    glRecti(130,350,150,370);

}

void nagordula(){
    glColor3ub(151,75,0);
    glRecti(750,270,760,390);
}

void nagordula_two(){

    glPushMatrix();
    glTranslatef(755,390,0);
    glRotatef(angle,0,0,-1);
    glTranslatef(-755,-390,0);

    glBegin(GL_TRIANGLES);// t-one
    glColor3ub(200,0,0);
             glVertex2i(690,330);
             glVertex2i(690,360);
             glVertex2i(755,390);
    glEnd();

    glBegin(GL_TRIANGLES);// hill
    glColor3ub(200,0,0);
             glVertex2i(690,390);
             glVertex2i(690,420);
             glVertex2i(755,390);
    glEnd();

    glBegin(GL_TRIANGLES);// hill
    glColor3ub(200,0,0);
             glVertex2i(730,460);
             glVertex2i(760,460);
             glVertex2i(755,390);
    glEnd();

    glBegin(GL_TRIANGLES);// hill
    glColor3ub(200,0,0);
             glVertex2i(820,420);
             glVertex2i(820,390);
             glVertex2i(755,390);
    glEnd();

    glBegin(GL_TRIANGLES);// hill
    glColor3ub(200,0,0);
             glVertex2i(820,330);
             glVertex2i(820,360);
             glVertex2i(755,390);
    glEnd();

    glBegin(GL_TRIANGLES);// hill
    glColor3ub(200,0,0);
             glVertex2i(730,330);
             glVertex2i(770,330);
             glVertex2i(755,390);
    glEnd();
    glPopMatrix();
}
void display() {
    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(sk1,sk2,sk3); //sky
    glRecti(0,500,900,700);

     glBegin(GL_POLYGON);// hill
             glColor3ub(151,75,0);
             glVertex2i(0,500);
             glVertex2i(50,600);
             glVertex2i(100,500);
    glEnd();

    glBegin(GL_POLYGON);// hill
             glColor3ub(151,75,0);
             glVertex2i(150,500);
             glVertex2i(250,600);
             glVertex2i(340,500);
    glEnd();

    glBegin(GL_POLYGON);// hill
             glColor3ub(151,75,0);
             glVertex2i(450,500);
             glVertex2i(550,600);
             glVertex2i(625,500);
    glEnd();

    glBegin(GL_POLYGON);// hill
             glColor3ub(151,75,0);
             glVertex2i(700,500);
             glVertex2i(750,600);
             glVertex2i(810,500);
    glEnd();

    glBegin(GL_POLYGON);// hill
             glColor3ub(151,75,0);
             glVertex2i(850,500);
             glVertex2i(900,600);
             glVertex2i(900,500);
    glEnd();

    glBegin(GL_TRIANGLES);// hill---
    glColor3ub(0,126,63);
             glVertex2i(340,500);
             glVertex2i(400,550);
             glVertex2i(450,500);
    glEnd();

    glColor3ub(m,o,n);//sun
    makeCircle(45,400,630);

    cloud();
    tree();
    river();
    ground();
    boat_one();
    boat_two();
    house();
    tree_two();
    nagordula();
    nagordula_two();
    glFlush();
    glutSwapBuffers();

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(500, 100);
    glutInitWindowSize(1000, 700);
    glutCreateWindow("VILLAGE");
    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;

}
