#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<windows.h>
# define PI 3.1416
using namespace std;

int start_flag=0;

GLfloat positionB = 0.0f;
GLfloat speedB = 0.0f;
GLfloat positionSt = 0.0f;
GLfloat speedSt = 0.0f;
GLfloat positionL2 = 0.0f;
GLfloat speedL2 = 0.0f;
GLfloat positionL3 = 0.0f;
GLfloat speedL3 = 0.0f;
GLfloat positionS = 0.0f;
GLfloat speedS = 0.0f;
GLfloat positionM = 0.0f;
GLfloat speedM = 0.005f;
GLfloat positionC1 = 0.0f;
GLfloat speedC1 = 0.0f;
GLfloat positionC2 = 0.0f;
GLfloat speedC2 = 0.0f;
GLfloat positionC3 = 0.0f;
GLfloat speedC3 = 0.0f;

void update(int value) {

    if(positionB>0.7f)
        positionB = -1.7f;

    positionB += speedB;

 if(positionSt<-1.5f)
        positionSt = 1.0f;

    positionSt -= speedSt;

     if(positionL2>1.5f)
        positionL2 = -1.5f;

    positionL2 += speedL2;

    if(positionL3>1.5f)
        positionL3 = -1.5f;

    positionL3 += speedL3;

    if(positionC1>1.64f)
        positionC1 = -1.0f;

    positionC1 += speedC1;

    if(positionC2<-1.5f)
        positionC2 = 1.0f;

    positionC2 -= speedC2;

    if(positionC3>1.4f)
        positionC3 = -1.0f;

    positionC3 += speedC3;

glutPostRedisplay();
glutTimerFunc(100, update, 0);
}

void updateSun(int value){
        if(positionS<-1.0f)
        positionS = -1.0f;
        positionS -= speedS;

    glutPostRedisplay();
    glutTimerFunc(100, updateSun, 0);
}

void updateMoon(int value){
        if(positionM > 0.7f)
        positionM = 0.7f;
        positionM += speedM;

    glutPostRedisplay();
    glutTimerFunc(100, updateMoon, 0);
}

void Day(int value)
{
    ///Sky
    glBegin(GL_QUADS);
       glColor3ub(0, 191, 255);
       glVertex2f(1.0f,  1.0f);
       glVertex2f(-1.0f, 1.0);
       glColor3ub(191, 239, 255);
       glVertex2f(-1.0f,  0.2f);
       glVertex2f(1.0f,  0.2f);
       glEnd();

    glutPostRedisplay();
    glutTimerFunc(100, Day, 0);
}

void Night(int value)
{
    ///Night_Sky
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(1.0f,  1.0f);
    glVertex2f(-1.0f, 1.0);
    glColor3ub(25, 25, 112);
    glVertex2f(-1.0f,  0.2f);
    glVertex2f(1.0f,  0.2f);
    glEnd();

    glutPostRedisplay();
    glutTimerFunc(100, updateMoon, 0);
}

void Sun(){
    glPushMatrix();
    glTranslatef(0.0f,positionS, 0.0f);

    int s;
    GLfloat p=0.7f;
    GLfloat q= 0.8f;
    GLfloat r= 0.1f;
    int triangle=50;
    GLfloat tp=2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0);
    glVertex2f (p,q);
    for(s= 0;s<=triangle; s++)
    {
        glVertex2f (
                    p+(r*cos(s*tp/triangle)),
                    q+(r*sin(s*tp/triangle))
                    );
    }
    glEnd ();
    glPopMatrix();
}

void Moon()
{
    glPushMatrix();
    glTranslatef(0.0f,positionM,0.0f);

    int s;
    GLfloat p=-0.85f;
    GLfloat q= 0.1f;
    GLfloat r= 0.07f;
    int triangle=50;
    GLfloat tp=2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f (p,q);
    for(s= 0;s<=triangle; s++)
    {
        glVertex2f (
                    p+(r*cos(s*tp/triangle)),
                    q+(r*sin(s*tp/triangle))
                    );
    }
    glEnd ();
    glPopMatrix();
}

void Road(){
    glBegin(GL_QUADS);
       glColor3ub(0, 0, 0);
       glVertex2f(-1.0f, 0.2f);
       glVertex2f(-1.0f,  0.0f);
       glVertex2f(1.0f,  0.0f);
       glVertex2f(1.0f,  0.2f);

       glColor3ub(112, 128, 144);
       glVertex2f(-1.0f, 0.01f);
       glVertex2f(-1.0f,  0.0f);
       glVertex2f(1.0f,  0.0f);
       glVertex2f(1.0f,  0.01f);
       glEnd();
}

void River(){
    glBegin(GL_QUADS);
       glColor3ub(100, 149, 237);
       glVertex2f(-1.0f, 0.0f);
       glVertex2f(-1.0f,  -1.0f);
       glVertex2f(1.0f,  -1.0f);
       glVertex2f(1.0f,  0.0f);
       glEnd();
}

    ///************************************************Terminal_Shade
void Terminal_Shade(){
    ///Shade
    glBegin(GL_QUADS);
       glColor3ub(210, 105, 30);
       glVertex2f(-0.9f, 0.03f);
       glVertex2f(-0.75f, 0.1f);
       glVertex2f(0.9f, 0.1f);
       glVertex2f(0.75f, 0.03f);
       glEnd();
    ///Shade_Stand
       glLineWidth(5);
       glBegin(GL_LINES);
       glColor3ub(255, 255, 255);
       glVertex2f(-0.85f, 0.04f);
       glVertex2f(-0.85f, -0.07f);

       glVertex2f(0.76f, 0.04f);
       glVertex2f(0.76f, -0.07f);

       glVertex2f(-0.74f, 0.1f);
       glVertex2f(-0.74f, -0.17f);

       glVertex2f(0.88f, 0.1f);
       glVertex2f(0.88f, -0.17f);
       glEnd();
}

    ///************************************************Terminal
void Terminal(){
       glBegin(GL_POLYGON);
       glColor3ub(139,126, 102);
       glVertex2f(-1.0f, -0.05f);
       glVertex2f(-1.0f,  -0.3f);
       glVertex2f(1.0f,  -0.3f);
       glVertex2f(1.0f,  -0.05f);
       glEnd();

       glBegin(GL_QUADS);
       glColor3ub(139, 87, 66);
       glVertex2f(-1.0f, -0.3f);
       glVertex2f(-1.0f,  -0.31f);
       glVertex2f(1.0f,  -0.31f);
       glVertex2f(1.0f,  -0.3f);
       glEnd();
}

    ///*************************************************Clouds
void Cloud1(){
    glPushMatrix();
    glTranslatef(positionC1,0.0f,0.0f);

    int i;
    GLfloat p1=-0.65f;
    GLfloat q1= 0.9f;
    GLfloat r1 = 0.06f;
    int triangle1=50;
    GLfloat tp1 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p1,q1);
    for(i= 0;i<=triangle1; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp1/triangle1)),
                    q1+(r1*sin(i*tp1/triangle1))
                    );
    }
    glEnd ();

    GLfloat p2=-0.55f;
    GLfloat q2= 0.9f;
    GLfloat r2 = 0.06f;
    int triangle2=50;
    GLfloat tp2 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p2,q2);
    for(i= 0;i<=triangle2; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp2/triangle2)),
                    q2+(r2*sin(i*tp2/triangle2))
                    );
    }
    glEnd ();

    GLfloat p3=-0.65f;
    GLfloat q3= 0.8f;
    GLfloat r3 = 0.06f;
    int triangle3=50;

    GLfloat tp3 =2.0f * PI;
    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p3,q3);
    for(i= 0;i<=triangle3; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp3/triangle3)),
                    q3+(r3*sin(i*tp3/triangle3))
                    );
    }
    glEnd ();

    GLfloat p4=-0.55f;
    GLfloat q4= 0.8f;
    GLfloat r4 = 0.06f;
    int triangle4=50;
    GLfloat tp4 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p4,q4);
    for(i= 0;i<=triangle4; i++)
    {
        glVertex2f (
                    p4+(r4*cos(i*tp4/triangle4)),
                    q4+(r4*sin(i*tp4/triangle4))
                    );
    }
    glEnd ();

    GLfloat p5=-0.71f;
    GLfloat q5= 0.85f;
    GLfloat r5 = 0.06f;
    int triangle5=50;
    GLfloat tp5 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p5,q5);
    for(i= 0;i<=triangle5; i++)
    {
        glVertex2f (
                    p5+(r5*cos(i*tp5/triangle5)),
                    q5+(r5*sin(i*tp5/triangle5))
                    );
    }
    glEnd ();

    GLfloat p6=-0.49f;
    GLfloat q6= 0.85f;
    GLfloat r6 = 0.06f;
    int triangle6=50;
    GLfloat tp6 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p6,q6);
    for(i= 0;i<=triangle6; i++)
    {
        glVertex2f (
                    p6+(r6*cos(i*tp6/triangle6)),
                    q6+(r6*sin(i*tp6/triangle6))
                    );
    }
    glEnd ();

    GLfloat p7=-0.6f;
    GLfloat q7= 0.85f;
    GLfloat r7 = 0.06f;
    int triangle7=50;
    GLfloat tp7 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p7,q7);
    for(i= 0;i<=triangle7; i++)
    {
        glVertex2f (
                    p7+(r7*cos(i*tp7/triangle7)),
                    q7+(r7*sin(i*tp7/triangle7))
                    );
    }
    glEnd ();
    glPopMatrix();
}

