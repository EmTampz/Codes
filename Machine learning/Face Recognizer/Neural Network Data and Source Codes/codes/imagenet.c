/*
 ******************************************************************
 * HISTORY
 * 15-Oct-94  Jeff Shufelt (js), Carnegie Mellon University
 *      Prepared for 15-681, Fall 1994.
 *
 ******************************************************************
 */

#include <stdio.h>
#include <string.h>
#include "pgmimage.h"
#include "backprop.h"

extern void exit();

/* 避免使用0和1作为目标值的原因是sigmoid单元对于有限权值不能产生这样的输出,
   如果我们企图用训练网络来准确匹配目标值0和1，梯度下降将会迫使权值无限增长。
   值0.1和0.9是sigmoid函数在有限权值情况下可以完成的。
*/
#define TARGET_HIGH 0.9
#define TARGET_LOW 0.1


/*** This is the target output encoding for a network with one output unit.
     It scans the image name, and if it's an image of me (js) then
     it sets the target unit to HIGH; otherwise it sets it to LOW.
     Remember, units are indexed starting at 1, so target unit 1
     is the one to change....  ***/
/***
    目标输出编码
***/

int load_target(img, net)
IMAGE *img;
BPNN *net;
{
  int scale;
  char userid[40], head[40], expression[40], eyes[40], photo[40];

  userid[0] = head[0] = expression[0] = eyes[0] = photo[0] = '\0';

  /*** scan in the image features ***/
  sscanf(NAME(img), "%[^_]_%[^_]_%[^_]_%[^_]_%d.%[^_]",
    userid, head, expression, eyes, &scale, photo);
  //姓名     朝向     表情      眼镜    大小

  // happy       <0.9, 0.1, 0.1, 0.1>
  // neutral     <0.1, 0.9, 0.1, 0.1>
  // sad         <0.1, 0.1, 0.9, 0.1>
  // angry       <0.1, 0.1, 0.1, 0.9>
  if (!strcmp(expression, "happy")) 
  {
      // happy       <0.9, 0.1, 0.1, 0.1>
      net->target[1] = TARGET_HIGH;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_LOW;
  } 
  else if(!strcmp(expression, "neutral"))
  {
      // neutral     <0.1, 0.9, 0.1, 0.1>
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_HIGH;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_LOW;
    }
  else if(!strcmp(expression, "sad"))
  {
      // sad         <0.1, 0.1, 0.9, 0.1>
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_HIGH;
      net->target[4] = TARGET_LOW;
  }
  else if(!strcmp(expression, "angry"))
  {
      // angry       <0.1, 0.1, 0.1, 0.9>
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_HIGH;
  }
  
  return 0;
}


/***********************************************************************/
/********* You shouldn't need to change any of the code below.   *******/
/***********************************************************************/

int load_input_with_image(img, net)
IMAGE *img;
BPNN *net;
{
  double *units;
  int nr, nc, imgsize, i, j, k;

  nr = ROWS(img);
  nc = COLS(img);
  imgsize = nr * nc;;
  if (imgsize != net->input_n) {
    printf("LOAD_INPUT_WITH_IMAGE: This image has %d pixels,\n", imgsize);
    printf("   but your net has %d input units.  I give up.\n", net->input_n);
    exit (-1);
  }

  units = net->input_units;
  k = 1;
  for (i = 0; i < nr; i++) {
    for (j = 0; j < nc; j++) {
      units[k] = ((double) img_getpixel(img, i, j)) / 255.0;
      k++;
    }
  }
  return 0;
}