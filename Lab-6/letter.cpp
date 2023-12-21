#include "letter.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <windows.h>

GLfloat letter::vertexData[vertices][3] =
{
        {-0.1f, 0, 0}, //0
        {-0.1f, 0, 0.25f},
        {0.1f, 0, 0.25f},
        {0.1f, 0, 0},

        {-0.1f, 1.5f, 0}, //4
        {-0.1f, 1.5f, 0.25},
        {0.1f, 1.5f, 0.25f},
        {0.1f, 1.5f, 0},

        {0.0f, 1.5f, 0.0f}, //8
        {0, 1.5f, 0.25f},
        {0, 1.25f, 0.25f},
        {0, 1.25f, 0},

        {0.6f, 1.5f, 0},//12
        {0.6f, 1.5f, 0.25f},
        {0.6f, 1.25f, 0.25f},
        {0.6f, 1.25f, 0},

        {0.6f, 1.25f, 0.25f},//16
        {0.6f, 1.5f, 0.25f},
        {0.6f, 1.5f, 0},
        {0.6f, 1.25f, 0},

        {0.95f, 1.1f, 0.25f},//20
        {0.95f, 1.35f, 0.25f},
        {0.95f, 1.35f, 0},
        {0.95f, 1.1f, 0},

        {0.95f, 1.35f, 0},//24
        {0.95f, 1.35f, 0.25f},
        {0.75f, 1.35f, 0.25f},
        {0.75f, 1.35f, 0},

        {0.95f, 0.95f, 0},//28
        {0.95f, 0.95f, 0.25f},
        {0.75f, 0.95f, 0.25f},
        {0.75f, 0.95f, 0},

        {0.6f, 0.55f, 0},//32
        {0.6f, 0.55f, 0.25f},
        {0.6f, 0.8f, 0.25f},
        {0.6f, 0.8f, 0},

        {0.0f, 0.55f, 0},//36
        {0.0f, 0.55f, 0.25f},
        {0.0f, 0.8f, 0.25f},
        {0.0f, 0.8f, 0},

        {-0.6f, 1.5f, 0},//40
        {-0.6f, 1.5f, 0.25f},
        {-0.6f, 1.25f, 0.25f},
        {-0.6f, 1.25f, 0},

        {-0.6f, 1.25f, 0.25f},//44
        {-0.6f, 1.5f, 0.25f},
        {-0.6f, 1.5f, 0},
        {-0.6f, 1.25f, 0},

        {-0.95f, 1.1f, 0.25f},//48
        {-0.95f, 1.35f, 0.25f},
        {-0.95f, 1.35f, 0},
        {-0.95f, 1.1f, 0},

        {-0.95f, 1.35f, 0},//52
        {-0.95f, 1.35f, 0.25f},
        {-0.75f, 1.35f, 0.25f},
        {-0.75f, 1.35f, 0},

        {-0.95f, 0.95f, 0},//56
        {-0.95f, 0.95f, 0.25f},
        {-0.75f, 0.95f, 0.25f},
        {-0.75f, 0.95f, 0},

        {-0.6f, 0.55f, 0},//60
        {-0.6f, 0.55f, 0.25f},
        {-0.6f, 0.8f, 0.25f},
        {-0.6f, 0.8f, 0},

        {0.0f, 0.55f, 0},//64
        {0.0f, 0.55f, 0.25f},
        {0.0f, 0.8f, 0.25f},
        {0.0f, 0.8f, 0},
};

void letter::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0,0,0,0); // цвет для очистки буфера изображения - здесь просто фон окна
    glEnable(GL_DEPTH_TEST);  // устанавливает режим проверки глубины пикселей
    glShadeModel(GL_FLAT);    // отключает режим сглаживания цветов
    glEnableClientState(GL_VERTEX_ARRAY); // активизация массива вершин
}

letter::letter(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setGeometry(400,200,800,600);

    // начальные значения
    xRot=0; yRot=0; zRot=0; zTra=-1; nSca=1;

    // передает дальше указатель на объект pwgt

    getVertexArray();
    getIndexArray();
}

