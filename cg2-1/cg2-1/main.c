//
//  main.c
//  cg2-1
//
//  Created by merarli on 2018/04/16.
//  Copyright © 2018年 merarli. All rights reserved.
//

#include <stdio.h>


#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

void display(void){
    //ウィンドウの塗りつぶし
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush(); //命令の実行
}

void myInit(char *progname){
    //ディスプレイの表示モード設定
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(progname);
    glClearColor(0.0, 0.0, 1.0, 1.0);
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    myInit(argv[0]); //初期化処理
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

