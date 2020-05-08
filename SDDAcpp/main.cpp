//draw_main.cpp: main loop of drawing program

#define _USE_MATH_DEFINES // for PI number
#include <math.h>
#include <iostream> 
#include <GL/glut.h> //Drawing

//initialization
void init(void);
//does the drawing 
void display(void);

/*  Main Loop
 *  Open window with initial window size, title bar,
 *  RGBA display mode, depth buffer.
 */

struct Point {
    int x = -1;
    int y = -1;
} A{ -1, 1 }, B{ 1 }, C{ 1 }, D, E, F;

float step, xinc, yinc, x, y, perim;

void Input() 
{ 
    /*
    140 pixels is the min height for the hexagon drawed by 20x20 pseudopixels
    */
    std::cout << "Enter side length (>139): ";
    std::cin >> perim;

    if (perim < 140) {
        std::cout << "Too small parameters!\n";
        Input();
    }
}
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);	//get white background color
    glColor3f(0.0f, 0.0f, 0.0f);	//set drawing color
    glMatrixMode(GL_PROJECTION); //(0,0) is in the left buttom corner
    glLoadIdentity();			//replace current matrix with identity matrix
    gluOrtho2D(0.0, perim, 0.0, perim); // set workplace with the entered perimeter
}

int Round(float a)			//any x i.e 1>=x>=0.5 is rounded to 1
{
    if (a - int(a) >= 0.5)
        return int(a) + 1;
    else
        return int(a);
}

void DrawBig(float newXEnd, float newYEnd) // pseudopixels 20x20
{
    float yiff = newYEnd - y;
    float xdiff = newXEnd - x;
    if (abs(xdiff) > abs(yiff))
        step = abs(xdiff);                //assign abs(xdiff) to step1 if xdiff>yiff
    else
        step = abs(yiff);              //assign abs(yiff) to step1 if xdiff<yiff

    xinc = xdiff / step;            //assign xdiff/step1 to xinc
    yinc = yiff / step;           //assign yiff/step1 to yinc


    int rX = x, rY = y;
  
    for (int k = 0; k < Round(step); k++)
    {
        x = x + xinc;       // update x by xinc
        y = y + yinc;
        // to convert coordinates ц
        rX = Round(x) * 20 - 10, rY = Round(y) * 20 - 10;
        glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
            glVertex2i(rX, rY);//sets vertex
        glEnd();
    }
}

void DrawHexagon() 
{
    glColor3f(1.0, 0.5, 0.0); // set orange color
    glPointSize(20.0);			 // sets the size of points to be drawn (in pixels)
    x = A.x;               //assign xstart to x
    y = A.y;              //assign ystart to y

    //A->B
    DrawBig(B.x, B.y);
    //B->C
    DrawBig(C.x, C.y);
    //C->D
    DrawBig(D.x, D.y);
    //D->E
    DrawBig(E.x, E.y);
    //E->F
    DrawBig(F.x, F.y);
    //F->A
    DrawBig(A.x, A.y);
}

void Brezenhem(int x0, int y0, int x1, int y1, bool isCenter) {
    int A, B, sign;
    int xShift = isCenter ? 10 : 5;
    A = y1 - y0;
    B = x0 - x1;
    if (abs(A) > abs(B)) sign = 1;
    else sign = -1;
    int signa, signb;
    if (A < 0) signa = -1;
    else signa = 1;
    if (B < 0) signb = -1;
    else signb = 1;
    int f = 0;
    int rX = (Round(x0) * 10 - xShift), rY = (Round(y0) * 10 - 5);
    glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
    glVertex2i(rX, rY); // sets vertex (draws the pseudopixel)
    glEnd();
    int x = x0, y = y0;
    if (sign == -1)
    {
        do {
            f += A * signa;
            if (f > 0)
            {
                f -= B * signb;
                y += signa;
            }
            x -= signb;
            rX = (Round(x) * 10 - xShift), rY = (Round(y) * 10 - 5);
            glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
            glVertex2i(rX, rY); // sets vertex (draws the pseudopixel)
            glEnd();
        } while (x != x1 || y != y1);
    }
    else
    {
        do {
            f += B * signb;
            if (f > 0) {
                f -= A * signa;
                x -= signb;
            }
            y += signa;
            rX = (Round(x) * 10 - xShift), rY = (Round(y) * 10 - 5);
            glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
            glVertex2i(rX, rY); // sets vertex (draws the pseudopixel)
            glEnd();
        } while (x != x1 || y != y1);
    }
}

