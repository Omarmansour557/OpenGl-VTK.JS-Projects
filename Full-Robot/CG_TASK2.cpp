#include <stdlib.h>
#include <GL/glut.h>
#include<math.h>
#define PI 3.14159265358979323846
#define speed 0.2


static int shoulder_rx, shoulder_rz, shoulder_lx, shoulder_lz, elbow_r, elbow_l, hip_rx, hip_rz, hip_lx, hip_lz, knee_l, knee_r;
//static int shoulder = 0, elbow = 0, fingerBase1 = 0, fingerUp1 = 0, fingerBase2 = 0, fingerBase3 = 0, fingerUp2 = 0, fingerUp3 = 0, fingerBase4 = 0, fingerUp4 = 0;
int moving, startx, starty;
double eye[] = {0, 0, 2};
double center[] = {0, 0, 0};
double up[] = {0, 1, 0};

GLfloat angle = 0.0;  /* in degrees */
GLfloat angle2 = 0.0; /* in degrees */

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    gluLookAt(eye[0],
 	 eye[1],
 	 eye[2],
 	 center[0],
 	 center[1],
 	 center[2],
 	 up[0],
 	 up[1],
 	 up[2]);

    // Creating the body part
    glTranslatef(-1.0, 0.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glPushMatrix();
    glPushMatrix();
    glPushMatrix();
    glPushMatrix();
    glScalef(2.0, 4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Creating the right hand upper part(X-axis)
    glTranslatef(1.0, 1.7, 0.0);
    glRotatef((GLfloat)shoulder_rx, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder_rz, 0.0, 0.0, 1.0);
    glTranslatef(1, 0, 0.0);
    glPushMatrix();
    glScalef(1.5, 0.4, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    // Creating the right hand lower part

    glTranslatef(0.9, 0.0, 0);
    glRotatef((GLfloat)elbow_r, 0.0, 0.0, 1.0);
    glTranslatef(0.6, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.5, 0.4, 0.2);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();

    // Creating the left hand upper part

    glTranslatef(-1.0, 1.7, 0.0);
    glRotatef((GLfloat)shoulder_lx, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder_lz, 0.0, 0.0, 1.0);
    glTranslatef(-1, 0, 0.0);
    glPushMatrix();
    glScalef(1.5, 0.4, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    //creating the left hand lower part
    glTranslatef(-0.9, 0.0, 0);
    glRotatef((GLfloat)elbow_l, 0.0, 0.0, 1.0);
    glTranslatef(-0.6, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.5, 0.4, 0.2);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();

    //creating the right leg upper part
    glTranslatef(0.4, -3, 0);
    glRotatef((GLfloat)hip_rz, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)hip_rx, 1.0, 0.0, 0.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.7, 1.7, 0.7);
    glutWireCube(1);
    glPopMatrix();

    //creating the right leg lower part
    glTranslatef(-0.2, -1.7, 0);
    glRotatef((GLfloat)knee_r, 1.0, 0.0, 0.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.7, 1.7, 0.7);
    glutWireCube(1);
    glPopMatrix();

    //creating the right foot
    glTranslatef(-0.35, -1, 0.5);
    glTranslatef(0.35, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.7, 0.5, 1.5);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    //creating the left leg upper part
    glTranslatef(-0.4, -3, 0);
    glRotatef((GLfloat)hip_lz, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)hip_lx, 1.0, 0.0, 0.0);
    glTranslatef(-0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.7, 1.7, 0.7);
    glutWireCube(1);
    glPopMatrix();

    //creating the left leg lower part
    glTranslatef(-0.2, -1.7, 0);
    glRotatef((GLfloat)knee_l, 1.0, 0.0, 0.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.7, 1.7, 0.7);
    glutWireCube(1);
    glPopMatrix();

    //creating the left foot
    glTranslatef(-0.35, -1, 0.5);
    glTranslatef(0.35, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.7, 0.5, 1.5);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    //creating the head

    glTranslatef(0, 4, 0.0);
    glPushMatrix();
    glScalef(1, 1, 1);
    glutWireSphere(1, 50, 50);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void crossProduct(double a[], double b[], double c[])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(double a[])
{
	double norm;
	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void rotatePoint(double a[], double theta, double p[])
{

	double temp[3];
	temp[0] = p[0];
	temp[1] = p[1];
	temp[2] = p[2];

	temp[0] = -a[2] * p[1] + a[1] * p[2];
	temp[1] = a[2] * p[0] - a[0] * p[2];
	temp[2] = -a[1] * p[0] + a[0] * p[1];

	temp[0] *= sin(theta);
	temp[1] *= sin(theta);
	temp[2] *= sin(theta);

	temp[0] += (1 - cos(theta))*(a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
	temp[1] += (1 - cos(theta))*(a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
	temp[2] += (1 - cos(theta))*(a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

	temp[0] += cos(theta)*p[0];
	temp[1] += cos(theta)*p[1];
	temp[2] += cos(theta)*p[2];

	p[0] = temp[0];
	p[1] = temp[1];
	p[2] = temp[2];

}






void lookUp()
{
    double horizontal[3];
    double direction[3];
    direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
    crossProduct(up, direction, horizontal);
    normalize(horizontal);
    rotatePoint(horizontal,PI/8,eye);
    rotatePoint(horizontal,PI/8,up);
    normalize(up); 
}

void lookDown()
{
    double horizontal[3];
    double direction[3];
    direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
    crossProduct(up, direction, horizontal);
    normalize(horizontal);
    rotatePoint(horizontal,-PI/8,eye);
    rotatePoint(horizontal,-PI/8,up);
    normalize(up);
 
}

void moveForward()
{
    double direction[3];
    direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
    eye[0]    += direction[0] * speed;
	eye[1]    += direction[1] * speed;
	eye[2]    += direction[2] * speed;

	center[0] += direction[0] * speed;
	center[1] += direction[1] * speed;
	center[2] += direction[2] * speed;
}
void moveBackward()
{
    double direction[3];
    direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
    eye[0]    -= direction[0] * speed;
	eye[1]    -= direction[1] * speed;
	eye[2]    -= direction[2] * speed;
	center[0] -= direction[0] * speed;
	center[1] -= direction[1] * speed;
	center[2] -= direction[2] * speed;
}
void lookLeft()
{
    rotatePoint(up,PI/8,eye);
}
void lookRight()
{
    rotatePoint(up,-PI/8,eye);
}




void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(130, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        if (shoulder_rx >= 0 && shoulder_rx <= 90)
        {
            shoulder_rx = (shoulder_rx + 5);
        }

        glutPostRedisplay();
        break;

    case 'A':
        if (shoulder_rx >= 1)
        {
            shoulder_rx = (shoulder_rx - 5);
            glutPostRedisplay();
        }

        break;

    case 'b':
        if (shoulder_rz >= -80 && shoulder_rz <= 80)
        {
            shoulder_rz = (shoulder_rz + 5);
        }

        glutPostRedisplay();
        break;

    case 'B':
        if (shoulder_rz >= -79)
        {
            shoulder_rz = (shoulder_rz - 5);
            glutPostRedisplay();
        }

        break;

    case 'c':
        if (shoulder_lx >= 0 && shoulder_lx <= 90)
        {
            shoulder_lx = (shoulder_lx + 5);
        }

        glutPostRedisplay();
        break;

    case 'C':
        if (shoulder_lx >= 1)
        {
            shoulder_lx = (shoulder_lx - 5);
            glutPostRedisplay();
        }

        break;

    case 'd':

        if (shoulder_lz >= -80)
        {
            shoulder_lz = (shoulder_lz - 5);
            glutPostRedisplay();
        }

        break;

    case 'D':
        if (shoulder_lz <= 80 && shoulder_lz >= -170)
        {
            shoulder_lz = (shoulder_lz + 5);
            glutPostRedisplay();
        }

        break;

    case 'e':
        if (elbow_r >= 0 && elbow_r <= 150)
        {
            elbow_r = (elbow_r + 5);

            glutPostRedisplay();
        }

        break;

    case 'E':
        if (elbow_r >= 1)
        {
            elbow_r = (elbow_r - 5);

            glutPostRedisplay();
        }
        break;

    case 'f':

        if (elbow_l >= -150)
        {
            elbow_l = (elbow_l - 5);
            glutPostRedisplay();
        }

        break;

    case 'F':
        if (elbow_l <= -1 && elbow_l >= -155)
        {
            elbow_l = (elbow_l + 5);
            glutPostRedisplay();
        }

        break;

        break;

    case 'g':

        if (hip_rx >= -90)
        { //&& hip_rx <=360) {
            hip_rx = (hip_rx - 5);
            glutPostRedisplay();
        }

        break;

    case 'G':
        if (hip_rx <= 10)
        { //&& hip_rx >= 180
            hip_rx = (hip_rx + 5);
            glutPostRedisplay();
        }

        break;

    case 'z':

        if (hip_rz >= 0)
        {
            hip_rz = (hip_rz - 5);
            glutPostRedisplay();
        }

        break;

    case 'Z':
        if (hip_rz <= 90)
        {
            hip_rz = (hip_rz + 5);
            glutPostRedisplay();
        }

        break;

    case 'h':

        if (hip_lx >= -90)
        { //&& hip_lx <= 0
            hip_lx = (hip_lx - 5);
            glutPostRedisplay();
        }

        break;

    case 'H':
        if (hip_lx <= 10)
        { // && hip_lx >=
            hip_lx = (hip_lx + 5);
            glutPostRedisplay();
        }

        break;

    case 'i':

        if (hip_lz >= -90)
        { // && hip_lz <= 0
            hip_lz = (hip_lz - 5);
            glutPostRedisplay();
        }

        break;

    case 'I':
        if (hip_lz <= 10)
        { //&& hip_lz >= -155
            hip_lz = (hip_lz + 5);
            glutPostRedisplay();
        }

        break;

    case 'J':

        if (knee_r >= 1)
        { //&& knee_r <= 0
            knee_r = (knee_r - 5);
            glutPostRedisplay();
        }

        break;

    case 'j':
        if (knee_r <= 90)
        { //&& knee_r >= -155
            knee_r = (knee_r + 5);
            glutPostRedisplay();
        }

        break;

    case 'K':

        if (knee_l >= 1)
        { //&& knee_l <= 0
            knee_l = (knee_l - 5);
            glutPostRedisplay();
        }

        break;

    case 'k':
        if (knee_l <= 90)
        { //&& knee_l >= -155
            knee_l = (knee_l + 5);
            glutPostRedisplay();
        }

        break;


     case 'l':

            lookLeft();
            glutPostRedisplay();
        

        break;    
    case 'L':

            lookRight();
            glutPostRedisplay();
        

        break;  

    case 'm':

            lookUp();
            glutPostRedisplay();
        

        break; 
    case 'M':

            lookDown();
            glutPostRedisplay();
        

        break; 
    case 'n':

            moveForward();
            glutPostRedisplay();
        

        break;   

    case 'N':

            moveBackward();
            glutPostRedisplay();
        

        break;       

    }
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP)
        {
            moving = 0;
        }
    }
}

static void motion(int x, int y)
{
    if (moving)
    {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
