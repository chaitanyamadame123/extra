groupadd 'grpname'
cat /etc/group|grep grp
gpasswd grpname
cat /etc/shadow|grep grp



useradd -g grpname username   (primary) (G-secondary)
chown userbane file/directory
chgrp ------"----------------
setfacl -m u:u1:rwx data.txt
------------g:G1:-----------

getfacl data.txt
sefacl -m o:w data.txt

cp -rfv /etc/fstab/var/tmp
chown root:root var/tmp/fstab
    (user:group)

chmod o=r /var/tmp/fstab


