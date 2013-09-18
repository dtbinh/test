#!/usr/bin/env python
#-*-coding:utf-8-*-

import sys
import random
import math
import matplotlib.pyplot as plt

class d(object):

    def __init__(self):
        self.x = random.uniform(0, 10)
        self.y = random.uniform(0, 10)
        self.cluster = 0
        self.select = 0
        
    def __show__(self):
        print self.distance 

    


if __name__ == '__main__':
    
    point = {}
    means = {}
    for i in range(0, 100):
        point[i] = d()

    print point.__len__()
    
    centers = {}
    t = 0

    for i in range(1, 11): 
        t = random.randint(0, 99)

        while point[t].select == 1:
            t = random.randint(0,99)

        centers[i] = point[t]
        centers[i].cluster = i
        point[t].cluster = i
        point[t].select = 1


        


    stop_num = 0
    while stop_num < 10:  

        stop_num = 0
        for i in range(0,100):
            min = 200.00
            for j in range (1, 11):
                new_dis = math.hypot(centers[j].x-point[i].x ,centers[j].y-point[i].y)
                if new_dis < min:
                    min = new_dis
                    point[i].distance = new_dis
                    point[i].cluster = j

        
        for i in range(1,11):
            count = 0
            sum_x = 0.0
            sum_y = 0.0
            means_x = 0.0
            means_y = 0.0
            for j in range(0,100):
                if point[j].cluster == i:
                    count = count + 1
                    sum_x = sum_x + point[j].x
                    sum_y = sum_y + point[j].y
            if count != 0:
                means_x = sum_x/count
                means_y = sum_y/count
            if abs(centers[i].x - means_x) < 0.001 and abs(centers[i].y -means_y) < 0.001:
                stop_num += 1
                continue
            else:
                centers[i].x = means_x
                centers[i].y = means_y
        
    sum_count = {}
    for i in range (1,11):
        sum_count[i] = 0

    for i in range (0, 100):
        sum_count[point[i].cluster] += 1
        print point[i].x,' ',point[i].y,' ',point[i].cluster
    
    for i in range (1,11):
        print 'numbers of cluster ', i, ': ', sum_count[i]

    for i in range(0, 100):
        plt.plot(point[i].x,point[i].y)
        plt.show()

        






                