void Cloud2(){
    glPushMatrix();
    glTranslatef(positionC2,0.0f,0.0f);

    int i;
    GLfloat p1=0.25;
    GLfloat q1= 0.75;
    GLfloat r1 = 0.06f;
    int triangle1=50;
    GLfloat tp1 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p1,q1);
    for(i= 0;i<=triangle1; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp1/triangle1)),
                    q1+(r1*sin(i*tp1/triangle1))
                    );
    }
    glEnd ();

    GLfloat p2=0.35;
    GLfloat q2= 0.78f;
    GLfloat r2 = 0.06f;
    int triangle2=50;
    GLfloat tp2 =2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p2,q2);
    for(i= 0;i<=triangle2; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp2/triangle2)),
                    q2+(r2*sin(i*tp2/triangle2))
                    );
    }
    glEnd ();

    GLfloat p3=0.43f;
    GLfloat q3= 0.75;
    GLfloat r3 = 0.06;
    int triangle3=50;

    GLfloat tp3 =2.0f * PI;
    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p3,q3);
    for(i= 0;i<=triangle3; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp3/triangle3)),
                    q3+(r3*sin(i*tp3/triangle3))
                    );
    }
    glEnd ();

    GLfloat p4=0.32;
    GLfloat q4= 0.7;
    GLfloat r4 = 0.06;
    int triangle4=50;
    GLfloat tp4 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p4,q4);
    for(i= 0;i<=triangle4; i++)
    {
        glVertex2f (
                    p4+(r4*cos(i*tp4/triangle4)),
                    q4+(r4*sin(i*tp4/triangle4))
                    );
    }
    glEnd ();

    GLfloat p5=0.4;
    GLfloat q5= 0.68;
    GLfloat r5 = 0.05f;
    int triangle5=50;
    GLfloat tp5 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p5,q5);
    for(i= 0;i<=triangle5; i++)
    {
        glVertex2f (
                    p5+(r5*cos(i*tp5/triangle5)),
                    q5+(r5*sin(i*tp5/triangle5))
                    );
    }
    glEnd ();
    glPopMatrix();
}

void Cloud3(){
    glPushMatrix();
    glTranslatef(positionC3,0.0f,0.0f);

    int i;
    GLfloat p1=-0.2f;
    GLfloat q1= 0.65f;
    GLfloat r1 = 0.04f;
    int triangle1=50;
    GLfloat tp1 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p1,q1);
    for(i= 0;i<=triangle1; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp1/triangle1)),
                    q1+(r1*sin(i*tp1/triangle1))
                    );
    }
    glEnd ();

    GLfloat p2=-0.12f;
    GLfloat q2= 0.68f;
    GLfloat r2 = 0.05f;
    int triangle2=50;
    GLfloat tp2 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p2,q2);
    for(i= 0;i<=triangle2; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp2/triangle2)),
                    q2+(r2*sin(i*tp2/triangle2))
                    );
    }
    glEnd ();

    GLfloat p3=-0.07f;
    GLfloat q3= 0.64f;
    GLfloat r3 = 0.06f;
    int triangle3=50;

    GLfloat tp3 =2.0f * PI;
    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p3,q3);
    for(i= 0;i<=triangle3; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp3/triangle3)),
                    q3+(r3*sin(i*tp3/triangle3))
                    );
    }
    glEnd ();

    GLfloat p4=-0.14f;
    GLfloat q4= 0.62f;
    GLfloat r4 = 0.05f;
    int triangle4=50;
    GLfloat tp4 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p4,q4);
    for(i= 0;i<=triangle4; i++)
    {
        glVertex2f (
                    p4+(r4*cos(i*tp4/triangle4)),
                    q4+(r4*sin(i*tp4/triangle4))
                    );
    }
    glEnd ();
    glPopMatrix();
}


        ///**************************************City_View
void CityView(){
        ///Left Building 1
       glBegin(GL_QUADS);
       glColor3ub(255, 127, 36);
       glVertex2f(-1.0f, 0.6f);
       glVertex2f(-1.0f, 0.1f);
       glVertex2f(-0.96f, 0.1f);
       glVertex2f(-0.96f, 0.61f);

       glColor3ub(255, 127, 36);
       glVertex2f(-0.96f, 0.61f);
       glVertex2f(-0.96f, 0.1f);
       glVertex2f(-0.85f, 0.1f);
       glVertex2f(-0.85f, 0.6f);
       glEnd();

       glLineWidth(5);
       glBegin(GL_LINES);
       glColor3ub(178, 34, 34);
       glVertex2f(-1.0f, 0.6f);
       glVertex2f(-1.0f, 0.1f);

       glVertex2f(-0.96f, 0.1f);
       glVertex2f(-0.96f, 0.61f);

       glVertex2f(-0.85f, 0.1f);
       glVertex2f(-0.85f, 0.6f);

       glVertex2f(-1.0f, 0.6f);
       glVertex2f(-0.96f, 0.61f);

       glVertex2f(-0.96f, 0.61f);
       glVertex2f(-0.85f, 0.6f);
       glEnd();

       ///Left Building 2
       glBegin(GL_QUADS);
       glColor3ub(54, 100, 139);
       glVertex2f(-0.849f, 0.4f);
       glVertex2f(-0.849f, 0.1f);
       glVertex2f(-0.78f, 0.1f);
       glVertex2f(-0.78f, 0.4f);

       ///Left Building 3
       glColor3ub(79, 148, 205);
       glVertex2f(-0.78, 0.5f);
       glVertex2f(-0.78f, 0.1f);
       glVertex2f(-0.72f, 0.1f);
       glVertex2f(-0.72f, 0.5f);

       ///Left Building 4
       glColor3ub(131, 111, 255);
       glVertex2f(-0.72f, 0.73f);
       glVertex2f(-0.72f, 0.1f);
       glVertex2f(-0.65f, 0.1f);
       glVertex2f(-0.65f, 0.74f);

       glVertex2f(-0.65f, 0.74f);
       glVertex2f(-0.65f, 0.1f);
       glVertex2f(-0.53f, 0.1f);
       glVertex2f(-0.53f, 0.73f);
       glEnd();

       glLineWidth(5);
       glBegin(GL_LINES);
       glColor3ub(235, 235, 235);
       glVertex2f(-0.72f, 0.73f);
       glVertex2f(-0.72f, 0.1f);

       glVertex2f(-0.65f, 0.74f);
       glVertex2f(-0.65f, 0.1f);

       glVertex2f(-0.53f, 0.73f);
       glVertex2f(-0.53f, 0.1f);

       glVertex2f(-0.72f, 0.73f);
       glVertex2f(-0.65f, 0.74f);

       glVertex2f(-0.65f, 0.74f);
       glVertex2f(-0.53f, 0.73f);
       glEnd();

       ///Left Building 5
       glBegin(GL_QUADS);
       glColor3ub(255, 255, 224);
       glVertex2f(-0.529f, 0.55f);
       glVertex2f(-0.529f, 0.1f);
       glVertex2f(-0.5f, 0.1f);
       glVertex2f(-0.5, 0.56f);

       glVertex2f(-0.5f, 0.56f);
       glVertex2f(-0.5f, 0.1f);
       glVertex2f(-0.47f, 0.1f);
       glVertex2f(-0.47f, 0.55f);
       glEnd();

       glLineWidth(4);
       glBegin(GL_LINES);
       glColor3ub(218, 165, 32);
       glVertex2f(-0.529f, 0.55f);
       glVertex2f(-0.529f, 0.1f);

       glVertex2f(-0.5f, 0.56f);
       glVertex2f(-0.5f, 0.1f);

       glVertex2f(-0.47f, 0.55f);
       glVertex2f(-0.47f, 0.1f);

       glVertex2f(-0.529f, 0.55f);
       glVertex2f(-0.5f, 0.56f);

       glVertex2f(-0.5f, 0.56f);
       glVertex2f(-0.47f, 0.55f);
       glEnd();

       ///Tower
       glBegin(GL_QUADS);
       glColor3ub(47, 79, 79);
       glVertex2f(-0.469f, 0.75f);
       glVertex2f(-0.469f, 0.1f);
       glVertex2f(-0.44f, 0.1f);
       glVertex2f(-0.44f, 0.75f);

       glVertex2f(-0.461f, 0.765f);
       glVertex2f(-0.461f, 0.75f);
       glVertex2f(-0.447f, 0.75f);
       glVertex2f(-0.447f, 0.765f);

       glVertex2f(-0.466f, 0.8f);
       glVertex2f(-0.466f, 0.765f);
       glVertex2f(-0.443f, 0.765f);
       glVertex2f(-0.443f, 0.8f);

       glVertex2f(-0.461f, 0.815f);
       glVertex2f(-0.461f, 0.8f);
       glVertex2f(-0.448f, 0.8f);
       glVertex2f(-0.448f, 0.815f);
       glEnd();

       ///Tower Stand
       glLineWidth(4);
       glBegin(GL_LINES);
       glColor3ub(218, 165, 32);
       glVertex2f(-0.461, 0.85f);
       glVertex2f(-0.461f, 0.81f);

       glVertex2f(-0.448, 0.85f);
       glVertex2f(-0.448, 0.81f);

       glVertex2f(-0.461f, 0.85f);
       glVertex2f(-0.448f, 0.85f);
       glEnd();

       ///Left Building 6
       glBegin(GL_QUADS);
       glColor3ub(255, 255, 224);
       glVertex2f(-0.439f, 0.45f);
       glVertex2f(-0.439f, 0.1f);
       glVertex2f(-0.38f, 0.1f);
       glVertex2f(-0.38f, 0.46f);

       glVertex2f(-0.38f, 0.46f);
       glVertex2f(-0.38f, 0.1f);
       glVertex2f(-0.25f, 0.1f);
       glVertex2f(-0.25f, 0.45f);
       glEnd();

       glLineWidth(5);
       glBegin(GL_LINES);
       glColor3ub(218, 165, 32);
       glVertex2f(-0.439f, 0.45f);
       glVertex2f(-0.439f, 0.1f);

       glVertex2f(-0.38, 0.46f);
       glVertex2f(-0.38f, 0.1f);

       glVertex2f(-0.25f, 0.45f);
       glVertex2f(-0.25f, 0.1f);

       glVertex2f(-0.439f, 0.45f);
       glVertex2f(-0.38f, 0.46f);

       glVertex2f(-0.38f, 0.46f);
       glVertex2f(-0.25f, 0.45f);
       glEnd();

       ///Left Building 7
       glBegin(GL_QUADS);
       glColor3ub(69, 139, 116);
       glVertex2f(-0.247f, 0.5f);
       glVertex2f(-0.247f, 0.1f);
       glVertex2f(-0.2f, 0.1f);
       glVertex2f(-0.2f, 0.51);

       glColor3ub(82, 139, 139);
       glVertex2f(-0.2f, 0.51f);
       glVertex2f(-0.2f, 0.1f);
       glVertex2f(-0.1f, 0.1f);
       glVertex2f(-0.1f, 0.5f);
       glEnd();

       glLineWidth(5);
       glBegin(GL_LINES);
       glColor3ub(240, 255, 255);
       glVertex2f(-0.247f, 0.5f);
       glVertex2f(-0.247f, 0.1f);

       glVertex2f(-0.2f, 0.51f);
       glVertex2f(-0.2f, 0.1f);

       glVertex2f(-0.1f, 0.51f);
       glVertex2f(-0.1f, 0.1f);

       glVertex2f(-0.247f, 0.5f);
       glVertex2f(-0.2f, 0.51f);

       glVertex2f(-0.2f, 0.51f);
       glVertex2f(-0.1f, 0.5f);
       glEnd();

       ///Left Building 8
       glBegin(GL_QUADS);
       glColor3ub(165, 42, 42);
       glVertex2f(-0.05f, 0.4f);
       glVertex2f(-0.05f, 0.1f);
       glVertex2f(0.1f, 0.1f);
       glVertex2f(0.1f, 0.41);

       glColor3ub(238, 59, 59);
       glVertex2f(0.1f, 0.41f);
       glVertex2f(0.1f, 0.1f);
       glVertex2f(0.5f, 0.1f);
       glVertex2f(0.5f, 0.4f);
       glEnd();

       ///Left Building 9
       glBegin(GL_QUADS);
       glColor3ub(54, 100, 139);
       glVertex2f(0.55f, 0.5f);
       glVertex2f(0.55f, 0.1f);
       glVertex2f(0.6f, 0.1f);
       glVertex2f(0.6f, 0.5f);

       ///Left Building 10
       glColor3ub(79, 148, 205);
       glVertex2f(0.6f, 0.6f);
       glVertex2f(0.6f, 0.1f);
       glVertex2f(0.7f, 0.1f);
       glVertex2f(0.7f, 0.6f);
}

        ///*******************************************Boat
