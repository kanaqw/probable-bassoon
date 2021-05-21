using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{

    class Program
    {

     static void Main(string []args)
        {
            for (int row = 0; row < 10; row+=2)
            {   if (row%2==0) { 
                int column = 0;
                    for (int size = 0; size < (10-row)/2; size++)
                        Console.Write(" ");
                    for (column = 0; column < row + 1; column++)
                    {
                        Console.Write("*");
                    }
                   
                }
                   
                Console.WriteLine();
            }
            }
           
        }
    }
