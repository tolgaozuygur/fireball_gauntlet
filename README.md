# Fireball Gauntlet
This is a gauntlet that throws small fireballs when you throw a punch. It was built on my YouTube channel <a href="https://www.youtube.com/channel/UCMPCc9hZ-YBZkEon9tzESVA" target="_blank">Hallederiz</a>.

It works by heating balls of flash paper (nitrocellulose) when it detects the movement of a punch. Flash paper is a material mostly used by magicians to produce flashes of fire, so it is relatively safe to use.

It has 3 barrels, so you can throw 3 subsequent punches.   

> Here is how it looks when assembled

<img src="https://github.com/tolgaozuygur/fireball_gauntlet/blob/master/images/fireballGauntlet.jpg" title="Fireball Gauntlet" alt="Fireball Gauntlet" width="500">

The building process is documented on <a href="https://www.youtube.com/watch?v=1SC4p9y7-fk" target="_blank">YouTube</a>, the channel is in Turkish, but even though it's in Turkish you can still watch the progress and get some ideas about how to assemble the device properly. I intend to add English subtitles soon.

## CAUTION
As mentioned, Flash Paper is relatively safe to use but you must be cautious with this device. Never aim at humans or animals, always use safety goggles and do not use indoors. <b>Build and use this device at your own risk.</b>

## Parts Required
- <a href="https://store.arduino.cc/usa/arduino-nano" target="_blank">1x Arduino Nano</a>
- <a href="https://www.amazon.com/MPU-6050-MPU6050-Accelerometer-Gyroscope-Converter/dp/B008BOPN40" target="_blank">MPU 6050 module</a>
- <a href="https://www.pololu.com/product/2562" target="_blank">5V Step-Up Voltage Regulator</a>
- <a href="https://www.pololu.com/product/1147" target="_blank">3-AAA Battery Holder with switch</a>
- <a href="https://www.sparkfun.com/products/8619" target="_blank">Protoboard</a> (or any other prototyping board)
- <a href="https://www.amainhobbies.com/o.s.-r5-short-body-standard-glow-plug-medium-osm71605200/p194679" target="_blank">3x Glow Plug</a>
- 3x IRF540 N Mosfet
- 3x LED (yellow)
- 3x 180Ω Resistor
- 3x 1kΩ Resistor
- 10mm aluminum rod
- Elastic Sewing Band (3 cm witdh)
- JB Weld
- 2mm screws
- Jumper Cables 
- Heat Shrinking Tube

## 3d Printing and Assembling the Case
Print the stl files in the 3d_files folder. You need to print more than one copies of some parts; print 2x gloveCaseHolder.stl, 4x gloveCaseHolderSupport.stl and 3x plugNut.stl.  

They do not need any support, just print them as they are. (make sure you lay them flat in your slicer). 

Glue the gloveCaseHolder to the gloveCaseBase by using some super glue. Also glue the gloveCaseHolderSupport parts to the top exposed surfaces of the gloveCaseHolders to make them stronger.

>Here is an image to show how to assemble it.

<img src="https://github.com/tolgaozuygur/fireball_gauntlet/blob/master/images/3dAssembly.jpg" title="Fireball Gauntlet Assembly" alt="Fireball Gauntlet Assembly" width="800">

>There are 2 versions of the gloveCaseTop.stl, the one in the photos is the regular one that exposes some the electronics. You might want to print the extended one that will cover the entire circuit.

Once everything is in place, sew two rings of elastic sewing bands to the gloveCaseHolder parts to hold the gauntlet on your hand. 

## Making the Barrels
Use a hacksaw to cut the aluminum rod in 3x 4cm barrels. Use JB Weld to glue the plugNut parts that you have printed to one end of each barrel. Before screwing a glow plug into a plutNut, solder a jumper cable to the rear tip of the glow plug (or you can use a buttsplice), then slide another jumper cable between the threads of the glow plug and the plugNut part while screwing it in.

>Here's how it should look.

<img src="https://github.com/tolgaozuygur/fireball_gauntlet/blob/master/images/barrelConnection.jpg" title="Fireball Gauntlet Barrel Connections" alt="Fireball Gauntlet Barrel Connections" width="800">

Then slide a large heat shrinking tube on top of the plugNut and glow plugs to ensure they are properly insulated.

## Soldering the circuit
Solder the components on the protoboard based on the diagram below. Or you can of course get it professionally printed if you draw the circuit properly.

<img src="https://github.com/tolgaozuygur/fireball_gauntlet/blob/master/images/fireballGauntletCircuit_bb.png" title="Fireball Gauntlet Circuit Diagram" alt="Fireball Gauntlet Circuit Diagram" width="800">

> Here is a photo of how I fitted them on. Note that I separated the LEDs and their resistors on a small prototyping board piece to fit it on the top part of the case. (It's a bit messy, since I did it in hurry on the Youtube video :) )
<img src="https://github.com/tolgaozuygur/fireball_gauntlet/blob/master/images/fireballGauntletCircuit.jpg" title="Fireball Gauntlet Circuit Photo" alt="Fireball Gauntlet Circuit Photo" width="800">

Also please note the orientation of the MPU 6050 accelerometer module. If you place it in a different position, you'll need to correct the punch detection axis in the arduino code.

## Finalizing the Device
Upload the Kal_Vas_Flam.ino to the Arduino, place the barrels and the circuit to the case, plug in some batteries. Then cut 4x4cm pieces of flash paper and squeeze them into small balls. Put a single ball in each barrel, push them to the end with a pencil.
Put on your safety goggles and start throwing some punches!
And again, be safe and use caution.

## Final Thoughts
This device was built in a single day from scratch for the video, so I'm aware that there are many things that could be designed better. I intend to do a new version sometime soon. Also please send me photos and videos if you build one at tolgaozuygur@gmail.com , I'd be very happy to see it in action!




