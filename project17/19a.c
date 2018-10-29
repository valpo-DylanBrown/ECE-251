#include <math.h>
#include <stdlib.h>
#if defined(__APPLE__)
#include <GLUT/glut.h>    /* Header File For The GLUT Library  */
#include <OpenGL/gl.h>	/* Header File For The OpenGL Library  */
#include <OpenGL/glu.h>	/* Header File For The GLu Library  */
#else
#include <windows.h>
#include <C:\Users\Dylan\Documents\GitHub\ECE-251_new\project17\glut.h>  //connects to glut.h
#endif

#define MOVESPEED 40.0f   // Move 40 meters per second
#define TURNSPEED 2.0f    // 2 radians per second

// angle of rotation for the camera direction
float angle = 0.0f;

// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;

// XZ position of the camera
float x=0.0f, z=5.0f;

// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;

int etime = 0;
// Calculate elapsed time since last render (milliseconds)
int getEtime(void) {
  static int lasttime = 0;
  int time = glutGet(GLUT_ELAPSED_TIME);
  int etime = time - lasttime;
  lasttime = time; // store current time for next frame
  return (etime);
}

void changeSize(int w, int h) {

  // Prevent a divide by zero, when window is too short
  // (you cant make a window of zero width).
  if (h == 0)
    h = 1;

  float ratio =  w * 1.0 / h;

  // Use the Projection Matrix
  glMatrixMode(GL_PROJECTION);

  // Reset Matrix
  glLoadIdentity();

  // Set the viewport to be the entire window
  glViewport(0, 0, w, h);

  // Set the correct perspective.
  gluPerspective(45.0f, ratio, 0.1f, 100.0f);

  // Get Back to the Modelview
  glMatrixMode(GL_MODELVIEW);
}

void drawHouse() {
  //begin windows
  glColor3f(0.992f, 0.992f, 0.588f); //yellow
  glBegin(GL_QUADS);		         // Draw a Quadrangle
  glVertex3f(0.5f, 0.5f, 0.0f); // Bottom Left
  glVertex3f(0.5f, 1.5f, 0.0f); // Top Left
  glVertex3f(1.5f,1.5f, 0.0f); // Top Right
  glVertex3f(1.5f, 0.5f, 0.0f); //Bottom Right
  glEnd();					     // Finished Square (Quadrangle)
  glBegin(GL_QUADS);		         // Draw a Quadrangle
  glVertex3f(0.5f, 4.5f, 0.0f); // Bottom Left
  glVertex3f(0.5f, 5.5f, 0.0f); // Top Left
  glVertex3f(1.5f,5.5f, 0.0f); // Top Right
  glVertex3f(1.5f, 4.5f, 0.0f); //Bottom Right
  glEnd();					     // Finished Square (Quadrangle)
  glBegin(GL_QUADS);		         // Draw a Quadrangle
  glVertex3f(0.5f, 0.5f, 0.0f); // Bottom Left
  glVertex3f(0.5f, 1.5f, 0.0f); // Top Left
  glVertex3f(1.5f,1.5f, 0.0f); // Top Right
  glVertex3f(1.5f, 0.5f, 0.0f); //Bottom Right
  glEnd();					     // Finished Square (Quadrangle)
  glBegin(GL_QUADS);		         // Draw a Quadrangle
  glVertex3f(4.5f, 0.5f, 0.0f); // Bottom Left
  glVertex3f(4.5f, 1.5f, 0.0f); // Top Left
  glVertex3f(5.5f,1.5f, 0.0f); // Top Right
  glVertex3f(5.5f, 0.5f, 0.0f); //Bottom Right
  glEnd();					     // Finished Square (Quadrangle)
  glBegin(GL_QUADS);		         // Draw a Quadrangle
  glVertex3f(4.5f, 4.5f, 0.0f); // Bottom Left
  glVertex3f(4.5f, 5.5f, 0.0f); // Top Left
  glVertex3f(5.5f,5.5f, 0.0f); // Top Right
  glVertex3f(5.5f, 4.5f, 0.0f); //Bottom Right
  glEnd();					     // Finished Square (Quadrangle)
  //end windows
  //begin handle
  glColor3f(0.75f, 0.75f, 0.75f); //blue
  glBegin(GL_QUADS);		         // Draw a Quadrangle
  glVertex3f(3.5f, 1.2f, 0.0f); // Bottom Left
  glVertex3f(3.5f, 1.5f, 0.0f); // Top Left
  glVertex3f(3.75f,1.5f, 0.0f); // Top Right
  glVertex3f(3.75f, 1.2f, 0.0f); //Bottom Right
  glEnd();					     // Finished Square (Quadrangle)
  //end handle
  //begin door
  glColor3f(0.467f, 0.675f, 0.796f); //blue
  glBegin(GL_QUADS);		         // Draw a Quadrangle
  glVertex3f(2.0f, 0.0f, 0.0f); // Bottom Left
  glVertex3f(2.0f, 3.0f, 0.0f); // Top Left
  glVertex3f(4.0f,3.0f, 0.0f); // Top Right
  glVertex3f(4.0f, 0.0f, 0.0f); //Bottom Right
  glEnd();					     // Finished Square (Quadrangle)
  //end door
  //begin house
  glColor3f(1.0f, 0.0f, 0.0f); //red
  glBegin(GL_QUADS);		         // Draw a Quadrangle
  glVertex3f(0.0f, 0.0f, 0.0f); // Bottom Left
  glVertex3f(0.0f, 6.0f, 0.0f); // Top Left
  glVertex3f( 6.0f,6.0f, 0.0f); // Top Right
  glVertex3f(6.0f, 0.0f, 0.0f); //Bottom Right
  glEnd();					     // Finished Square (Quadrangle)
  //end house
  //begin roof
  glColor3f(0.0f, 0.0f, 0.0f);     //black
  glBegin(GL_TRIANGLES);		     // Draw a Triangle
  glVertex3f(3.0f, 12.0f, 0.0f); // Top
  glVertex3f(-2.0f,6.0f, 0.0f); // Bottom Left
  glVertex3f( 8.0f,6.0f, 0.0f); // Bottom Right
  glEnd();					     // Finished Triangle
  //end roof
  //begin chimney
  glColor3f(1.0f, 1.0f, 1.0f); //white
  glBegin(GL_QUADS);		         // Draw a Quadrangle
  glVertex3f(4.0f, 7.0f, 0.0f); // Bottom Left
  glVertex3f(4.0f, 12.0f, 0.0f); // Top Left
  glVertex3f(6.0f,12.0f, 0.0f); // Top Right
  glVertex3f(6.0f, 7.0f, 0.0f); //Bottom Right
  glEnd();					     // Finished Square (Quadrangle)
  //end chimney

}

