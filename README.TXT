# --------------------------SOUND SRNSOR PROJECT --------------------------
This project is ment to collect sound level at a proximity of a Raspberry Pi
device. The PRi is equipped with a PSB sound card (C-Media Electronics, Inc.
Audio Adapter) and a microphone. The sound is recored at 16000Hz samples rate
and every scound will produce 80 pieces of RMS value as a bar-diagram...

Instruction Content

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
		- Change the relative imformation to your own(email...)
	Set USB Sound Card as Default
		- Run "lsusb"
		- Run "sudo nano /etc/asound.conf"
			input following content
			pcm.!fault
			{
				type plug
				slave
				{
					pc, "hw:1,0"
				}
			}
			crl.!default
			{
				type hw
				card 1
			}
		- Go to home directory, run"nano .asoundrc"
		- Run"alsamixer", you should be able to see that USB sound card is the default audio device
	Fix the Bug of arecord
		- Downgrade alsa-il to an earlier version(1.0.25)
		- Run "sudo nano /etc/apt/sources.list"
		- Add"#deb-src http://archive.raspbian.org/raspbian/ jessie main contrib non-free rpi
			deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rpi"
		- Run "sudo apt-get update"
		- Run "sudo aptitude versions alsa-utils" to check if version 1.0.25 of alsa-util is available
		- Run "sudo apt-get install alsa-utils=1.0.25-4" to downgrade.
		- Reboot
		- Run "arecord -r44100 -c1 -f S16_LE -d5 test.wav" to test that your microphone is working 
			You should see a "test.wav" file in the current folder
		- Run "aplay test.wav" to check that your recording is okay

2. Installation
	This Raspberry is pre-installed with NOOBS.
	Contains Raspberry Pi Recovery System.
		- Put your SD card in Raspberry
		- Connect Rspberry to the internet to get a IPv4 address with 
			internet cable
		- Connect Microphone to Sound card and Sound card to Raspberry
		- Connect power cable to spberry
		- Power on
		
3. Operation
	Run the sound project
		- Run "make" to complie(makefile automaticlly generate ./sound.a)
		- Run "./sound.a" to show the final result - a durable update sound bar

4. Mainfest (list of files and short description of their roles)
	Original File : main.c, sound.c, screen.c, comm.c,
						sound.h, screen.h, comm.h,
						makefile
	Generate : After you run the sound project, 
					it will automatically generate sound.a and final.tar
					when you use "make" command to complie the code successfully, 
					also generate the test.wav which record the sound 
					when you use "./sound.a" command to run the project.

5. License
	All the right of the project is released.

6. Contact information 
	Author: Dan Wang 
	Supervisor: Chao Gao
	Email: aimaomao1996@qq.com
