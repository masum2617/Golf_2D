#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define ballMargin -38
#include <string>
#include <sstream>
#define IDYES 6
using namespace std;

HWND hwnd;
float angle2 = 0.0;
float amp=0.0;
float incx =-55.0;
float incy = -38.0;
float stickRoate = 0.0;
int stateForSpeedBar, count, stateForLoft, stateForUpDown;
int upperMargin = -38;
float speedBarX=45.0, speedBarY = 57.0;
float ballSpeedMeter=0;
int score = 0, df=10;
bool restart = false;



void animate();
void stick();
void ballUpDown();
void loft();
void speedBar();
void ballMoveGround();
void cloud();
//string converToString(int s);


string convertToString() {

    ostringstream str1;
    str1<<score;

  string score_string = str1.str();
  return score_string;

}


void instructions(){

    char *instr[500] = { "************ INSTRUCTIONS **********************", " ",

                        "1. Hold Right Arrow key to increase the Speed of your Shot",
                        "2. Release the Right Arrow key after increasing speed",
                        "3. Press S ---> Grounded shot",
                        "4. If attempts failed press 'R' to reset the ball position",
                        " *********************************************** "," ",
                        " ********* Scoring Information ****************",
                        " Player will get 5 points each successful attempt"};

    for (int i = 0; i < 500; i++)
        std::cout << instr[i] << "\n";

}

void scoretext(char text[50])
{
    //char text[32] = "Score: ";
   // string s1 = convertToString();

    glColor3f(0, 0, 0);
    glRasterPos3f( -70 , 70 , 0.0);
    //glutBitmapString(GLUT_BITMAP_HELVETICA_12,s);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    for(int i = 0; convertToString()[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, convertToString()[i]);

}

void outputText(char text[100], float pos_x, float pos_y) {

    glColor3f(0, 0, 0);
    glRasterPos3f( pos_x , pos_y , 0.0);
    //glutBitmapString(GLUT_BITMAP_HELVETICA_12,s);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

}

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

        case 'l':
            // code animating
            glutIdleFunc(loft);
            //isAnimate = false;
            //cout<<speedBar();
            //cout<<"Ball speed ";
            //cout<<ballSpeedMeter;
			break;
        case 's':
             glutIdleFunc(ballMoveGround);

            break;
        case 'r':
            incx =-55.0;
            incy = -38.0;

            speedBarX=45.0; speedBarY = 57.0;
            ballSpeedMeter = 0;
            glutIdleFunc(NULL);
            break;
        case 'g':
            break;
        case 'w':

            break;
        case 'd':
            //code
            //PlaySound("ball_hit.wav", NULL, SND_ASYNC|SND_FILENAME);

            //glutPostRedisplay();
            break;

		default:
			break;
	}
}

void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:
		    	//down arrow key
			break;
		case GLUT_KEY_UP:
//		    ballUpDown();		// up arrow key
//            glutIdleFunc(ballUpDown);



			break;

		case GLUT_KEY_RIGHT:
		    ballSpeedMeter+=0.001;
		    //speedBarX += 0.01;
		    if (speedBarX <=62.4){
                speedBarX +=0.1;
		    }
		    cout<<" "<< ballSpeedMeter;

		   //glutTimerFunc(25,animate,0);

            //incx+=2.0;
           //glutIdleFunc(animate);
           //glutIdleFunc(ballMoveGround);

			break;
		case GLUT_KEY_LEFT:
		    //incx +=2.0;

            //glutIdleFunc(loft);

			break;

		case GLUT_KEY_PAGE_UP:

			break;
		case GLUT_KEY_PAGE_DOWN:
		    //code
		    glutIdleFunc(NULL);
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}


