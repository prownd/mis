CC = g++
EXEC = emis
OBJS = src/main.o \
src/managerview_console_impl.o \
src/manager.o  \
src/managerservice_impl.o  \
src/tools.o  \
src/managerdao_file_impl.o  \
src/serviceview_console_impl.o \
src/department.o \
src/employee.o  \
src/service_impl.o  \
src/servicedao_file_impl.o 

all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) -o $@ $^
clean:
	rm -f $(EXEC) $(OBJS)
