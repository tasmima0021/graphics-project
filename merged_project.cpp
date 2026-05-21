#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <cmath>
#define PI 3.14159f

// SCENE SELECTOR 
int currentScene = 1; // 1 = city scene (default), 2 = nature scene


//  SCENE 1 VARIABLES 
bool isDayR = true;
float timeOfDayR = 0.0f;

float _movecloud1 = 0.0f;
float _speedcloud1 = 0.21f;

float _movecloud2 = 0.0f;
float _speedcloud2 = 0.17f;

float _movecloud3 = 0.0f;
float _speedcloud3 = 0.13f;

float _move1 = 0.0f;
float speed1  = 0.55f;
float angle1  = 0.0f;

float _move2 = 0.0f;
float speed2 = 0.55f;
float angle2 = 0.0f;


// SCENE 2 VARIABLES 
float _movecloudm1 = 0.0f;
float _speedcloudm1 = 0.21f;

float _movecloudm2 = 0.0f;
float _speedcloudm2 = 0.17f;

float _movecloudm3 = 0.0f;
float _speedcloudm3 = 0.13f;

float _movem1 = 0.0f;
float speedm1  = 0.1f;

#define MAX_DROPS 2000
bool  rainActive = false;
float dropX[MAX_DROPS];
float dropY[MAX_DROPS];
int   totalDrops = 0;

float minX = 20.0f, maxX = 180.0f;
float minY = 10.0f, maxY = 110.0f;


//  SHARED FUNCTION 
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * (float)i / (float)num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}


// SCENE 1 FUNCTIONS 

void sun(){
    glColor3f(1.0f, 0.84f, 0.0f);
    drawCircle(133.9917139933831f, 102.2321896340315f, 6.2531f, 100);
}

void moon(){
    glColor3f(0.95f, 0.95f, 0.95f);
    drawCircle(133.9917139933831f, 102.2321896340315f, 6.2531f, 100);
}

void moon2(){
    glColor3f(0.05f, 0.05f, 0.25f);
    drawCircle(131.4672228869984f, 103.8891160430279f, 5.82171f, 100);
}

void cloud1(){
    glPushMatrix();
    glTranslatef(_movecloud1, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(46.7378089103416f,  96.7957373843854f, 4.5872f, 100);
    drawCircle(57.3488784014373f,  96.8209901434938f, 4.5193f, 100);
    drawCircle(52.2880229820523f,  99.8223455739813f, 4.4504f, 100);
    drawCircle(52.2809577747879f,  93.8126948168084f, 4.4308f, 100);
    glPopMatrix();
}

void cloud2(){
    glPushMatrix();
    glTranslatef(_movecloud1, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(96.7378089103416f,  96.7957373843854f, 4.5872f, 100);
    drawCircle(107.3488784014373f, 96.8209901434938f, 4.5193f, 100);
    drawCircle(102.2880229820523f, 99.8223455739813f, 4.4504f, 100);
    drawCircle(102.2809577747879f, 93.8126948168084f, 4.4308f, 100);
    glPopMatrix();
}

void cloud3(){
    glPushMatrix();
    glTranslatef(_movecloud1, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(146.7378089103416f,  96.7957373843854f, 4.5872f, 100);
    drawCircle(157.3488784014373f,  96.8209901434938f, 4.5193f, 100);
    drawCircle(152.2880229820523f,  99.8223455739813f, 4.4504f, 100);
    drawCircle(152.2809577747879f,  93.8126948168084f, 4.4308f, 100);
    glPopMatrix();
}

void sky(){
    glBegin(GL_QUADS);
        glVertex2f(20.0f, 110.0f);
        glVertex2f(20.0, 41.0);
        glVertex2f(180.0, 45.0);
        glVertex2f(180.0f, 110.0f);
    glEnd();
}

void grassfield() {
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(20.0f, 18.0f);
        glVertex2f(20.0f, 10.0f);
        glVertex2f(180.0f, 10.0f);
        glVertex2f(180.0f, 18.0f);
    glEnd();
}

void grassfield2(){
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(20.0, 45.0);
        glVertex2f(20.0, 41.0);
        glVertex2f(180.0, 41.0);
        glVertex2f(180.0, 45.0);
    glEnd();
}

void tree4(){
    // TREE 1 
    glColor3f(0.45f, 0.25f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(34.0f, 10.0f);
        glVertex2f(34.0f, 13.5f);
        glVertex2f(36.0f, 13.5f);
        glVertex2f(36.0f, 10.0f);
    glEnd();
    glColor3f(0.0f, 0.45f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(29.0f, 13.5f);
        glVertex2f(41.0f, 13.5f);
        glVertex2f(35.0f, 19.0f);
    glEnd();

    //  TREE 2 
    glColor3f(0.45f, 0.25f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(99.0f, 10.0f);
        glVertex2f(99.0f, 13.5f);
        glVertex2f(101.0f, 13.5f);
        glVertex2f(101.0f, 10.0f);
    glEnd();
    glColor3f(0.0f, 0.45f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(94.0f, 13.5f);
        glVertex2f(106.0f, 13.5f);
        glVertex2f(100.0f, 19.0f);
    glEnd();

    //TREE 3 (right) 
    glColor3f(0.45f, 0.25f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(154.0f, 10.0f);
        glVertex2f(154.0f, 13.5f);
        glVertex2f(156.0f, 13.5f);
        glVertex2f(156.0f, 10.0f);
    glEnd();
    glColor3f(0.0f, 0.45f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(149.0f, 13.5f);
        glVertex2f(161.0f, 13.5f);
        glVertex2f(155.0f, 19.0f);
    glEnd();

    // BENCH 
    glColor3f(0.5f, 0.25f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(118.0f, 12.5f);
        glVertex2f(118.0f, 13.2f);
        glVertex2f(132.0f, 13.2f);
        glVertex2f(132.0f, 12.5f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(119.0f, 10.0f);
        glVertex2f(119.0f, 12.5f);
        glVertex2f(120.2f, 12.5f);
        glVertex2f(120.2f, 10.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(129.8f, 10.0f);
        glVertex2f(129.8f, 12.5f);
        glVertex2f(131.0f, 12.5f);
        glVertex2f(131.0f, 10.0f);
    glEnd();
}

void building1(){
    glColor3f(0.290f, 0.478f, 0.471f);
    glBegin(GL_QUADS);
        glVertex2f(110, 80);
        glVertex2f(110.0, 45.0);
        glVertex2f(135.0, 45.0);
        glVertex2f(135.0, 80.0);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_QUADS);
        glVertex2f(110.0, 80.0);
        glVertex2f(110.7, 80.0);
        glVertex2f(110.7, 45.0);
        glVertex2f(110.0, 45.0);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_QUADS);
        glVertex2f(134.3, 80.0);
        glVertex2f(135, 80.0);
        glVertex2f(135.0, 45.0);
        glVertex2f(134.3, 45.0);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_QUADS);
        glVertex2f(110.7, 80.0);
        glVertex2f(110.7, 79.3);
        glVertex2f(134.3, 79.3);
        glVertex2f(134.3, 80.0);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_QUADS);
        glVertex2f(110.7, 75.0);
        glVertex2f(110.7, 74.3);
        glVertex2f(134.3, 74.3);
        glVertex2f(134.3, 75.0);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_QUADS);
        glVertex2f(110.7, 70.0);
        glVertex2f(110.7, 69.3);
        glVertex2f(134.3, 69.3);
        glVertex2f(134.3, 70.0);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_QUADS);
        glVertex2f(110.7, 65.0);
        glVertex2f(110.7, 64.3);
        glVertex2f(134.3, 64.3);
        glVertex2f(134.3, 65.0);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_QUADS);
        glVertex2f(110.7, 60.0);
        glVertex2f(110.7, 59.3);
        glVertex2f(134.3, 59.3);
        glVertex2f(134.3, 60.0);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_QUADS);
        glVertex2f(110.7, 55.0);
        glVertex2f(110.7, 54.3);
        glVertex2f(134.3, 54.3);
        glVertex2f(134.3, 55.0);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_QUADS);
        glVertex2f(110.7, 50.0);
        glVertex2f(110.7, 49.3);
        glVertex2f(134.3, 49.3);
        glVertex2f(134.3, 50.0);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_LINES);
    glVertex2f(115,79.3);
    glVertex2f(115,45);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_LINES);
    glVertex2f(120,79.3);
    glVertex2f(120,45);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_LINES);
    glVertex2f(125,79.3);
    glVertex2f(125,45);
    glEnd();

    glColor3f(0.82, 0.82, 0.82f);
    glBegin(GL_LINES);
    glVertex2f(130,79.3);
    glVertex2f(130,45);
    glEnd();
}