void letter::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION); // устанавливает текущей проекционную матрицу
    glLoadIdentity();            // присваивает проекционной матрице единичную матрицу

    GLfloat ratio=(GLfloat)nHeight/(GLfloat)nWidth; // отношение высоты окна виджета к его ширине

    // мировое окно
    if (nWidth>=nHeight)
       glOrtho(-1.0/ratio, 1.0/ratio, -1.0, 1.0, -5.0, 5.0); // параметры видимости ортогональной проекции
    else
       glOrtho(-1.0, 1.0, -1.0*ratio, 1.0*ratio, -5.0, 5.0); // параметры видимости ортогональной проекции
    // плоскости отсечения (левая, правая, верхняя, нижняя, передняя, задняя)

    // glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0); // параметры видимости перспективной проекции
    // плоскости отсечения (левая, правая, верхняя, нижняя, ближняя, дальняя)

    // поле просмотра
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void letter::paintGL()
{
    glClearColor(1,1,1,0); // цвет фона
    glClear(GL_COLOR_BUFFER_BIT); // окно виджета очищается текущим цветом очистки
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очистка буфера изображения и глубины
    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования
    glLoadIdentity();           // загружает единичную матрицу моделирования
    // последовательные преобразования
    glScalef(nSca, nSca, nSca);        // масштабирование
    glTranslatef(0.0f, zTra, 0.0f);  // трансляция
    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
    drawAxis();
    double e=0,r=0,t=0;
    colour.getRgbF(&e,&r,&t,nullptr);
    glColor4f(e, r, t, 0.0f);
    if(check==1)
    draw_xy_projection();
    else if(check==2)
    draw_xz_projection();
    else if(check==3)
    draw_zy_projection();
    else if(check==4)
    draw_scaling();
    else if(check==5)
    draw_transfer();
    else if(check==6)
    draw_rotation_x();
    else if(check==7)
    draw_rotation_y();
    else if(check==8)
    draw_rotation_z();
    else if(check==9)
    {
        getVertexArray();
        drawFigure();
    }

    QFont tmpfont;
            tmpfont.setFamily("Segoe UI");
            tmpfont.setPointSize(10);
            tmpfont.setBold(false);
            glColor3f(0,0,0);
            glColor3f(0,0,0);
            glColor3f(0,0,0);

}

void letter::mousePressEvent(QMouseEvent* pe)
{
   // при нажатии пользователем кнопки мыши переменной ptrMousePosition будет
   // присвоена координата указателя мыши
   ptrMousePosition = pe->pos();
}

void letter::mouseReleaseEvent(QMouseEvent* pe)
{
   // некоторые функции, которые должны выполняться при отжатии клавиши мыши
}

void letter::mouseMoveEvent(QMouseEvent* pe)
{
   xRot += 1/M_PI*(GLfloat)(pe->y()-ptrMousePosition.y());//height(); // вычисление углов поворота
   yRot += 1/M_PI*(GLfloat)(pe->x()-ptrMousePosition.x());//width();
   ptrMousePosition = pe->pos();
   update();
}

void letter::wheelEvent(QWheelEvent* pe)
{
   if ((pe->angleDelta().y())>0) scale_plus(); else if ((pe->angleDelta().y())<0) scale_minus();

   update();
}

void letter::keyPressEvent(QKeyEvent* pe) // нажатие определенной клавиши
{
   switch (pe->key())
   {
      case Qt::Key_Plus:
         scale_plus();     // приблизить сцену
      break;

      case Qt::Key_Equal:
         scale_plus();     // приблизить сцену
      break;

      case Qt::Key_Minus:
         scale_minus();    // удалиться от сцены
      break;

      case Qt::Key_W:
         rotate_up();      // повернуть сцену вверх
      break;

      case Qt::Key_S:
         rotate_down();    // повернуть сцену вниз
      break;

      case Qt::Key_A:
        rotate_left();     // повернуть сцену влево
      break;

      case Qt::Key_D:
         rotate_right();   // повернуть сцену вправо
      break;

      case Qt::Key_Z:
         translate_down(); // транслировать сцену вниз
      break;

      case Qt::Key_X:
         translate_up();   // транслировать сцену вверх
      break;

      case Qt::Key_Space:
         defaultScene();   // возвращение значений по умолчанию
      break;

      case Qt::Key_Escape:
         this->close();    // завершает приложение
      break;
   }

   update();
}