void Boat(){
    glPushMatrix();
    glTranslatef(positionB,0.0f,0.0f);

    ///Deck
       glBegin(GL_QUADS);
       glColor3ub(93, 71, 139);
       glVertex2f(0.4f, -0.4);
       glVertex2f(0.45,  -0.45f);
       glVertex2f(0.58f,  -0.45f);
       glVertex2f(0.65f,  -0.4f);
       glEnd();

    ///Pal_1
       glBegin(GL_TRIANGLES);
       glColor3ub(205, 0, 205);
       glVertex2f(0.43f, -0.39);
       glVertex2f(0.5f,  -0.39f);
       glVertex2f(0.5f,  -0.27);
       glEnd();

    ///Pal_2
       glBegin(GL_TRIANGLES);
       glColor3ub(162, 205, 90);
       glVertex2f(0.5, -0.2);
       glVertex2f(0.5f,  -0.39f);
       glVertex2f(0.57f,  -0.39f);
       glEnd();
    ///Stand
       glLineWidth(3);
       glBegin(GL_LINES);
       glColor3ub(0, 0, 0);
       glVertex2f(0.5, -0.4);
       glVertex2f(0.5f, -0.2f);
       glEnd();

    glPopMatrix();
}

        ///*******************************************Steamer
void Steamer(){
    glPushMatrix();
    glTranslatef(positionSt,0.0f,0.0f);

    ///Deck
    glBegin(GL_QUADS);
       glColor3ub(47, 79, 79);
       glVertex2f(0.2f, -0.75f);
       glVertex2f(0.3f,  -0.83f);
       glVertex2f(0.55f,  -0.83f);
       glVertex2f(0.6f,  -0.75f);
       glEnd();

        ///Tank1
    glBegin(GL_QUADS);
       glColor3ub(218, 165, 32);
       glVertex2f(0.25f, -0.65f);
       glVertex2f(0.25f,  -0.75f);
       glVertex2f(0.55f,  -0.75f);
       glVertex2f(0.55f,  -0.65f);
       glEnd();

       for (float i = 0.25f; i<= 0.55f; i+= 0.03f)
       {
           glLineWidth(2);
           glBegin(GL_LINES); ///Vertical Lines
           glColor3ub(139, 126, 102);
           glVertex2f(i, -0.65f);
           glVertex2f(i, -0.75f);
           glEnd();
       }

       ///Tank2
    glBegin(GL_QUADS);
       glColor3ub(238, 99, 99);
       glVertex2f(0.3f, -0.57f);
       glVertex2f(0.3f,  -0.65f);
       glVertex2f(0.5f,  -0.65f);
       glVertex2f(0.5f,  -0.57f);
       glEnd();

       for (float i = 0.3f; i<= 0.5f; i+= 0.03f)
       {
           glLineWidth(2);
           glBegin(GL_LINES); ///Vertical Lines
           glColor3ub(139, 126, 102);
           glVertex2f(i, -0.57f);
           glVertex2f(i, -0.65f);
           glEnd();
       }

    glPopMatrix();
}

        ///***********************************Launch
void Launch1(){
     ///DeckL3
    glBegin(GL_QUADS);
       glColor3ub(18, 18, 18);
       glVertex2f(-0.9f, -0.3f);
       glVertex2f(-0.89f, -0.375);
       glVertex2f(-0.65f, -0.375);
       glVertex2f(-0.55f, -0.3);
       glEnd();

    ///Deck BorderL2
    glBegin(GL_QUADS);
       glColor3ub(127, 255, 212);
       glVertex2f(-0.9f, -0.29f);
       glVertex2f(-0.9f, -0.3f);
       glVertex2f(-0.55f, -0.3f);
       glVertex2f(-0.55f, -0.29f);
       glEnd();

       ///DeckL2
    glBegin(GL_QUADS);
       glColor3ub(255, 48, 48);
       glVertex2f(-0.88f, -0.22f);
       glVertex2f(-0.88f, -0.29f);
       glVertex2f(-0.6f, -0.29f);
       glVertex2f(-0.65f, -0.22f);
       glEnd();

       ///Windows
       glBegin(GL_QUADS);
       glColor3ub(255, 255, 255);
       glVertex2f(-0.87f, -0.23f);
       glVertex2f(-0.87f, -0.28f);
       glVertex2f(-0.835f, -0.28f);
       glVertex2f(-0.835f, -0.23f);

       glVertex2f(-0.79f, -0.23f);
       glVertex2f(-0.79f, -0.28f);
       glVertex2f(-0.755f, -0.28f);
       glVertex2f(-0.755f, -0.23f);

       glVertex2f(-0.71f, -0.23f);
       glVertex2f(-0.71f, -0.28f);
       glVertex2f(-0.675f, -0.28f);
       glVertex2f(-0.675f, -0.23f);
       glEnd();

       ///Deck BorderL1
    glBegin(GL_QUADS);
       glColor3ub(127, 255, 212);
       glVertex2f(-0.88f, -0.21f);
       glVertex2f(-0.88f, -0.22f);
       glVertex2f(-0.65f, -0.22f);
       glVertex2f(-0.65f, -0.21f);
       glEnd();

       ///DeckL1
    glBegin(GL_QUADS);
       glColor3ub(255, 127, 0);
       glVertex2f(-0.86f, -0.15f);
       glVertex2f(-0.86f, -0.21f);
       glVertex2f(-0.675f, -0.21f);
       glVertex2f(-0.725f, -0.15f);
       glEnd();

    ///Air Pipe 1
    glBegin(GL_QUADS);
       glColor3ub(139, 28, 98);
       glVertex2f(-0.84f, -0.08f);
       glVertex2f(-0.84f, -0.15f);
       glVertex2f(-0.82f, -0.15f);
       glVertex2f(-0.82f, -0.08f);
       glEnd();

       ///Air Pipe 2
    glBegin(GL_QUADS);
       glColor3ub(139, 28, 98);
       glVertex2f(-0.78f, -0.08f);
       glVertex2f(-0.78f, -0.15f);
       glVertex2f(-0.76f, -0.15f);
       glVertex2f(-0.76f, -0.08f);
       glEnd();

       ///Control Room
    glBegin(GL_QUADS);
       glColor3ub(247, 247, 247);
       glVertex2f(-0.855f, -0.16f);
       glVertex2f(-0.855f, -0.2f);
       glVertex2f(-0.69f, -0.2f);
       glVertex2f(-0.73f, -0.16f);
       glEnd();

       ///Window1
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.85f, -0.17);
       glVertex2f(-0.85f, -0.19f);
       glVertex2f(-0.81f, -0.19f);
       glVertex2f(-0.81f, -0.17f);
       glEnd();

       ///Window2
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.80f, -0.17);
       glVertex2f(-0.80f, -0.19f);
       glVertex2f(-0.76f, -0.19f);
       glVertex2f(-0.76f, -0.17f);
       glEnd();

       ///Window3
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.75f, -0.17f);
       glVertex2f(-0.75f, -0.19f);
       glVertex2f(-0.71f, -0.19f);
       glVertex2f(-0.725f, -0.17f);
       glEnd();
}

