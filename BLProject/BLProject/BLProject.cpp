// BLProject.cpp

#include "stdafx.h"
#include <iostream>
#include <gl\GL.h>

using namespace std;

int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

	glutInitWindowSize(800,600);
	glutCreateWindow("BLProject");

	glutMainLoop();

    return 0;
}
