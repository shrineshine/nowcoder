s=set()
while(True):
    try:
        name = raw_input("")
        name = name.split()
        for i in range(len(name)):
            s.add(name[i])
    except:
        break
print len(s)