void tree()
{

glPushMatrix();
glScalef(0.7,0.8,0);
glTranslatef(20, 14, 0);
   //tree 1 triangle
    glPushMatrix();
        glTranslatef(-80, -62, 0);
        glColor3f(0.2446,0.55,0.176);
        glBegin(GL_POLYGON);
            glVertex2f(10, 20);
            glVertex2f(20, 35);
            glVertex2f(30, 20);
        glEnd();
    glPopMatrix();
 //tree 1 triangle end



    //tree 2 triangle
    glPushMatrix();
        glTranslatef(-80, -64, 0);
         glColor3f(0.2446,0.55,0.176);
        glBegin(GL_TRIANGLES);
            glVertex2f(10, 30);
            glVertex2f(20, 40);
            glVertex2f(30, 30);
        glEnd();
    glPopMatrix();
 //tree 2 triangle end


//tree body start
glPushMatrix();
    //glTranslatef(0,-90,0);
    glTranslatef(-72.3, -50, 0);
    glBegin(GL_QUADS);
        glColor3f(0.5,0.3533,0.06);
        //glColor3f(1,0,0);
        glVertex2f(10,10); //0,0
        glVertex2f(10,-10); // 0, 5
        glVertex2f(12,16);
        glVertex2f(15,-10); // 100,5
        glVertex2f(15,10); // 100,0
    glEnd();
glPopMatrix();//tree body end

glPopMatrix();

}


void tree2()
{
	glPushMatrix();
glScalef(0.6,0.5,0);
glTranslatef(-22, -15, 0);
   //tree 1 triangle
    glPushMatrix();
        glTranslatef(-80, -62, 0);
        glColor3f(0.2446,0.55,0.176);
        glBegin(GL_POLYGON);
            glVertex2f(10, 20);
            glVertex2f(20, 35);
            glVertex2f(30, 20);
        glEnd();
    glPopMatrix();
 //tree 1 triangle end



    //tree 2 triangle
    glPushMatrix();
        glTranslatef(-80, -64, 0);
         glColor3f(0.2446,0.55,0.176);
        glBegin(GL_TRIANGLES);
            glVertex2f(10, 30);
            glVertex2f(20, 40);
            glVertex2f(30, 30);
        glEnd();
    glPopMatrix();
 //tree 2 triangle end


//tree body start
glPushMatrix();
    //glTranslatef(0,-90,0);
    glTranslatef(-72.3, -50, 0);
    glBegin(GL_QUADS);
        glColor3f(0.5,0.3533,0.06);
        //glColor3f(1,0,0);
        glVertex2f(10,10); //0,0
        glVertex2f(10,-10); // 0, 5
        glVertex2f(12,16);
        glVertex2f(15,-10); // 100,5
        glVertex2f(15,10); // 100,0
    glEnd();
glPopMatrix();//tree body end

glPopMatrix();
}

void tree3() {


glPushMatrix();
glScalef(0.6,0.5,0);
glTranslatef(180, -15, 0);
   //tree 1 triangle
    glPushMatrix();
        glTranslatef(-80, -62, 0);
        glColor3f(0.2446,0.55,0.176);
        glBegin(GL_POLYGON);
            glVertex2f(10, 20);
            glVertex2f(20, 35);
            glVertex2f(30, 20);
        glEnd();
    glPopMatrix();
 //tree 1 triangle end



    //tree 2 triangle
    glPushMatrix();
        glTranslatef(-80, -64, 0);
         glColor3f(0.2446,0.55,0.176);
        glBegin(GL_TRIANGLES);
            glVertex2f(10, 30);
            glVertex2f(20, 40);
            glVertex2f(30, 30);
        glEnd();
    glPopMatrix();
 //tree 2 triangle end


//tree body start
glPushMatrix();
    //glTranslatef(0,-90,0);
    glTranslatef(-72.3, -50, 0);
    glBegin(GL_QUADS);
        glColor3f(0.5,0.3533,0.06);
        //glColor3f(1,0,0);
        glVertex2f(10,10); //0,0
        glVertex2f(10,-10); // 0, 5
        glVertex2f(12,16);
        glVertex2f(15,-10); // 100,5
        glVertex2f(15,10); // 100,0
    glEnd();
glPopMatrix();//tree body end

glPopMatrix();

}


void cloud() {


int i = 0;
	float angle = 0.0;

//cloud 1 start
glPushMatrix();
glTranslatef(20, 60,0);
    glColor3f(1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;

			glVertex3f (cos(angle) * 10, sin(angle) * 8, 0);

		}
    }
	glEnd();
glPopMatrix(); //cloud  1 end


//cloud 2 start
glPushMatrix();
glTranslatef(10, 60,0);
    glColor3f(1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;

			glVertex3f (cos(angle) * 5, sin(angle) * 6, 0);

		}
    }
	glEnd();
glPopMatrix();
//cloud 2 end


