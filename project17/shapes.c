#include <windows.h>  //must be included to work in windows.
#include <math.h>     //provides sin, cos, etc.
#include <stdlib.h>   //provides several useful functions.
#include <H:\ECE251\glut.h>  //connects to glut.h 

float x=-5;

void changeSize(int w, int h) {
    //DO NOT CHANGE ANYTHING IN THIS FUNCTION.
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


void renderScene(void) {
	float xSpacing=5.0;

	x+=0.01; //shift to the right.
	if(x>xSpacing*18)
	{
	  x=-xSpacing*2;
	}

    //You may change the following line to adjust the background:
	glClearColor(1.0f, 1.0f, 1.0f, 0); //Set background to blue
	
	// Clear the screen. DO NOT CHANGE.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	// Reset transformations. DO NOT CHANGE.
	glLoadIdentity(); 
	// Set the camera view.  DO NOT CHANGE.
	gluLookAt(x, 0.0f, 5.0, //Location of your eye
			  x, 0.0f, 0.0f, //Location you are looking at
			  0.0f, 1.0f, 0.0f); //Direction of "up"
		  
	////////Change this section to draw your object///////

	glPushMatrix();
	glTranslatef(xSpacing*0,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutSolidSphere(1.0f, 32, 32);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(xSpacing*1,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutWireSphere(1.0f, 32, 32);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(xSpacing*2,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutSolidCube(1.5f);	
	glColor3f(1.0f, 1.0f, 1.0f);
    glutWireCube(1.5f);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(xSpacing*3,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutWireCube(1.5f);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(xSpacing*4,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(90, 1, 1, 0);
    glutSolidCone(1.0f, 2.0f, 32, 32);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(xSpacing*5,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(90, 1, 1, 0);
    glutWireCone(1.0f, 2.0f, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xSpacing*6,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutSolidTorus(0.25f, 0.5f, 32, 32); //inner, outer, sides, rings
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xSpacing*7,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutWireTorus(0.25f, 0.5f, 32, 32); //inner, outer, sides, rings
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xSpacing*8,0.0f,0.0f);
	glScalef(0.7f,0.7f, 0.7f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutSolidDodecahedron();
	glColor3f(1.0f, 1.0f, 1.0f);
    glutWireDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xSpacing*9,0.0f,0.0f);
	glScalef(0.7f,0.7f, 0.7f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutWireDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xSpacing*10,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutSolidOctahedron();
	glColor3f(1.0f, 1.0f, 1.0f);
    glutWireOctahedron();	
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xSpacing*11,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutWireOctahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xSpacing*12,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutSolidTetrahedron();
	glColor3f(1.0f, 1.0f, 1.0f);
    glutWireTetrahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xSpacing*13,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutWireTetrahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xSpacing*14,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutSolidIcosahedron();
	glColor3f(1.0f, 1.0f, 1.0f);
    glutWireIcosahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xSpacing*15,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutWireIcosahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xSpacing*16,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutSolidTeapot(1.0f);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(xSpacing*17,0.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
    glutWireTeapot(1.0f);
	glPopMatrix();

    ///////////End of section to be changed.//////////////
	
	glutSwapBuffers();  //DO NOT CHANGE
} 

int main(int argc, char **argv) {
    //You should not need to change anything in this main program.
	
	// init GLUT and create window
	glutInit(&argc, argv); //Allows input arguments to initialize OpenGL.
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100); //Create window at this location.
	glutInitWindowSize(320,320); //Default window size.
	glutCreateWindow("Triangle");  //Window title.

	// register callbacks
	glutDisplayFunc(renderScene);  //When you need to display, call renderScene().
	glutIdleFunc(renderScene);  //When you have nothing else to do, call renderScene().
	glutReshapeFunc(changeSize);   //When you need to reshape, call changeSize().

	// OpenGL init
	glEnable(GL_DEPTH_TEST);  //Enables objects to appear in 3D

	// enter GLUT event processing cycle
	glutMainLoop();  //Enter an infinite loop to draw the picture.
	
	return 1;
}