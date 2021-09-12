#include<Windows.h>
#include<GL\glut.h>
#include<math.h>
#define PI = 3.14159265

float shipPosition = -500.0;
float x_cloud_position = 0;
float x_boat_position = 0;
float x_wave_position = 0;
static int time=0;

void night(int value);
void day(int value);

void init()
{
    glClearColor(1, 1, 1, 1);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 2560, 0.0, 1440);
}

// ei function er kaj keyboard input neya
void handleKeypress(unsigned char key, int x, int y)
{

    switch (key)
    {


    case 'd':
        glutTimerFunc(0,day,0);
        break;

    case 'n':
        glutTimerFunc(0,night,0);
        break;


        glutPostRedisplay();

    }
}

void cloud_animation()
{
    if(x_cloud_position < 2590)
    {
        x_cloud_position+=0.3;
    }
    else if(x_cloud_position >= 2590)
    {
        x_cloud_position=0;
    }


}

void ship_animation()
{


    if(shipPosition < 2650)
    {
        //ship er position samner dike pathay
        shipPosition+=0.6;
    }
    else if(shipPosition >= 2650)
    {
        shipPosition=-1000;
    }

}


void boat_animation()
{
    if(x_boat_position < 2590)
    {
        x_boat_position-=0.8;
    }
    else if(x_boat_position >= 2590)
    {
        x_boat_position=0;
    }

}
void wave_animation()
{


    if(x_wave_position < 3000)
    {
        //ship er position samner dike pathay
        x_wave_position-=0.2;
    }
    else if(x_wave_position >= 3000)
    {
        x_wave_position=0;
    }

}



void timer(int)
{
    glutPostRedisplay();
    //nijere nije call kore
    glutTimerFunc(1000/75,timer,0);
    //ship er position change korar jonno nicher function call kora hoise
    ship_animation();
    cloud_animation();
    boat_animation();
    wave_animation();

}

void cloud1(int x, int y)
{

    int c1x = x;
    int c1y = y;
    int c2x = c1x+90;
    int c2y = c1y+20;
    int c3x = c2x+80;
    int c3y = c1y;
    int c1r = 60;
    int c2r = 80;
    int c3r = 45;



    float theta;

    //circle 1

    glColor3ub(235, 235, 235);
    glBegin(GL_POLYGON);
    for(int i =0; i<360; i++)
    {
        theta = i* 3.14159/180;
        glVertex2f(c1x+c1r*cos(theta), c1y+c1r*sin(theta));
    }
    glEnd();

    //circle 2

    glBegin(GL_POLYGON);
    for(int i =0; i<360; i++)
    {
        theta = i* 3.14159/180;
        glVertex2f(c2x+c2r*cos(theta), c2y+c2r*sin(theta));
    }
    glEnd();

    //circle 3
    glBegin(GL_POLYGON);
    for(int i =0; i<360; i++)
    {
        theta = i* 3.14159/180;
        glVertex2f(c3x+c3r*cos(theta), c3y+c3r*sin(theta));
    }
    glEnd();





}
void cloud2(int x, int y)
{

    int c1x= x;
    int c1y= y;
    int c2x = c1x+100;
    int c2y = c1y+20;
    int c3x = c2x+100;
    int c3y = c1y;
    int c1r = 60;
    int c2r = 80;
    int c3r = 45;



    float theta;


    //circle 1

    glColor3ub(235, 235, 235);
    glBegin(GL_POLYGON);
    for(int i =0; i<360; i++)
    {
        theta = i* 3.14159/180;
        glVertex2f(c1x+c1r*cos(theta), c1y+c1r*sin(theta));
    }
    glEnd();

    //circle 2

    glBegin(GL_POLYGON);
    for(int i =0; i<360; i++)
    {
        theta = i* 3.14159/180;
        glVertex2f(c2x+c2r*cos(theta), c2y+c2r*sin(theta));
    }
    glEnd();

    //circle 3
    glBegin(GL_POLYGON);
    for(int i =0; i<360; i++)
    {
        theta = i* 3.14159/180;
        glVertex2f(c3x+c3r*cos(theta), c3y+c3r*sin(theta));
    }
    glEnd();

}

