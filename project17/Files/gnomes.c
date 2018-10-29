//#include <windows.h>
#include <math.h>
#include <stdlib.h>
//#include <H:\ECE251\glut.h>  //connects to glut.h

#if defined(__APPLE__)
#include <GLUT/glut.h>    /* Header File For The GLUT Library  */
#include <OpenGL/gl.h>	/* Header File For The OpenGL Library  */
#include <OpenGL/glu.h>	/* Header File For The GLu Library  */
#else
#include <windows.h>
#include <H:\ECE251\glut.h>  //connects to glut.h
#endif



// move 10 units / second (MAC)
// turn 2 radians per second : 115 deg per second
#define MOVESPEED 15.0f
#define TURNSPEED 2.5f

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

// For timing: Elapsed ms since last render
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

void drawGnome(float x, float z) {
	

  // Draw Legs
  glPushMatrix();
  glTranslatef(x ,0.0f, z); 
  glColor3f(0.545,0.271,0.075);
  glutSolidSphere(0.25f,10,10);    //Pants
  glPopMatrix();

  glPushMatrix();
  glTranslatef(x ,0.40f, z); 
  glColor3f(0.0f,0.0f,1.0f);
  glutSolidSphere(0.25f,10,10);    //Torso
  glPopMatrix();

  glPushMatrix();
  glTranslatef(x ,0.40f, z); 
  glRotatef(90,1,0,0);
  glColor3f(0.545,0.271,0.075);
  glutSolidTorus(0.05f,0.21f,20,20);  //Belt
  glPopMatrix();
	
  glPushMatrix();
  glTranslatef(x ,0.65f, z); 
  glRotatef(90,1,0,0);
  glColor3f(1.0f, 1.0f, 1.0f);
  glutSolidTorus(0.05f,0.20f,10,10);  //Beard
  glPopMatrix();
	
  glPushMatrix();
  glTranslatef(x, 0.90f, z);
  glColor3f(1.0f, 0.894f, 0.710f);
  glutSolidSphere(0.25f,10,10);    //Face
  glPopMatrix();

  glPushMatrix();
  glTranslatef(x-0.10f ,0.95f, z+0.2f); 
  glColor3f(0.0f, 0.0f, 0.0f);
  glutSolidSphere(0.05f,10,10);    //Left Eye
  glPopMatrix();
	
  glPushMatrix();
  glTranslatef(x+0.10f ,0.95f, z+0.2f); 
  glColor3f(0.0f, 0.0f, 0.0f);
  glutSolidSphere(0.05f,10,10);    //Right Eye
  glPopMatrix();

  glPushMatrix();
  glTranslatef(x, 1.05f, z);
  glRotatef(90,-1,0,0);
  glColor3f(1.0f, 0.0f, 0.0f);
  glutSolidCone(0.20,0.75,10,10); // Hat
  glPopMatrix();

  glPushMatrix();
  glTranslatef(x ,1.80f, z); 
  glColor3f(1.0f, 1.0f, 1.0f);
  glutSolidSphere(0.05f,10,10);    //Puffball
  glPopMatrix();




}

void drawGround() {

  glColor3f(0.0f, 1.0f, 0.0f);
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

  if (deltaMove||deltaAngle) {
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

  // Draw Gnome
  int rowCounter, colCounter;
  float spacing=2;
  for (rowCounter=-10 ; rowCounter<=10 ; rowCounter++){
    for (colCounter=-10 ; colCounter<=10 ; colCounter++){
      drawGnome(rowCounter * spacing, colCounter * spacing);
    }
  }
	
  //drawGnome();
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
  glutCreateWindow("Gnomey the Gnome");

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