//cloud 3 start
glPushMatrix();
glTranslatef(30, 60,0);
    glColor3f(1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;

			glVertex3f (cos(angle) * 5, sin(angle) * 6, 0);

		}
    }
	glEnd();
glPopMatrix();
//cloud 3 end
//glutPostRedisplay();

}

//Initializes 3D rendering
void init() {
    glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL); //Enable color
	glClearColor(0.7f, 0.9f, 1.0f, 1.0f); //Change the background to sky blue


}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80,	1,	1,	1000.0);
}


void speedBar() {



//    speedBarY +=0.02;
//
//    if(stateForSpeedBar ==0 && speedBarY>=58.3){ stateForSpeedBar =1;}
//    if(stateForSpeedBar ==1 && speedBarY < 40.3 ){stateForSpeedBar =0;}
//
//    if(stateForSpeedBar == 0) {
//        speedBarY+=0.04;
//
//    }
//    else {
//        speedBarY-=0.06;
//
//    }

    glPushMatrix();
        glTranslatef(speedBarX,speedBarY,0);
        glColor3f(1,1.0,1);
            glBegin(GL_LINE_LOOP);
//                glVertex2f(56,80);
//                glVertex2f(56,67);

                glVertex2f(10.3,23);
                glVertex2f(10.3,10);
            glEnd();
        glPopMatrix();



    glutPostRedisplay();



    //return speedBarY;

}



void drawAxes()
{

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);{
        glVertex3f( 100,0,0);
        glVertex3f(-100,0,0);

        glVertex3f(0,-100,0);
        glVertex3f(0, 100,0);

        glVertex3f(0,0, 100);
        glVertex3f(0,0,-100);
    }glEnd();

}

void simple_trans()
{
    //Ground color begin
    glPushMatrix();
    glTranslatef(0,-90,0);
    glBegin(GL_QUADS);
        glColor3f(0.5,0.221,0.035);
        //glColor3f(1,0,0);
        glVertex2f(-100,0); //0,0
        glVertex2f(-100,40); // 0, 5
        glVertex2f(100,40); // 100,5
        glVertex2f(100,0); // 100,0
    glEnd();
    glPopMatrix(); //Ground color END


    //green field 1 begin
    glPushMatrix();
        glTranslatef(0,-85,0);
        glBegin(GL_QUADS);
            glColor3f(0.3718,0.56,0.2072);
            glVertex2f(-100,0);
            //glColor3f(0.3818,0.52,0.2972);
            glVertex2f(-100,39.5);
           // glColor3f(0.2818,0.50,0.1972);
            glVertex2f(100,39.5);
            glVertex2f(100,0);
        glEnd();
    glPopMatrix(); //green field 1 end

    //green field 2 start
    glPushMatrix();
        glTranslatef(0,-82,0);
        glBegin(GL_QUADS);
            glColor3f(0.3146,0.57,0.0912);
            glVertex2f(-100,0);
            glVertex2f(-100,45);
            glVertex2f(100,45);
            glVertex2f(100,0);
        glEnd();
    glPopMatrix(); //green field 2 e

    //First triangle start
    glPushMatrix();
        //glScaled(1.0,1.0,0.0);
        glTranslatef(5,-36.8,0);
        glBegin(GL_TRIANGLES);
            glColor3f(0.6027,0.63,0.5985);
            glVertex2f(15,0);
            glColor3f(0.6127,0.60,0.6985);
            glVertex2f(40,35);
            //glColor3f(0.9030,0.63,0.2985);
            glVertex2f(65,0);
        glEnd();
    glPopMatrix();     //First triangle end

    //Second triangle start
    glPushMatrix();
        //glScaled(1.0,1.0,0.0);
        glTranslatef(-40,-36.8,0);
        glBegin(GL_TRIANGLES);
            glColor3f(0.6027,0.63,0.5985);
            glVertex2f(20,0);
            glColor3f(0.6127,0.60,0.6985);
            glVertex2f(40,20);
            //glColor3f(0.9030,0.63,0.2985);
            glVertex2f(60,0);
        glEnd();
    glPopMatrix(); //Second triable end

    //Third triable start
    glPushMatrix();
        //glScaled(1.0,1.0,0.0);
        glTranslatef(-120,-36.8,0);
        glBegin(GL_TRIANGLES);
            glColor3f(0.6027,0.63,0.5985);
            glVertex2f(30,0);
            glColor3f(0.6127,0.60,0.6985);
            glVertex2f(40,40);
            //glColor3f(0.9030,0.63,0.2985);
            glVertex2f(70,0);
        glEnd();
    glPopMatrix(); //Third triangle ends



    //start of speed box
    glPushMatrix();
        glColor3f(1,0.59,0.26);
        glBegin(GL_QUADS);
            glVertex2f(55,70);
            glVertex2f(73,70);
            glVertex2f(73,77);
            glVertex2f(55,77);
        glEnd();
    glPopMatrix();


}

