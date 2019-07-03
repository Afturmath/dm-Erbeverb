## dm-Erbeverb
This is an attempt to recreate the Make Noise reverb unit called [Erbe-Verb](http://www.makenoisemusic.com/modules/erbe-verb). The reverb algorithm is invented by [Tom Erbe](http://www.soundhack.com/). The reverb design I made is based on this [article](https://quod.lib.umich.edu/cgi/p/pod/dod-idx/building-the-erbe-verb-extending-the-feedback-delay-network.pdf?c=icmc;idno=bbp2372.2015.054;format=pdf) that he wrote.

Here's what the plug-in looks like on MODEP:

![demo](https://media.giphy.com/media/llrmivpom8WzVyY53h/giphy.gif)

## Table of contents:
- [Description](#Description)
- [Goal](#Goal)
- [Install instructions](#Install-instructions)
- [License](#License)

## Description
I designed this mono input/stereo output reverb in Max/MSP gen~ which is a C-like coding environment within Max/MSP that compiles to C++ code. Since gen~ code can be compiled as C++ code the reverb can be compiled for use on the OWL Pedal, MOD Duo & [Pisound / MODEP](https://blokas.io/modep/). In this repository you can find the files needed to get the reverb plug-in running in Max/MSP, Ableton Live (Max For Live device) & MODEP (LV2 plug-in). You can see [here](./modep/src/gen_exported.cpp) what the compiled C++ code looks like.

## Goal
The goal for this project was to investigate how to design a reverb algorithm. When I first heard the Erbe-Verb I was fascinated by the sound and the flexibility the device offers to change the characteristics of the simulated space. The article helped me out setting up the basic structure. Not all details are shared in the article, but I've given my best shot to get all the original features in and get it to be a nice sounding reverb.

## Install instructions
- [Max/MSP](./max-msp):
  - open the file and start playing
- [Max For Live](./max-for-live): 
  - open the file in Ableton Live and start playing
- [Pisound / MODEP](./modep):
  - Copy the LV2 folder into your Raspberry Pi (you might need to change permissions):
  
    ```
    $ scp -rp \<path to the dm-Erbeverb.lv2 folder\> modep@172.24.1.1:/usr/local/modep/.lv2
    ```
  - Enter your password and you're ready to go
  - If you want to remove the plugin:
    - Connect to your Raspberry Pi via SSH:
    
      ```
      $ ssh modep@172.24.1.1
      ```
    - Enter your password
    - Remove the plug-in:
    
      ```
      $ rm -r /usr/local/modep/.lv2/dm-Erbeverb.lv2
      ```

## License
Copyright: © 2015 Tom Erbe. This is code distributed under the terms of the Creative Commons Attribution License 3.0 Unported, which permits unrestricted use, distribution, and reproduction in any medium, provided the original author and source are credited.