void moon(int x, int y)
{

    int c1x = x;
    int c1y = y;

    int c1r = 100;




    float theta;

    //circle 1

    glColor3ub(248, 239, 177);
    glBegin(GL_POLYGON);
    for(int i =0; i<360; i++)
    {
        theta = i* 3.14159/180;
        glVertex2f(c1x+c1r*cos(theta), c1y+c1r*sin(theta));
    }
    glEnd();








}
void riverwave ()
{

    int m;

//for line 0
    for(m=5000 ; m>0 ; m--)
    {

        glColor3ub(158, 232, 250);
        glBegin(GL_POLYGON);
        glVertex2i(m-300, 50);
        glVertex2i(m-200, 50);
        glVertex2i(m-200, 70);
        glVertex2i(m-300, 70);
        glEnd();
        m=m-600;
    };

    //for line 1

    for(m=5000 ; m>0 ; m--)
    {

        glColor3ub(158, 232, 250);
        glBegin(GL_POLYGON);
        glVertex2i(m-100, 150);
        glVertex2i(m, 150);
        glVertex2i(m, 170);
        glVertex2i(m-100, 170);
        glEnd();
        m=m-600;
    };



//for line 2

    for(m=5000 ; m>0 ; m--)
    {

        glColor3ub(158, 232, 250);
        glBegin(GL_POLYGON);
        glVertex2i(m-300, 250);
        glVertex2i(m-200, 250);
        glVertex2i(m-200, 270);
        glVertex2i(m-300, 270);
        glEnd();
        m=m-600;
    };





//for line 3
    for(m=5000 ; m>0 ; m--)
    {

        glColor3ub(158, 232, 250);
        glBegin(GL_POLYGON);
        glVertex2i(m-100, 350);
        glVertex2i(m, 350);
        glVertex2i(m, 370);
        glVertex2i(m-100, 370);
        glEnd();
        m=m-600;
    };

    //for line 4

    for(m=5000 ; m>0 ; m--)
    {

        glColor3ub(158, 232, 250);
        glBegin(GL_POLYGON);
        glVertex2i(m-300, 450);
        glVertex2i(m-200, 450);
        glVertex2i(m-200, 470);
        glVertex2i(m-300, 470);
        glEnd();
        m=m-600;
    };


//for line 5
    for(m=5000 ; m>0 ; m--)
    {

        glColor3ub(158, 232, 250);
        glBegin(GL_POLYGON);
        glVertex2i(m-100, 550);
        glVertex2i(m, 550);
        glVertex2i(m, 570);
        glVertex2i(m-100, 570);
        glEnd();
        m=m-600;
    };

    //for line 6

    for(m=5000 ; m>0 ; m--)
    {

        glColor3ub(158, 232, 250);
        glBegin(GL_POLYGON);
        glVertex2i(m-300, 650);
        glVertex2i(m-200, 650);
        glVertex2i(m-200, 670);
        glVertex2i(m-300, 670);
        glEnd();
        m=m-600;
    };

    //for line 7
    for(m=5000 ; m>0 ; m--)
    {

        glColor3ub(158, 232, 250);
        glBegin(GL_POLYGON);
        glVertex2i(m-100, 750);
        glVertex2i(m, 750);
        glVertex2i(m, 770);
        glVertex2i(m-100, 770);
        glEnd();
        m=m-600;
    };


}

void backgroundcity ()
{
    glPushMatrix();
    glTranslated(130,0,0);

    glScaled(0.95,0.95,0);


    glColor3ub(112, 124, 152);
    glBegin(GL_POLYGON);
    glVertex2i(2450, 800);
    glVertex2i(2560, 800);
    glVertex2i(2560, 1050);
    glVertex2i(2450, 1050);
    glEnd();

    glColor3ub(112, 124, 152);
    glBegin(GL_POLYGON);
    glVertex2i(2300, 800);
    glVertex2i(2450, 800);
    glVertex2i(2450, 950);
    glVertex2i(2300, 950);
    glEnd();

    glColor3ub(112, 124, 152);
    glBegin(GL_POLYGON);
    glVertex2i(2200, 800);
    glVertex2i(2300, 800);
    glVertex2i(2300, 1250);
    glVertex2i(2200, 1250);
    glEnd();

    glColor3ub(112, 124, 152);
    glBegin(GL_POLYGON);
    glVertex2i(1850, 800);
    glVertex2i(2200, 800);
    glVertex2i(2200, 1050);
    glVertex2i(1850, 1050);
    glEnd();

    glColor3ub(112, 124, 152);
    glBegin(GL_POLYGON);
    glVertex2i(1850, 800);
    glVertex2i(2000, 800);
    glVertex2i(2000, 1120);
    glVertex2i(1850, 1120);
    glEnd();

    glColor3ub(112, 124, 152);
    glBegin(GL_POLYGON);
    glVertex2i(1750, 800);
    glVertex2i(1850, 800);
    glVertex2i(1850, 1000);
    glVertex2i(1750, 1000);
    glEnd();
    glColor3ub(112, 124, 152);
    glBegin(GL_POLYGON);
    glVertex2i(1600, 800);
    glVertex2i(1750, 800);
    glVertex2i(1750, 950);
    glVertex2i(1600, 950);
    glEnd();

    glColor3ub(112, 124, 152);
    glBegin(GL_POLYGON);
    glVertex2i(1450, 800);
    glVertex2i(1600, 800);
    glVertex2i(1600, 1200);
    glVertex2i(1450, 1200);
    glEnd();

    glColor3ub(112, 124, 152);
    glBegin(GL_POLYGON);
    glVertex2i(1320, 800);
    glVertex2i(1450, 800);
    glVertex2i(1450, 1000);
    glVertex2i(1320, 1000);
    glEnd();

    glColor3ub(112, 124, 152);
    glBegin(GL_POLYGON);
    glVertex2i(1200, 800);
    glVertex2i(1320, 800);
    glVertex2i(1320, 1120);
    glVertex2i(1200, 1120);
    glEnd();

    glPopMatrix();


}

