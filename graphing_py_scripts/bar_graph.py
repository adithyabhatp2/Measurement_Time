#!/usr/bin/env python
import matplotlib.pyplot as plt;

plt.rcdefaults()
import numpy as np
import matplotlib.pyplot as plt

# graph_type="Overhead"
# graph_type="RTT"
# graph_type = "BW"

import os;

def median(lst):
    lst = sorted(lst)
    if len(lst) < 1:
        return None
    if len(lst) % 2 == 1:
        return lst[((len(lst) + 1) / 2) - 1]
    else:
        return float(sum(lst[(len(lst) / 2) - 1:(len(lst) / 2) + 1])) / 2.0


def setGraph(graph_type_var):

    local_or_remote = "remote"
    optimized_or_not = "_o" #or empty
    average_or_median = "median"

    pathToGit = "/u/a/d/adbhat/private"
    path = pathToGit + "/gitRepository/739_A1/part3/thrift/Echo/v3/results_" + local_or_remote + optimized_or_not

    outDir = "graphs"

    if not os.path.exists(outDir):
        os.makedirs(outDir)

    # msg = [10, 100, 1000, 10000, 20000, 40000, 60000]
    # objects = ('10B', '100B', '1000B', '10,000B', '20,000B', '40,000B', '60,000B')

    # msg = [10, 100, 1000, 10000, 20000, 40000, 60000, 100000, 200000, 400000, 1000000, 2000000, 4000000]
    # objects = ('10B', '100B', '1KB', '10KB', '20KB', '40KB', '60KB', '100KB', '200KB', '400KB', '1MB', '2MB', '4MB')

    msg = [10, 100, 1000, 10000, 20000, 40000, 60000, 100000, 200000, 400000, 1000000, 2000000]
    objects = ('10B', '100B', '1KB', '10KB', '20KB', '40KB', '60KB', '100KB', '200KB', '400KB', '1MB', '2MB')

    # msg = [10, 100, 1000, 10000, 100000, 1000000, 2000000, 4000000]
    # objects = ('10B', '100B', '1KB', '10KB', '100KB', '1MB', '2MB', '4MB')

    masterBW = []
    masterLstStd = []

    for msgIter in msg:

        fileBW = path + "/" + str(msgIter) + "_" + graph_type_var + ".txt"
        f = open(fileBW, 'r')
        bw = []

        for line in f:
            bw.append(float(line))

        '''
        for x in bw:
            print x
        '''

        bw.sort()

        '''
        for x in bw:
            print x
        '''

        if average_or_median == "average":
            # Average graph
            masterBW.append(sum(bw) / len(bw))
        elif average_or_median == "median":
            # Median graph
            masterBW.append(median(bw))
        else:
            print "Die. niether avg nor median"
        masterLstStd.append(np.std(bw))

    # for error bars

    for masterBwIter in masterBW:
        print masterBwIter



    outFile = outDir + "/"
    outFile += local_or_remote + "_";
    outFile += average_or_median + "_";
    # Font size for plots
    plt.rcParams.update({'font.size': 10})


    if optimized_or_not == "_o":
        outFile += "opt_"


    y_pos = np.arange(len(objects))
    barList = plt.bar(y_pos, masterBW, align='center', yerr=masterLstStd)

    plt.xticks(y_pos, objects)

    for allBar in barList:
        allBar.set_color('y')

    if graph_type_var == "Overhead":
        print "Overhead graph"
        plt.ylabel('Overhead of sending message (ns)')
        plt.title('Overhead of sending message Vs Message size')
        outFile += "Overhead.png"
    elif graph_type_var == "RTT":
        print "RTT graph"
        plt.ylabel('RTT (us)')
        plt.title('RTT Vs Message size')
        outFile += "RTT.png"
    elif graph_type_var == "BW":
        print "BW graph"
        plt.ylabel('Bandwidth (Mbps)')
        plt.title('BW Vs Message size')
        outFile += "BW.png"

    my_dpi = 96;

    plt.xlabel("Message size (Bytes)")
    plt.autoscale(enable=True)
    plt.ylim(ymin=0)
    plt.savefig(outFile)
    plt.clf()
    # plt.savefig(outFile, dpi = my_dpi*2)
    # plt.show()


def main():
    for graph_type_var in ["BW", "RTT", "Overhead"]:
        setGraph(graph_type_var)


if __name__ == '__main__':
    main()
