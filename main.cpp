#include<iostream>
using namespace std;


int main()

{
	double moment_of_inertia = 3800; /* 𝐼𝑦y = 3800 𝑘𝑔𝑚², the moment of intertia of the helicopter in y axis */ 
	double initial_yaw_rate = 0; /* 𝜃̇'(0)= 0 𝑟𝑎𝑑/𝑠, the initial yaw rate of the helicopter*/
	double initial_yaw = 0; /* 𝜃(0) = 0 rad, the initial yaw of the helicopter*/
	double torque_applied = 0.3; /*  0.3𝑡 𝑘𝑔𝑚² / 𝑠², the torque applied to helicopter */
	double angular_velocity_yaw_y_axis = torque_applied / moment_of_inertia;/* angular velocity 𝜃̈ and yaw 𝜃 around the y axis.*/

	/* Time steps */
	double time_step = 0.01; /*10ms TimeStep*/

	
		/*Increment in Helicopter yaw with respect to time increment*/

		for ( int i = 0; i <= 1000; ++i) /* Loop for time in miliseconds from 0 to 1000*/

		{
			double time = i * .01; /* Our simulation shall have a 10 ms step size i.e. = 0.01 seconds*/
			if (i % 100 == 0)
			{
				int seconds = i/100;
				cout << "Time:" << seconds << " seconds" << endl;  //Time (seconds)
				cout << "Yaw: " << initial_yaw << " radians" << endl;	//Yaw (radians)
			}
			/*Implementation of Euler integration*/
			torque_applied *= time; // 0.3𝑡 𝑘𝑔𝑚²/𝑠², the torque applied to helicopter over time
			initial_yaw_rate = initial_yaw_rate + angular_velocity_yaw_y_axis * time_step; //Angular Velocity
			initial_yaw = initial_yaw + initial_yaw_rate * time_step; //Yaw of helicopter over time

		}

		

	return 0;
}
