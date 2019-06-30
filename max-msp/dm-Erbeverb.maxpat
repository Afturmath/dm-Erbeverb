{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 0,
			"revision" : 4,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 34.0, 79.0, 933.0, 787.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 10.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial Bold",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 205.0, 483.0, 64.0, 20.0 ],
					"text" : "exportcode"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-20",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 706.0, 355.0, 42.0, 20.0 ],
					"text" : "mix $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"linecount" : 6,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 364.740295000000003, 438.0, 427.0, 74.0 ],
					"text" : "An attempt to implement the Make-Noise module called Erbe-Verb following the article \"Building the Erbe-Verb: Extending the Feedback Delay Network Reverb for Modular Synthesizer Use\" written by Tom Erbe.\n\nhttps://quod.lib.umich.edu/cgi/p/pod/dod-idx/building-the-erbe-verb-extending-the-feedback-delay-network.pdf?c=icmc;idno=bbp2372.2015.054;format=pdf"
				}

			}
, 			{
				"box" : 				{
					"data" : 					{
						"clips" : [ 							{
								"absolutepath" : "drumLoop.aif",
								"filename" : "drumLoop.aif",
								"filekind" : "audiofile",
								"loop" : 1,
								"content_state" : 								{
									"slurtime" : [ 0.0 ],
									"pitchcorrection" : [ 0 ],
									"speed" : [ 1.0 ],
									"play" : [ 0 ],
									"followglobaltempo" : [ 0 ],
									"quality" : [ "basic" ],
									"pitchshift" : [ 1.0 ],
									"timestretch" : [ 0 ],
									"formantcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"originallength" : [ 0.0, "ticks" ],
									"mode" : [ "basic" ],
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"basictuning" : [ 440 ]
								}

							}
 ]
					}
,
					"id" : "obj-34",
					"maxclass" : "playlist~",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "signal", "", "dictionary" ],
					"patching_rect" : [ 118.0, 91.0, 150.0, 30.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 118.0, 534.0, 51.75, 20.0 ],
					"text" : "dac~ 1 2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-25",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 346.5, 72.0, 46.0, 18.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 16.5, 42.0, 46.0, 18.0 ],
					"text" : "reverse"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "live.toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 354.0, 91.0, 26.0, 26.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 24.0, 61.0, 26.0, 26.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "reverse",
							"parameter_initial_enable" : 1,
							"parameter_mmax" : 1,
							"parameter_initial" : [ 0.0 ],
							"parameter_shortname" : "reverse",
							"parameter_enum" : [ "off", "on" ],
							"parameter_type" : 2,
							"parameter_linknames" : 1
						}

					}
,
					"varname" : "reverse"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 354.0, 143.5, 60.0, 20.0 ],
					"text" : "reverse $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 596.444153000000028, 46.5, 44.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 266.444152999999972, 16.5, 44.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "mix",
							"parameter_initial_enable" : 1,
							"parameter_mmax" : 100.0,
							"parameter_initial" : [ 0.0 ],
							"parameter_shortname" : "mix",
							"parameter_type" : 0,
							"parameter_unitstyle" : 5,
							"parameter_linknames" : 1
						}

					}
,
					"varname" : "mix"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-40",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 485.408630000000016, 224.928374999999988, 66.0, 20.0 ],
					"text" : "predelay $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 637.900817999999958, 297.162170000000003, 37.0, 20.0 ],
					"text" : "tilt $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-35",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 592.444153000000028, 273.084228999999993, 52.0, 20.0 ],
					"text" : "depth $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 551.0, 95.5, 44.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 221.0, 65.5, 44.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "decay",
							"parameter_initial_enable" : 1,
							"parameter_mmax" : 120.0,
							"parameter_initial" : [ 0.0 ],
							"parameter_shortname" : "decay",
							"parameter_type" : 0,
							"parameter_unitstyle" : 5,
							"parameter_linknames" : 1
						}

					}
