//
//  main.cpp
//  cg3-1
//
//  Created by merarli on 2018/04/23.
//  Copyright © 2018年 merarli. All rights reserved.
//


#include <GLUT/glut.h>
#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#define KEY_ESC 27

void myKeyboard(unsigned char key, int x, int y){
    //押されたキーがESCキーならプログラム終了
    if(key == KEY_ESC)
        exit(0);
    
}

void display( void ){
    //ウィンドウの塗りつぶし
    glClear(GL_COLOR_BUFFER_BIT);
    
    //赤色で塗りつぶし
    glColor3d( 1.0, 0.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2d(-0.5, -0.5);    //点の位置を設定
    glVertex2d(0.5, 0.5);
    glVertex2d(-0.5, 0.5);
    glEnd();
    glFlush(); //命令の実行
    
    //緑色で塗りつぶし
    glColor3d( 0.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2d(0.9, 0.9);    //点の位置を設定
    glVertex2d(0.8, 0.8);
    glVertex2d(1.0, -1.0);
    glEnd();
    glFlush(); //命令の実行
    
}
void myInit(char *progname){
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(170,100);
    glutCreateWindow(progname);
    glClearColor(0.0, 0.0, 0.0, 1.0);
//    glutKeyboardFunc(myKeyboard);
}

int main( int argc, char *argv[] ){
    glutInit(&argc, argv);
    myInit(argv[0]);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