void DrawInnerLines()
{
    glPointSize(10.0);			 // sets the size of points to be drawn (in pixels)

    /*
        Перевод из 20х20 в 10х10ж
        с учетом того, в каком квадранте должен находиться новый псевдопиксель
        мы либо отнимаем (лево/низ) либо прибавляем (верх/право) 1
    */

    //C -> F RED
    glColor3f(1.0, 0.0, 0.0); // set red color in rgb
    int startX = C.x * 2 - 1; // x start in 10x10 pseudopixels
    int startY = C.y * 2; // y start in 10x10 pseudopixels
    int endX = F.x * 2; // x end in 10x10 pseudopixels
    int endY = F.y * 2 - 1; // y end in 10x10 pseudopixels
    Brezenhem(startX, startY, endX, endY, false); // false means it is not the vertical line

    //B -> E GREEN
    glColor3f(0.0, 1.0, 0.0); // set green color in rgb
    startX = B.x * 2 - 1; // x start in 10x10 pseudopixels
    startY = B.y * 2 - 1; // y start in 10x10 pseudopixels
    endX = E.x * 2; // x end in 10x10 pseudopixels
    endY = E.y * 2; // y end in 10x10 pseudopixels
    Brezenhem(startX, startY, endX, endY, false); // false means it is not the vertical line

    //A -> D BLUE
    glColor3f(0.0, 0.0, 1.0); // set blue color in rgb
    startX = A.x * 2; // x start in 10x10 pseudopixels
    startY = A.y * 2 - 1; // y start in 10x10 pseudopixels
    endX = D.x * 2; // x end in 10x10 pseudopixels
    endY = D.y * 2; // y end in 10x10 pseudopixels
    Brezenhem(startX, startY, endX, endY, true); // true means it is the vertical line
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);	//clear screen

    DrawHexagon(); // Big 20x20 outer lines. DDA

    DrawInnerLines(); // Little 10x10 innter lines. Bresenham's Line Drawing Algorithm

    glutPostRedisplay();

    glFlush();	//send all output to screen
}

void SetPoints() {
    int p = perim / 20; //perimeter in pseudopixels

    double sinus = 0.5;// sin(30 * M_PI / 180.0); // 
    double cosinus = .86;// cos(30 * M_PI / 180.0);
    
    double r = ((p + 1)) / 2;
    int y = r * sinus;
    int x = r * cosinus;

    //A
    A.x = Round(r);
    A.y = 1;

    //B
    B.y = Round(y * -1 + (r));

    //C
    C.y = Round(y + (r));

    //D
    D.x = Round(r);
    D.y = p;

    //E
    E.x = Round(x * 2 + 1);
    E.y = Round(y + (r));

    //F
    F.x = Round(x * 2 + 1);
    F.y = Round(y * -1 + (r));

    C.x = B.x = A.x;
    for (int i = E.x; i > A.x; i--) 
    {
        C.x = --B.x;
    } 
}



int main(int argc, char** argv)
{
    Input();
    
    // 
    while((int)perim % 40 != 20)
    {
        perim--;
    }
 
    SetPoints();
    glutInit(&argc, argv);	//initialize toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set display mode: single bufferring, RGBA model
    glutInitWindowSize(perim,perim);		//set window size on screen
    glutInitWindowPosition(100, 100); 	//set window position on screen
    glutCreateWindow(argv[0]);		//open screen window
    init();
    glutDisplayFunc(display);		//points to display function
    glutMainLoop();			//go into perpetual loop
    return 0;
}