void letter::scale_plus()
{
   nSca = nSca*1.1;
}

void letter::scale_minus()
{
   nSca = nSca/1.1;
}

void letter::rotate_up()
{
   xRot += 1.0;
}

void letter::rotate_down()
{
   xRot -= 1.0;
}

void letter::rotate_left()
{
   zRot += 1.0;
}

void letter::rotate_right()
{
   zRot -= 1.0;
}

void letter::translate_down()
{
   zTra -= 0.05;
}

void letter::translate_up() {
   zTra += 0.05;
}

void letter::defaultScene() // наблюдение сцены по умолчанию
{
   xRot=-90; yRot=0; zRot=0; zTra=0; nSca=1;
}

void letter::drawAxis()
{
    glLineWidth(3.0f); // устанавливаю ширину линии приближённо в пикселях
    // до вызова команды ширина равна 1 пикселю по умолчанию

    glColor4f(1.00f, 0.00f, 0.00f, 1.0f); // устанавливается цвет последующих примитивов
    // ось x красного цвета
    glBegin(GL_LINES); // построение линии
       glVertex3f( 10.0f,  0.0f,  0.0f); // первая точка
       glVertex3f(-10.0f,  0.0f,  0.0f); // вторая точка
    glEnd();

    QColor halfGreen(0, 128, 0, 255);
     glColor3i(0, 128, 0);
    glBegin(GL_LINES);
       // ось y зеленого цвета
       glVertex3f( 0.0f,  10.0f,  0.0f);
       glVertex3f( 0.0f, -10.0f,  0.0f);

       glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
       // ось z синего цвета
       glVertex3f( 0.0f,  0.0f,  10.0f);
       glVertex3f( 0.0f,  0.0f, -10.0f);

        glColor4f(0.00f, 0.00f, 0.00f, 0.0f);
       for (float i = -10; i < 10; i+=0.25){
           float k = 20.0;
           glBegin(GL_LINES);
           glVertex3f(i, -1.0 / k, 0.0f);
           glVertex3f(i, 1.0 / k, 0.0f);
           glVertex3f(-1.0 / k, i, 0.0f);
           glVertex3f(1.0 / k, i, 0.0f);
           glVertex3f( 0.0f, 1.0 / k, i);
           glVertex3f( 0.0f, -1.0 / k, i);
       }

    glEnd();
}

void letter::getIndexArray()
{
    setQuad(0, 0, 1, 2, 3);
    setQuad(1, 0, 1, 5, 4);
    setQuad(2, 8, 9, 10, 11);
    setQuad(3, 12, 13, 14, 15);
    setQuad(4, 1, 2, 6, 5);
    setQuad(5, 2, 3, 7, 6);
    setQuad(6, 3, 0, 4, 7);
    setQuad(7, 8, 9, 13, 12);
    setQuad(8, 9, 10, 14, 13);
    setQuad(9, 10, 11, 15, 14);
    setQuad(10, 11, 8, 12, 15);
    setQuad(11, 16, 19, 23, 20);
    setQuad(12, 18, 17, 21, 22);
    setQuad(13, 16, 17, 21, 20);
    setQuad(14, 18, 19, 23, 22);
    setQuad(15, 20, 21, 22, 23);
    setQuad(16, 24, 25, 29, 28);
    setQuad(17, 25, 26, 30, 29);
    setQuad(18, 26, 27, 31, 30);
    setQuad(19, 27, 24, 28, 31);
    setQuad(20, 31, 35, 34, 30);
    setQuad(21, 30, 34, 33, 29);
    setQuad(22, 29, 33, 32, 28);
    setQuad(23, 28, 32, 35, 31);
    setQuad(24, 32, 36, 37, 33);
    setQuad(25, 33, 37, 38, 34);
    setQuad(26, 34, 38, 39, 35);
    setQuad(27, 35, 39, 36, 32);


    setQuad(28, 2, 3, 7, 6);
    setQuad(29, 3, 0, 4, 7);

    setQuad(30, 41, 40, 4, 5);
    setQuad(31, 41, 40, 43, 42);
    setQuad(32, 40, 43, 11, 8);
    setQuad(33, 41, 42, 10, 9);
    setQuad(34, 42, 43, 11, 10);

    setQuad(35, 40, 50, 51, 43);
    setQuad(36, 41, 49, 48, 42);
    setQuad(37, 51, 48, 42, 43);
    setQuad(38, 50, 40, 41, 49);

    setQuad(39, 52, 55, 59, 56);
    setQuad(40, 53, 54, 58, 57);
    setQuad(41, 54, 55, 59, 58);
    setQuad(42, 52, 53, 56, 57);

    setQuad(43, 63, 67, 64, 60);
    setQuad(44, 63, 62, 66, 67);
    setQuad(45,62,61,65,66);
    setQuad(46,60,61,65,64);

    setQuad(47,56,60,63,59);
    setQuad(48,59,58,62,63);
    setQuad(49,57,58,62,61);
    setQuad(50, 56, 57, 61, 60);

 }

