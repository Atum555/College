def time_diff(time1:tuple, time2:tuple):
    if not (0<= time1[0] <24 and 0<= time2[0] <24 and 0<= time1[1] <60 and 0<= time2[1] <60): return None
    time1abs = time1[0]*60 + time1[1]
    time2abs = time2[0]*60 + time2[1]
    timeDiff = abs(time1abs-time2abs)
    return (timeDiff//60, timeDiff%60)