void Launch2(){
    glPushMatrix();
    glTranslatef(positionL2,0.0f,0.0f);

    ///DeckL3
    glBegin(GL_QUADS);
       glColor3ub(46, 139, 87);
       glVertex2f(-0.2f, -0.5);
       glVertex2f(-0.185f, -0.575);
       glVertex2f(0.1f, -0.575);
       glVertex2f(0.2f, -0.5);
       glEnd();

    ///Deck BorderL2
    glBegin(GL_QUADS);
       glColor3ub(255, 130, 71);
       glVertex2f(-0.2f, -0.5f);
       glVertex2f(-0.2f, -0.495f);
       glVertex2f(0.2f, -0.495f);
       glVertex2f(0.2f, -0.5f);
       glEnd();

       ///DeckL2
    glBegin(GL_QUADS);
       glColor3ub(0, 0, 139);
       glVertex2f(-0.175f, -0.42f);
       glVertex2f(-0.175f, -0.495f);
       glVertex2f(0.125f, -0.495f);
       glVertex2f(0.075f, -0.42f);
       glEnd();

       ///Windows
       glBegin(GL_QUADS);
       glColor3ub(255, 255, 255);
       glVertex2f(-0.15f, -0.435f);
       glVertex2f(-0.15f, -0.48f);
       glVertex2f(-0.12f, -0.48f);
       glVertex2f(-0.12f, -0.435f);

       glVertex2f(-0.07f, -0.435f);
       glVertex2f(-0.07f, -0.48f);
       glVertex2f(-0.04f, -0.48f);
       glVertex2f(-0.04f, -0.435f);

       glVertex2f(0.05f, -0.435f);
       glVertex2f(0.05f, -0.48f);
       glVertex2f(0.02f, -0.48f);
       glVertex2f(0.02f, -0.435f);
       glEnd();

       ///Deck BorderL1
    glBegin(GL_QUADS);
       glColor3ub(255, 130, 71);
       glVertex2f(-0.175f, -0.415f);
       glVertex2f(-0.175f, -0.42f);
       glVertex2f(0.075f, -0.42f);
       glVertex2f(0.075f, -0.415f);
       glEnd();

       ///DeckL1
    glBegin(GL_QUADS);
       glColor3ub(0, 197, 205);
       glVertex2f(-0.16f, -0.35f);
       glVertex2f(-0.16f, -0.415f);
       glVertex2f(0.05f, -0.415f);
       glVertex2f(0.0f, -0.35f);
       glEnd();

    ///Air Pipe 1
    glBegin(GL_QUADS);
       glColor3ub(139, 76, 57);
       glVertex2f(-0.13f, -0.275f);
       glVertex2f(-0.13f, -0.35f);
       glVertex2f(-0.11f, -0.35f);
       glVertex2f(-0.11f, -0.275);
       glEnd();

       ///Air Pipe 2
    glBegin(GL_QUADS);
       glColor3ub(139, 76, 57);
       glVertex2f(-0.07f, -0.275f);
       glVertex2f(-0.07f, -0.35f);
       glVertex2f(-0.05f, -0.35f);
       glVertex2f(-0.05f, -0.275f);
       glEnd();

       ///Control Room
    glBegin(GL_QUADS);
       glColor3ub(247, 247, 247);
       glVertex2f(-0.155f, -0.36f);
       glVertex2f(-0.155f, -0.405f);
       glVertex2f(0.03f, -0.405f);
       glVertex2f(0.0f, -0.36f);
       glEnd();

       ///Window1
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.15f, -0.37);
       glVertex2f(-0.15f, -0.4f);
       glVertex2f(-0.1f, -0.4f);
       glVertex2f(-0.1f, -0.37f);
       glEnd();

       ///Window2
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.09f, -0.37);
       glVertex2f(-0.09f, -0.4f);
       glVertex2f(-0.04f, -0.4f);
       glVertex2f(-0.04f, -0.37f);
       glEnd();

       ///Window3
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.03f, -0.37f);
       glVertex2f(-0.03f, -0.4f);
       glVertex2f(0.01f, -0.4f);
       glVertex2f(0.0f, -0.37f);
       glEnd();

    glPopMatrix();
}

void Launch3(){
    glPushMatrix();
    glTranslatef(positionL3,0.0f,0.0f);

    ///DeckL3
    glBegin(GL_QUADS);
       glColor3ub(18, 18, 18);
       glVertex2f(-0.6f, -0.8);
       glVertex2f(-0.58f, -0.9f);
       glVertex2f(-0.225f, -0.9f);
       glVertex2f(-0.1f, -0.8f);
       glEnd();

    ///Deck BorderL2
    glBegin(GL_QUADS);
       glColor3ub(205, 38, 38);
       glVertex2f(-0.6f, -0.8f);
       glVertex2f(-0.6f, -0.79f);
       glVertex2f(-0.1f, -0.79f);
       glVertex2f(-0.1f, -0.8f);
       glEnd();

       ///DeckL2
    glBegin(GL_QUADS);
       glColor3ub(0, 134, 139);
       glVertex2f(-0.57f, -0.7f);
       glVertex2f(-0.57f, -0.79f);
       glVertex2f(-0.2f, -0.79f);
       glVertex2f(-0.25f, -0.7f);
       glEnd();

       ///Windows
       glBegin(GL_QUADS);
       glColor3ub(255, 255, 255);
       glVertex2f(-0.52f, -0.715f);
       glVertex2f(-0.52f, -0.775f);
       glVertex2f(-0.48f, -0.775f);
       glVertex2f(-0.48f, -0.715f);

       glVertex2f(-0.42f, -0.715f);
       glVertex2f(-0.42f, -0.775f);
       glVertex2f(-0.38f, -0.775f);
       glVertex2f(-0.38f, -0.715f);

       glVertex2f(-0.32f, -0.715f);
       glVertex2f(-0.32f, -0.775f);
       glVertex2f(-0.28f, -0.775f);
       glVertex2f(-0.28f, -0.715f);
       glEnd();

       ///Deck BorderL1
    glBegin(GL_QUADS);
       glColor3ub(205, 38, 38);
       glVertex2f(-0.57f, -0.69f);
       glVertex2f(-0.57f, -0.7f);
       glVertex2f(-0.25f, -0.7f);
       glVertex2f(-0.25f, -0.69f);
       glEnd();

       ///DeckL1
    glBegin(GL_QUADS);
       glColor3ub(25, 25, 112);
       glVertex2f(-0.54, -0.6f);
       glVertex2f(-0.54f, -0.69f);
       glVertex2f(-0.3f, -0.69f);
       glVertex2f(-0.35f, -0.6f);
       glEnd();

    ///Air Pipe 1
    glBegin(GL_QUADS);
       glColor3ub(139, 102, 139);
       glVertex2f(-0.5f, -0.5f);
       glVertex2f(-0.5f, -0.6f);
       glVertex2f(-0.475f, -0.6f);
       glVertex2f(-0.475f, -0.5f);
       glEnd();

       ///Air Pipe 2
    glBegin(GL_QUADS);
       glColor3ub(139, 102, 139);
       glVertex2f(-0.425f, -0.5f);
       glVertex2f(-0.425f, -0.6f);
       glVertex2f(-0.4f, -0.6f);
       glVertex2f(-0.4f, -0.5f);
       glEnd();

       ///Control Room
    glBegin(GL_QUADS);
       glColor3ub(247, 247, 247);
       glVertex2f(-0.535f, -0.61f);
       glVertex2f(-0.535f, -0.68f);
       glVertex2f(-0.31f, -0.68f);
       glVertex2f(-0.35f, -0.61f);
       glEnd();

       ///Window1
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.525f, -0.62f);
       glVertex2f(-0.525f, -0.67f);
       glVertex2f(-0.47f, -0.67f);
       glVertex2f(-0.47f, -0.62f);
       glEnd();

       ///Window2
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.46f, -0.62f);
       glVertex2f(-0.46f, -0.67f);
       glVertex2f(-0.4f, -0.67f);
       glVertex2f(-0.4f, -0.62f);
       glEnd();

       ///Window3
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.39f, -0.62f);
       glVertex2f(-0.39f, -0.67f);
       glVertex2f(-0.32f, -0.67f);
       glVertex2f(-0.35f, -0.62f);
       glEnd();

    glPopMatrix();
}

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    Day(1);
    if(positionS < -0.7f)
                {
                    Night(1);
                }
    Sun();
    Moon();
    Cloud1();
    Cloud2();
    Cloud3();
    CityView();
    Road();
    River();
    Terminal();
    Terminal_Shade();
    Launch1();
    Boat();
    Launch2();
    Steamer();
    Launch3();
    glutSwapBuffers();
}

void handleMouse(int button, int state, int x, int y) {
if (button == GLUT_LEFT_BUTTON)
{    speedC1 = 0.01f;
    speedC2 = 0.015f;
    speedC3 = 0.02f;
}
if (button == GLUT_RIGHT_BUTTON)
{   speedC1 = 0.0f;
    speedC2 = 0.0f;
    speedC3 = 0.0f;
}
glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key){
    case 'a':
        speedB = 0.01f;
        speedSt = 0.025f;
        speedL2 = 0.04f;
        speedL3 = 0.05f;
        break;
    case 's':
        speedB = 0.0f;
        speedSt = 0.0f;
        speedL2 = 0.0f;
        speedL3 = 0.0f;
        break;
    case 'n':
        speedS = 0.01f;
        break;
glutPostRedisplay();
}
}