void hole() {


    //hole start
    glPushMatrix();
   // glColor3f(0.31,0.1491,0.0341);
    //glRectf(90,-10,-90,0);
        glTranslatef(13.5,-46,0);
        glBegin(GL_QUADS);
            glColor3f(0.27,0.1409,0.0486);
            glVertex2f(39.8,0);
            glVertex2f(39.8,5);
            glVertex2f(49.5,5);
            glVertex2f(49.5,0);
        glEnd();
    glPopMatrix();

    //hole bar
    glPushMatrix();
        glTranslatef(14,0,0);
        glBegin(GL_QUADS);
            glColor3f(0.27,0.1409,0.0486);
            glVertex2f(41,-50);
            glVertex2f(41,-71.7);
            glVertex2f(47,-71.7);
            glVertex2f(47,-50);
        glEnd();
    glPopMatrix();

    // Flag
    glPushMatrix();
        glTranslatef(16.7,-45,0);

        glBegin(GL_LINE_LOOP);
            glColor3f(0.93,0.806, 0.465);
            glVertex2f(42,0);
            glVertex2f(42,20);
        glEnd();

        glBegin(GL_TRIANGLES);
//        glColor3f(0.93,0.806, 0.465);
            glColor3f(0.9637,0.98, 0.0);
            glVertex2f(42,20);
            glVertex2f(42,15);
            glVertex2f(44,18);
        glEnd();

    glPopMatrix(); //flag end


}


void ball(float radius_x, float radius_y) {

    int i = 0;
	float angle = 0.0;
	glPushMatrix();

    glTranslatef(incx,incy,0);
    glRotatef(angle2, 1.0,1.0,0);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;

			glColor3f(1, 0.978, 0.67/i);

			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);

		}

    }
	glEnd();
    glPopMatrix();

}

void loft() {
    amp = 0.09;
    incx += 0.09;
//    incy += 0.04;


    if( stateForLoft == 0 && incx >=5){ //>=-20 chilo
            //upore cond a incx >=-30 dile flat vabe jabe
        stateForLoft = 1;

          /*** eta holo ekbar bounce hoye x axis shoja giye hole a porbe upore incx>=-20 korte hobe age**/
//        if ( incx >=57.5) {
//            incx = 57.5;
//            //incy-=0.2;
//            if (incy >= -68 ){ // incy >= -68 chilo age
//                incy-=0.01;
//
//            }
//            //cout<<"y: "<<incy;
//            score = 5;
//
//        }

        /** nicher cond holo ball hole cross kore chole jabe jokhon amp =0.07 *****/
//
//         if ( incx >=-40.5 && incx <= 55.5 ){
//            incx +=0.02;
//
//        }
        /** end of ball hole cross kore chole jabe jokhon amp =0.07 *****/


       /**** nicher ta  ball lofted hoye hole a giye porbe ***/
        if ( incx >= 56.5) {
             incx = 57.5;
            //incy-=0.2;
            if (incy >= -68 ){ // incy >= -68 chilo age
                incy-=0.06;

            }
            //cout<<"y: "<<incy;
            score = 5;
        }
        /****end of ball lofted hoye hole a giye porbe ***/


    /*** nicher eta holo ekbar bounce hoye x axis shoja giye hole a porbe**/
    }
    if (stateForLoft==1 && incy < ballMargin){
        stateForLoft = 0;
    }

    if (stateForLoft ==0){
            //incy+=0.05;
            incy +=0.05*sin(incx/-20); //-20 te loft okay //0.05* okay
            //amp = 0.07 korle ball hole cross kore chole jabe

           if (incy <=-68){
               incy -=0.07;
               incy = -68; //ball ta hole er moddhe -68 pos a giye atkabe
            }


    }
    else {
        incy-=0.04;
    }



    //glutPostRedisplay();

}

