
#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, fingerBase1 = 0, fingerUp1 = 0,fingerBase2 = 0,fingerBase3 = 0 ,fingerUp2 = 0,fingerUp3 = 0, fingerBase4 = 0 ,fingerUp4 = 0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);
   glTranslatef (-1.0, 0.0, 0.0);
   glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.6, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.6, 1);
   glutWireCube (1.0);
   glPopMatrix();

   // Draw finger flang 1 
   glPushMatrix();
   glTranslatef(1.0, 0.25, 0.45);
   glRotatef((GLfloat)fingerBase1, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();


      //Draw finger flang 1 
     
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)fingerUp1, 0.0, 0, 1);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();


// 
// finger2
   glPushMatrix();
  glTranslatef(1, 0.25, -0.45);
   glRotatef((GLfloat)fingerBase2, 0.0, 0.0, 1);
   glTranslatef(0.15, 0.0, 0.0);
  glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();


      //Draw finger flang 2
      
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)fingerUp2, 0.0, 0.0, 4);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();



    //Draw finger 3
    glPushMatrix();
   glTranslatef(1, 0.25, -0.05);
   glRotatef((GLfloat)fingerBase3, 0.0, 0.0, 1);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();


      //Draw finger flang 3
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)fingerUp3, 0.0, 0.0, 1);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();   





     //Draw finger 4
    glPushMatrix();
   glTranslatef(1, -0.25, -0.05);
   glRotatef((GLfloat)fingerBase4, 0.0, 0.0, 1);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();


      //Draw finger flang 4
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)fingerUp4, 0.0, 0.0, 1);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.1, 0.1);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();   



   
   glPopMatrix();
   glutSwapBuffers();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 'j':
      shoulder = (shoulder + 5) % 360;
      glutPostRedisplay();
      break;
   case 'J':
         shoulder = (shoulder - 5) % 360;
      
      glutPostRedisplay();
      break;
   case 'k':
      if(elbow >=0 && elbow<=180){
         elbow = (elbow + 5) ;
      }
      
      glutPostRedisplay();
      break;

   case 'K':
      if(elbow>=1){
         elbow = (elbow - 5);
         glutPostRedisplay();
      }
      
      break;   
    case 'q':

      if(fingerBase1<=5 && fingerBase1>=-90){
         fingerBase1 = (fingerBase1 - 5);
         glutPostRedisplay();
      }
      break;
   case 'Q':
      if(fingerBase1<=1){

         fingerBase1 = (fingerBase1 + 5);
         glutPostRedisplay();
   }

      break;




   case 'e':

      if(fingerBase2<=5 && fingerBase2>=-90){
         fingerBase2 = (fingerBase2 - 5);
         glutPostRedisplay();
      }
      break;
   case 'E':
      if(fingerBase2<=1){

         fingerBase2 = (fingerBase2 + 5);
         glutPostRedisplay();
   }

      break;



    case 'w':

      if(fingerBase3<=5 && fingerBase3>=-90){
         fingerBase3 = (fingerBase3 - 5);
         glutPostRedisplay();
      }
      break;
   case 'W':
      if(fingerBase3<=1){

         fingerBase3 = (fingerBase3 + 5);
         glutPostRedisplay();
   }

      break;
   case 'r':

      if(fingerBase4>=0 && fingerBase4<=90){
         fingerBase4 = (fingerBase4 + 5);
         glutPostRedisplay();
      }
      break;
   case 'R':
      if(fingerBase4>=1){

         fingerBase4= (fingerBase4 - 5);
         glutPostRedisplay();
   }

      break;

    case 's':

      if(fingerUp1<=5 && fingerUp1>=-90){
         fingerUp1= (fingerUp1 - 5);
         glutPostRedisplay();
      }
      break;
   case 'S':
      if(fingerUp1<=1){

         fingerUp1 = (fingerUp1 + 5);
         glutPostRedisplay();
   }

      break;
   case 'g':

      if(fingerUp2<=5 && fingerUp2>=-90){
         fingerUp2 = (fingerUp2 - 5);
         glutPostRedisplay();
      }
      break;
   case 'G':
      if(fingerUp2<=1){

         fingerUp2 = (fingerUp2 + 5);
         glutPostRedisplay();
   }

      break;





    case 't':

      if(fingerUp3<=5 && fingerUp3>=-90){
         fingerUp3 = (fingerUp3 - 5);
         glutPostRedisplay();
      }
      break;
   case 'T':
      if(fingerUp3<=1){

         fingerUp3 = (fingerUp3 + 5);
         glutPostRedisplay();
   }

      break;

    case 'y':

      if(fingerUp4>=0 && fingerUp4<=90){
         fingerUp4 = (fingerUp4 + 5);
         glutPostRedisplay();
      }
      break;
   case 'Y':
      if(fingerUp4>=1){

         fingerUp4= (fingerUp4 - 5);
         glutPostRedisplay();
   }

      break;


   case 27:
      exit(0);
      break;
   default:
      break;
   }
}

static void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      moving = 1;
      startx = x;
      starty = y;
    }
    if (state == GLUT_UP) {
      moving = 0;
    }
  }
}


static void motion(int x, int y)
{
  if (moving) {
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