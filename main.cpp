#include <iostream>
#include <stdlib.h>

#include <GL/glut.h>

using namespace std;

GLfloat xRotate = -1.0;
GLfloat yRotate = 152.0;
GLfloat zRotate = 0.0;

GLfloat xScale = 1.0f;
GLfloat yScale = 1.0f;
GLfloat zScale = 1.0f;

GLfloat xTranslate = 0.0f;
GLfloat yTranslate = 0.0f;
GLfloat zTranslate = -2.0f;

void drawShape(void);

void idle(void)
{
    drawShape();
}

void keyPressHandler(unsigned char key, int x, int y) {
    if (key <= 'Z' && key >= 'A')
        key -= ('Z' - 'z');

    switch(key)
    {
        case 'w':
            xRotate -= 1.0;
            break;
        case 's':
            xRotate += 1.0;
            break;
        case 'a':
            yRotate -= 1.0;
            break;
        case 'd':
            yRotate += 1.0;
            break;
        case 'q':
            zRotate += 1.0;
            break;
        case 'z':
            zRotate -= 1.0;
            break;

        case 'c':
            xScale += 0.1;
            yScale += 0.1;
            zScale += 0.1;
            break;
        case 'v':
            xScale -= 0.1;
            yScale -= 0.1;
            zScale -= 0.1;
            break;

        case 'u':
            yTranslate += 0.1;
            break;
        case 'j':
            yTranslate -= 0.1;
            break;
        case 'h':
            xTranslate -= 0.1;
            break;
        case 'k':
            xTranslate += 0.1;
            break;
        case 'y':
            zTranslate += 0.1;
            break;
        case 'g':
            zTranslate -= 0.1;
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

void initRendering() {
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

    GLfloat shininess[] = {50.0};
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    GLfloat ambient[] = {0.1, 0.1, 0.1, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void handleResize(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(40.0, (double) width / (double) height, 0.9, 90.0);
}

void drawShape() {
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

    glTranslatef(-1.0f, -1.5f, -2.0f);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(1.0f, 1.0f, 0.0f);
    glColor3f(1.0, 0.25, 1.0);
    glColor3f (.5, 0.5, .25);

    glTranslatef(xTranslate, yTranslate, zTranslate);
    glRotatef(xRotate, 1.0f, 0.0f, 0.0f);
    glRotatef(yRotate, 0.0f, 1.0f, 0.0f);
    glRotatef(zRotate, 0.0f, 0.0f, 1.0f);
    
    glScalef(xScale, yScale, zScale);

    //alt kisim
    glBegin(GL_POLYGON);
    glColor3f (0.85, 0.57, 0.44);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f (0.91, 0.11, 0.01);
    glVertex3f (0.91, 0.11, 0.51);
    glVertex3f (0.21, 0.11, 0.51);
    glVertex3f (0.21, 0.11, 0.01);
    glEnd();
    
    //kapi
    glBegin(GL_POLYGON);
    glColor3f (0.18, 0.18, 0.4);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f (0.48, 0.47, -0.0011);
    glVertex3f (0.66, 0.47, -0.0011);
    glVertex3f (0.66, 0.131, -0.0011);
    glVertex3f (0.48, 0.131, -0.0011);
    glEnd();

    //pencere
    glBegin(GL_POLYGON);
    glColor3f (0.13, 0.13, 0.55);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f (0.73, 0.41, -0.0011);
    glVertex3f (0.84, 0.41, -0.0011);
    glVertex3f (0.84, 0.26, -0.0011);
    glVertex3f (0.73, 0.26, -0.0011);
    glEnd();

    //pencere
    glBegin(GL_POLYGON);
    glColor3f (0.13, 0.13, 0.55);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f (0.28, 0.41, -0.0011);
    glVertex3f (0.39, 0.41, -0.0011);
    glVertex3f (0.39, 0.26, -0.0011);
    glVertex3f (0.28, 0.26, -0.0011);
    glEnd();

    //bize bakan dortgen
    glBegin(GL_POLYGON);
    glColor3f (0.9, 0.5, 0.0);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f (0.21, 0.569, 0.01);
    glVertex3f (0.91, 0.569, 0.01);
    glVertex3f (0.91, 0.11, 0.01);
    glVertex3f (0.21, 0.11, 0.01);
    glEnd();


    // arkaya bakan dortgen
    glBegin(GL_POLYGON);
    glColor3f (0.9, 0.5, 0.0);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f (0.21, 0.569, 0.51);
    glVertex3f (0.91, 0.569, 0.51);
    glVertex3f (0.91, 0.11, 0.51);
    glVertex3f (0.21, 0.11, 0.51);
    glEnd();

    //sola bakan dortgen
    glBegin(GL_POLYGON);
    glColor3f (0.13, 0.55, 0.41);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f (0.21, 0.569, 0.51);
    glVertex3f (0.21, 0.569, 0.01);
    glVertex3f (0.21, 0.11, 0.01);
    glVertex3f (0.21, 0.11, 0.51);
    glEnd();

    // saga bakan dortgen
    glBegin(GL_POLYGON);
    glColor3f (0.13, 0.55, 0.41);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f (0.91, 0.569, 0.51);
    glVertex3f (0.91, 0.569, 0.01);
    glVertex3f (0.91, 0.11, 0.01);
    glVertex3f (0.91, 0.11, 0.51);
    glEnd();

    // sola bakan ucgen
    glBegin(GL_TRIANGLES);
    glColor3f (0.86, 0.44, 0.86);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f (0.91, 0.81, 0.26);
    glVertex3f (0.91, 0.569, 0.51);
    glVertex3f (0.91, 0.569, 0.01);
    glEnd();

    //saga bakan ucgen
    glBegin(GL_TRIANGLES);
    glColor3f (0.86, 0.44, 0.86);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f (0.21, 0.81, 0.26);
    glVertex3f (0.21, 0.569, 0.51);
    glVertex3f (0.21, 0.569, 0.01);
    glEnd();

    //bize bakan cati
    glBegin(GL_POLYGON);
    glColor3f (0.86, 0.44, 0.86);
    glNormal3f(0.0, -1.0, -1.0);
    glVertex3f (0.21, 0.81, 0.26);
    glVertex3f (0.91, 0.81, 0.26);
    glVertex3f (0.91, 0.569, 0.01);
    glVertex3f (0.21, 0.569, 0.01);
    glEnd();

    // arkaya bakan cati
    glBegin(GL_POLYGON);
    glColor3f (0.86, 0.44, 0.86);
    glNormal3f(0.0, -1.0, 1.0);
    glVertex3f (0.21, 0.81, 0.26);
    glVertex3f (0.91, 0.81, 0.26);
    glVertex3f (0.91, 0.569, 0.51);
    glVertex3f (0.21, 0.569, 0.51);
    glEnd();

    glFlush ();
    glPopMatrix();
    glutSwapBuffers();    
}


int main(int argc, char ** argv) {
    glutInit(& argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1200, 960);
    glutCreateWindow("3D-House");
    initRendering();
    glutDisplayFunc(drawShape);
    glutKeyboardFunc(keyPressHandler);
    glutReshapeFunc(handleResize);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
