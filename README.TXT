# --------------------------SOUND SRNSOR PROJECT --------------------------
This project is ment to collect sound level at a proximity of a Raspberry Pi
device. The PRi is equipped with a PSB sound card (C-Media Electronics, Inc.
Audio Adapter) and a microphone. The sound is recored at 16000Hz samples rate
and every scound will produce 80 pieces of RMS value as a bar-diagram...

Table of Cointent
1. Configuration
	RPi Default Booting & Keyboard Layout
	- By default RPi3 boots into X-server mode. This takes more booting time. 
		And in most cases you don’t use a display. So the first thing is to disable it. 
		To do so, you need to attach a HDMI display to it and change configurations. 
		You also need a USB keyboard for this step.
	- Open a "terminal" window (Ctrl+ESC, and choose from the “Accessories”)
	- Run "sudo raspi-config" in the terminal
	- Select "boot options"- "B2 Console Autologin"
	- The newer version of Raspbian disables SSH by default, therefore you have to enable it.
		Navigate to and select “SSH”, Choose “Yes”, Select “Ok”
	- (Optional-change keyboard layout)Select "Internationalisation Options"
	- Run "sudo reboot" to reboot
	Send IP Address by Email
	- Get the IP address from Pi, the simplest way to edit "rc.local" file.
	- Run "sudo nano /etc/rc.local" 
	- Set "sleep 30"
	- Change the relative imformation to your own(email, )
	
2. Installation
	This Raspberry is pre-installed with NOOBS.
	Contains Raspberry Pi Recovery System.

3. Operation
	- Original File : main.c, sound.c, screen.c, comm.c, 
						sound.h, screen.h, comm.h,
						makefile
	- Generate : After you run the sound project, 
					it will automatically generate sound.a and final.tar
					when you use "make" command to complie the code successfully, 
					also generate the test.wav which record the sound 
					when you use "./sound.a" command to run the project.

4. Mainfest (list of files and short description of their roles)
5. License
6. Contact information 