void ballMoveGround() {

    incx +=ballSpeedMeter;

    if ( (ballSpeedMeter> 0 && ballSpeedMeter <= 0.004) && incx >= -40.5){
        incx = -40.5;
    }

    else if ( (ballSpeedMeter>0.004 && ballSpeedMeter <= 0.006) && incx>=-30.0) {
        restart = true;
        incx = -30.0;
        int v = MessageBox(hwnd,"hello","GAME OVER",MB_YESNO);
        if (v == IDYES){
            DestroyWindow(hwnd);

        //cout<<"mess "<<v;
        //MessageBox(NULL, L"Description\nline2", L"Info", MB_OK | MB_ICONEXCLAMATION);
	}

    }
    else if ( (ballSpeedMeter>0.006 && ballSpeedMeter <= 0.009) && incx>=-5.0) {
        incx = -5.0;
    }
    else if ( (ballSpeedMeter>0.009 && ballSpeedMeter <= 0.02) && incx>=15.0) {
        incx = 15.0;
    }

    else if ( (ballSpeedMeter>0.02 && ballSpeedMeter <= 0.04) && incx>=35.0) {
        incx = 35.0;

    }
    else if ( (ballSpeedMeter>0.03 && ballSpeedMeter <= 0.05) && incx>=53.4) {
        incx = 53.3;
    }
    else if ( (ballSpeedMeter>0.05 && ballSpeedMeter <= 0.2) && incx>=57.2) {
        incx =57.2;

        if( incy >= -68)
            incy -=0.08;
            score = 5;
             //PlaySound("hole.wav", NULL, SND_ASYNC|SND_FILENAME);
    }
//    else if(ballSpeedMeter > 0.2 && incx>=57.2) {
//            incx =56.0;
//    }

//    else if( (ballSpeedMeter>0.08 && ballSpeedMeter <= 0.2) && incx>= 57.2){
//        incx =57.2;
//        score = 5;
//        if( incy >= -68)
//            incy -=0.07;
//
//    }



//    else if ( incx>=57.5) {
//        incx =57.5;
//        if( incy >= -68)
//            incy -=0.04;
//        score = 5;
//
//    }


    //glutPostRedisplay();

}




void stick() {

    glPushMatrix();
        glRotatef(stickRoate,1,0,0);
        glTranslatef(-20,1.8,0);
        glBegin(GL_QUADS);
        glColor3f(0.9312,0.97,0.9622);
            glVertex2f(-40,-5);
            glVertex2f(-45,-40);
            glVertex2f(-44.2,-40);
            glVertex2f(-39.5,-5);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.9312,0.97,0.9622);
            glVertex2f(-45,-40);
            glVertex2f(-45,-42);
            glVertex2f(-42,-41);
            glVertex2f(-42,-40);
        glEnd();

    glPopMatrix();

}


void display1(){

	//clear the display
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(0,0,100,	0,0,0,	0,1,0);

	glMatrixMode(GL_MODELVIEW);



	//drawAxes();
    ball(2,3.1);
	//drawGrid();
	//tree2(6, 14);
	//hill();
	//stick();
	hole();
	speedBar();
	scoretext("Score: ");
	outputText("Level 1", -2, 78);
	outputText("Speed", 58,62);
	tree();
	tree2();
	tree3();
//	cloud(10,8,20,50);
//	cloud(5,6,10,50);
//	cloud(5,6,30,50);
	cloud();
	glPushMatrix();
        glScalef(0.8,0.8,0);
        glTranslatef(-70, 10,0);
        cloud();
    glPopMatrix();
    simple_trans();


    //ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
	glFlush();
}



void display2() {


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(0,0,100,	0,0,0,	0,1,0);

	glMatrixMode(GL_MODELVIEW);


	hole();
    simple_trans();

    glutSwapBuffers();
	glFlush();

}


int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();
	//PlaySound("theme.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


//    cout<< score;
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glEnable(GL_COLOR_MATERIAL);
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);

    instructions();

    glutDisplayFunc(display1);

   // glutDisplayFunc(display2);	//display callback function





	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	glutReshapeFunc(handleResize);
	//glutMouseFunc(mouseListener);
    //glutIdleFunc(speedBar);

    //count<<speedBar();
	glutMainLoop();		//The main loop of OpenGL
    //glutTimerFunc(25,animate,0);

	return 0;
}









