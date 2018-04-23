//
//  main.cpp
//  cg3-2
//
//  Created by merarli on 2018/04/23.
//  Copyright © 2018年 merarli. All rights reserved.
//

#include <GLUT/glut.h>
#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <math.h>

#define KEY_ESC 27
#define M_PI 3.1416

//nは頂点の個数,rは半径,sizeは1を最大として0より大きい,shiftX,shiftYは中心(0,0)からの移動量
void takaku(int n, int r, double size,double shiftX,double shiftY){
    n = n + 1;
    
    double x;
    double y;
    double x2;
    double y2;
    double x1;
    double y1;
    double jusinX;
    double jusinY;
    
    double radian = 2 * M_PI / n;
    
    //重心を計算する
    for (int i = 0; i <= n; i++ ) {
        x = cos( radian * i ) * r + shiftX;
        y = sin( radian * i ) * r + shiftY;
        
        jusinX = jusinX + x;
        jusinY = jusinY + y;
        
        jusinX = jusinX / n;
        jusinY = jusinY / n;
    }
    
    for (int i = 0; i <= n; i++ ) {
        x = cos( radian * i ) * r;
        y = sin( radian * i ) * r;
        
        if( i % 2 == 0 ){
            x1 = x;
            y1 = y;
        }else{
            x2 = x;
            y2 = y;
        }

        glVertex2f((x1+shiftX)*size, (y1+shiftY)*size);
        glVertex2f((x2+shiftX)*size, (y2+shiftY)*size);
        glVertex2d(jusinX, jusinY);
    }
    
    glEnd();
    glFlush(); //命令の実行

}

void myKeyboard(unsigned char key, int x, int y){
    //押されたキーがESCキーならプログラム終了
    if(key == KEY_ESC)
        exit(0);
}


void display( void ){
    //ウィンドウの塗りつぶし
    glClear(GL_COLOR_BUFFER_BIT);
    
    //紫で塗りつぶし
    glColor3d( 0.5, 0.0, 1.0 );
    glBegin(GL_TRIANGLES);
    takaku(10, 1.0,0.3,-0.7,-0.7);
    
    //オレンジで塗りつぶし
    glColor3d( 1.0, 0.5, 0.0 );
    glBegin(GL_TRIANGLES);
    takaku(8, 1.0,0.4,0.8,0.8);
    
    
    
}
void myInit(char *progname){
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(170,100);
    glutCreateWindow(progname);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutKeyboardFunc(myKeyboard);
}

int main( int argc, char *argv[] ){
    glutInit(&argc, argv);
    myInit(argv[0]);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


