/*
wdune: This is an accessible and freely available interpretation of a cellular automata
simulation program for sand dunes. Please note that the random number generator
has a different license than this program, see file in this directory: 'mersenne_twister.h'.

Copyright (C) 2011 Thomas E. Barchyn, Chris H. Hugenholtz
Contact: tom.barchyn@uleth.ca, +1 (403) 332-4043

License:
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

Credits:
This program is further detailed in a accompanying publication. The code is an
interpretation of a simulation algorithm first described in the following publication:

Werner, B.T., 1995. Eolian dunes: Computer simulations and attractor interpretation.
Geology 23, 1107-1110. DOI: 10.1130/0091-7613(1995)023<1107:EDCSAA>2.3.CO;2

If you are using this program for research, we would appreciate citation of
both papers.

Notes:
This program is written in C/C++ and has been compiled successfully with GCC 4.4.1 in
both Windows (XP, Vista, 7) and Linux (Ubuntu 11.04). We have used the following compiler
flags: -Wall -pedantic -O1. The program will function on some systems with higher optimization
but we have encountered problems in some cases with -O2 and -O3.

This program is designed to be called exclusively from a Python script as a long string
of arguments need to be passed to the executable. The idea being that the Python script
can easily be modified for batch operation, etc. Please contact Tom Barchyn for further
assistance if you wish to extend the program (tom.barchyn@uleth.ca).
*/

// Accessory functions

void timePrinter()     // time printer: prints percentages of time completed
{
    if (t % (numIterations/10) == 0)
    {
        time_t nowTime;
        struct tm * timeString;
        time (&nowTime);
        timeString = localtime (&nowTime);
        int percentDone = (int)(0.5 + (double)t * 100/ numIterations);         // calculates percent done, add 0.5 to approx round
        cout << percentDone << "% complete, Time: " << asctime(timeString);
    }
}


void variablePrinter()   // function that print variables value each time the completion percentag is printed on the terminal
{
    if (t % (numIterations/10) == 0)
    {
		int shadstr = shad[10][10];
		int surfstr = surf[10][10];
		int shadowVal = shadstr - surfstr;
		cout << shadowVal << " Greater than zero if in shadow at position [10][10]"<<"\n";
    }
	
}


void RecordSurf(int rec_iter)
{
	/*
	for(int i = 0; i < maxNrow; i++){
		for (int j = 0; j < maxNcol; j++){
			int surfinter[i][j][rec_iter] = surf[i][j];
		}
	}*/
	
	FILE *pSurfinter;
	
	char filename[16]; 
	sprintf( filename, "surf_inter_%d.txt", rec_iter );  
	
	pSurfinter = fopen (filename, "w");
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < (ncols - 2); j++)
        {
            fprintf (pSurfinter, "%i ", surf[i][j]);
        }
        fprintf (pSurfinter, "%i", surf[i][ncols - 2]);
        fprintf (pSurfinter, "%i", surf[i][ncols - 1]);
        fprintf (pSurfinter, "%s", "\n");    // endline character
    }
    fclose (pSurfinter);
}