void myInit(void)
{
    glClearColor(255, 255, 255, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize (1200, 680);
    glutInitWindowPosition (200, 100);
    glutCreateWindow ("Smart Launch Terminal");
    myInit();
    glutDisplayFunc(myDisplay);
    glutTimerFunc(100, update, 0);
    glutTimerFunc(100, updateSun, 0);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutMainLoop();
}
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<windows.h>
# define PI 3.1416
using namespace std;

int start_flag=0;

GLfloat positionB = 0.0f;
GLfloat speedB = 0.0f;
GLfloat positionSt = 0.0f;
GLfloat speedSt = 0.0f;
GLfloat positionL2 = 0.0f;
GLfloat speedL2 = 0.0f;
GLfloat positionL3 = 0.0f;
GLfloat speedL3 = 0.0f;
GLfloat positionS = 0.0f;
GLfloat speedS = 0.0f;
GLfloat positionM = 0.0f;
GLfloat speedM = 0.005f;
GLfloat positionC1 = 0.0f;
GLfloat speedC1 = 0.0f;
GLfloat positionC2 = 0.0f;
GLfloat speedC2 = 0.0f;
GLfloat positionC3 = 0.0f;
GLfloat speedC3 = 0.0f;

void update(int value) {

    if(positionB>0.7f)
        positionB = -1.7f;

    positionB += speedB;

 if(positionSt<-1.5f)
        positionSt = 1.0f;

    positionSt -= speedSt;

     if(positionL2>1.5f)
        positionL2 = -1.5f;

    positionL2 += speedL2;

    if(positionL3>1.5f)
        positionL3 = -1.5f;

    positionL3 += speedL3;

    if(positionC1>1.64f)
        positionC1 = -1.0f;

    positionC1 += speedC1;

    if(positionC2<-1.5f)
        positionC2 = 1.0f;

    positionC2 -= speedC2;

    if(positionC3>1.4f)
        positionC3 = -1.0f;

    positionC3 += speedC3;

glutPostRedisplay();
glutTimerFunc(100, update, 0);
}

void updateSun(int value){
        if(positionS<-1.0f)
        positionS = -1.0f;
        positionS -= speedS;

    glutPostRedisplay();
    glutTimerFunc(100, updateSun, 0);
}

void updateMoon(int value){
        if(positionM > 0.7f)
        positionM = 0.7f;
        positionM += speedM;

    glutPostRedisplay();
    glutTimerFunc(100, updateMoon, 0);
}

void Day(int value)
{
    ///Sky
    glBegin(GL_QUADS);
       glColor3ub(0, 191, 255);
       glVertex2f(1.0f,  1.0f);
       glVertex2f(-1.0f, 1.0);
       glColor3ub(191, 239, 255);
       glVertex2f(-1.0f,  0.2f);
       glVertex2f(1.0f,  0.2f);
       glEnd();

    glutPostRedisplay();
    glutTimerFunc(100, Day, 0);
}

void Night(int value)
{
    ///Night_Sky
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(1.0f,  1.0f);
    glVertex2f(-1.0f, 1.0);
    glColor3ub(25, 25, 112);
    glVertex2f(-1.0f,  0.2f);
    glVertex2f(1.0f,  0.2f);
    glEnd();

    glutPostRedisplay();
    glutTimerFunc(100, updateMoon, 0);
}

void Sun(){
    glPushMatrix();
    glTranslatef(0.0f,positionS, 0.0f);

    int s;
    GLfloat p=0.7f;
    GLfloat q= 0.8f;
    GLfloat r= 0.1f;
    int triangle=50;
    GLfloat tp=2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0);
    glVertex2f (p,q);
    for(s= 0;s<=triangle; s++)
    {
        glVertex2f (
                    p+(r*cos(s*tp/triangle)),
                    q+(r*sin(s*tp/triangle))
                    );
    }
    glEnd ();
    glPopMatrix();
}

void Moon()
{
    glPushMatrix();
    glTranslatef(0.0f,positionM,0.0f);

    int s;
    GLfloat p=-0.85f;
    GLfloat q= 0.1f;
    GLfloat r= 0.07f;
    int triangle=50;
    GLfloat tp=2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f (p,q);
    for(s= 0;s<=triangle; s++)
    {
        glVertex2f (
                    p+(r*cos(s*tp/triangle)),
                    q+(r*sin(s*tp/triangle))
                    );
    }
    glEnd ();
    glPopMatrix();
}

void Road(){
    glBegin(GL_QUADS);
       glColor3ub(0, 0, 0);
       glVertex2f(-1.0f, 0.2f);
       glVertex2f(-1.0f,  0.0f);
       glVertex2f(1.0f,  0.0f);
       glVertex2f(1.0f,  0.2f);

       glColor3ub(112, 128, 144);
       glVertex2f(-1.0f, 0.01f);
       glVertex2f(-1.0f,  0.0f);
       glVertex2f(1.0f,  0.0f);
       glVertex2f(1.0f,  0.01f);
       glEnd();
}

void River(){
    glBegin(GL_QUADS);
       glColor3ub(100, 149, 237);
       glVertex2f(-1.0f, 0.0f);
       glVertex2f(-1.0f,  -1.0f);
       glVertex2f(1.0f,  -1.0f);
       glVertex2f(1.0f,  0.0f);
       glEnd();
}

    ///************************************************Terminal_Shade
void Terminal_Shade(){
    ///Shade
    glBegin(GL_QUADS);
       glColor3ub(210, 105, 30);
       glVertex2f(-0.9f, 0.03f);
       glVertex2f(-0.75f, 0.1f);
       glVertex2f(0.9f, 0.1f);
       glVertex2f(0.75f, 0.03f);
       glEnd();
    ///Shade_Stand
       glLineWidth(5);
       glBegin(GL_LINES);
       glColor3ub(255, 255, 255);
       glVertex2f(-0.85f, 0.04f);
       glVertex2f(-0.85f, -0.07f);

       glVertex2f(0.76f, 0.04f);
       glVertex2f(0.76f, -0.07f);

       glVertex2f(-0.74f, 0.1f);
       glVertex2f(-0.74f, -0.17f);

       glVertex2f(0.88f, 0.1f);
       glVertex2f(0.88f, -0.17f);
       glEnd();
}

    ///************************************************Terminal
void Terminal(){
       glBegin(GL_POLYGON);
       glColor3ub(139,126, 102);
       glVertex2f(-1.0f, -0.05f);
       glVertex2f(-1.0f,  -0.3f);
       glVertex2f(1.0f,  -0.3f);
       glVertex2f(1.0f,  -0.05f);
       glEnd();

       glBegin(GL_QUADS);
       glColor3ub(139, 87, 66);
       glVertex2f(-1.0f, -0.3f);
       glVertex2f(-1.0f,  -0.31f);
       glVertex2f(1.0f,  -0.31f);
       glVertex2f(1.0f,  -0.3f);
       glEnd();
}

    ///*************************************************Clouds
void Cloud1(){
    glPushMatrix();
    glTranslatef(positionC1,0.0f,0.0f);

    int i;
    GLfloat p1=-0.65f;
    GLfloat q1= 0.9f;
    GLfloat r1 = 0.06f;
    int triangle1=50;
    GLfloat tp1 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p1,q1);
    for(i= 0;i<=triangle1; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp1/triangle1)),
                    q1+(r1*sin(i*tp1/triangle1))
                    );
    }
    glEnd ();

    GLfloat p2=-0.55f;
    GLfloat q2= 0.9f;
    GLfloat r2 = 0.06f;
    int triangle2=50;
    GLfloat tp2 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p2,q2);
    for(i= 0;i<=triangle2; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp2/triangle2)),
                    q2+(r2*sin(i*tp2/triangle2))
                    );
    }
    glEnd ();

    GLfloat p3=-0.65f;
    GLfloat q3= 0.8f;
    GLfloat r3 = 0.06f;
    int triangle3=50;

    GLfloat tp3 =2.0f * PI;
    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p3,q3);
    for(i= 0;i<=triangle3; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp3/triangle3)),
                    q3+(r3*sin(i*tp3/triangle3))
                    );
    }
    glEnd ();

    GLfloat p4=-0.55f;
    GLfloat q4= 0.8f;
    GLfloat r4 = 0.06f;
    int triangle4=50;
    GLfloat tp4 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p4,q4);
    for(i= 0;i<=triangle4; i++)
    {
        glVertex2f (
                    p4+(r4*cos(i*tp4/triangle4)),
                    q4+(r4*sin(i*tp4/triangle4))
                    );
    }
    glEnd ();

    GLfloat p5=-0.71f;
    GLfloat q5= 0.85f;
    GLfloat r5 = 0.06f;
    int triangle5=50;
    GLfloat tp5 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p5,q5);
    for(i= 0;i<=triangle5; i++)
    {
        glVertex2f (
                    p5+(r5*cos(i*tp5/triangle5)),
                    q5+(r5*sin(i*tp5/triangle5))
                    );
    }
    glEnd ();

    GLfloat p6=-0.49f;
    GLfloat q6= 0.85f;
    GLfloat r6 = 0.06f;
    int triangle6=50;
    GLfloat tp6 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p6,q6);
    for(i= 0;i<=triangle6; i++)
    {
        glVertex2f (
                    p6+(r6*cos(i*tp6/triangle6)),
                    q6+(r6*sin(i*tp6/triangle6))
                    );
    }
    glEnd ();

    GLfloat p7=-0.6f;
    GLfloat q7= 0.85f;
    GLfloat r7 = 0.06f;
    int triangle7=50;
    GLfloat tp7 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p7,q7);
    for(i= 0;i<=triangle7; i++)
    {
        glVertex2f (
                    p7+(r7*cos(i*tp7/triangle7)),
                    q7+(r7*sin(i*tp7/triangle7))
                    );
    }
    glEnd ();
    glPopMatrix();
}