void boat(int xposition, int yposition)
{

    int x = xposition;
    int y = yposition;

    // boat er tola
    glColor3ub(00, 00, 0);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x+50, y+(-75));
    glVertex2i(x+340, y+(-75));
    glVertex2i(x+340, y);
    glEnd();

    // boat er seat
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(x+180, y);
    glVertex2i(x+290, y);
    glVertex2i(x+290, y+80);
    glVertex2i(x+180, y+80);
    glEnd();

    // boat er piller 1
    glColor3ub(71, 71, 71);
    glBegin(GL_POLYGON);
    glVertex2i(x+120, y);
    glVertex2i(x+127, y);
    glVertex2i(x+127, y+80);
    glVertex2i(x+120, y+80);
    glEnd();

    // boat er piller 2
    glColor3ub(71, 71, 71);
    glBegin(GL_POLYGON);
    glVertex2i(x+135, y);
    glVertex2i(x+142, y);
    glVertex2i(x+142, y+80);
    glVertex2i(x+135, y+80);
    glEnd();

    // boat er seat er chad
    glColor3ub(71, 71, 71);
    glBegin(GL_POLYGON);
    glVertex2i(x+80, y+80);
    glVertex2i(x+290, y+80);
    glVertex2i(x+290, y+100);
    glVertex2i(x+80, y+100);
    glEnd();

    // boat er uporer matha 1
    glColor3ub(71, 71, 71);
    glBegin(GL_POLYGON);
    glVertex2i(x+240, y+100);
    glVertex2i(x+260, y+100);
    glVertex2i(x+260, y+135);
    glVertex2i(x+240, y+135);
    glEnd();

    // boat er uporer matha 2
    glColor3ub(71, 71, 71);
    glBegin(GL_POLYGON);
    glVertex2i(x+210, y+100);
    glVertex2i(x+230, y+100);
    glVertex2i(x+230, y+135);
    glVertex2i(x+210, y+135);
    glEnd();
    //window
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(x+220, y+50);
    glVertex2i(x+250, y+50);
    glVertex2i(x+250, y+20);
    glVertex2i(x+220, y+20);
    glEnd();

    //boat wave
    glColor3ub(158, 232, 250);
    glBegin(GL_POLYGON);
    glVertex2i(x+100, y+(-100));
    glVertex2i(x+370, y+(-100));
    glVertex2i(x+370, y+(-90));
    glVertex2i(x+100, y+(-90));
    glEnd();

    glColor3ub(158, 232, 250);
    glBegin(GL_POLYGON);
    glVertex2i(x+140, y+(-120));
    glVertex2i(x+390, y+(-120));
    glVertex2i(x+390, y+(-110));
    glVertex2i(x+140, y+(-110));
    glEnd();


}

