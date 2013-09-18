import os
import time
source=['/home/wbmc74/iNodeClient','/home/wbmc74/music']
target_dir='/mnt/e/backup/'
target=target_dir+time.strftime('%Y%m%d%H%M%S')+'.zip'
zip_command="zip -qr '%s' %s" %(target,''.join(source))

if os.system(zip_command)==0:
    print 'Successful backup to',target
else:
    print 'Backup FAILED'
