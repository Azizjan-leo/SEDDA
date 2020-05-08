////draw.cpp : demo program for drawing 3 dots, two lines, ploylines, rectangles
//#include <GL/glut.h>
//#include <cstdlib>
//
//float xstart = 4, ystart = 1, xend = 1, yend = 2, step, xinc, yinc, x, y;
//
//
//void init(void)
//{
//    glClearColor(1.0, 1.0, 1.0, 0.0);	//get white background color
//    glColor3f(0.0f, 0.0f, 0.0f);	//set drawing color
//    glPointSize(20.0);			 // sets the size of points to be drawn (in pixels)
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();			//replace current matrix with identity matrix
//    gluOrtho2D(0.0, 140.0, 0.0, 140.0);
//}
//
//int Round(float a)			//any x i.e 1>=x>=0.5 is rounded to 1
//{
//    if (a - int(a) >= 0.5)
//        return int(a) + 1;
//    else
//        return int(a);
//}
//
//void draw(float newXEnd, float newYEnd) {
//    float yiff = newYEnd - y;
//    float xdiff = newXEnd - x;
//    if (abs(xdiff) > abs(yiff))
//        step = abs(xdiff);                //assign abs(xdiff) to step1 if xdiff>yiff
//    else
//        step = abs(yiff);              //assign abs(yiff) to step1 if xdiff<yiff
//
//    xinc = xdiff / step;            //assign xdiff/step1 to xinc
//    yinc = yiff / step;           //assign yiff/step1 to yinc
//
//
//    int rX = Round(x), rY = Round(y);
//
//    for (int k = 0; k < step; k++)
//    {
//        x = x + xinc;       // update x by xinc
//        y = y + yinc;
//        rX = Round(x) * 20 - 10, rY = Round(y) * 20 - 10;
//        glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
//        glVertex2i(rX, rY);//sets vertex
//        glEnd();
//    }
//}
//
//void display(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);	//clear screen
//    glColor3f(1.0, 0.5, 0.0);
//    float yiff = yend - ystart;
//    float xdiff = xend - xstart;
//    if (abs(xdiff) > abs(yiff))
//        step = abs(xdiff);                //assign abs(xdiff) to step1 if xdiff>yiff
//    else
//        step = abs(yiff);              //assign abs(yiff) to step1 if xdiff<yiff
//    
//    xinc = xdiff / step;            //assign xdiff/step1 to xinc
//    yinc = yiff / step;           //assign yiff/step1 to yinc
//    
//    x = xstart;               //assign xstart to x
//    y = ystart;              //assign ystart to y
//   
//    int rX = Round(x), rY = Round(y);
//
//    for (int k = 0; k < step; k++)
//    {
//        x = x + xinc;       // update x by xinc
//        y = y + yinc;
//        rX = Round(x) * 20-10, rY = Round(y) * 20-10;
//        glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
//        glVertex2i(rX, rY);//sets vertex
//        glEnd();
//    }
//
//    //2
//    draw(1, 6);
//    //
//    draw(4, 7);
//    //
//    draw(7, 6);
//    //
//    draw(7, 2);
//    //
//    draw(4, 1);
//    
//    glutPostRedisplay();
//
//    glFlush();				//send all output to screen
//}
//
