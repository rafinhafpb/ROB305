# ROB305 Class Exercises

## TD1

### TD1a

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD1
arm-linux-g++ -Wall -Wextra timespec.cpp td1a.cpp -o td1a
rsync -avz td1a root@192.168.50.52:
```

- In another terminal:

Enter the Raspberry:

```bash
ssh root@192.168.50.52
```

Execute the code:

```bash
./td1a
```

### TD1b

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD1
arm-linux-g++ -Wall -Wextra timespec.cpp Chrono.cpp td1b.cpp -o td1b
rsync -avz td1b root@192.168.50.52:
```

- In the terminal connected to the Raspberry (as shown in TD1a):

Execute the code:

```bash
./td1b
```

## TD2

### TD2a

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD2
arm-linux-g++ -Wall -Wextra td2a.cpp -o td2a
rsync -avz td2a root@192.168.50.52:
```

- In the terminal connected to the Raspberry (as shown in TD1a):

Execute the code:

```bash
./td2a
```

### TD2b

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD2
arm-linux-g++ -Wall -Wextra Timer.cpp CountDown.cpp td2b.cpp -o td2b
rsync -avz td2b root@192.168.50.52:
```

- In the terminal connected to the Raspberry (as shown in TD1a):

Execute the code:

```bash
./td2b
```

### TD2c

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD2
arm-linux-g++ -Wall -Wextra Looper.cpp Chrono.cpp timespec.cpp td2c.cpp -o td2c
rsync -avz td2c root@192.168.50.52:
```

- In the terminal connected to the Raspberry (as shown in TD1a):

Execute the code:

```bash
./td2c <nLoops>
```

### TD2d

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD2
arm-linux-g++ -Wall -Wextra -Wno-psabi Timer.cpp Looper.cpp Calibrator.cpp Chrono.cpp timespec.cpp td2d.cpp -o td2d
rsync -avz td2d root@192.168.50.52:
```

- In the terminal connected to the Raspberry (as shown in TD1a):

Execute the code:

```bash
./td2d
```

### TD2e

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD2
arm-linux-g++ -Wall -Wextra -Wno-psabi Timer.cpp Looper.cpp Calibrator.cpp Chrono.cpp timespec.cpp CpuLoop.cpp td2e.cpp -o td2e
rsync -avz td2e root@192.168.50.52:
```

- In the terminal connected to the Raspberry (as shown in TD1a):

Execute the code:

```bash
./td2e
```

## TD3

### TD3a-1

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD3/TD3a
arm-linux-g++ -Wall -Wextra td3a-1.cpp -o td3a-1
rsync -avz td3a-1 root@192.168.50.52:
```

- In the terminal connected to the Raspberry (as shown in TD1a):

Execute the code:

```bash
./td3a-1
```

### TD3a-2

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD3/TD3a
arm-linux-g++ -Wall -Wextra td3a-2.cpp -o td3a-2
rsync -avz td3a-2 root@192.168.50.52:
```

- In the terminal connected to the Raspberry (as shown in TD1a):

Execute the code:

```bash
./td3a-2
```

### TD3a-3

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD3/TD3a
arm-linux-g++ -Wall -Wextra td3a-3.cpp -o td3a-3
rsync -avz td3a-3 root@192.168.50.52:
```

- In the terminal connected to the Raspberry (as shown in TD1a):

Execute the code:

```bash
./td3a-3
```

### TD3b

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD3/TD3b
arm-linux-g++ -Wall -Wextra Mutex.cpp TimeoutException.cpp timespec.cpp td3b.cpp -o td3b
rsync -avz td3b root@192.168.50.52:
```

- In the terminal connected to the Raspberry (as shown in TD1a):

Execute the code:

```bash
./td3b
```

### TD3c

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD3/TD3c
arm-linux-g++ -Wall -Wextra Thread.cpp Chrono.cpp timespec.cpp
```

### TD3d

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD3/TD3d
arm-linux-g++ -Wall -Wextra Mutex.cpp TimeoutException.cpp Counter.cpp Incrementer.cpp Thread.cpp timespec.cpp Chrono.cpp td3d.cpp -o td3d
rsync -avz td3d root@192.168.50.52:
```

- In the terminal connected to the Raspberry (as shown in TD1a):

Execute the code:

```bash
./td3d <nLoops> <nTasks> [protect] [policy]
```

### TD3e

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD3/TD3e
arm-linux-g++ -Wall -Wextra -Wno-psabi Mutex.cpp TimeoutException.cpp timespec.cpp ../../TD2/Calibrator.cpp ../../TD2/CpuLoop.cpp ../../TD2/Looper.cpp ../../TD2/Timer.cpp ../TD3c/Thread.cpp ../../TD1/Chrono.cpp  td3e.cpp -o td3e
rsync -avz td3e root@192.168.50.52:
```

- In the terminal connected to the Raspberry (as shown in TD1a):

Execute the code:

```bash
./td3e
```

## TD4

### TD4a

- To compile the file (if not already) and send it to the Raspberry Pi:

```bash
cd
cd ROB305/TD4
arm-linux-g++ -Wall -Wextra ../TD3/TD3b/Mutex.cpp ../TD1/timespec.cpp ../TD3/TD3b/TimeoutException.cpp Monitor.cpp
```