#include <ostream>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <unistd.h>
#include <vector>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glext.h>
#endif



//#include "vertex.h"
//#include "face.h"
#include "aw.h"
#include "camera.h"


//global variables
std::vector<aw_t*> the_objects;
std::vector<aw_t*>::iterator pit;
aw_t   *awp;
//camera object 
camera_t camera;

// forward declarations of functions
int	main(int argc, char *argv[]);

void	keyboard(unsigned char key, int x, int y);
void	display();
void	resize(int w, int h);
void	idle();
void	timer(int);
void	initializeGL();
void	cleanup(void);


void cleanup(void)
{
  //clean up

  for(pit= the_objects.begin(); pit != the_objects.end(); pit= the_objects.erase(pit))
   if(*pit != NULL) delete *pit;
  std::cout<<"the_objects vector has been cleared...\n";
  std::cout<<"Ok we are finally done. \n\n";
  
}


int main(int argc, char *argv[])
{
//	point_t* pointp;  

  // register onexit
  atexit(cleanup);

  // set up GLUT
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutCreateWindow("OpenGL2.0 demo");

  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  //glutIdleFunc(idle);
  //glutIdleFunc(idle);
  //glutTimerFunc(1000,timer,1000);

  // set up GL
  initializeGL();
  
  while(!std::cin.eof()){
    std::cin>> (awp= new aw_t() );
   // if(std::cin.good())
    the_objects.push_back(awp);

    std::cout<<awp;
  }
/*
  for(int i=0; i <(int) the_objects.size(); i++){
    std::cout<< "x: "<< (*the_objects[i])[0]<< "\ty: "<< (*the_objects[i])[1] <<std::endl;
  }
*/
  // for(pit= the_objects.begin(); pit != the_objects.end(); pit= the_objects.erase(pit))
  //   if(*pit != NULL) delete *pit;
//  std::cout<<"the_objects vector has been cleared...\n";
  
  std::cout<< "Printing object center\n";
  awp->center();




  // and all the rest happens in the display function...
  glutMainLoop();

  return 0;
}
/*void timer(int dt)
{
  glutTimerFunc(dt, timer, dt);
}*/
void resize(int w, int h)
{
  glViewport(0,0,w,h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,w,0.0,h);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
	int modifiers = glutGetModifiers();

  if(modifiers & GLUT_ACTIVE_SHIFT)
    std::cerr << "SHIFT" << std::endl;

  if(modifiers & GLUT_ACTIVE_CTRL)
    std::cerr << "CTRL" << std::endl;

  if(modifiers & GLUT_ACTIVE_ALT)
    std::cerr << "ALT" << std::endl;

  switch(key) {
    // translations
    case 'h':
      camera.truck(-0.5);
      std::cout<<"pressing h, trucking left.\n";
      break;
    case 'j':
      camera.pedestal(-0.5);
      std::cout<<"pressing j, pedestal down.\n";
      break;
    case 'k':
      camera.pedestal(.5);
      break;
    case 'l':
      camera.truck(.5);
      break;
    case 'i':
      camera.dolly(.5);
      break;
    case 'm':
      camera.dolly(-.5);
      break;
    // rotations
    case 'H':
      camera.pan(-.5);
      break;
    case 'J':
      camera.pitch(-.5); 
      break;
    case 'K':
      camera.pitch(.5); 
      break; 
    case 'L':
      camera.pan(.5); 
      break;
    case 'I':
      camera.tilt(.5);
      break;
    case 'M':
      camera.tilt(-.5);
      break;
    case 's':
      for(int h=0; h< (int) the_objects.size(); h++)
      {  (* the_objects[h]).rotate(1.0, 0.0, 0.0); }    
      break;
    case 'd':
      for(int h=0; h< (int) the_objects.size(); h++)
      {  (* the_objects[h]).rotate(0.0, 1.0, 0.0); }    
      break;
    case 'f':
      for(int h=0; h< (int) the_objects.size(); h++)
      {   (*the_objects[h]).rotate(0.0, 0.0, 1.0); }  
      break;
    case 'S':
      for(int h=0; h< (int) the_objects.size(); h++)
      {   (*the_objects[h]).rotate(-1.0, 0.0, 0.0); }    
      break;
    case 'D':
      for(int h=0; h< (int) the_objects.size(); h++)
      {   (*the_objects[h]).rotate(0.0,-1.0, 0.0); }    
      break;
    case 'F':
      for(int h=0; h< (int) the_objects.size(); h++)
      {   (*the_objects[h]).rotate(0.0, 0.0,-1.0); }    
      break;
    case 'q':
    case 'Q':
    case 27:
   
      // clean up
      exit(0);
      break;
  }

  glutPostRedisplay();
}