void foodcourt(){
    glColor3f(0.45f, 0.50f, 0.52f);
    glBegin(GL_QUADS);
        glVertex2f(90, 73);
        glVertex2f(90, 45);
        glVertex2f(108, 45);
        glVertex2f(108, 73);
    glEnd();

    glColor3f(0.45f, 0.50f, 0.52f);
    glBegin(GL_QUADS);
        glVertex2f(70, 60);
        glVertex2f(70, 45);
        glVertex2f(108, 45);
        glVertex2f(108, 58);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(89, 74);
        glVertex2f(90, 73);
        glVertex2f(108, 73);
        glVertex2f(109, 74);
    glEnd();

    glColor3f(0.95f, 0.93f, 0.85f);
    glBegin(GL_QUADS);
        glVertex2f(92, 72);
        glVertex2f(92, 61);
        glVertex2f(106, 61);
        glVertex2f(106, 72);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(70, 60);
        glVertex2f(70, 58.8);
        glVertex2f(108, 58.8);
        glVertex2f(108, 60);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(91.8, 72.2);
        glVertex2f(91.8, 60.8);
        glVertex2f(92  , 61);
        glVertex2f(92, 72);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(91.8, 72.2);
        glVertex2f(92, 72);
        glVertex2f(106  , 72);
        glVertex2f(106.2, 72.2);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(106.2, 72.2);
        glVertex2f(106, 72);
        glVertex2f(106  , 61);
        glVertex2f(106.2, 60.8);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(92, 61);
        glVertex2f(91.8 , 60.8);
        glVertex2f(106.2  , 60.8);
        glVertex2f(106, 61);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(92, 70);
        glVertex2f(92 , 69.6);
        glVertex2f(106  , 69.6);
        glVertex2f(106, 70);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(92, 63.4);
        glVertex2f(92 , 63);
        glVertex2f(106  , 63);
        glVertex2f(106, 63.4);
    glEnd();

    glColor3f(0.0, 0.0, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(95,72);
    glVertex2f(95,61);
    glEnd();

    glColor3f(0.0, 0.0, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(99,72);
    glVertex2f(99,61);
    glEnd();

    glColor3f(0.0, 0.0, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(103,72);
    glVertex2f(103,61);
    glEnd();

    glColor3f(0.95f, 0.93f, 0.85f);
    glBegin(GL_QUADS);
        glVertex2f(95.4, 54.4);
        glVertex2f(95.4 , 45);
        glVertex2f(102.6  ,45);
        glVertex2f(102.6, 54.4);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(95, 55);
        glVertex2f(95 , 45);
        glVertex2f(95.4  ,45);
        glVertex2f(95.4, 55);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(95.4, 55);
        glVertex2f(95.4 , 54.4);
        glVertex2f(102.6 ,54.4);
        glVertex2f(102.6, 55);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(102.6, 55);
        glVertex2f(102.6 , 45);
        glVertex2f(103 ,45);
        glVertex2f(103, 55);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(98.9, 55);
        glVertex2f(98.9 , 45);
        glVertex2f(99.4 ,45);
        glVertex2f(99.4, 55);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(90, 73);
        glVertex2f(90, 45);
        glVertex2f(90.2 ,45);
        glVertex2f(90.2, 73);
    glEnd();

    glColor3f(0.95f, 0.93f, 0.85f);
    glBegin(GL_QUADS);
        glVertex2f(72, 57);
        glVertex2f(72, 47);
        glVertex2f(88, 47);
        glVertex2f(88, 57);
    glEnd();

    glColor3f(0.0, 0.0, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(76,57);
    glVertex2f(76,47);
    glEnd();

    glColor3f(0.0, 0.0, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(80,57);
    glVertex2f(80,47);
    glEnd();

    glColor3f(0.0, 0.0, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(84,57);
    glVertex2f(84,47);
    glEnd();

    glColor3f(0.0, 0.0, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(72,54);
    glVertex2f(88,54);
    glEnd();

    glColor3f(0.0, 0.0, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(72,50);
    glVertex2f(88,50);
    glEnd();
}

void building2(){
    glColor3f(0.7f, 0.75f, 0.71f);
    glBegin(GL_QUADS);
        glVertex2f(30, 80);
        glVertex2f(30, 45);
        glVertex2f(64, 45);
        glVertex2f(64, 80);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(31, 78);
        glVertex2f(31, 73);
        glVertex2f(44, 73);
        glVertex2f(44, 78);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(31, 70);
        glVertex2f(31, 65);
        glVertex2f(44, 65);
        glVertex2f(44, 70);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(31, 62);
        glVertex2f(31, 57);
        glVertex2f(44, 57);
        glVertex2f(44, 62);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(31, 54);
        glVertex2f(31, 48);
        glVertex2f(44, 48);
        glVertex2f(44, 54);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(50, 78);
        glVertex2f(50, 73);
        glVertex2f(62, 73);
        glVertex2f(62, 78);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(50, 70);
        glVertex2f(50, 65);
        glVertex2f(62, 65);
        glVertex2f(62, 70);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(50, 62);
        glVertex2f(50, 57);
        glVertex2f(62, 57);
        glVertex2f(62, 62);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(50, 54);
        glVertex2f(50, 48);
        glVertex2f(62, 48);
        glVertex2f(62, 54);
    glEnd();
}

void mosque(){
    glColor3f(0.35f, 0.22f, 0.10f);
    glBegin(GL_TRIANGLES);
        glVertex2f(167, 83);
        glVertex2f(165, 80);
        glVertex2f(169, 80);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(165, 80);
        glVertex2f(165, 65);
        glVertex2f(169, 65);
        glVertex2f(169, 80);
    glEnd();

    glColor3f(0.13f, 0.45f, 0.13f);
    drawCircle(168.1134722462732, 68.2459664173526, 8.4590f, 100);

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(154, 63);
        glVertex2f(154, 45);
        glVertex2f(160, 45);
        glVertex2f(160, 65);
    glEnd();

    glColor3f(0.85f, 0.85f, 0.87f);
    glBegin(GL_QUADS);
        glVertex2f(160, 65);
        glVertex2f(160, 45);
        glVertex2f(179, 45);
        glVertex2f(179, 65);
    glEnd();

    glColor3f(0.30f, 0.15f, 0.08f);
    glBegin(GL_POLYGON);
        glVertex2f(170, 50);
        glVertex2f(168,49);
        glVertex2f(168,45);
        glVertex2f(172,45);
        glVertex2f(172,49);
    glEnd();

    glColor3f(0.85f, 0.55f, 0.15f);
    glBegin(GL_QUADS);
        glVertex2f(163, 54);
        glVertex2f(163, 51.6);
        glVertex2f(165, 51.6);
        glVertex2f(165, 54);
    glEnd();

    glColor3f(0.85f, 0.55f, 0.15f);
    glBegin(GL_QUADS);
        glVertex2f(176, 54);
        glVertex2f(176, 51.6);
        glVertex2f(178, 51.6);
        glVertex2f(178, 54);
    glEnd();
}

void tree(){
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
        glVertex2f(34.0, 52.0);
        glVertex2f(34.0, 45.0);
        glVertex2f(38.0, 45.0);
        glVertex2f(38.0, 52.0);
    glEnd();

    glPushMatrix();
    glColor3f(0.0f, 0.8f, 0.0f);
    drawCircle(35.6861254419165f, 60.6469817700911f, 4.7574f, 100);
    drawCircle(32.0184566853971f,  54.7256909563252f, 4.7574f, 100);
    drawCircle(40, 55 , 4.7574f, 100);
    glPopMatrix();
}

void tree2(){
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
        glVertex2f(23.5, 51.0);
        glVertex2f(23.5, 45.0);
        glVertex2f(25.0, 45.0);
        glVertex2f(25.0, 51.0);
    glEnd();

    glColor3f(0.0f, 0.8f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(24.5f, 58.0f);
        glVertex2f(20.5f, 50.0f);
        glVertex2f(28.0f, 50.0f);
    glEnd();

    glColor3f(0.0f, 0.8f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(24.5f, 62.0f);
        glVertex2f(21.0f, 53.0f);
        glVertex2f(28.5f, 53.0f);
    glEnd();
}

void tree3(){
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
        glVertex2f(139, 50);
        glVertex2f(139, 45);
        glVertex2f(140, 45);
        glVertex2f(140, 50);
    glEnd();

    glColor3f(0.0f, 0.8f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(139.5, 54.5);
        glVertex2f(136, 50);
        glVertex2f(143, 50);
    glEnd();

    glColor3f(0.0f, 0.8f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(139.5, 57.5);
        glVertex2f(136.2, 51.8);
        glVertex2f(142.8, 51.8);
    glEnd();

    glColor3f(0.0f, 0.8f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(139.5, 60);
        glVertex2f(136.5, 53.8);
        glVertex2f(142.6, 53.8);
    glEnd();

    glColor3f(0.0f, 0.8f, 0.0f);
    drawCircle(145.0f, 45.0f, 3.6581f, 100);
    drawCircle(150.0f, 45.0f, 5.0277f, 100);
}

void road() {
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(20.0f, 41.0f);
        glVertex2f(20.0f, 18.0f);
        glVertex2f(180.0f, 18.0f);
        glVertex2f(180.0f, 41.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
        glVertex2f(22.0f, 29.5f);
        glVertex2f(22.0f, 30.5f);
        glVertex2f(42.0f, 30.5f);
        glVertex2f(42.0f, 29.5f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(56.0f, 29.5f);
        glVertex2f(56.0f, 30.5f);
        glVertex2f(76.0f, 30.5f);
        glVertex2f(76.0f, 29.5f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(90.0f, 29.5f);
        glVertex2f(90.0f, 30.5f);
        glVertex2f(110.0f, 30.5f);
        glVertex2f(110.0f, 29.5f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(124.0f, 29.5f);
        glVertex2f(124.0f, 30.5f);
        glVertex2f(144.0f, 30.5f);
        glVertex2f(144.0f, 29.5f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(158.0f, 29.5f);
        glVertex2f(158.0f, 30.5f);
        glVertex2f(178.0f, 30.5f);
        glVertex2f(178.0f, 29.5f);
    glEnd();
}

void car1(){
    glPushMatrix();
    glTranslatef(_move1, 0.0f, 0.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(30.0f, 25.5f);
        glVertex2f(30.0f, 20.2f);
        glVertex2f(56.0f, 20.2f);
        glVertex2f(56.0f,25.5f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(37.5, 29.4);
        glVertex2f(34, 25.5);
        glVertex2f(53, 25.5);
        glVertex2f(50, 29.4);
    glEnd();

    glColor3f(0.847f, 0.894f, 0.914f);
    glBegin(GL_QUADS);
        glVertex2f(37.8, 28.9);
        glVertex2f(35, 25.5);
        glVertex2f(43, 25.5);
        glVertex2f(43, 28.9);
    glEnd();

    glColor3f(0.847f, 0.894f, 0.914f);
    glBegin(GL_QUADS);
        glVertex2f(43.5, 28.9);
        glVertex2f(43.5, 25.5);
        glVertex2f(51.3, 25.5);
        glVertex2f(49.6, 28.9);
    glEnd();

    glPushMatrix();
    glTranslatef(36.0f, 20.5748862832272f, 0.0f);
    glRotatef(angle1, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.0f, 0.0f, 2.2f, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50.1693269552945f, 20.6416901282634f, 0.0f);
    glRotatef(angle1, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.0f, 0.0f, 2.2f, 100);
    glPopMatrix();

    glPopMatrix();
}

void car2() {
    glPushMatrix();
    glTranslatef(_move2, 2.0f, 0.0f);

    glColor3f(0.000f, 0.467f, 0.745f);
    glBegin(GL_QUADS);
        glVertex2f(126.0f, 35.5f);
        glVertex2f(126.0f, 30.2f);
        glVertex2f(100.0f, 30.2f);
        glVertex2f(100.0f, 35.5f);
    glEnd();

    glColor3f(0.000f, 0.467f, 0.745f);
    glBegin(GL_QUADS);
        glVertex2f(118.5f, 39.4f);
        glVertex2f(122.0f, 35.5f);
        glVertex2f(103.0f, 35.5f);
        glVertex2f(106.0f, 39.4f);
    glEnd();

    glColor3f(0.847f, 0.894f, 0.914f);
    glBegin(GL_QUADS);
        glVertex2f(118.2f, 38.9f);
        glVertex2f(121.0f, 35.5f);
        glVertex2f(113.0f, 35.5f);
        glVertex2f(113.0f, 38.9f);
    glEnd();

    glColor3f(0.847f, 0.894f, 0.914f);
    glBegin(GL_QUADS);
        glVertex2f(112.5f, 38.9f);
        glVertex2f(112.5f, 35.5f);
        glVertex2f(104.7f, 35.5f);
        glVertex2f(106.4f, 38.9f);
    glEnd();

    glPushMatrix();
    glTranslatef(120.0f, 30.5748862832272f, 0.0f);
    glRotatef(angle1, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.0f, 0.0f, 2.2f, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(105.8306730447055f, 30.6416901282634f, 0.0f);
    glRotatef(angle1, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.0f, 0.0f, 2.2f, 100);
    glPopMatrix();

    glPopMatrix();
}

void star() {
    glColor3f(1.0f, 1.0f, 0.8f);

    glBegin(GL_POLYGON);
        glVertex2f(26.0f, 105.35f);
        glVertex2f(25.82f, 105.0f);
        glVertex2f(26.18f, 105.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(25.82f, 105.20f);
        glVertex2f(26.0f, 104.90f);
        glVertex2f(26.18f, 105.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(34.0f, 101.35f);
        glVertex2f(33.82f, 101.0f);
        glVertex2f(34.18f, 101.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(33.82f, 101.20f);
        glVertex2f(34.0f, 100.90f);
        glVertex2f(34.18f, 101.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(41.0f, 107.35f);
        glVertex2f(40.82f, 107.0f);
        glVertex2f(41.18f, 107.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(40.82f, 107.20f);
        glVertex2f(41.0f, 106.90f);
        glVertex2f(41.18f, 107.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(49.0f, 99.35f);
        glVertex2f(48.82f, 99.0f);
        glVertex2f(49.18f, 99.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(48.82f, 99.20f);
        glVertex2f(49.0f, 98.90f);
        glVertex2f(49.18f, 99.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(56.0f, 104.35f);
        glVertex2f(55.82f, 104.0f);
        glVertex2f(56.18f, 104.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(55.82f, 104.20f);
        glVertex2f(56.0f, 103.90f);
        glVertex2f(56.18f, 104.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(63.0f, 108.35f);
        glVertex2f(62.82f, 108.0f);
        glVertex2f(63.18f, 108.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(62.82f, 108.20f);
        glVertex2f(63.0f, 107.90f);
        glVertex2f(63.18f, 108.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(71.0f, 100.35f);
        glVertex2f(70.82f, 100.0f);
        glVertex2f(71.18f, 100.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(70.82f, 100.20f);
        glVertex2f(71.0f, 99.90f);
        glVertex2f(71.18f, 100.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(79.0f, 106.35f);
        glVertex2f(78.82f, 106.0f);
        glVertex2f(79.18f, 106.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(78.82f, 106.20f);
        glVertex2f(79.0f, 105.90f);
        glVertex2f(79.18f, 106.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(87.0f, 102.35f);
        glVertex2f(86.82f, 102.0f);
        glVertex2f(87.18f, 102.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(86.82f, 102.20f);
        glVertex2f(87.0f, 101.90f);
        glVertex2f(87.18f, 102.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(95.0f, 109.35f);
        glVertex2f(94.82f, 109.0f);
        glVertex2f(95.18f, 109.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(94.82f, 109.20f);
        glVertex2f(95.0f, 108.90f);
        glVertex2f(95.18f, 109.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(103.0f, 98.35f);
        glVertex2f(102.82f, 98.0f);
        glVertex2f(103.18f, 98.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(102.82f, 98.20f);
        glVertex2f(103.0f, 97.90f);
        glVertex2f(103.18f, 98.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(110.0f, 104.35f);
        glVertex2f(109.82f, 104.0f);
        glVertex2f(110.18f, 104.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(109.82f, 104.20f);
        glVertex2f(110.0f, 103.90f);
        glVertex2f(110.18f, 104.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(118.0f, 107.35f);
        glVertex2f(117.82f, 107.0f);
        glVertex2f(118.18f, 107.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(117.82f, 107.20f);
        glVertex2f(118.0f, 106.90f);
        glVertex2f(118.18f, 107.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(126.0f, 101.35f);
        glVertex2f(125.82f, 101.0f);
        glVertex2f(126.18f, 101.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(125.82f, 101.20f);
        glVertex2f(126.0f, 100.90f);
        glVertex2f(126.18f, 101.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(134.0f, 105.35f);
        glVertex2f(133.82f, 105.0f);
        glVertex2f(134.18f, 105.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(133.82f, 105.20f);
        glVertex2f(134.0f, 104.90f);
        glVertex2f(134.18f, 105.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(142.0f, 99.35f);
        glVertex2f(141.82f, 99.0f);
        glVertex2f(142.18f, 99.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(141.82f, 99.20f);
        glVertex2f(142.0f, 98.90f);
        glVertex2f(142.18f, 99.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(149.0f, 108.35f);
        glVertex2f(148.82f, 108.0f);
        glVertex2f(149.18f, 108.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(148.82f, 108.20f);
        glVertex2f(149.0f, 107.90f);
        glVertex2f(149.18f, 108.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(157.0f, 103.35f);
        glVertex2f(156.82f, 103.0f);
        glVertex2f(157.18f, 103.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(156.82f, 103.20f);
        glVertex2f(157.0f, 102.90f);
        glVertex2f(157.18f, 103.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(165.0f, 106.35f);
        glVertex2f(164.82f, 106.0f);
        glVertex2f(165.18f, 106.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(164.82f, 106.20f);
        glVertex2f(165.0f, 105.90f);
        glVertex2f(165.18f, 106.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(173.0f, 100.35f);
        glVertex2f(172.82f, 100.0f);
        glVertex2f(173.18f, 100.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(172.82f, 100.20f);
        glVertex2f(173.0f, 99.90f);
        glVertex2f(173.18f, 100.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(30.0f, 96.35f);
        glVertex2f(29.82f, 96.0f);
        glVertex2f(30.18f, 96.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(29.82f, 96.20f);
        glVertex2f(30.0f, 95.90f);
        glVertex2f(30.18f, 96.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(38.0f, 93.35f);
        glVertex2f(37.82f, 93.0f);
        glVertex2f(38.18f, 93.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(37.82f, 93.20f);
        glVertex2f(38.0f, 92.90f);
        glVertex2f(38.18f, 93.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(46.0f, 89.35f);
        glVertex2f(45.82f, 89.0f);
        glVertex2f(46.18f, 89.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(45.82f, 89.20f);
        glVertex2f(46.0f, 88.90f);
        glVertex2f(46.18f, 89.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(54.0f, 95.35f);
        glVertex2f(53.82f, 95.0f);
        glVertex2f(54.18f, 95.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(53.82f, 95.20f);
        glVertex2f(54.0f, 94.90f);
        glVertex2f(54.18f, 95.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(62.0f, 91.35f);
        glVertex2f(61.82f, 91.0f);
        glVertex2f(62.18f, 91.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(61.82f, 91.20f);
        glVertex2f(62.0f, 90.90f);
        glVertex2f(62.18f, 91.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(70.0f, 87.35f);
        glVertex2f(69.82f, 87.0f);
        glVertex2f(70.18f, 87.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(69.82f, 87.20f);
        glVertex2f(70.0f, 86.90f);
        glVertex2f(70.18f, 87.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(88.0f, 90.35f);
        glVertex2f(87.82f, 90.0f);
        glVertex2f(88.18f, 90.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(87.82f, 90.20f);
        glVertex2f(88.0f, 89.90f);
        glVertex2f(88.18f, 90.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(100.0f, 94.35f);
        glVertex2f(99.82f, 94.0f);
        glVertex2f(100.18f, 94.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(99.82f, 94.20f);
        glVertex2f(100.0f, 93.90f);
        glVertex2f(100.18f, 94.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(120.0f, 92.35f);
        glVertex2f(119.82f, 92.0f);
        glVertex2f(120.18f, 92.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(119.82f, 92.20f);
        glVertex2f(120.0f, 91.90f);
        glVertex2f(120.18f, 92.20f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(145.0f, 88.35f);
        glVertex2f(144.82f, 88.0f);
        glVertex2f(145.18f, 88.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(144.82f, 88.20f);
        glVertex2f(145.0f, 87.90f);
        glVertex2f(145.18f, 88.20f);
    glEnd();
}

void renderDaySceneR() {
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.53f, 0.81f, 0.98f);
    sky();
    sun();
    cloud1();
    cloud2();
    cloud3();
}

void renderNightSceneR() {
    glColor3f(0.05f, 0.05f, 0.25f);
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    star();
    moon();
    moon2();
}

void displayh() {
    glLoadIdentity();
    if (isDayR) {
        renderDaySceneR();
    } else {
        renderNightSceneR();
    }
    tree3();
    grassfield();
    road();
    grassfield2();
    building1();
    building2();
    mosque();
    foodcourt();
    tree();
    tree2();
    tree4();
    car1();
    car2();
    glutSwapBuffers();
}


// SCENE 2 FUNCTIONS 

void cloud1m(){
    glPushMatrix();
    glTranslatef(_movecloudm1, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(46.7378089103416f,  96.7957373843854f, 4.5872f, 100);
    drawCircle(57.3488784014373f,  96.8209901434938f, 4.5193f, 100);
    drawCircle(52.2880229820523f,  99.8223455739813f, 4.4504f, 100);
    drawCircle(52.2809577747879f,  93.8126948168084f, 4.4308f, 100);
    glPopMatrix();
}

void cloud2m(){
    glPushMatrix();
    glTranslatef(_movecloudm2, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(96.7378089103416f,  96.7957373843854f, 4.5872f, 100);
    drawCircle(107.3488784014373f, 96.8209901434938f, 4.5193f, 100);
    drawCircle(102.2880229820523f, 99.8223455739813f, 4.4504f, 100);
    drawCircle(102.2809577747879f, 93.8126948168084f, 4.4308f, 100);
    glPopMatrix();
}

void cloud3m(){
    glPushMatrix();
    glTranslatef(_movecloudm3, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(146.7378089103416f,  96.7957373843854f, 4.5872f, 100);
    drawCircle(157.3488784014373f,  96.8209901434938f, 4.5193f, 100);
    drawCircle(152.2880229820523f,  99.8223455739813f, 4.4504f, 100);
    drawCircle(152.2809577747879f,  93.8126948168084f, 4.4308f, 100);
    glPopMatrix();
}

void skym(){
    glColor3f(0.53f, 0.81f, 0.98f);
    glBegin(GL_QUADS);
        glVertex2f(20, 110);
        glVertex2f(20, 65);
        glVertex2f(180, 65);
        glVertex2f(180, 110);
    glEnd();
}

void river(){
    glColor3f(0.2f, 0.6f, 0.9f);
    glBegin(GL_QUADS);
        glVertex2f(20, 65);
        glVertex2f(20, 60);
        glVertex2f(180, 60);
        glVertex2f(180, 65);
    glEnd();
}

void field(){
    glColor3f(0.420f, 0.680f, 0.180f);
    glBegin(GL_QUADS);
        glVertex2f(20, 60);
        glVertex2f(20, 10);
        glVertex2f(180, 10);
        glVertex2f(180, 60);
    glEnd();
}

void field2(){
    glColor3f(0.545f, 0.765f, 0.290f);
    glBegin(GL_TRIANGLES);
        glVertex2f(20, 40);
        glVertex2f(20, 25);
        glVertex2f(99, 32.5);
    glEnd();
}

void field3(){
    glColor3f(0.545f, 0.765f, 0.290f);
    glBegin(GL_TRIANGLES);
        glVertex2f(80, 52.5);
        glVertex2f(180, 45);
        glVertex2f(180, 60);
    glEnd();
}

void hill(){
    glColor3f(0.247f, 0.604f, 0.682f);
    glBegin(GL_QUADS);
        glVertex2f(90, 90);
        glVertex2f(50, 65);
        glVertex2f(150, 65);
        glVertex2f(110, 90);
    glEnd();

    glColor3f(0.95f, 0.95f, 0.95f);
    glBegin(GL_POLYGON);
        glVertex2f(90.0f, 90.0f);
        glVertex2f(74.7191011235955f, 80.4494382022472f);
        glVertex2f(87.0f, 85.0f);
        glVertex2f(89.4433158612221f, 78.9707482922409f);
        glVertex2f(99.999675734067f, 85.2326597368598f);
        glVertex2f(110.8665199318207f, 79.595191460218f);
        glVertex2f(110.0f, 85.0f);
        glVertex2f(124.9497599952499f, 80.6564000029688f);
        glVertex2f(110.0f, 90.0f);
    glEnd();
}

void hill2(){
    glColor3f(0.337f, 0.475f, 0.502f);
    glBegin(GL_QUADS);
        glVertex2f(150, 65);
        glVertex2f(180, 65);
        glVertex2f(180, 70);
        glVertex2f(160, 80);
    glEnd();

    glColor3f(0.290f, 0.420f, 0.451f);
    glBegin(GL_TRIANGLES);
        glVertex2f(160, 80);
        glVertex2f(150, 65);
        glVertex2f(143.4845841434112, 69.072134910368);
    glEnd();
}

void boat(){
    glPushMatrix();
    glTranslatef(_movem1, 0.0f, 0.0f);

    glColor3f(0.961f, 0.773f, 0.094f);
    glBegin(GL_QUADS);
        glVertex2f(108, 64);
        glVertex2f(110, 62);
        glVertex2f(120, 62);
        glVertex2f(122, 64);
    glEnd();

    glColor3f(0.1f, 0.05f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(113.9, 74);
        glVertex2f(114, 74);
        glVertex2f(114, 64);
        glVertex2f(113.9, 64);
    glEnd();

    glColor3f(0.910f, 0.224f, 0.165f);
    glBegin(GL_TRIANGLES);
        glVertex2f(114, 73.2);
        glVertex2f(120.5, 65.2);
        glVertex2f(114, 65.2);
    glEnd();

    glColor3f(0.1f, 0.05f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(113.9, 73.6);
        glVertex2f(113.9, 74);
        glVertex2f(110.4, 64);
        glVertex2f(110.6, 64);
    glEnd();

    glPopMatrix();
}

void house(){
    glColor3f(0.910f, 0.224f, 0.165f);
    glBegin(GL_QUADS);
        glVertex2f(145, 61);
        glVertex2f(135, 55);
        glVertex2f(175, 55);
        glVertex2f(165, 61);
    glEnd();

    glColor3f(0.961f, 0.961f, 0.863f);
    glBegin(GL_QUADS);
        glVertex2f(140, 55);
        glVertex2f(140, 44);
        glVertex2f(170, 44);
        glVertex2f(170, 55);
    glEnd();

    glColor3f(0.545f, 0.271f, 0.075f);
    glBegin(GL_QUADS);
        glVertex2f(151, 50);
        glVertex2f(151, 44);
        glVertex2f(159, 44);
        glVertex2f(159, 50);
    glEnd();

    glColor3f(0.545f, 0.271f, 0.075f);
    glBegin(GL_QUADS);
        glVertex2f(142, 52);
        glVertex2f(142, 49.4);
        glVertex2f(146, 49.4);
        glVertex2f(146, 52);
    glEnd();

    glColor3f(0.545f, 0.271f, 0.075f);
    glBegin(GL_QUADS);
        glVertex2f(164, 52);
        glVertex2f(164, 49.4);
        glVertex2f(168, 49.4);
        glVertex2f(168, 52);
    glEnd();

    glColor3f(0.910f, 0.224f, 0.165f);
    glBegin(GL_QUADS);
        glVertex2f(140, 44);
        glVertex2f(139.5, 43);
        glVertex2f(170.5, 43);
        glVertex2f(170, 44);
    glEnd();
}

void windmill(){
    glColor3f(0.659f, 0.475f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(146, 61);
        glVertex2f(148, 61);
        glVertex2f(147.36, 70);
        glVertex2f(146.6, 70);
    glEnd();

    glColor3f(0.831f, 0.827f, 0.792f);
    drawCircle(146.982011533702f, 70.1938502873849f, 0.4608f, 100);

    glColor3f(0.969f, 0.812f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(147.1726838016121, 69.774161799855);
        glVertex2f(148, 62);
        glVertex2f(143, 62);
    glEnd();

    glColor3f(0.969f, 0.812f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(146.52108128806659, 70.1999856073607);
        glVertex2f(137.8, 68);
        glVertex2f(139.4, 72.6);
    glEnd();

    glColor3f(0.969f, 0.812f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(146.9945825031321, 70.6546499304433);
        glVertex2f(148, 80);
        glVertex2f(143, 79);
    glEnd();

    glColor3f(0.969f, 0.812f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(147.4429709274351, 70.1971332196721);
        glVertex2f(156.8, 69.65);
        glVertex2f(158, 74);
    glEnd();
}

void treem(){
    glColor3f(0.165f, 0.545f, 0.165f);
    drawCircle(57.2267302992607f, 59.3371900768569f,  12.7904f, 100);

    glColor3f(0.408f, 0.722f, 0.200f);
    drawCircle(56.9703166833458f, 43.6959594755418f, 9.7772f, 100);

    glColor3f(0.122f, 0.286f, 0.137f);
    drawCircle(23.5603526736602f, 45.7151731160162f, 7.3197f, 100);

    glColor3f(0.165f, 0.545f, 0.165f);
    drawCircle(27.2507986629503f, 59.9233902024915f, 9.4565f, 100);

    glColor3f(0.408f, 0.722f, 0.200f);
    drawCircle(41.3060697285697f, 67.882918798553f, 15.2547f, 100);

    glColor3f(0.247f, 0.12f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(35, 44);
        glVertex2f(38, 44);
        glVertex2f(36, 10);
        glVertex2f(30, 10);
    glEnd();

    glColor3f(0.247f, 0.12f, 0.05f);
    glBegin(GL_POLYGON);
        glVertex2f(38.0f, 44.0f);
        glVertex2f(42.0,46.0);
        glVertex2f(55.0f, 45.0f);
        glVertex2f(55.5f, 45.5f);
        glVertex2f(43.0f, 47.0f);
        glVertex2f(60.0f, 55.0f);
        glVertex2f(58.3752106329381f, 54.8358399451939f);
        glVertex2f(43.0732443311814f, 48.0079221370469f);
        glVertex2f(44.2232722196051f, 55.997589572411f);
        glVertex2f(39.8652718003155f, 47.9473943534456f);
        glVertex2f(35.0f, 47.5f);
        glVertex2f(30.0f, 55.0f);
        glVertex2f(28.8710243875676f, 55.0052088740891f);
        glVertex2f(32.2194456025592f, 48.0039645154702f);
        glVertex2f(25.9567230743619f, 48.8092799177172f);
        glVertex2f(26.0f, 48.0f);
        glVertex2f(35.0f, 44.0f);
    glEnd();
}

void grasstreem(){
    glColor3f(0.122f, 0.286f, 0.137f);
    drawCircle(26.1032476088069f, 16.2928150356515f,  8.5411f, 100);
    drawCircle(67.8976257689406f, 14.9577168418213f,  9.1854f, 100);
    drawCircle(170.623906150935f, 16.8272000534163f,  13.4433f, 100);

    glColor3f(0.263f, 0.682f, 0.176f);
    drawCircle(38.641561056847, 17.163531249019f,  10.6455f, 100);
    drawCircle(53.5017844026723f, 13.7387141431068f,  8.6543f, 100);
    drawCircle(83.6687917043414f, 13.1669535983914f,  9.4289f, 100);
    drawCircle(101.0181019505673f, 16.0585053117348f,  9.9960f, 100);
    drawCircle(153.1514114654528f, 16.0756949041881f,  10.5025f, 100);

    glColor3f(0.165f, 0.545f, 0.165f);
    drawCircle(117.7388139994663f, 16.1842249514454f,  12.5725f, 100);
    drawCircle(136.1554270425855f, 13.7838197439298f,  8.9389f, 100);
}

void flower(){
    glColor3f(1.0f, 0.08f, 0.08f);
    drawCircle(26.1f, 23.2f, 1.35f, 100);
    drawCircle(24.0f, 21.7f, 1.35f, 100);
    drawCircle(24.8f, 19.2f, 1.35f, 100);
    drawCircle(27.4f, 19.2f, 1.35f, 100);
    drawCircle(28.2f, 21.7f, 1.35f, 100);
    glColor3f(1.0f, 0.95f, 0.0f);
    drawCircle(26.1f, 21.0f, 1.15f, 100);

    glColor3f(1.0f, 0.60f, 0.80f);
    drawCircle(38.6f, 24.2f, 1.35f, 100);
    drawCircle(36.5f, 22.7f, 1.35f, 100);
    drawCircle(37.3f, 20.2f, 1.35f, 100);
    drawCircle(39.9f, 20.2f, 1.35f, 100);
    drawCircle(40.7f, 22.7f, 1.35f, 100);
    glColor3f(1.0f, 0.95f, 0.0f);
    drawCircle(38.6f, 22.0f, 1.15f, 100);

    glColor3f(1.0f, 0.85f, 0.0f);
    drawCircle(53.5f, 21.2f, 1.35f, 100);
    drawCircle(51.4f, 19.7f, 1.35f, 100);
    drawCircle(52.2f, 17.2f, 1.35f, 100);
    drawCircle(54.8f, 17.2f, 1.35f, 100);
    drawCircle(55.6f, 19.7f, 1.35f, 100);
    glColor3f(1.0f, 0.45f, 0.0f);
    drawCircle(53.5f, 19.0f, 1.15f, 100);

    glColor3f(1.0f, 0.08f, 0.08f);
    drawCircle(67.9f, 22.2f, 1.35f, 100);
    drawCircle(65.8f, 20.7f, 1.35f, 100);
    drawCircle(66.6f, 18.2f, 1.35f, 100);
    drawCircle(69.2f, 18.2f, 1.35f, 100);
    drawCircle(70.0f, 20.7f, 1.35f, 100);
    glColor3f(1.0f, 0.95f, 0.0f);
    drawCircle(67.9f, 20.0f, 1.15f, 100);

    glColor3f(1.0f, 0.60f, 0.80f);
    drawCircle(83.7f, 20.7f, 1.35f, 100);
    drawCircle(81.6f, 19.2f, 1.35f, 100);
    drawCircle(82.4f, 16.7f, 1.35f, 100);
    drawCircle(85.0f, 16.7f, 1.35f, 100);
    drawCircle(85.8f, 19.2f, 1.35f, 100);
    glColor3f(1.0f, 0.95f, 0.0f);
    drawCircle(83.7f, 18.5f, 1.15f, 100);

    glColor3f(1.0f, 0.85f, 0.0f);
    drawCircle(101.0f, 23.2f, 1.35f, 100);
    drawCircle(98.9f,  21.7f, 1.35f, 100);
    drawCircle(99.7f,  19.2f, 1.35f, 100);
    drawCircle(102.3f, 19.2f, 1.35f, 100);
    drawCircle(103.1f, 21.7f, 1.35f, 100);
    glColor3f(1.0f, 0.45f, 0.0f);
    drawCircle(101.0f, 21.0f, 1.15f, 100);

    glColor3f(1.0f, 0.08f, 0.08f);
    drawCircle(117.7f, 24.2f, 1.35f, 100);
    drawCircle(115.6f, 22.7f, 1.35f, 100);
    drawCircle(116.4f, 20.2f, 1.35f, 100);
    drawCircle(119.0f, 20.2f, 1.35f, 100);
    drawCircle(119.8f, 22.7f, 1.35f, 100);
    glColor3f(1.0f, 0.95f, 0.0f);
    drawCircle(117.7f, 22.0f, 1.15f, 100);

    glColor3f(1.0f, 0.60f, 0.80f);
    drawCircle(136.2f, 21.2f, 1.35f, 100);
    drawCircle(134.1f, 19.7f, 1.35f, 100);
    drawCircle(134.9f, 17.2f, 1.35f, 100);
    drawCircle(137.5f, 17.2f, 1.35f, 100);
    drawCircle(138.3f, 19.7f, 1.35f, 100);
    glColor3f(1.0f, 0.95f, 0.0f);
    drawCircle(136.2f, 19.0f, 1.15f, 100);

    glColor3f(1.0f, 0.85f, 0.0f);
    drawCircle(153.2f, 23.2f, 1.35f, 100);
    drawCircle(151.1f, 21.7f, 1.35f, 100);
    drawCircle(151.9f, 19.2f, 1.35f, 100);
    drawCircle(154.5f, 19.2f, 1.35f, 100);
    drawCircle(155.3f, 21.7f, 1.35f, 100);
    glColor3f(1.0f, 0.45f, 0.0f);
    drawCircle(153.2f, 21.0f, 1.15f, 100);

    glColor3f(1.0f, 0.08f, 0.08f);
    drawCircle(170.6f, 25.2f, 1.35f, 100);
    drawCircle(168.5f, 23.7f, 1.35f, 100);
    drawCircle(169.3f, 21.2f, 1.35f, 100);
    drawCircle(171.9f, 21.2f, 1.35f, 100);
    drawCircle(172.7f, 23.7f, 1.35f, 100);
    glColor3f(1.0f, 0.95f, 0.0f);
    drawCircle(170.6f, 23.0f, 1.15f, 100);
}

void addDrop() {
    if (totalDrops < MAX_DROPS) {
        dropX[totalDrops] = minX + (maxX - minX) * (rand() / (float)RAND_MAX);
        dropY[totalDrops] = maxY;
        totalDrops++;
    }
}

void drawRaindrops() {
    glColor3f(0.4f, 0.7f, 1.0f);
    glBegin(GL_LINES);
    for (int i = 0; i < totalDrops; i++) {
        glVertex2f(dropX[i], dropY[i]);
        glVertex2f(dropX[i], dropY[i] - 1.0f);
    }
    glEnd();
}

void displaym() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    river();
    boat();
    skym();
    field();
    field2();
    field3();
    hill2();
    hill();
    boat();
    treem();
    house();
    windmill();
    sun();
    cloud1m();
    cloud2m();
    cloud3m();
    grasstreem();
    flower();
    drawRaindrops();
    glutSwapBuffers();
}


//  UNIFIED DISPLAY
void displayUnified() {
    if (currentScene == 1) {
        displayh();
    } else {
        displaym();
    }
}


//  SCENE 1 TIMERS
void update(int value) {
    _move1 -= speed1;
    if (_move1 < -180.0f) {
        _move1 = 180.0f;
    }

    _move2 += speed2;
    if (_move2 > 180.0f) {
        _move2 = -180.0f;
    }

    _movecloud1 += _speedcloud1;
    if (_movecloud1 > 200.0f) {
        _movecloud1 = -160.0f;
    }

    _movecloud2 += _speedcloud2;
    if (_movecloud2 > 200.0f) {
        _movecloud2 = -210.0f;
    }

    _movecloud3 += _speedcloud3;
    if (_movecloud3 > 200.0f) {
        _movecloud3 = -260.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

void update1(int value) {
    angle1 -= 5.0f;
    if (angle1 < -360.0f) angle1 += 360.0f;

    angle2 -= 5.0f;
    if (angle2 < -360.0f) angle2 += 360.0f;

    glutPostRedisplay();
    glutTimerFunc(10, update1, 0);
}


// SCENE 2 TIMER 
void updatem(int value) {
    _movecloudm1 += _speedcloudm1;
    if (_movecloudm1 > 200.0f) {
        _movecloudm1 = -160.0f;
    }

    _movecloudm2 += _speedcloudm2;
    if (_movecloudm2 > 200.0f) {
        _movecloudm2 = -210.0f;
    }

    _movecloudm3 += _speedcloudm3;
    if (_movecloudm3 > 200.0f) {
        _movecloudm3 = -260.0f;
    }

    _movem1 -= speedm1;
    if (_movem1 < -180.0f) {
        _movem1 = 180.0f;
    }

    if (rainActive) {
        for (int i = 0; i < totalDrops; i++) {
            dropY[i] -= 0.5f;
            if (dropY[i] < minY) {
                dropX[i] = minX + (maxX - minX) * (rand() / (float)RAND_MAX);
                dropY[i] = maxY;
            }
        }
        for (int i = 0; i < 10; i++) {
            addDrop();
        }
    }

    glutPostRedisplay();
    glutTimerFunc(10, updatem, 0);
}


//UNIFIED KEYBOARD 
void handleKeypress(unsigned char key, int x, int y) {
    if (key == '1') { currentScene = 1; glutPostRedisplay(); return; }
    if (key == '2') { currentScene = 2; glutPostRedisplay(); return; }

    if (currentScene == 1) {
        switch (key) {
            case 's': speed1 = 0.0f; speed2 = 0.0f; break;
            case 'r': speed1 = 0.5f; speed2 = 0.5f; break;
            case 'n': isDayR = false; break;
            case 'd': isDayR = true;  break;
        }
    } else {
        switch (key) {
            case 's': speedm1 = 0.0f; break;
            case 'r': speedm1 = 0.5f; break;
            case 'v': rainActive = true; break;
            case 'c': rainActive = false; totalDrops = 0; break;
        }
    }

    glutPostRedisplay();
}


// UNIFIED MOUSE 
void handleMouse(int button, int state, int x, int y) {
    if (currentScene == 1) {
        if (button == GLUT_LEFT_BUTTON)  { speed1 += 0.1f; speed2 += 0.1f; }
        if (button == GLUT_RIGHT_BUTTON) {
            speed1 -= 0.1f; speed2 -= 0.1f;
            if (speed1 < 0.1f) speed1 = 0.1f;
            if (speed2 < 0.1f) speed2 = 0.1f;
        }
    } else {
        if (button == GLUT_LEFT_BUTTON)  { speedm1 += 0.1f; }
        if (button == GLUT_RIGHT_BUTTON) {
            speedm1 -= 0.1f;
            if (speedm1 < 0.1f) speedm1 = 0.1f;
        }
    }
    glutPostRedisplay();
}


// MAIN 
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Project");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(20, 180, 10, 110);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(displayUnified);
    glutTimerFunc(20, update, 0);
    glutTimerFunc(20, update1, 0);
    glutTimerFunc(20, updatem, 0);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}
