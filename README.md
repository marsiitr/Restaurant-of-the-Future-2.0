# Restaurant-of-the-Future-2.0

![IsometricView]<img src="https://github.com/PrathamMeena/Restaurant-of-the-Future-2.0/tree/master/Images/IsoMetricView.PNG">

# Abstract
	
The idea is to make a robot capable of serving dish to customers. The order will be given via a mobile device located at the table, which will be sent to the reception for billing and to kitchen's menu for chef as well the bot.
Once the food is prepared it will be placed in the bot's tray which will then take the food to the diner.  

# Acknowledgement

We would like to express our special thanks to Shivam Srivastava sir, Prashant Kumar sir, Nitesh Kumar sir, Bhaskar Kaushik sir for guiding us through the journey.

# Hardware

1. Base
2. Castor
3. Gears
4. Motor
5. Components
6. Pulley
7. Shaft
8. Slider
9. Tray
10. Wheel
11. Arduino
12. Encoder
13. Motor Driver

# Software
	Arduino
The movement of dc motors and the servo motor is controlled by the arduino code with the help of the feedback from the rotary encoders.

# Working

Basically initial and final coordinatesa are fixed. The customer gives the order from th etable via mobile device which sends the data to the reception and also to the kitchen and the bot. Bill is then prepared based on the order and chef starts with the order. Now, the table's coordinate are fed into the bot along with the order via a bluetooth system.
Once the food is prepared it is then kept on the tray and the chef gives instruction to the bot to start.
A 2D-Map of the restaurant has been prepared and based on this an optimized shortest path is calculated using Matlab. Now, the bot moves along this path and reaches the table. Once it has reached its destination the tray lifts upward and bot moves little closer to the table.
Once the bot is at its correct position the tray then moves downward and an Push button sensor gets activated as it touches the table. The lifing mechanism then stops and the tray at this point rest on the table free from any contact with the bot. The bot then moves back from the table and retraces its path back to the kitchen.
	
# Future Improvements

An Obstacle detection system will be installed to prevent collision with both static as well as dynamic obtacles either via IR sensor or via Image Processing.
A better lift system is to be added so that more than one dishes can be taken at a time. 	

# Applications

Current aim was to apply this in restaurants but with further improvements we can apply this to various areas such as in warehouses for shifting of objects as well as in shops to deliever the requiered items.
Also, it can be used for domestic purposes in houses and offices. 
 
# Team Members

•Pratham Meena

•Divyansh Gupta

•Vaibhav Agarwal

•Sandeep Marandi

•Aman Kumar

•Sakshi Priya

# Mentors

•Anurag Singh

•Vishal Singh
