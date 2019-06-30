## dm-Erbeverb
This is an attempt to recreate the Make Noise reverb unit called [Erbe-Verb](http://www.makenoisemusic.com/modules/erbe-verb). The reverb algorithm is invented by [Tom Erbe](http://www.soundhack.com/). The reverb design I made is based on this [article](https://quod.lib.umich.edu/cgi/p/pod/dod-idx/building-the-erbe-verb-extending-the-feedback-delay-network.pdf?c=icmc;idno=bbp2372.2015.054;format=pdf) that he wrote.

## Table of contents:
- [Description](#Description)
- [Goal](#Goal)
- [Install instructions](#Install-instructions)
- [License](#License)

## Description
I designed this mono input/stereo output reverb in Max/MSP gen~ which is a C-like coding environment within Max/MSP that compiles to C++ code. It's efficient and gives you the control to build more sophisticated audio plug-ins. Since gen~ code can be compiled as C++ code the reverb can be compiled for use on the [OWL Pedal](https://www.rebeltech.org/product/owl-pedal/), [MOD Duo](https://www.moddevices.com/) & [Pisound / MODEP](https://blokas.io/modep/). In this repository you can find the files needed to get the reverb plug-in running in [Max/MSP](./max-msp), [Ableton Live (Max For Live device)](./max-for-live) & [MODEP (LV2 plug-in)](./modep). You can see [here](./modep/src/gen_exported.cpp) what the compiled C++ code looks like.

## Goal
The goal for this project was to investigate how to design a reverb algorithm. When I first heard the Erbe-Verb I was fascinated by the sound and the flexibility the device offers to change the characteristics of the simulated space. The article helped me out a great deal in learning how to build my first nice sounding reverb. There was still a lot work to figure out by myself, because the original creator didn't share all of his secrets of course...

## Install instructions
- Max/MSP
  - open the file and start playing
- Max For Live: 
  - open the file in Ableton Live and start playing
- Pisound / MODEP:
  - Copy the LV2 folder into your Raspberry Pi:
  
    *scp -rp \<path to the dm-Erbeverb.lv2 file\> modep@172.24.1.1:/usr/local/modep/.lv2*
  - Enter the password and your ready to go
  - If you don't have permissions to write to that location, change them

  - If you want to remove the plugin:
    - Connect to your Raspberry Pi via SSH:
    
      *ssh modep@172.24.1.1*
    - Enter the password
    - Remove the plug-in
    
      *rm -r /usr/local/modep/.lv2/dm-Erbeverb.lv2*

## License
Copyright: © 2015 Tom Erbe. This is code distributed under the terms of the Creative Commons Attribution License 3.0 Unported, which permits unrestricted use, distribution, and reproduction in any medium, provided the original author and source are credited.