,
					"varname" : "decay"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-32",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 505.0, 95.5, 44.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 175.0, 65.5, 44.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_mmin" : -100.0,
							"parameter_longname" : "tilt",
							"parameter_initial_enable" : 1,
							"parameter_mmax" : 100.0,
							"parameter_initial" : [ 0.0 ],
							"parameter_shortname" : "tilt",
							"parameter_type" : 0,
							"parameter_unitstyle" : 5,
							"parameter_linknames" : 1
						}

					}
,
					"varname" : "tilt"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-31",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 459.0, 95.5, 44.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 129.0, 65.5, 44.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_mmin" : -100.0,
							"parameter_longname" : "depth",
							"parameter_initial_enable" : 1,
							"parameter_mmax" : 100.0,
							"parameter_initial" : [ 0.0 ],
							"parameter_shortname" : "depth",
							"parameter_type" : 0,
							"parameter_unitstyle" : 5,
							"parameter_linknames" : 1
						}

					}
,
					"varname" : "depth"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 505.0, 46.5, 44.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 175.0, 16.5, 44.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_mmin" : 7.0,
							"parameter_exponent" : 3.3333333,
							"parameter_longname" : "predelay",
							"parameter_initial_enable" : 1,
							"parameter_mmax" : 500.0,
							"parameter_initial" : [ 7.0 ],
							"parameter_shortname" : "predelay",
							"parameter_type" : 0,
							"parameter_unitstyle" : 2,
							"parameter_linknames" : 1
						}

					}
,
					"varname" : "predelay"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-29",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 398.0, 75.0, 44.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 68.0, 45.0, 44.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_mmin" : 1.0,
							"parameter_exponent" : 3.333333,
							"parameter_longname" : "size",
							"parameter_initial_enable" : 1,
							"parameter_mmax" : 500.0,
							"parameter_initial" : [ 40 ],
							"parameter_shortname" : "size",
							"parameter_type" : 0,
							"parameter_unitstyle" : 9,
							"parameter_linknames" : 1,
							"parameter_units" : "m"
						}

					}
,
					"varname" : "size"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 551.0, 46.5, 44.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 221.0, 16.5, 44.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "absorb",
							"parameter_initial_enable" : 1,
							"parameter_mmax" : 100.0,
							"parameter_initial" : [ 0.0 ],
							"parameter_shortname" : "absorb",
							"parameter_type" : 0,
							"parameter_unitstyle" : 5,
							"parameter_linknames" : 1
						}

					}
,
					"varname" : "absorb"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 459.0, 46.5, 44.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 129.0, 16.5, 44.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_mmin" : 0.1,
							"parameter_exponent" : 6.0,
							"parameter_longname" : "speed",
							"parameter_initial_enable" : 1,
							"parameter_mmax" : 256.0,
							"parameter_initial" : [ 0.1 ],
							"parameter_shortname" : "speed",
							"parameter_type" : 0,
							"parameter_unitstyle" : 3,
							"parameter_linknames" : 1
						}

					}
,
					"varname" : "speed"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 437.849060000000009, 200.85043300000001, 53.0, 20.0 ],
					"text" : "speed $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 670.740294999999946, 321.240112000000011, 53.0, 20.0 ],
					"text" : "decay $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 542.080688000000009, 249.006302000000005, 58.0, 20.0 ],
					"text" : "absorb $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 398.0, 174.5, 43.0, 20.0 ],
					"text" : "size $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 0,
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "dsp.gen",
						"rect" : [ 413.0, 79.0, 1039.0, 787.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-3",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 354.0, 820.0, 37.0, 22.0 ],
									"text" : "out 2"
								}

							}