void Cloud2(){
    glPushMatrix();
    glTranslatef(positionC2,0.0f,0.0f);

    int i;
    GLfloat p1=0.25;
    GLfloat q1= 0.75;
    GLfloat r1 = 0.06f;
    int triangle1=50;
    GLfloat tp1 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p1,q1);
    for(i= 0;i<=triangle1; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp1/triangle1)),
                    q1+(r1*sin(i*tp1/triangle1))
                    );
    }
    glEnd ();

    GLfloat p2=0.35;
    GLfloat q2= 0.78f;
    GLfloat r2 = 0.06f;
    int triangle2=50;
    GLfloat tp2 =2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p2,q2);
    for(i= 0;i<=triangle2; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp2/triangle2)),
                    q2+(r2*sin(i*tp2/triangle2))
                    );
    }
    glEnd ();

    GLfloat p3=0.43f;
    GLfloat q3= 0.75;
    GLfloat r3 = 0.06;
    int triangle3=50;

    GLfloat tp3 =2.0f * PI;
    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p3,q3);
    for(i= 0;i<=triangle3; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp3/triangle3)),
                    q3+(r3*sin(i*tp3/triangle3))
                    );
    }
    glEnd ();

    GLfloat p4=0.32;
    GLfloat q4= 0.7;
    GLfloat r4 = 0.06;
    int triangle4=50;
    GLfloat tp4 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p4,q4);
    for(i= 0;i<=triangle4; i++)
    {
        glVertex2f (
                    p4+(r4*cos(i*tp4/triangle4)),
                    q4+(r4*sin(i*tp4/triangle4))
                    );
    }
    glEnd ();

    GLfloat p5=0.4;
    GLfloat q5= 0.68;
    GLfloat r5 = 0.05f;
    int triangle5=50;
    GLfloat tp5 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p5,q5);
    for(i= 0;i<=triangle5; i++)
    {
        glVertex2f (
                    p5+(r5*cos(i*tp5/triangle5)),
                    q5+(r5*sin(i*tp5/triangle5))
                    );
    }
    glEnd ();
    glPopMatrix();
}

void Cloud3(){
    glPushMatrix();
    glTranslatef(positionC3,0.0f,0.0f);

    int i;
    GLfloat p1=-0.2f;
    GLfloat q1= 0.65f;
    GLfloat r1 = 0.04f;
    int triangle1=50;
    GLfloat tp1 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p1,q1);
    for(i= 0;i<=triangle1; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp1/triangle1)),
                    q1+(r1*sin(i*tp1/triangle1))
                    );
    }
    glEnd ();

    GLfloat p2=-0.12f;
    GLfloat q2= 0.68f;
    GLfloat r2 = 0.05f;
    int triangle2=50;
    GLfloat tp2 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p2,q2);
    for(i= 0;i<=triangle2; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp2/triangle2)),
                    q2+(r2*sin(i*tp2/triangle2))
                    );
    }
    glEnd ();

    GLfloat p3=-0.07f;
    GLfloat q3= 0.64f;
    GLfloat r3 = 0.06f;
    int triangle3=50;

    GLfloat tp3 =2.0f * PI;
    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p3,q3);
    for(i= 0;i<=triangle3; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp3/triangle3)),
                    q3+(r3*sin(i*tp3/triangle3))
                    );
    }
    glEnd ();

    GLfloat p4=-0.14f;
    GLfloat q4= 0.62f;
    GLfloat r4 = 0.05f;
    int triangle4=50;
    GLfloat tp4 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f (p4,q4);
    for(i= 0;i<=triangle4; i++)
    {
        glVertex2f (
                    p4+(r4*cos(i*tp4/triangle4)),
                    q4+(r4*sin(i*tp4/triangle4))
                    );
    }
    glEnd ();
    glPopMatrix();
}


        ///**************************************City_View
void CityView(){
        ///Left Building 1
       glBegin(GL_QUADS);
       glColor3ub(255, 127, 36);
       glVertex2f(-1.0f, 0.6f);
       glVertex2f(-1.0f, 0.1f);
       glVertex2f(-0.96f, 0.1f);
       glVertex2f(-0.96f, 0.61f);

       glColor3ub(255, 127, 36);
       glVertex2f(-0.96f, 0.61f);
       glVertex2f(-0.96f, 0.1f);
       glVertex2f(-0.85f, 0.1f);
       glVertex2f(-0.85f, 0.6f);
       glEnd();

       glLineWidth(5);
       glBegin(GL_LINES);
       glColor3ub(178, 34, 34);
       glVertex2f(-1.0f, 0.6f);
       glVertex2f(-1.0f, 0.1f);

       glVertex2f(-0.96f, 0.1f);
       glVertex2f(-0.96f, 0.61f);

       glVertex2f(-0.85f, 0.1f);
       glVertex2f(-0.85f, 0.6f);

       glVertex2f(-1.0f, 0.6f);
       glVertex2f(-0.96f, 0.61f);

       glVertex2f(-0.96f, 0.61f);
       glVertex2f(-0.85f, 0.6f);
       glEnd();

       ///Left Building 2
       glBegin(GL_QUADS);
       glColor3ub(54, 100, 139);
       glVertex2f(-0.849f, 0.4f);
       glVertex2f(-0.849f, 0.1f);
       glVertex2f(-0.78f, 0.1f);
       glVertex2f(-0.78f, 0.4f);

       ///Left Building 3
       glColor3ub(79, 148, 205);
       glVertex2f(-0.78, 0.5f);
       glVertex2f(-0.78f, 0.1f);
       glVertex2f(-0.72f, 0.1f);
       glVertex2f(-0.72f, 0.5f);

       ///Left Building 4
       glColor3ub(131, 111, 255);
       glVertex2f(-0.72f, 0.73f);
       glVertex2f(-0.72f, 0.1f);
       glVertex2f(-0.65f, 0.1f);
       glVertex2f(-0.65f, 0.74f);

       glVertex2f(-0.65f, 0.74f);
       glVertex2f(-0.65f, 0.1f);
       glVertex2f(-0.53f, 0.1f);
       glVertex2f(-0.53f, 0.73f);
       glEnd();

       glLineWidth(5);
       glBegin(GL_LINES);
       glColor3ub(235, 235, 235);
       glVertex2f(-0.72f, 0.73f);
       glVertex2f(-0.72f, 0.1f);

       glVertex2f(-0.65f, 0.74f);
       glVertex2f(-0.65f, 0.1f);

       glVertex2f(-0.53f, 0.73f);
       glVertex2f(-0.53f, 0.1f);

       glVertex2f(-0.72f, 0.73f);
       glVertex2f(-0.65f, 0.74f);

       glVertex2f(-0.65f, 0.74f);
       glVertex2f(-0.53f, 0.73f);
       glEnd();

       ///Left Building 5
       glBegin(GL_QUADS);
       glColor3ub(255, 255, 224);
       glVertex2f(-0.529f, 0.55f);
       glVertex2f(-0.529f, 0.1f);
       glVertex2f(-0.5f, 0.1f);
       glVertex2f(-0.5, 0.56f);

       glVertex2f(-0.5f, 0.56f);
       glVertex2f(-0.5f, 0.1f);
       glVertex2f(-0.47f, 0.1f);
       glVertex2f(-0.47f, 0.55f);
       glEnd();

       glLineWidth(4);
       glBegin(GL_LINES);
       glColor3ub(218, 165, 32);
       glVertex2f(-0.529f, 0.55f);
       glVertex2f(-0.529f, 0.1f);

       glVertex2f(-0.5f, 0.56f);
       glVertex2f(-0.5f, 0.1f);

       glVertex2f(-0.47f, 0.55f);
       glVertex2f(-0.47f, 0.1f);

       glVertex2f(-0.529f, 0.55f);
       glVertex2f(-0.5f, 0.56f);

       glVertex2f(-0.5f, 0.56f);
       glVertex2f(-0.47f, 0.55f);
       glEnd();

       ///Tower
       glBegin(GL_QUADS);
       glColor3ub(47, 79, 79);
       glVertex2f(-0.469f, 0.75f);
       glVertex2f(-0.469f, 0.1f);
       glVertex2f(-0.44f, 0.1f);
       glVertex2f(-0.44f, 0.75f);

       glVertex2f(-0.461f, 0.765f);
       glVertex2f(-0.461f, 0.75f);
       glVertex2f(-0.447f, 0.75f);
       glVertex2f(-0.447f, 0.765f);

       glVertex2f(-0.466f, 0.8f);
       glVertex2f(-0.466f, 0.765f);
       glVertex2f(-0.443f, 0.765f);
       glVertex2f(-0.443f, 0.8f);

       glVertex2f(-0.461f, 0.815f);
       glVertex2f(-0.461f, 0.8f);
       glVertex2f(-0.448f, 0.8f);
       glVertex2f(-0.448f, 0.815f);
       glEnd();

       ///Tower Stand
       glLineWidth(4);
       glBegin(GL_LINES);
       glColor3ub(218, 165, 32);
       glVertex2f(-0.461, 0.85f);
       glVertex2f(-0.461f, 0.81f);

       glVertex2f(-0.448, 0.85f);
       glVertex2f(-0.448, 0.81f);

       glVertex2f(-0.461f, 0.85f);
       glVertex2f(-0.448f, 0.85f);
       glEnd();

       ///Left Building 6
       glBegin(GL_QUADS);
       glColor3ub(255, 255, 224);
       glVertex2f(-0.439f, 0.45f);
       glVertex2f(-0.439f, 0.1f);
       glVertex2f(-0.38f, 0.1f);
       glVertex2f(-0.38f, 0.46f);

       glVertex2f(-0.38f, 0.46f);
       glVertex2f(-0.38f, 0.1f);
       glVertex2f(-0.25f, 0.1f);
       glVertex2f(-0.25f, 0.45f);
       glEnd();

       glLineWidth(5);
       glBegin(GL_LINES);
       glColor3ub(218, 165, 32);
       glVertex2f(-0.439f, 0.45f);
       glVertex2f(-0.439f, 0.1f);

       glVertex2f(-0.38, 0.46f);
       glVertex2f(-0.38f, 0.1f);

       glVertex2f(-0.25f, 0.45f);
       glVertex2f(-0.25f, 0.1f);

       glVertex2f(-0.439f, 0.45f);
       glVertex2f(-0.38f, 0.46f);

       glVertex2f(-0.38f, 0.46f);
       glVertex2f(-0.25f, 0.45f);
       glEnd();

       ///Left Building 7
       glBegin(GL_QUADS);
       glColor3ub(69, 139, 116);
       glVertex2f(-0.247f, 0.5f);
       glVertex2f(-0.247f, 0.1f);
       glVertex2f(-0.2f, 0.1f);
       glVertex2f(-0.2f, 0.51);

       glColor3ub(82, 139, 139);
       glVertex2f(-0.2f, 0.51f);
       glVertex2f(-0.2f, 0.1f);
       glVertex2f(-0.1f, 0.1f);
       glVertex2f(-0.1f, 0.5f);
       glEnd();

       glLineWidth(5);
       glBegin(GL_LINES);
       glColor3ub(240, 255, 255);
       glVertex2f(-0.247f, 0.5f);
       glVertex2f(-0.247f, 0.1f);

       glVertex2f(-0.2f, 0.51f);
       glVertex2f(-0.2f, 0.1f);

       glVertex2f(-0.1f, 0.51f);
       glVertex2f(-0.1f, 0.1f);

       glVertex2f(-0.247f, 0.5f);
       glVertex2f(-0.2f, 0.51f);

       glVertex2f(-0.2f, 0.51f);
       glVertex2f(-0.1f, 0.5f);
       glEnd();

       ///Left Building 8
       glBegin(GL_QUADS);
       glColor3ub(165, 42, 42);
       glVertex2f(-0.05f, 0.4f);
       glVertex2f(-0.05f, 0.1f);
       glVertex2f(0.1f, 0.1f);
       glVertex2f(0.1f, 0.41);

       glColor3ub(238, 59, 59);
       glVertex2f(0.1f, 0.41f);
       glVertex2f(0.1f, 0.1f);
       glVertex2f(0.5f, 0.1f);
       glVertex2f(0.5f, 0.4f);
       glEnd();

       ///Left Building 9
       glBegin(GL_QUADS);
       glColor3ub(54, 100, 139);
       glVertex2f(0.55f, 0.5f);
       glVertex2f(0.55f, 0.1f);
       glVertex2f(0.6f, 0.1f);
       glVertex2f(0.6f, 0.5f);

       ///Left Building 10
       glColor3ub(79, 148, 205);
       glVertex2f(0.6f, 0.6f);
       glVertex2f(0.6f, 0.1f);
       glVertex2f(0.7f, 0.1f);
       glVertex2f(0.7f, 0.6f);
}

        ///*******************************************Boat
