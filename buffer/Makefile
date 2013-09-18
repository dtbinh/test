foo: test.o wbmc.info.pb.o
	gcc -o test test.o wbmc.info.pb.o -lprotobuf
wbmc.info.pb.o : wbmc.info.pb.cc wbmc.info.pb.h
	gcc -c wbmc.info.pb.cc
test.o: test.cc wbmc.info.pb.h
	gcc -c test.cc
