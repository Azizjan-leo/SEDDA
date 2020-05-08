//
//#include <GL/glut.h>
//#include<stdlib.h>
//#include<math.h>
//#include <cstdlib>
//#include <iostream>

//void myinit(void)
//{
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
//}
//
//float xstart = 2, ystart = 0, xend = 0, yend = 1, step, xinc, yinc, x, y;
//
//
//int Round(float a)			//any x i.e 1>=x>=0.5 is rounded to 1
//{
//    if (a - int(a) >= 0.5)
//        return int(a) + 1;
//    else
//        return int(a);
//}
//
//void drawline()
//{
//
//    float ydiff = yend - ystart;
//    float xdiff = xend - xstart;
//    if (abs(xdiff) > abs(ydiff))
//        step = abs(xdiff);                //assign abs(xdiff) to step if xdiff>ydiff
//    else
//        step = abs(ydiff);              //assign abs(ydiff) to step if xdiff<ydiff
//
//    xinc = xdiff / step;            //assign xdiff/step to xinc
//    yinc = ydiff / step;           //assign ydiff/step to yinc
//
//    x = xstart;               //assign xstart to x
//    y = ystart;              //assign ystart to y
//
//    glColor3f(1.0, 0.5, 0.0); // sets the current drawing (foreground) color to blue 
//    glPointSize(20); // sets the size of points to be drawn (in pixels)
//    int rX = Round(x), rY = Round(y);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
//        glVertex2i(0, 0);
//        glVertex2i(40, 40);
//    glEnd();
//    //for (int k = 0; k < step; k++)
//    //{
//    //    x = x + xinc;       // update x by xinc
//    //    y = y + yinc;
//    //    rX = Round(x), rY = Round(y);
//    //    glColor3f(1.0, 0.5, 0.0); // sets the current drawing (foreground) color to blue 
//    //    glPointSize(20); // sets the size of points to be drawn (in pixels)
//    //    glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
//    //    glVertex2i(rX*20, rY*20);//sets vertex
//    //    glEnd();
//    //}
//    glutPostRedisplay();
//
//
//}
//
//void display(void)
//{
//
//    glClear(GL_COLOR_BUFFER_BIT); // clears the frame buffer and set values defined in glClearColor() function call 
//
//    drawline();
//
//
//    glFlush(); // flushes the frame buffer to the screen
//}
//
//int main(int argc, char** argv)
//{
//    int height = 500, width = 500;
//   /* std::cout << "Enter height and width \n";
//    std::cin >> height >> width;*/
//    glutInit(&argc, argv);
//    glutInitWindowSize(width, height);//sets the width and height of the window in pixels
//    glutInitWindowPosition(100, 200);//sets the position of the window in pixels from top left corner 
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//creates a single frame buffer of RGB color capacity.
//    glutCreateWindow("DDA Line Drawing");//creates the window as specified by the user as above.
//
//    glutDisplayFunc(display);//links the display event with the display event handler(display)
//    myinit();
//    glutIdleFunc(drawline);
//    glutMainLoop();//loops the current event
//}