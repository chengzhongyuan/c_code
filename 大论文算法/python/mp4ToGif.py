# -*- coding: utf-8 -*-

from moviepy.editor import VideoFileClip

clip = VideoFileClip("D:\\Code\\bite\\大论文算法\\python\\roscar.mp4").subclip(0, 15)  
clip.resize(height=300).write_gif("roscar.gif", fps=10)