void ship(int xposition, int yposition)
{

    int x = xposition; //1600
    int y = yposition;  //700

    // ship er tola
    glColor3ub(80, 50, 54);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x, y+(-40));
    glVertex2i(x+30, y+(-75));
    glVertex2i(x+840, y+(-75));
    glVertex2i(x+890, y);

    glEnd();

    //backpart

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(x+20, y+100);
    glVertex2i(x+20, y+00);
    glVertex2i(x+240, y+00);
    glVertex2i(x+240, y+100);

    glEnd();

    // head of backpart

    glColor3ub(88, 87, 92);
    glBegin(GL_POLYGON);
    glVertex2i(x+10, y+120);
    glVertex2i(x+10, y+100);
    glVertex2i(x+250, y+100);
    glVertex2i(x+250, y+120);

    glEnd();

    // top backpart

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(x+40, y+200);
    glVertex2i(x+40, y+120);
    glVertex2i(x+220, y+120);
    glVertex2i(x+250, y+200);

    glEnd();
    //window
    glColor3ub(88, 87, 92);
    glBegin(GL_POLYGON);
    glVertex2i(x+180, y+180);
    glVertex2i(x+180, y+160);
    glVertex2i(x+210, y+160);
    glVertex2i(x+218, y+180);

    glEnd();
    //window
    glColor3ub(88, 87, 92);
    glBegin(GL_POLYGON);
    glVertex2i(x+150, y+180);
    glVertex2i(x+150, y+160);
    glVertex2i(x+170, y+160);
    glVertex2i(x+170, y+180);

    glEnd();
    //window
    glColor3ub(88, 87, 92);
    glBegin(GL_POLYGON);
    glVertex2i(x+120, y+180);
    glVertex2i(x+120, y+160);
    glVertex2i(x+140, y+160);
    glVertex2i(x+140, y+180);

    glEnd();



    //container

    glColor3ub(22, 151, 72);
    glBegin(GL_POLYGON);
    glVertex2i(x+660, y+160);
    glVertex2i(x+660, y+80);
    glVertex2i(x+740, y+80);
    glVertex2i(x+740, y+160);

    glEnd();
    glColor3ub(171, 38, 41);

    glBegin(GL_POLYGON);
    glVertex2i(x+660, y+80);
    glVertex2i(x+660, y+0);
    glVertex2i(x+740, y+0);
    glVertex2i(x+740, y+80);

    glEnd();

    glColor3ub(170, 170, 170);
    glBegin(GL_POLYGON);
    glVertex2i(x+580, y+160);
    glVertex2i(x+580, y+80);
    glVertex2i(x+660, y+80);
    glVertex2i(x+660, y+160);

    glEnd();

    glColor3ub(241, 160, 60);
    glBegin(GL_POLYGON);
    glVertex2i(x+580, y+80);
    glVertex2i(x+580, y+0);
    glVertex2i(x+660, y+0);
    glVertex2i(x+660, y+80);

    glEnd();

    glColor3ub(204, 77, 60);
    glBegin(GL_POLYGON);
    glVertex2i(x+500, y+160);
    glVertex2i(x+500, y+80);
    glVertex2i(x+580, y+80);
    glVertex2i(x+580, y+160);

    glEnd();

    glColor3ub(70, 00, 170);
    glBegin(GL_POLYGON);
    glVertex2i(x+500, y+80);
    glVertex2i(x+500, y+0);
    glVertex2i(x+580, y+0);
    glVertex2i(x+580, y+80);

    glEnd();




    glColor3ub(59, 164, 106);
    glBegin(GL_POLYGON);
    glVertex2i(x+420, y+80);
    glVertex2i(x+420, y+00);
    glVertex2i(x+500, y+00);
    glVertex2i(x+500, y+80);

    glEnd();

    glColor3ub(74, 122, 189);
    glBegin(GL_POLYGON);
    glVertex2i(x+340, y+80);
    glVertex2i(x+340, y+00);
    glVertex2i(x+420, y+00);
    glVertex2i(x+420, y+80);

    glEnd();

    glColor3ub(241, 160, 60);
    glBegin(GL_POLYGON);
    glVertex2i(x+260, y+80);
    glVertex2i(x+260, y+00);
    glVertex2i(x+340, y+00);
    glVertex2i(x+340, y+80);

    glEnd();

    glColor3ub(241, 160, 60);
    glBegin(GL_POLYGON);
    glVertex2i(x+420, y+160);
    glVertex2i(x+420, y+80);
    glVertex2i(x+500, y+80);
    glVertex2i(x+500, y+160);

    glEnd();

    glColor3ub(170, 170, 170);
    glBegin(GL_POLYGON);
    glVertex2i(x+340, y+160);
    glVertex2i(x+340, y+80);
    glVertex2i(x+420, y+80);
    glVertex2i(x+420, y+160);

    glEnd();

    glColor3ub(204, 77, 60);
    glBegin(GL_POLYGON);
    glVertex2i(x+260, y+160);
    glVertex2i(x+260, y+80);
    glVertex2i(x+340, y+80);
    glVertex2i(x+340, y+160);

    glEnd();

    //samner part

    glColor3ub(54, 87, 91);
    glBegin(GL_POLYGON);
    glVertex2i(x+710, y+50);
    glVertex2i(x+670, y);
    glVertex2i(x+890, y);
    glVertex2i(x+925, y+50);

    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(x+710, y+60);
    glVertex2i(x+710, y+50);
    glVertex2i(x+925, y+50);
    glVertex2i(x+925, y+60);

    glEnd();


    glColor3ub(54, 87, 91);
    glBegin(GL_POLYGON);
    glVertex2i(x, y+40);
    glVertex2i(x, y+00);
    glVertex2i(x+225, y+00);
    glVertex2i(x+225, y+40);

    glEnd();

    //flag stand

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(x+850, y+120);
    glVertex2i(x+850, y+60);
    glVertex2i(x+855, y+60);
    glVertex2i(x+855, y+120);

    glEnd();

    //flag
    glColor3ub(59, 164, 106);
    glBegin(GL_POLYGON);

    glVertex2i(x+800, y+110);
    glVertex2i(x+855, y+100);
    glVertex2i(x+855, y+120);

    glEnd();

    //flag stand matha

    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(x+850, y+130);
    glVertex2i(x+850, y+120);
    glVertex2i(x+855, y+120);
    glVertex2i(x+855, y+130);

    glEnd();

    //ship wave
    glColor3ub(158, 232, 250);
    glBegin(GL_POLYGON);
    glVertex2i(x+(-50), y+(-100));
    glVertex2i(x+500, y+(-100));
    glVertex2i(x+500, y+(-90));
    glVertex2i(x+(-50), y+(-90));
    glEnd();

    glColor3ub(158, 232, 250);
    glBegin(GL_POLYGON);
    glVertex2i(x+(-80), y+(-120));
    glVertex2i(x+390, y+(-120));
    glVertex2i(x+390, y+(-110));
    glVertex2i(x+(-80), y+(-110));
    glEnd();

}