void initializeGL()
{
  std::cerr << "GL: ";
  std::cerr << glGetString(GL_VERSION);
  std::cerr << " ";
  std::cerr << glGetString(GL_VENDOR);
  std::cerr << std::endl;

  // specify clear color; (0.3,0.4,0.6,1.0) is a nice "slate blue"
  glClearColor( 0.3, 0.4, 2.0, 1.0 );

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  //setting up lights
  GLfloat light0_pos[4] = { -50.0, 0.0, 0.0, 0.0};
  GLfloat light0_color[4] ={ .1, .1, .7, 0.25 };

  GLfloat light1_pos[4] = { -0.0, 50.0, 0.0, 0.0};
  GLfloat light1_color[4] ={ .1, .81, .17, 0.55 };
  
  GLfloat light2_pos[4] = { 50.0, 0.0, 0.0, 0.0};
  GLfloat light2_color[4] ={ .5, .7, .3, 0.25 };
  
  glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_color);

  glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_color);

  glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);
  glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_color);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);
}

void display() 
{
//	int			ww = glutGet(GLUT_WINDOW_WIDTH);
//	int			wh = glutGet(GLUT_WINDOW_HEIGHT);
//	int			sw = glutGet(GLUT_SCREEN_WIDTH);
//	int			sh = glutGet(GLUT_SCREEN_HEIGHT);

  // window width x height is window
//std::cerr << "ww = " << ww << ", wh = " << wh << std::endl;
  // screen width x height is entire screen
//std::cerr << "sw = " << sw << ", sh = " << sh << std::endl;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //gluOrtho2D(0,ww,0,wh);

  gluPerspective(90, 1.0, 1.0, 1000.0); 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(camera.pos[0], camera.pos[1], camera.pos[2], 
	camera.ref[0],camera.ref[1], camera.ref[2],
	camera.vup[0], camera.vup[1], camera.vup[2] );

  glDrawBuffer(GL_BACK);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  for(int i=0; i< (int) the_objects.size(); i++)
  {
     awp=the_objects[i];
     glTranslatef( (awp->oc[0]), (awp-> oc[1]), (awp -> oc[2]));
     glPushMatrix();

     glRotatef(awp -> rotx, 1, 0,0); 
     glRotatef(awp -> roty, 0, 1, 0); 
     glRotatef(awp -> rotz, 0 ,0, 1); 
     for(int f=0; f <(int) awp->faces.size(); f++)
     { 
       glNormal3f(awp->faces[f]->norm[0], awp->faces[f]->norm[1], awp->faces[f]->norm[2]);
       glBegin(GL_POLYGON); 
       for(int v=0; v<(int) awp->faces[f]->vin.size(); v++)
       {
         int vin = awp ->faces[f]->vin[v];
         glVertex3f((*awp->verts[vin-1])[0], (*awp->verts[vin-1])[1],(*awp->verts[vin-1])[2]);
       }
       glTranslatef( -awp->oc[0], -awp->oc[1], -awp ->oc[2]);
       glPopMatrix();
       glEnd();
     }
  }
 /* glBegin(GL_QUADS);
  for(int i =0; i< (int) the_objects.size(); i++){
    glVertex3f((*the_objects[i])[0], (*the_objects[i])[1], (*the_objects[i])[2]);
  }*/

  glutSwapBuffers();
  glFlush();
}

void idle()
{
  std::cerr << "in idle()" << std::endl;

  // force display(), so that the object keeps moving
  glutPostRedisplay();
}

void timer(int dt)
{
  std::cerr << "in timer()" << std::endl;

  // force display(), so that the object keeps moving
  glutPostRedisplay();

  // sleep for dt ms (simulating sampling rate)
  glutTimerFunc(dt,timer,dt);
}
