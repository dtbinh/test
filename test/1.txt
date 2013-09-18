import cPickle as p
import os

print '欢迎进入我的地址簿'
filename='address.data'
f=file(filename)
info=p.load(f)
num=1
while(num>=1 and num<=5):
  num=int(raw_input('please make your choose:\n(1) add\n(2) del\n(3) find\n(4)display all members\n(5)exit with save\n' ))
  if num==1:
    name=raw_input('please enter your name:\n')
    phone_number=int(raw_input('please enter your phone number:\n'))
    info[name]=phone_number
    print 'name:%s  phone number:%s ' %(name,phone_number)
    continue
  if num==2:
    name=raw_input('ready to delete the member...\n please enter your name:\n')
    for i in info.items():
        if name==i:
          del info[name]
    print'The member %s delete success' %name
    continue
  if num==3:
    name=raw_input('ready to find the member...\n please enter your name:\n')
    for i,j in info.items():
        if name==i:
          print 'name:%s  phone number:%s'  %(name,phone_number)
        else:
          print 'There isn\'t %s here ' % name 
    continue
  if num==3:
    name=raw_input('ready to find the member...\n please enter your name:\n')
    for i,j in info.items():
        if name==i:
          print 'name:%s  phone number:%s'  %(name,phone_number)
        else:
          print 'There isn\'t %s here ' % name 
    continue
  if num==4:
    for i,j in info.items():
      print 'name:%s  phone number:%s'  %(i,j)
  if num==5:
    f=file(filename,'w')
    p.dump(info,f)
    print 'save success'
    os.system("clear")
    exit  
    