void lighthouse()
{

//basement
    glPushMatrix();
    glTranslated(0,-50,0);
    glColor3ub(72, 126, 62);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(1100, 0);
    glVertex2i(950, 305);
    glVertex2i(0, 305);
    glEnd();
    glPopMatrix();




//Down house
    glPushMatrix();
    glTranslated(0,-75,0);
    glScaled(1.1,1.1,0);
    glColor3ub(225,231,237);
    glBegin(GL_POLYGON);
    glVertex2i(500, 300);
    glVertex2i(800, 300);
    glVertex2i(790, 460);
    glVertex2i(510, 460);
    glEnd();


//Down house door
    glPushMatrix();
    glTranslated(50,0,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(625, 300);
    glVertex2i(675, 300);
    glVertex2i(675, 400);
    glVertex2i(625, 400);
    glEnd();
    glPopMatrix();


//head of down house

    glColor3ub(69, 90, 100);
    glBegin(GL_POLYGON);
    glVertex2i(510, 460);
    glVertex2i(790, 460);
    glVertex2i(790, 480);
    glVertex2i(510, 480);
    glEnd();

//main tower

    glColor3ub(232,80,91);
    glBegin(GL_POLYGON);
    glVertex2i(550, 480);
    glVertex2i(750, 480);
    glVertex2i(730, 1020);
    glVertex2i(570, 1020);
    glEnd();

//1st windows of main tower
//280-415

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(605, 528);
    glVertex2i(635, 528);
    glVertex2i(635, 568);
    glVertex2i(605, 568);
    glEnd();

//2nd windows of main tower
//415-550

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(655, 663);
    glVertex2i(685, 663);
    glVertex2i(685, 703);
    glVertex2i(655, 703);
    glEnd();

//3rd windows of main tower
//550-685

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(605, 798);
    glVertex2i(635, 798);
    glVertex2i(635, 838);
    glVertex2i(605, 838);
    glEnd();

//4th windows of main tower
//685-820

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(655, 933);
    glVertex2i(685, 933);
    glVertex2i(685, 973);
    glVertex2i(655, 973);
    glEnd();



//head of main tower
    glColor3ub(69, 90, 100);
    glBegin(GL_POLYGON);
    glVertex2i(565, 1020);
    glVertex2i(735, 1020);
    glVertex2i(735, 1040);
    glVertex2i(565, 1040);
    glEnd();

    //Light source
//    glColor3ub(254, 238, 239);
//    glBegin(GL_POLYGON);
//    glVertex2i(730, 1055);
//
//    glVertex2i(1600, 300);
//    glVertex2i(2000, 300);
//    glVertex2i(730, 1115);
//    glEnd();

// upper house middle body part
    glColor3ub(35, 118, 163);
    glBegin(GL_POLYGON);
    glVertex2i(570, 1040);
    glVertex2i(730, 1040);
    glVertex2i(730, 1130);
    glVertex2i(570, 1130);
    glEnd();


//upper house body first part
    glColor3ub(38, 82, 128);
    glBegin(GL_POLYGON);
    glVertex2i(570, 1040);
    glVertex2i(620, 1040);
    glVertex2i(620, 1130);
    glVertex2i(570, 1130);
    glEnd();

//upper house body last part
    glColor3ub(81, 161, 200);
    glBegin(GL_POLYGON);
    glVertex2i(680, 1040);
    glVertex2i(730, 1040);
    glVertex2i(730, 1130);
    glVertex2i(680, 1130);
    glEnd();


    //upper triangle
    glColor3ub(232,80,91);
    glBegin(GL_TRIANGLES);
    glVertex2i(650, 1225);
    glVertex2i(570, 1130);
    glVertex2i(730, 1130);
    glEnd();
    glPopMatrix();

}

void sea()
{
    //glColor3ub(113, 206, 237);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(2560, 0);
    glVertex2i(2560, 800);
    glVertex2i(0, 800);
    glEnd();

}
void day(int value)
{

    time=0;
    glClear(GL_COLOR_BUFFER_BIT);


    //background_sky
    glColor3ub(178, 209, 228);

    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(2560, 0);

    glVertex2i(2560, 1440);
    glVertex2i(0, 1440);
    glEnd();

    //background city

    glColor3ub(0, 0, 0);
    backgroundcity();

    //sea
    glColor3ub(113, 206, 237);
    sea();

    glPushMatrix();
    glTranslated(x_wave_position,0,0);
    riverwave();
    glPopMatrix();

    ship(shipPosition,800);

    glPushMatrix();
    glTranslated(x_boat_position,0,0);


    boat(500,560);

    boat(1600,410);

    boat(2600,500);


    boat(3600,430);
    glPopMatrix();

    lighthouse();


    glPushMatrix();
    glTranslated(x_cloud_position,0,0);

    cloud2(-1200,1260);

    cloud1(-800,1200);

    cloud2(100,1260);

    cloud1(1000,1160);

    cloud1(1800,1300);

    cloud2(2200,1200);
    glPopMatrix();

    glFlush();
}


void night(int value)
{
    time=1;

    glClear(GL_COLOR_BUFFER_BIT);


    //background
    glColor3ub(0, 6, 81);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(2560, 0);
    glVertex2i(2560, 1440);
    glVertex2i(0, 1440);
    glEnd();

    moon(1650,1170);

    //background city

    backgroundcity();

    //sea

    glColor3ub(18, 70, 157);
    sea();


    glPushMatrix();
    glTranslated(x_wave_position,0,0);
    riverwave();
    glPopMatrix();

    ship(shipPosition,800);

//    glPushMatrix();
//    glTranslated(x_boat_position,0,0);
//
//
//    boat(500,560);
//
//    boat(1600,410);
//
//    boat(2600,500);
//
//
//    boat(3600,430);
//    glPopMatrix();
    //Light source
    glColor3ub(216, 215, 220);
    glBegin(GL_POLYGON);
    glVertex2i(730, 1150);
    glVertex2i(1600, 395);
    glVertex2i(2000, 395);
    glVertex2i(730, 1210);
    glEnd();


    lighthouse();




    glPushMatrix();
    glTranslated(x_cloud_position,0,0);

    cloud2(-1200,1260);

    cloud1(-800,1200);

    cloud2(100,1260);

    cloud1(1000,1160);

    cloud1(1800,1300);

    cloud2(2200,1200);
    glPopMatrix();

    glFlush();



}

void display()
{

    // Clear the color buffer (background)
//SKY
    if(time==0)
    {
        day(0);
    }
    if(time==1)
    {
        night(0);
    }


}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(500, 150);
    glutInitWindowSize(1366, 768);
    glutCreateWindow("Project LightHouse");
    init();

    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);
    glutKeyboardFunc(handleKeypress);

    glutMainLoop();
}
