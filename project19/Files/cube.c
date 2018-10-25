#include <windows.h>  //must be included to work in windows.
#include <math.h>     //provides sin, cos, etc.
#include <stdlib.h>   //provides several useful functions.
#include <H:\ECE251\glut.h>  //connects to glut.h 

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
    //You may change the following line to adjust the background:
	glClearColor(0.0f, 0.0f, 1.0f, 0); //Set background to blue
	
	// Clear the screen. DO NOT CHANGE.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	// Reset transformations. DO NOT CHANGE.
	glLoadIdentity(); 
	// Set the camera view.  DO NOT CHANGE.
	gluLookAt(0.0f, 0.0f, 5.0, //Location of your eye
			  0.0f, 0.0f, 0.0f, //Location you are looking at
			  0.0f, 1.0f, 0.0f); //Direction of "up"

			  
			  
	////////Change this section to draw your object///////


	

	glPushMatrix();  //Save the home location and orientation.
	glRotatef(60, 1.0f, 1.0f, 1.0f);  //Rotate the coordinate system.
	glColor3f(1.0f, 0.0f, 0.0f);  //Set color to red
    glutSolidCube(2.0f);  //Draw a cube with side=2.0
	glColor3f(0.0f, 0.0f, 0.0f);  //Set color to black.
	glLineWidth(3.0f);   //Set line width to 3.0
    glutWireCube(2.0f);   //Draw a wire (hollow) cube
	glPopMatrix();    //Restore the home location.



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
	glutCreateWindow("Cube");  //Window title.

	// register callbacks
	glutDisplayFunc(renderScene);  //When you need to display, call renderScene().
	glutReshapeFunc(changeSize);   //When you need to reshape, call changeSize().

	// OpenGL init
	glEnable(GL_DEPTH_TEST);  //Enables objects to appear in 3D

	// enter GLUT event processing cycle
	glutMainLoop();  //Enter an infinite loop to draw the picture.
	
	return 1;
}