void letter::getVertexArray()
{
    if(VertexArray == nullptr)
    {
        VertexArray = new GLfloat*[vertices];
        for(int i = 0; i < vertices; i++)
        {
            VertexArray[i] = new GLfloat[3];
            for(int j = 0; j < 3; j++)
            {
                VertexArray[i][j] = vertexData[i][j];
            }
        }
    }

    else
    {
        for(int i = 0; i < vertices; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                VertexArray[i][j] = vertexData[i][j];
            }
        }
    }
}

void letter::setVertex(int idx, float k, float x, float y, float z)
{
    VertexArray[idx][0] = x * k;
    VertexArray[idx][1] = y * k;
    VertexArray[idx][2] = z * k;
}

void letter::setTriangle(int idx, int x1, int x2, int x3)
{
    IndexArray[idx][0] = x1;
    IndexArray[idx][1] = x2;
    IndexArray[idx][2] = x3;
}

void letter::setQuad(int idx, int x1, int x2, int x3, int x4)
{
    IndexArray[idx][0] = x1;
    IndexArray[idx][1] = x2;
    IndexArray[idx][2] = x3;
    IndexArray[idx][3] = x4;
}

void letter::draw_rotation_z()
{
    GLfloat conv[3][3] ;
    conv[0][0]=cos(angle*(M_PI/180.0));;
    conv[0][1]=-sin(angle*(M_PI/180.0));;
    conv[0][2]=0;

    conv[1][0]=sin(angle*(M_PI/180.0));
    conv[1][1]=cos(angle*(M_PI/180.0));
    conv[1][2]=0;

    conv[2][0]=0;
    conv[2][1]=0;
    conv[2][2]=1;
    qDebug()<<"Z rotation matrix"<<Qt::endl;
    for(int i=0; i < 3; i++)
    {
    qDebug()<<conv[i][0]<<" "<<conv[i][1]<<" "<<conv[i][2]<<" ";
     qDebug()<<Qt::endl;
    }

    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     {
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
     }
    }
    drawFigure();

}

void letter::draw_rotation_y()
{
    GLfloat conv[3][3] ;
    conv[0][0]=cos(angle*(M_PI/180.0));
    conv[0][1]=0;
    conv[0][2]=sin(angle*(M_PI/180.0));

    conv[1][0]=0;
    conv[1][1]=1;
    conv[1][2]=0;

    conv[2][0]=-sin(angle*(M_PI/180.0));
    conv[2][1]=0;
    conv[2][2]=cos(angle*(M_PI/180.0));

    qDebug()<<"Y rotation matrix"<<Qt::endl;
    for(int i=0; i < 3; i++)
    {
     qDebug()<<conv[i][0]<<" "<<conv[i][1]<<" "<<conv[i][2]<<" ";
     qDebug()<<Qt::endl;
    }

    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     {
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
     }
    }
    drawFigure();
}

