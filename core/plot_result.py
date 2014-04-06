# -*- coding: utf-8 -*-
"""
Created on Tue Mar 18 20:23:43 2014

@author: simonfilhol

Script to analyze result from the Wdune model
"""

import numpy as np
from matplotlib import pyplot as plt

# Function to plot intermadiate results from the Wdune model. 
def plot_surf_inter(nRow=None,nCol=None, mydir=None, toGIF=None):
    # add code if more than 12plots, produce GIF animation instead by default (ask where to save)
    # add colorscale bar to plot
    #
    if mydir==None:
        mydir = "/Users/simonfilhol/github/SnWdune/core/"
    mysurfaces=loadSurfaces(mydir)
    nPlots=mysurfaces.shape[2]
    
    if nRow==None:
        nRow = int(round(np.sqrt(nPlots)))
    if nCol ==None:
        nCol= int(round(np.sqrt(nPlots)))+1
    if toGIF==None:
        if nPlots>15:
            toGIF=True
        else:
            toGIF=False
        # change in futur to a pop-up window asking for directory folder
    if (nPlots>15) or (toGIF==True):
        from matplotlib import animation
        fig=plt.figure()
        def animate(nframe):
            plt.cla()
            plt.imshow(mysurfaces[:,:,nframe],cmap='jet')
            plt.colorbar() 
        anim = animation.FuncAnimation(fig, animate, frames=nPlots)
        anim.save('demoanimation.gif', writer='imagemagick', fps=4);
    else:
        plt.figure()
        for i in range(nPlots):            
            plt.subplot(nRow,nCol,i+1)
            plt.imshow(mysurfaces[:,:,i],cmap='jet')
            plt.colorbar()



def loadSurfaces(mydir=None):
    if mydir==None:
        mydir = "/Users/simonfilhol/github/SnWdune/core/"
        # change in futur to a pop-up window asking for directory folder
    from path import path
    p=path(mydir)
    myfiles=p.files(pattern='surf_inter_*')
    forsize=np.loadtxt(myfiles[0])    
    surfaces=np.empty((forsize.shape[0],forsize.shape[1],len(myfiles)))
    for i in range(len(myfiles)):
        surfaces[:,:,i]=np.loadtxt(myfiles[i])
        i=++1
    return surfaces
    



plot_surf_inter(10)










"""
code to compile graphs in an animated gif file.
http://www.jamesphoughton.com/2013/08/making-gif-animations-with-matplotlib.html

or 


            print(i)
            #pylab.ion()
            pylab.scatter( x, y, c=(j/nbodies,j/nbodies,j/nbodies) )
            pylab.axis([-400, 400, -400, 400])
            #pylab.draw()
            pylab.savefig('picture'+str(i))

os.chdir('C://Users/Alex')
subprocess.call(['ffmpeg', '-i', 'picture%d0.png', 'output.avi'])
subprocess.call(['ffmpeg', '-i', 'output.avi', '-t', '5', 'out.gif'])
"""

#=====================================================
# Extra functions to write for analyzing surfaces: 

# 1. Make function for plotting shadow cast (shadow matrix - surf matrix)
# 2. Make function to derive basic statisticts from surfaces (amplitude, elev distrib, slope distrib, aspect distrib...)
#   2a. plotting fuctions associated
# 3. Make functions to calculate dune wavelenght (cross correlation, fft, ...)  http://stackoverflow.com/questions/6991471/computing-cross-correlation-function
#       3a. use fftpack.fftfreq() or opencv crosscorrelate