void Boat(){
    glPushMatrix();
    glTranslatef(positionB,0.0f,0.0f);

    ///Deck
       glBegin(GL_QUADS);
       glColor3ub(93, 71, 139);
       glVertex2f(0.4f, -0.4);
       glVertex2f(0.45,  -0.45f);
       glVertex2f(0.58f,  -0.45f);
       glVertex2f(0.65f,  -0.4f);
       glEnd();

    ///Pal_1
       glBegin(GL_TRIANGLES);
       glColor3ub(205, 0, 205);
       glVertex2f(0.43f, -0.39);
       glVertex2f(0.5f,  -0.39f);
       glVertex2f(0.5f,  -0.27);
       glEnd();

    ///Pal_2
       glBegin(GL_TRIANGLES);
       glColor3ub(162, 205, 90);
       glVertex2f(0.5, -0.2);
       glVertex2f(0.5f,  -0.39f);
       glVertex2f(0.57f,  -0.39f);
       glEnd();
    ///Stand
       glLineWidth(3);
       glBegin(GL_LINES);
       glColor3ub(0, 0, 0);
       glVertex2f(0.5, -0.4);
       glVertex2f(0.5f, -0.2f);
       glEnd();

    glPopMatrix();
}

        ///*******************************************Steamer
void Steamer(){
    glPushMatrix();
    glTranslatef(positionSt,0.0f,0.0f);

    ///Deck
    glBegin(GL_QUADS);
       glColor3ub(47, 79, 79);
       glVertex2f(0.2f, -0.75f);
       glVertex2f(0.3f,  -0.83f);
       glVertex2f(0.55f,  -0.83f);
       glVertex2f(0.6f,  -0.75f);
       glEnd();

        ///Tank1
    glBegin(GL_QUADS);
       glColor3ub(218, 165, 32);
       glVertex2f(0.25f, -0.65f);
       glVertex2f(0.25f,  -0.75f);
       glVertex2f(0.55f,  -0.75f);
       glVertex2f(0.55f,  -0.65f);
       glEnd();

       for (float i = 0.25f; i<= 0.55f; i+= 0.03f)
       {
           glLineWidth(2);
           glBegin(GL_LINES); ///Vertical Lines
           glColor3ub(139, 126, 102);
           glVertex2f(i, -0.65f);
           glVertex2f(i, -0.75f);
           glEnd();
       }

       ///Tank2
    glBegin(GL_QUADS);
       glColor3ub(238, 99, 99);
       glVertex2f(0.3f, -0.57f);
       glVertex2f(0.3f,  -0.65f);
       glVertex2f(0.5f,  -0.65f);
       glVertex2f(0.5f,  -0.57f);
       glEnd();

       for (float i = 0.3f; i<= 0.5f; i+= 0.03f)
       {
           glLineWidth(2);
           glBegin(GL_LINES); ///Vertical Lines
           glColor3ub(139, 126, 102);
           glVertex2f(i, -0.57f);
           glVertex2f(i, -0.65f);
           glEnd();
       }

    glPopMatrix();
}

        ///***********************************Launch
void Launch1(){
     ///DeckL3
    glBegin(GL_QUADS);
       glColor3ub(18, 18, 18);
       glVertex2f(-0.9f, -0.3f);
       glVertex2f(-0.89f, -0.375);
       glVertex2f(-0.65f, -0.375);
       glVertex2f(-0.55f, -0.3);
       glEnd();

    ///Deck BorderL2
    glBegin(GL_QUADS);
       glColor3ub(127, 255, 212);
       glVertex2f(-0.9f, -0.29f);
       glVertex2f(-0.9f, -0.3f);
       glVertex2f(-0.55f, -0.3f);
       glVertex2f(-0.55f, -0.29f);
       glEnd();

       ///DeckL2
    glBegin(GL_QUADS);
       glColor3ub(255, 48, 48);
       glVertex2f(-0.88f, -0.22f);
       glVertex2f(-0.88f, -0.29f);
       glVertex2f(-0.6f, -0.29f);
       glVertex2f(-0.65f, -0.22f);
       glEnd();

       ///Windows
       glBegin(GL_QUADS);
       glColor3ub(255, 255, 255);
       glVertex2f(-0.87f, -0.23f);
       glVertex2f(-0.87f, -0.28f);
       glVertex2f(-0.835f, -0.28f);
       glVertex2f(-0.835f, -0.23f);

       glVertex2f(-0.79f, -0.23f);
       glVertex2f(-0.79f, -0.28f);
       glVertex2f(-0.755f, -0.28f);
       glVertex2f(-0.755f, -0.23f);

       glVertex2f(-0.71f, -0.23f);
       glVertex2f(-0.71f, -0.28f);
       glVertex2f(-0.675f, -0.28f);
       glVertex2f(-0.675f, -0.23f);
       glEnd();

       ///Deck BorderL1
    glBegin(GL_QUADS);
       glColor3ub(127, 255, 212);
       glVertex2f(-0.88f, -0.21f);
       glVertex2f(-0.88f, -0.22f);
       glVertex2f(-0.65f, -0.22f);
       glVertex2f(-0.65f, -0.21f);
       glEnd();

       ///DeckL1
    glBegin(GL_QUADS);
       glColor3ub(255, 127, 0);
       glVertex2f(-0.86f, -0.15f);
       glVertex2f(-0.86f, -0.21f);
       glVertex2f(-0.675f, -0.21f);
       glVertex2f(-0.725f, -0.15f);
       glEnd();

    ///Air Pipe 1
    glBegin(GL_QUADS);
       glColor3ub(139, 28, 98);
       glVertex2f(-0.84f, -0.08f);
       glVertex2f(-0.84f, -0.15f);
       glVertex2f(-0.82f, -0.15f);
       glVertex2f(-0.82f, -0.08f);
       glEnd();

       ///Air Pipe 2
    glBegin(GL_QUADS);
       glColor3ub(139, 28, 98);
       glVertex2f(-0.78f, -0.08f);
       glVertex2f(-0.78f, -0.15f);
       glVertex2f(-0.76f, -0.15f);
       glVertex2f(-0.76f, -0.08f);
       glEnd();

       ///Control Room
    glBegin(GL_QUADS);
       glColor3ub(247, 247, 247);
       glVertex2f(-0.855f, -0.16f);
       glVertex2f(-0.855f, -0.2f);
       glVertex2f(-0.69f, -0.2f);
       glVertex2f(-0.73f, -0.16f);
       glEnd();

       ///Window1
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.85f, -0.17);
       glVertex2f(-0.85f, -0.19f);
       glVertex2f(-0.81f, -0.19f);
       glVertex2f(-0.81f, -0.17f);
       glEnd();

       ///Window2
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.80f, -0.17);
       glVertex2f(-0.80f, -0.19f);
       glVertex2f(-0.76f, -0.19f);
       glVertex2f(-0.76f, -0.17f);
       glEnd();

       ///Window3
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.75f, -0.17f);
       glVertex2f(-0.75f, -0.19f);
       glVertex2f(-0.71f, -0.19f);
       glVertex2f(-0.725f, -0.17f);
       glEnd();
}

