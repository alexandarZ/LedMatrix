#include "matrix.h"

Matrix::Matrix()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            _matrix[i][j]=0;
        }
    }
}

void Matrix::set_pixel(int x, int y, bool state)
{
    if(state)
    {
        _matrix[x][y] = 1;
    }
    else
    {
        _matrix[x][y] = 0;
    }

}

void Matrix::generate_hex(char message[])
{
   int rows[8];

   for(int i=0;i<8;i++)
   {
       rows[i]=0;
   }

   for(int i=0;i<8;i++)
   {
       for(int j=0;j<8;j++)
       {
           if(_matrix[i][j]==1)
           {
               rows[i]+=pow(2,j);
           }
       }
   }

   sprintf(message,"{0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x}",rows[7],rows[6],rows[5],rows[4],rows[3],rows[2],rows[1],rows[0]);
}

void Matrix::generate_dec(char message[])
{
    int rows[8];

    for(int i=0;i<8;i++)
    {
        rows[i]=0;
    }

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(_matrix[i][j]==1)
            {
                rows[i]+=pow(2,j);
            }
        }
    }

    sprintf(message,"{%d,%d,%d,%d,%d,%d,%d,%d}",rows[7],rows[6],rows[5],rows[4],rows[3],rows[2],rows[1],rows[0]);
}

void Matrix::generate_bin(char message[])
{
//TODO
}

void Matrix::generate_for_device(char message[])
{

    memset(message,0,256);

    char char_matrix[8][8];

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
           if(_matrix[i][j]==1)
           {
               char_matrix[i][j]='1';
           }
           else
           {
               char_matrix[i][j]='0';
           }
        }
    }

    for(int i=0;i<8;i++)
    {
        if(i==0)
        {
            strncpy(message,char_matrix[i],8);
            strcat(message,";");
        }
        else
        {
            strncat(message,char_matrix[i],8);
            strcat(message,";");
        }
    }
}