void letter::draw_rotation_x()
{
    GLfloat conv[3][3] ;
    conv[0][0]=1;
    conv[0][1]=0;
    conv[0][2]=0;

    conv[1][0]=0;
    conv[1][1]=cos(angle*(M_PI/180.0));
    conv[1][2]=-sin(angle*(M_PI/180.0));

    conv[2][0]=0;
    conv[2][1]=sin(angle*(M_PI/180.0));
    conv[2][2]=cos(angle*(M_PI/180.0));

    qDebug()<<"X rotation matrix"<<Qt::endl;
    for(int i=0; i < 3; i++)
    {
    qDebug()<<conv[i][0]<<" "<<conv[i][1]<<" "<<conv[i][2]<<" ";
     qDebug()<<Qt::endl;
    }

    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     {
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
     }
    }
    drawFigure();

}
void letter::draw_transfer()
{
    GLfloat conv[4][3] ;
    conv[0][0]=1;
    conv[0][1]=0;
    conv[0][2]=0;

    conv[1][0]=0;
    conv[1][1]=1;
    conv[1][2]=0;

    conv[2][0]=0;
    conv[2][1]=0;
    conv[2][2]=1;

    conv[3][0]=x_transfer;
    conv[3][1]=y_transfer;
    conv[3][2]=z_transfer;

    qDebug()<<"transfer matrix"<<Qt::endl;
    for(int i=0; i < 4; i++)
    {
       qDebug()<<conv[i][0]<<" "<<conv[i][1]<<" "<<conv[i][2]<<" ";
       qDebug()<<Qt::endl;
    }

    for(int i=0; i < vertices; i++)
    {
        for(int j=0; j < 3; j++)
        {
            VertexArray[i][j]=0;
            for(int k=0; k < 4; k++)
            {
                if(k==3)
                   VertexArray[i][j]+=1*conv[k][j];
                else
                   VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
            }
        }
    }
    drawFigure();
}
void letter::draw_scaling()
{
    GLfloat conv[3][3] ;
    conv[0][0]=x_scale;
    conv[0][1]=0;
    conv[0][2]=0;

    conv[1][0]=0;
    conv[1][1]=y_scale;
    conv[1][2]=0;

    conv[2][0]=0;
    conv[2][1]=0;
    conv[2][2]=z_scale;

    qDebug()<<"scale matrix"<<Qt::endl;
    for(int i=0; i < 3; i++)
    {
     qDebug()<<conv[i][0]<<" "<<conv[i][1]<<" "<<conv[i][2]<<" ";
     qDebug()<<Qt::endl;
    }

    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
    }
    drawFigure();
}
void letter::draw_xy_projection()
{
    GLfloat conv[3][3] ;
    conv[0][0]=1;
    conv[0][1]=0;
    conv[0][2]=0;

    conv[1][0]=0;
    conv[1][1]=1;
    conv[1][2]=0;

    conv[2][0]=0;
    conv[2][1]=0;
    conv[2][2]=0;
    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
    }
    drawFigure();
}
void letter::draw_xz_projection()
{
    GLfloat conv[3][3] ;
    conv[0][0]=1;
    conv[0][1]=0;
    conv[0][2]=0;

    conv[1][0]=0;
    conv[1][1]=0;
    conv[1][2]=0;

    conv[2][0]=0;
    conv[2][1]=0;
    conv[2][2]=1;
    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
    }
    drawFigure();
}

void letter::draw_zy_projection()
{
    GLfloat conv[3][3] ;
    conv[0][0]=0;
    conv[0][1]=0;
    conv[0][2]=0;

    conv[1][0]=0;
    conv[1][1]=1;
    conv[1][2]=0;

    conv[2][0]=0;
    conv[2][1]=0;
    conv[2][2]=1;
    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
    }
    drawFigure();
}
void letter::drawFigure()
{
  GLfloat c[vertices * 3];
  for(int i = 0; i < vertices; i++)
  {
      for(int j = 0; j < 3; j++)
      {
          c[i * 3 + j] = VertexArray[i][j];
      }
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, c);
  glDrawElements(GL_QUADS, indexPoints, GL_UNSIGNED_BYTE, IndexArray);
  glDisableClientState(GL_VERTEX_ARRAY);
}