void drawGround() {

  glColor3f(0.376f, 0.502f, 0.22f);
  glBegin(GL_QUADS);
  glVertex3f(-100.0f, 0.0f, -100.0f);
  glVertex3f(-100.0f, 0.0f,  100.0f);
  glVertex3f( 100.0f, 0.0f,  100.0f);
  glVertex3f( 100.0f, 0.0f, -100.0f);
  glEnd();

}

void computePos(float deltaMove) {
  angle += deltaAngle * etime / 1000.0f;
  lx = sin(angle);
  lz = -cos(angle);
  x += (deltaMove * etime / 1000.0f) * lx;
  z += (deltaMove * etime / 1000.0f) * lz;
}

void renderScene(void) {

  etime = getEtime();		// Get the elasped ms since last render

  if (deltaMove||deltaAngle)
    {
      computePos(deltaMove);
    }

  // Clear Color and Depth Buffers
  glClearColor(0.529f, 0.808f, 0.980f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Reset transformations
  glLoadIdentity();
  // Set the camera
  gluLookAt(	x, 1.0f, z,
		x+lx, 1.0f,  z+lz,
		0.0f, 1.0f,  0.0f);

  //Draw Ground
  drawGround();

  // Draw House
  drawHouse();
  glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int xx, int yy) {

  if (key == 27)
    exit(0);
}

void pressKey(int key, int xx, int yy) {

  switch (key) {
  case GLUT_KEY_UP    : deltaMove  =  MOVESPEED; break;
  case GLUT_KEY_DOWN  : deltaMove  = -MOVESPEED; break;
  case GLUT_KEY_LEFT  : deltaAngle = -TURNSPEED; break;
  case GLUT_KEY_RIGHT : deltaAngle =  TURNSPEED; break;
  }
}

void releaseKey(int key, int x, int y) {

  switch (key) {
  case GLUT_KEY_UP :
  case GLUT_KEY_DOWN : deltaMove = 0;break;
  case GLUT_KEY_LEFT :
  case GLUT_KEY_RIGHT : deltaAngle = 0; break;

  }
}

int main(int argc, char **argv) {

  // init GLUT and create window
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(320,320);
  glutCreateWindow("House");

  // register callbacks
  glutDisplayFunc(renderScene);
  glutReshapeFunc(changeSize);
  glutIdleFunc(renderScene);

  glutKeyboardFunc(processNormalKeys);
  glutSpecialFunc(pressKey);
  glutSpecialUpFunc(releaseKey);

  // OpenGL init
  glEnable(GL_DEPTH_TEST);

  // enter GLUT event processing cycle
  glutMainLoop();

  return 1;
}
