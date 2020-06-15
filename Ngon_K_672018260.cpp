#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <cmath>
#define M_PI 3.14


void myInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
}

void ngon(int n, float cx, float cy, float radius, float rotAngle)
{
    double angle, angleInc;
    int k;
    if (n < 3)
        return;
    angle = rotAngle * 3.14159265 / 180;
    angleInc = 2 * 3.14159265 / n;
    glVertex2f(radius* cos(angle) + cx, radius* sin(angle) + cy);
    for(k=0; k<n; k++)
    {
        angle += angleInc;

        glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);
    }
}

void Display(void)
{
    int j;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    for (j = 1; j <= 50; j++)
    {
        glColor3f(0.0 - (j * 0.05), 0.0 + (j * 0.05), 15.0 + (j * 0.5));
        ngon(6, 0.0, 0, 10 - (j * 0.2), j * 3);
    }
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Holbed Joshua Petty - 672018260");
    myInit();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
