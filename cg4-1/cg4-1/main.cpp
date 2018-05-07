//
//  main.cpp
//  cg4-1
//
//  Created by merarli on 2018/05/07.
//  Copyright © 2018年 merarli. All rights reserved.
//

#include <GLUT/glut.h>
#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <math.h>
#define KEY_ESC 27

void myKeyboard( unsigned char key, int x, int y ) {
    //押されたキーがESCキーならプログラム終了
    if(key == KEY_ESC)
        exit(0);
}

void display() {
    double a=0.25, z1=-2.0;
    
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3d(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3d(-a, -a, z1);
    glVertex3d(a, -a, z1);
    glVertex3d(a, a, z1);
    glVertex3d(-a, a, z1);
    glEnd();
    
    
    
    //青色のしかく
    glTranslated(0.2,0.1,0.2);
    glRotated(30,0,0,1);
    glScaled(2,0.5,1);
    
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    
    glTranslated(0.2,0.1,0.2);
    glRotated(0,0,0,30);
    glScaled(2,0.5,1);
    
    glVertex3d(-a, -a, z1);
    glVertex3d(a, -a, z1);
    glVertex3d(a, a, z1);
    glVertex3d(-a, a, z1);
    

    
    glEnd();
    
    glFlush();
}

void myInit( char *progname ) {
    int width=500, height=500;
    double aspect = (double)width/(double)height;
    
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0,0);
    glutCreateWindow(progname);
    
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutKeyboardFunc(myKeyboard);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspect, 0.1, 7.0);
}

int main( int argc, char *argv[] ){
    glutInit(&argc, argv);
    myInit(argv[0]);
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