, 							{
								"box" : 								{
									"code" : "lowpass(input, coeff){\n\tHistory lowpass(0);\n\tlowpass = mix(input, lowpass, coeff);\n\treturn lowpass;\n}\nallpass(input, time, gain){\n\tDelay allpass(1440, interp=\"linear\");\n\tallpassread = allpass.read(mstosamps(time));\n\tfeedback = allpassread * gain * 0.5;\n \tallpassinput = input + feedback;\n\tfeedforward = allpassinput * gain * -0.5;\n\tallpassoutput = allpassread + feedforward;\n\tallpass.write(allpassinput);\n\treturn allpassoutput;\n}\nsaturate(input, drive){\r\n\tx = clip(input, -1, 1);\r\n\tcheby = 4*pow(x,3)-3*x;\n\tsaturation = (input-(cheby*0.05))*0.877193;\n\tsaturation -= lowpass(saturation, 0.99);\n\tsatout = mix(input, saturation, drive);\n\treturn satout;\n}\nbiquad(xL, xR, cf, gain, Q, mode) {\n\tHistory z1L, z2L, z1R, z2R;\n\ta0, a1, a2, b1, b2 = 0;\n\t\n\tomega = cf * twopi / samplerate;\n\tsn = sin(omega);\n\tcs = cos(omega);\n\tA = sqrt(gain);\n\tbeta = sqrt((A * A + 1) / Q - (A - 1) * (A - 1));\n\tif(mode == 0) {\n\t\tb0 = 1 / (A + 1 + (A - 1) * cs + beta * sn);\n    \ta0 = A * (A + 1 - (A - 1) * cs + beta * sn) * b0;\n    \ta1 = 2 * A * (A - 1 - (A + 1) * cs) * b0;\n    \ta2 = A * (A + 1 - (A - 1) * cs - beta * sn) * b0;\n    \tb1 = (-2) * (A - 1 + ( A + 1) * cs) * b0;\n    \tb2 = (A + 1 + (A - 1) * cs - beta * sn) * b0;\n\t}\n\tif(mode == 1) {\n\t\tb0 = 1 / (A + 1 - (A - 1) * cs + beta * sn); \n\t\ta0 = A * (A + 1 + (A - 1) * cs + beta * sn) * b0;  \n\t\ta1 = (-2) * A * (A - 1 + (A + 1) * cs) * b0;  \n\t\ta2 =  A * (A + 1 + (A - 1) * cs - beta * sn) * b0;\n\t\tb1 = 2 * (A - 1 - (A + 1) * cs) * b0;  \n\t\tb2 = (A + 1 - (A - 1) * cs - beta * sn) * b0; \n\t}\n\t\n\tyL = xL * a0 + z1L;\n    z1L = xL * a1 + z2L - b1 * yL;\n    z2L = xL * a2 - b2 * yL;\r\n\r\n\tyR = xR * a0 + z1R;\n    z1R = xR * a1 + z2R - b1 * yR;\n    z2R = xR * a2 - b2 * yR;\r\n\t\n\treturn yL, yR;\n}\n\nDelay predelayLR(48336), delay1(88320), delay2(101519), delay3(119001), delay4(141176);\nParam reverse(default=0, min=0, max=1), size(default=40, min=1, max=500), speed(default=1, min=0.1, max=256), \ndepth(default=0, min=-100, max=100), predelay(default=7, min=7, max=500), tilt(default=0, min=-100, max=100), \nabsorb(default=30, min=0, max=100), decay(default=85, min=0, max=120), mix(default=50, min=0, max=100);\n\n//----SMOOTH OUT CONTROL INPUTS----//\nreverseLP = lowpass(reverse, 0.997243);\nsizeLP = lowpass(size*samplerate/340, 0.9997243);\n//speed doesn't need to be smoothed\ndepthLP = lowpass(depth*0.01, 0.9997243);\npredelayLP = lowpass(predelay, 0.997243);\ntiltLP = lowpass(tilt*0.005+0.5, 0.9997243);\nabsorbLP = lowpass(absorb*0.01, 0.9997243);\ndecayLP = lowpass(decay*0.005, 0.9997243);\nmixLP = lowpass(mix*0.01, 0.9997243);\n\n//----PREDELAY----//\n//predelay input\ninput = in1; //scale the input\npredelayLR.write(input); //write to left channel delay\n\n//variables\nrevflag = reverseLP > 0.00001; //toggle when smoothed reverse is near 0\npredelayLP_samps = mstosamps(predelayLP); //predelay time in samples\n\n//non-reversed predelay\npredelay1 = predelayLR.read(predelayLP_samps, interp=\"linear\");\n\n//reversed predelay\npredelay2, predelay3 = 0;\nif(revflag){\n\trevphasor = phasor(1000/predelayLP);\n\trevphasorA = revphasor * 2; //revphasor1 doubles the speed (for reverse) and doubles the range (allows for crossfading)\n\trevphasorB = (revphasor+0.5) % 1 * 2; //revphasor2 is 180 degrees out of phase with revphasor1\n\tpretimeA = revphasorA * predelayLP_samps;\n\tpretimeB = revphasorB * predelayLP_samps;\n\t\n\t//fades\n\txfadeFac = predelayLP / 3.5; //calculate the crossfade factor for a 3.5 ms ramp\n\txfadeOff = 1 / xfadeFac + 1; //calculate the offset for the ramp down when revphaserA passes 1.\n\txfadeA1 = revphasorA * xfadeFac; //ramp up\n\txfadeA1 = clip(xfadeA1, 0, 1); //constrain the range from 0 to 1\n\txfadeA2 = (xfadeOff - revphasorA) * xfadeFac; //ramp down\n\txfadeA2 = clip(xfadeA2, 0, 1); //constrain the range from 0 to 1\n\txfadeA = xfadeA1*xfadeA2; //fade-in and -out for revphaserA\n\txfadeB = 1 - xfadeA; //fade-in and -out for revphaserB, moves in opposite direction  to xfadeA\n\t\n\t//read delayline and apply crossfades\n\tpredelay2 = predelayLR.read(pretimeA, interp=\"linear\") * xfadeA;\n\tpredelay3 = predelayLR.read(pretimeB, interp=\"linear\") * xfadeB;\n}\n\n//predelay output\npredelayOut = mix(predelay1, predelay2+predelay3, reverseLP);\n//--------------//\n\n//----EARLY REFLECTIONS----//\nearly1 = delay1.read(0);\nearly2 = delay1.read(0.207771 * sizeLP, interp=\"linear\");\nearly3 = delay2.read(0.357573 * sizeLP, interp=\"linear\");\nearly4 = delay3.read(0);\nearly5 = delay3.read(0.421567 * sizeLP, interp=\"linear\");\nearly6 = delay4.read(0);\nearly7 = delay4.read(0.501143 * sizeLP, interp=\"linear\");\n\n//----FDN----//\ndelayt1 = 0.625597 * sizeLP;\ndelayt2 = 0.719094 * sizeLP;\ndelayt3 = 0.842925 * sizeLP;\ndelayt4 = sizeLP;\n\n//----MODULATION----//\nmoddepth = depthLP * depthLP * 480;\n\nFDN1, FDN2, FDN3, FDN4, FDN1mod, FDN2mod, FDN3mod, FDN4mod = 0;\nif(depthLP <= 0){\n\t//cyclic modulation\n\tmaster = phasor(speed);\n\tmod1 = (cycle((master + 0.23) % 1, index=\"phase\") + 1) * moddepth * 0.5;\n\tmod2 = (cycle((master + 0.541) % 1, index=\"phase\") + 1) * moddepth * 0.5;\n\tmod3 = (cycle((master + 0.0321) % 1, index=\"phase\") + 1) * moddepth * 0.5;\n\tmod4 = (cycle((master + 0.87102) % 1, index=\"phase\") + 1) * moddepth * 0.5;\n\t\n\t//----MOD READ----//\n\tFDN1 = delay1.read(delayt1 + mod1, interp=\"linear\");\n\tFDN2 = delay2.read(delayt2 + mod2, interp=\"linear\");\n\tFDN3 = delay3.read(delayt3 + mod3, interp=\"linear\");\n\tFDN4 = delay4.read(delayt4 + mod4, interp=\"linear\");\n\t\n\t//----FEEDBACK READ----//\n\tFDN1mod = FDN1;\n\tFDN2mod = FDN2;\n\tFDN3mod = FDN3;\n\tFDN4mod = FDN4;\n}\nelse {\n\t//ergodic modulation\r\n\trandom1 = noise()*0.5+0.5;\n    random2 = noise()*0.5+0.5;\n    random3 = noise()*0.5+0.5;\n    random4 = noise()*0.5+0.5;\n\n    phasor1 = phasor(speed*0.25);\n    phasor2 = (phasor1 + 0.25) % 1;\n    phasor3 = (phasor1 + 0.50) % 1;\n    phasor4 = (phasor1 + 0.75) % 1;\n\n    window1 = sin(phasor1*pi);\r\n\twindow1 *= window1;\n    window2 = sin(phasor2*pi);\r\n\twindow2 *= window2;\n    window3 = 1-window1;\n    window4 = 1-window2;\n\n    trig1 = delta(phasor1);\n    trig2 = delta(phasor2);\n    trig3 = delta(phasor3);\n    trig4 = delta(phasor4);\n\n    randt01 = sah(random1, trig1, 0) * moddepth;\n    randt02 = sah(random1, trig2, 0) * moddepth;\n    randt03 = sah(random1, trig3, 0) * moddepth;\n    randt04 = sah(random1, trig4, 0) * moddepth;\n    randt05 = sah(random2, trig1, 0) * moddepth;\n    randt06 = sah(random2, trig2, 0) * moddepth;\n    randt07 = sah(random2, trig3, 0) * moddepth;\n    randt08 = sah(random2, trig4, 0) * moddepth;\n    randt09 = sah(random3, trig1, 0) * moddepth;\n    randt10 = sah(random3, trig2, 0) * moddepth;\n    randt11 = sah(random3, trig3, 0) * moddepth;\n    randt12 = sah(random3, trig4, 0) * moddepth;\n    randt13 = sah(random4, trig1, 0) * moddepth;\n    randt14 = sah(random4, trig2, 0) * moddepth;\n    randt15 = sah(random4, trig3, 0) * moddepth;\n    randt16 = sah(random4, trig4, 0) * moddepth;\n\n    FDN1mod += delay1.read(delayt1 + randt01 , interp=\"linear\") * window1;\n    FDN1mod += delay1.read(delayt1 + randt02, interp=\"linear\") * window2;\n    FDN1mod += delay1.read(delayt1 + randt03, interp=\"linear\") * window3;\n    FDN1mod += delay1.read(delayt1 + randt04, interp=\"linear\") * window4;\n    FDN2mod += delay2.read(delayt2 + randt05, interp=\"linear\") * window1;\n    FDN2mod += delay2.read(delayt2 + randt06, interp=\"linear\") * window2;\n    FDN2mod += delay2.read(delayt2 + randt07, interp=\"linear\") * window3;\n    FDN2mod += delay2.read(delayt2 + randt08, interp=\"linear\") * window4;\n    FDN3mod += delay3.read(delayt3 + randt09, interp=\"linear\") * window1;\n    FDN3mod += delay3.read(delayt3 + randt10, interp=\"linear\") * window2;\n    FDN3mod += delay3.read(delayt3 + randt11, interp=\"linear\") * window3;\n    FDN3mod += delay3.read(delayt3 + randt12, interp=\"linear\") * window4;\n    FDN4mod += delay4.read(delayt4 + randt13, interp=\"linear\") * window1;\n    FDN4mod += delay4.read(delayt4 + randt14, interp=\"linear\") * window2;\n    FDN4mod += delay4.read(delayt4 + randt15, interp=\"linear\") * window3;\n    FDN4mod += delay4.read(delayt4 + randt16, interp=\"linear\") * window4;\n\n    FDN1mod *= 0.5;\n    FDN2mod *= 0.5;\n    FDN3mod *= 0.5;\n    FDN4mod *= 0.5;\r\n\r\n\t//----SHIMMER----//\r\n\tshimmer = maximum(5 * (depthLP - 0.8), 0);\r\n\tshimmerOut1, shimmerOut2 = 0;\n\tif(shimmer){\r\n\t\tshRandom = noise()*80+80;\r\n\t\tshPhasor1 = phasor(-samplerate/delayt1);\r\n\t\tshPhasor2 = (shPhasor1+0.5)%1;\r\n\t\tshWindow1 = sin(shPhasor1*pi);\r\n\t\tshWindow1 *= shWindow1;\r\n\t\tshWindow2 = 1-shWindow1;\r\n\t\tshRand1 = sah(shRandom, delta(shPhasor1), 0);\r\n\t\tshRand2 = sah(shRandom, delta(shPhasor2), 0);\r\n\t\t\r\n\t\tshPhasor3 = phasor(-samplerate/delayt2);\r\n\t\tshPhasor4 = (shPhasor3+0.5)%1;\r\n\t\tshWindow3 = sin(shPhasor3*pi);\r\n\t\tshWindow3 *= shWindow3;\r\n\t\tshWindow4 = 1-shWindow3;\r\n\t\tshRand3 = sah(shRandom, delta(shPhasor3), 0);\r\n\t\tshRand4 = sah(shRandom, delta(shPhasor4), 0);\r\n\t\t\r\n\t\tshimmerOut1 = delay1.read(shPhasor1 * delayt1 + shRand1, interp=\"linear\") * shWindow1;\r\n\t\tshimmerOut1 += delay1.read(shPhasor2 * delayt1 + shRand2, interp=\"linear\") * shWindow2;\r\n\t\tshimmerOut2 = delay2.read(shPhasor3 * delayt2 + shRand3, interp=\"linear\") * shWindow3;\r\n\t\tshimmerOut2 += delay2.read(shPhasor4 * delayt2 + shRand4, interp=\"linear\") * shWindow4;\r\n\t}\n\n\t//----FEEDBACK READ----//\n\tFDN1 = mix(delay1.read(delayt1, interp=\"linear\"), shimmerOut1, shimmer);\n\tFDN2 = mix(delay2.read(delayt2, interp=\"linear\"), shimmerOut2, shimmer);\n\tFDN3 = delay3.read(delayt3, interp=\"linear\");\n\tFDN4 = delay4.read(delayt4, interp=\"linear\");\n}\n\n//----SATURATION----//\ndrive = clip((decayLP - 0.495) * 200, 0, 1);\nif(drive){\n\tFDN1 = saturate(FDN1, drive, sat);\n\tFDN2 = saturate(FDN2, drive, sat);\n\tFDN3 = saturate(FDN3, drive, sat);\n\tFDN4 = saturate(FDN4, drive, sat);\n}\n\n//----FEEDBACK MATRIX----//\nfeedback1 = decayLP * (FDN1 - FDN2 - FDN3 + FDN4);\nfeedback2 = decayLP * (FDN1 + FDN2 - FDN3 - FDN4);\nfeedback3 = decayLP * (FDN1 - FDN2 + FDN3 - FDN4);\nfeedback4 = decayLP * (FDN1 + FDN2 + FDN3 + FDN4);\n\n//----ABSORB----//\ndamping = maximum((absorbLP - 0.3) * 1.428571, 0); //filter is enabled from 0.3 to 1.\ndamping1 = lowpass(predelayOut + feedback1, damping);\ndamping2 = lowpass(predelayOut + feedback3, damping);\ndamping3 = lowpass(feedback2, damping);\ndamping4 = lowpass(feedback4, damping);\n\n//----DIFFUSE----//\ndiff = minimum(absorbLP * 2.666667, 0.8); //diffuse is enabled from 0. to 0.3\ndiffuse1 = allpass(allpass(allpass(allpass(damping1, 5.020833, diff), 1.854167, diff), 7.229167, diff), 14.604167, diff);\ndiffuse2 = allpass(allpass(allpass(allpass(damping2, 4.145833, diff), 3.145833, diff), 7.979167, diff), 13.145833, diff);\ndiffuse3 = allpass(allpass(allpass(allpass(damping3, 5.229167, diff), 2.645833, diff), 10.395833, diff), 12.770833, diff);\ndiffuse4 = allpass(allpass(allpass(allpass(damping4, 4.395833, diff), 3.770833, diff), 5.854167, diff), 14.020833, diff);\n\n//----WRITE TO DELAY----//\ndelay1.write(diffuse1);\ndelay2.write(diffuse2);\ndelay3.write(diffuse3);\ndelay4.write(diffuse4);\n\n//----REVERB OUT----//\nearlyRefl = 0.15 * (early1+early2+early3+early4+early5+early6+early7);\nreverbL = FDN1mod * 0.75 + FDN2mod * 0.25 + FDN3mod * 0.5 + FDN4mod * 0.5 + earlyRefl; //apply some panning\nreverbR = FDN1mod * 0.25 + FDN2mod * 0.75 + FDN3mod * 0.5 + FDN4mod * 0.5 + earlyRefl;\n\n//----TILT----//\ngainlow = dbtoa(tiltLP * -24 + 12); //gain for the lowshelf filter\ngainhigh = dbtoa(tiltLP * 48 - 24); //gain for the hishelf filter\ntiltlowL, tiltlowR = biquad(reverbL, reverbR, 300, gainlow, 0.8, 0); //lowshelf filter\ntiltoutL, tiltoutR = biquad(tiltlowL, tiltlowR, 6000, gainhigh, 0.8, 1); //hishelf filter\n\n//----DRY/WET----//\noutputL = interp(mixLP, input, tiltoutL, mode=\"cosine\");\noutputR = interp(mixLP, input, tiltoutR, mode=\"cosine\");\n\nout1 = outputL;\nout2 = outputR;\n",
									"fontface" : 0,
									"fontname" : "Menlo",
									"fontsize" : 12.0,
									"id" : "obj-5",
									"maxclass" : "codebox",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 50.0, 87.0, 931.0, 713.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 14.0, 30.0, 22.0 ],
									"text" : "in 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 50.0, 820.0, 37.0, 22.0 ],
									"text" : "out 1"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-5", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
 ],
						"editing_bgcolor" : [ 0.9, 0.9, 0.9, 1.0 ]
					}
,
					"patching_rect" : [ 118.0, 465.0, 51.75, 20.0 ],
					"saved_object_attributes" : 					{
						"exportfolder" : "Macintosh SSD:/Users/davemollen/Git-Repositories/audio/dm-Erbeverb/"
					}
,
					"text" : "gen~"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 1 ],
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 0 ],
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-40", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-28" : [ "absorb", "absorb", 0 ],
			"obj-32" : [ "tilt", "tilt", 0 ],
			"obj-18" : [ "mix", "mix", 0 ],
			"obj-30" : [ "predelay", "predelay", 0 ],
			"obj-33" : [ "decay", "decay", 0 ],
			"obj-31" : [ "depth", "depth", 0 ],
			"obj-12" : [ "reverse", "reverse", 0 ],
			"obj-27" : [ "speed", "speed", 0 ],
			"obj-29" : [ "size", "size", 0 ],
			"parameterbanks" : 			{

			}

		}
,
		"dependency_cache" : [ 			{
				"name" : "drumLoop.aif",
				"bootpath" : "C74:/media/msp",
				"type" : "AIFF",
				"implicit" : 1
			}
 ],
		"autosave" : 0
	}

}