void Launch2(){
    glPushMatrix();
    glTranslatef(positionL2,0.0f,0.0f);

    ///DeckL3
    glBegin(GL_QUADS);
       glColor3ub(46, 139, 87);
       glVertex2f(-0.2f, -0.5);
       glVertex2f(-0.185f, -0.575);
       glVertex2f(0.1f, -0.575);
       glVertex2f(0.2f, -0.5);
       glEnd();

    ///Deck BorderL2
    glBegin(GL_QUADS);
       glColor3ub(255, 130, 71);
       glVertex2f(-0.2f, -0.5f);
       glVertex2f(-0.2f, -0.495f);
       glVertex2f(0.2f, -0.495f);
       glVertex2f(0.2f, -0.5f);
       glEnd();

       ///DeckL2
    glBegin(GL_QUADS);
       glColor3ub(0, 0, 139);
       glVertex2f(-0.175f, -0.42f);
       glVertex2f(-0.175f, -0.495f);
       glVertex2f(0.125f, -0.495f);
       glVertex2f(0.075f, -0.42f);
       glEnd();

       ///Windows
       glBegin(GL_QUADS);
       glColor3ub(255, 255, 255);
       glVertex2f(-0.15f, -0.435f);
       glVertex2f(-0.15f, -0.48f);
       glVertex2f(-0.12f, -0.48f);
       glVertex2f(-0.12f, -0.435f);

       glVertex2f(-0.07f, -0.435f);
       glVertex2f(-0.07f, -0.48f);
       glVertex2f(-0.04f, -0.48f);
       glVertex2f(-0.04f, -0.435f);

       glVertex2f(0.05f, -0.435f);
       glVertex2f(0.05f, -0.48f);
       glVertex2f(0.02f, -0.48f);
       glVertex2f(0.02f, -0.435f);
       glEnd();

       ///Deck BorderL1
    glBegin(GL_QUADS);
       glColor3ub(255, 130, 71);
       glVertex2f(-0.175f, -0.415f);
       glVertex2f(-0.175f, -0.42f);
       glVertex2f(0.075f, -0.42f);
       glVertex2f(0.075f, -0.415f);
       glEnd();

       ///DeckL1
    glBegin(GL_QUADS);
       glColor3ub(0, 197, 205);
       glVertex2f(-0.16f, -0.35f);
       glVertex2f(-0.16f, -0.415f);
       glVertex2f(0.05f, -0.415f);
       glVertex2f(0.0f, -0.35f);
       glEnd();

    ///Air Pipe 1
    glBegin(GL_QUADS);
       glColor3ub(139, 76, 57);
       glVertex2f(-0.13f, -0.275f);
       glVertex2f(-0.13f, -0.35f);
       glVertex2f(-0.11f, -0.35f);
       glVertex2f(-0.11f, -0.275);
       glEnd();

       ///Air Pipe 2
    glBegin(GL_QUADS);
       glColor3ub(139, 76, 57);
       glVertex2f(-0.07f, -0.275f);
       glVertex2f(-0.07f, -0.35f);
       glVertex2f(-0.05f, -0.35f);
       glVertex2f(-0.05f, -0.275f);
       glEnd();

       ///Control Room
    glBegin(GL_QUADS);
       glColor3ub(247, 247, 247);
       glVertex2f(-0.155f, -0.36f);
       glVertex2f(-0.155f, -0.405f);
       glVertex2f(0.03f, -0.405f);
       glVertex2f(0.0f, -0.36f);
       glEnd();

       ///Window1
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.15f, -0.37);
       glVertex2f(-0.15f, -0.4f);
       glVertex2f(-0.1f, -0.4f);
       glVertex2f(-0.1f, -0.37f);
       glEnd();

       ///Window2
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.09f, -0.37);
       glVertex2f(-0.09f, -0.4f);
       glVertex2f(-0.04f, -0.4f);
       glVertex2f(-0.04f, -0.37f);
       glEnd();

       ///Window3
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.03f, -0.37f);
       glVertex2f(-0.03f, -0.4f);
       glVertex2f(0.01f, -0.4f);
       glVertex2f(0.0f, -0.37f);
       glEnd();

    glPopMatrix();
}

void Launch3(){
    glPushMatrix();
    glTranslatef(positionL3,0.0f,0.0f);

    ///DeckL3
    glBegin(GL_QUADS);
       glColor3ub(18, 18, 18);
       glVertex2f(-0.6f, -0.8);
       glVertex2f(-0.58f, -0.9f);
       glVertex2f(-0.225f, -0.9f);
       glVertex2f(-0.1f, -0.8f);
       glEnd();

    ///Deck BorderL2
    glBegin(GL_QUADS);
       glColor3ub(205, 38, 38);
       glVertex2f(-0.6f, -0.8f);
       glVertex2f(-0.6f, -0.79f);
       glVertex2f(-0.1f, -0.79f);
       glVertex2f(-0.1f, -0.8f);
       glEnd();

       ///DeckL2
    glBegin(GL_QUADS);
       glColor3ub(0, 134, 139);
       glVertex2f(-0.57f, -0.7f);
       glVertex2f(-0.57f, -0.79f);
       glVertex2f(-0.2f, -0.79f);
       glVertex2f(-0.25f, -0.7f);
       glEnd();

       ///Windows
       glBegin(GL_QUADS);
       glColor3ub(255, 255, 255);
       glVertex2f(-0.52f, -0.715f);
       glVertex2f(-0.52f, -0.775f);
       glVertex2f(-0.48f, -0.775f);
       glVertex2f(-0.48f, -0.715f);

       glVertex2f(-0.42f, -0.715f);
       glVertex2f(-0.42f, -0.775f);
       glVertex2f(-0.38f, -0.775f);
       glVertex2f(-0.38f, -0.715f);

       glVertex2f(-0.32f, -0.715f);
       glVertex2f(-0.32f, -0.775f);
       glVertex2f(-0.28f, -0.775f);
       glVertex2f(-0.28f, -0.715f);
       glEnd();

       ///Deck BorderL1
    glBegin(GL_QUADS);
       glColor3ub(205, 38, 38);
       glVertex2f(-0.57f, -0.69f);
       glVertex2f(-0.57f, -0.7f);
       glVertex2f(-0.25f, -0.7f);
       glVertex2f(-0.25f, -0.69f);
       glEnd();

       ///DeckL1
    glBegin(GL_QUADS);
       glColor3ub(25, 25, 112);
       glVertex2f(-0.54, -0.6f);
       glVertex2f(-0.54f, -0.69f);
       glVertex2f(-0.3f, -0.69f);
       glVertex2f(-0.35f, -0.6f);
       glEnd();

    ///Air Pipe 1
    glBegin(GL_QUADS);
       glColor3ub(139, 102, 139);
       glVertex2f(-0.5f, -0.5f);
       glVertex2f(-0.5f, -0.6f);
       glVertex2f(-0.475f, -0.6f);
       glVertex2f(-0.475f, -0.5f);
       glEnd();

       ///Air Pipe 2
    glBegin(GL_QUADS);
       glColor3ub(139, 102, 139);
       glVertex2f(-0.425f, -0.5f);
       glVertex2f(-0.425f, -0.6f);
       glVertex2f(-0.4f, -0.6f);
       glVertex2f(-0.4f, -0.5f);
       glEnd();

       ///Control Room
    glBegin(GL_QUADS);
       glColor3ub(247, 247, 247);
       glVertex2f(-0.535f, -0.61f);
       glVertex2f(-0.535f, -0.68f);
       glVertex2f(-0.31f, -0.68f);
       glVertex2f(-0.35f, -0.61f);
       glEnd();

       ///Window1
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.525f, -0.62f);
       glVertex2f(-0.525f, -0.67f);
       glVertex2f(-0.47f, -0.67f);
       glVertex2f(-0.47f, -0.62f);
       glEnd();

       ///Window2
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.46f, -0.62f);
       glVertex2f(-0.46f, -0.67f);
       glVertex2f(-0.4f, -0.67f);
       glVertex2f(-0.4f, -0.62f);
       glEnd();

       ///Window3
       glBegin(GL_QUADS);
       glColor3ub(207, 207, 207);
       glVertex2f(-0.39f, -0.62f);
       glVertex2f(-0.39f, -0.67f);
       glVertex2f(-0.32f, -0.67f);
       glVertex2f(-0.35f, -0.62f);
       glEnd();

    glPopMatrix();
}

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    Day(1);
    if(positionS < -0.7f)
                {
                    Night(1);
                }
    Sun();
    Moon();
    Cloud1();
    Cloud2();
    Cloud3();
    CityView();
    Road();
    River();
    Terminal();
    Terminal_Shade();
    Launch1();
    Boat();
    Launch2();
    Steamer();
    Launch3();
    glutSwapBuffers();
}

void handleMouse(int button, int state, int x, int y) {
if (button == GLUT_LEFT_BUTTON)
{    speedC1 = 0.01f;
    speedC2 = 0.015f;
    speedC3 = 0.02f;
}
if (button == GLUT_RIGHT_BUTTON)
{   speedC1 = 0.0f;
    speedC2 = 0.0f;
    speedC3 = 0.0f;
}
glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key){
    case 'a':
        speedB = 0.01f;
        speedSt = 0.025f;
        speedL2 = 0.04f;
        speedL3 = 0.05f;
        break;
    case 's':
        speedB = 0.0f;
        speedSt = 0.0f;
        speedL2 = 0.0f;
        speedL3 = 0.0f;
        break;
    case 'n':
        speedS = 0.01f;
        break;
glutPostRedisplay();
}
}

void myInit(void)
{
    glClearColor(255, 255, 255, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize (1200, 680);
    glutInitWindowPosition (200, 100);
    glutCreateWindow ("Smart Launch Terminal");
    myInit();
    glutDisplayFunc(myDisplay);
    glutTimerFunc(100, update, 0);
    glutTimerFunc(100, updateSun, 0);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutMainLoop();
}
