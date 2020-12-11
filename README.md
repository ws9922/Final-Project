# fandudu2-shuow6-sz31
Final Project
Based on openflights dataset, we build this program.
Sample entries of airports dataset is like:
507,"London Heathrow Airport","London","United Kingdom","LHR","EGLL",51.4706,-0.461941,83,0,"E","Europe/London","airport","OurAirports"
Sample entries of routes dataset is like:
BA,1355,SIN,3316,LHR,507,,0,744 777


First of all, you should put your dataset file into our Code folder
You can only use the worldmap.png we provide
To complie our code, run the following from our Code directory:
$ make main
Then run it by running:
$ ./main

There is a series of instructions which helps you follow our program.
1.Please input your Airports dataset file name
2.Please input your Routes dataset file name
3.Please input your source airport's name
4.Please input your destination airport's name

At last, our program would output the shortest path's distance and the shortest path. The results would be saved as output.png with source, destination, stops, and the path marked on the world map.
