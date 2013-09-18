import threading
import time

semaphore = threading.Semaphore(2)

def func():
    print '%s acquire semaphore...' % threading.currentThread().getName()
    if semaphore.acquire():

        print '%s get semaphore...' % threading.currentThread().getName()        
        time.sleep(4)

        print '%s release semaphore...' % threading.currentThread().getName()

        semaphore.release()

t1 = threading.Thread(target = func )

t2 = threading.Thread(target = func )
t3 = threading.Thread(target = func )
t4 = threading.Thread(target = func )

t1.start()
t2.start()
t3.start()
t4.start()

time.sleep(2)

print 'MainThread release semaphore without acquire'
semaphore.release()
