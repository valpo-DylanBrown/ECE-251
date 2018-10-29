#include <windows.h>  //must be included to work in windows.
#include <math.h>     //provides sin, cos, etc.
#include <stdlib.h>   //provides several useful functions.
#include <H:\ECE251\glut.h>  //connects to glut.h 

#define DEGREES_PER_SECOND 15.0f
float angle=0;

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

			  
			  
     etime = getEtime();		// Get the elasped ms since last render
     ////////Change this section to draw your object///////
	
     // Update geometry:  (deg/sec * ms / ms per second = degrees)
     angle += DEGREES_PER_SECOND * etime / 1000.0;
	
     // Draw geometry
     glPushMatrix();
     glRotatef(angle, 1.0f, 1.0f, 1.0f);
     glColor3f(1.0f, 0.0f, 0.0f);
     glutSolidCube(2.0f);
     glColor3f(0.0f, 0.0f, 0.0f);
     glLineWidth(3.0f);
     glutWireCube(2.0f);
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
     glutIdleFunc(renderScene);  //When you are idle, call renderScene().
     glutDisplayFunc(renderScene);  //When you need to display, call renderScene().
     glutReshapeFunc(changeSize);   //When you need to reshape, call changeSize().

     // OpenGL init
     glEnable(GL_DEPTH_TEST);  //Enables objects to appear in 3D

     // enter GLUT event processing cycle
     glutMainLoop();  //Enter an infinite loop to draw the picture.
	
     return 1;
}
